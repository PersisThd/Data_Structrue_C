#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct number
{
    Node P;
    int num;
    //int age;
}number;


void InitStack(LinkStack* st)
{
    st->length = 0;
    st->top = NULL;
}

int StackEmpty(LinkStack* st)
{
    if(st->length == 0)
        return 1;

    return 0;
}

int StackLength(LinkStack* st)
{
    return st->length;
}

void GetTop(LinkStack* st, Node** e)
{
    if(st->length == 0)
    {
        printf("空栈！\n");
        return;
    }

    *e = st->top;
}

void PopStack(LinkStack* st, Node** e)
{
    if(st->length == 0)
    {
        printf("空栈！\n");
        return;
    }

    Node* pDel = st->top;
    *e = pDel;
    st->top = pDel->next;
    st->length--;
}

void PushStack(LinkStack* st, Node* e)
{
    Node* pNew = e;
    pNew->next = st->top;
    st->top = pNew;
    st->length++;
}

void ClearStack(LinkStack* st)
{
    Node* tmp;
    while(st->length)
    {
        PopStack(st, &tmp);
    }
}

int isnumber(char c)
{
    if(c <= '9' && c >= '0')
    {
        return 1;
    }

    return 0;
}

int isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int cacluate(int left, int right, char c)
{
    int result;
    switch(c)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        result = left / right;
        break;
    default:
        break;
    }

    return result;
}

void convert(LinkStack* st, char* p)
{
    int i = 0;
    while(p[i] != '\0')
    {
        if(isnumber(p[i]))
        {
            number* num1 = (number*)malloc(sizeof(number));
            num1->num = p[i] - '0';
            PushStack(st, &num1->P);
        }
        else if(isoperator(p[i]) && st->length != 0)
        {
            int right, left, result;
            Node* tmp;
            PopStack(st, &tmp);
            number* tmp1 = (number*)tmp;
            right = tmp1->num;
            PopStack(st, &tmp);
            tmp1 = (number*)tmp;
            left = tmp1->num;
            result = cacluate(left, right, p[i]);
            number* num2 = (number*)malloc(sizeof(number));
            num2->num = result;
            PushStack(st, &num2->P);
        }
        else
        {
            //printf("后缀表达式有误！\n");
        }

        i++;
    }
    if(st->length == 1)
    {
        Node* tmp;
        PopStack(st, &tmp);
        number* tmp1 = (number*)tmp;
        printf("运算结果为：%d\n", tmp1->num);
    }
}


