//谢玲红
//2020.1.16
//最小生成树 （Prim算法）
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//无权值设为双字节无符号整数的最大值65535 
#define MaxVertexNum 1000
#define error -1
typedef int WeightType;
typedef char VertexDataType;//邻接矩阵顶点数据类型 
typedef int Vertex;
typedef char DataType; //邻接表顶点数据类型 

struct ENode{
	Vertex V1,V2; //边的两个端点 
	WeightType data; //边的权重 
};
typedef struct ENode* Edge;

/* 邻接矩阵 */ 
struct MGraph//邻接矩阵图包含了顶点数，边数，权重，顶点数据 
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];//这个是有向边 
	VertexDataType data[MaxVertexNum];
};
typedef struct MGraph MGraph;

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
		Edge E=(Edge)malloc(sizeof(struct ENode));
		for(e=0;e<Graph->Ne;e++)
		{
			printf("图的权重两顶点和权重值：");
			scanf("%d %d %d",&E->V1,&E->V2,&E->data);
			Graph->G[E->V1][E->V2]=E->data;
			Graph->G[E->V2][E->V1]=E->data;//如果是无向图需要加上这语句
		}
	}
	/* 顶点数据 */ 
	printf("图的顶点数据："); 
	char p; //因为整数 %d 后输入的值直接被字符 %c 使用，所以要用一个临时变量把转换行收纳进去 
	scanf("%c",&p);
	for(v=0;v<Graph->Nv;v++) scanf("%c",&Graph->data[v]);
	return Graph; 
} 

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

/* 深度遍历 */ 
int visited[MaxVertexNum];
void Visit(LGraph Graph,Vertex V)
{
	PtrToAdjVNode w;
	printf("现在访问的顶点是 %c\n",Graph->G[V].data);
	visited[V] = true; //这个是全局变量，访问哪个顶点，哪个顶点亮灯
	for(w=Graph->G[V].FristEdge;w;w=w->next){
		if(visited[w->adjv]==false) Visit(Graph,w->adjv);
	} 
}

/* 最小生成树 */
int FindMindist(MGraph* Graph,WeightType dist[])//寻找树外点中离树最近的点 
{
	WeightType Mindist=infinity;
	Vertex MinV,V;
	for(V=0;V<Graph->Nv;V++){
		if(dist[V]!=0 && dist[V]<Mindist){
			Mindist=dist[V];
			MinV=V;
		}
	}
	if(Mindist==infinity) return error;
	else return MinV;
} 

int Prim(MGraph* Graph,LGraph MST)
{
	WeightType dist[MaxVertexNum];
	Vertex parent[MaxVertexNum], V , W ; // V 表示 树上每一个新增的树叶；W 表示 树外每一个顶点 
	int Vcount,WeightTotal;
	Edge E;
	
	for(V=0;V<Graph->Nv;V++){//初始化
		dist[V]=Graph->G[0][V];
		parent[V]=0;
	} 
	Vcount=0;
	WeightTotal=0;	
	
	MST=CreatNullGraph(Graph->Nv);	//创建最小生成树
	E=(Edge)malloc(sizeof(struct ENode));
	
	dist[0]=0;//引入树
	MST->G[0].data=Graph->data[0];
	parent[0]=-1;
	Vcount++;
	while(1){//每一个新增树叶 
		V=FindMindist(Graph,dist);//在树外找最小权值 
		if(V==error) break;
		
		E->V1=parent[V];//找到后，把边的信息全都给E代理边 
		E->V2=V;
		E->data=dist[V];
		MST->G[V].data=Graph->data[V];
		InsertGraph(MST,E);//把E插入到最小生成树中 
		WeightTotal+=dist[V];//记入相关统计信息 
		Vcount++;
		dist[V]=0;//树叶的边权值改为0，因为已经在树上 
		for(W=0 ;W<Graph->Nv;W++){//把每一个树外的旧边权值和新树叶的权值对比，更新dist和parent 
			if(Graph->G[V][W]<infinity && dist[W]!=0){
				if(Graph->G[V][W]<dist[W]){
					dist[W]=Graph->G[V][W];
					parent[W]=V;
				}
			}
		}
	} 
	if(Vcount!=Graph->Nv){//不要遗漏不存在最小生成树的情况 
			WeightTotal=error;
		}
	else{
		Visit(MST,0);
	}
	return WeightTotal;
} 


int main()
{
	MGraph* Graph;
	LGraph MST;
	WeightType EdgeTotal;
	Graph=insertGraph();
	EdgeTotal=Prim(Graph,MST);
	printf("%d\n",EdgeTotal);
}
/* 结果测试： 
10
17
0 1 8
0 2 5
1 2 5
1 4 5
1 5 4
4 5 4
2 3 8
2 6 4
3 6 7
5 6 4
5 8 2
6 8 3
3 7 5
6 7 5
6 9 6
7 9 6
8 9 7
ZBWXDLHYFC
*/
