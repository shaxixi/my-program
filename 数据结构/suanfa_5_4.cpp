//谢玲红
//2020/11/26
//哈夫曼树
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

MinHeap* creatHeap(int n)//创建权值 
{
	/* 空普通堆 */ 
	MinHeap* H=(MinHeap*)malloc(sizeof(MinHeap));
	H->data=(elementtype*)malloc(n*sizeof(elementtype));
	H->size=0;
	H->capacity=n;
//	printf("\n____调试程序_____\n");
	H->data[0]->weight=mindata;
//	printf("\n____调试程序_____\n");
	/* 普通堆入值 */ 
	int i,m;
	printf("权值个数：");
	scanf("%d",&m);
	if(m)
	{
		printf("权值序列：");
		for(i=1;i<=m;i++)//**注意用i还是用H->size 较合适 
		{
			scanf("%d",&H->data[++H->size]->weight);//**
			H->data[H->size]->left=H->data[H->size]->right=NULL;
//			printf("\n____调试程序_____\n");
		}
//		printf("\n____调试程序_____\n");
		for(i=1;i<=m;i++)
		{
			printf("%d",H->data[i]->weight);
		}
	}
	
	return H;
}

bool insertMinHeap(MinHeap* H,elementtype x)//插入最小堆 
{
	if(H->size==H->capacity) 
	{
		printf("最小堆已满");
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

bool DeleteMinHeap(MinHeap* H)//删除最小堆 
{
	if(H->size==0) 
	{
		printf("最小堆已空");
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

void precdown(MinHeap* H,int p)//局部最小堆的建立 
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

void buildMinHeap(MinHeap* H)//最小堆的建立 
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

