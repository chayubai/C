//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "game.h"
////����ʵ�֣���ʼ������
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
////����ʵ�֣���ӡ����
////�˷����б��̶���
////void DisplayBoard(char board[ROW][COL], int row, int col)
////{
////	int i = 0;
////	for (i = 0; i < row; i++)
////	{
////		//1����ӡһ�����ݺͷָ���
////		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
////		if (i < row - 1)//���һ�в���ӡ
////		{
////			//2����ӡ�ָ���
////			printf("---|---|---\n");
////		}	
////	}
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)//1����ӡһ�����ݺͷָ���
//		{
//			
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)//���һ�ָ��߲���ӡ
//			{
//				printf("|");
//			}
//		}
//		printf("\n");
//		if (i < row - 1)//���һ�в���ӡ
//		{
//			//2����ӡ�ָ���
//			int j = 0;
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)//���һ�ָ��߲���ӡ
//				{
//					printf("|");
//				}
//			}
//			printf("\n");
//		}	
//	}
//}
//
////����ʵ�֣��������
//void PlayerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("����ߣ�>\n");
//	while (1)
//	{
//		printf("������Ҫ�µ����꣺>");
//		scanf("%d %d", &x, &y);//ע����������ĸ�ʽ
//		//�ж�x,y����ĺϷ���
//		if (x >= 1 && x <= row && y >= 1 && y <= col)//�û��Ѻ�
//		{
//			if (board[x - 1][y - 1] == ' ')//��x-1�е�y-1��λ��
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("��λ���ѱ�ռ�ã�������������\n");
//			}
//		}
//		else
//		{
//			printf("����Ƿ����������룡\n");
//		}
//	}
//}
////����ʵ�֣���������
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("�����ߣ�>\n");
//	
//	while (1)
//	{
//		x = rand() % row;//ÿ����3����λ����
//		y = rand() % col;//ÿ����3����λ����
//		//ʹ��rand()֮ǰ��Ҫ����srand()����ֻ��Ҫ����һ�Σ�������test()��������ʹ��
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//		//else
//		//{
//		//	printf("��λ���ѱ�ռ��\n");//�����µ��ӱ�ռ�ã�����ʾ
//		//}
//
//	}
//}
//
////����ʵ�������Ƿ����ˣ����ˣ��򷵻�1��û�����򷵻�0
//int IsFull(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;//û��
//		}
//	}
//	return 1;//����
//}
////����ʵ�֣��ж��Ƿ�Ӯ
//char IsWin(char board[ROW][COL], int row, int col)//ֻ��ʵ��3*3��������Ӯ
//{
//	int i = 0;
//	//�жϺ�����
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//		{
//			return board[i][1];
//		}
//	}
//	//�ж�������
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
//		{
//			return board[1][i];
//		}
//	}
//	//�ж����Խ���
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
//	{
//		return board[1][i];
//	}
//	//�ж�ƽ��
//	if (1 == IsFull(board, ROW, COL))
//	{
//		return 'Q';
//	}
//	else
//		return 'C';
//
//}