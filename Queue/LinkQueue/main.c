#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

typedef struct stu
{
    Node p;
    int id;
    int age;
}student;

int main()
{
    LinkQueue lq;
    InitQueue(&lq);
    student s[10];
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
        EnQueue(&lq, &s[i].p);
    }

    printf("当前队列长度为：%d\n", QueueLength(&lq));

    while(!QueueEmpty(&lq))
    {
        Node* tmp;
        GetFront(&lq, (Node**)&tmp);
        student* tmp1 = (student*)tmp;
        printf("当前队头元素值为：id = %d, age = %d\n", tmp1->id, tmp1->age);
        DeQueue(&lq, (Node**)&tmp);
        tmp1 = (student*)tmp;
        printf("当前出队元素值为：id = %d, age = %d\n", tmp1->id, tmp1->age);
        printf("\n");

    }
    return 0;
}
