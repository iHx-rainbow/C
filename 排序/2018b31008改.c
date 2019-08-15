#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAXSIZE = 99999;
typedef int ElemType;
typedef struct
{
	ElemType key;
} node;

int compare_times[4];
int move_times[4];
double runtime[4];

//ֱ�Ӳ�������
void stinsort(node r[MAXSIZE], int n)
{
	clock_t start, stop;
	start = clock();
	compare_times[0] = 0;
	move_times[0] = 0;
	runtime[0] = 0;
	int i, j;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		j = i - 1;
		compare_times[0]++;
		while (r[j].key > r[0].key)
		{
			r[j + 1] = r[j];
			j--;
			move_times[0]++;
		}
		r[j + 1] = r[0];
	}
	stop = clock();
	//��ʾ���
	/*
	for (int i = 1; i <= n; i++)
	{
		printf("%d,", r[i].key);
	}
	*/
	runtime[0] = (double)(stop - start) / CLOCKS_PER_SEC;
}

//�۰��������
void binasort(node r[MAXSIZE], int n)
{
	clock_t start, stop;
	start = clock();
	compare_times[1] = 0;
	move_times[1] = 0;
	runtime[1] = 0;
	int i, j, l, h, mid;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		l = 1;
		h = i - 1;
		while (l <= h)
		{
			mid = (l + h) / 2;
			compare_times[1]++;
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
			move_times[1]++;
		}
		r[l] = r[0];
	}
	stop = clock();
	//��ʾ���
	/*
	for (int i = 1; i <= n; i++)
	{
		printf("%d,", r[i].key);
	}
	*/
	runtime[1] = (double)(stop - start) / CLOCKS_PER_SEC;
}

//ð������
void bubblesort(node r[MAXSIZE], int n)
{
	clock_t start, stop;
	start = clock();
	compare_times[2] = 0;
	move_times[2] = 0;
	runtime[2] = 0;
	int i = 1;
	int j, tag;
	node x;
	do
	{
		tag = 0;
		for (j = n; j > i; j--)
		{
			compare_times[2]++;
			if (r[j].key < r[j - 1].key)
			{
				x = r[j];
				r[j] = r[j - 1];
				r[j - 1] = x;
				tag = 1;
				move_times[2]++;
			}
		}
		i++;
	} while (tag == 1 && i <= n);
	stop = clock();
	//��ʾ���
	/*
	for (int i = 1; i <= n; i++)
	{
		printf("%d,", r[i].key);
	}
	*/
	runtime[2] = (double)(stop - start) / CLOCKS_PER_SEC;
}

//��ѡ������
void sisort(node r[MAXSIZE], int n)
{
	clock_t start, stop;
	start = clock();
	compare_times[3] = 0;
	move_times[3] = 0;
	runtime[3] = 0;
	int i, z, j;
	node x;
	for (i = 1; i < n; i++)
	{
		z = i;
		for (j = i + 1; j <= n; j++)
		{
			compare_times[3]++;
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
			move_times[3]++;
		}
	}
	stop = clock();
	/*
	for (int i = 1; i <= n; i++)
	{
		printf("%d,", r[i].key);
	}
	*/
	runtime[3] = (double)(stop - start) / CLOCKS_PER_SEC;
}

void createOrderList(node list[MAXSIZE], int n)
{
	for (int t = 1; t <= n; t++)
	{
		list[t].key = t;
	}
}
void createDescList(node list[MAXSIZE], int n)
{
	for (int t = 1; t <= n; t++)
	{
		list[t].key = n - t + 1;
	}
}
void createRandList(node list[MAXSIZE], int n)
{
	for (int t = 1; t <= n; t++)
	{
		list[t].key = rand();
	}
}

void main()
{
	int n;
	printf("���������N:");
	scanf("%d", &n);
	node list[n + 1];
	printf("N����С�������������:\n");
	int j = 0;
	createOrderList(list, n);
	stinsort(list, n);
	printf("ֱ�Ӳ�������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createOrderList(list, n);
	binasort(list, n);
	printf("�۰��������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createOrderList(list, n);
	bubblesort(list, n);
	printf("ð������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createOrderList(list, n);
	sisort(list, n);
	printf("��ѡ������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);

	printf("N���Ӵ�С����������:\n");
	j = 0;
	createDescList(list, n);
	stinsort(list, n);
	printf("ֱ�Ӳ�������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createDescList(list, n);
	binasort(list, n);
	printf("�۰��������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createDescList(list, n);
	bubblesort(list, n);
	printf("ð������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createDescList(list, n);
	sisort(list, n);
	printf("��ѡ������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);

	printf("N�����������������:\n");
	srand(time(NULL));
	j = 0;
	createRandList(list, n);
	stinsort(list, n);
	printf("ֱ�Ӳ�������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createRandList(list, n);
	binasort(list, n);
	printf("�۰��������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createRandList(list, n);
	bubblesort(list, n);
	printf("ð������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);
	j++;
	createRandList(list, n);
	sisort(list, n);
	printf("��ѡ������Ƚϴ���Ϊ%d�Σ��ƶ�����Ϊ%d�Σ����к�ʱΪ%f��\n", compare_times[j], move_times[j], runtime[j]);

	system("pause");
}
