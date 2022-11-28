#define _CRT_SECURE_NO_WARNINGS 1
/*1、关于C语言关键字说话正确的是：*/
//A.关键字可以自己创建
//正确答案B.关键字不能自己创建
//C.关键字可以做变量名
//D.typedef不是关键字

/*2、用在switch语言中的关键字不包含哪个？*/
//正确答案A.continue
//B.break
//C.default
//D.if

/*3、下面哪个不是关键字：*/
//A.int
//B.struct
//正确答案C.default //default属于预处理指令
//D.continue

/*4、关于指针说话正确的是：*/
//A.sizeof(char*)大小一定是1
//正确答案B.指针是变量，用来存放地址
//C.指针变量的大小都是4个字节
//D.指针不是变量

/*5、关于static说法不正确的是：*/
//A.static可以修饰局部变量
//B.static可以修饰全局变量
//正确答案C.static修饰的变量不能改变
//D.static可以修饰函数

/*6、下面程序的结果是：*/
/*
#include <stdio.h>
int sum(int a)
{
	int c = 0;//局部变量c，从进入，被创建，到出来后，被销毁
	static int b = 3;//被static修饰的局部变量b，从进入，被创建，到出来，没有销毁
	c += 1;
	b += 2;
	return (a + b + c);//a = 2,b = 5,c = 1// a = 2,b = 7,c = 1
}
int main()
{
	int i;
	int a = 2;
	for (i = 0; i < 5; i++)
	{
		printf("%d,", sum(a));
	}
	return 0;
}
*/
//A.6,8,10,12,14
//正确结果B.8,10,12,14,16
//C.10,12,14,16,18
//D.12,14,16,18,20

/*6、下面代码执行的结果是：*/
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)//判断条件恒成立
	{
		if (i = 5)
			printf("%d ", i);
	}
	return 0;
}
*/
//A.1 2 3 4 5 6 7 8 9 10
//B.5 5 5 5 5 5 5 5 5 5 
//正确结果C.死循环的打印5
//D.0 1 2 3 4 5 6 7 8 9 

/*7、关于if语句说法正确的是：*/
//A.if语句后面只能跟一条语句
//B.if语句中0表示假，1表示真
//正确结果C.if语句是一种分支语句，可以实现单分支，也可以实现多分支
//D.else语句总是和它的对齐的if语句匹配

/*8、关于switch说法不正确的是：*/
//A.switch语句中的default子句可以放在任意位置
//B.switch语句中的case后的表达式只能是整型常量表达式
//正确结果C.switch语句中的case子句必须在default子句之前
//D.switch语句中的case表达式不要求顺序

/*9、下面代码执行的结果是：*/
/*
#include <stdio.h>
int func(int a)
{
	int b;
	switch (a)
	{
	case 1:
		b = 30;
	case 2:
		b = 20;
	case 3:
		b = 16;
	default:
		b = 0;
	}
	return b;
}
int main()
{
	printf("%d\n", func(1));
	return 0;
}
*/
//A.30
//B.20
//C.16
//正确结果D.0 

/*10、switch(c)语句中，c不可以是什么类型*/
//A.int
//B.long  
//C.char
//正确结果D.float 

/*11、下面代码执行的结果是：*/
/*
#include <stdio.h>
int main()
{
	int x = 3;
	int y = 3;
	switch (x % 2)
	{
	case 1:
		switch (y)
		{
		case 0:
			printf("first");
		case 1:
			printf("second");
			break;
		default:
			printf("hello");
		}
	case 2:
		printf("third");
	}
	return 0;
}
*/
//A.secondthird
//B.hello
//C.firstsecond
//正确结果D.hellothird

/*12、写代码将三个数按从大到小输出*/
//思路：三个数两两比较，找到两个较大值，再两个较大值中比较，确定次小值和最小值
//即：a < b 则b的值大，a < c 则c的值大，b < c 则c的值最大，b的值次之，a的值最小
//由于三个变量的值不确定，都有可能是最大值或中间值或最小值，可以固定用某变量存储最大值，中间值，最小值
/*
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);//scanf中不加空格和加空格，输入的格式都一样。
	//通过调整顺序实现：a放最大值，b次之，c放最小值
	if (a < b)
	{//a与b比较，若b大，则a和b的值互换，此时a和b中，a的值较大。
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{//a与c比较，若c大，则a和c的值互换，此时a和c中，a的值较大。
	 //a，b，c中，a的值为最大值
		int temp = a;
		a = c;
		c = temp;
	}
	if (b < c)
	{//b与c比较，若c大，则b和c的值互换，此时b和c中，b的值次之，c的值为最小值
		int temp = b;
		b = c;
		c = temp;
	}
	//假设以a，b，c的方式打印，则a最大，b次之，c最小
	printf("%d %d %d",a,b,c);
	return 0;
}
*/
//方法二：写一个函数，调用三次

/*13、写一个代码打印1-100之间所有3的倍数的数字*/
//思路：循环从1-100中判断，除以3，余数是否为0。若为0，则为3的倍数
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{//判断i是否为3的倍数
		if (i % 3 == 0)
			printf("%d ", i);
	}
	return 0;
}
//方法二：
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 3; i <= 100; i+=3)
	{
			printf("%d ", i);
	}
	return 0;
}
*/

/*14、给定两个数，求这两个数的最大公约数*/
//思路：
//方法一：试除法
//找出数字同时整除这两个数的数，如24 18，然后要那个最大的数
//最大公约数不会超过其中这两个数的较小的数
//先找出其中的较小值，除以这两个数，如果不能同时整除这俩个数，则从较小值依次减减，再除以这两个数是否整除，直到整除，
//当第一次找到能同时整除这两个数的数，则这个数一定是最大公约数
/*
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int max = 0;//用来存最大公约数和两个数的较小的数
	//假设最大公约数就是m和n的较小数
	//int max = m > n ? n : m;
	if (m > n)
		max = n;
	else
		max = m;

	while (1)
	{
		if (m % max == 0 && n % max == 0)
		{
			printf("最大公约数是：%d\n", max);
			break;
		}
		//不能同时整除，则（从大到小）找下一个数
		max--;
	}

	return 0;
}
*/

//类比：求最小公倍数
//找出数字同时被这两个数整除的数，如24 18，然后要那个最小的数
//最小公倍数一定会超过其中这两个数的较大的数
//先找出其中的较大值，然后被这两个数除以，如果不能同时被这两个数整除，则从较大值依次加加，然后被这两个数除以再是否整除，直到整除，
//当第一次找到能同时被这两个数整除的数，则这个数一定是最小公倍数
/*
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int min = 0;//用来存最小公倍数和两个数的较大的数
	//假设最小公倍数就是m和n的较大数
	if (m > n)
		min = m;
	else
		min = n;

	while (1)
	{
		if (min % n == 0 && min % m == 0)
		{
			printf("最小公倍数是：%d\n", min);
			break;
		}

		//这种写法是错误的，因为min在min * n == min * m执行前就已经计算出来了，min * n == min * m两个不同的数乘以一个相同的数结果永远为假
		//if ((min != 0) && (min * n == min * m))
		//{
		//	printf("最小公倍数是：%d\n", min);
		//	break;
		//}
		
		//不能同时被整除，则（从大一直）找下一个数
		min++;
	}

	return 0;
}
*/
//除此之外，求最小公倍数的公式：最小公倍数 = m * n / 最大公约数
//使用求最小公倍数的公式，然后将求最大公约数进行封装成一个函数后，进行调用

//方法二：辗转相除法：m % n若余数不为零，则将n作为被除数，余数作为除数，取模是否为0，不为零则继续以上操作，直到余数为0，则除数为最大公约数
/*
#include <stdio.h>
int main()
{
	int m = 24;
	int n = 18;
	int r = 0;//保存余数
	scanf("%d%d", &m, &n);//输入的两个数m和n，在运算过程中，第二次会互换大小，故无大小顺序
	while (m % n) //余数为0，条件为假，则结束循环
	{
		r = m % n;
		m = n;
		n = r;
	}
	printf("%d\n", n);
	return 0;
}
*/
//程序优化：
/*
#include <stdio.h>
int main()
{
	int m = 24;
	int n = 18;
	int r = 0;
	scanf("%d%d", &m, &n);
	while (r = m % n)
	{	
		m = n;
		n = r;
	}
	printf("%d\n", n);
	return 0;
}
*/

/*14、打印1000年-2000年之间的闰年*/
//思路：判断某一年是否为闰年，再循环判断1000-2000各个年份是否为闰年
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;//不能放在判断语句里
	for (year = 1000; year <= 2000; year++)
	{
		//判断year是否为闰年
		//1.能被4整除并且不能被100整除是闰年
		//2.能被400整除是闰年
		//int count = 0;//不能放在这里，则打印count的结果报错：“count”未声明的标识符
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount = %d\n",count);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 == 0))
		{
			printf("%d ", year);
			count++;

		}
	}
	printf("\ncount = %d\n",count);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if(year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d ", year);
				count++;
			}
		}
		if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount = %d\n",count);
 
	return 0;
}
*/

/*15、写一个代码：打印100-200之间的素数*/
//思路：判断某一数是否为素数，再循环判断100-200各个数是否为素数
//方法一：试除法：判断素数
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		//判断i是否为素数
		//素数判断的规则：只能被1和它本身整除 
		//产生2-（i-1）的数字，取试除i，看能不能整除
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}		
		}
		//跳到这里
	 	if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/
//程序优化：
//i = a * b
//16 = 2 * 8 = 4 * 4，当判断2整除16，就不需要判断8是否整除16了，减少了判断次数
//即：a/b中至少一个数字 <= 开平方i
/*
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		//判断i是否为素数
		//素数判断的规则
		//产生2-（i-1）的数字，除以i
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)//开根号sqrt--math.h
		{
			if (i % j == 0)
			{
				break;
			}		
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/
//再优化：
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)//将偶数直接剔除
	{		
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/

//方法二：标签法
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)//将偶数直接剔除
	{		
		int j = 0;
		int flag = 1;//假设i就是素数
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;//如果i不是素数，改变它的值
				break;
			}
		}
		if (flag == 1)//flag的值没有改变，说明：i是素数
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/