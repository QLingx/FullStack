#ifndef REQUEST_H
#define REQUEST_H

#include "list.h"

typedef enum Method{
    OPTIONS,GET,HEAD,POST,PUT,DELETE,TRACE,CONNECT,UNKNOWN_METHOD
}Method;

typedef struct Request{
    Method method;
    char *path;
    char *uri;
    ListCell* queryString;
    ListCell* postBody;
    ListCell* cookies;
    ListCell* headers;
}Request;

Request* newRequest(char*);
void delRequest(Request*);

#endif