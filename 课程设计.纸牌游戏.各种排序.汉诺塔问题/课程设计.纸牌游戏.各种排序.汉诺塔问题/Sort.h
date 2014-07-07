#pragma once
#include "CardGame.h"
#include "Select.h"
#include "Bubble.h"
#include "Insert.h"
class Sort
{
public:
	Sort();
	~Sort();

	CardGame extra;

	Insert iSort;
	Select sSort;
	Bubble bSort;

	void SortMenu();
};

