#define _CRT_SECURE_NO_WARNINGS 1

//数组：
//1. 一维数组的创建和初始化
//数组的创建
//数组是一组相同类型元素的集合。
//数组的创建方式：
//type_t arr_name[const_n];
//type_t 是指数组的元素类型
//const_n 是一个常量表达式，用来指定数组的大小
/*
#include <stdio.h>
int main()
{
	int arr[10];//创建一个数组，存放10个整型
	char arr2[5];

	//int n = 5;
	//char ch[n];//error，n必须是一个常量表达式

	return 0;
}
*/

//数组的初始化
//数组的初始化是指，在创建数组的同时给数组的内容一些合理初始值（初始化）。即创建的同时赋值，就是初始化
/*
#include <stdio.h>
int main()
{
	int arr[10] = {1,2,3};//不完全初始化，剩下的元素默认初始化为0
	//字符数组的初始化
	char arr2[5] = {'a','b'};//调试发现，剩下的元素默认初始化也为0
	char arr3[5] = "ab";//数组的内容有三个，'a'、'b'、'\0'，剩下的元素默认初始化也为0
	char arr4[5] = { 'a',98 };//调试发现，'b'-98
	char arr5[] = "abcdef";//数组没有指定大小，会根据初始化的内容确定数组的大小，即为7，包含一个'\0'
 	
	printf("%d\n",sizeof(arr5));//7
	//sizeof计算arr所占空间的大小
	//7个元素，char是1个字节，即7 * 1 = 7
	printf("%d\n",strlen(arr5));//6
	//strlen求字符串的长度，不包含'\0'

	//注意：字符数组每个元素的值为整型，每个整型值对应每个字符
	//不论上面数组，数组元素不完全初始化时，默认值初始化为0
	return 0;
}
*/
//1. strlen和sizeof没有什么关联
//2. strlen是求字符串长度的 - 只能针对字符串求长度–库函数 - 使用得引头文件
//3. sizeof计算变量、数组、类型的所占空间的大小-单位是字节–操作符
/*
#include <stdio.h>
int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c' };
	printf("%d\n", sizeof(arr1));//4
	//元素有：'a','b','c','\0'四个元素，故所占空间大小：4 * 1字节 = 4字节
	printf("%d\n", sizeof(arr2));//3
	//元素有：'a','b','c'三个元素，故所占空间大小：3 * 1字节 = 4字节
	printf("%d\n", strlen(arr1));//3
	//计算长度，不包含'\0'，故长度为：3
	printf("%d\n", strlen(arr2));//随机值
	//不确定'\0'的位置，故为随机值
	int arr3[] = {1,2,3};
	printf("%d\n", sizeof(arr3));//12
	//元素有：1,2,3,三个元素，故所占空间大小：3 * 4字节 = 12字节
	printf("%d\n", strlen(arr3));//1
	//整型数组的长度都是1
	return 0;
}
*/

//2. 一维数组的使用
//对于数组的使用我们之前介绍了一个操作符：[] ，下标引用操作符。它其实就数组访问的操作符
/*
#include <stdio.h>
int main()
{
	char arr[] = "abcdef";//[a] [b] [c] [d] [e] [f] [\0]
	//访问数组元素
	printf("%c\n", arr[3]);

	//遍历数组元素
	int i = 0;
	for (i = 0;i < (int)strlen(arr); i++)//strlen() - size_t strlen( const char *string );默认返回的是一个无符号整型typedef unsigned int     size_t;
	{
		printf("%c ",arr[i]);
	}
	printf("\n");

	//通常写法
	int len = strlen(arr);
	for (i = 0; i < len; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");

	int sz = sizeof(arr) / sizeof(arr[0]);//7，元素有七个，下标最大为6
	for (i = 0; i < sz - 1; i++)//不打印最后一个元素，则下标最大为5
	{
		printf("%c ", arr[i]);
	}
	printf("\n");

	int arr2[] = {1,2,3,4,5,6,7,8,9,0};
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);

	for (i = 0; i < sz2; i++)//for (i = 0; i <= sz - 1; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}
*/
//1. 数组是使用下标来访问的，下标是从0开始。
//2. 数组的大小可以通过计算得到。int sz = sizeof(arr)/sizeof(arr[0]);

//3. 一维数组在内存中的存储
/*
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("&arr[%d] = %p\n", i , &arr[i]);
	}
	return 0;
}
*/
//观察运行结果，发现每个元素之间的地址相差4，即相差一个int型大小的空间
//由此可知数组在内存中是连续存放的，即int int int int int int int int int int 

//4. 二维数组的创建和初始化
//二维数组的创建
/*
#include <stdio.h>
int main()
{
	int arr[3][4];//三行四列
	//arr[0]:arr[0][0]、arr[0][1]、arr[0][2]、arr[0][3]
	//arr[1]:arr[1][0]、arr[1][1]、arr[1][2]、arr[1][3]
	//arr[2]:arr[2][0]、arr[2][1]、arr[2][2]、arr[2][3]
	return 0;
}
*/

//二维数组的初始化
/*
#include <stdio.h>
int main()
{
	int arr[3][4] = {1,2,3,4,5};//不完全初始化
	//arr[0]:arr[0][0] = 1、arr[0][1] = 2、arr[0][2] = 3、arr[0][3] = 4
	//arr[1]:arr[1][0] = 5、arr[1][1] = 0、arr[1][2] = 0、arr[1][3] = 0
	//arr[2]:arr[2][0] = 0、arr[2][1] = 0、arr[2][2] = 0、arr[2][3] = 0
	int arr2[3][4] = { {1,2,3},{4,5} };
	//arr[0]:arr[0][0] = 1、arr[0][1] = 2、arr[0][2] = 3、arr[0][3] = 0
	//arr[1]:arr[1][0] = 4、arr[1][1] = 5、arr[1][2] = 0、arr[1][3] = 0
	//arr[2]:arr[2][0] = 0、arr[2][1] = 0、arr[2][2] = 0、arr[2][3] = 0

	int arr[] = { 1,2,3,4 };
	int arr3[][4] = { {1,2,3,4},{4,5} };
	//注意：二维数组的行下标可以省略，列下标不能省略
	return 0;
}
*/

//5. 二维数组的使用
//二维数组的使用也是通过下标的方式。
/*
#include <stdio.h>
int main()
{
	int arr2[3][4] = { {1,2,3},{4,5} };
	//arr[0]:arr[0][0] = 1、arr[0][1] = 2、arr[0][2] = 3、arr[0][3] = 0
	//arr[1]:arr[1][0] = 4、arr[1][1] = 5、arr[1][2] = 0、arr[1][3] = 0
	//arr[2]:arr[2][0] = 0、arr[2][1] = 0、arr[2][2] = 0、arr[2][3] = 0
	
	//二维数组的遍历
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/

//6. 二维数组在内存中的存储
/*
#include <stdio.h>
int main()
{
	int arr2[3][4] = { {1,2,3},{4,5} };
	//arr[0][j]:arr[0][0] = 1、arr[0][1] = 2、arr[0][2] = 3、arr[0][3] = 0
	//arr[1][j]:arr[1][0] = 4、arr[1][1] = 5、arr[1][2] = 0、arr[1][3] = 0
	//arr[2][j]:arr[2][0] = 0、arr[2][1] = 0、arr[2][2] = 0、arr[2][3] = 0
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d] = %p\n",i,j,&arr2[i][j]);
		}
	}

	return 0;
}
*/
//观察运行结果，发现每个元素之间的地址相差4，即相差一个int型大小的空间
//由此可知二维数组在内存中是连续存放的，即int int int int int int int int int int int int
//可以理解arr[0]作为第一行的数组名、arr[1]作为第二行的数组名、arr[2]作为第三行的数组名

//7. 数组越界
//数组的下标是有范围限制的。
//数组的下规定是从0开始的，如果数组有n个元素，最后一个元素的下标就是n - 1。
//所以数组的下标如果小于0，或者大于n - 1，就是数组越界访问了，超出了数组合法空间的访问。

//8. 数组作为函数参数
//冒泡排序函数的错误设计

//冒泡排序（升序）的原理：
//每轮相邻两个数比较，前者比后者大，则交换位置，最终每一轮最后一个数都会是最大的数。
//将剩余的元素进行，相邻比较，得第二大的数。依次类推...
//持续对越来越少的数，进行相邻比较，直到没有元素需要比较
//计算整型数组的长度，不能使用int len = strlen(arr);否则都是1
//循环实现：
/*
#include <stdio.h>
int main()
{
	int arr[] = {1,3,2,4,9,5,-1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	//遍历冒泡排序前的数组元素
	printf("冒泡排序前： ");
	for(int i = 0;i < sz;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	//冒泡排序
	for(int i = 0;i < sz;i++) {
		//外层循环控制比较的轮数：有sz-1轮
		for(int j = 0;j < sz-1-i;j++) {
			//内层循环控制每轮相邻之间比较的次数：每轮都需要比较sz-1-i次
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		//每轮比较后打印数组元素
		printf("第%d轮排序后：",i+1);
		for(int j = 0;j < sz;j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	//遍历冒泡排序后的数组元素
	printf("冒泡排序后： ");
	for(int i = 0;i < sz;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
	//注意：多个i和j变量不是同一个变量
	//i、(1 3)--(1 3) ，(3 2)--(2 3)，(3 4)--(3 4)，(4 9)--(4 9)，(9 5)--(5 9)，(9 -1)--(-1 9)
	//第一轮比较的结果：1 2 3 4 5 -1 9
	//将剩余的元素进行，相邻比较，得第二大的数
	//ii、(1 2)--(1 2)、(2 3)--(2 3)、(3 4)--(3 4)、(4 5)--(4 5)、(5 -1)--(-1 5)、(5 9)--(5 9)
	//第二轮比较的结果：1 2 3 4 -1 5 9
	//将剩余的元素进行，相邻比较，得第三大的数
	//iii、(1 2)--(1 2)、(2 3)--(2 3)、(3 4)--(3 4)、(4 -1)--(-1 4)、(4 5)--(4 5)、(5 9)--(5 9)
	//第三轮比较的结果：1 2 3 -1 4 5 9
	//将剩余的元素进行，相邻比较，得第四大的数
	//iv、(1 2)--(1 2)、(2 3)--(2 3)、(3 -1)--(-1 3)、(3 4)--(3 4)、(4 5)--(-4 5)、(5 9)--(5 9)
	//第四轮比较的结果：1 2 -1 3 4 5 9
	//将剩余的元素进行，相邻比较，得第五大的数
	//v、(1 2)--(1 2)、(2 -1)--(-1 2)、(2 3)--(2 3)、(3 4)--(3 4)、(4 5)--(4 5)、(5 9)--(5 9)
	//第五轮比较的结果：1 -1 2 3 4 5 9
	//将剩余的元素进行，相邻比较，得第六大的数
	//vi、(1 -1)--(-1 1)、(2 -1)--(-1 2)、(2 3)--(2 3)、(3 4)--(3 4)、(4 5)--(4 5)、(5 9)--(5 9)
	//第六轮比较的结果：-1 1 2 3 4 5 9
}
*/

//函数实现：
//方法1：
/*
#include <stdio.h>
void bubble_sort(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);//这样对吗？
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
	int i = 0;
	bubble_sort(arr);//是否可以正常排序？
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//结果出问题了
//通过调试，arr、i、sz发现在函数内部的sz的值是1，观察sizeof(arr)的值
//对arr数组传参，真实传递的是数组第一个元素的地址，即&arr[0]，sizeof(&arr[0])=4
//解决方法：将数组的元素个数在外边计算好，作为参数传入函数中
//方法2：
/*
#include <stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//如果给的数组元素为9，1，2，3，4，5，6，7，8，则上面的程序效率较低
//改进：当里面有一轮两两比较结束后发现，都不需要交换，则判断为已经有序
/*
#include <stdio.h>
void bubble_sort(int arr[],int sz)//这里的int arr[]本质上是int* arr 
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这一轮已经有序
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//本轮不完全有序
			}
		}
		if (flag == 1)
		{
			break;//break语句只能用于for和switch，不能用于if语句中，但可以用于循环语句里的if语句中。
		}
	}
	//break跳到这里
}
int main()
{
	int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);//arr为整个数组
	int i = 0;
	bubble_sort(arr,sz);//arr为首元素的地址
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//数组名是什么？
/*
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	printf("%p\n",arr);//数组名是首元素的地址
	printf("%p\n",&arr[0]);//真正的首元素地址
	printf("%d\n",*arr);//解引用找到地址指向的内容

	int sz = sizeof(arr) / sizeof(arr[0]);
	//疑问：如果arr是数组首元素地址，则sizeof(arr) = 4 ?
	//两个例外：
	//1、sizeof(数组名):此时数组名表示整个数组，不表示数组的首元素地址，sizeof(数组名)计算的是整个数组的大小，单位是字节
	//2、&数组名：数组名代表整个数组，&数组名取出的是整个数组的地址，与数组首元素的地址相同，但不是数组首元素的地址
	//除此1,2两种情况之外，所有的数组名都表示数组首元素的地址。
	//此外，需要注意：在数组当作实参传给形参时，数组名表示首元素的地址，sizoef(数组名)表示首元素地址的大小
	printf("%p\n",&arr);
	return 0;
}
*/
//例如：
/*
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7};

	printf("%p\n", arr);//数组第一个元素的地址
	printf("%p\n", arr+1);//数组第二个元素的地址
	//两个结果相差int型个字节，即4个字节
	printf("%p\n", &arr[0]);//数组第一个元素的地址
	printf("%p\n", &arr[0]+1);//数组第二个元素的地址
	//两个结果相差int型个字节，即4个字节
	printf("%p\n", &arr);//数组的地址
	printf("%p\n", &arr+1);//第二个数组的地址
	//两个结果相差int[7]个字节，即4*7=28个字节
	
	return 0;
}
*/

//9. 数组的应用实例1：三子棋
//见项目"三子棋"：gameTest.c、game.c、game.h
//10. 数组的应用实例2：扫雷游戏
//见项目"扫雷"：test.c、game.c、game.h