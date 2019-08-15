#include  <stdio.h>
#include  <stdlib.h>
#define MAXSIZE 100
typedef int datatype;
typedef struct{
   	datatype elem[MAXSIZE];
   	int top;
}seqstack;
typedef struct{
   	datatype elem[MAXSIZE];
   	int front;
   	int rear;
}sequeue;
 
/**************************************************/
/*  函数功能：栈（顺序存储）初始化                */
/*  函数名：inits()                               */
/**************************************************/ 
void inits(seqstack *s)
{
  	s->top=-1;
}

/***************************************************/
/*  函数功能：判断栈（顺序存储）是否为空           */
/*  函数名：empty()                                */
/***************************************************/
int empty(seqstack *s)
{
 	return(s->top==-1?1:0);
}

/**********************************/
/*函数功能：输入栈                */
/*函数名：input()                 */
/**********************************/
void input(seqstack *s)
{  	datatype x;
   	inits(s);
   	printf("请输入一组数据，以0做为结束符：\n");
   	scanf("%d",&x);
   	while(x)
   	{	s->elem[++s->top]=x;
    	scanf("%d",&x);
    }
}

/**********************************/
/*函数功能：输出栈                */
/*函数名：prints()                */
/**********************************/
void prints(seqstack *s)
{   int i;
	if(empty(s))
		printf("顺序栈是空的");
    else
		for(i=0;i<=s->top;i++)
    	{  	printf("%5d",s->elem[i]);
    		if((i+1)%10==0) printf("\n");
   		}
    printf("\n\n");
}

/***************************************************/
/*  函数功能：队列（顺序存储）初始化               */
/*  函数名：initq()                                */
/***************************************************/
void initq(sequeue *q)
{
   	q->front=q->rear=-1;
}

/**********************************/
/*函数功能：输出队列              */
/*函数名：printq()                */
/**********************************/
void printq(sequeue *q)
{   int i;
	if(q->front==q->rear)
		printf("循环队列是空的");
    else
		for(i=q->front+1;i<=q->rear;i++)
    	{  	printf("%5d",q->elem[i]);
    		if((i+1)%10==0) printf("\n");
    	}
    printf("\n\n");
}
