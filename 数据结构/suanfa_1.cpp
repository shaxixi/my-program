#include <stdio.h>
#define list_size 6
int maxsubseqsum1(int list[],int n);
void scanf_date(int list[],int n);
int main()
{
	int list[list_size];
	scanf_date(list,list_size);
	printf("最大和:%d",maxsubseqsum1(list,list_size));
 }

int maxsubseqsum1(int list[],int n)
{
	int i,j,k,l;
	int thissum,maxsum=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<=n;j++)
		{
			thissum=0;
			for(k=i;k<=j;k++)
			{
				thissum+=list[k];
			}
			if(thissum>maxsum)
			{
				maxsum=thissum;
			}
		}
	}
	return maxsum;
}
void scanf_date(int list[],int n)
{
	int i;
	printf("请输入六位整型数：");
	for(i=0;i<list_size;i++)
	{
		scanf("%d",&list[i]); 	
	}

}
