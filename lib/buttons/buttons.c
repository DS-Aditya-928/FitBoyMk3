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

    bool isCombo;
    lv_key_t comboKeyCode;
};

#define BUTTON_INIT_LVGL(node_id, lvglLabel) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .keyCode = lvglLabel, .pressTime = 0, \
        .isPressed = false, .isLVGL = true, .isCombo = false, .comboKeyCode = 0 }

#define BUTTON_INIT_NON_LVGL(node_id, key) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .keyCode = key, .pressTime = 0, \
        .isPressed = false, .isLVGL = false , .isCombo = false, .comboKeyCode = 0}

static struct buttonData buttons[] = 
{
    BUTTON_INIT_LVGL(DT_ALIAS(up), LV_KEY_LEFT),
    BUTTON_INIT_LVGL(DT_ALIAS(down), LV_KEY_RIGHT),
    BUTTON_INIT_LVGL(DT_ALIAS(select), LV_KEY_ENTER),
    BUTTON_INIT_NON_LVGL(DT_ALIAS(mode), KEY_MODE),
};

struct comboData
{
    int keyCode1;
    int keyCode2;

    uint32_t activeButtons;
    lv_key_t comboKeyCode;
};

#define COMBO_INIT(bI1, bI2, ckCode) \
    { .keyCode1 = bI1, .keyCode2 = bI2, .comboKeyCode = ckCode }

static struct comboData combos[] = 
{
    COMBO_INIT(LV_KEY_LEFT, LV_KEY_RIGHT, LV_KEY_HOME),
    COMBO_INIT(LV_KEY_RIGHT, LV_KEY_LEFT, LV_KEY_HOME),
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
    lv_key_t keyCode;
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
            int subComboIndex = -1;
            struct buttonAction* top = (struct buttonAction*)listPeekHead(&buttonActionList);
            
            if(top != NULL)
            {
                printk("Top of list button code %d, timestamp %d, state %d\n", top->keyCode, top->timestamp, (int)(top->state == LV_INDEV_STATE_PRESSED));
                int32_t timeDiff = k_uptime_get() - top->timestamp;
                if(timeDiff < 50)
                {
                    //printk("Checking for combo with button %d, top action button %d, time diff %d\n", buttons[i].keyCode, top->keyCode, timeDiff);
                    for(int j = 0; j < ARRAY_SIZE(combos); j++)
                    {
                        if(top->keyCode == combos[j].keyCode1 
                        && buttons[i].keyCode == combos[j].keyCode2
                        && top->state == LV_INDEV_STATE_PRESSED) 
                        {
                            printk("Found combo for buttons %d and %dm %d\n", top->keyCode, buttons[i].keyCode, top->state);
                            subComboIndex = j;
                            break;
                        }
                    }
                }
            }

            if(subComboIndex != -1)
            {
                //cycle through list and print entites
                struct LinkedListNode* current = buttonActionList.head;
                //printk("Found combo, modifying list. Current list size %d\n", buttonActionList.size);
                //printk("Current button action list: \n");
                while(current != NULL) 
                {
                    struct buttonAction* action = (struct buttonAction*)current->data;
                    //printk("Button code %d, timestamp %d, state %d\n", action->keyCode, action->timestamp, action->state);
                    current = current->next;
                }

                combos[subComboIndex].activeButtons |= BIT(buttons[i].keyCode);
                combos[subComboIndex].activeButtons |= BIT(top->keyCode); 

                //modify top action.
                //printk("Modifying top action from button %d to combo button %d\n", top->keyCode, combos[subComboIndex].comboKeyCode);
                top->keyCode = combos[subComboIndex].comboKeyCode;

                printf("Modified top action. Current button action list: \n");
                current = buttonActionList.head;
                while(current != NULL)
                {
                    struct buttonAction* action = (struct buttonAction*)current->data;
                    //printk("Button code %d, timestamp %d, state %d\n", action->keyCode, action->timestamp, action->state);
                    current = current->next;
                }
                
                //now the combo entry's bitmask holds 1s for each index that triggered it.
            }

            else // no combo, regular action
            {
                struct buttonAction* action = k_malloc(sizeof(struct buttonAction));
                action->keyCode = buttons[i].keyCode;
                action->timestamp = k_uptime_get();
                action->state = LV_INDEV_STATE_PRESSED;
                listPrepend(&buttonActionList, action);
            }
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
            int comboIndex = -1;
            for(int j = 0; j < ARRAY_SIZE(combos); j++)
            {
                if(combos[j].activeButtons & BIT(buttons[i].keyCode)) //look for a combo that this button is a part of.
                {
                    comboIndex = j;
                    break;
                }
            }

            if(comboIndex != -1)
            {
                combos[comboIndex].activeButtons &= ~BIT(buttons[i].keyCode); 
                if(!combos[comboIndex].activeButtons) // last button released
                {
                    //printk("Adding button release for combo button %d to list\n", combos[comboIndex].comboKeyCode);
                    struct buttonAction* action = k_malloc(sizeof(struct buttonAction));
                    action->keyCode = combos[comboIndex].comboKeyCode;
                    action->timestamp = k_uptime_get();
                    action->state = LV_INDEV_STATE_RELEASED;
                    listPrepend(&buttonActionList, action);
                }
            }

            else
            {
                //printk("Adding button release for button %d to list\n", buttons[i].keyCode);
                struct buttonAction* action = k_malloc(sizeof(struct buttonAction));
                action->keyCode = buttons[i].keyCode;
                action->timestamp = k_uptime_get();
                action->state = LV_INDEV_STATE_RELEASED;
                listPrepend(&buttonActionList, action);
            }
        }
        
        buttons[i].pressTime = k_uptime_get();
    }

    buttons[i].isPressed = isCurrentlyPressed;
}

static struct gpio_callback pin_cb_data;

static struct buttonAction action;
void encoderRead(lv_indev_t* drv, lv_indev_data_t* data) 
{
    if(buttonActionList.size > 0 && 
    (k_uptime_get() - ((struct buttonAction*)listPeek(&buttonActionList))->timestamp) >= 50)
    {
        struct buttonAction* bA = (struct buttonAction*)listPop(&buttonActionList);
        action = *bA;
        printk("Read button index %d, state %d\n", action.keyCode, action.state);
        k_free(bA);
    }

    data->key = action.keyCode;
    data->state = action.state;
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

    listInit(&buttonActionList, 6);
 
    printk("Button Init Complete\n");
    return 0;
}