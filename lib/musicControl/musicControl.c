#include <appBasic.h>
#include <notificationViewer.h>
#include <utils.h>
#include <styles.h>

//019c9698-ccae-7bd0-9976-3017ee420aba
#define MUSIC_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x019c9698, 0xccae, 0x7bd0, 0x9976, 0x3017ee420aba)
static struct bt_uuid_128 music_service_uuid = BT_UUID_INIT_128(MUSIC_SERVICE_UUID_VAL);

//6ddb28be-a927-11ee-a506-0242ac120002
#define MUSIC_CONTROL_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x06ddb28be, 0xa927, 0x11ee, 0xa506, 0x0242ac120002)
static struct bt_uuid_128 music_control_char_uuid = BT_UUID_INIT_128(MUSIC_CONTROL_CHAR_UUID_VAL);

//5df4d2b0-a927-11ee-a506-0242ac120002
#define MUSIC_METADATA_CHAR_UUID_VAL BT_UUID_128_ENCODE(0x05df4d2b0, 0xa927, 0x11ee, 0xa506, 0x0242ac120002)
static struct bt_uuid_128 music_metadata_char_uuid = BT_UUID_INIT_128(MUSIC_METADATA_CHAR_UUID_VAL);