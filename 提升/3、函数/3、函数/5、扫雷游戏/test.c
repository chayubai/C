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
	//������ף����ַ�'1'��ʾ���������ַ�'0'��ʾ
	char mine[ROWS][COLS] = { 0 };//����Աʹ�õ���ROWS COLS�����û�ʹ�õ���ROW COL

	//���׵ĸ���Ϊ1ʱ��Ϊ���������׵ĸ��������Ǳ�������ף�����һ�������ʾ�Ų�������׵���Ϣ
	//û���Ų���ʱ�����ַ�*��ʾ�� �Ų鵽��ʱ�������ֱ�ʾ��Χ�׵ĸ������Ե�ǰλ��Ϊ���ģ���ΧһȦ�׵ĸ�����
	//���⣬���Ų���ʱ������Ų���Ǳ��ϵ�����λ��ʱ���ж���ΧһȦ�׵ĸ���ʱ��Ϊ�˷�ֹ����Խ�磬�����Ų��׵ĸ�������������Χ����һȦ
	//���������Ҫ9*9�����̣�������ǲ���11*11������(�������Ҷ�����һȦ)
	//2������Ų�����׵���Ϣ,ʹ��ROWS��COLS��Ϊ�˺�mine����ÿ��Ԫ�ص�λ��һһ��Ӧ
	char show[ROWS][COLS] = { 0 };

	//��ʼ��11*11�����̣�����Ҫ��ʼ����������Ϊ�������룬ע�⺯���Ĵ��κ��β�
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ9*9�����̣�ע�⺯���Ĵ��κ��β�
	//DisplayBoard(mine, ROW, COL);//���ԣ���ʼ���Ƿ�ɹ�
	DisplayBoard(show, ROW, COL);

	//��9*9�����̴�С�ϲ����ף���ΧһȦ������
	setMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//��ӡ�����׵���Ϣ�����ԣ��۲��Ƿ����׳ɹ�

	//ɨ��
	//����������ɨ��
	FindMine(mine, show, ROW, COL);//ע�⺯���Ĵ��κ��β�
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
