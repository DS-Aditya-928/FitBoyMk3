#include <btManager.h>
#include <utils.h>

//1f55d926-12bb-11ee-be56-0242ac120002
#define MAIN_SERVICE_UUID_VAL BT_UUID_128_ENCODE(0x1f55d926, 0x12bb, 0x11ee, 0xbe56, 0x0242ac120002)
static struct bt_uuid_128 main_service_uuid = BT_UUID_INIT_128(MAIN_SERVICE_UUID_VAL);
//just for advertising purposes ig

BT_GATT_SERVICE_DEFINE(main_service,
    BT_GATT_PRIMARY_SERVICE(&main_service_uuid),
    // Client Characteristic Configuration
    //BT_GATT_CCC(my_ccc_cfg_changed, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),
);

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_UUID128_ALL,
		      MAIN_SERVICE_UUID_VAL,)
};

static const struct bt_data sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		printk("Connection failed, err 0x%02x %s\n", err, bt_hci_err_to_str(err));
	} else {
		printk("Connected\n");
		//(void)atomic_set_bit(state, STATE_CONNECTED);
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	printk("Disconnected, reason 0x%02x %s\n", reason, bt_hci_err_to_str(reason));

	//(void)atomic_set_bit(state, STATE_DISCONNECTED);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = connected,
	.disconnected = disconnected,
};

int BTSetup(void)
{
    int err;

    err = bt_enable(NULL);
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
        return err;
    }

    printk("Bluetooth initialized\nStarting advertising...\n");

    err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_1, ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
	if (err) {
		printk("Advertising failed to start (err %d)\n", err);
		return 0;
	}    

    printk("Advertising successfully started\n");

    return 0;
}


PacketProcessState processPackets(char* buf, uint16_t pLen, struct BTDePacket* procData)
{
    if(!procData)
    {
        return FAIL;
    }

    if (pLen >= sizeof(procData->inPacket) - 1) 
    {
        printk("Invalid notification length\n");
        return FAIL;
    }

    if(!procData->processing)
    {
        //print_heap_stats();
        procData->finalStr = (char*)k_calloc((*(int16_t*)buf) + 1, sizeof(char));
        if(procData->finalStr == NULL)
        {
            printk("Failed to allocate memory for incoming data.\n");
            return FAIL;
        }

        //printk("Allocated %d bytes for incoming data\n", (*(int16_t*)buf) + 1);
        procData->textLen = *(int16_t*)(buf);
        procData->processing = true;
        procData->textIndex += pLen - 2;
        memcpy(procData->finalStr, (char*)buf + 2, pLen - 2);
    }

    else
    {
        memcpy(procData->finalStr + procData->textIndex, buf, pLen);
        procData->textIndex += pLen;
    }

    //printk("Received chunk: %d bytes, total received: %d/%d\n", pLen, procData->textIndex, procData->textLen);

    if(procData->textIndex >= procData->textLen)
    {
        //printk("Full data received %s bytes, length: %d\n", procData->finalStr, procData->textLen);
        //print_heap_stats();

        procData->textLen = 0;
        procData->textIndex = 0;
        procData->processing = false;

        return DONE;
    }    

    return WORKING;
}