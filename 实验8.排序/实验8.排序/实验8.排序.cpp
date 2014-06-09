// 实验8.排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Bubble.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Bubble bub,extra;
	int item;
	system("title 实验8.排序");
	extra.Line(70, 1);
	for (int main = 0;; main++){
		cout << "请选择演示项目: " << endl;
		for (int i = 0;; i++){
			extra.Line(70, 1);
			cout << "1.上机实验题10.3 冒泡排序算法应用" << endl << "2.上机实验题10.5 直接选择排序算法的应用" << endl << "0.退出程序" << endl;
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
		case 1:		//冒泡排序算法应用
		{
			bub.BubbleMenu();
		}break;
		case 2:		//直接选择排序算法的应用
		{
			//bst.BSTreeMenu();
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

