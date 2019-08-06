#include <stdio.h>
#include <stdlib.h>
#include "linkstack2.h"

typedef struct stu
{
    int id;
    int age;
}student;

int main()
{
    LinkStack st;
    InitStack(&st);

    /*student s[10];
    int i = 0;
    for(i = 0; i < sizeof(s) / sizeof(student); i++)
    {
        s[i].id = i;
        s[i].age = i + 20;
        PushStack(&st, &s[i]);
    }

    printf("当前栈的大小为：%d\n", st.length);

    for(i = 0; i < 5; i++)
    {
        student* tmp;
        GetTop(&st, (void**)&tmp);
        printf("当前栈顶元素的值为：id = %d, age = %d\n", tmp->id, tmp->age);
        PopStack(&st, (void**)&tmp);
        printf("当前出栈元素的值为：id = %d, age = %d\n", tmp->id, tmp->age);
        printf("\n");
    }

    printf("当前栈的大小为：%d\n", st.length);

    ClearStack(&st);
    printf("当前栈的大小为：%d\n", st.length);*/

    /*char str[] = "#include <stdio.h>, int main()return 0}void test()";

    char* p = str;
    //printf("%s\n", p);

    NearMatch(&st, p);

    char str1[] = "9+(3-1)*3+10/2";
    ConvertExpression(&st, str1);
    printf("\n");
    char str2[] = "8+(3-2)*5-1";
    ConvertExpression(&st, str2);*/
    char str3[] = "831-5*+";
    counter(&st, str3);

    return 0;
}
