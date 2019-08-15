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
/*  �������ܣ�ջ��˳��洢����ʼ��                */
/*  ��������inits()                               */
/**************************************************/ 
void inits(seqstack *s)
{
  	s->top=-1;
}

/***************************************************/
/*  �������ܣ��ж�ջ��˳��洢���Ƿ�Ϊ��           */
/*  ��������empty()                                */
/***************************************************/
int empty(seqstack *s)
{
 	return(s->top==-1?1:0);
}

/**********************************/
/*�������ܣ�����ջ                */
/*��������input()                 */
/**********************************/
void input(seqstack *s)
{  	datatype x;
   	inits(s);
   	printf("������һ�����ݣ���0��Ϊ��������\n");
   	scanf("%d",&x);
   	while(x)
   	{	s->elem[++s->top]=x;
    	scanf("%d",&x);
    }
}

/**********************************/
/*�������ܣ����ջ                */
/*��������prints()                */
/**********************************/
void prints(seqstack *s)
{   int i;
	if(empty(s))
		printf("˳��ջ�ǿյ�");
    else
		for(i=0;i<=s->top;i++)
    	{  	printf("%5d",s->elem[i]);
    		if((i+1)%10==0) printf("\n");
   		}
    printf("\n\n");
}

/***************************************************/
/*  �������ܣ����У�˳��洢����ʼ��               */
/*  ��������initq()                                */
/***************************************************/
void initq(sequeue *q)
{
   	q->front=q->rear=-1;
}

/**********************************/
/*�������ܣ��������              */
/*��������printq()                */
/**********************************/
void printq(sequeue *q)
{   int i;
	if(q->front==q->rear)
		printf("ѭ�������ǿյ�");
    else
		for(i=q->front+1;i<=q->rear;i++)
    	{  	printf("%5d",q->elem[i]);
    		if((i+1)%10==0) printf("\n");
    	}
    printf("\n\n");
}
