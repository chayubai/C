#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//初始化，对于一维数组的形参，可以不指明数组元素个数，二维数组列号需要指明
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
/*
//注意：9*9棋盘外围，右和下不打印
0 1 2 3 4 5 6 7 8 9 0
1 * * * * * * * * * 0
2 * * * * * * * * * 0
3 * * * * * * * * * 0
4 * * * * * * * * * 0
5 * * * * * * * * * 0
6 * * * * * * * * * 0
7 * * * * * * * * * 0
8 * * * * * * * * * 0
9 * * * * * * * * * 0
0 0 0 0 0 0 0 0 0 0 0
*/
//打印盘，注意：传入的是数组mine，show，则形参是board[ROWS][COLS]，不是board[ROW][COL]。传入的是ROW和COL，而不是ROWS和COLS
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------扫雷游戏-----------\n");
	for (i = 0; i <= col; i++)//打印列号，初始化为0
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//i = 1，棋盘只需要9*9
	{
		printf("%d ", i);//打印行号，变量为i
		for (j = 1; j <= col; j++)//j = 1，棋盘只需要9*9
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------扫雷游戏-----------\n");
}

//9*9中布置雷
void setMine(char board[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//产生1-9
		int y = rand() % col + 1;
		//去重
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//布置雷
			count--;
		}
	}
}

//计算x,y坐标周围的雷个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//1、循环遍历，计算
	//2、
	//'1' - '0' = 1
	//'0' - '0' = 0
	return 	mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//扫雷,计算当前位置mine数组中的雷的个数，把个数对应的字符放在show数组中。
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)//找出所有的非雷位置，即当所有的非雷全部排查完了，则停止
	{
		printf("请输入排查雷的坐标：>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//坐标合法
		{
			//1、踩雷
			if (mine[x][y] == '1')//一定是mine数组
			{
				printf("很遗憾，踩雷了\n");
				DisplayBoard(mine, row, col);//打印布置雷的信息
				break;
			}
			else//2、不是雷
			{
				//'1' - '0' = 1
				//'0' - '0' = 0
				// 1  + '0' = '1'
				//计算x,y坐标周围的雷个数
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//将字符放入到对应位置
				DisplayBoard(show, row, col);//打印排查的雷的信息
				win++;
			}
		}
		else//坐标非法
		{
			printf("请输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)//必须有一个判断，否则踩雷也会执行结束
	{
		printf("恭喜，排雷成功\n");
		//测试：9*9棋盘，则布置80个雷，通过DisplayBoard(mine, ROW, COL);查看布置雷的信息，测试结果的正确性
		DisplayBoard(mine, row, col);//打印布置雷的信息
	}
}
//展开方法：递归实现
//1、坐标不是雷，则改为空格
//2、该坐标周围也没有雷
//3、当周围的坐标又满足：1、坐标不是雷2、该坐标周围也没有雷，当不满足，则停止展开
//4...

