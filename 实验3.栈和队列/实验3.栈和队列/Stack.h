#pragma once
const int MaxSize = 100;
typedef char ElemType;

class Stack
{
public:
	Stack();
	~Stack();
	
	ElemType data[MaxSize], e;
	int top;
	Stack *s;

	void StackMenu();
	void InitStack(Stack *&s);
	void ClearStack(Stack *&s);
	int StackLength(Stack *s);
	int StackEmpty(Stack *s);
	int Push(Stack *&s, ElemType e);
	int Pop(Stack *&s, ElemType &e);
	void DispStack(Stack *s);
	void Line(int length, int type);
};

