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
        printf("%c�Ķ�Ϊ:%d \n", G.Vertex[i].data, count);
        printf("\n");
    }
}

main()
{
    AdjList G;
    printf("�����붥����: ");
    int a;
    scanf("%d", &a);
    printf("������ߵĸ���: ");
    int b;
    scanf(" %d", &b);
    getchar();
    creat(&G, a, b);
    print(G);
    degree(G);
}