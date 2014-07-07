#include "stdafx.h"
#include "Select.h"
#include <iostream>

using namespace std;

Select::Select()
{
}

Select::~Select()
{
}

void Select::SelectMenu()
{
	int i, k, n = 10, m = 5;
	Select R[MaxSize];
	KeyType a[] = { 6, 8, 7, 9, 0, 1, 3, 2, 4, 5 };
	for (i = 0; i < n; i++){
		R[i].key = a[i];
	}
	cout << "上机实验题10.5 直接选择排序算法的应用" << endl;
	extra.Line(70, 1);
	cout << "排序前：";
	for (k = 0; k < n; k++){
		cout << " " << R[k].key;
	}
	cout << endl;
	extra.Line(70, 1);
	cout << "排序过程：" << endl;
	SelectSort(R, n);
	extra.Line(70, 1);
	cout << "排序后：";
	for (k = 0; k < n; k++){
		cout << " " << R[k].key;
	}
	cout << endl;
	extra.Line(70, 1);
}

void Select::SelectSort(Select R[], int n)
{
	int i, j, k, l;
	Select temp;
	for (i = 0; i < n - 1; i++){
		k = i;
		for (j = i + 1; j < n; j++){
			if (R[j].key < R[k].key){
				k = j;
			}
		}
		if (k != i){
			temp = R[i];
			R[i] = R[k];
			R[k] = temp;
		}
		cout << "i = " << i << " : ";
		for (l = 0; l < n; l++){
			cout << " " << R[l].key;
		}
		cout << endl;
	}
}