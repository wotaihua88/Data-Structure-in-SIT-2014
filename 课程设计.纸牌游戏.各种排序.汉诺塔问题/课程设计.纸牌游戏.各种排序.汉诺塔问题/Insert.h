#pragma once
#include "CardGame.h"
typedef int KeyType;
class Insert
{
public:
	Insert();
	~Insert();

	CardGame extra;

	KeyType key;

	void InsertSort(Insert R[], int n);
};

