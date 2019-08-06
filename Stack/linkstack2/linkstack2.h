#include <stdio.h>

typedef struct Node
{
    struct Node* next;
}Node;

typedef struct StackNode  //ҵ����
{
    Node node;
    void* data;
}StackNode;

typedef struct LinkStack
{
    int length;
    StackNode* top;
}LinkStack;

void InitStack(LinkStack*);  //��ʼ��ջ
int StackEmpty(LinkStack*);   //�ж�ջ�Ƿ�Ϊ��
int StackLength(LinkStack*);   //����ջ�Ĵ�С
void GetTop(LinkStack*, void**);   //��ȡջ��Ԫ��ֵ
void PushStack(LinkStack*, void*);   //��ջ
void PopStack(LinkStack*, void**);   //��ջ
void ClearStack(LinkStack*);    //���ջ
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

