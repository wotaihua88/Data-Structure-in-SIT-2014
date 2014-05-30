// 实验7.查找.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "BinSearch.h"
#include "BSTree.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	BinSearch extra, bin;
	BSTree bst;
	int item;
	system("title 实验7.查找");
	extra.Line(70, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{
			extra.Line(70, 1);
			cout << "1.上机实验题9.2 顺序表折半查找应用" << endl << "2.上机实验题9.4 二叉排序树的基本运算" << endl << "3.上机实验题 9.8 哈希表的相关运算" << endl << "0.退出程序" << endl;
			extra.Line(70, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(70, 1);
			if (item != 1 && item != 2 && item != 3 && item != 0)
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
		case 1:		//顺序表折半查找应用
		{
			bin.BinMenu();
		}break;
		case 2:		//二叉排序树的基本运算
		{
			bst.BSTreeMenu();
		}break;
		case 3:		//哈希表的相关运算
		{
			//
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