//这个文件内包含了本次实验中使用到的多个表示类型

#pragma once
typedef int InfoType;
#define MAXV 100		//最大顶点个数
#define	INF 32767		//INF表示∞

//以下定义邻接矩阵类型
class VertexType				//顶点类型
{
public:
	int no;						//顶点编号
	InfoType info;				//顶点其他信息
};

class MGraph					//图的邻接矩阵类型
{
public:
	int edges[MAXV][MAXV];		//邻接矩阵
	int n, e;					//定点数，边数
	VertexType vexs[MAXV];		//存放顶点信息
};

//以下定义邻接表类型
class ArcNode					//边的结构类型
{
public:
	int adjvex;					//该边的终点位置
	ArcNode *nextarc;			//指向下一条边的指针
	InfoType info;				//该边的相关信息，这里用于存放权值
};

typedef int Vertex;	
class VNode						//邻接表头节点的类型
{
public:
	Vertex data;				//顶点信息
	ArcNode *firstarc;			//指向第一条边
};

typedef VNode AdjList[MAXV];	//Adjlist是邻接表类型
class ALGraph					//图的邻接表类型
{
public:
	AdjList adjlist;			//邻接表
	int n, e;					//图中定点数n和边数e
};

class Graph
{
public:
	Graph();
	~Graph();
	void MatToList(MGraph g, ALGraph *&G);		//将不带权图的邻接矩阵g转换成邻接表G
	void ListToMat(ALGraph *G, MGraph *&g);		//将不带权图的邻接表G转换成邻接矩阵g
	void DispMat(MGraph g);						//输出不带权图的邻接矩阵g
	void DispAdj(ALGraph *G);					//输出不带权图的邻接表G
	void MatToListW(MGraph g, ALGraph *&G);		//将带权图的邻接矩阵g转换成邻接表G
	void ListToMatW(ALGraph *G, MGraph &g);	//将带权图的邻接表G转换成邻接矩阵g
	void DispMatW(MGraph g);					//输出带权图的邻接矩阵g
	void DispAdjW(ALGraph *G);					//输出带权图的邻接表G
	void Line(int length, int type);
};