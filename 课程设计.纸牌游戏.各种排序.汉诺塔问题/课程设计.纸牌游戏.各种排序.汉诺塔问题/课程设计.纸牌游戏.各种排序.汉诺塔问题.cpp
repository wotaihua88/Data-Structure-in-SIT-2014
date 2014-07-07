// 课程设计.纸牌游戏.各种排序.汉诺塔问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CardGame.h"
#include "Sort.h"
#include "PopHanoi.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CardGame extra, cardMenu;
	Sort sortMenu;
	PopHanoi hanoiMenu;
	int item;
	system("title 课程设计.纸牌游戏.各种排序.汉诺塔问题");
	extra.Line(70, 1);
	for (int main = 0;; main++){
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++){
			extra.Line(70, 1);
			cout << "1.纸牌游戏" << endl << "2.各种排序" << endl <<  "3.汉诺塔问题" << endl << "0.退出程序" << endl;
			extra.Line(70, 1);
			cout << "请选择: ";
			cin >> item;
			extra.Line(70, 1);
			if (item != 1 && item != 2 && item != 3 && item != 0){
				cout << "输入错误，请重新输入！" << endl;
			}
			else{
				break;
			}
		}
		switch (item){
		case 1:		//纸牌游戏
		{
			cardMenu.CardMenu();
		}break;
		case 2:		//各种排序
		{
			sortMenu.SortMenu();
		}break;
		case 3:		//汉诺塔问题
		{
			hanoiMenu.HanoiMenu();
		}break;
		case 0:		//退出程序
		{
			return 0;
		}break;
		default:
		{
			break;
		}
		}
	}
	return 0;
}

