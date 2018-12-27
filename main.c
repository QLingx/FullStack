#include <stdio.h>
#include "server.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    Server *serv = (Server *)malloc(sizeof(Server));
    serv->port = 8080;

    serverServe(serv);

    return 0;
}