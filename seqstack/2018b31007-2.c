#include <stdio.h>
#include "seqsq.h"

void fenli(seqstack *s, sequeue *q)
{
    q->front = MAXSIZE;
    while (!empty(s))
    {
        if (s->elem[s->top] % 2 == 0)
        {
            q->rear++;
            q->elem[q->rear] = s->elem[s->top];
        }
        else    //����ĩβ�������
        {
            q->front--;
            q->elem[q->front] = s->elem[s->top];
        }
        s->top--;
    }
    while (q->front < MAXSIZE)
    {
        s->top++;
        s->elem[s->top] = q->elem[q->front];
        q->front++;
    }
    q->front=-1;
}

main()
{
    seqstack s;
    inits(&s);
    sequeue q;
    initq(&q);
    input(&s);
    printf("��ջS��");
    prints(&s);
    fenli(&s, &q);
    printf("========================================\n");
    printf("��ջS��");
    prints(&s);
    printf("����Q��");
    printq(&q);
}