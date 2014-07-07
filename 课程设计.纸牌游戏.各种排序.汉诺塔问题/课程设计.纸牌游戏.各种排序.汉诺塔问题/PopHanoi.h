#pragma once
#include "CardGame.h"
#define  MaxSize 30
class PopHanoi
{
public:
	PopHanoi();
	~PopHanoi();

	CardGame extra;

	int data[MaxSize];
	char name;
	int top;
	int step = 1;

	void HanoiMenu();
	void Move(PopHanoi *&a, PopHanoi*&b);		//用于输出移动方法
	int Hanoi(int n, PopHanoi *&a, PopHanoi*&b, PopHanoi*&c);
	void initStack(PopHanoi *&s);		//初始化堆栈
	int Push(PopHanoi *&s, int e);		//入栈
	int Pop(PopHanoi *&s, int &e);		//出栈
};

