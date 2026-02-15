#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/pm/device.h>

#include <zephyr/drivers/display.h>
#include <zephyr/drivers/i2c.h>

#include <utils.h>
#include <appBasic.h>
#include <appIncludes.h>

int main(void)
{
        k_sleep(K_SECONDS(1));
        printk("FitBoy Mk.3\n");
        k_sleep(K_SECONDS(1));
        
        const struct device *display;
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
        
        display_set_contrast(display, 32);

        int x = 0;
        uint8_t mpu_sleep_cmd[] = {0x6B, 0x40}; 
        x = i2c_write(i2c_bus, mpu_sleep_cmd, sizeof(mpu_sleep_cmd), 0x68);
        printk("MPU sleep command write returned %d\n", x);

        const struct device *flash_dev = DEVICE_DT_GET(DT_NODELABEL(p25q16h));
        pm_device_action_run(flash_dev, PM_DEVICE_ACTION_SUSPEND);

        buttonInit();
        
        App apps[] = {mainMenuApp, notificationViewerApp,settingsApp};
        AppManagerSetup(apps, 3);

        while(1)
        {
                print_heap_stats();
                print_lvgl_heap_usage();
                k_sleep(K_SECONDS(5));
        }
        return 0;
}
