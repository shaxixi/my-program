//谢玲红
//2020.1.15
//邻接表（运用指针，类似于链表)
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 1000
typedef int Vertex; //顶点类型 
typedef int WeightType; //权值类型 
typedef char DataType; //顶点数据类型 

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
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); // 无向图 则需要加入以下代码 
	NewNode->adjv=E->V1;
	NewNode->weight=E->data;
	NewNode->next=Graph->G[E->V2].FristEdge;
	Graph->G[E->V2].FristEdge=NewNode;
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
	char p; //因为整数 %d 后输入的值直接被字符 %c 使用，所以要用一个临时变量把转换行收纳进去 
	scanf("%c",&p);
	for(V=0;V<Graph->Nv;V++){
		scanf("%c",&Graph->G[V].data);
	}
	return Graph;
}

int main()
{
	LGraph Graph;
	Graph=BuildGraph();
	for(int i=0;i<Graph->Nv;i++){
		printf("%c ",Graph->G[i].data);
	}
	printf("\n"); 
	if(Graph->Ne!=0){
		PtrToAdjVNode temp;
		for(int j=0;j<Graph->Nv;j++){
			temp=Graph->G[j].FristEdge;
			while(1){
				if(temp!=NULL){
					printf("G[%c][%c] = %d ",Graph->G[j].data,Graph->G[temp->adjv].data,temp->weight);
					temp=temp->next;
				}
				else break;
			}
			printf("\n");
		}
	}	
}
