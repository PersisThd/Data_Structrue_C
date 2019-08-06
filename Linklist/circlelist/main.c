#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

int main()
{
    printf("输入圆桌上的总人数: \n");
    int len;
    scanf("%d", &len);

    CircleList ls;
    InitList(&ls);
    CreateList(&ls, len);
    //Node* tail = (Node*)malloc(sizeof(Node));
    printf("请输入最开始报数的人编号（从0到%d）：", len-1);
    int pos, num;
    scanf("%d", &pos);
    printf("请输入一个数字，数到该数字时的人出列：");
    scanf("%d", &num);

    Node* p = &ls.header;
    while(p->data != pos)
    {
        p = p->next;
    }

    Node* pB = (Node*)malloc(sizeof(Node));
    while(p->next != p)
    {

        int i = 0;
        for(i = 0; i < num - 1; i++)
        {
            pB = p;
            p = p->next;
        }
        pB->next = p->next;
        free(p);
        ls.length--;

    }
    //printf("The length is: %d\n", ls.length);
    /*int key;
    printf("please input the search position(start from 0): ");

    scanf("%d", &key);
    int tmp;
    GetElem(&ls, key, &tmp);
    printf("The value of the position_%d is: %d", key, tmp);*/

    //²åÈë²Ù×÷
    //int i = 0;
   // ListInsert(&ls, 3, 8);
    //printf("The length is: %d\n", ls.length);

    /*for(i = 0; i <= len; i++)
    {
        ListInsert(&ls, i, i + 10);
    }
    printf("The length is: %d\n", ls.length);*/
    /*int tmp1;

    ListDelete(&ls, 0, &tmp1);
    printf("The length is: %d\n", ls.length);
    ListDelete(&ls, 1, &tmp1);
    printf("The length is: %d\n", ls.length);
    ListDelete(&ls, ls.length-1, &tmp1);
    printf("The length is: %d\n", ls.length);*/


    return 0;
}


