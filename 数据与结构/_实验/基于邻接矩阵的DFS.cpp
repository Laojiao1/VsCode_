#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100  
#define INFINITF -1 
#define	MAX 100
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define OK 1 
#define ERROR 0
typedef int Boolean;
Boolean visited[MAX];
typedef struct {
	char vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX]; 
	int numVertexes, numEdges;
	int GraphType;
}MGraph;
void CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &G->numVertexes, &G->numEdges); 
	fflush(stdin);
	for (i = 0;i < G->numVertexes;i++)
	{
		printf("第%d个顶点", i + 1);
		scanf("%c", &G->vexs[i]);
		getchar();
	}
	for (i = 0;i < G->numVertexes;i++)
		for (j = 0;j < G->numVertexes;j++)
			G->arc[i][j] = INFINITF;
	for (k = 0;k < G->numEdges;k++)
	{
		printf("输入边(vi,vj)上的上标i,下标j和权W:");
		scanf("%d %d %d", &i, &j, &w);
		G->arc[i][j] = w;
		if (G->GraphType == 0)
			G->arc[j][i] = G->arc[i][j];
	}
}
//输出邻接矩阵
void output(MGraph* G)
{
	int i, j, count = 0;
	for (i = 0;i < G->numVertexes;i++)
		printf("\t%c", G->vexs[i]);
	printf("\n");
	for (i = 0;i < G->numVertexes;i++)
	{
		printf("%4c", G->vexs[i]);
		for (j = 0;j < G->numVertexes;j++)
		{
			printf("\t%d", G->arc[i][j]);
			count++;
			if (count % G->numVertexes == 0)
				printf("\n");
		}
	}
}
//邻接矩阵的深度优先递归算法 
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", G.vexs[i]); 
	for (j = 0;j < G.numVertexes;j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G, j); 
	}
}
//邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0;i < G.numVertexes;i++)
		visited[i] = FALSE; 
	for (i = 0;i < G.numVertexes;i++)
		if (!visited[i])  
			DFS(G, i);
}
int main()
{
	MGraph G;
	int i, j;
	G.GraphType = 0;
	CreateMGraph(&G);
	printf("邻接矩阵数据如下：\n");
	output(&G);
	printf("\n");
	printf("图的深度优先遍历如下:\n");
	DFSTraverse(G);

	return 0;
}