#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef char datatype;
typedef struct node /*¶þ²æÊ÷½á¹¹¶¨Òå*/
{
    datatype data;
    struct node *lch, *rch;
} bnode;

void fstorder(bnode *p) /*ÏÈÐòµÝ¹é±éÀú¶þ²æÊ÷*/
{
    if (p)
    {
        printf("%c", p->data);
        fstorder(p->lch);
        fstorder(p->rch);
    }
}
void lastorder(bnode *p) /*ºóÐòµÝ¹é±éÀú¶þ²æÊ÷*/
{
    if (p)
    {
        lastorder(p->lch);
        lastorder(p->rch);
        printf("%c", p->data);
    }
}

/*Ë³ÐòÕ»¶¨Òå*/
typedef struct
{
    bnode *data[N];
    int top;
} sqstack;

void init(sqstack *s) /*³õÊ¼»¯¿ÕÕ»*/
{
    s->top = -1;
}
int empty(sqstack *s) /*ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ*/
{
    if (s->top > -1)
        return 0;
    else
        return 1;
}
int full(sqstack *s) /*ÅÐ¶ÏÕ»ÊÇ·ñÎªÂú*/
{
    if (s->top == N - 1)
        return 1;
    else
        return 0;
}
void push(sqstack *s, bnode *x) /*½øÕ»*/
{
    if (!full(s))
        s->data[++s->top] = x;
}
bnode *pop(sqstack *s) /*³öÕ»*/
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
