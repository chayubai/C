#define _CRT_SECURE_NO_WARNINGS 1
//作业
//1、模拟实现strstr
//2、模拟实现memcpy
//3、模拟实现memmove
//4、课堂代码练习与本主题博客(课堂代码的编写、涉及到的核心知识点整理、以博客链接方式)

//5、在VS2013下，这个结构体所占空间大小是多少个字节：
//typedef struct 
//{
//	int a;//4  0-3
//	char b;//1  4
//	short c;//2  +1 5   6-7
//	short d;//2  8-9
//}AA_t;//12
//int main()
//{
//	printf("%d\n", sizeof(AA_t));
//	return 0;
//}
//A、16
//B、9
//正确答案C、12
//D、8

//6、在32位系统环境下，编译选项为4字节对齐（默认对齐数为4），那么sizeof(A)和sizeof(B)是：
//struct A
//{
//	int a;//4   0-3 
//	short b;//2  4-5
//	int c;//4  +2 6-7  8-11
//	char d;//1  12
//};//16
//struct B
//{
//	int a;//4   0-3
//	short b;//2  4-5
//	char c;//1  6
//	int d;//4  +1 7  8-11
//};//12
//A、16 16
//B、13 12
//正确答案C、16 12
//D、11 16

//6、下面代码的结果是：
//#pragma pack(4)/*编译选项，表示4字节对齐*/
//#include <stdio.h>
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;//2  0-1
//		char d;//1  2
//		long b;//4  +1 3 4-7  
//		long c;//4  8-11  
//	};//12
//	struct tagTest2
//	{
//		long b;//4  0-3
//		short c;//2 4-5
//		char d;//1 6
//		long a;//4 +1 7  8-11
//	};//12
//	struct tagTest3
//	{
//		short c;//2  0-1
//		long b;//4  +2 2-3 4-7
//		char d;//1 8
//		long a;//4 +3 9-11 12-15
//	};//16
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//
//	return 0;
//}
//#pragma pack()
//A、12 12 16
//B、11 11 11
//C、12 11 16
//D、11 11 16