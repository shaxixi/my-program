//л���
//2020.1.16
//��ȱ��� ��ȱ��� ���ڽӾ���
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//��Ȩֵ��Ϊ˫�ֽ��޷������������ֵ65535 
#define MaxVertexNum 1000
typedef int WeightType;
typedef int VertexDataType;
typedef int Vertex;

/* �ڽӾ��� */ 
struct MGraph//�ڽӾ���ͼ�����˶�������������Ȩ�أ��������� 
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];//���������� 
	VertexDataType data[MaxVertexNum];
};
typedef struct MGraph MGraph;

struct Edge//�߰����������˵㣬Ȩ������ 
{
		Vertex V1;
		Vertex V2;
		WeightType weight;
};
typedef struct Edge Edge; 

MGraph* CreatGraph(int Nv)//����һ��û�б�ֻ�ж���Ŀ�ͼ 
{
	MGraph* Graph=(MGraph*)malloc(sizeof(MGraph));
	int v1,v2;
	Graph->Nv=Nv;
	Graph->Ne=0;
	for(v1=0;v1<Nv;v1++)
	{
		for(v2=0;v2<Nv;v2++)
		{
			Graph->G[v1][v2]=infinity;
		}
	}
	return Graph;
}

MGraph* insertGraph()//����Ȩ�أ��γɴ��бߵ�ͼ 
{
	int Nv;
	int e,v;
	MGraph* Graph;
	/* ���� ͼ */ 
	printf("ͼ�Ķ�������"); 
	scanf("%d",&Nv);
	Graph=CreatGraph(Nv);
	/* �� Ȩ�� */ 
	printf("ͼ��Ȩ������"); 
	scanf("%d",&Graph->Ne);
	if(Graph->Ne)//���ܳ���û�бߵ���� 
	{
		Edge* E=(Edge*)malloc(sizeof(Edge));
		for(e=0;e<Graph->Ne;e++)
		{
			printf("ͼ��Ȩ���������Ȩ��ֵ��");
			scanf("%d %d %d",&E->V1,&E->V2,&E->weight);
			Graph->G[E->V1][E->V2]=E->weight;
			Graph->G[E->V2][E->V1]=E->weight;//���������ͼ��Ҫ���������
		}
	}
	/* �������� */ 
	printf("ͼ�Ķ������ݣ�"); 
	for(v=0;v<Graph->Nv;v++) scanf("%d",&Graph->data[v]);
	return Graph; 
}  

/* ���� */
struct queue
{
	Vertex* data;
	int maxsize;
	int front;//���е�ͷ 
	int rear; //���е�β 
};
typedef struct queue queue; 

queue* createqueue(int n)//����һ���ն��� 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(Vertex*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,Vertex x)//����β�������� 
{
	if((p->rear+1)%p->maxsize==p->front)
	{
		printf("����������");
		return false; 
	}
	p->rear=(p->rear+1)%p->maxsize;//����38�е���˳���ԭ���ǣ�p->front==p->rearʱΪ�գ����ܴ������ 
	p->data[p->rear]=x;
	return true;
}

Vertex Delete(queue* p)//����ͷɾ������ 
{
	if(p->front==p->rear) 
	{
		printf("�����ѿգ�");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}
 
/* ��ȱ��� */
int visited[MaxVertexNum];
void visit(MGraph* Graph,Vertex V)
{
	queue* Q;
	Vertex w,s;
	Q=createqueue(MaxVertexNum); //����һ�����У��ȵ�ƣ��ٱ�ǣ��������� 
	printf("���ڷ��ʵ���:%d\n",Graph->data[V]);
	visited[V]=true;
	insert(Q,V);
	while(Q->front!=Q->rear){
		s=Delete(Q); // �ȳ����У�Ȼ�󻷹�һ�ܣ�ɨ��õ��������жϵ�Ʒ��ٱ�ǣ�������� 
		for(w=0;w<Graph->Nv;w++){
			if(!visited[w] && Graph->G[s][w] != infinity){
				printf("���ڷ��ʵ��ǣ�%d\n",Graph->data[w]);
				visited[w]=true;
				insert(Q,w);
			}
			
		}
	}
}
// ������ԣ� 8 9 0 1 0 1 2 0 2 3 0 3 0 0 0 4 0 4 5 0 5 6 0 6 7 0 7 4 0 1 2 3 4 5 6 7 8 4
int main()
{
	int V;
	MGraph* Graph;
	Graph=insertGraph();
	printf("��������±꣺");
	scanf("%d",&V);
	visit(Graph,V); 
}
