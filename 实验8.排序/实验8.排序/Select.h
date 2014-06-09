#pragma once
#include "Bubble.h"
#define MaxSize 20
typedef int KeyType;  
typedef char InfoType[10];
class Select
{
public:
	Select();
	~Select();

	Bubble extra;

	KeyType key;
	InfoType data;

	void SelectMenu();
	void SelectSort(Select R[], int n);
};


