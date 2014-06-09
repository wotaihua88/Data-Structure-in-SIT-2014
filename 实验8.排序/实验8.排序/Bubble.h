#pragma once
#define MaxSize 20
typedef int KeyType;
typedef char InfoType[10];
class Bubble
{
public:
	Bubble();
	~Bubble();

	KeyType key;
	InfoType data;

	void BubbleMenu();
	void BubbleSort(Bubble R[], int n);
	void Line(int length, int type);
};

