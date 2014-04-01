#pragma once
class SingleList
{
public:
	SingleList();
	~SingleList();

	char data, e;

	SingleList *next, *h;

	void SingleListMenu();
	void InitList(SingleList * &L);
	void DestoryList(SingleList * &L);
	int ListEmpty(SingleList * L);
	int ListLength(SingleList * L);
	void DispList(SingleList *L);
	int GetElem(SingleList *L, int i, char &e);
	int LocateElem(SingleList *L, char e);
	int ListInsert(SingleList * &L, int i, char e);
	int ListDelete(SingleList * &L, int i, char &e);
	void Line(int length, int type);
};

