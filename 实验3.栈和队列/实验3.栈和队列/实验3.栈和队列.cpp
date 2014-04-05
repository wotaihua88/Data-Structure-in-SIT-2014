// 实验3.栈和队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Stack.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Stack stack, extra;
	int item;
	system("title 实验3.栈和队列");
	extra.Line(55, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{
			extra.Line(55, 1);
			cout << "1.上机实验题3.1 顺序栈基本功能演示" << endl << "2.上机实验题3.3 顺序环形队列基本功能演示" << endl << "0.退出程序" << endl;
			extra.Line(55, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(55, 1);
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
		case 1:		//顺序栈基本功能演示
		{
			stack.StackMenu();
		}break;
		case 2:		//顺序环形队列基本功能演示
		{
			//loop.LoopListMenu();
		}break;
		case 0:		//退出程序
		{
			return 0;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}

