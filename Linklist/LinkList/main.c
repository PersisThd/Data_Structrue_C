#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{

    LINKLIST ls;

    //¡¥±Ì≥ı ºªØ
    InitList(&ls);

    int i = 0;
    for(i=0;i<10;i++)
    {
        ListInsert(&ls, i, i+3);
    }

    for(i=0;i<10;i++)
    {
        int tmp = 0;
        GetElem(&ls, i, &tmp);
        printf("The num_%d element is: %d\n", i, tmp);
    }

    while(ListEmpty(&ls) != 1)
    {
        int tmp;
        ListDel(&ls, 0, &tmp);
        printf("The delete element is: %d\n", tmp);
    }

    DestroyList(&ls);
    system("Pause");
    return 0;
}
