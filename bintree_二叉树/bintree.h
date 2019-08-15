#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef char datatype;
typedef struct node /*�������ṹ����*/
{
    datatype data;
    struct node *lch, *rch;
} bnode;

void fstorder(bnode *p) /*����ݹ����������*/
{
    if (p)
    {
        printf("%c", p->data);
        fstorder(p->lch);
        fstorder(p->rch);
    }
}
void lastorder(bnode *p) /*����ݹ����������*/
{
    if (p)
    {
        lastorder(p->lch);
        lastorder(p->rch);
        printf("%c", p->data);
    }
}

/*˳��ջ����*/
typedef struct
{
    bnode *data[N];
    int top;
} sqstack;

void init(sqstack *s) /*��ʼ����ջ*/
{
    s->top = -1;
}
int empty(sqstack *s) /*�ж�ջ�Ƿ�Ϊ��*/
{
    if (s->top > -1)
        return 0;
    else
        return 1;
}
int full(sqstack *s) /*�ж�ջ�Ƿ�Ϊ��*/
{
    if (s->top == N - 1)
        return 1;
    else
        return 0;
}
void push(sqstack *s, bnode *x) /*��ջ*/
{
    if (!full(s))
        s->data[++s->top] = x;
}
bnode *pop(sqstack *s) /*��ջ*/
{
    if (!empty(s))
        return s->data[s->top--];
}
bnode *creat()
{
    bnode *p;
    char ch;
    scanf("%c", &ch);

    if (ch == '#')
    {
        p = NULL;
    }
    else
    {
        p = (bnode *)malloc(sizeof(bnode));
        p->data = ch;
        p->lch = creat();
        p->rch = creat();
    }
    return p;
}
