#pragma once
typedef int KeyType;
typedef char InfoType;

class BSTree
{
public:
	BSTree();
	~BSTree();

	KeyType key;
	InfoType data;
	BSTree *lchild, *rchild;

	void BSTree::BSTreeMenu();
};

