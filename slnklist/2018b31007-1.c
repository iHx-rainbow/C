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
		printf("\n x ������ ��");
	}
	else
	{
		q->next = p->next;
		printf("\n ��ɾ��x���");
		free(p);
	}
}

main()
{
	linklist head = creatbyqueue();
	print(head);
	printf("������Ҫɾ����xֵ:");
	datatype x;
	scanf("%d", &x);
	delx(head, x);
	print(head);
	delList(head);
}
