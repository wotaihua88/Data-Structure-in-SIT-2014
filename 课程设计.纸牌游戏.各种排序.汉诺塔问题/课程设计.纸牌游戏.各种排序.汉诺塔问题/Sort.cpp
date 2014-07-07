#include "stdafx.h"
#include "Sort.h"
#include <iostream>

using namespace std;

Sort::Sort()
{
}

Sort::~Sort()
{
}

void Sort::SortMenu()
{
	int tempData[999];
	Insert iData[999];
	Select sData[999];
	Bubble bData[999];
	int numCount = 0;
	cout << "2.各种排序" << endl;
	extra.Line(70, 1);
	cout << "请输入诺干用以排序的数字 (输入9999结束输入): " << endl;
	for (int i = 0; i < 999; i++){
		cout << "n" << i + 1 << " = ";
		cin >> tempData[i];
		if (tempData[i] == 9999){
			extra.Line(70, 1);
			cout << "结束输入" << endl;
			break;
		}
		else{
			numCount++;
		}
	}
	for (int i = 0; i < numCount; i++){		//将输入数据传递给不同排序类
		iData[i].key = tempData[i];
		sData[i].key = tempData[i];
		bData[i].key = tempData[i];
 	}
	extra.Line(70, 1);
	cout << "开始排序..." << endl;
	extra.Line(70, 1);
	cout << "方法1.插入法排序:" << endl;
	extra.Line(70, 1);
	cout << "排序过程:" << endl;
	iSort.InsertSort(iData, numCount);
	extra.Line(70, 1);
	cout << "排序结果:";
	for (int k = 0; k < numCount; k++){
		cout << " " << iData[k].key;
	}
	cout << endl;
	extra.Line(70, 1);
	cout << "方法2.选择法排序:" << endl;
	extra.Line(70, 1);
	cout << "排序过程:" << endl;
	sSort.SelectSort(sData, numCount);
	extra.Line(70, 1);
	cout << "排序结果:";
	for (int k = 0; k < numCount; k++){
		cout << " " << sData[k].key;
	}
	cout << endl;
	extra.Line(70, 1);
	cout << "方法3.起泡法改进算法排序:" << endl;
	extra.Line(70, 1);
	cout << "排序过程:" << endl;
	bSort.BubbleSort(bData, numCount);
	extra.Line(70, 1);
	cout << "排序结果:";
	for (int k = 0; k < numCount; k++){
		cout << " " << bData[k].key;
	}
	cout << endl;
	extra.Line(70, 1);
}
