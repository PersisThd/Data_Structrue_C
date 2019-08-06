#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;  //��������ṹ

typedef struct LINKLIST
{
    int length;
    Node header;
}LINKLIST;  //�ٿ�����

void InitList(LINKLIST*);  //��ʼ������
int ListEmpty(LINKLIST*);  //�ж������Ƿ�Ϊ��
int ListLength(LINKLIST*);  //����������
void GetElem(LINKLIST*, int, int *);  //��ȡָ��λ�õ�Ԫ�أ�pos��0��ʼ��
void ListInsert(LINKLIST*, int, int); //��ָ��λ���в�����Ԫ��
void ListDel(LINKLIST*, int, int *);  //ɾ��ָ��λ�õ�Ԫ��
void ClearList(LINKLIST*);  //�������
void DestroyList(LINKLIST*);  //��������
