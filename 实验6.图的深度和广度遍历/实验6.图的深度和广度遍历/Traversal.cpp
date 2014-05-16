#include "stdafx.h"
#include "Traversal.h"
#include <iostream>
#include <iomanip>

using namespace std;

Traversal::Traversal()
{
}

Traversal::~Traversal()
{
}

void Traversal::TravelMenu()
{
	int i, j;
	MGraph g;
	ALGraph *G;
	int A[MAXV][6] = {
	{  0,  5, INF, 7, INF, INF },
	{ INF, 0,  4, INF,INF, INF },
	{  8, INF, 0, INF,INF,  9  },
	{ INF,INF, 5,  0, INF,  6  },
	{ INF,INF,INF, 5,  0,  INF },
	{  3, INF,INF,INF, 1,   0  }
	};
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++){
		for (j = 0; j < g.n; j++){
			g.edges[i][j] = A[i][j];
		}
	}
	for (i = 0; i < MAXV; i++){		//初始化visited数组
		visited[i] = 0;
	}
	G = (ALGraph *)malloc(sizeof(ALGraph));
	extra.MatToListW(g, G);
	cout << "上机实验题8.2 图的遍历运算" << endl;
	extra.Line(70, 1);
	cout << "演示1：输出有向图G从定点0开始的深度优先遍历序列（递归算法）..." << endl;
	cout << "深度优先序列为：";
	DFS(G, 0);
	cout << endl << "完毕" << endl;
	extra.Line(70, 1);
	cout << "演示2：输出有向图G从定点0开始的广度度优先遍历序列..." << endl;
	cout << "广度优先序列为：";
	BFS(G, 0);
	cout << "完毕" << endl;
	extra.Line(70, 1);
}

void Traversal::DFS(ALGraph *G, int v)
{
	ArcNode *p;
	visited[v] = 1;
	cout << setw(3) << v;
	p = G->adjlist[v].firstarc;
	while (p != NULL){
		if (visited[p->adjvex] == 0){
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

void Traversal::BFS(ALGraph *G, int v)
{
	ArcNode *p;
	int queue[MAXV], front = 0, rear = 0;
	int visited[MAXV];
	int w, i;
	for (i = 0; i < G->n; i++){
		visited[i] = 0;
	}
	cout << setw(3) << v;
	visited[v] = 1;
	rear = (rear + 1) % MAXV;
	queue[rear] = v;
	while (front != rear){
		front = (front + 1) % MAXV;
		w = queue[front];
		p = G->adjlist[w].firstarc;
		while (p != NULL){
			if (visited[p->adjvex] == 0){
				cout << setw(3) << p->adjvex;
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}