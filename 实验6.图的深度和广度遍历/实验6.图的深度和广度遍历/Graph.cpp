#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <malloc.h>
#include <iomanip>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::MatToListW(MGraph g, ALGraph *&G)
{
	int i, j;
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	for (i = 0; i < g.n; i++){
		G->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < g.n; i++){
		for (j = g.n - 1; j >= 0; j--){
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF){
				p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = g.n;
	G->e = g.e;
}

void Graph::ListToMatW(ALGraph *G, MGraph &g)
{
	int i, j;
	ArcNode *p;
	for (i = 0; i < G->n; i++){
		for (j = 0; j < G->n; j++){
			if (i == j){
				g.edges[i][j] = 0;
			}
			else{
				g.edges[i][j] = INF;
			}
		}
	}
	for (i = 0; i < G->n; i++){
		p = G->adjlist[i].firstarc;
		while (p != NULL){
			g.edges[i][p->adjvex] = p->info;
			p = p->nextarc;
		}
	}
	g.n = G->n;
	g.e = G->e;
}

void Graph::DispMatW(MGraph g)
{
	int i, j;
	for (i = 0; i < g.n; i++){
		for (j = 0; j < g.n; j++){
			if (g.edges[i][j] == INF){
				cout << setw(3) << "∞";
			}
			else{
				cout << setw(3) << g.edges[i][j];
			}
		}
		cout << endl;
	}
}

void Graph::DispAdjW(ALGraph *G)
{
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++){
		p = G->adjlist[i].firstarc;
		cout << i << ":" ;
		while (p != NULL){
			cout << setw(3) << p->adjvex << "(" << p->info << ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}

void Graph::GraphMenu()
{

	int i, j;
	MGraph g, g1;
	ALGraph *G;
	int A[MAXV][6] = {  {  0,  5, INF, 7, INF, INF },
						{ INF, 0,  4, INF,INF, INF },
						{  8, INF, 0, INF,INF,  9  },
						{ INF,INF, 5,  0, INF,  6  },
						{ INF,INF,INF, 5,  0,  INF },
						{  3, INF,INF,INF, 1,   0  } };
	g.n = 6;
	g.e = 10;
	cout << "上机实验题8.1 邻接矩阵与邻接表的存储" << endl;
	Line(70, 1);
	cout << "演示1：建立有向图G的邻接矩阵，并输出..." << endl;
	cout << "正在建立...";
	for (i = 0; i < g.n; i++){
		for (j = 0; j < g.n; j++){
			g.edges[i][j] = A[i][j];
		}
	}
	cout << "完毕" << endl;
	Line(70, 1);
	cout << "有向图G的邻接矩阵为:" << endl;
	DispMatW(g);
	Line(70, 1);
	cout << "演示2：将邻接矩阵转换成邻接表，并输出..." << endl;
	cout << "正在转换...";
	MatToListW(g, G);
	cout << "完毕" << endl;
	Line(70, 1);
	cout << "有向图G的邻接表为:" << endl;
	DispAdjW(G);
	Line(70, 1);
	cout << "演示3：将邻接表转换成邻接矩阵，并输出..." << endl;
	cout << "正在转换...";
	ListToMatW(G,g1);
	cout << "完毕" << endl;
	Line(70, 1);
	cout << "有向图G的邻接表为:" << endl;
	DispMatW(g1);
	Line(70, 1);
}

void Graph::Line(int length, int type)
{
	for (int t = 0; t < length; t++)
	{
		cout << "-";
	}
	if (type == 1)
	{
		cout << endl;
	}
}