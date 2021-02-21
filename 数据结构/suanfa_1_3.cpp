#include <stdio.h>
#define list_size 6
void scanf_date(int list[],int n);
int maxsubseqsum3(int list[],int n);
int divideandconquer(int list[],int left,int right);
int maxsum(int a,int b,int c);

int main()
{
	int list[list_size];
	scanf_date(list,list_size);
	printf("最大和为：%d",maxsubseqsum3(list,list_size));
}

void scanf_date(int list[],int n)
{
	int i;
	printf("输入六个整形数：");
	for(i=0;i<list_size;i++)
	{
		scanf("%d",&list[i]);
	 } 
}

int maxsubseqsum3(int list[],int n)
{
	return divideandconquer(list,0,list_size-1);
}

int divideandconquer(int list[],int left,int right)
{
	int maxleftsum,maxrightsum;
	int leftbordersum,rightbordersum;
	int maxleftbordersum,maxrightbordersum;
	int center,i;
/*	if(left==right)											//着重复习和思考 
	{
		if(list[left]>0) return list[left];
		else return 0;
	}
	center=(left+right)/2;
	maxleftsum=divideandconquer(list,left,center);
	maxrightsum=divideandconquer(list,center+1,right);
	leftbordersum=maxleftbordersum=0;
	for(i=center;i>=left;i--)
	{
		leftbordersum+=list[i];
		if(leftbordersum>maxleftbordersum)
		{
			maxleftbordersum=leftbordersum;
		}
	}*/
	rightbordersum=maxrightbordersum=0;
	for(i=center+1;i<=right;i++)
	{
		rightbordersum+=list[i];
		if(rightbordersum>maxrightbordersum)
		{
			maxrightbordersum=rightbordersum;
		}
	}
	return maxsum(maxleftbordersum,maxrightbordersum,maxleftbordersum+maxrightbordersum);
}

int maxsum(int a,int b,int c)
{
	return a>b?a>c?a:c:b>c?b:c;
}
