#include "stdafx.h"
#include <iostream>
#include "SingleList.h"
#include <malloc.h>

using namespace std;

SingleList::SingleList()
{
}

SingleList::~SingleList()
{
}

void SingleList::SingleListMenu()
{
	cout << "上机实验题2.2 单链表基本功能演示" << endl;
	Line(55, 1);
	cout << "演示1：正在初始化单链表h...";
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
	cout << "演示3：输出单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示4：输出单链表h长度..." << endl;
	cout << "单链表h的长度为：" << ListLength(h) << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示5：判断单链表h是否为空..." << endl;
	if (ListEmpty(h) == 1)
	{
		cout << "单链表h为空" << endl;
	}
	else
	{
		cout << "单链表h不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示6：输出单链表h的第3个元素..." << endl;
	GetElem(h, 3, e);
	cout << "单链表h的第3个元素为：" << e << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示7：输出元素a的位置..." << endl;
	cout << "元素a的位置为：" << LocateElem(h, 'a') << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示8：在第4个元素位置上插入元素f...";
	ListInsert(h, 4, 'f');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示9：输出单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示10：删除h的第3个元素...";
	ListDelete(h, 3, e);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示11：输出单链表h..." << endl;
	DispList(h);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示12：释放单链表h...";
	DestoryList(h);
	cout << "完毕" << endl;
	Line(55, 1);
}

void SingleList::InitList(SingleList * &L)
{
	L = (SingleList *)malloc(sizeof(SingleList));
	L->next = NULL;
}

void SingleList::DestoryList(SingleList * &L)
{
	SingleList *p = L, *q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

int SingleList::ListEmpty(SingleList *L)
{
	return(L->next == NULL);
}

int SingleList::ListLength(SingleList *L)
{
	SingleList *p = L;
	int i = 0;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return (i);
}

void SingleList::DispList(SingleList *L)
{
	SingleList *p = L->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

int SingleList::GetElem(SingleList *L, int i, char &e)
{
	int j = 0;
	SingleList *p = L;
	while (j < i&&p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		e = p->data;
		return 1;
	}
}

int SingleList::LocateElem(SingleList *L, char e)
{
	SingleList *p = L->next;
	int n = 1;
	while (p != NULL&&p->data != e)
	{
		p = p->next;
		n++;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return (n);
	}
}
 
int SingleList::ListInsert(SingleList * &L, int i, char e)
{
	int j = 0;
	SingleList *p = L, *s;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		s = (SingleList *)malloc(sizeof(SingleList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

int SingleList::ListDelete(SingleList * &L, int i, char &e)
{
	int j = 0;
	SingleList *p = L, *q;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		q = p->next;
		if (q == NULL)
		{
			return 0;
		}
		e = q->data;
		p->next = q->next;
		free(q);
		return 1;
	}
}

void SingleList::Line(int length, int type)
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