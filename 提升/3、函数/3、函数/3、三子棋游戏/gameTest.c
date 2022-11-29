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
	//创建数组用来存放玩家和电脑下的棋子的棋盘信息
	char board[ROW][COL] = { 0 };//ROW COL方便未来修改棋盘的大小
	
	//由于棋盘数组被初始化为0，看上去不太直观，需要初始化棋盘为空格
	InitBoard(board, ROW, COL);

	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//下棋
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	//break跳到这里
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新输入！");
			break;
		}
	} while (input);
}
int main()
{
	test();//或者直接把test()函数的实现放入主函数中
	return 0;
}