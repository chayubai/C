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
	//如果是雷，用字符'1'表示，非雷用字符'0'表示
	char mine[ROWS][COLS] = { 0 };//程序员使用的是ROWS COLS，而用户使用的是ROW COL

	//当雷的个数为1时，为了区分是雷的个数，还是本身就是雷，创建一个数组表示排查出来的雷的信息
	//没有排查雷时，用字符*表示， 排查到雷时，用数字表示周围雷的个数（以当前位置为中心，周围一圈雷的个数）
	//此外，当排查雷时，如果排查的是边上的坐标位置时，判断周围一圈雷的个数时，为了防止访问越界，方便排查雷的个数，将棋盘外围扩大一圈
	//即，如果需要9*9的棋盘，则最好是布置11*11的棋盘(上下左右都增加一圈)
	//2、存放排查出的雷的信息,使用ROWS和COLS是为了和mine数组每个元素的位置一一对应
	char show[ROWS][COLS] = { 0 };

	//初始化11*11的棋盘，并将要初始化的内容作为参数传入，注意函数的传参和形参
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印9*9的棋盘，注意函数的传参和形参
	//DisplayBoard(mine, ROW, COL);//测试，初始化是否成功
	DisplayBoard(show, ROW, COL);

	//在9*9的棋盘大小上布置雷，外围一圈不放雷
	setMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//打印布置雷的信息，测试，观察是否布置雷成功

	//扫雷
	//函数声明：扫雷
	FindMine(mine, show, ROW, COL);//注意函数的传参和形参
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
