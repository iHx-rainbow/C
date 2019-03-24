#include <stdio.h>
#include "slnklist.h"

//??????????????x?????=y?????§ß??
void del(linklist head, datatype x, datatype y)
{
    linklist p = head;
    while (p->next != NULL)
    {
        if (p->next->data > x && p->next->data <= y)
        {
            linklist q = p->next;
            p->next = p->next->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}
main()
{
    linklist L1;
    L1 = creatbyqueue();
    print(L1);
    int x;
    int y;
    printf("??????x??");
    scanf("%d", &x);
    printf("??????y??");
    scanf("%d", &y);
    del(L1, x, y);
    print(L1);
}
