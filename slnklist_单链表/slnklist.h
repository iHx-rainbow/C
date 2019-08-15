#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
	datatype data;
   	struct node *next;
}Lnode,*linklist;

/******************************************/
/*�������ƣ�creatbystack() 		          */
/*�������ܣ�ͷ�巨������ͷ���ĵ�����    */
/******************************************/
linklist creatbystack()
{
    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    printf("�����������������У���0�������룩:\n");
    scanf("%d",&x);
    while(x!=0)
    {
        s=(linklist)malloc(sizeof(Lnode));
        s->data=x;
        s->next=head->next;
        head->next=s;
        scanf("%d",&x);
    }
    return head;
}

/*****************************************/
/*�������ƣ�creatbyqueue() 			 */
/*�������ܣ�β�巨������ͷ���ĵ�����   */
/*****************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    printf("�����������������У���0�������룩:\n");
    scanf("%d",&x);
    while(x!=0)
    {
         s=(linklist)malloc(sizeof(Lnode));
         s->data=x;
         r->next=s;
         r=s;
         scanf("%d",&x);
   }
    r->next=NULL;
    return head;
}

/************************************/
/*�������ƣ�print()		 		*/
/*�������ܣ������ͷ���ĵ�����    */
/************************************/
void print(linklist head)
{
    linklist p;
    int i=0;
    p=head->next;
    while(p)
    {
        printf("%5d",p->data);
        i++;
        if(i%10==0)    printf("\n");
        p=p->next;
    }
    printf("\n\n");
}

/***********************************/
/*�������ƣ�delList()		 	   */
/*�������ܣ��ͷŴ�ͷ���ĵ�����   */
/***********************************/
void delList(linklist head)
{ 	linklist p=head->next;
  	while(p)
 	{ 	head->next=p->next;
    	free(p);
    	p=head->next;
  	}
  	free(head);
}
