#include <stdio.h>
#include "slnklist.h"

void delx(linklist head, datatype x)
{
	linklist p, q;
	p = head;
	while ((p != NULL) && (p->data != x))
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		printf("值为x的节点不存在!\n");
	}
	else
	{
		q->next = p->next;
		printf("删除成功！\n");
		free(p);
	}
}

main()
{
	linklist head = creatbyqueue();
	print(head);
	printf("请输入要删除的x值:");
	datatype x;
	scanf("%d", &x);
	delx(head, x);
	print(head);
	delList(head);
}
