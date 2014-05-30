#pragma once
#define MAXL 100
typedef int KeyType;
typedef char InfoType[10];

class BinSearch
{
public:
	BinSearch();
	~BinSearch();

	KeyType key;
	InfoType data;

	typedef BinSearch SeqList[MAXL];

	int BinSearcher(SeqList R, int n, KeyType k);
	void BinMenu();
	void Line(int length, int type);
};

