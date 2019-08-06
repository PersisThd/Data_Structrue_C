#include <stdio.h>

typedef struct Node
{
    struct Node* next;
}Node;

typedef struct LinkQueue
{
    Node* front;
    Node* rear;
    int length;
}LinkQueue;

void InitQueue(LinkQueue*);
int QueueEmpty(LinkQueue*);
int QueueLength(LinkQueue*);
void GetFront(LinkQueue*, Node**);
void EnQueue(LinkQueue*, Node*);
void DeQueue(LinkQueue*, Node**);
void ClearQueue(LinkQueue*);
