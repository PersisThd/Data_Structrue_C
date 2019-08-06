#include <stdio.h>
#include <string.h>
#include "SqStack.h"

//栈的初始化
void InitStack(SqStack* S)
{
    //空栈
    S->top = -1;
    memset(S->data, 0, sizeof(S->data));
}

int StackEmpty(SqStack* S)
{
    if(S->top == -1)
    {
        return 1;
    }

    return 0;
}

void ClearStack(SqStack* S)
{
    S->top = -1;
}

void GetTop(SqStack* S, void** e)
{
    if(S->top == -1)
    {
        printf("当前栈为空栈！");
        return;
    }

    *e = S->data[S->top];
}

void PushStack(SqStack* S, void* e)
{
    if(S->top == MAXSIZE - 1)
    {
        printf("栈满，无法压栈！");
        return;
    }
    S->top++;
    S->data[S->top] = e;
}

void PopStach(SqStack* S, void** e)
{
    if(S->top == -1)
    {
        printf("空栈，无法出栈！");
        return;
    }
    *e = S->data[S->top];
    S->top--;
}

int StackLength(SqStack* S)
{
    return S->top+1;
}
