#pragma once
#include "Graph.h"
class Traversal
{
public:
	Traversal();
	~Traversal();
	
	Graph extra;

	int visited[MAXV];

	void DFS(ALGraph *G, int v);
	void BFS(ALGraph *G, int v);
	void TravelMenu();
};

