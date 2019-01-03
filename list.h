#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

typedef enum IterationResult
{
    BREAK,
    DONE
} IterationResult;

typedef struct Cell
{
    struct Cell *next;

    void *value;
    size_t size;
} ListCell;

ListCell listCons(void *, size_t, ListCell *);
ListCell listReverse(ListCell *);
void listDel(ListCell *);
IterationResult listForEach(ListCell *, IterationResult);
#endif
