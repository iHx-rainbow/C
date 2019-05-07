#include "bintree.h"

void fstorder1(bnode *p)
{
	sqstack s;
	bnode *t;
	init(&s);
	push(&s, p);
	while (!empty(&s))
	{
		t = pop(&s);
		printf("%c", t->data);
		if (t->rch != NULL)
		{
			push(&s, t->rch);
		}
		if (t->lch != NULL)
		{
			push(&s, t->lch);
		}
	}
}
main()
{
	bnode *p;
	printf("�������������:");
	p = creat();
	printf("�������:");
	fstorder1(p);
}