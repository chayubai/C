#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*******************************\n");
	printf("****** 1、play   0、exit ******\n");
	printf("*******************************\n");
}
//整个游戏的算法实现
void game()
{
	//创建数组用来存放雷的棋盘信息
	//1、存放布置好的雷的信息
	//如果是雷，用'1'表示，非雷用'0'表示
	char mine[ROWS][COLS] = { 0 };//ROW COL方便未来修改盘的大小
	//当雷的个数为1时，为了区分是雷的个数，还是本身就是雷，创建一个数组表示排查出来的雷的信息
	//没有排查雷时，用*表示， 排查到雷时，用数字表示周围雷的个数，同时为了防止访问越界，方便排查雷的个数，将棋盘外围扩大一圈
	//即，如果需要9*9的棋盘，则最好是布置11*11的棋盘
	//2、存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };

	//初始化，并将要初始化的内容作为参数传入，注意函数的传参和形参
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘，注意函数的传参和形参
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	setMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//打印布置雷的信息，观察是否布置雷成功
	
	//扫雷
	//函数声明：扫雷
	FindMine(mine, show, ROW, COL);//注意函数的传参和形参
}
void test()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入！");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}