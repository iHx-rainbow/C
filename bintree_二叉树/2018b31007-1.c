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
	printf("输入二叉树序列:");
	p = creat();
	printf("先序遍历:");
	fstorder1(p);
}