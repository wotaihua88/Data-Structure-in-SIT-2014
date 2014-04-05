#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include <malloc.h>

using namespace std;

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::StackMenu()
{
	cout << "上机实验题3.1 顺序栈基本功能演示" << endl;
	Line(55, 1);
	cout << "演示1：正在初始化栈s...";
	InitStack(s);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示2：判断栈s是否非空..." << endl;
	if (StackEmpty(s) == 1)		//对空栈检测函数的return进行检测
	{
		cout << "栈s为空" << endl;
	}
	else
	{
		cout << "栈s不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示3：依次进栈元素a，b，c，d，e...";
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	Push(s, 'e');
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示4：判断栈s是否非空..." << endl;
	if (StackEmpty(s) == true)		//对空栈检测函数的return进行检测
	{
		cout << "栈s为空" << endl;
	}
	else
	{
		cout << "栈s不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示5：输出栈长度..." << endl;
	cout << "栈的长度为：" << StackLength(s) << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示6：输出从栈顶到栈底的元素..." << endl;
	DispStack(s);
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示7：输出出栈序列..." << endl;
	while (StackEmpty(s) != true)
	{
		Pop(s, e);
		cout << e;
	}
	cout << endl << "完毕" << endl;
	Line(55, 1);
	cout << "演示8：判断栈s是否非空..." << endl;
	if (StackEmpty(s) == 1)		//对空栈检测函数的return进行检测
	{
		cout << "栈s为空" << endl;
	}
	else
	{
		cout << "栈s不为空" << endl;
	}
	cout << "完毕" << endl;
	Line(55, 1);
	cout << "演示9：释放栈...";
	ClearStack(s);
	cout << "完毕" << endl;
	Line(55, 1);
}


void Stack::InitStack(Stack *&s)
{
	s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
}

void Stack::ClearStack(Stack *&s)
{
	free(s);
}

int Stack::StackLength(Stack *s)
{
	return(s->top + 1);
}

bool Stack::StackEmpty(Stack *s)
{
	return(s->top == -1);
}

bool Stack::Push(Stack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)
	{
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Stack::Pop(Stack *&s, ElemType &e)
{
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

void Stack::DispStack(Stack *s)
{
	int i;
	for (i = s->top; i >= 0; i--)
	{
		cout << s->data[i];
	}
	cout << endl;
}

void Stack::Line(int length, int type)
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