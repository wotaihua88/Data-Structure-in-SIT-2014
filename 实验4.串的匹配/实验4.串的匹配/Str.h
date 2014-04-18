#pragma once
const int StrMaxSize = 100;

class Str
{
public:
	Str();
	~Str();

	char data[StrMaxSize];
	int length;

	void StrMenu();
	void StrAssign(Str &s, char sctr[]);
	void StrCopy(Str &s, Str t);
	bool StrEqual(Str s, Str t);
	int StrLength(Str s);
	Str Concat(Str s, Str t);
	Str SubStr(Str s, int, int j);
	Str InsStr(Str s1, int i, Str s2);
	Str DelStr(Str s, int i, int j);
	Str RepStr(Str s, int i, int j, Str t);
	void DispStr(Str s);
	void Line(int length, int type);
};

