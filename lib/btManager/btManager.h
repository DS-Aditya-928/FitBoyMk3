#pragma once

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

struct BTDePacket
{
    char inPacket[256];
    char* finalStr;

    bool processing;

    uint16_t textIndex;
    uint16_t textLen;
};

typedef enum
{
    DONE,
    WORKING,
    FAIL
} PacketProcessState;

int BTSetup(void);
PacketProcessState processPackets(char* buf, uint16_t pLen, struct BTDePacket* procData);
bool packetizeSend(char* toSend, const struct bt_gatt_attr* attr);