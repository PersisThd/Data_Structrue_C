#include <stdio.h>
#define MAXSIZE 100

typedef struct SqQuene
{
    int rear;
    void* data[MAXSIZE];
}SqQuene;

void InitQuene(SqQuene*);
int QueneEmpty(SqQuene*);
int QueneLength(SqQuene*);
void GetFront(SqQuene*, void**);
void EnQuene(SqQuene*, void*);
void DeQuene(SqQuene*, void**);
void ClearQuene(SqQuene*);
