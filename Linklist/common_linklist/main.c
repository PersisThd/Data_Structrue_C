#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_linklist.h"

int main()
{
    LINKLIST ls;
    InitList(&ls);

    typedef struct student
    {
        char id[20];
        int age;
        char name[50];
    }student;

    student s[2];

    strcpy(s[0].id, "2019888888");
    s[0].age = 20;
    strcpy(s[0].name, "Mike");

    strcpy(s[1].id, "2019999999");
    s[1].age = 22;
    strcpy(s[1].name, "John");

    int i = 0;
    for(i = 0; i < 2; i++)
    {
        ListInsert(&ls, i, (void*)&s[i]);
    }

    for(i = 0; i < 2; i++)
    {
        student* tmp = (student*)malloc(sizeof(student));
        GetElem(&ls, i, (void**)&tmp);

        printf("the num_%d id is %s\n", i, tmp->id);
        printf("the num_%d age is %d\n", i, tmp->age);
        printf("the num_%d id is %s\n", i, tmp->name);
    }

    system("Pause");

    return 0;
}
