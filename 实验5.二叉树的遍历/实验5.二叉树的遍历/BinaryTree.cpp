#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::TreeMenu()
{
	BinaryTree *FindNode(BinaryTree *b, ElemType x);
	BinaryTree *LchildNode(BinaryTree *p);
	BinaryTree *RchildNode(BinaryTree *p);
	cout << "上机实验题7.1 二叉树的各种基本运算" << endl;
	Line(65, 1);
	cout << "本次实验使用教材202页上机实验题7.1所提供的二叉树。" << endl;
	Line(65, 1);
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(N))))),C(F,G(I)))");
	cout << "演示1：输出二叉树b..." << endl;
	DispBTNode(b);
	cout << endl << "完毕" << endl;
	Line(65, 1);
	cout << "演示2：输出H节点的左、右孩子节点值..." << endl;
 	p = FindNode(b, 'H');
	if (p != NULL){
		lp = LchildNode(p);
		if (lp != NULL){
			cout << "H节点左孩子节点值为：" << lp->data << endl;
		}
		else{
			cout << "H节点无左孩子" << endl;
		}
		rp = RchildNode(p);
		if (rp != NULL){
			cout << "H节点右孩子节点值为：" << rp->data << endl;
		}
		else{
			cout << "H节点无右孩子" << endl;
		}
	}
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示3：输出二叉树b的深度..." << endl;
	cout << "二叉树b的深度为：" << BTNodeDepth(b) << endl;
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示4：输出二叉树b的节点个数..." << endl;
	cout << "二叉树b的节点个数为：" << Nodes(b) << endl;
	cout << "完毕" << endl;
	Line(65, 1);
	cout << "演示5：输出二叉树b的叶子节点个数及叶子节点值..." << endl;
	cout << "二叉树b的叶子节点个数为：" << LeafNodes(b) << endl;
	cout << "二叉树b的叶子节点值为：";
	DispLeaf(b);
	cout << endl << "完毕" << endl;
	Line(65, 1);
	cout << "演示6：输出二叉树b的先序遍历序列..." << endl;
	PreOrder(b);
	cout << endl << "完毕" << endl;
	Line(65, 1);
	cout << "演示7：输出二叉树b的中序遍历序列..." << endl;
	InOrder(b);
	cout << endl << "完毕" << endl;
	Line(65, 1);
	cout << "演示8：输出二叉树b的后序遍历序列..." << endl;
	PostOrder(b);
	cout << endl << "完毕" << endl;
	Line(65, 1);

}

void BinaryTree::CreateBTNode(BinaryTree *&b, char *str)
{
	BinaryTree *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:p = (BinaryTree *)malloc(sizeof(BinaryTree));
				p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL){
				b = p;
			}
			else{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

BinaryTree *FindNode(BinaryTree *b, ElemType x)
{
	BinaryTree *p;
	if (b == NULL){
		return NULL;
	}
	else if (b->data == x){
		return b;
	}
	else{
		p = FindNode(b->lchild, x);
		if (p != NULL){
			return p;
		}
		else{
			return FindNode(b->rchild, x);
		}
	}
}

BinaryTree *LchildNode(BinaryTree *p)
{
	return p->lchild;
}

BinaryTree *RchildNode(BinaryTree *p)
{
	return p->rchild;
}

int BinaryTree::BTNodeDepth(BinaryTree *b)
{
	int lchilddep, rchilddep;
	if (b == NULL){
		return (0);
	}
	else{
		lchilddep = BTNodeDepth(b->lchild);
		rchilddep = BTNodeDepth(b->rchild);
		return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
	}
}

void BinaryTree::DispBTNode(BinaryTree *b)
{
	if (b != NULL)
	{
		cout << (char)b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DispBTNode(b->lchild);
			if (b->rchild != NULL)
			{
				cout << ",";
			}
			DispBTNode(b->rchild);
			cout << ")";
		}
	}
}

int BinaryTree::Nodes(BinaryTree *b)
{
	int num1, num2;
	if (b == NULL){
		return 0;
	}
	else if (b->lchild == NULL&&b->rchild == NULL){
		return 1;
	}
	else{
		num1 = Nodes(b->lchild);
		num2 = Nodes(b->rchild);
		return (num1 + num2 + 1);
	}
}

int BinaryTree::LeafNodes(BinaryTree *b)
{
	int num1, num2;
	if (b == NULL){
		return 0;
	}
	else if (b->lchild == NULL && b->rchild == NULL){
		return 1;
	}
	else{
		num1 = LeafNodes(b->lchild);
		num2 = LeafNodes(b->rchild);
		return(num1 + num2);
	}
}

void BinaryTree::DispLeaf(BinaryTree *b)
{
	if (b != NULL){
		if (b->lchild == NULL && b->rchild == NULL){
			cout << b->data;
		}
		else{
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}
	}
}

void BinaryTree::PreOrder(BinaryTree *b)
{
	if (b != NULL){
		cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void BinaryTree::InOrder(BinaryTree *b)
{
	if (b != NULL){
		InOrder(b->lchild);
		cout << b->data;
		InOrder(b->rchild);
	}
}

void BinaryTree::PostOrder(BinaryTree *b)
{
	if (b != NULL){
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data;
	}
}

void BinaryTree::Line(int length, int type)
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