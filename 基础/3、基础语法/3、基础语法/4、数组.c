#define _CRT_SECURE_NO_WARNINGS 1

//一次性存储一组相同类型的数据	---数组
//数组：一组相同类型的元素的集合
/*
#include <stdio.h>
int main()
{
	//将10个整型存起来，并初始化
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//定义一个存放10个整型数字的数组,最多放10个元素
	char ch[5] = { 'a','b','c' };//不完全初始化，剩余的默认为0，即字符'\0'
	char c[] = "abc";
	//直按F10，调试至char ch[5]={'a','b','c'};点击“调试”选项卡，单击“窗口”，选择“监视”，选择任意监视
	
	//数组的访问arr[下标]：数组是用下标来访问各个元素的,第一个元素的下标是从0开始的
	//	  1			2		3		4		5		6		7		8		9		10
	//arr[0]	arr[1]	arr[2]	arr[3]	arr[4]	arr[5]	arr[6]	arr[7]	arr[8]	 arr[9]
	
	//打印数组各元素
	int i = 0;
	while (i < 10)
	{
		printf("%d\t", arr[i]);
		i++;
	}
	return 0;
}
*/
//调试观察打印过程

//习题：
//C语言中下面数组的创建错误的：
//A.int arr[10] = { 0 };
//正确结果B.int n = 10; int arr[n] = { 0 };
//C.int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//D.char ch[10] = "hello bit";

//C99标准中引用了一个概念：变长数组
// 支持数组创建的时候，用变量指定大小，但是这个数组不能初始化
// VS2019不支持C99中的变长数组
/*
#include <stdio.h>
int mian()
{
	int n = 10;
	int arr[n] = { 0 };//报错

	return 0;
}
*/