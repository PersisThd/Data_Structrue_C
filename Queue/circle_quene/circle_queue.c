#include "circle_queue.h"
#include <string.h>


void InitQueue(cqueue* cq)
{
    cq->front = -1;
    cq->rear = -1;
    memset(cq->data, 0, sizeof(cq->data));
}

int QueueEmpty(cqueue* cq)
{
    if(cq->front == cq->rear)
        return 1;

    return 0;
}

int QueueLength(cqueue* cq)
{
    return (cq->rear - cq->front + MAXSIZE) % MAXSIZE;
}

void GetFront(cqueue* cq, void** e)
{
    if(QueueEmpty(cq))
    {
        printf("空队列！\n");
        return;
    }

    *e = cq->data[cq->front + 1];
}

void EnQueue(cqueue* cq, void* e)
{
    if((cq->rear + 1) % MAXSIZE == cq->front)
    {
        printf("队满！\n");
        return;
    }

    cq->rear = (cq->rear + 1) % MAXSIZE;
    cq->data[cq->rear] = e;
}

void DeQueue(cqueue* cq, void** e)
{
    if(QueueEmpty(cq))
    {
        printf("空队列！\n");
        return;
    }

    *e = cq->data[cq->front + 1];
    cq->front = (cq->front + 1) % MAXSIZE;
}

void ClearQueue(cqueue* cq)
{
    while(!QueueEmpty(cq))
    {
        void* tmp;
        DeQueue(cq, &tmp);
    }
}
