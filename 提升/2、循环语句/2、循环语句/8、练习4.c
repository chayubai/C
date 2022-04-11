#define _CRT_SECURE_NO_WARNINGS 1
/*1、交换两个int变量的值，不能使用第三个变量。即a=3,b=5,交换后a=5,b=3*/
//方法一：使用第三变量
//#include <stdio.h>
//int main()
//{
//	//交换2个整形变量
//	int a = 3;
//	int b = 5;
//	int c = 0;//空瓶
//	printf("交换前:a=%d b=%d\n", a, b);
//	c = a;//第一步：把3放入空瓶中，此时a空了
//	a = b;//第二步：再把5放入空的a中，此时b空了
//	b = c;//第三步：最后把装了3的c放入b中
//	printf("交换后: a=%d b=%d\n", a, b);
//
//	return 0;
//}
//方法二：加减法
//#include <stdio.h>
//int main()
//{
//	//交换2个整形变量
//	int a = 3;
//	int b = 5;
//	printf("交换前:a=%d b=%d\n", a, b);
//	a = a + b;//第一步：此时a为两个内容的和，b还是原来的b
//	b = a - b;//第二步：a - b ,和减去b此时得到了原来的a，放入b中，此时b得到了原来的a
//	a = a - b;//第三步：a - b，和减去b此时得到了原来的b，放入a中，此时a得到了原来的b
//	printf("交换后: a=%d b=%d\n", a, b);
//
//	return 0;
//}
//代码会出现整型溢出问题：两个数的和超过最大值，多余内容会丢失，此时a - b得不到原来的数
//int 型能存储的最大值为：2^32-1
//观察INT_MAX的值，引头文件#include <limits.h>，选中INT_MAX，右键转到定义，#define INT_MAX 2147483647
//加减法：只能解决较小数字的交换

//方法三：按位异或法--相同为0，相异为1
//#include <stdio.h>
//int main()
//{
//	//交换2个整形变量
//	int a = 3;//011
//	int b = 5;//101
//	printf("交换前:a=%d b=%d\n", a, b);
//	a = a ^ b;//第一步：011^101 = 110 = a b = 101
//	b = a ^ b;//第二步：110^101 = 011 = b a = 110
//	a = a ^ b;//第三步：110^011 = 101 = a b = 011
//	printf("交换后: a=%d b=%d\n", a, b);
//
//	return 0;
//}
//不会溢出，因为不会产生进位
//进入企业后：
//交换两个数，会采用第三个变量的方法，代码的可读性高，执行效率高
//异或操作的方法，可读性差，执行效率低于其他方法

/*LeetCode-136题：找出只出现一次的数*/
/*题面:给定一个非空整型数组，除了某个元素只出现一次以外，其余每个元素均出现两次，找出那个只出现了一次的元素。*/
/*样例: int a[]={1,2,3,4,5,1,2,3,4}，该数组中只有5出现一次，其他数字都是成对出现的，要找出5。*/
//方法一：给定数组中，只能重复2/偶数次，可以找多个单数
/*思路：只要把每个元素在数组中出现的次数统计一下，即可。即：循环拿每个元素和数组中的所有元素对比是否相等*/
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,7 };
//	//找出单身狗
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的元素个数
//	for (i = 0; i < sz; i++)
//	{//依次找到数组中的元素
// 	
//		int count = 0;//计数器
//		int j = 0;
//		for (j = 0; j < sz; j++)
//		{//统计arr[i]在arr数组中出现了几次
//			if (arr[i] == arr[j])
//				count++;
//		}
//		if (count == 1)
//			printf("单身狗：%d\n", arr[i]);
//	}
//	return 0;
//}

//给定数组中，只能重复偶数次，只能找一个单数
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,-1,1,2,3,4 };
//	//找出单身狗
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的元素个数
//	for (i = 0; i < sz; i++)
//	{
//		//统计arr[i]在arr数组中出现了几次
//		int count = 0;
//		int j = 0;
//		for (j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//				count++;
//		}
//		if (count == 1)
//		{
//			printf("单身狗：%d\n", arr[i]);
//			break;
//		}
//	}
//	return 0;
//}
//需要执行9*9=81次，可优化见方法二

//方法二：给定数组中，只能找一个单数，且每个数只能重复出现了偶数次，不能出现奇数次，比如3重复出现了3次
//#include <stdio.h>
//int main()
//{
//	//3 ^ 3 = 0
//	//5 ^ 5 = 0
//	//a ^ a = 0
//
//	//0 ^ 5 = 5
//	//0 ^ 3 = 3
//	//0 ^ a = a
//
//	//3 ^ 5 ^ 3 = 5
//	//3 ^ 3 ^ 5 = 5
//	//异或满足交换律
//	 
//	int arr[] = { 1,2,3,4,5,1,2,5,3,4 };
//	//找出单身狗
//	//思路：1 ^ 1 ^ 2 ^ 2 ^ 3 ^ 3 ^ 4 ^ 4 ^ 5 最后结果为那个单着的数
//	int i = 0;
//	int ret = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//		ret = ret ^ arr[i];
//	printf("单身狗：%d\n", ret);
//	return 0;
//}
//此程序只要执行9次

/*3、写一个关机程序*/
//程序运行，你的电脑在1分钟后关机，如果输入：“我是猪”，则取消关机
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char input[20] = { 0 };//存储输入的数据
//  //system()专门用来执行系统命令的-stdlib.h
//	system("shutdown -s -t 60");//关机
//again:
//	printf("请注意，你的电脑将在1分钟后关机。若取消关机，请输入：“我是猪”\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)//strcmp()：两字符串相同，则返回0-string compare-string.h
//		system("shutdown -a");//取消关机
//	else
//	{
//		printf("输入错误！重新输入");
//		goto again;
//	}
//	return 0;
//}