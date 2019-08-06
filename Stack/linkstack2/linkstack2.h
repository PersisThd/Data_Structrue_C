#include <stdio.h>

typedef struct Node
{
    struct Node* next;
}Node;

typedef struct StackNode  //业务结点
{
    Node node;
    void* data;
}StackNode;

typedef struct LinkStack
{
    int length;
    StackNode* top;
}LinkStack;

void InitStack(LinkStack*);  //初始化栈
int StackEmpty(LinkStack*);   //判断栈是否为空
int StackLength(LinkStack*);   //返回栈的大小
void GetTop(LinkStack*, void**);   //获取栈顶元素值
void PushStack(LinkStack*, void*);   //入栈
void PopStack(LinkStack*, void**);   //出栈
void ClearStack(LinkStack*);    //清空栈
int isleft(char);
int isright(char);
int isMatch(char, char);
void NearMatch(LinkStack*, const char*);
int isnumber(char);
int priority(char);
int isoperator(char);
void ConvertExpression(LinkStack*, char*);
void counter(LinkStack*, char*);
int cacluate(int, int, char);

