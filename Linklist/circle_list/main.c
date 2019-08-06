#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

int main()
{
    printf("请输入总人数：\n");
    int len;
    scanf("%d", &len);

    CircleList ls;
    InitList(&ls);
    CreateList(&ls, len);

//  循环链表测试

    ListTest(&ls);
    printf("\n");


    int tmp;

    ListDelete(&ls, 0, &tmp);
    ListTest(&ls);
    printf("\n");

    ListDelete(&ls, ls.length-1, &tmp);
    ListTest(&ls);
    printf("\n");

    ListInsert(&ls, 0, 1);
    ListTest(&ls);
    printf("\n");

    ListInsert(&ls, ls.length, 5);
    ListTest(&ls);
    printf("\n");


//  约瑟夫环实现
    Josephus(&ls);

//  清空链表
    ClearList(&ls);
    printf("链表长度为：%d\n", ls.length);

    return 0;
}
