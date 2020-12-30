//
// Created by fi0x on 18.12.20.
//

#ifndef LITTLEBOTNET_CLIENTSTORAGE_H
#define LITTLEBOTNET_CLIENTSTORAGE_H

#endif //LITTLEBOTNET_CLIENTSTORAGE_H

typedef struct KnownClient
{
    struct KnownClient *prev;   //Previous client in list
    struct KnownClient *next;   //Next client in list
    char clientID[32];          //Random ID to identify client
    int clientIP;               //Store the IP of the client
    long lastConnection;         //Stores timestamp of last time client was online
} KnownClient;

int addClientToKnownClients(KnownClient *client);   //Add a new client to the list of known clients
int removeLeastActiveClient();                      //Remove the client with the oldes "lastConnection" from the known clients