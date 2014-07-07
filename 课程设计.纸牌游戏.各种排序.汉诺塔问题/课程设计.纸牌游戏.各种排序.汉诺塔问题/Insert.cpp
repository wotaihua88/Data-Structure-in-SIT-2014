#include "stdafx.h"
#include "Insert.h"
#include <iostream>

using namespace std;

Insert::Insert()
{
}

Insert::~Insert()
{
}

void Insert::InsertSort(Insert R[], int n)
{
	int i, j, k;
	Insert tmp;
	for (i = 1; i < n; i++)
	{
		tmp = R[i];		//暂存本次需要排序的值
		j = i - 1;		//存储位置定位
		while (j >= 0 && tmp.key < R[j].key)
		{
			R[j + 1] = R[j];		//后移数据
			j--;
		}
		R[j + 1] = tmp;		//插入值
		cout << "次数 " << i << " :";
		for (k = 0; k < n; k++){
			cout << " " << R[k].key;
		}
		cout << endl;
	}
}
