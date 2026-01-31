#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/pm/device.h>
#include <zephyr/sys/poweroff.h>

#include <zephyr/drivers/display.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>

#include <btManager.h>
#include <buttons.h>

#include <globals.h>
#include <appManager.h>
#include <appIncludes.h>

LV_FONT_DECLARE(TallerFont);

int main(void)
{
        k_sleep(K_SECONDS(1));
        printk("FitBoy Mk.3\n");
        k_sleep(K_SECONDS(1));
        
        display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        const struct device* mpu = DEVICE_DT_GET(DT_NODELABEL(mpu6050));
        const struct device *i2c_bus = DEVICE_DT_GET(DT_NODELABEL(i2c0));

        BTSetup();
        
        if (!device_is_ready(display) || !device_is_ready(mpu)) 
        {
                printk("Device not ready");
        }
        
        else
        {
                printk("Device is ready\n");
        }
        
        int x = 0;
        uint8_t mpu_sleep_cmd[] = {0x6B, 0x40}; 
        x = i2c_write(i2c_bus, mpu_sleep_cmd, sizeof(mpu_sleep_cmd), 0x68);
        printk("MPU sleep command write returned %d\n", x);

        /*
        uint8_t oled_sleep_cmd[] = {0x00, 0xAE};
        x = i2c_write(i2c_bus, oled_sleep_cmd, sizeof(oled_sleep_cmd), 0x3C);
        printk("OLED sleep command write returned %d\n", x);

        /*
        k_sleep(K_SECONDS(1));
        int state = 0;
        pm_device_state_get(i2c_bus, &state);
        printk("I2C device state before poweroff: %d\n", state);

        sys_poweroff();
        */
        const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(p25q16h));
        pm_device_action_run(flash_dev, PM_DEVICE_ACTION_SUSPEND);

        buttonInit();

        App apps[] = {mainMenuApp,};
        AppManagerSetup(apps, 1);

        while(1)
        {
                k_sleep(K_MSEC(50));
        }
        return 0;
}
