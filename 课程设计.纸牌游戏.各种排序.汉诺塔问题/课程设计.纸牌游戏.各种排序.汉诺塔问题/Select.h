#pragma once
#include "CardGame.h"
typedef int KeyType;  
class Select
{
public:
	Select();
	~Select();

	CardGame extra;

	KeyType key;

	void SelectSort(Select R[], int n);
};


