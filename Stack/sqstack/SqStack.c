#include <stdio.h>
#include <string.h>
#include "SqStack.h"

//ջ�ĳ�ʼ��
void InitStack(SqStack* S)
{
    //��ջ
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
        printf("��ǰջΪ��ջ��");
        return;
    }

    *e = S->data[S->top];
}

void PushStack(SqStack* S, void* e)
{
    if(S->top == MAXSIZE - 1)
    {
        printf("ջ�����޷�ѹջ��");
        return;
    }
    S->top++;
    S->data[S->top] = e;
}

void PopStach(SqStack* S, void** e)
{
    if(S->top == -1)
    {
        printf("��ջ���޷���ջ��");
        return;
    }
    *e = S->data[S->top];
    S->top--;
}

int StackLength(SqStack* S)
{
    return S->top+1;
}
