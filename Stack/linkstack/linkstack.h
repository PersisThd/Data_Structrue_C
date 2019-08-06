#include <stdio.h>

typedef struct Node
{
    struct Node* next;
}Node;

typedef struct LinkStack
{
    int length;
    Node* top;  //栈顶指针，永远指向第一个数据结点
}LinkStack;


void InitStack(LinkStack*);
int StackEmpty(LinkStack*);
int StackLength(LinkStack*);
void GetTop(LinkStack*, Node**);
void PopStack(LinkStack*, Node**);
void PushStack(LinkStack*, Node*);
void ClearStack(LinkStack*);
int isnumber(char);
int isoperator(char);
int cacluate(int, int, char);
void convert(LinkStack*, char*);


