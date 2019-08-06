#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

void InitList(DoubleList* L)
{
    L->header.next = NULL;
    L->length = 0;
}

int ListEmpty(DoubleList* L)
{
    if(L->length == 0)
        return 1;
    else
        return 0;
}

int ListLength(DoubleList* L)
{
    return L->length;
}

void ListInsert(DoubleList* L, int pos, int e)
{
    if(pos < 0 || pos > L->length)
    {
        printf("插入位置非法！");
        return;
    }


    Node* pCur = &L->header;

    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pNew = (Node*)malloc(sizeof(Node));
    if(pos == L->length)
    {
        pNew->data = e;
        pNew->prior = pCur;
        pCur->next = pNew;
        pNew->next = NULL;
        L->length++;
        return;
    }

    pNew->data = e;
    pNew->next = pCur->next;
    pCur->next->prior = pNew;
    pCur->next = pNew;
    pNew->prior = pCur;

    L->length++;
}

void PrintList(DoubleList* L)
{
    if(L->length == 0)
    {
        printf("链表为空，无法打印！");
        return;
    }

    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        pCur = pCur->next;
        printf("链表中位置%d的值为：%d\n", i, pCur->data);
    }
}

void PrintList_Reverse(DoubleList* L)
{
    if(L->length == 0)
    {
        printf("链表为空，无法打印！");
        return;
    }


    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        pCur = pCur->next;   //指向最后一个结点
    }

    for(i = L->length - 1; i >= 0; i--)
    {
        printf("链表中位置为%d的值为：%d\n", i, pCur->data);
        pCur = pCur->prior;
    }
}

void CreateList(DoubleList* L, int n)
{
    if(n <= 0)
        printf("输入的链表长度非法！");


    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("请输入链表位置%d处的值：\n", i);
        int num = 0;
        scanf("%d", &num);
        ListInsert(L, i, num);
    }
}

void ListDelete(DoubleList* L, int pos, int* e)
{
    if(pos < 0 || pos >= L->length)
    {
        printf("删除位置非法，无法删除！");
        return;
    }

    if(L->length == 0)
    {
        printf("链表为空，无法删除！");
        return;
    }


    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = pCur->next;
    }

    Node* pDel = (Node*)malloc(sizeof(Node));

    if(pos == L->length-1)
    {
        pDel = pCur->next;
        pCur->next = NULL;
        free(pDel);
        L->length--;
        return;
    }

    pDel = pCur->next;
    *e = pDel->data;

    pCur->next = pDel->next;
    pDel->next->prior = pCur;
    free(pDel);
    L->length--;
}

void GetElem(DoubleList* L, int pos, int* e)
{
    if(pos < 0 || pos >= L->length)
    {
        printf("查询位置非法！");
        return;
    }

    if(L->length == 0)
    {
        printf("链表为空！");
    }

    Node* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos + 1; i++)
    {
        pCur = pCur->next;
    }

    *e = pCur->data;
}

void ClearList(DoubleList* L)
{
    while(L->length)
    {
        int tmp;
        ListDelete(L, 0, &tmp);
    }
}

void DestroyList(DoubleList* L)
{
    ClearList(L);
    free(L);
}
