#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

//��
#define ROW 20
//��
#define COL 20

//�û�1�������Ϊ1
#define PLAYER1 1
//�û�2�������Ϊ2
#define PLAYER2 2

//��Ϸ������ĸ�״̬
#define NEXT 0//��Ϸ����
#define PLAYER1_WIN 1//�û�1Ӯ��
#define PLAYER2_WIN 2//�û�2Ӯ��
#define DRAW 3 //ƽ��

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN,
};

void Menu();
void process_bar();
void Game();
