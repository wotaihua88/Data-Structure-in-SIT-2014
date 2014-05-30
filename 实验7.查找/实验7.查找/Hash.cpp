#include "stdafx.h"
#include "Hash.h"
#include <iostream>
#include <iomanip>
using namespace std;

Hash::Hash()
{
}

Hash::~Hash()
{
}

void Hash::HashMenu()
{
	int x[] = { 16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77 };
	int n = 11, m = 13, p = 13, i, k = 29;
	HashTable ha;
	cout << "上机实验题9.8 哈希表的相关运算" << endl;
	extra.Line(70, 1);
	cout << "演示1：创建一颗二叉排序树并使用线性探查法解决冲突..." << endl;
	CreateHT(ha,x,n,m,p);
	DispHT(ha, n, m);
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "演示2：查找关键字为29的元素..." << endl;
	i = SearchHT(ha, p, k);
	if (i != -1){
		cout << "元素 " << k << " 的位置为：" << i << endl;
	}
	else{
		cout << "未找到" << endl;
	}
	extra.Line(70, 1);
}

void Hash::InsertHT(HashTable ha, int &n, KeyType k, int p)
{
	int i, adr;
	adr = k%p;
	if (ha[adr].key == NULLKEY){
		ha[adr].key = k;
		ha[adr].count = 1;
	}
	else{
		i = 1;
		do{
			adr = (adr + 1) % p;
			i++;
		} while (ha[adr].key != NULLKEY);
		ha[adr].key = k;
		ha[adr].count = i;
	}
	n++;
}

void Hash::CreateHT(HashTable ha, KeyType x[], int n, int m, int p)
{
	int i, n1 = 0;
	for (i = 0; i < m; i++){
		ha[i].key = NULLKEY;
		ha[i].count = 0;
	}
	for (i = 0; i < n; i++){
		InsertHT(ha, n1, x[i], p);
	}
}

int Hash::SearchHT(HashTable ha, int p, KeyType k)
{
	int i = 0,adr;
	adr = k%p;
	while (ha[adr].key != NULLKEY && ha[adr].key != k){
		i++;
		adr = (adr + 1) % p;
	}
	if (ha[adr].key == k){
		return adr;
	}
	else{
		return 1;
	}
}

void Hash::DispHT(HashTable ha, int n, int m)
{
	float avg = 0;
	int i;
	cout << "哈希表地址：  ";
	for (i = 0; i < m; i++){
		cout << setw(4) << i;
	}
	cout << endl;
	cout << "哈希表关键字：";
	for (i = 0; i < m; i++){
		if (ha[i].key == NULLKEY){
			cout << setw(4) << "NUL";
		}
		else{
			cout << setw(4) << ha[i].key;
		}
	}
	cout << endl;
	cout << "搜索次数：    ";
	for (i = 0; i < m; i++){
		if (ha[i].key == NULLKEY){
			cout << setw(4) << "NUL";
		}
		else{
			cout << setw(4) << ha[i].count;
		}
	}
	cout << endl;
}