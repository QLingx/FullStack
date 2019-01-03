#include<stdio.h>
#include<string.h>
#include "request.h"
#include "list.h"

static inline char *urlDecode(char *segment)
{
    return "";
}

static inline char *parseCookies(char *segment){
    return "";
}

static inline ListCell *parseQS(char *path){
    return NULL;
}

static inline ListCell *parseHeaders(char *segment)
{
    return NULL;
}


Request *newRequest(char *buff)
{
    Request *request = (Request *)malloc(sizeof(Request));

    request->method = UNKNOWN_METHOD;
    request->path = "";
    request->uri = "";
    request->queryString = NULL;
    request->postBody = NULL;
    request->cookies = NULL;
    request->headers = NULL;

    char *segment, *bs;

    fprintf(stdout,buff);
    segment = strtok(buff, " \t");

    if (!segment)
    {
        goto fail;
    }

    if (!strcmp(segment, "OPTIONS"))
        request->method = OPTIONS;
    else if (!strcmp(segment, "GET"))
        request->method = GET;
    else if (!strcmp(segment, "HEAD"))
        request->method = HEAD;
    else if (!strcmp(segment, "POST"))
        request->method = POST;
    else if (!strcmp(segment, "PUT"))
        request->method = PUT;
    else if (!strcmp(segment, "DELETE"))
        request->method = DELETE;
    else if (!strcmp(segment, "TRACE"))
        request->method = TRACE;
    else if (!strcmp(segment, "CONNECT"))
        request->method = CONNECT;
    else
        goto fail;

fail:
    delRequest(request);
    return NULL;
}

void delRequest(Request *req)
{
    free(req);
}