#include "seqlist.h"
#include <stdio.h>

//Ë³Ðò±íµÄµ¹ÖÃ
void reverse(Seqlist *L)
{
    int temp;
    int j = L->last - 1;
    for (int i = 0; i < j; i++, j--)
    {
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}

void main()
{
    Seqlist q;
    initseqlist(&q);
    input(&q);
    print(&q);
    reverse(&q);
    print(&q);
}