//谢玲红
//2020/11/25
//最大堆创建，插入，删除 
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

MaxHeap* creatMaxHeap(int n)//创建空最大堆 
{
	MaxHeap* H=(MaxHeap*)malloc(sizeof(MaxHeap));
	H->data=(elementtype*)malloc(sizeof(elementtype));
	H->size=0;	
	H->capacity=n;
	H->data[0]=maxsize;
	return H;
}

bool insertMaxHeap(MaxHeap* H,elementtype x)//插入最大堆 
{
	if(H->size==H->capacity) 
	{
		printf("堆已满");
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

bool DeleteMaxHeap(MaxHeap* H)//删除根结点，调整最大堆 
{
	if(H->size==0)
	{
		printf("堆已空");
		return false; 
	}
	else
	{
		int parent,child;
		elementtype temp,x;
		temp=H->data[1];//放根结点 
		x=H->data[H->size--];//存储尾结点 
		for(parent=1;parent*2<=H->size;parent=child)//父亲有孩子就循环 
		{
			child=parent*2;
			if(child!=H->size && H->data[child]<H->data[child+1])//再考虑左右孩子中最大值 
			{
				child++;
			}
			if(x>=H->data[child]) break;//最后考虑左右孩子中最大值和尾结点 两者之间的最大值 
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
	printf("最大堆的个数：");
	scanf("%d",&i); 
	printf("最大堆层序序列是：");
	for(j=1;j<=i;j++)
	{
		scanf("%d",&x); 
		insertMaxHeap(H,x);
	}
	for(j=1;j<=i;j++)
	{
		printf("%d ",H->data[j]);
	}
	printf("删除最大堆中的最大值后的序列是："); 
	DeleteMaxHeap(H);
	i--;
	for(j=1;j<=i;j++)
	{
		printf("%d ",H->data[j]);
	}
}
/* 44 25 31 18 10 */
