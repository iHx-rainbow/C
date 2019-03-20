#include <stdio.h>

void main()
{
    int a[10], b[10];
    int x, y;
    int cishu=0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d%d", &x, &y);
        if (x == 0 && y == 0)
        {
            break;
        }
        else
        {
            if (x > 0 && x < 10000 && y > 10 && y < 100)
            {
                a[i] = x;
                b[i] = y;
                cishu++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < cishu; i++)
    {
        int m = a[i];
        int n = b[i];
        for (int j = 0; j < 100; j++)
        {
            int temp = m * 100 + j;
            if (temp % n == 0)
            {
                if (j < 10)
                {
                    printf("0%d ", j);
                }
                else if (j + n < 100)
                {
                    printf("%d ", j);
                }
                else
                {
                    printf("%d", j);
                }
            }
        }
        printf("\n");
    }
}