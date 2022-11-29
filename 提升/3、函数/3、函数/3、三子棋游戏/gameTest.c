#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*******************************\n");
	printf("****** 1��play   0��exit ******\n");
	printf("*******************************\n");
}
//������Ϸ���㷨ʵ��
void game()
{
	//�����������������Һ͵����µ����ӵ�������Ϣ
	char board[ROW][COL] = { 0 };//ROW COL����δ���޸����̵Ĵ�С
	
	//�����������鱻��ʼ��Ϊ0������ȥ��ֱ̫�ۣ���Ҫ��ʼ������Ϊ�ո�
	InitBoard(board, ROW, COL);

	//��ӡ����
	DisplayBoard(board, ROW, COL);

	//����
	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	//break��������
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("��������������룡");
			break;
		}
	} while (input);
}
int main()
{
	test();//����ֱ�Ӱ�test()������ʵ�ַ�����������
	return 0;
}