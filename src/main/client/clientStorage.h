//
// Created by fi0x on 18.12.20.
//

#ifndef LITTLEBOTNET_CLIENTSTORAGE_H
#define LITTLEBOTNET_CLIENTSTORAGE_H

#endif //LITTLEBOTNET_CLIENTSTORAGE_H

typedef struct KnownClient
{
    struct KnownClient *prev;
    struct KnownClient *next;
    char clientID[32];
    int clientIP;
} KnownClient;

void addClientToKnownClients();