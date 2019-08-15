#include "seqlist.h"
#include <stdio.h>

//顺序表的分类
void sprit(Seqlist *L1, Seqlist *L2, Seqlist *L3)
{
    int i;
    int m = 0, n = 0;
    for (i = 0; i < L1->last; i++)
    {
        if (L1->data[i] % 2 == 1)
        {
            L2->data[m] = L1->data[i];
            m++;
        }
        else if (L1->data[i] % 2 == 0)
        {
            L3->data[n] = L1->data[i];
            n++;
        }
        L2->last = m;
        L3->last = n;
    }
}

void main()
{
    Seqlist q;
    initseqlist(&q);
    input(&q);
    print(&q);
    Seqlist q2, q3;
    initseqlist(&q2);
    initseqlist(&q3);
    sprit(&q, &q2, &q3);
    printf("奇数表\n");
    print(&q2);
    printf("偶数表\n");
    print(&q3);
}