#define _CRT_SECURE_NO_WARNINGS 1
//有字符类型char，但没有字符串类型，如何表示（描述）字符串信息？如何存储？此刻引入了数组，即将字符串放入字符数组内。
//注意;将相同整型类型的数据放入整型数组内。将字符串放入字符数组内。

//字符串：字符串就是一串字符，用双引号括起来的一串字符
//如：“123”、“abc”、“”                
//字符串的结束标志是一个\0的转义字符
//字符串就是一串字符，即多个字符
//如何将字符串（多个字符）存入内存中	——字符数组

//数组：是一组相同类型的元素
/*
#include <stdio.h>
int main()
{	//按Fn+F10
	char arr[] = "hello";//再按F10--arr中有6个元素

	return 0;
}
*/
//按Fn+F10调试，每按一次F10，逐句运行，观察每个过程的执行结果
//点击“调试”选项卡、单击“窗口”、选择“监视”再选择任意监视、在“添加要监视的项”，输入“arr”单击向右的三角形
//字符串在结尾的位置隐藏了一个\0的字符，\0是字符串的结束标志

//验证\0是字符串的结束标志
/*
#include <stdio.h>
int main()
{
	char arr1[] = "abc";//双引号引起来的是一串字符--字符串
	char arr2[] = {'a','b','c'};//单引号引起来的是一个字符
	char arr3[] = { 'a','b','c','\0' };
	//打印字符串，并通过监视观察arr1和arr2中的元素个数
	printf("%s\n", arr1);//打印abc---arr1有四个元素
	printf("%s\n", arr2);//打印abc烫烫烫烫蘟bc---arr2有三个元素
	printf("%s\n", arr3);//%s打印字符串---打印abc

	return 0;
}
*/
//分析结果：F10调试
//arr1中第四个字符是\0，打印结束。
//arr2中第四个字符未知，直到遇到\0字符打印结束
//当加入字符'\0'（ASCII码值为0）或者数字0，此时打印abc
//"...":字符串中的\0也算一个元素
//{'.','.',','}:一个字符算一个元素

//又如：
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//求字符串的长度
	//int len = strlen("abc");//strlen()--string length

	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	char arr3[] = { 'a','b','c','\0'};
	printf("%d\n", strlen(arr1));//字符串的长度为3、四个元素
	printf("%d\n", strlen(arr2));//字符串的长度为随机值、三个元素（没有\0，则长度随机）
	printf("%d\n", strlen(arr3));//字符串的长度为3、四个元素
	return 0;
}
*/
//"strlen"未定义问题：没有引用头文件#include <string.h>
//strlen求字符串的长度，不是元素的个数。元素个数包括\0，长度不包括\0
//sizeof求变量或类型的空间大小外，也可以求数组元素个数
//\0作为结束标志，计算字符串的长度时，不计入长度，不算字符串的内容（算元素，不算长度）
//求字符串数组的元素的个数会计算\0
//"...":计算字符串的长度，不算\0
//{'.', '.', '.'}:字符串的长度为随机值
//{'.', '.', '.',...'\0'}:字符的元素个数 - 1，即为字符串的长度

//转义字符：
/*
#include <stdio.h>
int main()
{
	printf("(are you ok??)");//		??)--三字母词，C++6.0软件会转义为],现今很多编译器不支持
	printf("(are you ok\?\?)");//	\?转义为？
	printf("%c", 'a');
	printf("%c", '\'');//	\'转义为'
	printf("%s", "\"");//	\"转义为"
	printf("%s", "'");//	单引号或双引号成对出现，会被成对解析
	printf("c:\\test\\32\\test.c");//	\\转义为\
	//	\ddd：ddd表示1~3个八进制的数字，如：\130
	//	\xdd：dd表示1~2个十六进制数字，如：\x30
	printf("%c\n", '\130');//八进制的130是十进制的多少？//88--X的ASCII码值是88
	printf("%c\n", '\101');//A--65--八进制是101
	printf("%c\n", '\x30');//十六进制30--ASCII码值是十进制48--对应字符'0'

	printf("%c\n", 65);
	printf("%c\n", 0101);
	printf("%c\n", 0x41);
	//ASCII 'A'的十进制表示65 八进制表示101 十六进制表示41
	//0101 = 0x41 = 65 = 'A' 字符'\101' = 'A' 字符'\x41' = 'A'
	//将八进制或十六进制转义为对应十进制表示的字符
	//转义字符：
	//'\ddd'字符的八进制 ddd表示1~3个八进制的数字
	//'\xdd'字符的十六进制 dd表示1~2个十六进制的数字
	//一个ASCII占1个字节，故十进制表示范围0 - 255,八进制表示范围0000 - 0377，十六进制表示范围0x00 - 0xFF
	//故八进制转义字符最多使用3个d，十六进制转义字符最多2个d

	//printf("%d\n", '');//报错，''内至少有一个字符
	return 0;
}
*/
/*区分：'\0', 0, '0', EOF*/
// '\0' 转义字符，ASCII码值为0
//   0  数字0，相当于'\0'
//  '0' 字符0，ASCII码值为48
// EOF  文件结束标志，是一个宏定义，值为-1

//'\0' ASCII = 数字0 空字符  NULL = 0
//空格 ASCII = 32  即' ' ASCII = 32

//笔试题：
/*1、程序输出什么？*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    printf("%d\n", strlen("abcdef"));//6--\0不算长度，算元素
    // \62被解析成一个转义字符
    printf("%d\n", strlen("c:\test\628\test.c"));//14
    return 0;
}
*/
/*2、下面代码执行的结果是：*/
/*
#include <stdio.h>
int main()
{
	char arr[] = { 'b','i','t' };
	printf("%d\n", strlen(arr));

	return 0;
}
*/
//A.3
//B.4
//正确结果C.随机值
//D.5

//注释：
//VS快捷键注释：Ctrl+K+C、取消注释：Ctrl+K+U
//注释分为：
//（1）//--C++风格
//（2）/*...*/--C风格---不支持嵌套注释
//例如：
#include <stdio.h>
//定义一个加法函数
int add(int x, int y) 
{
	return x + y;
}
/*定义一个减法函数*/
int sub(int x, int y)
{
	return x - y;
}
int main()
{
	//调用add()
	printf("%d\n", add(1, 2));
	/*调用sub()*/
	printf("%d\n", sub(5, 1));

	return 0;
}