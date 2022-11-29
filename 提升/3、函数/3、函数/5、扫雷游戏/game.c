#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
//��ʼ��������һά������βΣ����Բ�ָ������Ԫ�ظ�������ά�����к���Ҫָ��
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
//ע�⣺9*9������Χ���Һ��²���ӡ
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
//��ӡ�̣�ע�⣺�����������mine��show�����β���board[ROWS][COLS]������board[ROW][COL]���������ROW��COL��������ROWS��COLS
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------ɨ����Ϸ-----------\n");
	for (i = 0; i <= col; i++)//��ӡ�кţ���ʼ��Ϊ0
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//i = 1������ֻ��Ҫ9*9
	{
		printf("%d ", i);//��ӡ�кţ�����Ϊi
		for (j = 1; j <= col; j++)//j = 1������ֻ��Ҫ9*9
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ����Ϸ-----------\n");
}

//9*9�в�����
void setMine(char board[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//����1-9
		int y = rand() % col + 1;
		//ȥ��
		if (board[x][y] == '0')
		{
			board[x][y] = '1';//������
			count--;
		}
	}
}

//����x,y������Χ���׸���
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//1��ѭ������������
	//2��
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

//ɨ��,���㵱ǰλ��mine�����е��׵ĸ������Ѹ�����Ӧ���ַ�����show�����С�
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)//�ҳ����еķ���λ�ã��������еķ���ȫ���Ų����ˣ���ֹͣ
	{
		printf("�������Ų��׵����꣺>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//����Ϸ�
		{
			//1������
			if (mine[x][y] == '1')//һ����mine����
			{
				printf("���ź���������\n");
				DisplayBoard(mine, row, col);//��ӡ�����׵���Ϣ
				break;
			}
			else//2��������
			{
				//'1' - '0' = 1
				//'0' - '0' = 0
				// 1  + '0' = '1'
				//����x,y������Χ���׸���
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//���ַ����뵽��Ӧλ��
				DisplayBoard(show, row, col);//��ӡ�Ų���׵���Ϣ
				win++;
			}
		}
		else//����Ƿ�
		{
			printf("����������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)//������һ���жϣ��������Ҳ��ִ�н���
	{
		printf("��ϲ�����׳ɹ�\n");
		//���ԣ�9*9���̣�����80���ף�ͨ��DisplayBoard(mine, ROW, COL);�鿴�����׵���Ϣ�����Խ������ȷ��
		DisplayBoard(mine, row, col);//��ӡ�����׵���Ϣ
	}
}
//չ���������ݹ�ʵ��
//1�����겻���ף����Ϊ�ո�
//2����������ΧҲû����
//3������Χ�����������㣺1�����겻����2����������ΧҲû���ף��������㣬��ֹͣչ��
//4...

