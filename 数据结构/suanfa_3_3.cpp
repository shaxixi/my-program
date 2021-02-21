//л���
//2020.10.22
//���Ա�ѭ������ 
#include <stdio.h>
#include <stdlib.h>
#define ElementType int 
struct list_lianbiao
{
	ElementType data;
	struct list_lianbiao* next;
};
typedef struct list_lianbiao list;

int main()
{
	list* Creatlist(int n);
	int Lenth(list* p);
	bool Insert(list* p, int i, ElementType n); 
	bool Detele(list *p,int i);
	int Find_number(list* p, ElementType n);
	ElementType Find_data(list *p,int i);
	void print(list *p);
	
	list *p;
	printf("\n����Ҫ������ѭ�����Ա��5�����ݣ�\n");
	p=Creatlist(5);
	printf("\nѭ�����Ա��5������ѭ��һ���ǣ�\n");
	print(p);
	printf("\nѭ�����Ա�ĳ���Ϊ��\n");
	printf("%d \n",Lenth(p));
	printf("\n��ѭ�����Ա��е�һ��λ�ò�������5��ǰʮ�������ǣ�\n");
	Insert(p,1,5);
	print(p);
	printf("\n��ѭ�����Ա���ɾ����3������\n");
	Detele(p,3);
	print(p);
	printf("\n��ѭ�����Ա�������4��λ�ã�\n");
	printf("%d \n",Find_number(p,4));
	printf("\n��ѭ�����Ա��е�2��λ���ϵ������ǣ�\n");
	printf("%d \n",Find_data(p,2));

}

list* Creatlist(int n)//�����±���n�����
{
	int i; 
	list* head, * r, * s, * tail;
	if ((head = (list*)malloc(sizeof(list))) == NULL) printf("error!");	
	head->next=NULL;		//ͷָ���ÿ�   ***	
	r=head;				

	for (i=0;i<n;i++)
	{
		if ((s = (list*)malloc(sizeof(list))) == NULL) printf("error!");
		scanf("%d", &s->data);
		r->next=s; 
		r=s;
	} 
	r->next=head->next;		//ʵ��ͷβѭ�� *** 
	return head;
}

int Lenth(list* p)//���
{
	int count=1;
	list* pt;
	pt = p->next->next;
	while (pt != p->next)
	{
		count++;
		pt = pt->next;
	}
	return count;
}

bool Insert(list* p, int i, ElementType n)//�������ݣ���p��Ķ�λi�ϲ�������n
{
	list* pt, * s;
	int j = 0;
	pt = p;
	while ( j < i - 1 )//��λ��i-1�Ľ�� ��ʱiû�и�����Χ
	{
		pt = pt->next;
		j++;
	}
//	if(pt==NULL)
//	if(j!=i-1)
	if (j != i - 1)//����Ϊpt==NULL��j!=i-1�ǵȼ۵ġ����ʡ�
	{
		printf("error!");
		return false;
	}
	else
	{
		s = (list*)malloc(sizeof(list));
		s->data = n;
		s->next = pt->next;
		pt->next = s;
		return true;
	}
}

bool Detele(list *p,int i)//ɾ�����ݣ�ɾ������n
{
	list* pre,*s;
	int j=0;
	pre = p;
	while (pre != NULL && j < i - 1)
	{
		pre = pre->next;
		j++;
	}
	if (pre == NULL || j != i - 1 || pre->next == NULL)//�ж������������е���
	{
		printf("error!");
		return false;
	}
	else
	{
		s = pre->next;
		pre->next = s->next;
		free(s);
		return true;
	}
 } 

int Find_number(list* p, ElementType n)//����p���е�����n����λ�� 
{
	int count=0;
	list* pt;
	pt = p;
	while (pt != NULL && pt->data != n) 
	{
		pt = pt->next;
		count++;
	}
	if (pt != NULL) return count;
	else return NULL;
}

ElementType Find_data(list *p,int i)//����p���еĵ�i��λ�õ�����
{
	int j=0;
	list *pt;
	pt=p;
	while(pt!=NULL&&j<i) 
	{
		pt=pt->next;
		j++;
	}
	if(pt!=NULL) return pt->data;
	else return NULL;
 } 

void print(list *p)
{
	int i;
	list *pt;
	pt=p->next;
	for(i=0;i<10;i++)
	{
		printf("%d ",pt->data);
		pt=pt->next;
	}
	printf("\n");
}
