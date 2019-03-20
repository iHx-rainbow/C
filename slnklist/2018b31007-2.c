#include <stdio.h>
#include "slnklist.h"

void insert(linklist head, datatype x)
{
	linklist p, q, s;
	s = (linklist)malloc(sizeof(Lnode));
	s->data = x;
	s->next = NULL;
	p = head;
	q = p->next;
	while ((q != NULL) && (s->data > q->data))
	{
		p = q;
		q = q->next;
	}
	if (q == NULL)
	{
		p->next = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
}
main()
{
	linklist head = creatbyqueue();
	print(head);
	int x;
	printf("请输入要插入结点的x值:");
	scanf("%d", &x);
	insert(head, x);
	print(head);
}