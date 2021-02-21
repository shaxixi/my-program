//谢玲红
//2020/11/5
//链式队列实现 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct node
{
	elementtype data;
	struct node* next;
 }; 
typedef struct node node;

struct queue
{
	int maxsize;
	node* front;
	node* rear;
};
typedef struct queue queue;
 
queue* creatqueue(int n);
bool insert(queue* p,elementtype x);
elementtype Delete(queue* p);

int main()
{
	queue* p;
	int x=0;
	static int n;
	printf("队列的数据个数是：");
	scanf("%d",&n); 
	p=creatqueue(n);
	printf("输入队列的数据：");
	for(n;n>0;n--)
	{
		scanf("%d",&x);
		insert(p,x);
	}
	while(p->front!=NULL)
	{
		printf("%d ",Delete(p));
	}
}

queue* creatqueue(int n)//创造一个空队列 
{
	queue* p=(queue*)malloc(sizeof(queue));
	p->rear=p->front=NULL;
	p->maxsize=n;
	return p;
}

bool insert(queue* p,elementtype x)//不带头结点的数据进队列 
{
	node* pt=(node*)malloc(sizeof(node));
	if(p->front==NULL)//在本结点放数据 
	{
		pt->data=x;//注意：pt是指向数据和下一个结点的，不是指向头结点和尾结点的 
		pt->next=NULL;
		p->rear=pt;
		p->front=pt;//为了方便判断队列空不空，用front来判断空不空，rear只负责增加就好了 
	}
	else//在下一结点放数据，然后往后推一个结点 
	{
		p->rear->next=pt;
		pt->data=x;
		pt->next=NULL;
		p->rear=p->rear->next;	
	}
	return true;
 } 
 
 elementtype Delete(queue* p)// 不带头结点的数据出队列 
 {
 	node* pt=(node*)malloc(sizeof(node));
 	elementtype x;
 	if(p->front==NULL)
 	{
 		printf("队列已空！");	
 		return 0;
	}
	pt=p->front;
	x=pt->data;
	p->front=pt->next;
	free(pt);
	return x;
  } 
