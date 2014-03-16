// 实验1.顺序表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "DeleteXY.h"
#include "Sequence.h"

using namespace std;

void Line(int length, int type);

int _tmain(int argc, _TCHAR* argv[])
{
	DeleteXY xy;
	Sequence seq;
	int item;
	system("title 实验1.顺序表");
	Line(55, 1);
	for (int main = 0;; main++)
	{
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++)		//输入检测
		{		
			Line(55, 1);
			cout << "1.练习题2.2 删除给定值之间的所有元素功能演示" << endl << "2.上机实验题2.1 顺序表基本功能演示" << endl << "0.退出程序" << endl;
			Line(55, 1);
			cout << "请选择: ";
			cin >> item;
			Line(55, 1);
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
		case 1:		//删除给定值之间的所有元素功能演示
		{	
			xy.DeleteXYMenu();
		}break;
		case 2:		//顺序表基本功能演示
		{	
			seq.SequenceMenu();
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

//函数实现
void Line(int length, int type)
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