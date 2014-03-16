#include "stdafx.h"
#include <iostream>
#include "DeleteXY.h"

using namespace std;

DeleteXY::DeleteXY()
{
}

DeleteXY::~DeleteXY()
{
}

void DeleteXY::DeleteXYMenu()
{
	int x, y;
	cout << "练习题2.2 删除给定值之间的所有元素功能演示" << endl;
	Line(55, 1);
	initArray();
	cout << "请输入需要删除的元素下限值X与上限值Y：" << endl;
	for (int i = 0;; i++)		//上下限检测
	{
		cout << "下限值X = ";
		cin >> x;
		cout << "上限值Y = ";
		cin >> y;
		Line(55, 1);
		if (x > y)
		{
			cout << "下限值不能大于上限值，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	deleteXY(x, y);
}

void DeleteXY::initArray()
{
	int seed;
	cout << "为生成演示用元素，请输入任意整数用作随机数生成种子：";
	cin >> seed;
	srand(seed);
	cout << "正在随机生成演示用元素...";
	for (int i = 0; i < 10; i++)
	{
		data[i] = rand()%9;		//随机数生成，进行取余处理，使生成的数值不与特殊值重复
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示用元素为：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << "   ";
	}
	cout << endl;
	Line(55, 1);
}

void DeleteXY::deleteXY(int x, int y)
{
	int count = 0;
	cout << "正在删除元素中大于等于" << x << "小于等于" << y << "的数据...";
	for (int i = 0; i < 10; i++)
	{
		if (data[i] >= x && data[i] <= y)
		{
			data[i] = 999;	//考虑到时间复杂度，不易使用递归，采用标记特殊值的方法
		}
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "新的演示用元素为：" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (data[i] != 999)		//检测特殊值，若是则不输出
		{
			cout << data[i] << "   ";
		}
		else
		{
			count = count + 1;
		}
	}
	if (count == 10)
	{
		cout <<"空" ;		//若所有元素被删除则显示空表
	}
	cout << endl;
	Line(55, 1);
}

void DeleteXY::Line(int length, int type)
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