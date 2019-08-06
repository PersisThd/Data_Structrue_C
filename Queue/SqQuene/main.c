#include <stdio.h>
#include <stdlib.h>
#include "SqQuene.h"

typedef struct stu
{
    int id;
    int age;
}Student;

int main()
{
    SqQuene sq;
    InitQuene(&sq);

    Student s[10];
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
    }

    for(i = 0; i < 10; i++)
    {
        EnQuene(&sq, &s[i]);
    }

    printf("The size of Quene: %d\n", QueneLength(&sq));

    while(!QueneEmpty(&sq))
    {
        Student* tmp;
        GetFront(&sq, (void**)&tmp);
        printf("��ǰ��ͷԪ��ֵΪ��%d, %d\n", tmp->id, tmp->age);
        //printf("��ǰ��ͷ��Ԫ��ֵΪ��id = %d, age = %d\n", tmp->id, tmp->age);

        DeQuene(&sq, (void**)&tmp);
        printf("��ǰ���ӵ�Ԫ��ֵΪ��id = %d, age = %d\n", tmp->id, tmp->age);
        printf("\n");
    }

    EnQuene(&sq, &s[0]);

    ClearQuene(&sq);
    printf("The size of Quene: %d\n", QueneLength(&sq));

    return 0;
}
