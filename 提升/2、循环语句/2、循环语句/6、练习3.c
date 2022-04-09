#define _CRT_SECURE_NO_WARNINGS 1
/*1、关于while(条件表达式)循环体,以下叙述正确的是（)﹖（假设循环体里面没有break,continue，return，goto等等语句)*/
//A.循环体的抵行次数总是比条件表达式的执行次数多一次
//正确答案B.条件表达式的执行次数总是比循环体的执行次数多一次
//C.条件表达式的执行次数与循环体的执行次数一样
//D.条件表达式的执行次数与循环体的执行次数无关

/*2、有以下程序，程序输出的结果是：*/
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20)
//			break;
//		if (b % 3 == 1) //1 4 7 10 13 16 19 22
//		{				//1 2 3  4  5  6  7  8
//			b = b + 3;//永远不会执行
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//
//	return 0;
//}
//A.10
//B.9
//正确结果C.8
//D.7

/*3、编写程序数一下1-100的所有整数中出现多少个数字9*/
//思路：
//		1、个位为9：模10，余9
//		2、十位为9：除10，商9
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		else if (i / 10 == 9)
//			count++;
//	}
//	printf("count = %d\n", count);
//	return 0;
//}
//9 19 29 39 49 59 69 79 89 99
//90 91 92 93 94 95 96 97 98 99
//共计20个（99算2个9）

//程序修改：
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100.i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("count = %d\n", count);
//	return 0;
//}

/*4、计算1/1-1/2+1/3-1/4+1/5 ......+ 1/99 - 1/100的值，打印出结果*/
//先计算：计算1/1+1/2+1/3+1/4+1/5 ......+ 1/99 + 1/100的值，打印出结果
//思路：循环累加
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1 / i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//结果为1
//原因分析：
//1/1+1/2+1/3...=1
//1+0+0+0...
//要打印小数，必须操作数至少有一个是小数

//程序修改：
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0.0;//赋值为double类型的初始值
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1.0 / i;//i为整型，则将b变为double类型
//	}
//	printf("%lf\n", sum);//打印格式为lf
//	return 0;
//}
//再计算：1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ...... + 1 / 99 - 1 / 100的值
//思路：定义一个变量控制正负符号，再循环累加
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//或者奇数项相加，偶数项相加，最后整体相加

/*5、求10个整数中的最大值*/
//思路：定义一个最大值变量，将元素各个数循环与之比较
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = 0;//假设为最大值
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i <= sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d\n",max);
//	return 0;
//}
//当数组有负数时，程序有误
//max赋初值时，必须为数组中的数，一般以第一个元素为最大值

//程序修改：
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];//假设数组的第一个元素的值为最大值
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i <= sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d\n",max);
//	return 0;
//}

/*6、打印九九乘法表*/
//思路：循环打印每行中的每列，先打印一行，再打印一行中的各列
//行号*列号
//1 * 1 = 1
//2 * 1 = 2 2 * 2 = 4
//3 * 1 = 3 3 * 2 = 6 3 * 3 = 9 4 * 1 = 4 .....
//....
//9 * 1 = 9 ..
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	//打印9行
//	for (i = 1; i <= 9; i++)
//	{
//		//每打印一行，打印i列
//		int j = 1;//必须放在这里
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i,j,i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//%2d:两位数右对齐，不足两位，空格补齐。
//%-2:两位数左对齐

/*7、猜数字游戏*/
//思路：
//		1、生成一个随机数
//		2、猜数字
//			a.猜对了，就恭喜你，游戏结束
//			b.你猜错了，会告诉猜大了，还是猜小了，直到猜对
//		3、游戏一直玩，除非退出游戏
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("*********** 1.play     ***********\n");
//	printf("*********** 0.exit     ***********\n");
//	printf("**********************************\n");
//}
//
//void game()
//{//猜数字游戏的实现
//
//	//1、生成一个随机数
//	//使用MSDN索引中，搜索rand
//	//rand---stdlib.h
//	//Generates a pseudorandom number.
//	//int rand(void):函数无参数，返回一个整型
//	//Return Value：
//	//rand returns a pseudorandom number, as described above.There is no error return.
//	//Remarks：
//	//The rand function returns a pseudorandom integer in the range 0 to RAND_MAX.
//	//在一个0-RAND_MAX的范围内，rand函数返回一个随机整数
//	//RAND_MAX--rand函数能返回一个0-32767之间的整数。
//	//引入头文件stdlib.h，RAND_MAX选择右击，转到定义，#define RAND_MAX 0x7fff    = 32767
//	
	/*
	//观察生成随机数的特点
	int ret = rand();//接收生成随机数变量--rand()---stdlib.h
	printf("%d\n", ret);//生成的随机数，每次运行程序，随机结果相同
	*/
//
//	//Use the srand function to seed the pseudorandom-number generator before calling rand.
//	//在调用rand之前，使用srand函数设置生成随机数的生成器
//	//使用MSDN索引，搜索srand
//	//srand---stdlib.h
//	//Sets a random starting point.
//	//void srand( unsigned int seed )：无返回值，参数为unsigned int型
//
	/*int ret = 0;
	srand(1);//当srand函数的参数在变化时，打印的结果才变化，但之后的随机值相同，故参数应传随机变化的值--电脑上的时间
	ret = rand();//可能报错：缺少“；”(在“类型”的前面)。解决方法：变量应定义在代码块的最前面
	printf("%d\n", ret);//每次生成的随机数，都相同
	*/
//
//	//时间戳：当前计算机的时间 - 计算机的起始时间（1970年1月1日0时0分0秒）= xxx秒
//	//拿时间戳设置随机数的生成起始点，获取时间戳，即srand(time())
//	//使用MSDN索引，搜索time
//	//time---time.h
//	//Gets the system time.
//	//time()函数获取系统时间。
//	//time_t time( time_t *timer )：返回类型：time_t，time_t*指针类型
//	//time_t转到定义，重定义typedef __time32_t time_t,再转到定义，发现为long类型
	
//	//故srand()调用time()，time函数传一个空指针参数，得到的返回值强制类型转化成unsigned int型
//	//即srand((unsigned int)time(NULL))

	/*
	int ret = 0；
	srand((unsigned int)time(NULL));//NULL传入空指针
	ret = rand();
	printf("%d\n", ret);//生成的随机数，随机结果很接近
//	//解决方法：把srand((unsigned int)time(NULL));，当设置随机起点时，在主函数里，设置一次即可
	*/
//
	//int ret = rand() % 100 + 1;//设置成1-100的随机数：模100的余数是0-99
//	//2、猜数字
	//int guess = 0;//接收猜的数字
	//while (1)
	//{
	//	printf("请输入猜的数字>:");//二分法猜测
	//	scanf("%d", &guess);
	//	if (guess > ret)
	//	{
	//		printf("猜大了\n");
	//	}
	//	else if (guess < ret)
	//	{
	//		printf("猜小了\n");
	//	}
	//	else
	//	{
	//		printf("恭喜你，猜对了\n");
	//		break;
	//	}
	//}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));//设置生成起点，放在这里
// 
//	do
//	{//主框架
//		menu();
//		printf("请选择>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误,请重新输入!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}