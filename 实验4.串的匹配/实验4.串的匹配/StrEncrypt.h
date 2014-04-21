#pragma once
#include "Str.h"
class StrEncrypt
{

public:
	StrEncrypt();
	~StrEncrypt();

	Str A, B, text, encryptxt, unencryptxt, extra;

	void EncryptMenu();
	Str EnCrypt(Str p);
	Str UnEncrypt(Str q);
};

