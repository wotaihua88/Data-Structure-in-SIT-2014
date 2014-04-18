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
	void StrAssign(Str &s, char cstr[]);
	int StrLength(Str s);
	Str Concat(Str s, Str t);
	Str Str::SubStr(Str s, int i, int j);
	Str InsStr(Str s1, int i, Str s2);
	Str DelStr(Str s, int i, int j);
	Str RepStr(Str s, int i, int j, Str t);
	void DispStr(Str s);
	void Line(int length, int type);
};

