#include "stdafx.h"
#include "Convert.h"
#include "Graph.h"
#include <iostream>

using namespace std;

Convert::Convert()
{
}

Convert::~Convert()
{
}

void Convert::ConvertMenu()
{
	Graph extra;
	int i, j;
	MGraph g, g1;
	ALGraph *G;
	int A[MAXV][6] = { 
	{  0,   5, INF, 7, INF, INF },
	{ INF,  0,  4, INF,INF, INF },
	{  8,  INF, 0, INF,INF,  9  },
	{ INF, INF, 5,  0, INF,  6  },
	{ INF, INF,INF, 5,  0,  INF },
	{  3,  INF,INF,INF, 1,   0  } 
	};
	g.n = 6;
	g.e = 10;
	cout << "上机实验题8.1 邻接矩阵与邻接表的存储" << endl;
	extra.Line(70, 1);
	cout << "演示1：建立有向图G的邻接矩阵，并输出..." << endl;
	cout << "正在建立...";
	for (i = 0; i < g.n; i++){
		for (j = 0; j < g.n; j++){
			g.edges[i][j] = A[i][j];
		}
	}
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "有向图G的邻接矩阵为:" << endl;
	extra.DispMatW(g);
	extra.Line(70, 1);
	cout << "演示2：将邻接矩阵转换成邻接表，并输出..." << endl;
	cout << "正在转换...";
	extra.MatToListW(g, G);
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "有向图G的邻接表为:" << endl;
	extra.DispAdjW(G);
	extra.Line(70, 1);
	cout << "演示3：将邻接表转换成邻接矩阵，并输出..." << endl;
	cout << "正在转换...";
	extra.ListToMatW(G, g1);
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "有向图G的邻接表为:" << endl;
	extra.DispMatW(g1);
	extra.Line(70, 1);
}
