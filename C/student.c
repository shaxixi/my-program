#include <stdio.h>
	void printf_1();
	int dengru();
	void mulu();
	void project1();
	void frist();
	void second();
	void third();
	void fourth();
	void fifth();
	void sixth();
	void seventh();
	void eighth();
main()
{
	int i,xz;
	printf_1();
	printf("             ��ӭ����ѧ���ɼ�����ϵͳ��            \n");
	for (i=0;i<3;i++)
	{
		if(dengru()==1)
		{
			if(i<2)
			{printf("����������������룡�㻹ʣ%d�λ���\n",2-i);}
			if(i==2)
			{printf("24Сʱ�����޷����룬���Ժ����ԣ�");}
		}
		else{break;}
	}
	mulu();
	xz=9;
	while(xz!=0)
	{
		scanf("%d",&xz);
		printf("\n\n");
		if(xz==1){frist();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==2){second();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==3){third();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==4){fourth();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==5){fifth();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==6){sixth();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==7){seventh();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==8){eighth();printf("������������������ѡ������������ţ�������˳������밴 0 ����\n");continue;}
		if(xz==0){break;}
		
	}
}
void printf_1()
{
	printf("***************************************************\n");
	printf("*************                       ***************\n");
	printf("*************  ��д���ڣ�2020/5/30  ***************\n");
	printf("*************  ��д�ˣ�л���       ***************\n");
	printf("*************  �汾��no.001         ***************\n");
	printf("*************                       ***************\n");
	printf("***************************************************\n");
	printf("\n\n");
}
int dengru()
{
	int a,b;
	printf("�û�����(������123456)");
	scanf("%d",&a);
	printf("���룺");
	scanf("%d",&b);
	if(b==123123){return 0;}
	else{return 1;}
}
void mulu()
{
	printf("������ȷ������ɹ���\n");
	printf("\n\n");
	printf("         1. ¼��ɼ�       2. ��ѯ�ɼ�             \n");
	printf("         3. �޸ĳɼ�       4. ɾ���ɼ�             \n");
	printf("         5. ����ɼ�       6. �ɼ�ͳ��             \n");
	printf("         7. �ɼ�����       8. ͳ�Ʒ���             \n");
	printf("\n\n");
	printf("��ѡ������������ţ�");
}
int a,sum,i,xh[50],cj[50];
void frist()
{
	int j;
	printf("¼��ɼ���������");
	scanf("%d",&a);
	printf("��¼��ѧ��ѧ�� �ɼ���ѧ��Ϊ2λ����\n");
	for(i=0;i<a;i++)
	{
		scanf("%d%d",&xh[i],&cj[i]);
		for(j=0;j<i;j++)
		{
			if(xh[i]==xh[j])
			{
				printf("��ѧ���Ѿ�¼�룬���������룡\n");
				i--;
				break;
			}
		}
	}
	printf("\n\n��¼�룺\n");
	for(i=0;i<a;i++)
	{
		printf("%dѧ���ĳɼ�Ϊ%d\n",xh[i],cj[i]);
	}
	sum=a;
	a=0;
}
void second()
{
	int cx;
	printf("���ѧ���ǣ�");
	scanf("%d",&cx);
	for(i=0;i<50;i++)
	{
		if(cx==xh[i])
		{
			printf("��ĳɼ��ǣ�%d\n",cj[i]);
			break;
		}
	}
	if(cx!=xh[i])
	{
		printf("���޴��ˣ�����¼��ɼ���\n");
	}
}
void third()
{
	int i,t,cx,xcj;
	printf("���ѧ���ǣ�");
	scanf("%d",&cx);
	for(i=0;i<50;i++)
	{
		if(cx==xh[i])
		{
			printf("��ԭ���ĳɼ��ǣ�%d\n",cj[i]);
			printf("�������޸ĺ�ĳɼ���");
			scanf("%d",&xcj);
			t=cj[i];
			cj[i]=xcj;
			xcj=t;
			printf("��¼�룬ѧ��%d�ĳɼ���%d\n",xh[i],cj[i]);
			break;
		}
	}
	if(cx!=xh[i])
	{
		printf("���޴��ˣ�����¼��ɼ���\n");
	}
}
void fourth()
{
	int sc;
	printf("���ѧ���ǣ�");
	scanf("%d",&sc);
	for(i=0;i<sum+a;i++)
	{
		if(sc==xh[i])
		{
			xh[i]=0;
			cj[i]=0;
			printf("ѧ��%d�ɼ���Ϣ��ɾ��������Ҫ¼��ɼ����������� 1 ��¼��ɼ���\n",sc);
			break;
		}	
	}
	if(i==(sum+a))
	{
		printf("���޴��ˣ�����¼��ɼ���\n");
	}
}
void fifth()
{
	int j;
	sum=sum+a;
	printf("����ɼ���������");
	scanf("%d",&a);
	printf("��¼��ѧ��ѧ�� �ɼ���\n");
	for(i=sum;i<sum+a;i++)
	{
		scanf("%d%d",&xh[i],&cj[i]);
		for(j=0;j<i;j++)
		{
			if(xh[i]==xh[j])
			{
				printf("��ѧ���Ѿ�¼�룬���������룡\n");
				i--;
				break;
			}
		}
	}
	printf("\n\n��¼�룺\n");
	for(i=sum;i<sum+a;i++)
	{
		printf("%dѧ���ĳɼ�Ϊ%d\n",xh[i],cj[i]);
	}
}
void sixth()
{
	printf("|     ѧ��    |     �ɼ�     |\n");  
	for(i=0;i<sum+a;i++)
	{
		if(xh[i]!=0)
		{
			printf("|     %2d      |     %3d      |\n",xh[i],cj[i]);
		}
	}
}
void seventh()
{
	int j,t;
	for(i=0;i<sum+a-1;i++)
	{
		for(j=i+1;j<sum+a;j++)
		{
			if(cj[i]<cj[j])
			{
				
				t=cj[i];
				cj[i]=cj[j];
				cj[j]=t;
				t=xh[i];
				xh[i]=xh[j];
				xh[j]=t;
			}
		}
	}
	printf("|     ѧ��    |     �ɼ�     |\n");  
	for(i=0;i<sum+a;i++)
	{
		if(xh[i]!=0)
		{
			printf("|     %2d      |     %3d      |\n",xh[i],cj[i]);
		}
	}
}
void eighth()
{
	int n;
	n=0;
	for(i=0;i<sum+a;i++)
	{
		if(cj[i]>=90)
		{n++;}
	}
	printf("���㣨>=90����������%d\n",n);
	printf("�����������\n");
	for(i=0;i<sum+a;i++)
	{
		if(cj[i]>=90)
		{printf("%2d    %3d    \n",xh[i],cj[i]);}
	}
	printf("\n\n");
	n=0;
	for(i=0;i<sum+a;i++)
	{
		if(cj[i]<60)
		{n++;}
	}
	printf("������<60����������%d\n",n);
	printf("�������������\n");
	for(i=0;i<sum+a;i++)
	{
		if(xh[i]!=0)
		{
			if(cj[i]<60)
			{printf("%2d    %3d    \n",xh[i],cj[i]);}
		}
	}
	printf("\n\n");
}








