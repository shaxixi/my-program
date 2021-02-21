//л���
//2020/11/25
//���Ѵ��������룬ɾ�� 
#include <stdio.h>
#include <stdlib.h>
#define maxsize 10000
#define elementtype int
struct Heap
{
	elementtype* data;
	int size;
	int capacity;
};
typedef struct Heap MaxHeap;

MaxHeap* creatMaxHeap(int n)//���������� 
{
	MaxHeap* H=(MaxHeap*)malloc(sizeof(MaxHeap));
	H->data=(elementtype*)malloc(sizeof(elementtype));
	H->size=0;	
	H->capacity=n;
	H->data[0]=maxsize;
	return H;
}

bool insertMaxHeap(MaxHeap* H,elementtype x)//�������� 
{
	if(H->size==H->capacity) 
	{
		printf("������");
		return false; 
	}
	else
	{
		int i;
		i=++H->size;
		for(;x>H->data[i/2];i/=2)
		{
			H->data[i]=H->data[i/2];
		}
		H->data[i]=x;
	}
	return true;	
}

bool DeleteMaxHeap(MaxHeap* H)//ɾ������㣬�������� 
{
	if(H->size==0)
	{
		printf("���ѿ�");
		return false; 
	}
	else
	{
		int parent,child;
		elementtype temp,x;
		temp=H->data[1];//�Ÿ���� 
		x=H->data[H->size--];//�洢β��� 
		for(parent=1;parent*2<=H->size;parent=child)//�����к��Ӿ�ѭ�� 
		{
			child=parent*2;
			if(child!=H->size && H->data[child]<H->data[child+1])//�ٿ������Һ��������ֵ 
			{
				child++;
			}
			if(x>=H->data[child]) break;//��������Һ��������ֵ��β��� ����֮������ֵ 
			else H->data[parent]=H->data[child];
		}
		H->data[parent]=x;
	}
	return true;
 } 
 
int main()
{	
	MaxHeap* H=creatMaxHeap(50);
	elementtype x;
	int i,j;
	printf("���ѵĸ�����");
	scanf("%d",&i); 
	printf("���Ѳ��������ǣ�");
	for(j=1;j<=i;j++)
	{
		scanf("%d",&x); 
		insertMaxHeap(H,x);
	}
	for(j=1;j<=i;j++)
	{
		printf("%d ",H->data[j]);
	}
	printf("ɾ�������е����ֵ��������ǣ�"); 
	DeleteMaxHeap(H);
	i--;
	for(j=1;j<=i;j++)
	{
		printf("%d ",H->data[j]);
	}
}
/* 44 25 31 18 10 */
