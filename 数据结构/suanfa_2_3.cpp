#include <stdio.h>
#include <stdlib.h>
#define datatype int
#define N 5
struct list
{
	datatype data;
	struct list *next;
};
typedef struct list list;
typedef list *list_p;

list_p creat_list(int n)//�������� ���Ҳ������� 
{
	list_p head,r,s;//head ͷ��㣻r ǰһ��㣻s �ֽ�㣻
	int i;
	if((head=(list_p)malloc(sizeof(list)))==NULL)
	{
		printf("error!");
		return 0;
	 } 
	head->next=NULL;
//	head=NULL; 
	r=head;//ͷ����ÿ�
	for(i=0;i<n;i++)
	{
		if((s=(list_p)malloc(sizeof(list)))==NULL)
		{
			printf("error!");
			return 0;
		}
		scanf("%d",&s->data);
		r->next=s;//����ǰһ�����ֽ�����ϵ 
		r=s; //���ֽ����ǰһ��㣬�Ա����ֽ�����¸�ֵ 
	 } 
	 r->next=NULL;//β����ÿ�
	 return head; 
}

void print(list_p p1)//������� 
{
	list_p p;
	p=p1->next;
	while(p!=NULL)
	{
		printf("%-8d",p->data);
		p=p->next;
	}
}
int main()
{
	list_p creat_list(int n);
	void print(list_p p1);
	
	list_p no_1;
	printf("�������봴��������������\n");
	no_1=creat_list(N);
	printf("���������������ǣ�\n");
	print(no_1);
	return 0;
}

