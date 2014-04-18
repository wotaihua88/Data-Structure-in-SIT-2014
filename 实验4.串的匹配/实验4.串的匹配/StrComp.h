#pragma once
#include "Str.h"
class StrComp
{
public:
	StrComp();
	~StrComp();

	Str comp, extra;

	void StrCompMenu();
	Str CompChar(Str s1, Str s2);
};

