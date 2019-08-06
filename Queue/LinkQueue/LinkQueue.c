#include <stdio.h>
#include "LinkQueue.h"

void InitQueue(LinkQueue* lq)
{
    lq->front = NULL;
    lq->rear = NULL;
    lq->length = 0;
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

void GetFront(LinkQueue* lq, Node** e)
{
    if(lq->length == 0)
    {
        printf("空队列！\n");
        return;
    }

    *e = lq->front;
}

void EnQueue(LinkQueue* lq, Node* e)
{
    if(lq->length == 0)
    {
        lq->front = lq->rear = e;
    }
    else
    {
        lq->rear->next = e;
        lq->rear = lq->rear->next;
    }

    lq->length++;
}

void DeQueue(LinkQueue* lq, Node** e)
{
    if(lq->length == 0)
    {
        printf("空队列！\n");
        return;
    }

    *e = lq->front;
    lq->front = lq->front->next;
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
        Node* tmp;
        DeQueue(lq, (Node**)&tmp);
    }
}




