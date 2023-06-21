#include<stdio.h>
#include<stdlib.h>
#define MAXVERTICES 100 //数组大小
int visited[MAXVERTICES]; //访问标志数组
typedef int	QElemType; //队列数据类型
typedef int ElemType;//顶点数据类型

//边表
typedef struct NODE
{
	int adjvex;//顶点下标
	int weight;//权值，只有网（加权图）有
	struct NODE *next;//指向下一个结点
}EdgeNode;
//顶点表
typedef struct
{
	ElemType vertex;//顶点的值
	EdgeNode *edgenext;//边表
}VertexNode;

typedef VertexNode AdjList[MAXVERTICES];
//图
typedef struct
{
	AdjList adjlist;
	int Vn;//顶点个数
	int Ve;//边的个数
}AdjTable;
//创建邻接表
void creatTable(AdjTable *G)
{
	int n, e, vi, vj, w;
	EdgeNode *s;
	printf("请输入图的顶点和边的个数（用空格隔开）：");
	scanf("%d%d", &n, &e);
	G->Vn = n;
	G->Ve = e;
	//建立顶点表
	printf("\n建立顶点表\n");
	for (int i = 0; i < G->Vn; i++)
	{
		printf("请输入第%d个顶点的信息：", i + 1);
		scanf("%d", &G->adjlist[i].vertex);
		G->adjlist[i].edgenext = NULL;
	}
	//建立边表-前插法
	printf("\n建立边表\n");
	for (int j = 0; j < G->Ve; j++)
	{
		printf("输入有链接的顶点下标和权值（用空格隔开）：\n");//无权图权值为1
		scanf("%d%d%d", &vi, &vj, &w);
		vi -= 1;
		vj -= 1;
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = vj;
		s->weight = w;
		s->next = G->adjlist[vi].edgenext;
		G->adjlist[vi].edgenext = s;
		//无向图需要对称，上下两者都要写
		//有向图分为邻接表和逆邻接表，邻接表确定顶点的出度，逆邻接表确定顶点的入度
		//上面是有向图邻接表（出度），下面是逆邻接表（入度），要分开实现
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = vi;
		s->weight = w;
		s->next = G->adjlist[vj].edgenext;
		G->adjlist[vj].edgenext = s;		
	}
}
//显示连接表
void ShowAdjTable(AdjTable *G)
{
	printf("显示顶点信息：\n");
	for (int i = 0; i < G->Vn; i++)
	{
		printf("%d ", G->adjlist[i].vertex);
	}
	printf("\n显示边的信息：\n");
	for (int i = 0; i < G->Vn; i++)
	{
		EdgeNode *q = G->adjlist[i].edgenext;
		printf("%d  -> ", i + 1);
		while (1)
		{
			if (q == NULL)
			{
				printf("^");
				break;
			}
			printf("  (w = %d)  %d", q->weight, q->adjvex + 1);
			q = q->next;
		}
		printf("\n");
	}
}

//邻接表的深度优先搜索
void DFS(AdjTable *G, int i)
{
	EdgeNode *p;
	visited[i] = 1;
	printf("%d ", G->adjlist[i].vertex);
	p = G->adjlist[i].edgenext;//让p指向边表的第一个结点
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G, p->adjvex);
		}
		p = p->next;
	}

}
void DFSTraverse(AdjTable *G)
{
	for (int i = 0; i < G->Vn; i++)
	{
		visited[i] = 0;//初始化标记数组为0
	}
	for (int i = 0; i < G->Vn; i++)
	{
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}

int main()
{
	AdjTable G;
	creatTable(&G);
	ShowAdjTable(&G);

	printf("\n深度优先遍历：\n");
	DFSTraverse(&G);

	system("pause");
	return 0;
}
