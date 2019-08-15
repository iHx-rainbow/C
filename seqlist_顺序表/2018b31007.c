#include "seqlist.h"
#include <stdio.h>

//˳���Ĳ���
int Insert_Seqlist(Seqlist *L, int i, DataType x)
{
    int j;
    i--;
    if (L->last == MAXSIZE)
    {
        printf("\n Error??\n");
        return (-1);
    }
    if (i < 0 || i > L->last + 1)
    {
        printf("\n Error??\n");
        return (-1);
    }
    else
    {
        for (j = L->last - 1; j >= i; j--)
        {
            L->data[j + 1] = L->data[j];
        }
        L->data[i] = x;
        L->last++;
        return (1);
    }
}

//˳���ĵ���
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

//˳���ķ���
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
    printf("�����밴1�������밴2����ż�������밴3��˳���ϲ��밴4��\n");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        int i, n;
        printf("����λ��\n");
        scanf("%d", &i);
        printf("����ֵ\n");
        scanf("%d", &n);
        Insert_Seqlist(&q, i, n);
        print(&q);
    }
    else if (x == 2)
    {
        reverse(&q);
        print(&q);
    }
    else if (x == 3)
    {
        Seqlist q2, q3;
        initseqlist(&q2);
        initseqlist(&q3);
        sprit(&q, &q2, &q3);
        printf("������\n");
        print(&q2);
        printf("ż����\n");
        print(&q3);
    }
    else if (x == 4)
    {
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
    else
    {
        printf("��������\n");
    }
}