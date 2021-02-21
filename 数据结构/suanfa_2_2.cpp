#include <stdio.h>
#include <stdlib.h>
#define one 3
#define two 4
struct xiang
	{
		int xi;
		int zhi;
		struct xiang *next;	
	};
typedef struct xiang xiang;
typedef xiang *pt;

pt l(int n)//创建链表和插入 
{
	pt head,s,r;//head 头节点，s 当前节点，r 上一节点
	int i;
	if((head=(pt)malloc(sizeof(xiang)))==NULL) 
	{
		printf("error!");
		return 0;
	 } //检查head是否有被分配空间 
	head->next=NULL; 				//为什么不是head=NULL **** 
	r=head;//头结点置空
	for(i=0;i<n;i++)
	{
		if((s=(pt)malloc(sizeof(xiang)))==NULL)
		{
			printf("error!");
			return 0;
		}//检查s是否有被分配空间 
		scanf("%d %d",&s->xi,&s->zhi);
		r->next=s;							//head->next又不是空指针了 **** 
		r=s;//建立链表中两两之间的联系 并将链表往后移 
	 } 
	r->next=NULL;//尾结点置空 
	return head;//指向头节点以便于查找 
}

void print(pt list)//输出链表 
{
	pt p;
	p=list->next;
	while(p!=NULL)
	{
		printf("%-8d %-8d\n",p->xi,p->zhi);
		p=p->next;
	} 
//	return list;
}

void print_(pt list1,pt list2)//多项式相加并输出 
{
	pt p1,p2;
	p1=list1->next;
	p2=list2->next;
	while(p1!=NULL||p2!=NULL)
	{
		if(p1!=NULL&&p2!=NULL)//修改了if换成if-else 
		{
			if(p1->zhi>p2->zhi)
			{
				printf("%dx^%d + ",p1->xi,p1->zhi);
				p1=p1->next;
			}
			else 
			{
				if(p1->zhi<p2->zhi)
				{
					printf("%dx^%d + ",p2->xi,p2->zhi);
					p2=p2->next;
				}
				else
				{
					if(p1->zhi==p2->zhi)
					{
						printf("%dx^%d + ",p1->xi+p2->xi,p1->zhi);
						p1=p1->next;
						p2=p2->next;
					}
				}	
			}
		}
		if(p1==NULL&&p2!=NULL)
		{
			if(p2->next==NULL)
			{
				printf("%dx^%d	",p2->xi,p2->zhi);
				p2=p2->next;
			}
			else
			{
				printf("%dx^%d + ",p2->xi,p2->zhi);
				p2=p2->next;
			}
		}
		if(p2==NULL&&p1!=NULL)
		{
			if(p1->next==NULL)
			{
				printf("%dx^%d	",p1->xi,p1->zhi);
				p1=p1->next;
			}
			else
			{
				printf("%dx^%d + ",p1->xi,p1->zhi);
				p1=p1->next;
			}
					
		}
	}
}
int main()
{
	pt l(int n);
	void print(pt list);
	void print_(pt list1,pt list2);
	
	pt l1,l2;
	printf("\n输入第一个多项式中每项的系数 指数：\n");
	l1=l(one);
	printf("\n输入第一个多项式中每项的系数 指数：\n");
	l2=l(two);
	printf("\n第一个多项式每项的系数 指数：\n");
	print(l1);
	printf("\n第二个多项书每项的系数 指数：\n");
	print(l2);
	printf("\n两个多项式相加后的结果为：\n");
	print_(l1,l2);
	return 0;
 } 
/*
9 12
15 8
3 2
26 19
-4 8
-13 6
82 0
*/ 
