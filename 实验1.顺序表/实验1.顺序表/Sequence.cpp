#include "stdafx.h"
#include <iostream>
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
	Line(55, 1);
	cout << "演示1：正在初始化顺序表L...";
	initSeqList();
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示2：采用尾插法一次插入元素a，b，c，d，e...";
	SeqListInsert(L, 1, 'a');
	SeqListInsert(L, 2, 'b');
	SeqListInsert(L, 3, 'c');
	SeqListInsert(L, 4, 'd');
	SeqListInsert(L, 5, 'e');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示3：输出顺序表L..." << endl;
	dispSeqList(L);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示4：判断顺序表L长度..." << endl;
	cout << "顺序表L的长度为：" << listLength(L) << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示5：判断顺序表L是否为空..." << endl;
	if (emptyListCheck(L) == 1)		//对空表检测函数的return进行检测
	{
		cout << "顺序表L为空" << endl;
	}   
	else
	{
		cout << "顺序表L不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示6：输出顺序表L的第3个元素..." << endl;
	cout << "顺序表L的第3个元素为：" << getElem(L, 3, e) << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示7：输出元素a的位置..." << endl;
	cout << "元素a的位置为：" << locateElem(L, 'a') << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示8：在第4个元素位置上插入元素f..." ;
	SeqListInsert(L, 4, 'f');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示9：输出顺序表L..." << endl;
	dispSeqList(L);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示10：删除L的第3个元素...";
	listDelete(L, 3, e);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示11：输出顺序表L..." << endl;
	dispSeqList(L);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示12：释放顺序表L..." ;
	freeList(L);
	cout << "完毕" << endl;
	Line(55, 1);
}

void Sequence::initSeqList()		//初始化顺序表L
{
	L = (Sequence *)malloc(sizeof(Sequence));
	L->length = 0;
}

void Sequence::freeList(Sequence *L)		//释放内存
{
	free(L);
}

int Sequence::emptyListCheck(Sequence *L)
{
	return (L->length == 0);
}

int Sequence::listLength(Sequence *L)
{
	return (L->length);
}

int Sequence::SeqListInsert(Sequence * &L, int i, char e)
{
	int j;
	if (i < 1 || i > L->length + 1)
	{
		return 0;
	}
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return 1;
}

void Sequence::dispSeqList(Sequence *L)
{
	int i;
	if (emptyListCheck(L))
	{
		return;
	}
	for (i = 0; i < L->length; i++)
	{
		cout << (char)L->data[i] << "   ";
	}
	cout << endl;
}

int Sequence::getElem(Sequence *L, int i, char &e)
{
	if (i < 1 || i > L->length)
	{
		return 0;
	}
	e = L->data[i - 1];
	return 1;
}

int Sequence::locateElem(Sequence *L, char e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
	{
		i++;
	}
	if (i > L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

int Sequence::listDelete(Sequence * &L, int i, char &e)
{
	int j;
	if (i < 1 || i > L->length)
	{
		return 0;
	}
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return 1;
}

void Sequence::Line(int length, int type)
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