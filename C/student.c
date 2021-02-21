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
	printf("             欢迎来到学生成绩管理系统！            \n");
	for (i=0;i<3;i++)
	{
		if(dengru()==1)
		{
			if(i<2)
			{printf("密码错误，请重新输入！你还剩%d次机会\n",2-i);}
			if(i==2)
			{printf("24小时内已无法登入，请稍后再试！");}
		}
		else{break;}
	}
	mulu();
	xz=9;
	while(xz!=0)
	{
		scanf("%d",&xz);
		printf("\n\n");
		if(xz==1){frist();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==2){second();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==3){third();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==4){fourth();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==5){fifth();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==6){sixth();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==7){seventh();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==8){eighth();printf("如果继续操作，请继续选择你想点击的序号；如果想退出程序，请按 0 键！\n");continue;}
		if(xz==0){break;}
		
	}
}
void printf_1()
{
	printf("***************************************************\n");
	printf("*************                       ***************\n");
	printf("*************  编写日期：2020/5/30  ***************\n");
	printf("*************  编写人：谢玲红       ***************\n");
	printf("*************  版本：no.001         ***************\n");
	printf("*************                       ***************\n");
	printf("***************************************************\n");
	printf("\n\n");
}
int dengru()
{
	int a,b;
	printf("用户名：(密码是123456)");
	scanf("%d",&a);
	printf("密码：");
	scanf("%d",&b);
	if(b==123123){return 0;}
	else{return 1;}
}
void mulu()
{
	printf("密码正确，登入成功！\n");
	printf("\n\n");
	printf("         1. 录入成绩       2. 查询成绩             \n");
	printf("         3. 修改成绩       4. 删除成绩             \n");
	printf("         5. 插入成绩       6. 成绩统计             \n");
	printf("         7. 成绩排序       8. 统计分析             \n");
	printf("\n\n");
	printf("请选择你想点击的序号：");
}
int a,sum,i,xh[50],cj[50];
void frist()
{
	int j;
	printf("录入成绩的人数：");
	scanf("%d",&a);
	printf("请录入学生学号 成绩（学号为2位）：\n");
	for(i=0;i<a;i++)
	{
		scanf("%d%d",&xh[i],&cj[i]);
		for(j=0;j<i;j++)
		{
			if(xh[i]==xh[j])
			{
				printf("此学号已经录入，请重新输入！\n");
				i--;
				break;
			}
		}
	}
	printf("\n\n已录入：\n");
	for(i=0;i<a;i++)
	{
		printf("%d学生的成绩为%d\n",xh[i],cj[i]);
	}
	sum=a;
	a=0;
}
void second()
{
	int cx;
	printf("你的学号是：");
	scanf("%d",&cx);
	for(i=0;i<50;i++)
	{
		if(cx==xh[i])
		{
			printf("你的成绩是：%d\n",cj[i]);
			break;
		}
	}
	if(cx!=xh[i])
	{
		printf("查无此人，请先录入成绩！\n");
	}
}
void third()
{
	int i,t,cx,xcj;
	printf("你的学号是：");
	scanf("%d",&cx);
	for(i=0;i<50;i++)
	{
		if(cx==xh[i])
		{
			printf("你原本的成绩是：%d\n",cj[i]);
			printf("请输入修改后的成绩：");
			scanf("%d",&xcj);
			t=cj[i];
			cj[i]=xcj;
			xcj=t;
			printf("已录入，学号%d的成绩是%d\n",xh[i],cj[i]);
			break;
		}
	}
	if(cx!=xh[i])
	{
		printf("查无此人，请先录入成绩！\n");
	}
}
void fourth()
{
	int sc;
	printf("你的学号是：");
	scanf("%d",&sc);
	for(i=0;i<sum+a;i++)
	{
		if(sc==xh[i])
		{
			xh[i]=0;
			cj[i]=0;
			printf("学号%d成绩信息已删除，如需要录入成绩，请重新在 1 中录入成绩！\n",sc);
			break;
		}	
	}
	if(i==(sum+a))
	{
		printf("查无此人，请先录入成绩！\n");
	}
}
void fifth()
{
	int j;
	sum=sum+a;
	printf("插入成绩的人数：");
	scanf("%d",&a);
	printf("请录入学生学号 成绩：\n");
	for(i=sum;i<sum+a;i++)
	{
		scanf("%d%d",&xh[i],&cj[i]);
		for(j=0;j<i;j++)
		{
			if(xh[i]==xh[j])
			{
				printf("此学号已经录入，请重新输入！\n");
				i--;
				break;
			}
		}
	}
	printf("\n\n已录入：\n");
	for(i=sum;i<sum+a;i++)
	{
		printf("%d学生的成绩为%d\n",xh[i],cj[i]);
	}
}
void sixth()
{
	printf("|     学号    |     成绩     |\n");  
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
	printf("|     学号    |     成绩     |\n");  
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
	printf("优秀（>=90）的人数：%d\n",n);
	printf("优秀的名单：\n");
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
	printf("不及格（<60）的人数：%d\n",n);
	printf("不及格的名单：\n");
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








