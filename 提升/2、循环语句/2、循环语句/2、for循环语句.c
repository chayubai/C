#define _CRT_SECURE_NO_WARNINGS 1

//while循环的缺点
//while结构的特点
/*
#include <stdio.h>
int main()
{
	int i = 0;//定义变量部分
	i = 1;//循环变量的初始化
	while (i < 10)//循环变量的判断
	{
		//...
		i++;//循环变量的调整
	}
	return 0;
}
*/
//当代码越来越多时，初始化、判断部分、调整部分会分离，不易于代码维护

//for循环
//for循环语法结构：
//for (表达式1;表达式2;表达式3)
//{
//	循环语句;
//}
//表达式1为初始化部分，用于初始化循环变量,表达式2为条件判断部分，用于判断循环终止次数，表达式3为调整部分，用于循环条件的调整
//表达式1只执行一次

//用for循环打印1-10
/*
#include <stdio.h>
int main()
{
	int i = 0;//定义变量部分，并赋值0
	for (i = 1; i <= 10; i++)//变量初始化，判断部分，调整部分
	{
		printf("%d ", i);
	}
	return 0;
}
*/

//for循环中的break和continue
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1;i <= 10;i++)
	{
		if (i == 5)
			break;
		printf("%d ", i);
	}
	return 0;
}
*/
//调试观察可知：与while循环中的break一致，结果为：1 2 3 4
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1;i <= 10;i++)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
	}
	return 0;
}
*/
//结果为 1 2 3 4 6 7 8 9 10，while循环中的continue不同
//原因：for循环中跳过continue后的代码后，会继续i++，而while循环中的i++不会执行

//for语句的循环控制变量：
//一些建议：
//1、不可在for循环体内修改循环变量，防止for循环失去控制。
//如：
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i = 5)//修改了循环变量
			printf("haha\n");
		printf("hehe\n");//这行代码任何情况下都会执行
	}
	return 0;
}
*/
//此结果为死循环：输入haha hehe haha hehe haha ... hehe haha hehe...
//2、建议for语句的循环控制变量的取值采用“前闭后开区间”写法。不是绝对
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)//i = 0是闭区间，i< 10是开区间
	{
		printf("%d ", arr[i]);
	}
	return 0;
}//10次循环，10次打印，10个元素
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i <= 9; i++)//前闭后闭区间
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//一些for循环的变种：
//#include <stdio.h>
//int main()
//{
	//变种1
	//for (;;)//当【判断部分】的省略，即判断条件恒为真---死循环
	//{
	//	printf("hehe\n");
	//}
	//for循环的初始化部分，调整部分，判断部分都可以省略或部分省略，但不建议省略
	/*----------------------------------------------------*/
	/*int i = 0;
	//int j = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;//放里面放外面都一样，因为每次进入第二个for循环，都会初始化为0
		for (j = 0; j < 3; j++)
		{
			printf("hehe\n");
		}
	}*/
	//正确结果：打印3 * 3 = 9个竖排的hehe
	/*----------------------------------------------------*/
	/*int i = 0;
	int j = 0;
	for (; i < 3; i++)
	{
		for (; j < 3; j++)
		{
			printf("hehe\n");
		}
	}*/
	//正确结果：打印3个竖排的hehe
	//原因分析：即 i = 0时，里层循环执行了3次。j是局部变量，当第二次内循环时，j 不等于0，而是j = 3，最终外循环执行三次，内循环后两次不打印
	/*int i = 0;

	for (; i < 3; i++)
	{
		int j = 0;
		for (; j < 3; j++)
		{
			printf("hehe\n");
		}
	}*/
	//正确结果：打印9个竖排的hehe
	/*int i = 0;
	int j = 0;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			printf("hehe\n");
		}
	}*/
	//所以最好不要省略
//	return 0;
//}

/*
#include <stdio.h>
int main()
{
	//变种2
	int x, y;
	for (x = 0, y = 0; x < 2 && y < 5; ++x，y++)//逗号表达式
	{
		printf("hehe\n");
	}
	return 0;
}
*/
//结果打印2个hehe

//练习：
//请问循环几次？
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)//逗号运算符
		k++;
	return 0;
}
*/
//循环0次，因为判断部分k=0,结果为0，条件为假，不进入循环
//对于逻辑表达式的结果，只有两种：为真，则值为1，为假，则值为0
//对于什么情况下为真为假？表达式最终结果为非0为真，0为假