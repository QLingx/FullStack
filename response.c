#include<stdio.h>
#include "response.h"

void responseWrite(Response *response, int fd)
{
    fprintf(stdout,"before send: %d\n",fd);
    send(fd,"http response",13,0);
}