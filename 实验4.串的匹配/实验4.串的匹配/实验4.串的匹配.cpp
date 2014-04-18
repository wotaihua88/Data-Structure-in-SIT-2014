// 实验4.串的匹配.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Str.h"
#include "StrComp.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Str str, extra;
	StrComp strcomp;
	int item;
	system("title 实验4.串的匹配");
	extra.Line(65, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{
			extra.Line(65, 1);
			cout << "1.练习题4 求公共字符串" << endl << "2.上机实验题4.1 顺序串基本功能演示" << endl << "3.上机实验题4.4 文本串映射加密" << endl << "0.退出程序" << endl;
			extra.Line(65, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(65, 1);
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
		case 1:		//求公共字符串
		{
			strcomp.StrCompMenu();
		}break;
		case 2:		//顺序串基本功能演示
		{
			str.StrMenu();
		}break;
		case 3:		//文本串映射加密
		{
			//queue.QueueMenu();
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

