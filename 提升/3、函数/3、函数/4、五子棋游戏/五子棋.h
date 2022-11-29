#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

//行
#define ROW 20
//列
#define COL 20

//用户1，落的子为1
#define PLAYER1 1
//用户2，落的子为2
#define PLAYER2 2

//游戏结果的四个状态
#define NEXT 0//游戏继续
#define PLAYER1_WIN 1//用户1赢了
#define PLAYER2_WIN 2//用户2赢了
#define DRAW 3 //平局

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
