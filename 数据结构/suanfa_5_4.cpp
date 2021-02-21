//л���
//2020/11/26
//��������
#include <stdio.h>
#include <stdlib.h>
#define mindata -1 
struct HaffumanTree
{
	int weight;
	struct HaffumanTree* left;
	struct HaffumanTree* right;
};
typedef struct HaffumanTree HaffumanTree;
typedef struct HaffumanTree* elementtype;
struct Heap
{
	elementtype* data;
	int size;
	int capacity;
 } ;
typedef struct Heap MinHeap;

/* 7 19 2 6 32 21 10 */

MinHeap* creatHeap(int n)//����Ȩֵ 
{
	/* ����ͨ�� */ 
	MinHeap* H=(MinHeap*)malloc(sizeof(MinHeap));
	H->data=(elementtype*)malloc(n*sizeof(elementtype));
	H->size=0;
	H->capacity=n;
//	printf("\n____���Գ���_____\n");
	H->data[0]->weight=mindata;
//	printf("\n____���Գ���_____\n");
	/* ��ͨ����ֵ */ 
	int i,m;
	printf("Ȩֵ������");
	scanf("%d",&m);
	if(m)
	{
		printf("Ȩֵ���У�");
		for(i=1;i<=m;i++)//**ע����i������H->size �Ϻ��� 
		{
			scanf("%d",&H->data[++H->size]->weight);//**
			H->data[H->size]->left=H->data[H->size]->right=NULL;
//			printf("\n____���Գ���_____\n");
		}
//		printf("\n____���Գ���_____\n");
		for(i=1;i<=m;i++)
		{
			printf("%d",H->data[i]->weight);
		}
	}
	
	return H;
}

bool insertMinHeap(MinHeap* H,elementtype x)//������С�� 
{
	if(H->size==H->capacity) 
	{
		printf("��С������");
		return false;
	}
	else
	{
		int i=++H->size;
		for(;x<H->data[i/2];i/=2)//**
		{
			H->data[i]->weight=H->data[i/2]->weight;
		}
		H->data[i]=x;
		return true;
	}
}

bool DeleteMinHeap(MinHeap* H)//ɾ����С�� 
{
	if(H->size==0) 
	{
		printf("��С���ѿ�");
		return false; 
	}
	else
	{
		int parent,child;
		elementtype temp,x;
		temp=H->data[1]; 
		x=H->data[H->size--];
		for(parent=1;parent*2<=H->size;parent=child)
		{
			child=parent*2;
			if(child!=H->size && H->data[child]->weight>H->data[child+1]->weight) child++;
			if(H->data[child]->weight<=x->weight) H->data[parent]=H->data[child];
			else break;
		}
		H->data[parent]=x;
		return true;
	}	
}

void precdown(MinHeap* H,int p)//�ֲ���С�ѵĽ��� 
{
	int parent,child;
	elementtype x;
	x=H->data[p];
	for(parent=p;parent*2<=H->size;parent=child)
	{
		child=parent*2;
		if(child!=H->size && H->data[child]->weight>H->data[child+1]->weight) child++;
		if(H->data[child]->weight<=x->weight) H->data[parent]=H->data[child];
		else break;
	}
	H->data[parent]=x;
}

void buildMinHeap(MinHeap* H)//��С�ѵĽ��� 
{
	int i=H->size/2;
	for(i;i>0;i--)
	{
		precdown(H,i);
	}
}

int main()
{
	MinHeap* H=creatHeap(50);
	int i;
	for(i=1;i<=H->size;i++)
	{
		printf("%d",H->data[i]->weight);
	}
}

