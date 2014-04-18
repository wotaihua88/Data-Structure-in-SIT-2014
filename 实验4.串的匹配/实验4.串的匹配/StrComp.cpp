#include "stdafx.h"
#include "StrComp.h"
#include <iostream>

using namespace std;

StrComp::StrComp()
{
}

StrComp::~StrComp()
{
}

void StrComp::StrCompMenu()
{
	Str sc1, sc2, scc;
	char csc1[StrMaxSize], csc2[StrMaxSize];
	cout << "练习题4 求公共字符串" << endl;
	extra.Line(65, 1);
	cout << "请分别输入用于比对的字符串s1、s2：" << endl;
	cout << "s1 = ";
	cin >> csc1;
	comp.StrAssign(sc1, csc1);
	cout << "s2 = ";
	cin >> csc2;
	comp.StrAssign(sc2, csc2);
	extra.Line(65, 1);
	scc = CompChar(sc1, sc2);
	comp.DispStr(scc);
	extra.Line(65, 1);
}

Str StrComp::CompChar(Str s1, Str s2)
{
	Str s3;
	int i, j, k = 0;
	for (i = 0; i < s1.length; i++)
	{
		for (j = 0; j < s2.length; j++)
		{
			if (s2.data[j] == s1.data[i])
			{
				break;
			}
		}
		if (j < s2.length)
		{
			s3.data[k] = s1.data[i];
			k++;
		}
	}
	s3.length = k;
	return s3;
}