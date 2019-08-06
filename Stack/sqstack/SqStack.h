#include <stdio.h>
#define MAXSIZE 100

typedef struct SqStack
{
    void* data[MAXSIZE];
    int top;  //指向栈顶下标
}SqStack;

void InitStack(SqStack*);
int StackEmpty(SqStack*);
int StackLength(SqStack*);
void ClearStack(SqStack*);
void GetTop(SqStack*, void**);
void PushStack(SqStack*, void*);
void PopStach(SqStack*, void**);
