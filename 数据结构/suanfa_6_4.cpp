//л���
//2020.1.16
//��С������ ��Prim�㷨��
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//��Ȩֵ��Ϊ˫�ֽ��޷������������ֵ65535 
#define MaxVertexNum 1000
#define error -1
typedef int WeightType;
typedef char VertexDataType;//�ڽӾ��󶥵��������� 
typedef int Vertex;
typedef char DataType; //�ڽӱ����������� 

struct ENode{
	Vertex V1,V2; //�ߵ������˵� 
	WeightType data; //�ߵ�Ȩ�� 
};
typedef struct ENode* Edge;

/* �ڽӾ��� */ 
struct MGraph//�ڽӾ���ͼ�����˶�������������Ȩ�أ��������� 
{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];//���������� 
	VertexDataType data[MaxVertexNum];
};
typedef struct MGraph MGraph;

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
		Edge E=(Edge)malloc(sizeof(struct ENode));
		for(e=0;e<Graph->Ne;e++)
		{
			printf("ͼ��Ȩ���������Ȩ��ֵ��");
			scanf("%d %d %d",&E->V1,&E->V2,&E->data);
			Graph->G[E->V1][E->V2]=E->data;
			Graph->G[E->V2][E->V1]=E->data;//���������ͼ��Ҫ���������
		}
	}
	/* �������� */ 
	printf("ͼ�Ķ������ݣ�"); 
	char p; //��Ϊ���� %d �������ֱֵ�ӱ��ַ� %c ʹ�ã�����Ҫ��һ����ʱ������ת�������ɽ�ȥ 
	scanf("%c",&p);
	for(v=0;v<Graph->Nv;v++) scanf("%c",&Graph->data[v]);
	return Graph; 
} 

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

LGraph InsertGraph(LGraph Graph,Edge E) //����ߺ�Ȩֵ������������ϵ���� 
{
	PtrToAdjVNode NewNode; //�����µıߣ��ȴ����뵽ͼ�� 
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->adjv=E->V2;
	NewNode->weight=E->data;
	NewNode->next=Graph->G[E->V1].FristEdge; //���µı�Ȩֵ���뵽ͼ�У���ʽ�����뵽��ͷ 
	Graph->G[E->V1].FristEdge=NewNode;
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode)); // ����ͼ ����Ҫ�������´��� 
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
	char p; //��Ϊ���� %d �������ֱֵ�ӱ��ַ� %c ʹ�ã�����Ҫ��һ����ʱ������ת�������ɽ�ȥ 
	scanf("%c",&p);
	for(V=0;V<Graph->Nv;V++){
		scanf("%c",&Graph->G[V].data);
	}
	return Graph;
}

/* ��ȱ��� */ 
int visited[MaxVertexNum];
void Visit(LGraph Graph,Vertex V)
{
	PtrToAdjVNode w;
	printf("���ڷ��ʵĶ����� %c\n",Graph->G[V].data);
	visited[V] = true; //�����ȫ�ֱ����������ĸ����㣬�ĸ���������
	for(w=Graph->G[V].FristEdge;w;w=w->next){
		if(visited[w->adjv]==false) Visit(Graph,w->adjv);
	} 
}

/* ��С������ */
int FindMindist(MGraph* Graph,WeightType dist[])//Ѱ�����������������ĵ� 
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
	Vertex parent[MaxVertexNum], V , W ; // V ��ʾ ����ÿһ����������Ҷ��W ��ʾ ����ÿһ������ 
	int Vcount,WeightTotal;
	Edge E;
	
	for(V=0;V<Graph->Nv;V++){//��ʼ��
		dist[V]=Graph->G[0][V];
		parent[V]=0;
	} 
	Vcount=0;
	WeightTotal=0;	
	
	MST=CreatNullGraph(Graph->Nv);	//������С������
	E=(Edge)malloc(sizeof(struct ENode));
	
	dist[0]=0;//������
	MST->G[0].data=Graph->data[0];
	parent[0]=-1;
	Vcount++;
	while(1){//ÿһ��������Ҷ 
		V=FindMindist(Graph,dist);//����������СȨֵ 
		if(V==error) break;
		
		E->V1=parent[V];//�ҵ��󣬰ѱߵ���Ϣȫ����E����� 
		E->V2=V;
		E->data=dist[V];
		MST->G[V].data=Graph->data[V];
		InsertGraph(MST,E);//��E���뵽��С�������� 
		WeightTotal+=dist[V];//�������ͳ����Ϣ 
		Vcount++;
		dist[V]=0;//��Ҷ�ı�Ȩֵ��Ϊ0����Ϊ�Ѿ������� 
		for(W=0 ;W<Graph->Nv;W++){//��ÿһ������ľɱ�Ȩֵ������Ҷ��Ȩֵ�Աȣ�����dist��parent 
			if(Graph->G[V][W]<infinity && dist[W]!=0){
				if(Graph->G[V][W]<dist[W]){
					dist[W]=Graph->G[V][W];
					parent[W]=V;
				}
			}
		}
	} 
	if(Vcount!=Graph->Nv){//��Ҫ��©��������С����������� 
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
/* ������ԣ� 
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
