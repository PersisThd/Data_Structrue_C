#include <stdio.h>
#include <stdlib.h>
#include "circle_doublelist.h"

int main()
{
    cir_doublelist ls;
    InitList(&ls);

    printf("请输入链表的长度：");
    int len;
    scanf("%d", &len);

    CreateList(&ls, len);
    ListTest(&ls, 2 * ls.length);
    ListTest_Reverse(&ls, 2 * ls.length);


    int tmp;

    ListDelete(&ls, 0, &tmp);
    ListTest(&ls, 2 * ls.length);
    ListDelete(&ls, 1, &tmp);
    ListTest(&ls, 2 * ls.length);
    ListDelete(&ls, ls.length-1, &tmp);
    ListTest(&ls, 2 * ls.length);

    ListInsert(&ls, ls.length, 5);
    ListTest(&ls, 2 * ls.length);

    ListInsert(&ls, 1, 3);
    ListTest(&ls, 2 * ls.length);

    ListInsert(&ls, 0, 1);
    ListTest(&ls, 2 * ls.length);

    GetElem(&ls, 0, &tmp);
    printf("tmp = %d\n", tmp);
    GetElem(&ls, ls.length-1, &tmp);
    printf("tmp = %d\n", tmp);

    ClearList(&ls);
    printf("当前链表长度为：%d\n", ls.length);

    DestroyList(&ls);

    return 0;
}
