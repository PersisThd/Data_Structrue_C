#include <stdio.h>
#include <string.h>
#include "SqQuene.h"

void InitQuene(SqQuene* sq)
{
    sq->rear = -1;
    memset(sq->data, 0, sizeof(sq->data));
}

int QueneEmpty(SqQuene* sq)
{
    if(sq->rear == -1)
        return 1;
    return 0;
}

int QueneLength(SqQuene* sq)
{
    return sq->rear + 1;
}

void ClearQuene(SqQuene* sq)
{
    sq->rear = -1;
}

void GetFront(SqQuene* sq, void** e)
{
    if(sq->rear == -1)
    {
        printf("队列为空，无法出队！\n");
        return;
    }

    *e = sq->data[0];
}

void EnQuene(SqQuene* sq, void* e)
{
    if(sq->rear == MAXSIZE - 1)
    {
        printf("队列已满，无法入队！\n");
        return;
    }

    sq->rear++;
    sq->data[sq->rear] = e;
}

void DeQuene(SqQuene* sq, void** e)
{
    if(sq->rear == -1)
    {
        printf("空队列，无法出队！\n");
        return;
    }

    *e = sq->data[0];

    int i = 1;
    for(i = 1; i <= sq->rear; i++)
    {
        sq->data[i-1] = sq->data[i];
    }

    sq->rear--;

}
