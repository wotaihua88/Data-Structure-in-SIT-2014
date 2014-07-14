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

void Select::SelectSort(Select R[], int n)
{
	int i, j, k, l;
	Select temp;
	for (i = 0; i < n - 1; i++){
		k = i;
		for (j = i + 1; j < n; j++){		//有序区和无序区识别
			if (R[j].key < R[k].key){
				k = j;
			}
		}
		if (k != i){		//无序区内进行排序
			temp = R[i];
			R[i] = R[k];
			R[k] = temp;
		}
		cout << "次数 " << i + 1 << " :";
		for (l = 0; l < n; l++){
			cout << " " << R[l].key;
		}
		cout << endl;
	}
}