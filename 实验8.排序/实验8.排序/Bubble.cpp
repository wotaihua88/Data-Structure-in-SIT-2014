#include "stdafx.h"
#include "Bubble.h"
#include <iostream>

using namespace std;

Bubble::Bubble()
{
}

Bubble::~Bubble()
{
}

void Bubble::BubbleMenu()
{
	int i, n = 10;
	Bubble R[MaxSize];
	KeyType a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	for (i = 0; i < n; i++){
		R[i].key = a[i];
	}
	cout << "上机实验题10.3 冒泡排序算法应用" << endl;
	Line(70, 1);
	cout << "排序前：";
	for (i = 0; i < n; i++){
		cout << " " << R[i].key;
	}
	cout << endl;
	Line(70, 1);
	cout << "排序过程：" << endl;
	BubbleSort(R, n);
	Line(70, 1);
	cout << "排序后：";
	for (i = 0; i < n; i++){
		cout << " " << R[i].key;
	}
	cout << endl;
	Line(70, 1);
}

void Bubble::BubbleSort(Bubble R[], int n)
{
	int i, j, k, exchange;
	Bubble tmp;
	for (i = 0; i < n - 1; i++){
		exchange = 0;
		for (j = n - 1; j > i; j--){
			if (R[j].key < R[j - 1].key){
				tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
				exchange = 1;
			}
		}
		cout << "i = " << i << " : ";
		for (k = 0; k < n; k++){
			cout << " " << R[k].key;
		}
		cout << endl;
		if (exchange == 0){
			return;
		}
	}
}

void Bubble::Line(int length, int type)
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