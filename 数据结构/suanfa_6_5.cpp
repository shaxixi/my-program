//谢玲红
//2020.1.19
//拓扑排序
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 1000
typedef int Vertex; //顶点类型 
typedef int WeightType; //权值类型 
typedef int DataType; //顶点数据类型 

/* 邻接表 */ 
struct AdjVNode{
	Vertex adjv; //邻边的下标 
	WeightType weight; //邻边与顶点的权重值 
	struct AdjVNode* next; //顶点的下一个邻边 
};
typedef struct AdjVNode* PtrToAdjVNode;

struct Part_Graph{
	DataType data; //顶点值 
	PtrToAdjVNode FristEdge; //顶点的所有邻边 
}; 
typedef struct Part_Graph Adlist[MaxVertexNum]; 

struct Graph{
	int Ne; //权重数 
	int Nv; //顶点数
	Adlist G; //邻接表 图 
}; 
typedef struct Graph* LGraph;

LGraph CreatNullGraph(int VertexNum) //创建只含有顶点的空图 
{
	LGraph Graph;
	Vertex V;
	Graph=(LGraph)malloc(sizeof(struct Graph));
	Graph->Ne=0;
	Graph->Nv=VertexNum;
	for(V=0;V<Graph->Nv;V++){
		Graph->G[V].FristEdge=NULL; //邻边的结构体不是指针是数组，所以要用.表示 
	}
	return Graph;
}

struct ENode{
	Vertex V1,V2; //边的两个端点 
	WeightType data; //边的权重 
};
typedef struct ENode* Edge;

LGraph InsertGraph(LGraph Graph,Edge E) //插入边和权值，各个顶点联系起来 
{
	PtrToAdjVNode NewNode; //建立新的边，等待插入到图中 
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->adjv=E->V2;
	NewNode->weight=E->data;
	NewNode->next=Graph->G[E->V1].FristEdge; //将新的边权值插入到图中，方式：插入到表头 
	Graph->G[E->V1].FristEdge=NewNode;
	return Graph; 
}

LGraph BuildGraph()
{
	int Nv,i;
	Vertex V;
	LGraph Graph;
	Edge E; 
	printf("图的顶点数量是:"); 
	scanf("%d",&Nv);
	Graph=CreatNullGraph(Nv);
	printf("图的权重边数量是：");
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			printf("边的顶点和邻点，两端点之间的边权重值：");
			scanf("%d %d %d",&E->V1,&E->V2,&E->data);
			InsertGraph(Graph,E);
		}
	}
	printf("顶点值是：");
	for(V=0;V<Graph->Nv;V++){
		scanf("%d",&Graph->G[V].data);
	}
	return Graph;
}

/* 队列 */ 
struct queue
{
	DataType* data;
	int maxsize;
	int front;//队列的头 
	int rear; //队列的尾 
};
typedef struct queue queue; 
queue* createqueue(int n)//创造一个空队列 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(DataType*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,DataType x)//队列尾插入数据 
{
	if((p->rear+1)%p->maxsize==p->front)
	{
		printf("队列已满！");
		return false; 
	}
	p->rear=(p->rear+1)%p->maxsize;//不和38行调换顺序的原因是：p->front==p->rear时为空，不能存放数据 
	p->data[p->rear]=x;
	return true;
}

DataType Delete(queue* p)//队列头删除数据 
{
	if(p->front==p->rear) 
	{
		printf("队列已空！");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}

/* 拓扑排序 */
bool TopSort(LGraph Graph,Vertex TopOrder[])
{
	Vertex V;
	PtrToAdjVNode W;
	int Indegree[MaxVertexNum],cot=0;
	queue* Q;
	//顶点入度初始化
	for(V=0;V<Graph->Nv;V++){
		Indegree[V]=0;
	} 
	//确认每个顶点的入度值
	for(V=0;V<Graph->Nv;V++){
		for(W=Graph->G[V].FristEdge;W;W=W->next){
			Indegree[W->adjv]++;
		}
	} 
	//开始拓扑排序
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
		printf("拓扑排序为 ") ;
		for(int i=0;i<Graph->Nv;i++){
			printf("%d ",TopOrder[i]);
		}
	}
	else printf("error!图中有回路");
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
