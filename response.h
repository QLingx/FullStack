#ifndef RESPONSE_H
#define RESPONSE_H

#include "list.h"

typedef enum Status
{
    CONTINUE = 100,
    OK = 200,
    MULTIPLE_CHOICE = 300,
    BAD_REQUEST = 400,
    INTERNAL_SERVER_ERROR = 500,
} Status;

typedef struct Response
{
    Status status;

    ListCell *headers;
    char *body;
} Response;

Response *responseNew();
Response *responseNewRedirect(char *);
void responseSetStatus(Response *, Status);
void responseSetBody(Response *, char *);
void responseAddCookie(Response *, char *, char *, char *, char *, int);
void responseAddHeader(Response *, char *, char *);
void responseDel(Response *);
void responseWrite(Response *, int);

#endif