#include <buttons.h>
#include <appManager.h>

#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>
#include <lvgl.h>
#include <lvgl_input_device.h>
#include <lvgl_encoder_input.h>

#define HOLD_THRESHOLD_MS 1000
#define NON_LVGL_BUTTON -1

lv_indev_t* indev;

struct buttonData 
{
    const struct gpio_dt_spec spec;
    lv_key_t lvglKey;
    bool isPressed;
};
#define BUTTON_INIT(node_id, lvglLabel) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .lvglKey = lvglLabel, .isPressed = false }

static struct buttonData buttons[] = 
{
    BUTTON_INIT(DT_ALIAS(up), LV_KEY_LEFT),
    BUTTON_INIT(DT_ALIAS(down), LV_KEY_RIGHT),
    BUTTON_INIT(DT_ALIAS(select), LV_KEY_ENTER),
    BUTTON_INIT(DT_ALIAS(mode), NON_LVGL_BUTTON)
};

static bool keyPressed = false;
static int lastButton = 0;
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

    if(i != 3)
    {
        lastButton = i;
    }

    else
    {
        //rising edge
        if(!buttons[i].isPressed && gpio_pin_get_dt(&buttons[i].spec) == 1) 
        {
            modeChangeDT = k_uptime_get();
        }

        //falling edge
        else if(buttons[i].isPressed && gpio_pin_get_dt(&buttons[i].spec) == 0) 
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
    }

    buttons[i].isPressed = (gpio_pin_get_dt(&buttons[i].spec) == 1);
}

static struct gpio_callback pin_cb_data;

void encoderRead(lv_indev_t* drv, lv_indev_data_t* data) 
{
    data->key = buttons[lastButton].lvglKey;
    for(int i = 0; i < ARRAY_SIZE(buttons) - 1; i++)
    {
        if(buttons[i].isPressed && buttons[i].lvglKey != NON_LVGL_BUTTON)
        {
            data->state = LV_INDEV_STATE_PRESSED;
            return;
        }
    }

    data->state = LV_INDEV_STATE_RELEASED;
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
 
    printk("Button Init Complete\n");
    return 0;
}