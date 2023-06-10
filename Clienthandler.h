#pragma once
#include "Bible.h"

void ClientHandler(int index) {
    Packet packettype;
    while (true) {
        recv(Connections[index], (char*)&packettype, sizeof(Packet), NULL);

        if (!ProcessPacket(index, packettype)) {
            break;
        }
    }
    closesocket(Connections[index]);
}