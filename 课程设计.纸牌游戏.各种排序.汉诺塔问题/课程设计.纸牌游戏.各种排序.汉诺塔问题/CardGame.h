#pragma once
class CardGame
{
public:
	CardGame();
	~CardGame();

	bool cardStatus[53];		//记录卡面正反

	void Line(int length, int type);
	void FlopCard(int n);
	void CardMenu();
};

