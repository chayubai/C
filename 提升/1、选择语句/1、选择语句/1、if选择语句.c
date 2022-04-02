#define _CRT_SECURE_NO_WARNINGS 1

//C语言是结构化的程序设计语言！
//顺序结构
//什么是语句？C语言中由一个分号；隔开的就是一条语句，如：; 空语句、1 + 2；
//#include <stdio.h>
//int main()
//{
//	;//空语句
//	return 0;
//}

//选择结构--分支语句if/switch
//C语言是如何表示真和假的呢？非0表示真，0表示假
//表达式为真时，语句执行
//1、单分支语句
//语法结构：
//if(表达式)
//	语句；

//例子：
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age < 18)
//		printf("未成年\n");
//	return 0;
//}

//2、双分支语句
// 语法结构：
//if(表达式)
//	语句1；
//else
//	语句2；

//例子1：
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("未成年\n");
//	else
//		printf("成年\n");
//	return 0;
//}
// 

//例子2：
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age >= 18)
//		printf("成年\n");
//	else 
//		printf("未成年\n");
//		printf("不能谈恋爱\n");
//
//	return 0;
//}
//分析代码:
//执行结果：
// 成年
// 不能谈恋爱

//总结：
//没有大括号，只能管理一条语句.若要控制多条语句，用大括号限制范围.
// 如果条件成立，要执行多条语句，应该使用代码块，一对{ }就是一个代码块
//#include <stdio.h>
//int main()
//{
//	if (表达式)
//	{
//		语句列表1；
//	}
//	else
//	{
//		语句列表2；
//	}
//	return 0;
//}
//如：单分支语句
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age < 18)
//	{
// 		printf("未成年\n");
//	}
//	return 0;
//}
//又如：双分支语句
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//	{
//		printf("未成年\n");
//	}
//	else
//	{
// 		printf("成年\n");
//	}
//	return 0;
//}
//修改后的代码：
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	if (age >= 18)
//	{
//		printf("成年\n");
//	}
//	else
//	{
//		printf("未成年\n");
//		printf("不能谈恋爱\n");
//	}
//	return 0;
//}
//再如：多分支语句
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//	{
//		printf("少年\n");
//	}
//	else if(age > 18 && age < 26)
//	{
//	 	printf("青年年\n");
//	}
//	return 0;
//}

//3、多分支语句
//语法结构：
//if(表达式1)
//	语句1；
//else if(表达式2)
//	语句2；
//else
//	语句3；

//例子： 
//#include <stdio.h>
//int main()
//{
//	int age = 60;
//	if (age < 18)
//		printf("少年\n");
//	else if (18 <= age < 26)
//		printf("青年\n");
//
//	return 0;
//}
//打印结果：青年
//分析结果：
//age = 60，则，18 <= age 满足条件，为真结果为1。1 < 26满足条件，结果为真，执行语句，打印“青年”
//修改代码：
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("少年\n");
//	}
//	//else if (age >= 18 && age < 26)
//	else if (18 <= age && age < 26)//此方式可以减少bug
//	{
//		printf("青年\n");
//	}
//	else if (age >= 26 && age < 40)
//	{
//		printf("中年\n");
//	}
//	else if (age >= 40 && age < 60)
//	{
//		printf("壮年\n");
//	}
//	else if (age >= 60 && age < 100)
//	{
//		printf("老年\n");
//	}
//	//else
//	//{
//	//	printf("老不死\n");//最后一个else可以不写，else非必须
//	//}
//	return 0;
//}

//if嵌套
//#include <stdio.h>
//int main()
//{
//	int age = 60;
//	if (age < 18)
//		printf("少年\n");
//	else
//	{
//		if (18 <= age < 26)
//			printf("青年\n");
//	}
//	return 0;
//}

//悬空else
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//	else
//		printf("haha\n");
//	return 0;
//}
//输出结果:空
//分析代码：
//a = 0不等于1，结果为假
//总结：
//else 与最近未匹配的if进行匹配
//上述代码等同于
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	return 0;
//}
//也等同于单分支语句
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	return 0;
//}
//结果：hehe
//总结：正规的代码书写很重要，适当使用{ }可以使代码的逻辑更加清楚
//改正：
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//		{
//			printf("hehe\n");
//		}
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//如：
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if (num == 5)//= 赋值符号，== 判断相等
//	{
//		printf("hehe\n");
//	}
//}
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if (num = 5)//代码没有报错
//	{
//		printf("hehe\n");
//	}
//}
//建议常量放在左边，书写成if(5 == num)，当误写了一个“=”时，就会报错，代码书写更好，减少代码失误，易于检查代码
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if(5 == num)
//	{
//		printf("hehe\n");
//	}
//}


//if书写形式的对比
//1、代码1
//if (condition) {
//	return x;
//}
//return y;
//2、代码2
//if (condition)
//{
//	return x;
//}
//else
//{
//	return y;
//}
//代码1和代码2表达的意思相同，即：条件满足返回x，条件不满足返回y。因为只能有一个返回值
//例如：
//#include <stdio.h>
//int test() 
//{
//	if (1)
//		return 0;
//	printf("hehe\n");
//	return 1;
//}
//int main()
//{
//	test();
//	return 0;
//}
//结果：空，返回0，不执行printf语句和return 1；
//总结：代码风格对可读性很重要
//#include <stdio.h>
//int test()
//{
//	if (0)
//		return 0;
//	//printf("hehe\n");
//	return 1;
//}
//int  main()
//{
//	test();
//	return 0;
//}
//结果：空，返回0--主函数返回0
//调试查看函数体的执行过程，按Fn+F11
 
//练习：
/*1、判断一个数是否为奇数*/
//思路：判断除以2之后，余数（取模）是否为0，不为0则是奇数，否则是偶数
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 != 0)
//	{
//		printf("%d是奇数", num);
//	}
//	return 0;
//}

/*2、输出1-100之间的奇数*/
//思路：循环判断1-100的数是否为奇数
//#include <stdio.h>
//int main()
//{
	/*int num = 0;
	int count = 0;
	for (num = 1; num <= 100; num++)
	{
		if (num % 2 == 1)
		{
			printf("%d ", num);
			count++;
		}
	}
	printf("\ncount = %d\n", count);*/

	/*for (num = 1; num <= 100; num += 2)
	{
		printf("%d ", num);
	}*/
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 1;
//	while (num <= 100)
//	{
//		printf("%d\n", num);
//		num += 2;
//	}
//	return 0;
//}

//注意在for循环中，变量的定义和初始化
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	for (int num = 1; num <= 100; num++)
//	//在（ ）内定义变量是C++风格，且支持C99标准的编译器才支持这种定义
//	{
//		printf("%d ", num);
//	}
//	return 0;
//}

//练习：
/*判断一个整数是否能被5整除*/
//输入描述：输入包括一个整数M(1 <= M <= 100000)
//输出描述：输出包括一行，如果M可以被5整除就输出YES，否则输出NO
//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	if (m % 5 == 0)
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}