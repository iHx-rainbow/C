#include "ljjz.h"

main()
{
	AdjMatrix G;
	printf("请输入顶点总数: ");
	int a;
	scanf("%d", &a);
	printf("请输入边数: ");
	int b;
	scanf("%d", &b);
	getchar();
	creat(&G, a, b);
	print(G);
}