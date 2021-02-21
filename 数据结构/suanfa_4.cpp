//谢玲红
//2020.10.27
//顺序堆栈 
#include <stdio.h>
#include <stdlib.h>
#define datatype int
struct stack 
{
	int maxsize;
	datatype* data;	//为什么不用数组形式，因为数组需要有原始的限定容量[]，而指针可以后期自定义容量 
	int top;
};
typedef struct stack stack;

int main()
{
	stack* push(int n);
	void pop(stack* p);
	
	stack* p;
	printf("五个整数的入栈顺序是："); 
	p=push(5);
	printf("五个整数的出栈顺序是："); 
	pop(p);
 } 
 
stack* push(int n)	//创建栈并且入栈 
{
	stack* p=(stack*)malloc(sizeof(stack));
	p->data=(datatype*)malloc(n*sizeof(stack));
	p->maxsize=n;
	p->top=-1;	//栈的底端开始进入入 
	while(p->top!=p->maxsize-1) scanf("%d",&p->data[++(p->top)]);//由于top初始值为-1，所以要先加一 
	return p;
 } 
 
void pop(stack* p)
{
	stack* pt;
	pt=p;
	if(pt->top==-1)	printf("error!");
	else while(pt->top!=-1) printf("%6d",pt->data[(pt->top)--]);
}

