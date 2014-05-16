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