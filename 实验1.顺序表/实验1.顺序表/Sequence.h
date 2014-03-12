#pragma once
const int MAXSIZE = 100;
class Sequence
{
public:
	Sequence();
	~Sequence();

	int data[MAXSIZE];
	int length;

	Sequence *L, *s, *r;

	void SequenceMenu();
	void initSeqList();
	void createSeqList();
	void dispSeqList();
	void Line(int length, int type);
};
