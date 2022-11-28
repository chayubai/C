#define _CRT_SECURE_NO_WARNINGS 1

//循环结构--循环语句while/for/do-while
//while循环
//if (1)//这个语句只执行一次	while (1)//执行无数次（死循环）
//{								{
//	语句；			== = >			语句；
//}	
//								}

//while语法结构：
//while (表达式)
//{
//	循环语句；
//}
//当表达式为真时，执行循环语句
// { }代码块同if相同，当while没有{ }时，只管理一行代码

//打印1-10
/*
#include <stdio.h>
int main()
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}
	return 0;
}
*/
//调试观察i的变化

//break和continue在循环语句中的作用：
/*
#include <stdio.h>
int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (i == 5)
			break;
		printf("%d ", i);
		i++;
	}
	//跳出循环，跳到了这里，一个break只能跳出自己的循环
	return 0;
}
*/
//正确结果：1 2 3 4
//通过调试观察可知：在while中，i== 5时遇到break，break后面有语句也不执行，直接跳出循环，永久终止循环
/*
#include <stdio.h>
int main()
{
	int i = 1;
	while (i <= 10)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
		i++;
	}
	return 0;
}
*/
//正确结果：1 2 3 4 后面死循环
//原因分析：调试观察可知：当i == 5时，遇到continue，跳过本次后面的语句，即：跳过了printf("%d ",i)和i++;，继续下一次循环，此时i一直等于5
//在while循环中，continue的作用是跳过本次循环continue后边的代码，直接去判断部分，看是否进行下一次循环
/*
#include <stdio.h>
int main()
{
	int i = 0;
	while (i < 10)
	{
		i++;
		if (i == 5)
			continue;
		printf("%d ", i);
		
	}
	return 0;
}
*/
//正确结果为：1 2 3 4 6 7 8 9 10
//总结break在while循环中的作用：其实在循环中只要遇到break，就停止后期的所有循环，直接终止循环，所以：while中的break适用于永久终止循环的
//总结continue在while循环中的作用：continue是用于终止本次循环的，也就是本次循环中的continue后面的代码不会再执行
//而是直接跳转到while语句的判断部分，进行下一次循环的入口判断

//拓展：
/*
#include <stdio.h>
int main()
{
	int ch = getchar();//getchar接收一个来自键盘输入的字符
	putchar(ch);//输出一个字符，但不会换行。输入字符串，只打印一个字符
	printf("%c\n", ch);//同putchar
	return 0;
}
*/
//打开MSDN工具--win32 API:Platform SDK，输入getchar/putchar
// getc,getwc,getchar,getwchar函数描述:Read a character from a stream(getc,getwc),or get a character from stdin(getchar,getwchar)
// 从一个stream（流）或stdin（标准输入，如：键盘）中获取一个字符
// int getchar(void);返回值类型为int，
// Required Header头文件：<stdio.h>
// Return Value返回值：Each of these functions returns the character read.To indicate an read error or end-of-file condition,
// getc and getchar return EOF,and getc and getwchar return WEOF.For getc and getchar,use ferror of feof to check for an error or for end of file.
//使用int类型接收getchar返回的值，有两点原因：
//1、函数的返回类型为int，且返回的值可能是ASCII值，ASCII本质上是int类型存储的，所以使用int类型接收
//2、函数返回的值可能是EOF,EOF=-1所以，使用int类型接收
//如：
/*
#include <stdio.h>
int main()
{
	char password[20] = { 0 };
	printf("请输入密码：>");
	scanf("%s", password);//输入123456--字符串"123456"
	printf("请确认密码（Y/N）:>");
	int ch = getchar();//调试观察ch可知，ch存放的值为10，即'\n'的ASCII码值
	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}
	return 0;
}
*/
//输入123456，回车显示结果：请确认（Y/N）:>确认失败
//分析原因：数组：本身就是一个地址，不需要加&取地址符。键盘输入123456时，缓冲区相当于123456\n，
//sacnf解释：键盘有一个输入缓冲区，最初，键盘输入缓冲区内容为空，程序等待输入，当输入字符串123456又按了一个回车符，相当于把123456\n放入了缓冲区中，
//而scanf不会读取\n，因此password中为123456
//此时第一次sacnf拿123456放入password中，缓冲区里还有\n，由于缓冲区里面由内容getchar直接拿\n，不等于Y，输出“确认失败”
/*
#include <stdio.h>
int main()
{
	printf("%d",'\n');
	return 0;
}
*/
//结果为：10，说明“\n”的ASCII码值是10
//scanf和getchar输入函数解释：键盘有一个输入缓冲区，最初，键盘输入缓冲区内容为空，程序等待输入，
//当输入一个字符串123456又按了一个回车符，相当于把123456\n放入了缓冲区中，sacnf读取123456打印后，getchar继续读\n打印换行，
//即：回车符，也是字符，getchar也会读取
//此时Y/N，不等待，判断'\n'与'Y'是否相等，不相等输出确认失败
//getchar和putchar是输入输出函数，需要引stdio.h

//分析以下代码：
//代码1：
/*
#include <stdio.h>
int main()
{
	int ch = 0;
	//EOF--enf of file 文件结束标志
	while ((ch = getchar()) != EOF)//运算符优先级
	//VS2019编辑器，单击EOF，选择后，右击鼠标，单击转到定义，查看EOF值为 -1
	{
		putchar(ch);
	}
	return 0;
}
*/
//getchar解释：键盘有一个输入缓冲区，最初，键盘输入缓冲区内容为空，程序等待输入，
//假设当输入一个字符A又按了一个回车符，相当于把A\n放入了缓冲区中，getchar读取A打印后，继续读\n打印换行，即：回车符，也是字符，getchar也会读取
//代码的实际作用：不断输入字符	--相当于可以输入字符串,当输入EOF，也是打印EOF
//想要程序结束，按CTRL+Z，相当于getchar读取到了一个EOF
//实际意义：输入密码，确认密码

//实际意义：（对以上代码的修改）
/*
#include <stdio.h>
int main()
{
	char password[20] = { 0 };
	printf("请输入密码：>");
	scanf("%s", password);//输入123456--字符串"123456"
	//缓冲区剩余一个'\n'
	//读走'\n'，将缓冲区内容变为空
	getchar();//清理缓冲区中的一个字符：处理'\n'
	printf("请确认密码（Y/N）:>");
	int ch = getchar();
	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}
	return 0;
}
*/
//当输入123456 abcd时，输出结果：确认失败
//分析原因：当输入一个字符串123456 abcd又按了一个回车符，相当于把123456 abcd\n放入了缓冲区中，
//而scanf只会读取空格前面的字符串，因此password中为123456，缓冲区还剩余“ abcd\n”
//第一个getchar读取了空格，第二个getchar读取了a
//此时Y/N，不等待，判断'a'与'Y'是否相等，不相等输出确认失败
//对以上代码的修改
/*
#include <stdio.h>
int main()
{
	char password[20] = { 0 };
	printf("请输入密码：>");
	scanf("%s", password);//输入123456 ABCD\n
	//缓冲区剩余多个字符“ abcd\n”
	//读走所有的字符
	//清空缓冲区中多个字符
	int temp = 0;
	while ((temp = getchar()) != '\n')//循环读取字符
	{
		;//空语句
	}
	printf("请确认密码（Y/N）:>");
	int ch = getchar();
	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}
	return 0;
}
*/
//注意：如果输入带空格的密码，实际上是只能读取到空格之前的数据，存入的密码就发生了改变
//总结：scanf只能读取到空格之前的字符，且不会读取\n，如果scanf循环读取，则每次读取的都是空格前后的字符串
//如：1234 56 则第一次读取1234 第二次读取56，不会读取空格。

//代码2：
//只打印0-9范围内的一个字符
/*
#include <stdio.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')//ASCII码值48（'0'）-57（'9'）以外的值不输出
			continue;
		putchar(ch);
	}	
	return 0;
}
*/
//以上代码只会打印数字字符
