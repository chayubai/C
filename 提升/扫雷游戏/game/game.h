
//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��������:�׵����̴�С
#define ROW 9
#define COL 9
//��������:����һȦ��Χ���׵����̴�С
#define ROWS ROW+2
#define COLS COL+2
//�����������׵�����
#define EASY_COUNT 10

//������������ʼ����ע�⺯���Ĵ��κ��β�
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//������������ӡ���̣�ע�⺯���Ĵ��κ��β�
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//����������������
void setMine(char board[ROWS][COLS], int row, int col);
//����������ɨ�ף�ע�⺯���Ĵ��κ��β�
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);