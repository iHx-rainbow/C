#include "seqlist.h"
#include <stdio.h>

//顺序表的插入
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

//顺序表的倒置
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

//顺序表排序--升序
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

//两个顺序表合并
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
    printf("插入请按1，倒序请按2，奇偶数分类请按3，顺序表合并请按4。\n");
    int x;
    scanf("%d", &x);
    if (x == 1)
    {
        int i, n;
        printf("插入位置\n");
        scanf("%d", &i);
        printf("插入值\n");
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
        printf("奇数表\n");
        print(&q2);
        printf("偶数表\n");
        print(&q3);
    }
    else if (x == 4)
    {
        Seqlist q2, q3;
        initseqlist(&q2);
        initseqlist(&q3);
        printf("请输入第二组数据：");
        input(&q2);
        print(&q2);
        printf("--------------------------\n");
        add(&q, &q2, &q3);
        printf("第一组排序后：\n");
        sort(&q);
        print(&q);
        printf("第二组排序后：\n");
        sort(&q2);
        print(&q2);
        printf("--------------------------\n合并排序后为：\n");
        sort(&q3);
        print(&q3);
    }
    else
    {
        printf("输入有误！\n");
    }
}