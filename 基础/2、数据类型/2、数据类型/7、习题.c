#define _CRT_SECURE_NO_WARNINGS 1

//习题：
/*1、下面哪个不是C语言内置的数据类型：*/
//A.char
//B.double
//正确结果C.struct Stu
//D.short

/*2、局部变量的作用域是：*/
//A.main函数内部
//B.整个程序
//C.main函数之前
//正确结果D.局部变量所在的局部范围

/*3、下面代码输出的结果是：*/
/*
#include <stdio.h>
int num = 10； 
int main()
{
	int num = 1;
	printf("num = %d\n", num);
	return 0;
}
*/
//A.程序有问题，不能编译
//正确结果B.输出1
//C.输出10
//D.输出0

/*4、字符串的结束标志是：*/
//A.是'0'
//B.是EOF
//正确结果C.是'\0'
//D.是空格

/*区分：'\0', 0, '0', EOF*/
// '\0' 转义字符，ASCII码值为0
//   0  数字0，相当于'\0'
//  '0' 字符0，ASCII码值为48
//  EOF end of file 文件结束标志，值为：-1

/*5、下面代码的结果是：*/
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

/*6、下面那个不是转义字符：*/
//A.'\n'
//B.'\060'
//正确结果C.'\q'
//D.'\b'

/*7、关于数组描述错误的是：*/
//A.数组是一组相同类型元素的集合
//正确结果B.数组的下标是从1开始的
//C.数组的下标是从0开始的
//D.数组如果初始化，可以不指定数组的大小

/*8、C语言中下面那个数组的创建是错误的：*/
//A.int arr[10] = {0};
//正确结果B.int n = 10;int arr[n] = {0};
//C.int arr[] = {1,2,3,4,5,6,7,8,9,0};
//D.char ch[10] = "hello bit";
//VS2019不支持C99标准中的变长数组

/*9、下面程序的结果是：*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", strlen("C:\test\121"));
	return 0;
}
*/
//正确结果A.7
//B.8
//C.9
//D.10

/*10、写一个函数求两个数中的较大值*/
/*
int main()
{
	int num1 = 10;
	int num2 = 20;
 if(num1 > num2)
		printf("较大值是：%d\n", num1);
 else
		printf("较大值是：%d\n", num2);
	return 0;
}
*/

/*------------------------------------*/
/*
#include <stdio.h>
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//一般不建议把函数名写成全大写
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int m = max(a, b);
	printf("max = %d\n", m);
	return 0;
}
*/