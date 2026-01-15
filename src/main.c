#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#include <zephyr/drivers/display.h>
#include <zephyr/drivers/i2c.h>
#include <lvgl.h>

#include <btManager.h>
#include <TallerFont.h>

#include <globals.h>
#include <mainMenu.h>

LV_FONT_DECLARE(TallerFont);

int main(void)
{
        k_sleep(K_SECONDS(3));
        printk("LVGL Test Application Start\n");
        
        //bluetoothActivate();
        BTSetup();

        display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        
        if (!device_is_ready(display)) 
        {
                printk("Device not ready");
                //return 0;
        }
        
        else
        {
                printk("Device is ready\n");
        }

        if (display_set_pixel_format(display, PIXEL_FORMAT_MONO10) != 0) 
        {
                printk("Failed to set required pixel format\n");
        }

        lv_style_t style;
        lv_style_init(&style);
        
        lv_style_set_text_font(&style, &TallerFont);
        lv_obj_t *hello_label = lv_label_create(lv_scr_act());
        lv_label_set_text(hello_label, "12:30");
        lv_obj_add_style(hello_label, &style, 0);
        lv_obj_set_style_outline_width(hello_label, 1, 0);
        //lv_obj_set_style_outline_color(hello_label, lv_palette_main(), 0);
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
