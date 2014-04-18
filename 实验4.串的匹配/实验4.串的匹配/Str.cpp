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
	Str s, s1, s2, s3, s4;
	cout << "上机实验题4.1 顺序串基本功能演示" << endl;
	Line(65, 1);
	cout << "演示1：建立串s = \"abcdefghefghijklmn\" 和串s1 = \"xyz\"";
	StrAssign(s, "abcdefghijklmn");
	StrAssign(s1, "xyz");
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示2：输出串s..." << endl;
	DispStr(s);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示3：输出串s的长度..." << endl;
	cout << "串s的长度为：" << StrLength(s) << endl << "完毕" << endl;
	Line(65, 1);
	cout << "演示4：在串s的第9个字符位置插入串s1而产生串s2...";
	s2 = InsStr(s, 9, s1);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示5：输出串s2..." << endl;
	DispStr(s2);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示6：删除串s第2个字符开始的5个字符二产生串s2...";
	s2 = DelStr(s, 2, 5);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示7：输出串s2..." << endl;
	DispStr(s2);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示8：将串s第2个字符开始的5个字符替换成串s1而产生串s2...";
	s2 = RepStr(s, 2, 5, s1);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示9：输出串s2..." << endl;
	DispStr(s2);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示10：提取串s的第2个字符开始的10个字符而产生串s3...";
	s3 = SubStr(s, 2, 10);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示11：输出串s3..." << endl;
	DispStr(s3);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示12：将串s1和串s2连接起来而产生串s4...";
	s4 = Concat(s1, s2);
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示13：输出串s4..." << endl;
	DispStr(s4);
	cout << "完毕" << endl;
}

void Str::StrAssign(Str &s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		s.data[i] = cstr[i];
	}
	s.length = i;
}

void Str::StrCopy(Str &s, Str t)
{
	int i;
	for (i = 0; i < t.length; i++)
	{
		s.data[i] = t.data[i];
	}
	s.length = t.length;
}

bool Str::StrEqual(Str s, Str t)
{
	bool same = true;
	int i;
	if (s.length != t.length)
	{
		same = false;
	}
	else
	{
		for (i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
			{
				same = false;
				break;
			}
		}
	}
	return same;
}

int Str::StrLength(Str s)
{
	return s.length;
}

Str Str::Concat(Str s, Str t)
{
	Str str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
	{
		str.data[i] = s.data[i];
	}
	for (i = 0; i < t.length; i++)
	{
		str.data[s.length + i] = t.data[i];
	}
	return str;
}

Str Str::SubStr(Str s, int i, int j)
{
	Str str;
	int k;
	str.length = 0;
	if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length)
	{
		return str;
	}
	for (k = i - 1; k < i + j - 1; k++)
	{
		str.data[k - i + 1] = s.data[k];
	}
	str.length = j;
	return str;
}

Str Str::InsStr(Str s1, int i, Str s2)
{
	int j;
	Str str;
	str.length = 0;
	if (i <=0 || i > s1.length + 1)
	{
		return str;
	}
	for (j = 0; j < i - 1; j++)
	{
		str.data[j] = s1.data[j];
	}
	for (j = 0; j < s2.length; j++)
	{
		str.data[i + j - 1] = s2.data[j];
	}
	for (j = i - 1; j < s1.length; j++)
	{
		str.data[s2.length + j] = s1.data[j];
	}
	str.length = s1.length + s2.length;
	return str;
}

Str Str::DelStr(Str s, int i, int j)
{
	int k;
	Str str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1)
	{
		return str;
	}
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}
	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[k - j] = s.data[k];
	}
	str.length = s.length - j;
	return str;
}

Str Str::RepStr(Str s, int i, int j, Str t)
{
	int k;
	Str str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
	{
		return str;
	}
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}
	for (k = 0; k < t.length; k++)
	{
		str.data[i + k - 1] = t.data[k];
	}
	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[t.length + k - j] = s.data[k];
	}
	str.length = s.length - j + t.length;
	return str;
}

void Str::DispStr(Str s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
		{
			cout << s.data[i];
		}
		cout << endl;
	}
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