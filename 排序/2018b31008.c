#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const MAXSIZE = 2000;
typedef int ElemType;
typedef struct
{
	ElemType key;
} node;
clock_t start, stop;
int a[4];
int b[4];
double c[4];
//直接插入排序
void stinsort(node r[MAXSIZE], int n)
{

	start = clock();
	a[0] = 0;
	b[0] = 0;
	c[0] = 0;
	int i, j;
	for (i = 2; i < n; i++)
	{
		r[0] = r[i];
		j = i - 1;
		a[0]++;
		while (r[j].key > r[0].key)
		{
			r[j + 1] = r[j];
			j--;
			b[0]++;
		}
		r[j + 1] = r[0];
	}
	stop = clock();
	c[0] = (double)(stop - start) / CLOCKS_PER_SEC;
}
//折半插入排序

void binasort(node r[MAXSIZE], int n)
{
	start = clock();
	a[1] = 0;
	b[1] = 0;
	c[1] = 0;
	int i, j, l, h, mid;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		l = 1;
		h = i - 1;
		while (l <= h)
		{
			mid = (l + h) / 2;
			a[1]++;
			if (r[0].key < r[mid].key)
			{
				h = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		for (j = i - 1; j >= l; j--)
		{
			r[j + 1] = r[j];
			b[1]++;
		}
		r[l] = r[0];
	}
	stop = clock();
	c[1] = (double)(stop - start) / CLOCKS_PER_SEC;
}
//冒泡排序
void bubblesort(node r[MAXSIZE], int n)
{
	start = clock();
	a[2] = 0;
	b[2] = 0;
	c[2] = 0;
	int i = 1;
	int j, tag;
	node x;
	do
	{
		tag = 0;
		for (j = n; j > i; j--)
		{
			a[2]++;
			if (r[j].key < r[j - 1].key)
			{
				x = r[j];
				r[j] = r[j - 1];
				r[j - 1] = x;
				tag = 1;
				b[2]++;
			}
		}
		i++;
	} while (tag == 1 && i <= n);
	stop = clock();
	c[2] = (double)(stop - start) / CLOCKS_PER_SEC;
}
//简单选择排序
void sisort(node r[MAXSIZE], int n)
{
	start = clock();
	a[3] = 0;
	b[3] = 0;
	c[3] = 0;
	int i, z, j;
	node x;
	for (i = 1; i < n; i++)
	{
		z = i;
		for (j = i + 1; j <= n; j++)
		{
			a[3]++;
			if (r[j].key < r[z].key)
			{
				z = j;
			}
		}
		if (z != i)
		{
			x = r[i];
			r[i] = r[z];
			r[z] = x;
			b[3]++;
		}
	}
	stop = clock();
	c[3] = (double)(stop - start) / CLOCKS_PER_SEC;
}

main()
{
	int n, k, t;
	printf("请输入个数n:");
	scanf("%d", &n);
	node r1[n];
	printf("N个从小到大的有序整数:\n");
	for (k = 0; k < 4; k++)
	{
		for (t = 1; t <= n; t++)
		{
			r1[t].key = t;
		}
		if (k == 0)
		{
			stinsort(&r1, n + 1);
			printf("直接插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 1)
		{
			binasort(&r1, n + 1);
			printf("折半插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 2)
		{
			bubblesort(&r1, n);
			printf("冒泡排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 3)
		{
			sisort(&r1, n);
			printf("简单选择排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
	}
	printf("N个从大到小的有序整数:\n");
	for (k = 0; k < 4; k++)
	{
		for (t = 1; t <= n; t++)
		{
			r1[t].key = n - t + 1;
		}
		if (k == 0)
		{
			stinsort(&r1, n + 1);
			printf("直接插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 1)
		{
			binasort(&r1, n + 1);
			printf("折半插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 2)
		{
			bubblesort(&r1, n);
			printf("冒泡排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 3)
		{
			sisort(&r1, n);
			printf("简单选择排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
	}
	printf("N个随机产生的无序数:\n");
	srand(time(0));
	for (k = 0; k < 4; k++)
	{
		for (t = 1; t <= n; t++)
		{
			r1[t].key = rand() % n + 1;
		}
		if (k == 0)
		{
			stinsort(&r1, n + 1);
			printf("直接插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 1)
		{
			binasort(&r1, n + 1);
			printf("折半插入排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 2)
		{
			bubblesort(&r1, n);
			printf("冒泡排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
		else if (k == 3)
		{
			sisort(&r1, n);
			printf("简单选择排序比较次数为%d次，移动次数为%d次，运行耗时为%f秒\n", a[k], b[k], c[k]);
		}
	}
}
