//谢玲红
//2020.10.22
//线性表双向链表 
#include <stdio.h>
#include <stdlib.h>
#define ElementType int 
struct list_lianbiao
{
	ElementType data;
	struct list_lianbiao* next;
	struct list_lianbiao* previous;
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
	printf("\n你所要创建的双向线性表的5个数据：\n");
	p=Creatlist(5);
	print(p);
	printf("\n双向线性表的长度为：\n");
	printf("%d \n",Lenth(p));
	printf("\n在双向线性表中第一个位置插入数据8\n");
	Insert(p,1,8);
	print(p);
	printf("\n在双向线性表中删除第3个数据\n");
	Detele(p,3);
	print(p);
	printf("\n在双向线性表中数据4的位置：\n");
	printf("%d \n",Find_number(p,4));
	printf("\n在双向线性表中第2个位置上的数据是：\n");
	printf("%d \n",Find_data(p,2));

}

list* Creatlist(int n)//创建新表，有n个结点
{
	int i;
	list* head, * r, * s;
	if ((head = (list*)malloc(sizeof(list))) == NULL) printf("error!");
	head->previous=NULL;		//头指针置空   
	head->next=NULL;			
	r=head;						//有头结点 
	for (i=0;i<n;i++)
	{
		if ((s = (list*)malloc(sizeof(list))) == NULL) printf("error!");
		scanf("%d", &s->data);
		s->previous=r;		//双向 
		r->next=s;
		r=s;
	} 
	r->next=NULL;
	return head;
}

int Lenth(list* p)//求表长
{
	int count=0;
	list* pt;
	pt = p->next;
	while (pt!=NULL)
	{
		count++;
		pt = pt->next;
	}
	return count;
}

bool Insert(list* p, int i, ElementType n)//插入数据，在p表的定位i上插入数据n
{
	list* pt, * s;
	int j = 0;		//零界点多思考和下面的判断多对比 
	pt = p;
	while ( pt!=NULL && j < i - 1 )//定位在i-1的结点 此时i没有给定范围
	{
		pt = pt->next;
		j++;
	}
//	if(pt==NULL)
//	if(j!=i-1)
	if ( pt==NULL || j != i - 1)//我认为pt==NULL和j!=i-1是等价的【疑问】
	{
		printf("error!");
		return false;
	}
	else
	{
		s = (list*)malloc(sizeof(list));
		s->data = n;
		s->previous=pt;		//插入数据 
		s->next=pt->next;
		pt->next->previous=s;
		pt->next=s;
		return true;
	}
}

bool Detele(list *p,int i)	//删除数据，删除数据n
{
	list* pre,*s;
	int j=0;
	pre = p;
	while ( pre!=NULL&&j < i - 1)
	{
		j++;
		pre = pre->next;
	}
	if (pre == NULL || j != i - 1 || pre->next == NULL)//判断条件，就是有点迷
	{
		printf("error!");
		return false;
	}
	else
	{
		s=pre->next;		//删除数据 
		pre->next=s->next;
		s->next->previous=pre;
		free(s);
		return true;
	}
 } 

int Find_number(list* p, ElementType n)//查找p表中的数据n所在位置 
{
	int count=1;
	list* pt;
	pt = p->next;
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
	int j=1;
	list *pt;
	pt=p->next;
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
	int i;
	list *pt;
	pt=p->next;
	printf("\n顺序：\n");
	while(pt!=NULL) 
	{
		printf("%d ",pt->data);
		if(pt->next==NULL) break;
		pt=pt->next;
		
	}
	printf("\n");
	printf("\n逆序：\n");
	while(pt!=p)
	{
		printf("%d ",pt->data);
		pt=pt->previous;
	 } 
	 printf("\n");
}
