#include <stdio.h>
#include <stdlib.h>
#define datatype int
#define N 5
struct list
{
	datatype data;
	struct list *next;
};
typedef struct list list;
typedef list *list_p;

list_p creat_list(int n)//创造链表 并且插入链表 
{
	list_p head,r,s;//head 头结点；r 前一结点；s 现结点；
	int i;
	if((head=(list_p)malloc(sizeof(list)))==NULL)
	{
		printf("error!");
		return 0;
	 } 
	head->next=NULL;
//	head=NULL; 
	r=head;//头结点置空
	for(i=0;i<n;i++)
	{
		if((s=(list_p)malloc(sizeof(list)))==NULL)
		{
			printf("error!");
			return 0;
		}
		scanf("%d",&s->data);
		r->next=s;//建立前一结点和现结点的联系 
		r=s; //将现结点变成前一结点，以便于现结点重新赋值 
	 } 
	 r->next=NULL;//尾结点置空
	 return head; 
}

void print(list_p p1)//输出链表 
{
	list_p p;
	p=p1->next;
	while(p!=NULL)
	{
		printf("%-8d",p->data);
		p=p->next;
	}
}
int main()
{
	list_p creat_list(int n);
	void print(list_p p1);
	
	list_p no_1;
	printf("输入你想创建链表的五个数：\n");
	no_1=creat_list(N);
	printf("你所创建的链表是：\n");
	print(no_1);
	return 0;
}

