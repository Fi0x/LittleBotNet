//
// Created by fi0x on 18.12.20.
//

#include "clientStorage.h"
#include "stdio.h"

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

int removeLeastActiveClient()
{
    //TODO: Iterate list and remove client with oldest "lastConnection"
}