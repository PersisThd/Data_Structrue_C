#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

void InitQueue(LinkQueue* lq)
{
    lq->length = 0;
    lq->front = NULL;
    lq->rear = NULL;
}

int QueueEmpty(LinkQueue* lq)
{
    if(lq->length == 0)
        return 1;
    return 0;
}

int QueueLength(LinkQueue* lq)
{
    return lq->length;
}

void GetFront(LinkQueue* lq, void** e)
{
    if(lq->length == 0)
    {
        printf("空队列！\n");
        return;
    }

    *e = lq->front->data;
}

void EnQueue(LinkQueue* lq, void* e)
{
    QueueNode* pNew = (QueueNode*)malloc(sizeof(QueueNode));
    pNew->data = e;

    if(lq->length == 0)
    {
        lq->front = lq->rear = pNew;
    }
    else
    {
        lq->rear->P.next = &pNew->P;
        lq->rear = pNew;
    }
    lq->length++;
}

void DeQueue(LinkQueue* lq, void** e)
{
    if(lq->length == 0)
    {
        printf("空队列！\n");
        return;
    }

    QueueNode* pDel;
    pDel = lq->front;
    *e = pDel->data;
    lq->front = (QueueNode*)pDel->P.next;
    free(pDel);

    lq->length--;
    if(lq->length == 0)
    {
        lq->rear = NULL;
    }
}
void ClearQueue(LinkQueue* lq)
{
    while(lq->length)
    {
        void* tmp;
        DeQueue(lq, (void**)&tmp);
    }
}
