#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct CircleList  //���ڹ���ѭ������
{
    int length;
    Node header;  //ͷ�ڵ�
}CircleList;

void InitList(CircleList*);  //����ĳ�ʼ��
Node* CreateList(CircleList*, int);  //����ѭ������
void GetElem(CircleList*, int, int*);  //ȡ��ѭ�������е�ָ��λ�õ�Ԫ��ֵ
void ListInsert(CircleList*, int, int);  //ѭ������Ĳ������
void ListDelete(CircleList*, int, int*);  //ѭ�������ɾ������
int ListEmpty(CircleList*);  //�ж�ѭ�������Ƿ�Ϊ��
int ListLength(CircleList*);  //����ѭ������ĳ���
void ListTest(CircleList*);
void ClearList(CircleList*);
void Josephus(CircleList*);
