//л���
//2020/11/24
//�ڽӾ��� (������˳��洢�� 
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535//��Ȩֵ��Ϊ˫�ֽ��޷������������ֵ65535 
#define MaxVertexNum 1000
/*	
	Weight �ߵ�Ȩֵ
	VertexData ��������
	Adjacency Matrix �ڽӾ���
	Graph=(V,E) ͼ=(���㣬��) 
	G ����
	Vertex ����
*/
typedef int WeightType;
typedef int VertexDataType;
typedef int Vertex;
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

int main()
{
	MGraph* Graph;
	Graph= insertGraph();
	printf("�������ݣ�");
	for(int i;i<Graph->Nv;i++){
		printf("%d ",Graph->data[i]);
	}
	printf("\n");
	if(Graph->Ne){
		int j,k;
		printf("�ߵ�Ȩ���ǣ�"); 
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
