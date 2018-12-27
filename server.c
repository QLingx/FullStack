#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <stdio.h>
#include <arpa/inet.h>

#include "server.h"

static inline int createSocket(unsigned int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        fprintf(stderr, "failed to socket\n");
        exit(-1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        fprintf(stderr, "Failed to call bind\n");
        exit(-1);
    }

    if (listen(sock, 1) < 0)
    {
        fprintf(stderr, "Failed to call listen\n");
        exit(-1);
    }
    return sock;
}

void serverServe(Server *server)
{
    int sock = createSocket(server->port);
    int newSock;
    int nfds = sock + 1;

    struct sockaddr_in addr;
    socklen_t size = sizeof(addr);

    fd_set activeFDs;
    fd_set readFDs;

    FD_ZERO(&activeFDs);
    FD_SET(sock, &activeFDs);

    fprintf(stdout, "Server Listen on port %d\n", 8080);

    while (1)
    {
        readFDs = activeFDs;

        if (select(nfds, &readFDs, NULL, NULL, NULL) == -1)
        {
            fprintf(stderr, "Failed to call select\n");
            exit(-1);
        }

        if (FD_ISSET(sock, &readFDs))
        {
            newSock = accept(sock, (struct sockaddr *)&addr, &size);

            if (newSock < 0)
            {
                fprintf(stderr, "Failed to call accept\n");
                exit(-1);
            }

            if (newSock > nfds)
            {
                nfds = newSock + 1;
            }
            FD_SET(newSock, &activeFDs);
        }

        for (int fd = sock + 1; fd < nfds; fd++)
        {
            if (FD_ISSET(fd, &readFDs))
            {
                fprintf(stdout, "handle socket %d", fd);
            }
        }
    }
}