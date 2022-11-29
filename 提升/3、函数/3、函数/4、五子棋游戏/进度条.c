#define _CRT_SECURE_NO_WARNINGS 1
//进度条
//原理：先显示#，在把光标回到最开始，再输出#，再光标回到最开始…，即不断打印，不断回车。既有覆盖，又有增加
//光标旋转：在同一个位置，不同形态的更新设置:[ | ][ / ][ - ][ \ ]

#include <stdio.h>
#include <string.h>
#include <windows.h>
void process_bar()
{
	char bar[101];//这里是101，为了打印从0-100显示，下标必须为0-100
	memset(bar, '\0', sizeof(bar));
	const char* lable = "|/-\\";//注意：这里会把‘\\’当做一个字符
	
	int i = 0;
	while (i <= 100)
	{
		//[                 ###############][53%]
		//printf("[%100s]\r", bar);//这里由于是需要预留空间的，%100s，默认100个位，不足的前面补空格
		//[###############                 ][53%]
		printf("[%-100s][%-3d%%][%c]\r", bar, i, lable[i % 4]); // 这里覆盖，故使用%-100s，表示数据左对齐，不足位数右边补空格
		fflush(stdout);//立即刷新缓冲区
		bar[i] = '#';//这里增加
		i++;
		Sleep(1);//单位秒
	}
	printf("\n");//如果没有这一行，则结果是##############################][100%]
	//这一行的目的是，回车并换行显示
}
int main()
{
	process_bar();
	return 0;
}


//倒计时
//#include <stdio.h>
//#include <windows.h>
//void process_bar()
//{
//	int i = 10;
//	while (i >= 0)
//	{
//		printf("%d\r", i);
//		fflush(stdout);
//		i--;
//		Sleep(1);//单位秒
//	}
//	printf("hello Makefile!");
//	fflush(stdout);
//	Sleep(1);
//}
//int main()
//{
//	process_bar();
//	return 0;
//}