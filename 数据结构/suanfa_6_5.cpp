//л���
//2020.1.19
//��������
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 1000
typedef int Vertex; //�������� 
typedef int WeightType; //Ȩֵ���� 
typedef int DataType; //������������ 

/* �ڽӱ� */ 
struct AdjVNode{
	Vertex adjv; //�ڱߵ��±� 
	WeightType weight; //�ڱ��붥���Ȩ��ֵ 
	struct AdjVNode* next; //�������һ���ڱ� 
};
typedef struct AdjVNode* PtrToAdjVNode;

struct Part_Graph{
	DataType data; //����ֵ 
	PtrToAdjVNode FristEdge; //����������ڱ� 
}; 
typedef struct Part_Graph Adlist[MaxVertexNum]; 

struct Graph{
	int Ne; //Ȩ���� 
	int Nv; //������
	Adlist G; //�ڽӱ� ͼ 
}; 
typedef struct Graph* LGraph;

LGraph CreatNullGraph(int VertexNum) //����ֻ���ж���Ŀ�ͼ 
{
	LGraph Graph;
	Vertex V;
	Graph=(LGraph)malloc(sizeof(struct Graph));
	Graph->Ne=0;
	Graph->Nv=VertexNum;
	for(V=0;V<Graph->Nv;V++){
		Graph->G[V].FristEdge=NULL; //�ڱߵĽṹ�岻��ָ�������飬����Ҫ��.��ʾ 
	}
	return Graph;
}

struct ENode{
	Vertex V1,V2; //�ߵ������˵� 
	WeightType data; //�ߵ�Ȩ�� 
};
typedef struct ENode* Edge;

LGraph InsertGraph(LGraph Graph,Edge E) //����ߺ�Ȩֵ������������ϵ���� 
{
	PtrToAdjVNode NewNode; //�����µıߣ��ȴ����뵽ͼ�� 
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->adjv=E->V2;
	NewNode->weight=E->data;
	NewNode->next=Graph->G[E->V1].FristEdge; //���µı�Ȩֵ���뵽ͼ�У���ʽ�����뵽��ͷ 
	Graph->G[E->V1].FristEdge=NewNode;
	return Graph; 
}

LGraph BuildGraph()
{
	int Nv,i;
	Vertex V;
	LGraph Graph;
	Edge E; 
	printf("ͼ�Ķ���������:"); 
	scanf("%d",&Nv);
	Graph=CreatNullGraph(Nv);
	printf("ͼ��Ȩ�ر������ǣ�");
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			printf("�ߵĶ�����ڵ㣬���˵�֮��ı�Ȩ��ֵ��");
			scanf("%d %d %d",&E->V1,&E->V2,&E->data);
			InsertGraph(Graph,E);
		}
	}
	printf("����ֵ�ǣ�");
	for(V=0;V<Graph->Nv;V++){
		scanf("%d",&Graph->G[V].data);
	}
	return Graph;
}

/* ���� */ 
struct queue
{
	DataType* data;
	int maxsize;
	int front;//���е�ͷ 
	int rear; //���е�β 
};
typedef struct queue queue; 
queue* createqueue(int n)//����һ���ն��� 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(DataType*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,DataType x)//����β�������� 
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

DataType Delete(queue* p)//����ͷɾ������ 
{
	if(p->front==p->rear) 
	{
		printf("�����ѿգ�");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}

/* �������� */
bool TopSort(LGraph Graph,Vertex TopOrder[])
{
	Vertex V;
	PtrToAdjVNode W;
	int Indegree[MaxVertexNum],cot=0;
	queue* Q;
	//������ȳ�ʼ��
	for(V=0;V<Graph->Nv;V++){
		Indegree[V]=0;
	} 
	//ȷ��ÿ����������ֵ
	for(V=0;V<Graph->Nv;V++){
		for(W=Graph->G[V].FristEdge;W;W=W->next){
			Indegree[W->adjv]++;
		}
	} 
	//��ʼ��������
	Q=createqueue(Graph->Nv);
	for(V=0;V<Graph->Nv;V++){
		if(Indegree[V]==0) insert(Q,V);
	} 
	while(Q->front!=Q->rear){
		V=Delete(Q);
		TopOrder[cot++]=Graph->G[V].data;
		for(W=Graph->G[V].FristEdge;W;W=W->next){
			if(--Indegree[W->adjv]==0){
				insert(Q,W->adjv);
			}
		}
	}
	if(cot!=Graph->Nv) return false;
	else return true;
}

int main()
{
	bool flag;
	LGraph Graph;
	Vertex TopOrder[MaxVertexNum];
	Graph=BuildGraph();
	flag=TopSort(Graph,TopOrder);
	if(flag){
		printf("��������Ϊ ") ;
		for(int i=0;i<Graph->Nv;i++){
			printf("%d ",TopOrder[i]);
		}
	}
	else printf("error!ͼ���л�·");
 } 
/*
8
10
0 1 0
0 2 0
1 2 0
2 7 0
2 6 0
3 4 0
4 5 0
5 6 0
4 2 0
6 7 0
1 2 3 4 5 6 7 8
*/
