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
#include <TallerFont.h>

#include <globals.h>
#include <mainMenu.h>

LV_FONT_DECLARE(TallerFont);

int main(void)
{
        k_sleep(K_SECONDS(5));
        const struct device* mpu = DEVICE_DT_GET(DT_NODELABEL(mpu6050));
        //pm_device_action_run(mpu, PM_DEVICE_ACTION_SUSPEND);
        //k_sleep(K_SECONDS(100));
        printk("LVGL Test Application Start\n");
        //sys_poweroff();
        //bluetoothActivate();
        //BTSetup();

        display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
        
        if (!device_is_ready(display) || !device_is_ready(mpu)) 
        {
                printk("Device not ready");
                //return 0;
        }
        
        else
        {
                printk("Device is ready\n");
        }

        const struct device *i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c0));
         uint8_t chip_id;
    // 0x75 is the WHO_AM_I register for MPU9250/6500
        if (i2c_reg_read_byte(i2c_dev, 0x68, 0x75, &chip_id) == 0) {
                printk("Actual Chip ID detected: 0x%x\n", chip_id);
        }

        if (display_set_pixel_format(display, PIXEL_FORMAT_MONO10) != 0) 
        {
                printk("Failed to set required pixel format\n");
        }

        //display_set_contrast(display, 2);
        //k_sleep(K_MSEC(100));
        k_sleep(K_SECONDS(7));
        int x = 0;
        //x += pm_device_action_run(display, PM_DEVICE_ACTION_SUSPEND);
        //x += pm_device_action_run(mpu, PM_DEVICE_ACTION_SUSPEND);
        //printk("Suspended display with return code %d\n", pm_device_action_run(display, PM_DEVICE_ACTION_SUSPEND));
        //printk("Suspended mpu with return code %d\n", pm_device_action_run(mpu, PM_DEVICE_ACTION_SUSPEND));
        
        const struct device *i2c_bus = DEVICE_DT_GET(DT_NODELABEL(i2c0));
        if(!device_is_ready(i2c_bus)) 
        {
                printk("I2C bus not ready\n");
                return 0;
        }

        uint8_t mpu_sleep_cmd[] = {0x6B, 0x40}; 
        x = i2c_write(i2c_bus, mpu_sleep_cmd, sizeof(mpu_sleep_cmd), 0x68);
        printk("MPU sleep command write returned %d\n", x);
    // 2. SH1106: Send Display OFF command (0xAE)
    // 0x00 is the Control Byte for "Command Stream", 0xAE is Sleep

        uint8_t oled_sleep_cmd[] = {0x00, 0xAE};
        x = i2c_write(i2c_bus, oled_sleep_cmd, sizeof(oled_sleep_cmd), 0x3C);
        printk("OLED sleep command write returned %d\n", x);

        k_sleep(K_SECONDS(1));
        int state = 0;
        pm_device_state_get(i2c_dev, &state);
        printk("I2C device state before poweroff: %d\n", state);

        const struct device *gpio0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
        const struct device *gpio1 = DEVICE_DT_GET(DT_NODELABEL(gpio1));
        if (!device_is_ready(gpio0)) 
        {
                printk("GPIO0 not ready\n");
                return 0;
        }

        if(!device_is_ready(gpio1)) 
        {
                printk("GPIO1 not ready\n");
                return 0;
        }

        for (int i = 0; i < 32; i++) 
        {
            gpio_pin_configure(gpio0, i, GPIO_DISCONNECTED);
        }

        for (int i = 0; i < 16; i++) 
        {
            gpio_pin_configure(gpio1, i, GPIO_DISCONNECTED);
        }

        printk("Disconnecting GPIO pins 4 and 5 %d %d\n", gpio_pin_configure(gpio0, 4, GPIO_DISCONNECTED), gpio_pin_configure(gpio0, 5, GPIO_DISCONNECTED));
        //gpio_pin_configure(gpio0, 4, GPIO_DISCONNECTED);
        //gpio_pin_configure(gpio0, 5, GPIO_DISCONNECTED);
        k_sleep(K_MSEC(1000));
        const struct device *cons = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
        if (device_is_ready(cons)) 
        {
                printk("Suspending console device\n");
                k_sleep(K_MSEC(100));
                pm_device_action_run(cons, PM_DEVICE_ACTION_SUSPEND);
        }

        const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(p25q16h));
        pm_device_action_run(flash_dev, PM_DEVICE_ACTION_SUSPEND);

        sys_poweroff();

        while(1)
        {
                k_sleep(K_MSEC(50));
        }
        return 0;
}
