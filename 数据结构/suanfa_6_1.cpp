//л���
//2020.1.15
//�ڽӱ�����ָ�룬����������)
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 1000
typedef int Vertex; //�������� 
typedef int WeightType; //Ȩֵ���� 
typedef char DataType; //������������ 

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
