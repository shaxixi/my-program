//л���
//2020/11/20
//����˳�򴢴淽ʽ�Ķ��У������ͱ��� ���������  
//�����������Ĳ��ң���ֵ�������ɾ�� 
#include <stdio.h>
#include <stdlib.h>
#define elementtype int
struct bintree//�������ṹ�� 
{
	struct bintree* left;
	struct bintree* right;
	elementtype data;
};
typedef struct bintree bintree;

struct queue//˳��洢��ʽ �Ķ��нṹ�� 
{
	struct bintree** DATA;
	int front;
	int rear;
	int maxsize;
};
typedef struct queue queue;

struct stack//˳��洢��ʽ �Ķ�ջ�ṹ�� 
{
	struct bintree** DATA;
	int top;
	int maxsize;
};
typedef struct stack stack;

queue* creatqueue(int n);
bool insertqueue(queue* Q,bintree* x);
bintree* outputqueue(queue* Q);
void display(queue* Q);
stack* creatstack(int n);
bool pushstack(stack* S,bintree* x);
bintree*  popstack(stack* S);
bintree* creatbintree();
void level_order_traversal(bintree* BT);
void in_order_traversal(bintree* BT) ;
void pre_order_traversal(bintree* BT);
void post_order_traversal(bintree* BT);
void in_order_traversal_(bintree* BT);
void pre_order_printleaves(bintree* BT);
int get_height(bintree* BT);
bintree* find(bintree* BT,elementtype x);
bintree* find_(bintree* BT,elementtype x);
elementtype find_min(bintree* BT);
elementtype find_max(bintree* BT);
bintree* insertbintree(bintree* BT,elementtype x); 
bintree* Deletebintree(bintree* BT,elementtype x);

int main()
{
	int n; 
	static elementtype x;
	printf("����������1�� ��������������2����");
	scanf("%d",&n); 
	bintree* BT=creatbintree();
	/* ��ͬ�����ı��� */ 
	level_order_traversal(BT);
	printf("\n\n������������ݹ������");
	in_order_traversal(BT);
	printf("\n\n������������ݹ������"); 
	pre_order_traversal(BT);
	printf("\n\n�������ĺ���ݹ������");
	post_order_traversal(BT);
	in_order_traversal_(BT);
	printf("\n\n��������Ҷ�ڵ㣺");
	pre_order_printleaves(BT);
	printf("\n\n�������ĸ߶ȣ�%d",get_height(BT));
	/* ���������� */ 
	if(n==2)
	{
		printf("\n\n������ҵĽ���ǣ�");
		scanf("%d",&x);
		if(find(BT,x)!=NULL) printf("\n\n�ݹ���ҽ���ַ��%d",BT);
		if(find_(BT,x)!=NULL) printf("	�������ҽ���ַ��%d",BT);
		printf("\n\n��Сֵ�ǣ�%d",find_min(BT)); 
		printf("	���ֵ�ǣ�%d",find_max(BT));
		printf("\n\nҪ�����ֵ�ǣ�");
		scanf("%d",&x);
		level_order_traversal(insertbintree(BT,x));
		printf("\n\nҪɾ����ֵ�ǣ�");
		scanf("%d",&x); 
		level_order_traversal(Deletebintree(BT,x));
	}
}

queue* creatqueue(int n)//�����ն���
{
	queue* Q=(queue*)malloc(sizeof(queue));
	Q->DATA=(bintree**)malloc(n*sizeof(bintree*));//*����������䶯̬�ռ��ʱ��һ��һ��Ҫ����������� 
	Q->front=Q->rear=0;
	Q->maxsize=n;
	return Q;
}

bool insertqueue(queue* Q,bintree* x)//����� 
{
	if((Q->rear+1)%Q->maxsize==Q->front)
	{
		printf("����������");
		return false;
	}
	else 
	{
		Q->rear=(Q->rear+1)%Q->maxsize;
		Q->DATA[Q->rear]=x;
		return true;
	}
}

bintree* outputqueue(queue* Q)//������ 
{
	bintree* t;
	if(Q->rear%Q->maxsize==Q->front) 
	{
		printf("����Ϊ�գ�");
		return NULL;
	}
	else
	{
		Q->front=(Q->front+1)%Q->maxsize;
		t=Q->DATA[Q->front];
		return t;
	} 
}

void display(queue* Q)//չʾ�����ڵ�����
{
	int i=Q->front+1;
	if(Q->rear%Q->maxsize!=Q->front)
	{
		printf("����ʣ�ࣺ"); 
		while(i%Q->maxsize && i!=Q->rear || i%Q->maxsize!=Q->rear && i>Q->maxsize )
		{
			i=i%Q->maxsize;
			printf("%d ",Q->DATA[i]->data);
			i++;
		}
		printf("%d\n\n",Q->DATA[Q->rear]->data);//*�������ı���û��ֵ����ִ�в���ȥ�� 
	}
	else printf("�����ѿ�\n\n"); 
}

stack* creatstack(int n)//�����ն�ջ 
{
	stack* S=(stack*)malloc(sizeof(stack));
	S->DATA=(bintree**)malloc(n*sizeof(bintree*));
	S->top=-1;
	S->maxsize=n;
	return S;
} 

bool pushstack(stack* S,bintree* x)//�����ջ 
{
	if(S->top==S->maxsize-1)
	{
		printf("��ջ����\n");
		return false; 
	}
	else 
	{
		S->DATA[++(S->top)]=x;
		return true;
	}
} 

bintree*  popstack(stack* S)//������ջ 
{
	if(S->top==-1)
	{
		printf("��ջ�ѿ�\n");
		return NULL;
	} 
	else bintree* b=S->DATA[(S->top)--];
}

bintree* creatbintree()//������������� 
{
	bintree* BT,*T;
	queue* Q=creatqueue(20);
	elementtype x;
	printf("�������������������������������У�"); 
	scanf("%d",&x);//���ڵ� 
	if(x!=0) //�����Ϊ0�������Ϊ�� 
	{
		BT=(bintree*)malloc(sizeof(bintree));
		BT->data=x;
		BT->left=BT->right=NULL;
		insertqueue(Q,BT);//���������� 
		printf("ͷ�������У�%d\n",BT->data);
	}
	else return NULL;
	
	while(Q->rear%Q->maxsize!=Q->front)//���в�Ϊ�������ӽ��
	{
		T=outputqueue(Q);//������ʽ���������� 
		printf("�ӵ��������ϵ�����:%d\n",T->data);
		scanf("%d",&x);//����ý������ 
		if(x==0) T->left=NULL;
		else
		{
			T->left=(bintree*)malloc(sizeof(bintree));
			T->left->data=x;
			T->left->left=T->left->right=NULL;
			insertqueue(Q,T->left);
		}
		if(T->left!=NULL) printf("������������ǣ�%d\n",T->left->data);//*�������ı���û��ֵ����ͻ�ִֹͣ�У�ֱ�ӽ��� 
		else printf("�����û������\n"); 
		scanf("%d",&x);//����ý���Һ��� 
		if(x==0) T->right=NULL;
		else
		{
			T->right=(bintree*)malloc(sizeof(bintree));
			T->right->data=x;
			T->right->left=T->right->right=NULL;
			insertqueue(Q,T->right);
		} 
		if(T->right!=NULL) printf("��������Һ����ǣ�%d\n",T->right->data);//*�������ı���û��ֵ����ͻ�ִֹͣ�У�ֱ�ӽ��� 
		else printf("�����û���Һ���\n"); 
		printf("���Һ��������\n"); 
		display(Q);//�����ʱ�����ڵ����� 
	}
	printf("�ѽ��������\n"); 
	return BT;//���ظ���� 
}

void level_order_traversal(bintree* BT)//����ǵݹ������������ 
{
	
	if(!BT) 
	{
		printf("�޶�����\n");
		return;
	}
	queue* Q=creatqueue(20);
	bintree* T;
	insertqueue(Q,BT);
	printf("\n\n�������Ĳ���ǵݹ������");
	while(Q->rear%Q->maxsize!=Q->front)
	{
		T=outputqueue(Q);
		printf("%d",T->data);
		if(T->left)  insertqueue(Q,T->left);
		if(T->right) insertqueue(Q,T->right);
	}	
}

void in_order_traversal(bintree* BT) //����ݹ���� 
{ 
	if(BT)
	{
		in_order_traversal(BT->left);
		printf("%d",BT->data);
		in_order_traversal(BT->right);
	}
}

void pre_order_traversal(bintree* BT)//����ݹ���� 
{
	if(BT)
	{
		printf("%d",BT->data);
		pre_order_traversal(BT->left);
		pre_order_traversal(BT->right);
	}
} 

void post_order_traversal(bintree* BT)//����ݹ���� 
{
	if(BT)
	{
		pre_order_traversal(BT->left);
		pre_order_traversal(BT->right);
		printf("%d",BT->data);
	}
}

void in_order_traversal_(bintree* BT)//����ǵݹ����������ջ 
{
	 stack* S=creatstack(20);
	 if(BT)
	 {
	 	printf("\n\n������������ǵݹ������");
	 	bintree* T=BT; 
		while(T || S->top!=-1)
		{
			while(T)
			{
				pushstack(S,T);
				T=T->left;
			}
			T=popstack(S);
			printf("%d",T->data);
			T=T->right;
		 } 
	 }
}

void pre_order_printleaves(bintree* BT)//Ҷ�ڵ�ı��� 
{
	if(BT)
	{
		if(!BT->left && !BT->right)//if��������ǰ�к�λ�ã������һ�� 
		{
			printf("%d",BT->data);
		}
		pre_order_printleaves(BT->left);
		pre_order_printleaves(BT->right);
	}
} 

int get_height(bintree* BT)//�������ĸ߶� 
{
	int hl,hr,hmax;
	if(BT)
	{
		hl=get_height(BT->left);
		hr=get_height(BT->right);
		hmax= hl>hr ? hl : hr ;
		return hmax+1;
	}
	else return 0;
}

bintree* find(bintree* BT,elementtype x)//�����������ĵݹ���� 
{
	
	if(!BT) return NULL;
	if(x>BT->data) return find(BT->right,x);
		 else if(x<BT->data) return find(BT->left,x);
		 	  else if(x==BT->data) {return BT;}
				   else {return NULL;}
}

bintree* find_(bintree* BT,elementtype x)//�����������ĵݹ���� 
{
	if(!BT) return NULL;
	while(BT)
	{
		if(x>BT->data) BT=BT->right;
		else if(x<BT->data) BT=BT->left;
		 	 else if(x==BT->data) {return BT;}
				  else {return NULL;}
	}
}

elementtype find_min(bintree* BT)//�����������ĵ���������Сֵ 
{
	if(!BT) return NULL;
	else if(BT->left) return find_min(BT->left);
		 else return BT->data;
} 

elementtype find_max(bintree* BT)//�����������ĵ����������ֵ 
{
	if(!BT) return NULL;
	while(BT->right) BT=BT->right;
	return BT->data;
}

bintree* insertbintree(bintree* BT,elementtype x)//�����������Ĳ��� 
{
	if(!BT)
	{
		BT=(bintree*)malloc(sizeof(bintree));//** ������bintree* BT 
		BT->data=x;
		BT->left=BT->right=NULL;
	}
	else
	{
		if(x>BT->data) BT->right=insertbintree(BT->right,x);
		else if(x<BT->data) BT->left=insertbintree(BT->left,x);
	}
	return BT;
} 

bintree* Deletebintree(bintree* BT,elementtype x)//������������ɾ�� 
{
	if(!BT) printf("��������û�����ֵ");
	else
	{
		if(x>BT->data) BT->right=Deletebintree(BT->right,x);
		else if(x<BT->data) BT->left=Deletebintree(BT->left,x);
		else//BT��Ҫɾ���Ľ�� 
		{
			if(BT->left && BT->right)
			{
				elementtype y;
				y=find_min(BT->right);//Ҫɾ���Ľ���ϵ�ֵ�øý������������Сֵ���� 
				BT->data=y;
				BT->right=Deletebintree(BT->right,y);//**ɾ������Ҫɾ���Ľ���ϵ��Ǹ���� 
			}
			else
			{
				bintree* y=BT;//��զ������һ��û��Ҫ 
				if(!BT->left) BT=BT->right;//Ҫɾ���Ľ��ֻ���Һ��ӻ���û�к��� 
				else BT=BT->left;
				free(y);
			}
		}
	}
	return BT;
}
/* 1 2 3 4 5 6 7 0 0 8 0 0 9 0 0 0 0 0 0 */
/* 5 2 8 1 3 7 9 0 0 0 0 0 0 0 0 */
