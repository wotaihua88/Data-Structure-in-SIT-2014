#pragma once

const int MAXSIZE = 100;
class Sequence
{
public:
	Sequence();
	~Sequence();

	int data[MAXSIZE];
	int length;

	char e;

	Sequence *L;

	void SequenceMenu();
	void initSeqList();
	void freeList(Sequence *L);
	int emptyListCheck(Sequence *L);
	int listLength(Sequence *L);
	int SeqListInsert(Sequence * &L, int i, char e);
	void dispSeqList(Sequence *L);
	int getElem(Sequence *L, int i, char &e);
	int locateElem(Sequence *L, char e);
	int listDelete(Sequence * &L, int i, char &e);
	void Line(int length, int type);
};
