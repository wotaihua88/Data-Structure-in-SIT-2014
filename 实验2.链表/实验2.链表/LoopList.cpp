#include "stdafx.h"
#include <iostream>
#include "LoopList.h"
#include <malloc.h>

using namespace std;

LoopList::LoopList()
{
}

LoopList::~LoopList()
{
}

void LoopList::LoopListMenu()
{
	cout << "上机实验题2.4 循环单链表基本功能演示" << endl;
	Line(55, 1);
	cout << "演示1：正在初始化循环单链表h...";
	InitList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示2：采用尾插法一次插入元素a，b，c，d，e...";
	ListInsert(h, 1, 'a');
	ListInsert(h, 2, 'b');
	ListInsert(h, 3, 'c');
	ListInsert(h, 4, 'd');
	ListInsert(h, 5, 'e');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示3：输出循环单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示4：输出循环单链表h长度..." << endl;
	cout << "循环单链表h的长度为：" << ListLength(h) << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示5：判断循环单链表h是否为空..." << endl;
	if (ListEmpty(h) == 1)
	{
		cout << "循环单链表h为空" << endl;
	}
	else
	{
		cout << "循环单链表h不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示6：输出循环单链表h的第3个元素..." << endl;
	GetElem(h, 3, e);
	cout << "循环单链表h的第3个元素为：" << e << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示7：输出元素a的位置..." << endl;
	cout << "元素a的位置为：" << LocateElem(h, 'a') << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示8：在第4个元素位置上插入元素f...";
	ListInsert(h, 4, 'f');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示9：输出循环单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示10：删除h的第3个元素...";
	ListDelete(h, 3, e);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示11：输出循环单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示12：释放循环单链表h...";
	DestoryList(h);
	cout << "完毕" << endl;
	Line(55, 1);
}

void LoopList::InitList(LoopList * &L)
{
	L = (LoopList *)malloc(sizeof(LoopList));
	L->next = L;
}

void LoopList::DestoryList(LoopList * &L)
{
	LoopList *p= L, *q = p->next;
	while (q != L)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

int LoopList::ListEmpty(LoopList *L)
{
	return(L->next == L);
}

int LoopList::ListLength(LoopList *L)
{
	LoopList *p = L;
	int i = 0;
	while (p->next != L)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void LoopList::DispList(LoopList *L)
{
	LoopList *p = L->next;
	while (p != L)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

int LoopList::GetElem(LoopList *L, int i, char &e)
{
	int j = 0;
	LoopList *p;
	if (L->next != L)
	{
		if (i == 1)
		{
			e = L->next->data;
			return 1;
		}
		else
		{
			p = L->next;
			while (j < i - 1 && p != L)
			{
				j++;
				p = p->next;
			}
			if (p == L)
			{
				return 0;
			}
			else
			{
				e = p->data;
				return 1;
			}
		}
	}
	else
	{
		return 0;
	}
}

int LoopList::LocateElem(LoopList *L, char e)
{
	LoopList *p = L->next;
	int n = 1;
	while (p != L&&p->data != e)
	{
		p = p->next;
		n++;
	}
	if (p == L)
	{
		return (0);
	}
	else
	{
		return (n);
	}
}

int LoopList::ListInsert(LoopList *&L, int i, char e)
{
	int j = 0;
	LoopList *p = L, *s;
	if (p->next == L || i == 1)
	{
		s = (LoopList *)malloc(sizeof(LoopList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return 1;
	}
	else
	{
		p = L->next;
		while (j < i - 2 && p != L)
		{
			j++;
			p = p->next;
		}
		if (p == L)
		{
			return 0;
		}
		else
		{
			s = (LoopList *)malloc(sizeof(LoopList));
			s->data = e;
			s->next = p->next;
			p->next = s;
			return 1;
		}
	}
}

int LoopList::ListDelete(LoopList * &L, int i, char &e)
{
	int j = 0;
	LoopList *p = L, *q;
	if (p->next != L)
	{
		if (i == 1)
		{
			q = L->next;
			e = q->data;
			L->next = q->next;
			free(q);
			return 1;
		}
		else
		{
			p = L->next;
			while (j < i - 2 && p != L)
			{
				j++;
				p = p->next;
			}
			if (p == L)
			{
				return 0;
			}
			else
			{
				q = p->next;
				e = q->data;
				p->next = q->next;
				free(q);
				return 1;
			}
		}
	}
	else
	{
		return 0;
	}
}

void LoopList::Line(int length, int type)
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