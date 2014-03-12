#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "Sequence.h"
#include <malloc.h>

using namespace std;

Sequence::Sequence()
{
}

Sequence::~Sequence()
{
}

void Sequence::SequenceMenu()
{
	cout << "上机实验题2.1 顺序表基本功能演示" << endl;
	//for (int i = 0;;i++)
	//{
		Line(55, 1);
		initSeqList();
		createSeqList();
		dispSeqList();
//	}
}

void Sequence::initSeqList()
{
	cout << "正在初始化顺序表L...";
	L = (Sequence *)malloc(sizeof(Sequence));
	cout << "完毕" << endl;
}

void Sequence::createSeqList()		//这里需要重写，要求是用尾插法
{
	Line(55, 1);
	length = 0;
	cout << "请为顺序表L中元素赋值，按回车键确认。" << endl;
	cout << "a = ";
	cin >> data[length];
	length = length + 1;
	cout << "b = ";
	cin >> data[length];
	length = length + 1;
	cout << "c = ";
	cin >> data[length];
	length = length + 1;
	cout << "d = ";
	cin >> data[length];
	length = length + 1;
	cout << "e = ";
	cin >> data[length];
	length = length + 1;
	cout << "元素赋值完毕。" << endl;
}

void Sequence::dispSeqList()		//输出部分在输入部分重写完成后进行更新，初步打算使用字符数组配合指针的方式指向输出a，b，c，d，e的元素头
{
	cout << "输出顺序表L内元素赋值..." << endl;
	int i = 0;
	cout << "a = " << data[i] << endl;
	i = i + 1;
	cout << "b = " << data[i] << endl;
	i = i + 1;
	cout << "c = " << data[i] << endl;
	i = i + 1;
	cout << "d = " << data[i] << endl;
	i = i + 1;
	cout << "e = " << data[i] << endl;
	i = i + 1;
	cout << "顺序表L内元素赋值输出完毕..." << endl;
	cout << "顺序表L的长度为：" << length << endl;
}

void Sequence::Line(int length, int type)
{
	for (int t = 0; t < length; t++)
	{
		cout << "-";
	}
	if (type = 1)
	{
		cout << endl;
	}
}