#pragma once
const int MaxSize = 100;
typedef char ElemType;
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	ElemType data;
	BinaryTree *lchild, *rchild;
	BinaryTree *b, *p, *lp, *rp;

	void TreeMenu();
	void CreateBTNode(BinaryTree *&b, char *str);
	int BTNodeDepth(BinaryTree *b);
	void DispBTNode(BinaryTree *b);
	int Nodes(BinaryTree *b);
	int LeafNodes(BinaryTree *b);
	void DispLeaf(BinaryTree *b);
	void Line(int length, int type);
};

