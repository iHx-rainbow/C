#include "ljb.h"

void degree(AdjList G)
{
    ArcNode *p;
    int i;
    for (i = 0; i < G.numV; i++)
    {
        int count = 0;
        p = G.Vertex[i].firstarc;
        while (p)
        {
            count++;
            p = p->nextarc;
        }
        printf("%c的度为:%d \n", G.Vertex[i].data, count);
        printf("\n");
    }
}

main()
{
    AdjList G;
    printf("请输入顶点数: ");
    int a;
    scanf("%d", &a);
    printf("请输入边的个数: ");
    int b;
    scanf(" %d", &b);
    getchar();
    creat(&G, a, b);
    print(G);
    degree(G);
}