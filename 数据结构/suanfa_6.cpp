//谢玲红
//2020/11/24
//邻接矩阵 (类似于顺序存储） 
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//无权值设为双字节无符号整数的最大值65535 
#define MaxVertexNum 1000
/*	
	Weight 边的权值
	VertexData 顶点数据
	Adjacency Matrix 邻接矩阵
	Graph=(V,E) 图=(顶点，边) 
	G 矩阵
	Vertex 顶点
*/
typedef int WeightType;
typedef int VertexDataType;
typedef int Vertex;
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

int main()
{
	MGraph* Graph;
	Graph= insertGraph();
	printf("顶点数据：");
	for(int i;i<Graph->Nv;i++){
		printf("%d ",Graph->data[i]);
	}
	printf("\n");
	if(Graph->Ne){
		int j,k;
		printf("边的权重是："); 
		for(j=0;j<Graph->Nv;j++){
			for(k=j+1;k<Graph->Nv;k++){
				if(Graph->G[j][k]!=65535){
					printf("G[%d][%d] = %d ",j,k,Graph->G[j][k]);
				}
			}
			printf("\n");
		}
	}
}
