//谢玲红
//2020.10.20 
//线性表单向链表 
#include <stdio.h>
#include <stdlib.h>
#define ElementType int 
struct list_lianbiao
{
	ElementType data;
	struct list_lianbiao* next;
};
typedef struct list_lianbiao list;

int main()
{
	list* Creatlist(int n);
	int Lenth(list* p);
	bool Insert(list* p, int i, ElementType n); 
	bool Detele(list *p,int i);
	int Find_number(list* p, ElementType n);
	ElementType Find_data(list *p,int i);
	void print(list *p);
	
	list *p;
	printf("\n你所要创建的线性表的5个数据：\n");
	p=Creatlist(5);
	printf("\n线性表的5个数据是：\n");
	print(p);
	printf("\n线性表的长度为：\n");
	printf("%d \n",Lenth(p));
	printf("\n在线性表中第一个位置插入数据5\n");
	Insert(p,1,5);
	print(p);
	printf("\n在线性表中删除第3个数据\n");
	Detele(p,3);
	print(p);
	printf("\n在线性表中数据4的位置：\n");
	printf("%d \n",Find_number(p,4));
	printf("\n在线性表中第2个位置上的数据是：\n");
	printf("%d \n",Find_data(p,2));
}

list* Creatlist(int n)//创建新表，有n个结点
{
	int i; 
	list* head, * r, * s;
	if ((head = (list*)malloc(sizeof(list))) == NULL) printf("error!");
	head->next = NULL;//头指针置空 
	r = head;
	for (i=0;i<n;i++)
	{
		if ((s = (list*)malloc(sizeof(list))) == NULL) printf("error!");
		scanf("%d", &s->data);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

int Lenth(list* p)//求表长
{
	int count=0;
	list* pt;
	pt = p->next;
	while (pt != NULL)
	{
		pt = pt->next;
		count++;
	}
	return count;
}

bool Insert(list* p, int i, ElementType n)//插入数据，在p表的定位i上插入数据n
{
	list* pt, * s;
	int j = 0;
	pt = p;
	while (pt != NULL && j < i - 1 )//定位在i-1的结点 此时i没有给定范围
	{
		pt = pt->next;
		j++;
	}
//	if(pt==NULL)
//	if(j!=i-1)
	if (pt == NULL || j != i - 1)//我认为pt==NULL和j!=i-1是等价的【疑问】
	{
		printf("error!");
		return false;
	}
	else
	{
		s = (list*)malloc(sizeof(list));
		s->data = n;
		s->next = pt->next;
		pt->next = s;
		return true;
	}
}

bool Detele(list *p,int i)//删除数据，删除数据n
{
	list* pre,*s;
	int j=0;
	pre = p;
	while (pre != NULL && j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (pre == NULL || j != i - 1 || pre->next == NULL)//判断条件，就是有点迷
	{
		printf("error!");
		return false;
	}
	else
	{
		s = pre->next;
		pre->next = s->next;
		free(s);
		return true;
	}
 } 

int Find_number(list* p, ElementType n)//查找p表中的数据n所在位置 
{
	int count=0;
	list* pt;
	pt = p;
	while (pt != NULL && pt->data != n) 
	{
		pt = pt->next;
		count++;
	}
	if (pt != NULL) return count;
	else return NULL;
}

ElementType Find_data(list *p,int i)//查找p表中的第i个位置的数据
{
	int j=0;
	list *pt;
	pt=p;
	while(pt!=NULL&&j<i) 
	{
		pt=pt->next;
		j++;
	}
	if(pt!=NULL) return pt->data;
	else return NULL;
 } 

void print(list *p)
{
	list *pt;
	pt=p->next;
	while(pt!=NULL)
	{
		printf("%d ",pt->data);
		pt=pt->next;
	}
	printf("\n");
}
