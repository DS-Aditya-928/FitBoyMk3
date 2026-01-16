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

        while(1)
        {
                k_sleep(K_MSEC(50));
        }
        return 0;
}
