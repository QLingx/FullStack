#ifndef SERVER_H
#define SERVER_H

typedef struct Server{
    unsigned int port;
}Server;

void serverServe(Server *server);
#endif