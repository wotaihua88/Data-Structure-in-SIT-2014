#pragma once
#include "Str.h"
class StrEncrypt
{

public:
	StrEncrypt();
	~StrEncrypt();

	Str A, B, p, q, ec, extra;

	void EncryptMenu();
	Str EnCrypt(Str p);
	Str UnEncrypt(Str q);
};

