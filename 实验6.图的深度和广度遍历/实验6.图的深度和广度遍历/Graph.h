//����ļ��ڰ����˱���ʵ����ʹ�õ��Ķ����ʾ����

#pragma once
typedef int InfoType;
#define MAXV 100		//��󶥵����
#define	INF 32767		//INF��ʾ��

//���¶����ڽӾ�������
class VertexType				//��������
{
public:
	int no;						//������
	InfoType info;				//����������Ϣ
};

class MGraph					//ͼ���ڽӾ�������
{
public:
	int edges[MAXV][MAXV];		//�ڽӾ���
	int n, e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
};

//���¶����ڽӱ�����
class ArcNode					//�ߵĽṹ����
{
public:
	int adjvex;					//�ñߵ��յ�λ��
	ArcNode *nextarc;			//ָ����һ���ߵ�ָ��
	InfoType info;				//�ñߵ������Ϣ���������ڴ��Ȩֵ
};

typedef int Vertex;	
class VNode						//�ڽӱ�ͷ�ڵ������
{
public:
	Vertex data;				//������Ϣ
	ArcNode *firstarc;			//ָ���һ����
};

typedef VNode AdjList[MAXV];	//Adjlist���ڽӱ�����
class ALGraph					//ͼ���ڽӱ�����
{
public:
	AdjList adjlist;			//�ڽӱ�
	int n, e;					//ͼ�ж�����n�ͱ���e
};

class Graph
{
public:
	Graph();
	~Graph();
	void MatToList(MGraph g, ALGraph *&G);		//������Ȩͼ���ڽӾ���gת�����ڽӱ�G
	void ListToMat(ALGraph *G, MGraph *&g);		//������Ȩͼ���ڽӱ�Gת�����ڽӾ���g
	void DispMat(MGraph g);						//�������Ȩͼ���ڽӾ���g
	void DispAdj(ALGraph *G);					//�������Ȩͼ���ڽӱ�G
	void MatToListW(MGraph g, ALGraph *&G);		//����Ȩͼ���ڽӾ���gת�����ڽӱ�G
	void ListToMatW(ALGraph *G, MGraph &g);	//����Ȩͼ���ڽӱ�Gת�����ڽӾ���g
	void DispMatW(MGraph g);					//�����Ȩͼ���ڽӾ���g
	void DispAdjW(ALGraph *G);					//�����Ȩͼ���ڽӱ�G
	void GraphMenu();
	void Line(int length, int type);
};