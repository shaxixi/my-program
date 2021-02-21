//谢玲红
//2020/11/4
//顺序队列实现 先进先出 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct queue
{
	elementtype* data;
	int maxsize;
	int front;//队列的头 
	int rear; //队列的尾 
};
typedef struct queue queue; 

void scan(queue* p);
void print(queue* p);
queue* createqueue(int n);
bool insert(queue* p,elementtype x);
elementtype Delete(queue* p);

int main()
{
	queue* p;
	static int n;
	int x;
	printf("队列的总数是:");//确定队列中数据的个数 
	scanf("%d",&n);
	p=createqueue(n+1);//因为队列中有一个地址的内容是空的，所以创建队列的时候要加一 
	printf("进入队列的数据是：");
	while((p->rear+1)%p->maxsize!=p->front)
	{
		scanf("%d",&x);
		insert(p,x); 
	}
	
	printf("出队列的数据是：");
	while(p->front!=p->rear)
	{
		printf("%d",Delete(p));
	}	
}

queue* createqueue(int n)//创造一个空队列 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(elementtype*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,elementtype x)//队列尾插入数据 
{
	if((p->rear+1)%p->maxsize==p->front)
	{
		printf("队列已满！");
		return false; 
	}
	p->rear=(p->rear+1)%p->maxsize;//不和38行调换顺序的原因是：p->front==p->rear时为空，不能存放数据 
	p->data[p->rear]=x;
	return true;
}

elementtype Delete(queue* p)//队列头删除数据 
{
	if(p->front==p->rear) 
	{
		printf("队列已空！");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}

