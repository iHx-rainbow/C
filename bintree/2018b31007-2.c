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
	printf("�������������:");
	p = creat();
	datatype c;
	getchar();
	printf("����Ҫ���ҵĽ��ֵ:");
	scanf("%c", &c);
	int len = Depth(p, c);
	if (len > 0)
	{
		printf("�ý����%d��\n", len);
	}
	else
	{
		printf("�����ڸý��!");
	}
}
