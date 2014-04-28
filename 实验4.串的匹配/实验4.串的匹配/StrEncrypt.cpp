#include "stdafx.h"
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
	char source[StrMaxSize];
	fflush(stdin);		//清空输入缓冲区，避免程序刷屏BUG
	cout << "上机实验题4.4 文本串映射加密" << endl;
	extra.Line(65, 1);
	cout << "本次加密使用的字母映射表为：" << endl;
	cout << "a b c d e f g h i j k l m n o p q r s t u v w x y z" << endl;
	cout << "n g z q t c o b m u h e l k p d a w x f y i v r s j" << endl;
	A.StrAssign(A, "abcdefghijklmnopqrstuvwxyz");
	B.StrAssign(B, "ngzqtcobmuhelkpdawxfyivrsj");
	extra.Line(65, 1);
	cout << "输入原文串：";
	cin.get(source, StrMaxSize);
	text.StrAssign(text, source);
	extra.Line(65, 1);
	cout << "原文串：";
	text.DispStr(text);
	encryptxt = EnCrypt(text);
	cout << "加密串：";
	text.DispStr(encryptxt);
	cout << "解密串：";
	unencryptxt = UnEncrypt(encryptxt);
	text.DispStr(unencryptxt);
	extra.Line(65,1);
}

Str StrEncrypt::EnCrypt(Str p)
{
	Str q;
	q.length = p.length;
	for (int i = 0; i < p.length; i++)
	{
		q.data[i] = islower(p.data[i]) ? B.data[p.data[i] - 'a'] : p.data[i];		//p串是否小写（存在映射值），存在则映射，不存在则直接赋值给q串
	}
	return q;
}

Str StrEncrypt::UnEncrypt(Str q)
{
	int i = 0, j;
	Str p;
	while (i < q.length)
	{
		for (j = 0; q.data[i] != B.data[j]; j++);
		if (j >= B.length)
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
