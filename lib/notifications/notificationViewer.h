#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/posix/time.h>
#include <ctype.h>
#include <time.h>
#include <globals.h>

//d2fa52f9-4c5d-4a05-a010-c26a1b99f5e6
#define NOTIFICATION_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0xd2fa52f9, 0x4c5d, 0x4a05, 0xa010, 0xc26a1b99f5e6)
static struct bt_uuid_128 notification_service_uuid = BT_UUID_INIT_128(NOTIFICATION_SERVICE_UUID_VAL);

//05590c96-12bb-11ee-be56-0242ac120002
#define NOTIF_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x05590c96, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 notif_char_uuid = BT_UUID_INIT_128(NOTIF_CHAR_UUID_VAL);

char notificationText[256] = {0};

static ssize_t notificationSet(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			     const void *buf, uint16_t len, uint16_t offset,
			     uint8_t flags)
{
    if (len >= sizeof(notificationText) - 1) 
    {
        printk("Invalid notification length\n");
        return -EINVAL;
    }
    memcpy(notificationText, buf, len);
    notificationText[len] = 0; 
    printk("Received notification: %s\n", notificationText);
    return len;
}

BT_GATT_SERVICE_DEFINE(notification_service,
    BT_GATT_PRIMARY_SERVICE(&notification_service_uuid),
    BT_GATT_CHARACTERISTIC(&notif_char_uuid.uuid,
                           BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE,
                           BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, 
                           0, notificationSet, 
                           &notificationText),
);