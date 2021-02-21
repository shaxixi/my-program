#include <stdio.h>
#define mixsize 20
struct list_guangyi
{
	int num;
	union rink
	{
		char group;
		char preson[mixsize];
	};
	struct list_guanyi *next;
};
typedef struct list_guanyi list;
typedef union rink rink;

int main()
{
	;
}

list *makelist(int n)//创建一个广义表，一个单位有n个部门 
{
	list *head,*r,*s;
	if((head=(list *)malloc(sizeof(list)))==NULL) 
	{
		printf("error!"); 
		return 0;
	}
	head->next=NULL;
	r=head;
	if((s=(list *)malloc(sizeof(list)))==NULL)
	{
		printf("error!");
		return 0;
	}
	else
	{
		for(i=0;i<n+1;i++)
		{
			scanf("%d",s->num);
			if(s->sum!=0)
			{
				for(i=0;i<4;i++)
				{
					scanf("%c",&s->rink->group->rink->preson);
				}
				
			}
			else scanf("%c",&s->rink->preson[mixsize]);
			r->next=s;
			r=s;
		}
		r->next=NULL;
		return head;
	}
}
