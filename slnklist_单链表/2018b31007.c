#include <stdio.h>
#include "slnklist.h"

//删除升序单链表中值大于x小于等于y的所有结点
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
    printf("请输入x：");
    scanf("%d", &x);
    printf("请输入y：");
    scanf("%d", &y);
    del(L1, x, y);
    print(L1);
}
