#include  <stdio.h>
#include  <stdlib.h>
#define MAXSIZE 100
typedef char datatype;
typedef struct seqstack{
   	datatype elem[MAXSIZE];
   	int top;
}seqstack;
 
/**************************************************/
/*  �������ܣ�ջ��˳��洢����ʼ��                */
/*  ��������init()                                */
/**************************************************/ 
void init(seqstack *s)
{
  	s->top=-1;
}

/***************************************************/
/*  �������ܣ��ж�ջ��˳��洢���Ƿ�Ϊ��           */
/*  ��������empty()                                */
/***************************************************/
int empty(seqstack s)
{
 	return(s.top==-1? 1:0);
}

/***************************************************/
/*  �������ܣ�ջ��˳��洢���Ĳ��루��ջ������     */
/*  ��������push()                                 */
/***************************************************/
void push(seqstack *s,datatype x)
{
   	if(s->top==MAXSIZE-1)
     	{printf("\nThe sequence stack is full!");exit(1);}
   	s->top++;
   	s->elem[s->top]=x;
}

/***************************************************/
/*  �������ܣ�ջ��˳��洢����ɾ������ջ������     */
/*  ������pop()                                    */
/***************************************************/
datatype pop(seqstack *s)
{
   	datatype x;
	if(s->top==-1)
     	{printf("\nThe sequence stack is empty!");exit(1);}
   	x=s->elem[s->top];
	s->top--;
	return x;
}
