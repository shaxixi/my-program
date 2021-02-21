//л���
//2020.10.28
//��ʽ��ջ
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct stack
{
	elementtype data;
	struct stack* next;
 } ;
 typedef struct stack stack;
 
 int main()
 {
 	stack* makestack();
 	void scan(stack* p,int n);
 	void print(stack* p);
 	bool push(stack* p,elementtype x);
 	elementtype Delete(stack* p);
 	
 	int i;
 	stack* p=makestack();
 	printf("��ջ��5������Ϊ��\n");
 	for(i=0;i<5;i++)	//��ѭ��������ջ 
 	{
 		elementtype x;
 		scanf("%d",&x);
 		push(p,x);
	 }
/*	push(p,1);
	push(p,2);
	push(p,3);
	push(p,4);
	push(p,5);*/
	printf("��ջ��5������Ϊ��\n");	 
 	while(p->next!=NULL)	//��ѭ�����ϳ�ջ����ɾ�����ڵ� 
 	{
 		printf("%d",Delete(p));
	 }
 }
 
 stack* makestack()	//����һ���ձ� 
 {
 	stack* p=(stack*)malloc(sizeof(stack));
	p->next=NULL; 
	return p;
 }
 
bool push(stack* p,elementtype x)	//������ջ���� 
 {
 	stack* pt;
	 if((pt=(stack*)malloc(sizeof(stack)))==NULL) return false;
	 else
	 {
	 	pt->data=x;
	 	pt->next=p->next;
	 	p->next=pt;
	 	return true;
	 }
 }
 
elementtype Delete(stack* p)	//ɾ�����ڵ㲢�ҳ�ջ���ڵ������ 
 {
 	stack* pt;
 	elementtype x;
 	if(p->next==NULL) return false;
 	else 
 	{
		pt=p->next;
		x=pt->data;
		p->next=pt->next;
		free(pt);
		return x;
	}
  } 
