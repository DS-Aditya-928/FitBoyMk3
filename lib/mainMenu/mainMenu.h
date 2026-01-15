#include <zephyr/bluetooth/bluetooth.h>

//1f55d926-12bb-11ee-be56-0242ac120007
#define MAINMENU_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x1f55d926, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120007)
static struct bt_uuid_128 mainmenu_service_uuid = BT_UUID_INIT_128(MAINMENU_SERVICE_UUID_VAL);

//93c37a10-1f37-11ee-be56-0242ac120002
#define TIME_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x93c37a10, 0x1f37, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 time_uuid = BT_UUID_INIT_128(TIME_CHAR_UUID_VAL);

uint64_t unixTime = 0;

static ssize_t timeSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if (len != sizeof(uint64_t)) {
        printk("Invalid time length\n");
        return -EINVAL;
    }

    unixTime = *(uint64_t *)buf;
    printk("Received time: %llu\n", unixTime);

    return len;
}

BT_GATT_SERVICE_DEFINE(mainmenu_service,
    BT_GATT_PRIMARY_SERVICE(&mainmenu_service_uuid),
    BT_GATT_CHARACTERISTIC(&time_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, timeSet, 
                           &unixTime),
    // Client Characteristic Configuration
    //BT_GATT_CCC(my_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

void MainMenu()
{
    printk("Main Menu Loaded\n");
}