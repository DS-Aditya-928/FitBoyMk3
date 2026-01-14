#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#include <zephyr/drivers/display.h>
#include <zephyr/drivers/i2c.h>
#include <lvgl.h>

#include <btManager.h>

int main(void)
{
        const struct device *display_dev;

        k_sleep(K_SECONDS(3));
        printk("LVGL Test Application Start\n");
        
        bluetoothActivate();
        
        display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        
        if (!device_is_ready(display_dev)) 
        {
                printk("Device not ready");
                //return 0;
        }
        
        else
        {
                printk("Device is ready\n");
        }

        if (display_set_pixel_format(display_dev, PIXEL_FORMAT_MONO10) != 0) 
        {
                printk("Failed to set required pixel format\n");
        }
        
        lv_obj_t *hello_label = lv_label_create(lv_scr_act());
        lv_label_set_text(hello_label, "Test LVGL");
        lv_obj_align(hello_label, LV_ALIGN_CENTER, 0, -10);
        //lv_task_handler();
        printk("Entering main loop\n");

        //lv_obj_t *count_label = lv_label_create(lv_scr_act());
        //lv_obj_align(count_label, LV_ALIGN_CENTER, 0, 10);
        int count = 0;
        char count_str[16] = "1234567890abcde";
        printk("Entering main loop %d %s\n", count, count_str);
        //printk("Mem used before lv_task_handler: %d\n", lv_mem_get_used_size());

        k_sleep(K_SECONDS(4));
        
        printk("After lv_task_handler\n");

        while(1)
        {
                
                lv_task_handler();
                k_sleep(K_MSEC(50));
        }
        return 0;
}
