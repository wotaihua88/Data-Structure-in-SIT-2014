#include "stdafx.h"
#include "Str.h"
#include <iostream>

using namespace std;

Str::Str()
{
}

Str::~Str()
{
}

void Str::StrMenu()
{
	cout << "上机实验题4.1 顺序串基本功能演示" << endl;
	Line(55, 1);
}

void Str::Line(int length, int type)
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