#include "ljjz.h"

main()
{
	AdjMatrix G;
	printf("�����붥������: ");
	int a;
	scanf("%d", &a);
	printf("���������: ");
	int b;
	scanf("%d", &b);
	getchar();
	creat(&G, a, b);
	print(G);
}