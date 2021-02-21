//л���
//2020.10.27
//˳��˫ջ
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct stack
{
	int maxsize;
	elementtype* data;
	int top1;
	int top2;
};
typedef struct stack stack;

int main()
{
	void scan(stack* p);
	void print(stack* p);
	stack* makestack(int n);
	bool push(stack* p,int tag,elementtype x);
	
	stack* p;
	p=makestack(7);
	scan(p);
	print(p);
 } 
 
 void scan(stack* p)	//��ѭ�������е�������ջ 
 {
 	bool push(stack* p,int tag,elementtype x);
 	
 	int tag;
 	elementtype x;
 	printf("��������ջ��ջһ��1 ջ����2������ջ������\n"); 
 	while(p->top1+1!=p->top2)
 	{
 		scanf("%d %d",&tag,&x);
 		push(p,tag,x);
	 }
 }
 
void print(stack* p)	//��ѭ�������е�������ջ 
 {
 	elementtype pop(stack* p,int tag);
 	
 	printf("ջһ��ջ��"); 
 	while(p->top1!=-1)
 	{
 		printf("%d",pop(p,1)) ;
	 }
	 printf("\nջ����ջ��"); 
	 while(p->top2!=p->maxsize)
	 {
	 	printf("%d",pop(p,2)) ;
	 }
 	
 }
 
 stack* makestack(int n)	//������ջ 
 {
	stack* p=(stack*)malloc(sizeof(stack));
	p->data=(elementtype*)malloc(n*sizeof(elementtype));  
	p->maxsize=n;
	p->top1=-1;
	p->top2=n;
	return p;
 }
 
bool push(stack* p,int tag,elementtype x)	//����������ջ 
 {
 	if(p->top1+1==p->top2) 
		{
			printf("full!");
			return false;
		}
	if(tag==1)
	{
		
		p->data[++(p->top1)]=x;
		return true;
	}
	else
	{
		p->data[--(p->top2)]=x;
		return true;
	}
  } 
  
elementtype pop(stack* p,int tag)	//����������ջ 
  {
	if(tag==1)
	{
		if(p->top1==-1)
		{
			printf("zero!");
			return false;
		}
		return p->data[(p->top1)--];
	 } 
	 else
	 {
 		if(p->top2==p->maxsize)
 		{
 			printf("zero!");
 			return false;
		 }
		 return p->data[(p->top2)++];
	 }
  }
