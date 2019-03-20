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
		printf("\n x 不存在 ！");
	}
	else
	{
		q->next = p->next;
		printf("\n 已删除x结点");
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
