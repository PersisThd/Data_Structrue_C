#include <stdio.h>
#define MAXSIZE 10

typedef struct cqueue
{
    int front;
    int rear;
    void* data[MAXSIZE];
}cqueue;

void InitQueue(cqueue*);
int QueueEmpty(cqueue*);
int QueueLength(cqueue*);
void GetFront(cqueue*, void**);
void EnQueue(cqueue*, void*);
void DeQueue(cqueue*, void**);
void ClearQueue(cqueue*);
