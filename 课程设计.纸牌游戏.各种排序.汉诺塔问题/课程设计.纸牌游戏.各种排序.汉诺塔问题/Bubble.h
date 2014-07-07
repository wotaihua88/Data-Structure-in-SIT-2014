#pragma once
#include "CardGame.h"
typedef int KeyType;
class Bubble
{
public:
	Bubble();
	~Bubble();

	CardGame extra;

	KeyType key;

	void BubbleSort(Bubble R[], int n);
};

