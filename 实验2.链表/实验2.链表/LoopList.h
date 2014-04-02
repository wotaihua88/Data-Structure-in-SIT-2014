#pragma once
class LoopList
{
public:
	LoopList();
	~LoopList();

	char data, e;

	LoopList *next, *h;

	void LoopListMenu();
	void InitList(LoopList * &L);
	void DestoryList(LoopList * &L);
	int ListEmpty(LoopList *L);
	int ListLength(LoopList *L);
	void DispList(LoopList *L);
	int GetElem(LoopList *L, int i, char &e);
	int LocateElem(LoopList *L, char e);
	int ListInsert(LoopList * &L, int i, char e);
	int ListDelete(LoopList * &L, int i, char &e);
	void Line(int length, int type);
};

