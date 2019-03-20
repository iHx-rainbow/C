#include  <stdio.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct{
   	DataType data[MAXSIZE];
   	int last;
}Seqlist;

/**********************************/
/*函数名称：initseqlist()         */
/*函数功能：初始化顺序表          */
/**********************************/
void initseqlist(Seqlist *L)
{	L->last=0;
}

/**********************************/
/*函数名称：input()               */
/*函数功能：输入顺序表            */
/**********************************/
void input(Seqlist *L)
{  	DataType x;
   	initseqlist(L);
   	printf("请输入一组数据，以0做为结束符：\n");
   	scanf("%d",&x);
   	while (x)
   	{	L->data[L->last++]=x;
    	scanf("%d",&x);
    }
}

/**********************************/
/*函数名称：inputfromfile()       */
/*函数功能：从文件输入顺序表      */
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
/*函数名称：print()               */
/*函数功能：输出顺序表            */
/**********************************/
void print(Seqlist *L)
{   int i;
	if(L->last==0)
		printf("顺序表为空\n");
    else
		for(i=0;i<L->last;i++)
   	 	{  	printf("%5d",L->data[i]);
    		if((i+1)%10==0) printf("\n");
    	}
    printf("\n");
}
