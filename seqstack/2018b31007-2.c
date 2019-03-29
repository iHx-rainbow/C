#include <stdio.h>
#include "seqsq.h"

void fenli(seqstack *s, sequeue *q)
{
    int b = MAXSIZE;
    while (!empty(s))
    {
        if (s->elem[s->top] % 2 == 0)
        {
            q->rear++;
            q->elem[q->rear] = s->elem[s->top];
        }
        else
        {
            b--;
            q->elem[b] = s->elem[s->top];
        }
        s->top--;
    }
    while (b < MAXSIZE)
    {
        s->top++;
        s->elem[s->top] = q->elem[b];
        b++;
    }
}

main()
{
    seqstack s;
    inits(&s);
    sequeue q;
    initq(&q);
    input(&s);
    printf("∂—’ªS£∫");
    prints(&s);
    fenli(&s, &q);
    printf("========================================\n");
    printf("∂—’ªS£∫");
    prints(&s);
    printf("∂”¡–Q£∫");
    printq(&q);
}