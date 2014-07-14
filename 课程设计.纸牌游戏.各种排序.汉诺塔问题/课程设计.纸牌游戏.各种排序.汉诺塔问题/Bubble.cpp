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
		cout << "次数 " << i + 1 << " :";
		for (k = 0; k < n; k++){
			cout << " " << R[k].key;
		}
		cout << endl;
		if (exchange == 0){
			return;
		}
	}
}

