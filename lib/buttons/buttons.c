#include <buttons.h>
#include <appManager.h>
#include <linkedlist.h>

#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>
#include <lvgl.h>
#include <lvgl_input_device.h>
#include <lvgl_encoder_input.h>

#define HOLD_THRESHOLD_MS 1000
#define DEBOUNCE_TIME_MS 50
#define KEY_MODE 1

lv_indev_t* indev;

struct buttonData 
{
    const struct gpio_dt_spec spec;
    lv_key_t keyCode;
    int64_t pressTime;
    bool isPressed;
    bool isLVGL;
};

#define BUTTON_INIT_LVGL(node_id, lvglLabel) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .keyCode = lvglLabel, .pressTime = 0, .isPressed = false, .isLVGL = true }

#define BUTTON_INIT_NON_LVGL(node_id, key) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .keyCode = key, .pressTime = 0, .isPressed = false, .isLVGL = false }

static struct buttonData buttons[] = 
{
    BUTTON_INIT_LVGL(DT_ALIAS(up), LV_KEY_LEFT),
    BUTTON_INIT_LVGL(DT_ALIAS(down), LV_KEY_RIGHT),
    BUTTON_INIT_LVGL(DT_ALIAS(select), LV_KEY_ENTER),
    BUTTON_INIT_NON_LVGL(DT_ALIAS(mode), KEY_MODE)
};

static bool keyPressed = false;
static int64_t modeChangeDT = 0;

void modeChange(struct k_work* work);
static struct modeChangeData
{
    struct k_work task;
    bool resetToFirst;
} modeChangeData = {
    .task = Z_WORK_INITIALIZER(modeChange),
    .resetToFirst = false
};

void modeChange(struct k_work* work)
{
    struct modeChangeData* data = CONTAINER_OF(work, struct modeChangeData, task);
    appChange(data->resetToFirst);
}

struct buttonAction
{
    int buttonIndex;
    int64_t timestamp;

    lv_indev_state_t state;
};

static struct LinkedList buttonActionList;
void button_pressed(const struct device* dev, struct gpio_callback* cb, uint32_t pins)
{
    //get the button that triggered the interrupt from pins via bitmask
    keyPressed = false;
    //get i from pins
    int i = 0;
    for(; i < ARRAY_SIZE(buttons); i++)
    {
        if(pins & BIT(buttons[i].spec.pin))
        {
            break;
        }
    }

    bool isCurrentlyPressed = gpio_pin_get_dt(&buttons[i].spec) == 1;

    //rising edge
    if(!buttons[i].isPressed && isCurrentlyPressed) 
    {
        if(k_uptime_get() - buttons[i].pressTime < DEBOUNCE_TIME_MS)
        {
            buttons[i].pressTime = k_uptime_get();
            return; //ignore any rising edges that occur within the debounce time
        }
        
        if(buttons[i].isLVGL)
        {
            struct buttonAction* action = k_malloc(sizeof(struct buttonAction));
            action->buttonIndex = i;
            action->timestamp = k_uptime_get();
            action->state = LV_INDEV_STATE_PRESSED;
            listAppend(&buttonActionList, action);
        }

        else
        {
            if(buttons[i].keyCode == KEY_MODE)
            {
                modeChangeDT = k_uptime_get();
            }
        }
    }

    //falling edge
    else if(buttons[i].isPressed && !isCurrentlyPressed) 
    {
        if(buttons[i].keyCode == KEY_MODE)
        {
            if((k_uptime_get() - modeChangeDT) >= HOLD_THRESHOLD_MS)
            {
                modeChangeData.resetToFirst = true;
                k_work_submit(&modeChangeData.task);
            }

            else
            {
                modeChangeData.resetToFirst = false;
                k_work_submit(&modeChangeData.task);
            }
        }

        if(buttons[i].isLVGL)
        {
            struct buttonAction* action = k_malloc(sizeof(struct buttonAction));
            action->buttonIndex = i;
            action->timestamp = k_uptime_get();
            action->state = LV_INDEV_STATE_RELEASED;
            listAppend(&buttonActionList, action);
        }
        
        buttons[i].pressTime = k_uptime_get();
    }

    buttons[i].isPressed = isCurrentlyPressed;
}

static struct gpio_callback pin_cb_data;

void encoderRead(lv_indev_t* drv, lv_indev_data_t* data) 
{
    if(buttonActionList.size > 0)
    {
        struct buttonAction* action = listPeek(&buttonActionList); 
        data->key = buttons[action->buttonIndex].keyCode;
        data->state = action->state;
        printk("Read button index %d, state %d\n", action->buttonIndex, action->state);
        //k_free(action);
    }
}

struct gpio_dt_spec* onButton;

int buttonInit(void)
{   
    const struct device *gpio1 = DEVICE_DT_GET(DT_NODELABEL(gpio1));
    if (!device_is_ready(gpio1)) return -1;

    uint32_t pin_mask = 0;
    onButton = &buttons[2].spec;
    for (int i = 0; i < ARRAY_SIZE(buttons); i++) 
    {
        gpio_pin_configure_dt(&buttons[i].spec, GPIO_INPUT);
        gpio_pin_interrupt_configure_dt(&buttons[i].spec, GPIO_INT_EDGE_BOTH);
        pin_mask |= BIT(buttons[i].spec.pin);
    }

    gpio_init_callback(&pin_cb_data, button_pressed, pin_mask);
    gpio_add_callback(gpio1, &pin_cb_data);

    indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(indev, encoderRead);

    listInit(&buttonActionList, 3);
 
    printk("Button Init Complete\n");
    return 0;
}