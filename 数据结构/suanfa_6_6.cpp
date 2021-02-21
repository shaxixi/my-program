//л���
//2020.1.20
//���·�� (Dijkstra)
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//��Ȩֵ��Ϊ˫�ֽ��޷������������ֵ65535 
#define MaxVertexNum 1000
#define error -1
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

/* ���·�� */
Vertex FindMinDist(MGraph* Graph,WeightType dist[],bool collect[])  //��dist·���е���Сֵ 
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
{//ÿ���㵽ԭ���·��dist ��С·�̵�ļ�¼collect  ���·���еĵ����ӵ���һ����path ��ʼ��S 
	bool collect[Graph->Nv];
	Vertex V,W;
	//��ʼ��
	for(V=0;V<Graph->Nv;V++){
		dist[V]=Graph->G[S][V];
		if(dist[V]!=infinity) path[V]=S; //�����Ҫȷ����һ��·�����ϸ��㣬���������ʼֵȷ��Ϊһ��� 
		else path[V]=-1;
		collect[V]=false;
	} 
	//��ʼֵȷ��
	dist[S]=0;
	collect[S]=true;
	//��ʼDijkstra
	while(1){
		V=FindMinDist(Graph,dist,collect);//��һ��ԭ��·������ĵ� 
		if(V==error) break;
		collect[V]=true;
		for(W=0;W<Graph->Nv;W++){//����·��֮��ĵ��ԭ��ľ��� 
			if(Graph->G[V][W]<infinity && collect[W]==false){
				if(Graph->G[V][W]+dist[V]<dist[W]){
					dist[W]=Graph->G[V][W]+dist[V];
					path[W]=V;
				}
				if(Graph->G[V][W]<0) return false; //�����ж� ����㷨�������и�Ȩֵ���������Ȼ����ѭ�� 
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
	printf("��ʼ���±�Ϊ��"); 
	scanf("%d",&S);
	Dijkstra(Graph,dist,path,S);
	printf("�յ��±�Ϊ: ");
	scanf("%d",&F);
	printf("·��Ϊ��%d \n ��·��Ϊ��",dist[F]);
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
