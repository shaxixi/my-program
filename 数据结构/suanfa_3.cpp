//л���
//2020.10.20 
//���Ա�˳���
#include <stdio.h>
#include <stdlib.h>
#define ElementType int
#define mixsize 100
struct list_shunxu
{
	ElementType data[mixsize];
	int size;
};
typedef list_shunxu list;

int main()
{
	list *Makelist(int n);
	bool Insert(list *p,int i,ElementType n);
	bool Delete(list *p,int i);
	ElementType Find(list * p,ElementType n);
	void print(list *p);
	
	list *p=NULL;
	printf("\n���봴�������Ա��5��������\n"); 
	p=Makelist(5);
	printf("\n���Ա��5������Ϊ��\n");
	print(p);
	printf("\n�����Ա��еڶ������ݲ�������5��\n"); 
	Insert(p,2,5);
	print(p);
	printf("\n�����Ա���ɾ�����������ݣ�\n");
	Delete(p,3);
	print(p);
	printf("\n�����Ա�������3���ڵ�λ���ǣ�\n");
	printf("%d",Find(p,3));
	return 0;
 } 
 
list *Makelist(int n)//����һ���� 
{
	list *p; 
	int i;
	p=(list *)malloc(sizeof(list));
	p->size=n;	
	for(i=0;i<p->size;i++) scanf("%d",&p->data[i]);
	return p;
}

bool Insert(list *p,int i,ElementType n)//�������� ����p���еĵ�i�����ݲ�������n
{
	int j;
	if(i<1||i>p->size+1)//error:if(i<1||i>p->size)
	{
		printf("insert number was error!");
		return false;//�ò����ͷ��ؽ�� 
	}
	if(p->size==mixsize)//error:if(p->size>mixsize)
	{
		printf("list length was error!");
		return false;
	}
	for(j=p->size;j>=i;j--)	p->data[j]=p->data[j-1];
	p->data[i-1]=n;
	p->size++;//error:������ 
	return false;//�ò����ͷ��ؽ�� 
} 

bool Delete(list *p,int i)//ɾ�����ݣ�ɾ����p���е�i������ 
{
	int j;
	if(i<1||i>p->size) 
	{
		printf("detele number was error!");
		return false;
	}
	for(j=i-1;j<p->size;j++) p->data[j]=p->data[j+1];
	p->size--;
	return true;
}

ElementType Find(list * p,ElementType n)//�������ݣ�����p���е�����n
{
	int j;
	for(j=1;j<=p->size;j++)	if(p->data[j-1]==n) return j;
	return NULL;
}

void print(list *p)
{
	int i;
	for(i=0;i<p->size;i++) printf("%d ",p->data[i]);
	printf("\n");
}
