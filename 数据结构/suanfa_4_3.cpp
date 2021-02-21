//л���
//2020.10.28
//��ջӦ�� ���ʽ��ֵ
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
 	printf("������׺���ʽ,�ԡ�#����ͷ���ԡ�;��������\n");
 	while(x!=';')
 	{
 		scanf("%c",&x);
 		change(p,x,pt);
	 }
	last_insert(p,pt);
	printf("\n"); 
	printf("��׺���ʽ��\n");
	list* pp=pt;
	while(pp->next!=NULL) 
	{
		pp=pp->next;
		printf("%c ",pp->data); 
	}
	count(pt,p1);
 }
 
 stack* makestack()	//����һ����ջ�ձ� 
 {
 	stack* p=(stack*)malloc(sizeof(stack));
 	p->next=NULL;
 	return p;
 }
 
 bool push(stack* p,elementtype x)	//��x����ѹ��ջp�� 
 {
 	stack* pt=(stack*)malloc(sizeof(stack));
 	pt->next=p->next;
 	p->next=pt;
 	pt->data=x;
//	printf("[%c]",pt->data);
 	return true;
 }
 
  bool push_num(stack* p,int x)	//��x����ѹ��ջp�� 
 {
 	stack* pt=(stack*)malloc(sizeof(stack));
 	pt->next=p->next;
 	p->next=pt;
 	pt->data=x;
//	printf("[%c]",pt->data);
 	return true;
 }
 elementtype pop(stack* p)	//�ö������ݳ�ջ��ɾ���������� 
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
 
 list* makelist()	//����һ���յ����Ա� ���洢��׺���ʽת���ɺ�׺���ʽ֮��ı��ʽ˳�� 
 {
 	list* head;
 	if((head=(list*)malloc(sizeof(list)))==NULL) return 0;
	head->next=NULL;
	return head; 
 }
 
list* insert(list* head,elementtype x)	//��������  
 {
 	list* r,*s;
 	r=head;
 	if((s=(list*)malloc(sizeof(list)))==NULL) return 0;
 	while(r->next!=NULL) 
 	{
 		r=r->next;
	 }
	s->data=x;	//�����ڣ�r->next=s;	r=s;�����ڲ�ѭ��������Ҫ�����滻�� 
	s->next=r->next;
	r->next=s;
//	printf("{%c}",s->data);
	return head; 
 }
 
 // ����׺���ʽת��ɺ�׺���ʽ 
bool change(stack* p,elementtype x,list* pt)	//	���ö�ջ����������ջ��ջ���뵽���Ա� 
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
 
bool last_insert(stack* p,list* pt)		//����ջ��ʣ�����������뵽���Ա��У��ó������ĺ�׺���ʽ 
{
	list* insert(list* head,elementtype x);
	elementtype pop(stack* p);
	while(p->next!=NULL) insert(pt,pop(p));
	return true;
}

//�����׺���ʽ 
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
			default: c=(int)x-48;push(pt,c);//��Ϊx���ַ��������ͣ��������ֵ�0-9��ASCII��ֵΪ48-57��
			//����Ϊ�˰����������0-9���ͽ�����ASCII��ֵ��ȥ48 
		}
		p=p->next;
	}
	printf("\n\n��������\n%d",pop(pt));
	return true;
}
/*
#a+b/(c-d)*(e+f)%g;
#2+4/(3-1)*(5+4)%2;
*/ 
