//л���
//2020.10.27
//˳���ջ 
#include <stdio.h>
#include <stdlib.h>
#define datatype int
struct stack 
{
	int maxsize;
	datatype* data;	//Ϊʲô����������ʽ����Ϊ������Ҫ��ԭʼ���޶�����[]����ָ����Ժ����Զ������� 
	int top;
};
typedef struct stack stack;

int main()
{
	stack* push(int n);
	void pop(stack* p);
	
	stack* p;
	printf("�����������ջ˳���ǣ�"); 
	p=push(5);
	printf("��������ĳ�ջ˳���ǣ�"); 
	pop(p);
 } 
 
stack* push(int n)	//����ջ������ջ 
{
	stack* p=(stack*)malloc(sizeof(stack));
	p->data=(datatype*)malloc(n*sizeof(stack));
	p->maxsize=n;
	p->top=-1;	//ջ�ĵ׶˿�ʼ������ 
	while(p->top!=p->maxsize-1) scanf("%d",&p->data[++(p->top)]);//����top��ʼֵΪ-1������Ҫ�ȼ�һ 
	return p;
 } 
 
void pop(stack* p)
{
	stack* pt;
	pt=p;
	if(pt->top==-1)	printf("error!");
	else while(pt->top!=-1) printf("%6d",pt->data[(pt->top)--]);
}

