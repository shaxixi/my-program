//л���
//2020/11/6
//��ʮ������ת���ɶ����ƣ��˽��ƣ�ʮ������ 
#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int data;
	struct stack* next;
};
typedef struct stack stack;

stack* creatstack();
bool insert(stack* p,int x);
int Delete(stack* p);
int count_2(stack* p,int x);

int main()
{
	stack* p=creatstack();
	int x;
	printf("����һ��ʮ����������");
	scanf("%d",&x);
	count_2(p,x);
}

stack* creatstack()
{
	stack* p=(stack*)malloc(sizeof(stack));
	p->next=NULL;
	return p;
}

bool insert(stack* p,int x)
{
	stack* pt=(stack*)malloc(sizeof(stack));
	pt->next=p->next;
	pt->data=x;
	p->next=pt;
//	printf("(%d) ",pt->data);
	return true;
}

int Delete(stack* p)
{
	stack* pt=(stack*)malloc(sizeof(stack));
	int x;
	pt=p->next;
	x=pt->data;
	p->next=pt->next;
	free(pt);
//	printf("{%d} ",x);
	return x;
}

int count_2(stack* p,int x)//ʮ����ת���ɶ����ƺͰ˽��� ,ʮ������ 
{
//	printf("[%d] ",x);
	bool insert(stack* p,int x);
	int Delete(stack* p);
	int y;
	printf("������Ϊ��"); 
	y=x;
	while(y!=0) 
	{
		insert(p,y%2);
		y=y/2;
	}
	while(p->next!=NULL) printf("%d",Delete(p));
	
	printf("\n�˽���Ϊ��");
	y=x;
	while(y!=0) 
	{
		insert(p,y%8);
		y=y/8;
	}
	while(p->next!=NULL) printf("%d",Delete(p));
	
	printf("\nʮ������Ϊ��");
	y=x;
	while(y!=0)
	{
		insert(p,y%16);
		y=y/16;
	}
	while(p->next!=NULL)
	{
		int z=Delete(p);
		switch(z) 
		{
			case 10: printf("A");break;
			case 11: printf("B");break;
			case 12: printf("C");break;
			case 13: printf("D");break;
			case 14: printf("E");break;
			case 15: printf("F");break;
			default: printf("%d",z);
		}
		
	}
}


