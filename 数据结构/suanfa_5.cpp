//谢玲红
//2020/11/13
//利用链表队列；层序二叉树创建与遍历（作废） 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int

struct bintree
{
	elementtype data;
	struct bintree* left;
	struct bintree* right;
};
typedef struct bintree bintree;

struct list
{
	struct bintree* data;
	struct list* next;
};
typedef struct list list;

struct queue
{
	struct list* front;
	struct list* rear;
};
typedef struct queue queue;

bintree* creatbintree();
void level_order_traversal(bintree* bt);
void in_order_traversal(bintree* bt);
void pre_order_traversal(bintree* bt);
void post_order_traversal(bintree* bt);
queue* creatqueue();
bool insert(queue* q,bintree* x);
bintree* Delete(queue* q);

int main()
{
	bintree* bt=creatbintree();
	level_order_traversal(bt);
	printf("\n");
	in_order_traversal(bt);
	printf("\n");
	pre_order_traversal(bt);
	printf("\n");
	post_order_traversal(bt);
	printf("\n");
 } 
bintree* creatbintree()//层序方法创建树  
{
	queue* creatqueue();
	bool insert(queue* q,bintree* x);
	bintree* Delete(queue* q);
	
	bintree* t,*t1;
	elementtype x;
	queue* q=creatqueue();
	scanf("%d",&x);
	if(x!=0) 
	{
		t=(bintree*)malloc(sizeof(bintree));
		t->data=x;
		t->left=NULL;
		t->right=NULL;
		insert(q,t);
	}
	else return NULL;
	while(q->front)
	{
		t1=Delete(q);
		scanf("%d",&x);
		if(x==0) {t1->left=NULL;}
		else
		{
			t1->left=(bintree*)malloc(sizeof(bintree));
			t1->left->data=x;
			t1->left->left=NULL;
			t1->left->right=NULL;
			insert(q,t1->left);
		}
		scanf("%d",&x);
		if(x==0) {t1->right=NULL;}
		else
		{
			t1->right=(bintree*)malloc(sizeof(bintree));
			t1->right->data=x;
			t1->right->left=NULL;
			t1->right->right=NULL;
			insert(q,t1->right);
		}
	}
	return t;
}
void level_order_traversal(bintree* bt)//层序遍历输出树 
{
	queue* creatqueue();
	bool insert(queue* q,bintree* x);
	bintree* Delete(queue* q);
	
	queue* qt=creatqueue();
	bintree* t=(bintree*)malloc(sizeof(bintree));
	if(bt==NULL) 
	{
		printf("空！"); 
		return;
	}
	insert(qt,bt);
	while(qt->front)
	{
		t=Delete(qt);
		printf("%d",t->data);
		if(t->left) {insert(qt,t->left);}//！！！ 
		if(t->right) {insert(qt,t->right);} //！！！ 
	}
}
void in_order_traversal(bintree* bt)
{
	if(bt==NULL) return;
	else
	{
		in_order_traversal(bt->left);
		printf("%d",bt->data);
		in_order_traversal(bt->right);
	}

}
void pre_order_traversal(bintree* bt)
{
	if(bt==NULL) return;
	else
	{
		printf("%d",bt->data);
		pre_order_traversal(bt->left);
		pre_order_traversal(bt->right);
	}
}
void post_order_traversal(bintree* bt)
{
	if(bt==NULL) return;
	else
	{
		post_order_traversal( bt->left);
		post_order_traversal( bt->right);
		printf("%d",bt->data);
	}
}
queue* creatqueue()//创建队列，通过队列创建树 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=q->rear=NULL;
	return q;
}
bool insert(queue* q,bintree* x)//入队列 ，入队列的是地址，不是值 
{
	list* qt=(list*)malloc(sizeof(list));
	if(q->front==NULL)
	{
		qt->data=x;
		qt->next=NULL;
		q->front=qt;
		q->rear=qt;
	}
	else
	{
		qt->data=x;
		q->rear->next=qt;
		qt->data->left=qt->data->right=NULL;
		q->rear=q->rear->next;
		q->rear->next=NULL;
	}
//	printf("[%d]",q->rear->data->data);
	return true;
}
bintree* Delete(queue* q)//出队列 ，出队列的是地址，不是值 
{
	list* qt=(list*)malloc(sizeof(list));
	if(q->front!=NULL) 
	{
		if(q->front==q->rear)
		{
			qt=q->front;
			q->front=q->rear=NULL;
//			printf("{%d}",qt->data->data);
			return qt->data;
		}
		else
		{
			qt=q->front;
			q->front=q->front->next;
//			printf("{%d}",qt->data->data);
			return qt->data;
		}
	}
}

/*
1 2 3 4 5 6 7 0 0 8 0 0 9 0 0 0 0 0 0
*/
