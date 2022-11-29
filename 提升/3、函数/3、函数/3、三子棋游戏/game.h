#define _CRT_SECURE_NO_WARNINGS 1
//包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//常量声明:棋盘大小
#define ROW 3
#define COL 3

//函数声明：初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//函数声明：打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//函数声明：玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//函数声明：电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//函数声明：判断是否赢--判断数组的内容
//输赢的四种状态：
//1、玩家赢 - '*'
//2、电脑赢 - '#'
//3、平局   - 'Q'
//4、继续   - 'C'
char IsWin(char board[ROW][COL], int row, int col);