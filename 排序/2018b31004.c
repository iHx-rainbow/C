#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const MAXSIZE = 100000;
typedef int ElemType;
typedef struct
{
	ElemType key;
} node;
//输出
void output(node r[MAXSIZE], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", r[i].key);
	}
}
//直接插入排序
void stinsort(node r[MAXSIZE], int n)
{
	int i, j;
	int bijiaocishu = 0;
	int jiaohuancishu = 0;
	clock_t start, end;
	start = clock();
	for (i = 2; i < n; i++)
	{
		r[0] = r[i];
		j = i - 1;
		bijiaocishu++;
		while (r[j].key > r[0].key)
		{
			r[j + 1] = r[j];
			j--;
			jiaohuancishu++;
		}
		r[j + 1] = r[0];
	}
	end = clock();
	double yunxinshijian = (double)(end - start) / CLOCKS_PER_SEC;
	printf("直接插入排序比较次数：%d 交换次数：%d 运行时间：%f\n", bijiaocishu, jiaohuancishu, yunxinshijian);
}
//折半插入排序
void binasort(node r[MAXSIZE], int n)
{
	int i, j, l, h, mid;
	int bijiaocishu = 0;
	int jiaohuancishu = 0;
	clock_t start, end;
	start = clock();
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		l = 1;
		h = i - 1;
		while (l <= h)
		{
			mid = (l + h) / 2;
			bijiaocishu++;
			if (r[0].key < r[mid].key)
			{
				h = mid - 1;
			}
			else
				l = mid + 1;
		}
		for (j = i - 1; j >= l; j--)
		{
			r[j + 1] = r[j];
			jiaohuancishu++;
		}
		r[l] = r[0];
	}
	end = clock();
	double yunxinshijian = (double)(end - start) / CLOCKS_PER_SEC;
	printf("折半插入排序比较次数：%d 交换次数：%d 运行时间：%f\n", bijiaocishu, jiaohuancishu, yunxinshijian);
}
//希尔排序
void shellsor(node r[MAXSIZE], int n)
{
	int i, j, k;
	int bijiaocishu = 0;
	int jiaohuancishu = 0;
	clock_t start, end;
	start = clock();
	k = n / 2;
	while (k >= 1)
	{
		for (i = k + 1; i <= n; i++)
		{
			r[0] = r[i];
			j = i - k;
			bijiaocishu++;
			while ((r[j].key > r[0].key) && (j >= 0))
			{
				r[j + k] = r[j];
				j = j - k;
				jiaohuancishu++;
			}
			r[j + k] = r[0];
		}
		k = k / 2;
	}
	end = clock();
	double yunxinshijian = (double)(end - start) / CLOCKS_PER_SEC;
	printf("希尔排序比较次数：%d 交换次数：%d 运行时间：%f\n", bijiaocishu, jiaohuancishu, yunxinshijian);
}
//冒泡排序
void bubblesort(node r[MAXSIZE], int n)
{
	int i, j, tag;
	node x;
	int bijiaocishu = 0;
	int jiaohuancishu = 0;
	clock_t start, end;
	start = clock();
	i = 1;
	do
	{
		tag = 0;
		for (j = n; j > i; j--)
		{
			bijiaocishu++;
			if (r[j].key < r[j - 1].key)
			{
				x = r[j];
				r[j] = r[j - 1];
				r[j - 1] = x;
				tag = 1;
				jiaohuancishu++;
			}
		}
		i++;
	} while (tag == 1 && i <= n);
	end = clock();
	double yunxinshijian = (double)(end - start) / CLOCKS_PER_SEC;
	printf("冒泡排序比较次数：%d 交换次数：%d 运行时间：%f\n", bijiaocishu, jiaohuancishu, yunxinshijian);
}
void input1(node r[MAXSIZE], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		r[i].key = i;
	}
}
void input2(node r[MAXSIZE], int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		r[i].key = n - i + 1;
	}
}
void input3(node r[MAXSIZE], int n)
{
	int i;
	srand(time(NULL));
	for (i = 1; i <= n; i++)
	{
		r[i].key = rand();
	}
}
main()
{
	int i, n;
	printf("请输入个数N：");
	scanf("%d", &n);

	node r[n];
	printf("N个从小到大的有序整数\n");
	input1(r, n);
	stinsort(&r, n + 1);
	binasort(&r, n + 1);
	shellsor(&r, n + 1);
	bubblesort(&r, n);
	printf("N个从大到小的有序整数\n");
	input2(r, n);
	stinsort(&r, n + 1);
	input2(r, n);
	binasort(&r, n + 1);
	input2(r, n);
	shellsor(&r, n + 1);
	input2(r, n);
	bubblesort(&r, n);
	printf("N个随机产生的无序数\n");
	input3(r, n);
	stinsort(&r, n + 1);
	input3(r, n);
	binasort(&r, n + 1);
	input3(r, n);
	shellsor(&r, n + 1);
	input3(r, n);
	bubblesort(&r, n);
}