
//包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//常量声明:雷的棋盘大小
#define ROW 9
#define COL 9
//常量声明:加了一圈外围的雷的棋盘大小
#define ROWS ROW+2
#define COLS COL+2
//常量声明：雷的数量
#define EASY_COUNT 10

//函数声明：初始化，注意函数的传参和形参
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//函数声明：打印棋盘，注意函数的传参和形参
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//函数声明：布置雷
void setMine(char board[ROWS][COLS], int row, int col);
//函数声明：扫雷，注意函数的传参和形参
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);