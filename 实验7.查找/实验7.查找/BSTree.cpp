#include "stdafx.h"
#include "BSTree.h"
#include <iostream>
#include <malloc.h>
#include "BinSearch.h"
#include <iomanip>

BinSearch extra;

using namespace std;

int InsertBST(BSTree *&p, KeyType k);
void DispBST(BSTree *bt);
BSTree *CreateBST(KeyType A[], int n);
int SearchBST(BSTree *bt, KeyType k);

BSTree::BSTree()
{
}

BSTree::~BSTree()
{
}

void BSTree::BSTreeMenu()
{
	BSTree *bt;
	KeyType k = 6;
	int a[] = { 4, 9, 0, 1, 8, 6, 3, 5, 2, 7 }, n = 10;
	cout << "上机实验题9.4 二叉排序树的基本运算" << endl;
	extra.Line(70, 1);
	cout << "演示1：创建一颗二叉排序树..." << endl;
	bt = CreateBST(a, n);
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "演示2：输出创建的二叉排序树..." << endl;
	DispBST(bt);
	cout << endl;
	cout << "完毕" << endl;
	extra.Line(70, 1);
	cout << "演示3：采用递归法查找关键字为 6 的节点，并输出查找路径..." << endl;
	cout << "查找路径为：";
	SearchBST(bt, k);
	cout << endl << "完毕" << endl;
	extra.Line(70, 1);
}

int InsertBST(BSTree *&p, KeyType k)
{
	if (p == NULL){
		p = (BSTree *)malloc(sizeof(BSTree));
		p->key = k;
		p->lchild = p->rchild = NULL;
		return 1;
	}
	else if (k == p->key){
		return 0;
	}
	else if (k < p->key){
		return InsertBST(p->lchild, k);
	}
	else{
		return InsertBST(p->rchild, k);
	}
}

void DispBST(BSTree *bt)
{
	if (bt != NULL){
		cout << bt->key;
		if (bt->lchild != NULL || bt->rchild != NULL){
			cout << "(";
			DispBST(bt->lchild);
			if (bt->rchild != NULL){
				cout << ",";
			}
			DispBST(bt->rchild);
			cout << ")";
		}
	}
}

BSTree *CreateBST(KeyType A[], int n)
{
	BSTree *bt = NULL;
	int i = 0;
	while (i < n){
		if (InsertBST(bt, A[i]) == 1){
			cout << "第 " << i + 1 << " 步，插入 " << A[i] ;
			i + 1 == 10 ? cout << "    " : cout << "     ";
			DispBST(bt);
			cout << endl;
			i++;
		}
	}
	return bt;
}

int SearchBST(BSTree *bt, KeyType k)
{
	if (bt == NULL){
		return 0;
	}
	else if (k == bt->key){
		cout << "  " << bt->key;
		return 1;
	}
	else if (k < bt->key){
		SearchBST(bt->lchild, k);
	}
	else{
		SearchBST(bt->rchild, k);
	}
	cout << "  " << bt->key;
	return 998;
}

