﻿#include "stdafx.h"
#include "StrEncrypt.h"
#include <iostream>

using namespace std;

StrEncrypt::StrEncrypt()
{
}

StrEncrypt::~StrEncrypt()
{
}

void StrEncrypt::EncryptMenu()
{
	char str[StrMaxSize];
	cout << "上机实验题4.4 文本串映射加密" << endl;
	extra.Line(65, 1);
	cout << "本次加密使用的字母映射表为：" << endl;
	cout << "a b c d e f g h i j k l m n o p q r s t u v w x y z" << endl;
	cout << "n g z q t c o b m u h e l k p d a w x f y i v r s j" << endl;
	ec.StrAssign(A, "abcdefghijklmnopqrstuvwxyz");
	ec.StrAssign(B, "ngzqtcobmuhelkpdawxfyivrsj");
	extra.Line(65, 1);
	cout << "输入原文串：";
	fflush(stdin);		//清空输入缓冲区，避免程序刷屏BUG
	cin.get(str, StrMaxSize);
	ec.StrAssign(p, str);
	extra.Line(65, 1);
	cout << "原文串：";
	ec.DispStr(p);
	q = EnCrypt(p);
	cout << "加密串：";
	ec.DispStr(q);
	cout << "解密串：";
	p = UnEncrypt(q);
	ec.DispStr(p);
	extra.Line(65,1);
}

Str StrEncrypt::EnCrypt(Str p)
{
	int i = 0, j;
	Str q;
	while (i < p.length)
	{
		for (j = 0; p.data[i] != A.data[j]; j++);
		if (j >= p.length)
		{
			q.data[i] = p.data[i];
		}
		else
		{
			q.data[i] = B.data[j];
		}
		i++;
	}
	q.length = p.length;
	return q;
}

Str StrEncrypt::UnEncrypt(Str q)
{
	int i = 0, j;
	Str p;
	while (i < q.length)
	{
		for (j = 0; q.data[i] != B.data[j]; j++);
		if (j >= q.length)
		{
			p.data[i] = q.data[i];
		}
		else
		{
			p.data[i] = A.data[j];
		}
		i++;
	}
	p.length = q.length;
	return p;
}
