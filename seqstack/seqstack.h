#include  <stdio.h>
#include  <stdlib.h>
#define MAXSIZE 100
typedef char datatype;
typedef struct seqstack{
   	datatype elem[MAXSIZE];
   	int top;
}seqstack;
 
/**************************************************/
/*  函数功能：栈（顺序存储）初始化                */
/*  函数名：init()                                */
/**************************************************/ 
void init(seqstack *s)
{
  	s->top=-1;
}

/***************************************************/
/*  函数功能：判断栈（顺序存储）是否为空           */
/*  函数名：empty()                                */
/***************************************************/
int empty(seqstack s)
{
 	return(s.top==-1? 1:0);
}

/***************************************************/
/*  函数功能：栈（顺序存储）的插入（进栈）操作     */
/*  函数名：push()                                 */
/***************************************************/
void push(seqstack *s,datatype x)
{
   	if(s->top==MAXSIZE-1)
     	{printf("\nThe sequence stack is full!");exit(1);}
   	s->top++;
   	s->elem[s->top]=x;
}

/***************************************************/
/*  函数功能：栈（顺序存储）的删除（出栈）操作     */
/*  函数名pop()                                    */
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
