#include  <stdio.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct{
   	DataType data[MAXSIZE];
   	int last;
}Seqlist;

/**********************************/
/*�������ƣ�initseqlist()         */
/*�������ܣ���ʼ��˳���          */
/**********************************/
void initseqlist(Seqlist *L)
{	L->last=0;
}

/**********************************/
/*�������ƣ�input()               */
/*�������ܣ�����˳���            */
/**********************************/
void input(Seqlist *L)
{  	DataType x;
   	initseqlist(L);
   	printf("������һ�����ݣ���0��Ϊ��������\n");
   	scanf("%d",&x);
   	while (x)
   	{	L->data[L->last++]=x;
    	scanf("%d",&x);
    }
}

/**********************************/
/*�������ƣ�inputfromfile()       */
/*�������ܣ����ļ�����˳���      */
/**********************************/
void inputfromfile(Seqlist *L,char *f)
{	initseqlist(L);
   	FILE *fp=fopen(f,"r");
   	if(fp)
   	{   while(!feof(fp))
		{
            fscanf(fp,"%d",&L->data[L->last++]);
        }
        fclose(fp);
  	}
}

/**********************************/
/*�������ƣ�print()               */
/*�������ܣ����˳���            */
/**********************************/
void print(Seqlist *L)
{   int i;
	if(L->last==0)
		printf("˳���Ϊ��\n");
    else
		for(i=0;i<L->last;i++)
   	 	{  	printf("%5d",L->data[i]);
    		if((i+1)%10==0) printf("\n");
    	}
    printf("\n");
}
