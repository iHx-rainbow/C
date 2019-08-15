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
	printf("输入二叉树序列:");
	p = creat();
	printf("交换前先序遍历:");
	fstorder(p);
	change(p);
	printf("\n交换后先序遍历:");
	fstorder(p);
}