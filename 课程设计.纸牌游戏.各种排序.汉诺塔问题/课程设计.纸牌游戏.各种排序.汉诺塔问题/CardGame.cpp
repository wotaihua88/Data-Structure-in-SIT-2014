#include "stdafx.h"
#include "CardGame.h"
#include <iostream>
#include <iomanip>

using namespace std;

CardGame::CardGame()
{
}

CardGame::~CardGame()
{
}

void CardGame::CardMenu()
{	
	int i;
	cout << "1.纸牌游戏" << endl;
	Line(70, 1);
	for (i = 0; i < 53; i++){		//初始化卡面状态
		cardStatus[i] = true;		//True表示正面
	}
	for (i = 2; i < 53; i++){		//开始翻牌

		FlopCard(i);
	}
	Line(70, 1);
	cout << "全部卡片翻转完毕" << endl;
	Line(70, 1);
	for (i = 1; i < 53; i++){
		if (cardStatus[i] == true){
			cout << "卡片: " << i << " 正面朝上" << endl;
		}
	}
	Line(70, 1);
}

void CardGame::FlopCard(int n)
{
	cout << "翻转 n = " << n << " 倍数卡片序号: ";
	for (int i = n; i <= 52; i++){
		if (i%n == 0){		//倍数翻牌
			cardStatus[i] = !cardStatus[i];
			cout << i << ", ";
		}
	}
	cout << endl;
}

void CardGame::Line(int length, int type)
{
	for (int t = 0; t < length; t++)
	{
		cout << "-";
	}
	if (type == 1)
	{
		cout << endl;
	}
}
