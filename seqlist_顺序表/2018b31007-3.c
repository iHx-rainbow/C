#include "seqlist.h"
#include <stdio.h>

//˳�������--����
void sort(Seqlist *L)
{
    int i, j;
    for (i = 0; i < L->last - 1; i++)
        for (j = i + 1; j < L->last; j++)
        {
            int temp;
            if (L->data[i] > L->data[j])
            {
                temp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = temp;
            }
        }
}

//����˳���ϲ�
void add(Seqlist *L1, Seqlist *L2, Seqlist *L3)
{
    for (int i = 0; i < L1->last; i++)
    {
        L3->data[L3->last++] = L1->data[i];
    }
    for (int j = 0; j < L2->last; j++)
    {
        L3->data[L3->last++] = L2->data[j];
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
    printf("������ڶ������ݣ�");
    input(&q2);
    print(&q2);
    printf("--------------------------\n");
    add(&q, &q2, &q3);
    printf("��һ�������\n");
    sort(&q);
    print(&q);
    printf("�ڶ��������\n");
    sort(&q2);
    print(&q2);
    printf("--------------------------\n�ϲ������Ϊ��\n");
    sort(&q3);
    print(&q3);
}