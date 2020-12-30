//
// Created by fi0x on 18.12.20.
//

#include "clientStorage.h"
#include "stdio.h"
#include "string.h"

static KnownClient *FirstKnownClient = NULL;

int addClientToKnownClients(KnownClient *client)
{
    if (client == NULL)
    {
        printf("Client to add is NULL");
        return -1;
    }

    if (FirstKnownClient == NULL)
    {
        FirstKnownClient = client;
    } else
    {
        KnownClient *iter = FirstKnownClient;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = client;
        client->prev = iter;
    }

    return 0;
}

int removeClientFromList(char[32] clientID)
{
    KnownClient *iter = FirstKnownClient;
    while (iter != NULL)
    {
        if(strcmp(clientID, iter->clientID))
        {
            if(iter->prev != NULL)
            {
                iter->prev->next = iter->next;
            }
            if(iter->next != NULL)
            {
                iter->next->prev = iter->prev;
            }
            return 0;
        }
    }
    return -2;
}

int removeLeastActiveClient()
{
    if(FirstKnownClient == NULL) return -1;
    KnownClient *oldestClient = FirstKnownClient;
    KnownClient *iter = FirstKnownClient;
    while (iter != NULL)
    {
        if(iter->lastConnection < oldestClient->lastConnection) oldestClient = iter;
        iter = iter->next;
    }

    return removeClientFromList(oldestClient->clientID);
}