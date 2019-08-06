#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_doublelist.h"

void InitList(DoubleList* L)
{
    L->header.node.next = NULL;
    L->header.node.prior = NULL;
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

void ListInsert(DoubleList* L, int pos, void* e)
{
    if(pos < 0 || pos > L->length)
    {
        printf("插入位置非法！");
        return;
    }


    DoubleNode* pCur = &L->header;

    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = (DoubleNode*)pCur->node.next;
    }

    DoubleNode* pNew = (DoubleNode*)malloc(sizeof(DoubleNode));
    if(pos == L->length)
    {
        pNew->data = e;
        pNew->node.prior = &pCur->node;
        pCur->node.next = &pNew->node;
        pNew->node.next = NULL;
        L->length++;
        return;
    }

    pNew->data = e;
    pNew->node.next = pCur->node.next;
    pCur->node.next->prior = &pNew->node;
    pCur->node.next = &pNew->node;
    pNew->node.prior = &pCur->node;

    L->length++;
}

void PrintList(DoubleList* L)
{
    if(L->length == 0)
    {
        printf("链表为空，无法打印！");
        return;
    }

    DoubleNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        pCur = (DoubleNode*)pCur->node.next;
        char* str = (char *)pCur->data;
        printf("链表中位置%d的值为：%s\n", i, str);
    }
}

void PrintList_Reverse(DoubleList* L)
{
    if(L->length == 0)
    {
        printf("链表为空，无法打印！");
        return;
    }


    DoubleNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < L->length; i++)
    {
        pCur = (DoubleNode*)pCur->node.next;   //指向最后一个结点
    }

    for(i = L->length - 1; i >= 0; i--)
    {
        char* str = (char*)pCur->data;
        printf("链表中位置为%d的值为：%s\n", i, str);
        pCur = (DoubleNode*)pCur->node.prior;
    }
}

void CreateList(DoubleList* L, int n)
{
    if(n <= 0)
        printf("输入的链表长度非法！");


    int i = 0;
    char* s[3];

    for(i = 0; i < 3; i++)
    {
        s[i] = (char*)malloc(sizeof(char*));
    }


    for(i = 0; i < 3; i++)
    {

        char tmp[20];
        printf("请输入位置%d处的值：\n", i);
        gets(tmp);
        strcpy(s[i], tmp);
        ListInsert(L, i, s[i]);
    }
}

void ListDelete(DoubleList* L, int pos, void** e)
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


    DoubleNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = (DoubleNode*)pCur->node.next;
    }

    DoubleNode* pDel = (DoubleNode*)malloc(sizeof(DoubleNode));

    if(pos == L->length-1)
    {
        pDel = (DoubleNode*)pCur->node.next;
        *e = pDel->data;
        pCur->node.next = NULL;
        free(pDel);
        L->length--;
        return;
    }

    pDel = (DoubleNode*)pCur->node.next;
    *e = pDel->data;

    pCur->node.next = pDel->node.next;
    pDel->node.next->prior = &pCur->node;
    free(pDel);
    L->length--;
}

void GetElem(DoubleList* L, int pos, void** e)
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

    DoubleNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos + 1; i++)
    {
        pCur = (DoubleNode*)pCur->node.next;
    }

    *e = pCur->data;
}

void ClearList(DoubleList* L)
{
    while(L->length)
    {
        void* tmp;
        ListDelete(L, 0, &tmp);
    }
}

void DestroyList(DoubleList* L)
{
    ClearList(L);
    free(L);
}
