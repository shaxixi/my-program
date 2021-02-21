//л���
//2020/11/5
//��ʽ����ʵ�� 
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
	printf("���е����ݸ����ǣ�");
	scanf("%d",&n); 
	p=creatqueue(n);
	printf("������е����ݣ�");
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

queue* creatqueue(int n)//����һ���ն��� 
{
	queue* p=(queue*)malloc(sizeof(queue));
	p->rear=p->front=NULL;
	p->maxsize=n;
	return p;
}

bool insert(queue* p,elementtype x)//����ͷ�������ݽ����� 
{
	node* pt=(node*)malloc(sizeof(node));
	if(p->front==NULL)//�ڱ��������� 
	{
		pt->data=x;//ע�⣺pt��ָ�����ݺ���һ�����ģ�����ָ��ͷ����β���� 
		pt->next=NULL;
		p->rear=pt;
		p->front=pt;//Ϊ�˷����ж϶��пղ��գ���front���жϿղ��գ�rearֻ�������Ӿͺ��� 
	}
	else//����һ�������ݣ�Ȼ��������һ����� 
	{
		p->rear->next=pt;
		pt->data=x;
		pt->next=NULL;
		p->rear=p->rear->next;	
	}
	return true;
 } 
 
 elementtype Delete(queue* p)// ����ͷ�������ݳ����� 
 {
 	node* pt=(node*)malloc(sizeof(node));
 	elementtype x;
 	if(p->front==NULL)
 	{
 		printf("�����ѿգ�");	
 		return 0;
	}
	pt=p->front;
	x=pt->data;
	p->front=pt->next;
	free(pt);
	return x;
  } 
