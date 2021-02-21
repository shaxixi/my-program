#include <stdio.h>
#include <stdlib.h> 
#define elementype int
#define mixsize 100
struct list
{
	elementype xi[mixsize];
	elementype zhi[mixsize];
	int last;
};
typedef struct list list;

list *creat_list(int n)//����˳��ṹ������		//ָ�뺯�� 
{
	int i;
	list *p;
	p=(list *)malloc(sizeof(list));
	p->last=n;
	for(i=0;i<p->last;i++)	scanf("%d %d",&p->xi[i],&p->zhi[i]);
	return p;
}

list *print(list *p)
{
	int i;
	for(i=0;i<p->last;i++) printf("%-8d %-8d\n",p->xi[i],p->zhi[i]);
}

list sum_list(list *p1,list *p2)//����ʽ��Ӳ������ 
{
	int i=0,j=0;
	while(i!=p1->last||j!=p2->last)
	{
		if((i!=(p1->last))&&(j!=(p2->last)))
		{
			if((p1->zhi[i])>(p2->zhi[j]))
			{
				printf("%dx^%d + ",p1->xi[i],p1->zhi[i]);
				i++;
				continue;
			}
			if((p1->zhi[i])<(p2->zhi[j]))
			{
				printf("%dx^%d + ",p2->xi[j],p2->zhi[j]);
				j++;
				continue;
			}
			if((p1->zhi[i])==(p2->zhi[j]))
			{
				printf("%dx^%d + ",p1->xi[i]+p2->xi[j],p1->zhi[i]);
				i+=1;
				j+=1;
				continue;
			}	
		}
		if(i==p1->last)
		{
			if(j+1==p2->last)
			{
				printf("%dx^%d	",p2->xi[j],p2->zhi[j]);
				j++;
			}
			else
			{
				printf("%dx^%d + ",p2->xi[j],p2->zhi[j]);
				j++;
			}
			
			continue;
		}
		if(j==p2->last)
		{
			if(i+1==p1->last)
			{
				printf("%dx^%d	",p1->xi[i],p1->zhi[i]);
				i++;	
			}
			else
			{
				printf("%dx^%d + ",p1->xi[i],p1->zhi[i]);
				i++;
			}
			continue;
		}
	}
}
int main()
{
	list *creat_list(int n);
	list sum_list(list *p1,list *p2);
	list *print(list *p);
	
	list *p1,*p2;
	printf("\n�����һ������ʽ��ÿ���ϵ�� ָ����\n");
	p1=creat_list(3);
	printf("\n�����һ������ʽ��ÿ���ϵ�� ָ����\n");
	p2=creat_list(4);
	printf("\n��һ������ʽÿ���ϵ�� ָ����\n");
	print(p1);
	printf("\n�ڶ���������ÿ���ϵ�� ָ����\n");
	print(p2);
	printf("\n��������ʽ��Ӻ�Ľ��Ϊ��\n");
	sum_list(p1,p2);
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
