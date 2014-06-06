#pragma once
#define  MaxSize 100
#define  NULLKEY -1
typedef int KeyType;
typedef char *InfoTypeHA;
#include "BinSearch.h"

class Hash
{
public:
	Hash();
	~Hash();

	KeyType key;
	InfoTypeHA data;
	int count;

	typedef Hash HashTable[MaxSize];

	BinSearch extra;

	void HashMenu();
	void InsertHT(HashTable ha, int &n, KeyType k, int p);
	void CreateHT(HashTable ha, KeyType x[], int n, int m, int p);
	int SearchHT(HashTable ha, int p, KeyType k);
	void DispHT(HashTable ha, int n, int m);
};

