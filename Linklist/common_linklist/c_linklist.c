#include <stdio.h>
#include <stdlib.h>
#include "c_linklist.h"

void InitList(LINKLIST *L)
{
    L->length = 0;
    L->header.node.next = NULL;
}

int ListEmpty(LINKLIST *L)
{
    if(L->length == 1)
        return 1;

    return 0;
}

int ListLength(LINKLIST* L)
{
    return L->length;
}

void GetElem(LINKLIST* L, int pos, void **e)
{
    if(pos < 0 || pos >= L->length)
        return;
    if(L->length == 0)
        return;

    ListNode* pCur = &L->header;

    int i = 0;
    for(i = 0; i < pos+1; i++)
    {
        //pCur->node.next返回一个node类型，因为其首地址与ListNode的首地址重合，强制类型转换后其取的内存区域大小占ListNode
        pCur = (ListNode*)pCur->node.next;
    }
    *e = pCur->data;
}

void ListInsert(LINKLIST* L, int pos, void *e)
{
    if(pos < 0 || pos > L->length)
        return;

    ListNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = (ListNode*)pCur->node.next;
    }

    ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
    pNew->node.next = pCur->node.next;
    pNew->data = e;
    pCur->node.next = &pNew->node;

    L->length++;
}

void ListDel(LINKLIST* L, int pos, void **e)
{
    if(pos < 0 || pos >= L->length)
        return;
    if(L->length == 0)
        return;

    ListNode* pCur = &L->header;
    int i = 0;
    for(i = 0; i < pos; i++)
    {
        pCur = (ListNode*)pCur->node.next;
    }

    ListNode* pDel;
    pDel = (ListNode*)pCur->node.next;
    *e = pDel->data;

    pCur->node.next = pDel->node.next;

    free(pDel);
    L->length--;
}

void ClearList(LINKLIST* L)
{
    while(L->length)
    {
        void * tmp;
        ListDel(L, 0, &tmp);
    }
}

void DestroyList(LINKLIST* L)
{
    ClearList(L);
}
