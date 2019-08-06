#include <stdio.h>

typedef struct Node
{
    struct Node* next;
}Node;

typedef struct QueueNode
{
    Node P;
    void* data;
}QueueNode;

typedef struct LinkQueue
{
    int length;
    QueueNode* front;
    QueueNode* rear;
}LinkQueue;

void InitQueue(LinkQueue*);
int QueueEmpty(LinkQueue*);
int QueueLength(LinkQueue*);
void GetFront(LinkQueue*, void**);
void EnQueue(LinkQueue*, void*);
void DeQueue(LinkQueue*, void**);
void ClearQueue(LinkQueue*);
