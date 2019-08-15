#include "bintree.h"

int Depth(bnode *p, char x)
{
	int len;
	if (!p)
	{
		return -1;
	}

	if (p->data == x)
	{
		return 1;
	}

	len = Depth(p->lch, x);
	if (len != -1)
	{
		return len + 1;
	}

	len = Depth(p->rch, x);
	if (len != -1)
	{
		return len + 1;
	}

	else
	{
		return -1;
	}
}

main()
{
	bnode *p;
	printf("输入二叉树序列:");
	p = creat();
	datatype c;
	getchar();
	printf("输入要查找的结点值:");
	scanf("%c", &c);
	int len = Depth(p, c);
	if (len > 0)
	{
		printf("该结点在%d层\n", len);
	}
	else
	{
		printf("不存在该结点!");
	}
}
