#include "stdafx.h"
#include "BinSearch.h"
#include <iostream>

using namespace std;

BinSearch::BinSearch()
{
}

BinSearch::~BinSearch()
{
}

void BinSearch::BinMenu()
{
	SeqList R;
	KeyType k = 9;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, i, n = 10;
	for (i = 0; i < n; i++){
		R[i].key = a[i];		//给顺序表赋初值
	}
	cout << "上机实验题9.2 顺序表折半查找应用" << endl;
	Line(70, 1);
	cout << "顺序表序列：";
	for (i = 0; i < n; i++){		//输出顺序表
		cout << " "<<R[i].key;
	}
	cout << endl;
	Line(70, 1);
	cout << "折半查找元素 " << k << " 的比较过程如下：" << endl;
	Line(70, 1);
	if ((i = BinSearcher(R, n, k)) != -1){
		Line(70, 1);
		cout << "元素 " << k << " 的位置是 " << i;
	}
	else{
		Line(70, 1);
		cout << "元素不在列表中";
	}
	cout << endl;
	Line(70, 1);
}

int BinSearch::BinSearcher(SeqList R, int n, KeyType k)
{
	int low = 0, high = n - 1, mid, count = 0;
	while (low < high){
		mid = (low + high) / 2;
		cout << "第 " << ++count << " 次比较：在 [" << low << "," << high << "] 中比较元素 R[" << mid << "]：" << R[mid].key << endl;
		if (R[mid].key == k){
			return mid;
		}
		if (R[mid].key > k){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	} 
	return -1;
}

void BinSearch::Line(int length, int type)
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