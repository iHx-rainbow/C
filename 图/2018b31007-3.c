#include "ljjz.h"

float dist[Max];
int path[Max];
int S[Max];
void dijkstra(AdjMatrix G, int v)
{
	for (int i = 0; i < G.numV; i++)
	{
		dist[i] = G.Edge[v][i];
		S[i] = 0;
		if (i != v && dist[i] < Max)
			path[i] = v;
		else
			path[i] = -1;
	}
	S[v] = 1;
	dist[v] = 0;
	for (int i = 0; i < G.numV; i++)
	{
		float min = Max;
		int u = v;
		for (int j = 0; j < G.numV; j++)
			if (!S[j] && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = 1;
		for (int w = 0; w < G.numV; w++)
		{
			if (!S[w] && G.Edge[u][w] < Max && dist[u] + G.Edge[u][w] < dist[w])
			{
				dist[w] = dist[u] + G.Edge[u][w];
				path[w] = u;
			}
		}
	}
	for (int i = 0; i < G.numV; i++)
	{
		printf("到%d的路径为:%f\n", i + 1, dist[i]);
	}
}

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
	printf("请输入顶点v的信息: ");
	int v;
	scanf(" %d", &v);
	dijkstra(G, v);
}
