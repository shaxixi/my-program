#include <stdio.h>
#define list_size 6

void scanf_date(int list[],int n);
int maxsubseqsum4(int list[],int n);

int main()
{
	int list[list_size];
	scanf_date(list,list_size);
	printf("����Ϊ��%d",maxsubseqsum4(list,list_size));
 } 
 
void scanf_date(int list[],int n)
 {
	int i;
	printf("��������λ�����ͣ�");
	for(i=0;i<n;i++)
	{
		scanf("%d",&list[i]);
	 } 
 }
int maxsubseqsum4(int list[],int n)
 {
	int i;
	int thissum=0,maxsum=0;
	for(i=0;i<=n;i++)
	{
		thissum+=list[i];
		if(thissum>maxsum) maxsum=thissum;
		else if(thissum<0) thissum=0;
	}
	return maxsum;
 }
