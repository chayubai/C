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
	//����������������׵�������Ϣ
	//1����Ų��úõ��׵���Ϣ
	//������ף���'1'��ʾ��������'0'��ʾ
	char mine[ROWS][COLS] = { 0 };//ROW COL����δ���޸��̵Ĵ�С
	//���׵ĸ���Ϊ1ʱ��Ϊ���������׵ĸ��������Ǳ�������ף�����һ�������ʾ�Ų�������׵���Ϣ
	//û���Ų���ʱ����*��ʾ�� �Ų鵽��ʱ�������ֱ�ʾ��Χ�׵ĸ�����ͬʱΪ�˷�ֹ����Խ�磬�����Ų��׵ĸ�������������Χ����һȦ
	//���������Ҫ9*9�����̣�������ǲ���11*11������
	//2������Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };

	//��ʼ��������Ҫ��ʼ����������Ϊ�������룬ע�⺯���Ĵ��κ��β�
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ���̣�ע�⺯���Ĵ��κ��β�
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	setMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//��ӡ�����׵���Ϣ���۲��Ƿ����׳ɹ�
	
	//ɨ��
	//����������ɨ��
	FindMine(mine, show, ROW, COL);//ע�⺯���Ĵ��κ��β�
}
void test()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������������룡");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}