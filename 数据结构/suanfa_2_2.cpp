#include <stdio.h>
#include <stdlib.h>
#define one 3
#define two 4
struct xiang
	{
		int xi;
		int zhi;
		struct xiang *next;	
	};
typedef struct xiang xiang;
typedef xiang *pt;

pt l(int n)//��������Ͳ��� 
{
	pt head,s,r;//head ͷ�ڵ㣬s ��ǰ�ڵ㣬r ��һ�ڵ�
	int i;
	if((head=(pt)malloc(sizeof(xiang)))==NULL) 
	{
		printf("error!");
		return 0;
	 } //���head�Ƿ��б�����ռ� 
	head->next=NULL; 				//Ϊʲô����head=NULL **** 
	r=head;//ͷ����ÿ�
	for(i=0;i<n;i++)
	{
		if((s=(pt)malloc(sizeof(xiang)))==NULL)
		{
			printf("error!");
			return 0;
		}//���s�Ƿ��б�����ռ� 
		scanf("%d %d",&s->xi,&s->zhi);
		r->next=s;							//head->next�ֲ��ǿ�ָ���� **** 
		r=s;//��������������֮�����ϵ �������������� 
	 } 
	r->next=NULL;//β����ÿ� 
	return head;//ָ��ͷ�ڵ��Ա��ڲ��� 
}

void print(pt list)//������� 
{
	pt p;
	p=list->next;
	while(p!=NULL)
	{
		printf("%-8d %-8d\n",p->xi,p->zhi);
		p=p->next;
	} 
//	return list;
}

void print_(pt list1,pt list2)//����ʽ��Ӳ���� 
{
	pt p1,p2;
	p1=list1->next;
	p2=list2->next;
	while(p1!=NULL||p2!=NULL)
	{
		if(p1!=NULL&&p2!=NULL)//�޸���if����if-else 
		{
			if(p1->zhi>p2->zhi)
			{
				printf("%dx^%d + ",p1->xi,p1->zhi);
				p1=p1->next;
			}
			else 
			{
				if(p1->zhi<p2->zhi)
				{
					printf("%dx^%d + ",p2->xi,p2->zhi);
					p2=p2->next;
				}
				else
				{
					if(p1->zhi==p2->zhi)
					{
						printf("%dx^%d + ",p1->xi+p2->xi,p1->zhi);
						p1=p1->next;
						p2=p2->next;
					}
				}	
			}
		}
		if(p1==NULL&&p2!=NULL)
		{
			if(p2->next==NULL)
			{
				printf("%dx^%d	",p2->xi,p2->zhi);
				p2=p2->next;
			}
			else
			{
				printf("%dx^%d + ",p2->xi,p2->zhi);
				p2=p2->next;
			}
		}
		if(p2==NULL&&p1!=NULL)
		{
			if(p1->next==NULL)
			{
				printf("%dx^%d	",p1->xi,p1->zhi);
				p1=p1->next;
			}
			else
			{
				printf("%dx^%d + ",p1->xi,p1->zhi);
				p1=p1->next;
			}
					
		}
	}
}
int main()
{
	pt l(int n);
	void print(pt list);
	void print_(pt list1,pt list2);
	
	pt l1,l2;
	printf("\n�����һ������ʽ��ÿ���ϵ�� ָ����\n");
	l1=l(one);
	printf("\n�����һ������ʽ��ÿ���ϵ�� ָ����\n");
	l2=l(two);
	printf("\n��һ������ʽÿ���ϵ�� ָ����\n");
	print(l1);
	printf("\n�ڶ���������ÿ���ϵ�� ָ����\n");
	print(l2);
	printf("\n��������ʽ��Ӻ�Ľ��Ϊ��\n");
	print_(l1,l2);
	return 0;
 } 
/*
9 12
15 8
3 2
26 19
-4 8
-13 6
82 0
*/ 
