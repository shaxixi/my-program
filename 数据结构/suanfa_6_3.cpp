//谢玲红
//2020.1.16
//广度遍历 深度遍历 （邻接矩阵）
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//无权值设为双字节无符号整数的最大值65535 
#define MaxVertexNum 1000
typedef int WeightType;
typedef int VertexDataType;
typedef int Vertex;

/* 邻接矩阵 */ 
struct MGraph//邻接矩阵图包含了顶点数，边数，权重，顶点数据 
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];//这个是有向边 
	VertexDataType data[MaxVertexNum];
};
typedef struct MGraph MGraph;

struct Edge//边包含了两个端点，权重数据 
{
		Vertex V1;
		Vertex V2;
		WeightType weight;
};
typedef struct Edge Edge; 

MGraph* CreatGraph(int Nv)//创建一个没有边只有顶点的空图 
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

MGraph* insertGraph()//插入权重，形成带有边的图 
{
	int Nv;
	int e,v;
	MGraph* Graph;
	/* 顶点 图 */ 
	printf("图的顶点数："); 
	scanf("%d",&Nv);
	Graph=CreatGraph(Nv);
	/* 边 权重 */ 
	printf("图的权重数："); 
	scanf("%d",&Graph->Ne);
	if(Graph->Ne)//可能出现没有边的情况 
	{
		Edge* E=(Edge*)malloc(sizeof(Edge));
		for(e=0;e<Graph->Ne;e++)
		{
			printf("图的权重两顶点和权重值：");
			scanf("%d %d %d",&E->V1,&E->V2,&E->weight);
			Graph->G[E->V1][E->V2]=E->weight;
			Graph->G[E->V2][E->V1]=E->weight;//如果是无向图需要加上这语句
		}
	}
	/* 顶点数据 */ 
	printf("图的顶点数据："); 
	for(v=0;v<Graph->Nv;v++) scanf("%d",&Graph->data[v]);
	return Graph; 
}  

/* 队列 */
struct queue
{
	Vertex* data;
	int maxsize;
	int front;//队列的头 
	int rear; //队列的尾 
};
typedef struct queue queue; 

queue* createqueue(int n)//创造一个空队列 
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->data=(Vertex*)malloc(sizeof(queue));
	q->maxsize=n;
	q->front=q->rear=0;
	return q;
}

bool insert(queue* p,Vertex x)//队列尾插入数据 
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

Vertex Delete(queue* p)//队列头删除数据 
{
	if(p->front==p->rear) 
	{
		printf("队列已空！");
		return false; 
	}
	p->front=(p->front+1)%p->maxsize;
	return p->data[p->front];
}
 
/* 广度遍历 */
int visited[MaxVertexNum];
void visit(MGraph* Graph,Vertex V)
{
	queue* Q;
	Vertex w,s;
	Q=createqueue(MaxVertexNum); //创建一个队列，先点灯，再标记，最后入队列 
	printf("现在访问的是:%d\n",Graph->data[V]);
	visited[V]=true;
	insert(Q,V);
	while(Q->front!=Q->rear){
		s=Delete(Q); // 先出队列，然后环顾一周，扫描得到的数据判断点灯否，再标记，后入队列 
		for(w=0;w<Graph->Nv;w++){
			if(!visited[w] && Graph->G[s][w] != infinity){
				printf("现在访问的是：%d\n",Graph->data[w]);
				visited[w]=true;
				insert(Q,w);
			}
			
		}
	}
}
// 结果测试： 8 9 0 1 0 1 2 0 2 3 0 3 0 0 0 4 0 4 5 0 5 6 0 6 7 0 7 4 0 1 2 3 4 5 6 7 8 4
int main()
{
	int V;
	MGraph* Graph;
	Graph=insertGraph();
	printf("遍历起点下标：");
	scanf("%d",&V);
	visit(Graph,V); 
}
