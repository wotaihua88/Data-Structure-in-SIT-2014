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
	cout << "上机实验题8.2 图的遍历运算" << endl;
	extra.Line(70, 1);
	cout << "演示1：输出有向图G从定点0开始的深度优先遍历序列（递归算法）..." << endl;
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