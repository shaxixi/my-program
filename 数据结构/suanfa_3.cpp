//谢玲红
//2020.10.20 
//线性表顺序表
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define mixsize 100
struct list_shunxu
{
	ElementType data[mixsize];
	int size;
};
typedef list_shunxu list;

int main()
{
	list *Makelist(int n);
	bool Insert(list *p,int i,ElementType n);
	bool Delete(list *p,int i);
	ElementType Find(list * p,ElementType n);
	void print(list *p);
	
	list *p=NULL;
	printf("\n你想创建的线性表的5个整数：\n"); 
	p=Makelist(5);
	printf("\n线性表的5个整数为：\n");
	print(p);
	printf("\n在线性表中第二个数据插入数据5：\n"); 
	Insert(p,2,5);
	print(p);
	printf("\n在线性表中删除第三个数据：\n");
	Delete(p,3);
	print(p);
	printf("\n在线性表中数据3所在的位置是：\n");
	printf("%d",Find(p,3));
	return 0;
 } 
 
list *Makelist(int n)//建立一个表 
{
	list *p; 
	int i;
	p=(list *)malloc(sizeof(list));
	p->size=n;	
	for(i=0;i<p->size;i++) scanf("%d",&p->data[i]);
	return p;
}

bool Insert(list *p,int i,ElementType n)//插入数据 ，在p表中的第i个数据插入数据n
{
	int j;
	if(i<1||i>p->size+1)//error:if(i<1||i>p->size)
	{
		printf("insert number was error!");
		return false;//用布尔型返回结果 
	}
	if(p->size==mixsize)//error:if(p->size>mixsize)
	{
		printf("list length was error!");
		return false;
	}
	for(j=p->size;j>=i;j--)	p->data[j]=p->data[j-1];
	p->data[i-1]=n;
	p->size++;//error:表长增加 
	return false;//用布尔型返回结果 
} 

bool Delete(list *p,int i)//删除数据，删除在p表中第i个数据 
{
	int j;
	if(i<1||i>p->size) 
	{
		printf("detele number was error!");
		return false;
	}
	for(j=i-1;j<p->size;j++) p->data[j]=p->data[j+1];
	p->size--;
	return true;
}

ElementType Find(list * p,ElementType n)//查找数据，查找p表中的数据n
{
	int j;
	for(j=1;j<=p->size;j++)	if(p->data[j-1]==n) return j;
	return NULL;
}

void print(list *p)
{
	int i;
	for(i=0;i<p->size;i++) printf("%d ",p->data[i]);
	printf("\n");
}
