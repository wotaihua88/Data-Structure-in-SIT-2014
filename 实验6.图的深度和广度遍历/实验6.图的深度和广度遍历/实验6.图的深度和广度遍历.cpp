// 实验6.图的深度和广度遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Graph.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Graph extra, graph;
	int item;
	system("title 实验6.图的深度和广度遍历");
	extra.Line(70, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{
			extra.Line(70, 1);
			cout << "1.上机实验题8.1 邻接矩阵与邻接表的存储" << endl <<  "2.上机实验题8.2 图的遍历运算" << "0.退出程序" << endl;
			extra.Line(70, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(70, 1);
			if (item != 1 && item != 2 && item != 0)
			{
				cout << "输入错误，请重新输入！" << endl;
			}
			else
			{
				break;
			}
		}
		switch (item)
		{
		case 1:		//邻接矩阵与邻接表的存储
		{
			graph.GraphMenu();
		}break;
		case 2:		//图的遍历运算
		{

		}break;
		case 0:		//退出程序
		{
			return 0;
		}break;
		default:
		{
			break;
		}
		}
	}
	return 0;
}

