//谢玲红
//2020.10.28
//链式堆栈
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
 	printf("入栈的5个整数为：\n");
 	for(i=0;i<5;i++)	//用循环不断入栈 
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
	printf("出栈的5个整数为：\n");	 
 	while(p->next!=NULL)	//用循环不断出栈并且删除顶节点 
 	{
 		printf("%d",Delete(p));
	 }
 }
 
 stack* makestack()	//创建一个空表 
 {
 	stack* p=(stack*)malloc(sizeof(stack));
	p->next=NULL; 
	return p;
 }
 
bool push(stack* p,elementtype x)	//单个入栈整数 
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
 
elementtype Delete(stack* p)	//删除顶节点并且出栈顶节点的整数 
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
