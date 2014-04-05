#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include <malloc.h>

using namespace  std;

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::QueueMenu()
{
	cout << "上机实验题3.2 顺序环形队列基本功能演示" << endl;
	extra.Line(55, 1);
	cout << "演示1：正在初始化队列q...";
	InitQueue(q);
	cout << "完毕" << endl;
	extra.Line(55, 1);
	cout << "演示2：判断队列q是否非空..." << endl;
	if (QueueEmpty(q) == true)		//对空链队检测函数的return进行检测
	{
		cout << "队列q为空" << endl;
	}
	else
	{
		cout << "队列q不为空" << endl;
	}
	cout << "完毕" << endl;
	extra.Line(55, 1);
	cout << "演示3：依次进队元素a，b，c...";
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	cout << "完毕" << endl;
	extra.Line(55, 1);
	cout << "演示4：出队一个元素，并输出该元素...";
	deQueue(q, e);
	cout << e;
	cout << endl << "完毕" << endl;
	extra.Line(55, 1);
 	cout << "演示5：输出队列q的元素个数..." << endl;
 	cout << "队列q的元素个数为为：" << QueueLength(q) << endl << "完毕" << endl;
 	extra.Line(55, 1);
	cout << "演示6：依次进队元素d，e，f..." << endl;
	//此处有队满事件，做个判断
	if (enQueue(q, 'd') == false)
	{
		cout << "队列满，进队失败" << endl;
	}
	else
	{
		cout << "d已成功进队" << endl;
	}
	if (enQueue(q, 'e') == false)
	{
		cout << "队列满，进队失败" << endl;
	}
	else
	{
		cout << "e已成功进队" << endl;
	}
	if (enQueue(q, 'f') == false)		// 环形队列最多只能存放QMaxSize - 1个元素，f无法入队。
	{
		cout << "队列满，f进队失败" << endl;
	}
 	cout << "完毕" << endl;
 	extra.Line(55, 1);
	cout << "演示7：输出队列q的元素个数..." << endl;
	cout << "队列q的元素个数为为：" << QueueLength(q) << endl << "完毕" << endl;
	extra.Line(55, 1);
	cout << "演示8：输出出队序列..." << endl;
	while (QueueEmpty(q) != true)
	{
		deQueue(q, e);
		cout << e;
	}
	cout << endl << "完毕" << endl;
	extra.Line(55, 1);
	cout << "演示9：释放队列...";
	ClearQueue(q);
	cout << "完毕" << endl;
	extra.Line(55, 1);
}

void Queue::InitQueue(Queue *&q)
{
	q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = 0;
}

void Queue::ClearQueue(Queue *&q)
{
	free(q);
}

bool Queue::QueueEmpty(Queue *q)
{
	return(q->front == q->rear);
}

int Queue::QueueLength(Queue *q)
{
	return (q->rear - q->front + QMaxSize) % QMaxSize;
}

bool Queue::enQueue(Queue *&q, ElemType e)
{
	if ((q->rear + 1) % QMaxSize == q->front)
	{
		return false;
	}
	q->rear = (q->rear + 1) % QMaxSize;
	q->elem[q->rear] = e;
	return true;
}

bool Queue::deQueue(Queue *&q, ElemType &e)
{
	if (q->front == q->rear)
	{
		return false;
	}
	q->front = (q->front + 1) % QMaxSize;
	e = q->elem[q->front];
	return true;
}
