#include "bintree.h"
void change(bnode *p)
{
	bnode *q;
	if (p)
	{
		q = p->lch;
		p->lch = p->rch;
		p->rch = q;
		change(p->lch);
		change(p->rch);
	}
}
main()
{
	bnode *p;
	printf("�������������:");
	p = creat();
	printf("����ǰ�������:");
	fstorder(p);
	change(p);
	printf("\n�������������:");
	fstorder(p);
}