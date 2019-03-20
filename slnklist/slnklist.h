#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
	datatype data;
   	struct node *next;
}Lnode,*linklist;

/******************************************/
/*函数名称：creatbystack() 		          */
/*函数功能：头插法建立带头结点的单链表    */
/******************************************/
linklist creatbystack()
{
    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    printf("请输入若干整数序列（以0结束输入）:\n");
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
/*函数名称：creatbyqueue() 			 */
/*函数功能：尾插法建立带头结点的单链表   */
/*****************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    printf("请输入若干整数序列（以0结束输入）:\n");
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
/*函数名称：print()		 		*/
/*函数功能：输出带头结点的单链表    */
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
/*函数名称：delList()		 	   */
/*函数功能：释放带头结点的单链表   */
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
