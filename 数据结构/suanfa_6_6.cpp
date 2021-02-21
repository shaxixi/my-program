//谢玲红
//2020.1.20
//最短路径 (Dijkstra)
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//无权值设为双字节无符号整数的最大值65535 
#define MaxVertexNum 1000
#define error -1
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

/* 最短路径 */
Vertex FindMinDist(MGraph* Graph,WeightType dist[],bool collect[])  //找dist路程中的最小值 
{ 
	Vertex MinV,V;
	WeightType Mindist=infinity;
	for(V=0;V<Graph->Nv;V++){
		if(dist[V]<Mindist && collect[V]==false){
			Mindist=dist[V];
			MinV=V;
		}
	}
	if(Mindist==infinity) return error;
	else return MinV;
}

bool Dijkstra(MGraph* Graph,WeightType dist[],Vertex path[],Vertex S)
{//每个点到原点的路程dist 最小路程点的记录collect  最短路径中的点连接的上一个点path 起始点S 
	bool collect[Graph->Nv];
	Vertex V,W;
	//初始化
	for(V=0;V<Graph->Nv;V++){
		dist[V]=Graph->G[S][V];
		if(dist[V]!=infinity) path[V]=S; //这里就要确定第一个路径的上个点，和下面的起始值确定为一块的 
		else path[V]=-1;
		collect[V]=false;
	} 
	//起始值确定
	dist[S]=0;
	collect[S]=true;
	//开始Dijkstra
	while(1){
		V=FindMinDist(Graph,dist,collect);//找一离原点路径最近的点 
		if(V==error) break;
		collect[V]=true;
		for(W=0;W<Graph->Nv;W++){//更新路径之外的点和原点的距离 
			if(Graph->G[V][W]<infinity && collect[W]==false){
				if(Graph->G[V][W]+dist[V]<dist[W]){
					dist[W]=Graph->G[V][W]+dist[V];
					path[W]=V;
				}
				if(Graph->G[V][W]<0) return false; //特殊判断 这个算法不可以有负权值的情况，不然会死循环 
			}
		}
	} 
	return true;
 } 
 
int main()
{
	WeightType dist[MaxVertexNum];
	Vertex path[MaxVertexNum],S,F;
	MGraph* Graph;
	Graph=insertGraph();
	printf("起始点下标为："); 
	scanf("%d",&S);
	Dijkstra(Graph,dist,path,S);
	printf("终点下标为: ");
	scanf("%d",&F);
	printf("路程为：%d \n 反路线为：",dist[F]);
	while(F!=-1){
		printf("%d ",Graph->data[F]);
		F=path[F];
	}
}
/*
10
17
0 1 2
0 3 5
1 3 2
1 2 5
2 4 8
2 5 4
3 5 4
3 6 2
4 5 2
5 6 3
4 7 5
5 7 9
5 8 6
6 8 7
7 8 3
7 9 4
8 9 8
0 1 2 3 4 5 6 7 8 9
0
9
*/
