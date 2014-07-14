#include "stdafx.h"
#include <stdlib.h>
#include "PopHanoi.h"
#include <iostream>

using namespace std;

PopHanoi::PopHanoi()
{
}

PopHanoi::~PopHanoi()
{
}

void PopHanoi::HanoiMenu()
{
	step = 1;
	int size, i;
	PopHanoi *a, *b, *c;
	cout << "3.汉诺塔问题" << endl;
	extra.Line(70, 1);
	initStack(a);		//初始化堆栈(柱)
	initStack(b);
	initStack(c);
	a->name = 'A';
	b->name = 'B';
	c->name = 'C';
	cout << "请输入汉诺塔的规模 n = ";
	cin >> size;
	extra.Line(70, 1);
	for (int t=size; t > 0; t--){
		Push(a, t);
	}
	i = Hanoi(size, a, b, c);
	extra.Line(70, 1);
	free(a);		//释放堆栈(柱)
	free(b);
	free(c);
	cout << "演示完毕" << endl;
	extra.Line(70, 1);
}

void PopHanoi::initStack(PopHanoi *&s)
{
	s = (PopHanoi *)malloc(sizeof(PopHanoi));
	s->top = -1;
}

int PopHanoi::Push(PopHanoi *&s, int e)
{
	if (s->top == MaxSize - 1){
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

int PopHanoi::Pop(PopHanoi *&s, int &e)
{
	if (s->top == -1){
		return 0;
	}
	e = s->data[s->top];
	s->top--;
	return 1;
}

int PopHanoi::Hanoi(int n, PopHanoi *&a, PopHanoi*&b, PopHanoi*&c)
{
	int i = 0;
	if(n == 1){
		Move(a, c);
		i++;
	}
	else{
		Hanoi(n - 1, a, c, b);
		Move(a, c);
		i++;
		Hanoi(n - 1, b, a, c);
	}
	return i;
}

void PopHanoi::Move(PopHanoi *&a, PopHanoi*&b)
{
	int i;
	Pop(a, i);
	cout << "步骤 " << step << " : " << i << "号盘 从 " << a->name << "柱 移动至 " << b->name << " 柱" << endl;
	Push(b, i);
	step++;
}