//谢玲红
//2020.10.28
//堆栈应用 表达式求值
#include <stdio.h>
#include <stdlib.h>
#define elementtype char
#define maxsize 100
struct stack
{
	elementtype data;
	struct stack* next;
 };
struct list
{
	elementtype data;
	struct list* next;
};
 typedef struct stack stack;
 typedef struct list list;

stack* makestack();
bool push(stack* p,elementtype x);
elementtype pop(stack* p);
list* makelist();
list* insert(list* head,elementtype x);
bool change(stack* p,elementtype x,list* pt);
bool last_insert(stack* p,list* pt);
bool count(list* p,stack* pt);
bool push_num(stack* p,int x);

 int main()
 {
 	stack* p=makestack();
 	list* pt=makelist();
 	stack* p1=makestack();
 	char x='0';
 	printf("输入中缀表达式,以“#”开头，以“;”结束：\n");
 	while(x!=';')
 	{
 		scanf("%c",&x);
 		change(p,x,pt);
	 }
	last_insert(p,pt);
	printf("\n"); 
	printf("后缀表达式：\n");
	list* pp=pt;
	while(pp->next!=NULL) 
	{
		pp=pp->next;
		printf("%c ",pp->data); 
	}
	count(pt,p1);
 }
 
 stack* makestack()	//创建一个堆栈空表 
 {
 	stack* p=(stack*)malloc(sizeof(stack));
 	p->next=NULL;
 	return p;
 }
 
 bool push(stack* p,elementtype x)	//将x数据压入栈p中 
 {
 	stack* pt=(stack*)malloc(sizeof(stack));
 	pt->next=p->next;
 	p->next=pt;
 	pt->data=x;
//	printf("[%c]",pt->data);
 	return true;
 }
 
  bool push_num(stack* p,int x)	//将x数据压入栈p中 
 {
 	stack* pt=(stack*)malloc(sizeof(stack));
 	pt->next=p->next;
 	p->next=pt;
 	pt->data=x;
//	printf("[%c]",pt->data);
 	return true;
 }
 elementtype pop(stack* p)	//让顶置数据出栈并删除顶置数据 
 {
 	stack* pt;
 	elementtype x;
 	if(p->next==NULL) return 0;
 	else
	{
		pt=p->next;
		x=pt->data;
		p->next=pt->next;
		free(pt);
//		printf("(%c)",x);
		return x;
	}
 }
 
 list* makelist()	//创建一个空的线性表 ：存储中缀表达式转换成后缀表达式之后的表达式顺序 
 {
 	list* head;
 	if((head=(list*)malloc(sizeof(list)))==NULL) return 0;
	head->next=NULL;
	return head; 
 }
 
list* insert(list* head,elementtype x)	//插入数据  
 {
 	list* r,*s;
 	r=head;
 	if((s=(list*)malloc(sizeof(list)))==NULL) return 0;
 	while(r->next!=NULL) 
 	{
 		r=r->next;
	 }
	s->data=x;	//区别于：r->next=s;	r=s;（有内部循环，所以要不断替换） 
	s->next=r->next;
	r->next=s;
//	printf("{%c}",s->data);
	return head; 
 }
 
 // 将中缀表达式转变成后缀表达式 
bool change(stack* p,elementtype x,list* pt)	//	利用堆栈，将数据入栈出栈插入到线性表 
 {
 	bool push(stack* p,elementtype x);
 	elementtype pop(stack* p);
 	list* insert(list* head,elementtype x);
//	printf("%c",x);
	int y;
 	if(x=='*'||x=='/'||x=='%') y=1;
	else if(x=='+'||x=='-') y=2;
		else if(x=='(') y=6;
			else if(x==')') y=7;
				else if(x=='#') y=8;
					else if(x==';') y=9;
						else y=10;
 	switch (y)
 	{
 		case 1: push(p,x);break;
 		case 2:
 			while((p->next->data=='*')||(p->next->data=='/')||(p->next->data=='%')) 
 			{insert(pt,pop(p));}
			push(p,x);
			break;
		case 6: push(p,x);break;
		case 7:
			while(p->next->data!='(') insert(pt,pop(p));
			pop(p);
			break;
		case 8:
			push(p,x);
			break;
		case 9: 
			break;
		default: 
			insert(pt,x);
	 }
	return true;
 }
 
bool last_insert(stack* p,list* pt)		//将堆栈中剩余的运算符插入到线性表中，得出完整的后缀表达式 
{
	list* insert(list* head,elementtype x);
	elementtype pop(stack* p);
	while(p->next!=NULL) insert(pt,pop(p));
	return true;
}

//计算后缀表达式 
bool count(list* p,stack* pt)
{
	bool push_num(stack* p,int x);
	elementtype pop(stack* p);
	list* now;
	elementtype x;
	int a,b,c;
	if(p==NULL) return false;
	now=p->next;
	while(p->data!='#')
	{
		x=p->data;
		int y;
	 	if(x=='*') y=1;
	 	else if(x=='/') y=2;
	 		else if(x=='%') y=3;
				else if(x=='+') y=4;
					else if(x=='-') y=5;
						else y=10;
	 	switch (y)
	 	{
	 		case 1: b=pop(pt);a=pop(pt);c=a*b;push_num(pt,c);break;
	 		case 2: b=pop(pt);a=pop(pt);c=a/b;push_num(pt,c);break;	
			case 3: b=pop(pt);a=pop(pt);c=a%b;push_num(pt,c);break;
			case 4: b=pop(pt);a=pop(pt);c=a+b;push_num(pt,c);break;
			case 5: b=pop(pt);a=pop(pt);c=a-b;push_num(pt,c);break;
			default: c=(int)x-48;push(pt,c);//因为x是字符数据类型，根据数字的0-9的ASCII码值为48-57，
			//所以为了把它变成数字0-9，就将它的ASCII码值减去48 
		}
		p=p->next;
	}
	printf("\n\n计算结果：\n%d",pop(pt));
	return true;
}
/*
#a+b/(c-d)*(e+f)%g;
#2+4/(3-1)*(5+4)%2;
*/ 
