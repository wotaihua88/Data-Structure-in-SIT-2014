#pragma once
#include "Stack.h"
const int QMaxSize = 5;
typedef char ElemType;

class Queue
{
public:
	Queue();
	~Queue();

	Stack extra;

	ElemType elem[QMaxSize], e;
	int front, rear;
	Queue *q;

	void QueueMenu();
	void InitQueue(Queue *&q);
	void ClearQueue(Queue *&q);
	bool QueueEmpty(Queue *q);
	int QueueLength(Queue *q);
	bool enQueue(Queue *&q, ElemType e);
	bool deQueue(Queue *&q, ElemType &e);
};

