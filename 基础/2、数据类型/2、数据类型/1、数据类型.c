#define _CRT_SECURE_NO_WARNINGS 1

//数据类型：计算机语言必须有能力描述生活中的问题，如书架上有十本书
/*
int main()
{	//类型的使用：类型名 变量名/空间名 = 初值;
	int Book = 10;//开辟一块内存空间，空间名为Book，把10存入空间内
	printf("%d");
	//字符数据类型---单引号引起的内容
	char ch = 'a';
	printf("%c",ch);
	//短整形---整数
	short int num = 10;
	//整型---整数
	int age = 20;
	//短整形 short int、长整型long int、更长的整型long long int，其中int都可以省略
	//整型有多种不同类型的区别在于空间大小，而打印格式都是%d
	//单精度浮点型---小数
	float weight = 55.5;
	//双精度浮点型---小数
	double d = 0.0;

	return 0;
}
*/
//%d打印整型十进制数据，%c打印字符格式的数据
//%f打印单精度浮点数字（小数），%p以地址的形式打印
//%lf打印双精度浮点数

//问题：每一种类型的大小是多少？
#include <stdio.h>
int main()
{
	//sizeof关键字--操作符
	printf("%d\n", sizeof(char));//1byte
	printf("%d\n", sizeof(short));//2byte  可存的最大值2^16-1
	printf("%d\n", sizeof(int));//4byte	 可存的最大值2^32-1
	printf("%d\n", sizeof(long));//4/8byte   	
	printf("%d\n", sizeof(long long));//8byte  可存的最大值2^64-1
	printf("%d\n", sizeof(float));//4byte
	printf("%d\n", sizeof(double));//8byte

	return 0;
}
//解读：
//sizeof()：计算数据类型或者变量所占空间的大小，单位：字节byte
//C语言标准规定：sizeof(long) >= sizeof(int)，故long类型所占字节因计算机而异。
//同一种类型的有符号和无符号所占字节数相同

//问题：为什么出现这么多种整型类型？
//原因：类型的选择性多，对空间的利用率更高。
//如，存一个年龄的数据，选择short类型开辟的空间需要2字节，选择int类型开辟的空间需要4字节，故选择合适的类型，有利于节省空间
//不同类型创建的变量，具有不同的空间大小，即存放的数据最大值不同

//问题：C语言有没有字符串类型？
//答：没有，C语言使用数组来存放字符串