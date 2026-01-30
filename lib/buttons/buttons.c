#include <buttons.h>

#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>

#define DEBOUNCE_DELAY_MS 50
#define HOLD_THRESHOLD_MS 1000

struct button_data 
{
    const struct gpio_dt_spec spec;
    struct k_work_delayable work;
    int64_t start_time;
    bool is_pressed;
    bool hold_fired;
};

void button_work_handler(struct k_work *work);

#define BUTTON_INIT(node_id) \
    { .spec = GPIO_DT_SPEC_GET(node_id, gpios), .start_time = 0, .is_pressed = false, .hold_fired = false }

static struct button_data buttons[] = 
{
    BUTTON_INIT(DT_ALIAS(up)),
    BUTTON_INIT(DT_ALIAS(down)),
    BUTTON_INIT(DT_ALIAS(select)),
    BUTTON_INIT(DT_ALIAS(mode))
};

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    for (int i = 0; i < ARRAY_SIZE(buttons); i++) {
        if ((pins & BIT(buttons[i].spec.pin)) != 0) 
        {
            k_work_reschedule(&buttons[i].work, K_MSEC(DEBOUNCE_DELAY_MS));
        }
    }
}

void button_work_handler(struct k_work *work)
{
    struct k_work_delayable *dwork = k_work_delayable_from_work(work);
    struct button_data *btn = CONTAINER_OF(dwork, struct button_data, work);

    int pin_val = gpio_pin_get_dt(&btn->spec);

    if (pin_val == 1) 
    {
        if (!btn->is_pressed) 
        {
            btn->is_pressed = true;
            btn->start_time = k_uptime_get();
            btn->hold_fired = false;
            printk("Button Pin %d: Pressed\n", btn->spec.pin);
        }

        else 
        {
            int64_t duration = k_uptime_get() - btn->start_time;
            
            if (duration >= HOLD_THRESHOLD_MS && !btn->hold_fired) 
            {
                printk("Button Pin %d: HELD (%lld ms)\n", btn->spec.pin, duration);
                btn->hold_fired = true;
            }
        }

        k_work_reschedule(&btn->work, K_MSEC(DEBOUNCE_DELAY_MS));
    } 
    
    else 
    {
        if (btn->is_pressed) 
        {
            printk("Button Pin %d: Released\n", btn->spec.pin);
            btn->is_pressed = false;
            btn->hold_fired = false;
        }
    }
}

static struct gpio_callback pin_cb_data;

int buttonInit(void)
{   
    const struct device *gpio1 = DEVICE_DT_GET(DT_NODELABEL(gpio1));
    if (!device_is_ready(gpio1)) return -1;

    uint32_t pin_mask = 0;

    for (int i = 0; i < ARRAY_SIZE(buttons); i++) 
    {
        gpio_pin_configure_dt(&buttons[i].spec, GPIO_INPUT);
        gpio_pin_interrupt_configure_dt(&buttons[i].spec, GPIO_INT_EDGE_BOTH);
        k_work_init_delayable(&buttons[i].work, button_work_handler);
        pin_mask |= BIT(buttons[i].spec.pin);
    }

    gpio_init_callback(&pin_cb_data, button_pressed, pin_mask);
    gpio_add_callback(gpio1, &pin_cb_data);
    
    printk("Button Init Complete\n");
    return 0;
}