// 实验5.二叉树的遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "BinaryTree.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree tree,extra;
	int item;
	system("title 实验5.二叉树的遍历");
	extra.Line(65, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{
			extra.Line(65, 1);
			cout << "1.上机实验题7.1 二叉树的各种基本运算" << endl << "0.退出程序" << endl;
			extra.Line(65, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(65, 1);
			if (item != 1 && item != 0)
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
		case 1:		//二叉树的各种基本运算
		{
			tree.TreeMenu();
		}break;
		default:
		{
			break;
		}
		}
	}
	return 0;
}

