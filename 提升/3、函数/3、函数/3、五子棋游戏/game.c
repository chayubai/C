//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "game.h"
////函数实现：初始化棋盘
//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0;j < col;j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
////函数实现：打印棋盘
////此方法列被固定了
////void DisplayBoard(char board[ROW][COL], int row, int col)
////{
////	int i = 0;
////	for (i = 0; i < row; i++)
////	{
////		//1、打印一行数据和分隔线
////		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
////		if (i < row - 1)//最后一行不打印
////		{
////			//2、打印分割行
////			printf("---|---|---\n");
////		}	
////	}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//1、打印一行数据和分隔线
//		{
//			
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)//最后一分隔线不打印
//			{
//				printf("|");
//			}
//		}
//		printf("\n");
//		if (i < row - 1)//最后一行不打印
//		{
//			//2、打印分割行
//			int j = 0;
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)//最后一分隔线不打印
//				{
//					printf("|");
//				}
//			}
//			printf("\n");
//		}	
//	}
//}
//
////函数实现：玩家下棋
//void PlayerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("玩家走：>\n");
//	while (1)
//	{
//		printf("请输入要下的坐标：>");
//		scanf("%d %d", &x, &y);//注意输入坐标的格式
//		//判断x,y坐标的合法性
//		if (x >= 1 && x <= row && y >= 1 && y <= col)//用户友好
//		{
//			if (board[x - 1][y - 1] == ' ')//第x-1行第y-1个位置
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("该位置已被占用，重新输入坐标\n");
//			}
//		}
//		else
//		{
//			printf("坐标非法，重新输入！\n");
//		}
//	}
//}
////函数实现：电脑下棋
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("电脑走：>\n");
//	
//	while (1)
//	{
//		x = rand() % row;//每超过3，进位丢掉
//		y = rand() % col;//每超过3，进位丢掉
//		//使用rand()之前需要调用srand()，且只需要调用一次，即放在test()函数外面使用
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//		//else
//		//{
//		//	printf("该位置已被占用\n");//电脑下的子被占用，不提示
//		//}
//
//	}
//}
//
////函数实现棋盘是否满了：满了，则返回1，没满，则返回0
//int IsFull(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;//没满
//		}
//	}
//	return 1;//满了
//}
////函数实现：判断是否赢
//char IsWin(char board[ROW][COL], int row, int col)//只能实现3*3的棋盘输赢
//{
//	int i = 0;
//	//判断横三行
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//		{
//			return board[i][1];
//		}
//	}
//	//判断竖三列
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
//		{
//			return board[1][i];
//		}
//	}
//	//判断两对角线
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
//	{
//		return board[1][i];
//	}
//	//判断平局
//	if (1 == IsFull(board, ROW, COL))
//	{
//		return 'Q';
//	}
//	else
//		return 'C';
//
//}