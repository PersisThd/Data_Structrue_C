#include <stdio.h>
#include <stdlib.h>
#include "circle_doublelist.h"

void InitList(cir_doublelist* L)
{
    L->header.next = NULL;
    L->header.next = NULL;
    L->length = 0;
}

int ListEmpty(cir_doublelist* L)
{
    if(L->length == 0)
        return 1;

    return 0;
}

int ListLength(cir_doublelist* L)
{
    return L->length;
}

Node* CreateList(cir_doublelist* L, int n)
{
    if(n <= 0)
    {
        printf("����������ȷǷ���");
        return NULL;
    }

    Node* pCur = &L->header;
    Node* head = &L->header;

    int i = 0;
    for(i = 0; i < n; i++)
    {
        Node* pNew = (Node*)malloc(sizeof(Node));
        printf("������������λ��%d����ֵ��\n", i);
        scanf("%d", &pNew->data);
        if(i == 0)
        {
            pCur->next = pNew;
            pCur = pCur->next;
            L->length++;
        }
        else
        {
           pCur->next = pNew;
           pNew->prior = pCur;
           pNew->next = head->next;
           head->next->prior = pNew;
           pCur = pCur->next;
           L->length++;
        }

    }
    return head;

}

void ListTest(cir_doublelist* L, int n)
{
    if(L->length == 0)
    {
        printf("��ǰ����Ϊ������");
        return;
    }

    printf("*****ѭ��˫����˳���������*****\n");

    int i = 0;
    Node* pCur = &L->header;
    for(i = 0; i < n; i++)
    {
        pCur = pCur->next;
        printf("The value is: %d\n", pCur->data);
    }

    printf("\n");
}

void ListTest_Reverse(cir_doublelist* L, int n)
{
    if(L->length == 0)
    {
        printf("��ǰ����Ϊ������");
        return;
    }

    printf("*****ѭ��˫���������������*****\n");

    int i = 0;
    Node* pCur = &L->header;
    for(i = 0; i < L->length; i++)
    {
        pCur = pCur->next;
    }

    for(i = 0; i < n; i++)
    {
        printf("The value is: %d\n", pCur->data);
        pCur = pCur->prior;
    }

    printf("\n");
}

void ListDelete(cir_doublelist* L, int pos, int* e)
{
    if(pos < 0 || pos >= L->length)
    {
        printf("�����λ�÷Ƿ���\n");
        return;
    }
    if(L->length == 0)
    {
        printf("����Ϊ�գ��޷�ɾ����");
    }

    int i = 0;
    Node* pCur = &L->header;
    Node* head = &L->header;   //ʼ��ָ��ͷ���
    Node* tail = &L->header;  //ʼ��ָ�����һ�����

    for(i = 0; i < L->length; i++)
    {
        tail = tail->next;
    }

    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pDel = (Node*)malloc(sizeof(Node));

    if(pos == 0)
    {
        pDel = pCur->next;
        *e = pDel->data;
        pCur->next = pDel->next;
        pDel->next->prior = tail;
        tail->next = pDel->next;
        free(pDel);
        L->length--;
        return;
    }

    if(pos == L->length - 1)
    {
        pDel = pCur->next;
        *e = pDel->data;
        pCur->next = head->next;
        head->next->prior = pCur;
        tail = pCur;  //ɾ�����һ�����ǰ�ǵø���βָ��
        free(pDel);
        L->length--;
        return;
    }

    pDel = pCur->next;
    pCur->next = pDel->next;
    pDel->next->prior = pCur;
    free(pDel);
    L->length--;
}

void ListInsert(cir_doublelist* L, int pos, int e)
{
    if(pos < 0 || pos > L->length)
    {
        printf("����λ�÷Ƿ���");
        return;
    }

    int i = 0;
    Node* pCur = &L->header;
    Node* head = &L->header;
    Node* tail = &L->header;

    for(i = 0; i < L->length; i++)
    {
        tail = tail->next;
    }

    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pNew = (Node*)malloc(sizeof(pNew));
    pNew->data = e;

    if(pos == 0)
    {
        pNew->next = pCur->next;
        pCur->next->prior = pNew;
        pCur->next = pNew;
        pNew->prior = tail;
        tail->next = pNew;
        L->length++;
        return;
    }

    if(pos == L->length)
    {
        pCur->next = pNew;
        pNew->prior = pCur;
        pNew->next = head->next;
        head->next->prior = pNew;
        tail = pNew;  //��������ʱ�ǵø���βָ��
        L->length++;
        return;
    }

    pNew->next = pCur->next;
    pCur->next->prior = pNew;
    pNew->prior = pCur;
    pCur->next = pNew;
    L->length++;

}

void GetElem(cir_doublelist* L, int pos, int* e)
{
    if(pos < 0 || pos >= L->length)
    {
        printf("��ѯλ�÷Ƿ���");
    }

    if(L->length == 0)
    {
        printf("����Ϊ������");
    }

    int i = 0;
    Node* pCur = &L->header;

    for(i = 0; i <= pos; i++)
    {
        pCur = pCur->next;
    }

    *e = pCur->data;
}

void ClearList(cir_doublelist* L)
{
    while(L->length)
    {
        int tmp;
        ListDelete(L, 0, &tmp);
    }
}

void DestroyList(cir_doublelist* L)
{
    ClearList(L);
    free(L);
    printf("��ǰ���������٣�");
}
