﻿#define _CRT_SECURE_NO_WARNINGS 1
#include "五子棋.h"
//用户落子的位置，保存在全局变量中
int x = 0;//行
int y = 0;//列

void Menu()
{
	printf("############################\n");
	printf("###  1.Play       0.Exit  ##\n");
	printf("############################\n");
}

//进度条
void process_bar()
{
	char bar[101];//这里是101，为了打印从0-100显示，下标必须为0-100
	memset(bar, '\0', sizeof(bar));
	const char* lable = "|/-\\";//注意：这里会把‘\\’当做一个字符
	
	int i = 0;
	while (i <= 100)
	{
		//[                 ###############][53%]
		//printf("[%100s]\r", bar);//这里由于是需要预留空间的，%100s，默认100个位，不足的前面补空格
		//[###############                 ][53%]
		printf("[%-100s][%-3d%%][%c]\r", bar, i, lable[i % 4]); // 这里覆盖，故使用%-100s，表示数据左对齐，不足位数右边补空格
		fflush(stdout);//立即刷新缓冲区
		bar[i] = '#';//这里增加
		i++;
		Sleep(1);//单位秒
	}
	printf("\n");//如果没有这一行，则结果是##############################][100%]
	//这一行的目的是，回车并换行显示
}

//按照x,y作为起点，按照特定的方向，求连续相对的最大个数
int ChessCount(int board[][COL], int row, int col, enum Dir d)//如果x,y不是全局的，则需要传参
{
	//临时变量保存x和y的值，防止后续发生变化，用户落子在数组中的真正坐标
	//x，y为全局变量，记录的是最近一次落子坐标
	int _x = x - 1;
	int _y = y - 1;
	int count = 0;
	while (1)
	{
		switch (d)
		{
			case LEFT:
				_y--;
				break;
			case RIGHT:
				_y++;
				break;
			case UP:
				_x--;
				break;
			case DOWN:
				_x++;
				break;
			case LEFT_UP:
				_x--;
				_y--;
				break;
			case LEFT_DOWN:
				_x++;
				_y--;
				break;
			case RIGHT_UP:
				_x--;
				_y++;
				break;
			case RIGHT_DOWN:
				_x++;
				_y++;
				break;
			default:
				//Do Nothing
				break;
		}
		//判断当前位置，不同方向的连珠情况，但不包括当前位置，故count + 1，这里在函数外实现了
		//如果在这里+1，则需要在函数外-1.因为两个方向都+1了
		
		//判断坐标是否越界，如果越界，不统计
		if (_x < 0 || _x > row - 1 || _y < 0 || _y > col - 1)
		{
			break;
		}
		//坐标合法，判断坐标的值是否与落子的值相等，若不相等，退出统计
		if (board[_x][_y] == board[x - 1][y - 1])
		//注意：不存在五个连续的空位置，因为当前计算的位置是上一个用户落子的位置，不可能为空
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

//四个状态的判断
int IsOver(int board[][COL], int row, int col)
{
	int count1 = ChessCount(board, row, col, LEFT) + ChessCount(board, row, col, RIGHT) + 1;
	int count2 = ChessCount(board, row, col, UP) + ChessCount(board, row, col, DOWN) + 1;
	int count3 = ChessCount(board, row, col, LEFT_UP) + ChessCount(board, row, col, RIGHT_DOWN) + 1;
	int count4 = ChessCount(board, row, col, LEFT_DOWN) + ChessCount(board, row, col, RIGHT_UP) + 1;

	//有人赢
	if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5)
	{
		//x，y为全局变量，记录的是最近一次落子坐标

		//第一种写法：由于用户1落的是1，用户2落的是2，直接判断落子的值，就能判断谁赢了
		//return board[x - 1][y - 1];
		
		//第二种写法：判断最近一次落子是哪个用户
		if (board[x - 1][y - 1] == PLAYER1)
			return PLAYER1_WIN;
		else
			return PLAYER2_WIN;
	}
	//判断棋盘是否满了，如果没满，则继续
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == 0)
				return NEXT;
		}
	}
	//既没有赢，且棋盘满了，即平局
	return DRAW;
}

//显示棋盘，包含了初始化棋盘
void ShowBoard(int board[][COL], int row, int col)
{
	system("cls");//清空屏幕
	//printf("\e[1;1H\e[2J");
	printf("  ");
	int i = 1;
	for (i = 1; i <= col; i++)//打印列坐标
	{
		printf("%3d", i);
	}
	printf("\n");
	//打印棋盘
	for (i = 0; i < row; i++)
	{
		int j = 0;
		printf("%2d ", i + 1);//打印横坐标
		for (j = 0; j < col; j++)
		{
			//用户落子为1，表示玩家1，落子为2表示玩家2.其余空闲位置表示0
			if (board[i][j] == 0)
				printf(" * ");
			else if (board[i][j] == PLAYER1)
				printf(" x ");
			else
				printf(" o ");
		}
		printf("\n");
	}	
}

//用户落子
void PlayerMove(int board[][COL], int row, int col, int who)
{
	while (1)
	{
		printf("Player[%d] Please Enter Your Pos#：", who);
		scanf("%d%d", &x, &y);//棋盘row从0开始，col从0开始，设用户输入的时候，都以1开始
		//坐标合法性
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("Pos Is Not Right!\n");
			continue;
		}
		//坐标去重，坐标被占用了
		if (board[x - 1][y - 1] != 0)
		{
			printf("Pos Is Not Right!\n");
			continue;
		}
		//落子
		board[x - 1][y - 1] = who;
		break;
	}
}

void Game()
{
	int board[ROW][COL];
	memset(board, 0, sizeof(board));//\0在值上，等于0，故可以使用'\0'
	int result = NEXT;//NEXT:表明要继续游戏
	do 
	{
		ShowBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL,PLAYER1);
		result = IsOver(board, ROW, COL);
		if (NEXT != result)//如果出了结果，则说明，你赢了，或者平局
		{
			break;
		}

		ShowBoard(board, ROW, COL);
		PlayerMove(board, ROW, COL, PLAYER2);
		result = IsOver(board, ROW, COL);
		if (NEXT != result)//如果出了结果，则说明，你赢了，或者平局
		{
			break;
		}
	} while (1);
	//P1 Win,P2 WIn,Draw
	ShowBoard(board, ROW, COL);
	switch (result)
	{
		case PLAYER1_WIN:
			printf("恭喜用户1，你赢了!\n");
			break;
		case PLAYER2_WIN:
			printf("恭喜用户2，你赢了!\n");
			break;
		case DRAW:
			printf("平局!\n");
			break;
		default:
			//Do Nothing
			break;
	}
}