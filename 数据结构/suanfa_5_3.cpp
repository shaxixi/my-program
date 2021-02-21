//л���
//2020/11/26
//����ͨ��ת�������� 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
#define maxdata 10000
struct Heap
{
	elementtype* data;
	int size;
	int capacity;
};
typedef struct Heap MaxHeap;

MaxHeap* creatHeap(int n)
{
	MaxHeap* H=(MaxHeap*)malloc(sizeof(MaxHeap));
	H->data=(elementtype*)malloc(sizeof(elementtype));
	H->size=0;
	H->capacity=n;
	H->data[0]=maxdata;
	
	int i,m;
	printf("���ѵĸ����ǣ�");
	scanf("%d",&m);
	if(m)
	{
		printf("��ͨ�Ѳ��������ǣ�");
		for(i=1;i<=m;i++)
		{
			scanf("%d",&H->data[++H->size]);
		}
	}
	return H;
}
void precdown(MaxHeap* H,int p)
{
	if(!H) printf("�˶�Ϊ��");
	else
	{
		int parent,child;
		elementtype x;
		x=H->data[p];
		for(parent=p;parent*2<=H->size;parent=child)
		{
			child=parent*2;
			if(child!=H->size && H->data[child]<H->data[child+1])
			{
				child++;
			}
			if(x>=H->data[child]) break;
			else H->data[parent]=H->data[child];
		}
		H->data[parent]=x;
	} 
}

void buildHeap(MaxHeap* H)
{
	int i;
	for(i=H->size/2;i>0;i--)
	{
		precdown(H,i);
	}
}

int main()
{
	MaxHeap* H=creatHeap(50);
	int i;
	buildHeap(H);
	printf("\n���ѵĲ������У�"); 
	for(i=1;i<=H->size;i++)
	{
		printf("%d ",H->data[i]);
	}
}
/* 44 25 31 18 10 */
/* 25 31 10 18 44 */
