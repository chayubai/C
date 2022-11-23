#define _CRT_SECURE_NO_WARNINGS 1
//变量的作用域

//局部变量的作用域：
/*
#include <stdio.h>
int main()
{
	int num = 0;
	printf("%d\n", num);//程序可以运行，说明num的作用域在{ }里可以使用
	//即num的作用域就是主函数{ }内
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	{
		int num = 0;
	}
	
	printf("%d\n", num);//程序不能运行，报错：num未声明的标识符,说明num的作用域在所在的{ }里可以使用
	//即num的作用域在主函数{ }内的{ }内
	return 0;
}
#include <stdio.h>
int main()
{
	{
		int num = 0;
		printf("%d\n", num);
	}
	//此时，程序可以运行
	return 0;
}
*/

//全局变量的作用域：
/*
#include <stdio.h>
int g_val = 2021;//全局变量
//printf("2:%d\n", g_val);//错误，执行性语句须放在函数里

int main()
{
	printf("1:%d\n", g_val);//全局变量的作用域：整个工程
	printf("打印字符a\n");
	{
		int a = 10;//局部变量
		printf("a = %d\n", a);//局部变量的作用域：就是变量所在的局部范围
		printf("2:%d\n", g_val);//全局变量的作用域：整个工程
	}
	//printf("a = %d", a);//运行报错，局部变量的作用域：就是变量所在的局部范围
	printf("3:%d\n", g_val);//全局变量的作用域：整个工程

	return 0;
}
*/

//又如：
//1、跨函数使用全局变量
/*
#include <stdio.h>
int global = 2020;//全局变量
 void test()
 {
	printf("test()-%d\n",global);//全局变量的作用域：整个工程
 }
int main()
{
	test();
	printf("%d\n",global);//全局变量的作用域：整个工程

	return 0;
}
*/

//2、跨文件使用全局变量
//创建add.c文件	//视图-解决方案资源管理器-源文件-新建项-C++文件（.cpp）-名称以.c结尾
//①在add.c文件中添加“int g_val = 2022;”在其他.c文件中（打印）使用变量g_val。
/*int g_val = 2022;//g_val是全局变量*/
//②test.c文件 //在test.c文件中使用g_val,此时报错：“g_val”：未声明的标识符
/*
#include <stdio.h>
int main()
{
	printf("g_val = %d", g_val);
	return 0;
}
*/
//报错：“g_val”：未声明的标识符

//程序修改：
/*
#include <stdio.h>
//extern声明外部符号
extern int g_val;//调用add.c文件（外部文件）的变量，须对该变量进行声明
int main()
{
	printf("g_val = %d", g_val);//程序正常运行
	return 0;
}
*/

//变量的生命周期：变量的创建到销毁之间的时间段
/*
#include <stdio.h>
int main()//全局变量的生命周期是（main函数的生命周期）整个程序的生命周期
{
	{//进入局部范围生命开始
		int a = 10;//局部变量
		printf("%d\n", a);//局部变量的生命周期是：进入局部范围生命开始，出局部范围生命结束
	}//出局部范围生命结束
	//printf("%d\n", a);//报错，变量a出局部范围生命结束
	 
	return 0;
}
*/

//例如：
/*
#include <stdio.h>
void test()
{
	int b = 20;//局部变量的作用域在test()函数里
}
int main()
{
	int a = 10;//局部变量的作用域在main函数里

	return 0;
}
*/