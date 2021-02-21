//л���
//2020/11/4
//˳�����ʵ�� �Ƚ��ȳ� 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct queue
{
	elementtype* data;
	int maxsize;
	int front;//���е�ͷ 
	int rear; //���е�β 
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
	printf("���е�������:");//ȷ�����������ݵĸ��� 
	scanf("%d",&n);
	p=createqueue(n+1);//��Ϊ��������һ����ַ�������ǿյģ����Դ������е�ʱ��Ҫ��һ 
	printf("������е������ǣ�");
	while((p->rear+1)%p->maxsize!=p->front)
	{
		scanf("%d",&x);
		insert(p,x); 
	}
	
	printf("�����е������ǣ�");
	while(p->front!=p->rear)
	{
		printf("%d",Delete(p));
	}	
}

queue* createqueue(int n)//����һ���ն��� 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(elementtype*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,elementtype x)//����β�������� 
{
	if((p->rear+1)%p->maxsize==p->front)
	{
		printf("����������");
		return false; 
	}
	p->rear=(p->rear+1)%p->maxsize;//����38�е���˳���ԭ���ǣ�p->front==p->rearʱΪ�գ����ܴ������ 
	p->data[p->rear]=x;
	return true;
}

elementtype Delete(queue* p)//����ͷɾ������ 
{
	if(p->front==p->rear) 
	{
		printf("�����ѿգ�");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}

