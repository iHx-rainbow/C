#include <stdio.h>
#include "slnklist.h"

linklist interSection(linklist L1, linklist L2)
{
	linklist head, p1, p2, m, n;
	head = m = (linklist)malloc(sizeof(Lnode));
	p1 = L1;
	p2 = L2;
	while (p1->next != NULL)
	{
		while ((p2->next != NULL) && (p1->next->data != p2->next->data))
		{
			p2 = p2->next;
		}
		if (p2->next == NULL)
		{
			p2 = L2;
		}
		else
		{
			n = (linklist)malloc(sizeof(Lnode));
			m->next = n;
			n->data = p2->next->data;
			m = n;
			p2 = L2;
		}
		p1 = p1->next;
	}
	m->next = NULL;

	//print(head);

	linklist p, q;
	p = head->next;						 //����data�ĵط���ʼ
	while (p != NULL && p->next != NULL) //��������ڵ���ͬ��ʱ��ɾ�������һ��������p����p��ΪNULL���������ж�p�Ƿ�Ϊ�գ�p->next�����Ѳ�����
	{
		q = p;
		while (q->next != NULL)
		{
			if (p->data == q->next->data)
			{
				q->next = q->next->next;
			}
			else
			{
				q = q->next;
			}
		}
		p = p->next;
	}

	/*
	linklist p = head;
	while (p != NULL)
	{
		linklist q = head;
		while (q->next != p && q->next != NULL)
		{
			if (q->next->data == p->data)
			{
				q->next = q->next->next;
			}
			else
			{
				q = q->next;
			}
		}
		p = p->next;
	}
	*/

	return head;
}

main()
{
	linklist L1 = creatbyqueue();
	print(L1);
	linklist L2 = creatbyqueue();
	print(L2);
	linklist head = interSection(L1, L2);
	printf("����������Ľ�����:");
	print(head);
}