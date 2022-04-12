#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1、函数是什么：负责完成某项特定任务的代码块
//#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main() 
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a , b);
//	printf("%d\n",sum);
//
//	return 0;
//}
//函数放在main函数之前，可以不用声明

//2. 库函数：C语言提供的需要频繁使用的功能/函数
//I/O函数：输入输出函数，放在stdio.h头文件下，如：printf、scanf、getchar、putchar
//字符串操作函数：放在string.h头文件下，如：strcpy、strlen
//字符操作函数：如：大写转小写
//内存操作函数：如：memset
//时间/日期函数：如：time
//数学函数：放在math.h头文件下，如：sqrt
//...

//如何学函数？步骤：
//1、使用cplusplus.com或者API文档MSDN或者cppreference.com，搜索函数名strcpy
//2、理解函数的参数、参数类型、函数返回类型
//3、char * strcpy ( char * destination, const char * source );
//char* 字符型指针类型，用来存放地址的、参数名destination目的地、source源头
//4、理解函数的功能描述
//5、Copies the C string pointed by source into the array pointed by destination, including the terminating null character
//拷贝通过源头指向的那个C字符串，到通过目的地所指向的那个数组中，包括结束的'\0'字符(null-'\0')
//6、Parameters参数
//destination
//Pointer to the destination array where the content is to be copied.
//source
//C string to be copied.
//7、Return Value
//destination is returned.
//8、测试函数，引头文件
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//strlen    -string length
//	//strcpy	-string copy
//	char arr1[] = "bit";
//	char arr2[20] = "########";//下标为8-19的数组元素均为0
//	strcpy(arr2, arr1);//数组本身是一个地址
//	printf("%s\n", arr2);
//
//	return 0;
//}
//运行Fn+F5，结果为bit
//分析：是否\0字符被拷贝了
//Fn+F10按至55行后，选择调试选项卡-窗口-监视：调试代码
//输入arr1和arr2，观察可知
//arr1有b、i、t、0
//arr2有########000000000000
//再按一下Fn+F10，调试至56行
//观察arr2的元素可知，为bit0####000000000000
//由于\0字符也被拷贝了，且\0是结束标志，所以打印结果后面不输出
//注意：源头的空间比目的地的空间长，会溢出

//1、使用cplusplus.com或者API文档MSDN或者cppreference.com，搜索函数名memset
//2、理解函数的参数、参数类型、函数返回类型
//3、void * memset ( void * ptr, int value, size_t num );
//void* 指针类型，用来存放地址的、参数名value、num
//4、理解函数的功能描述
//5、Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
//设置最开始num个字节被ptr指向的内存空间为value，即把ptr所指向的那个内存块空间的前num个字节的内容设置为指定的value值
//6、Parameters参数
//ptr
//Pointer to the block of memory to fill.
//value
//Value to be set.
//num
//Number of bytes to be set to the value.
//size_t is an unsigned integral type.
//7、Return Value
//ptr is returned.
//8、测试函数，引头文件
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//memset    -memory set
//	char arr[] = "hello world";
//	memset(arr,'*', 5); //将arr前五个字符设置为字符'*'，value = '*'实质上就是一个整型
//	printf("%s\n", arr);//***** world
//
//	return 0;
//} 

//3. 自定义函数
//函数的基本组成
//int Add(int x,int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//ret_type fun_name(para1,*)
//{//函数体
//	statement;//语句项
//  return value;
//}
//ret_type返回类型
//fun_name 函数名
//para1 函数参数
//如：写一个函数可以找出两个整数中的最大值
//定义函数
//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数的使用
//	int max = get_max(a,b);
//	printf("max = %d\n",max);
//	max = get_max(100,300);
//	printf("max = %d\n",max);
//	return 0;
//}
//如：写一个函数可以交换两个整型变量的内容
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int tmp = 0;
//	printf("a = %d b = %d\n", a, b);
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}

//void Swap(int x,int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a = %d b = %d\n", a, b);
//	Swap(a,b);//传值调用
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}
//调试：F10，观察函数内部F11
//观察a、b、&a、&b、x、y、&x、&y、tmp
//发现&a、&b，与&x、&y的地址不同，即a、b与x、y存储的是两个独立的空间
//即使函数内部x和y的值已经交换了，但是不会影响到&a和&b的地址内的值，故没有交换

//知识回顾
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;//*解引用操作，通过pa的地址找到a的内容，并修改a的值
//	printf("%d\n",a);
//	return 0;
//}
//修改后的代码
//void Swap(int* pa,int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a = %d b = %d\n", a, b);
//	Swap(&a,&b);//传址调用
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}
//当实参传给形参的时候，形参其实是实参的一份临时拷贝，对形参的修改是不会改变实参的

//4. 函数参数
//实参：真实传给函数的参数，叫实参。
//实参可以是：常量(get_max(10,20))、变量(如：get_max(a,b))、表达式（如：get_max(100,300+1)）、函数(如：get_max(get_max(10,20),30)等。
//无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。
//实参：如Swap(&a,&b)中的&a和&b
//形参：如Swap(int* pa,int* pb)中的pa和pb
//形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单
//元），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效。

//5. 函数调用
// 传值调用
//函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。
//传址调用
//传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
//这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操作函数外部的变量。
//什么时候使用传值调用，什么时候使用传址调用？
//---如果函数所要实现的功能需要改变变量值的内容，则使用传址调用
//---如果函数所要实现的功能只是获取变量的值，而不需要改变值的内容，则用传值调用
//练习
//1. 写一个函数可以判断一个数是不是素数。
//int main()
//{
//	int i = 0;
//	for (i = 100;i <= 200;i++)
//	{
//		int j = 0;
//		for (j = 2;j <= i-1;j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (j == i)
//			printf("%d ",i);
//
//	}
//}

//判断i是否为素数的函数
//假设函数返回值为1，则是素数，返回值为0，则不是素数
//#include <math.h>
//int is_prime(int i)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(i); j++)
//	{
//		if (i % j == 0)
//			return 0;//return比break强，return直接结束函数，break是终止外循环
//	}
//	//if (j == i)//不需要这行代码，因为return 0;不执行，一定会执行return 1;
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{	
//		//判断i是否为素数
//		//假设函数返回值为1，则是素数，返回值为0，则不是素数
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}
//2. 写一个函数判断一年是不是闰年。
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
////函数的设计，要单一，独立，如：不要在函数内打印
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{	
//		判断year是否为闰年
//		假设函数返回值为1，则是闰年，返回值为0，则不是闰年
//		if (1 == is_leap_year(year))
//			printf("%d ", year);
//	}
//	return 0;
//}
//3. 写一个函数，实现一个整形有序数组的二分查找。
//二分查找：在一个有序数组中查找具体的某个数
//如果找到了返回这个数的下标，找不到返回-1
//1、去哪查找	2、要查找谁	3、查找后的结果
//函数实现
//int binary_search(int arr[], int k)//注意：实参和形参，本质上arr是一个指针
//{
//	//算法实现--二分查找
//	int sz = sizeof(arr) / sizeof(arr[0]);//sizeof(arr)计算的是指针大小，win32是4个字节，arr[0]是int型，也是4个自己，即sz = 4 / 4 = 1
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)//多次二分查找
//	{
//		//一次二分查找
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 7;
//	//1、去哪查找:arr	2、要查找谁:k	3、查找后的结果ret
//	int ret = binary_search(arr,k);//传递过去的是数组arr首元素的地址
//	//如果找到了返回这个数的下标，找不到返回-1
//	if (ret == -1)
//		printf("找不到指定的数字\n");
//	else
//		printf("找到了，下标是%d\n",ret);
//	return 0;
//}
//结果出问题了
//分析：调试
//依次观察arr、k、sz
//发现sz计算错误：如果是把数组作为参数传入函数的形参中，不能使用sizeof(arr)/sizeof(arr[0])计算数组元素的个数
//原因：数组作为参数，传入的仅仅是第一个元素的地址，即此时的数组名代表的是首元素的地址
//修改代码：让计算元素个数放在函数外（主函数内）,把元素个数作为参数传入函数中
//int binary_search(int arr[], int k, int sz)//注意：实参和形参，本质上arr是一个指针
//{
//	//算法实现--二分查找
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)//需要相等，否则查找7的时候漏掉了7
//	{
//		//一次二分查找
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr,k,sz);//传递过去的是数组arr首元素的地址
//	//如果找到了返回这个数的下标，找不到返回-1
//	if (ret == -1)
//		printf("找不到指定的数字\n");
//	else
//		printf("找到了，下标是%d\n",ret);
//	return 0;
//}
//此时形参arr[]的作用，是为了获取arr[mid]，所有需要有一个int arr[]的参数
//4. 写一个函数，每调用一次这个函数，就会将 num 的值增加1。
//void Add(int* p)
//{
//	(*p)++;//++的优先级高于*
//}
//int main()
//{
//	int num = 0;
//	Add(&num);//函数需要操作实参的值，使用传址调用
//	printf("num = %d\n", num);
//	Add(&num);
//	printf("num = %d\n", num);
//	Add(&num);
//	printf("num = %d\n", num);
//	return 0;
//}

//6. 函数的嵌套调用和链式访问
//函数的嵌套调用：函数和函数之间可以有机的组合
//void line()
//{
//	printf("hehe\n");
//}
//void three_line()
//{
//	int i = 0;
//	for (i = 1; i <= 3; i++)
//	{
//		line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}
//函数的链式访问：把一个函数的返回值作为另一个函数的参数
//#include <string.h>
//int main()
//{
//	//1、
//	int len = 0;
//	len = strlen("abc");
//	printf("%d\n", len);
//	//2、链式访问
//	printf("%d\n", strlen("abc"));
//	return 0;
//}
//如：
//int main()
//{
//	printf("%d",printf("%d",printf("%d",43)));
//}
//打开MSDN搜索printf
//返回值类型是int型
//Return Value
//Each of these functions returns the number of characters printed, or a negative value if an error occurs.
//返回打印的字符的个数
//printf("%d", 43)的结果打印43，打印了两个字符，返回值是2
//printf("%d",printf("%d",43))的结果打印2，打印了一个字符，返回值是1
//printf("%d",printf("%d",printf("%d",43)))的结果打印1
//故结果为4321
//注意区分函数的返回值，和函数的结果

//7. 函数的声明和定义
//函数声明：
//1. 告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，函数声明决定不了。
//2. 函数的声明一般出现在函数的使用之前。要满足先声明后使用。
//3. 函数的声明一般要放在头文件中的。
//函数定义：
//函数的定义是指函数的具体实现，交待函数的功能实现。

//函数声明
//int Add(int, int);//也可以用int Add(int x,int y)
//int main() 
//{
//	int a = 10;
//	int b = 20;
//	//函数调用
//	int sum = Add(a , b);
//	printf("%d\n",sum);
//
//	return 0;
//}
//函数的定义
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//程序会报警告
//自定义函数放在主函数后面，需要声明函数，放在主函数前面，不需要声明函数

//函数声明的意义：
//1、在选择“头文件”右击创建一个文件：add.h
//文件写入代码：
//函数声明 
//int Add(int, int);
//2、在选择“源文件”右击新建一个文件：add.c
//函数的定义：
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//3、函数测试
//在test.c中使用add()
//#include "add.h"//自己创建的头文件用""，C语言提供的头文件用<>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数调用
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	return 0;
//}
//如：实现一个计算器的程序
//将功能拆分成：加法功能、减法功能、乘法功能、除法功能
//A实现：add.c和add.h、B实现：sub.c和sub.h、C实现：mul.c和mul.h、D实现：div.c和div.h
//使用的时候进行组合即可
//注意：.h头文件放的是函数声明，.c源文件放的是函数定义
//函数的声明也可以这么写：
#ifndef __ADD_H__//if not define Add.h，则为真，执行第二行；为假则所有代码不参与编译，来到最后一行end if
#define __ADD_H__//define Add.h
//函数的声明
int Add(int x,int y);
#endif // !__ADD_H__
//目的：防止同一个头文件被重复引入多次，在头文件中设置

//8. 函数递归：自身调用自身
//如：
//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;
//}
//通过调试发现：报错Stack overflow 
//递归常见的错误：栈溢出
//将内存划分为栈区、堆区、静态区
//栈区：放局部变量的内存、函数形参的内存，函数调用的内存
//堆区：放动态开辟的内存，如：malloc、calloc
//静态区：放全局变量的内存，如：static修饰的变量
//stackoverflow.com---程序员的知乎、提问、解答
//例如：接收一个整型值（无符号），按照顺序打印它的每一位。输入：1234，输出 1 2 3 4
//思路一：假设得到4，可以先对数%模10得到4，除10去掉了4，循环3次，再将这四个数存入一个数组中，逆着打印出来
//思路二：（递归思想）
//通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解
//print(1234)，由于打印末位的数比较容易，可以将打印拆除两部分
//print(123) 4//先将123的每位打印，再打印4
//print(12) 3 4//先将12的每位打印，再打印3，再打印4
//print(1) 2 3 4//先将1打印，再打印2，再打印3，再打印4
//void print(int n)
//{
//	if (n > 9)//说明n是一个两位及以上的数
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);//1234
//	//递归
//	print(num);
//	return 0;
//}
//递归的两个必要条件:
//存在限制条件，当满足这个限制条件的时候，递归便不再继续。
//每次递归调用之后越来越接近这个限制条件。
//例如：编写函数不允许创建临时变量，求字符串的长度。
//int main()
//{
//	char arr[] = "bit";
//	int len = strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}

//int my_strlen(char* str)//str是一个指针变量
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;//创建临时变量
//		str++;//指针的地址加1，数组每一个元素的地址是按顺序排列的
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是首元素的地址
//	printf("len = %d\n", len);
//	return 0;
//}

//递归思想：大事化小
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("\0")
//1+1+1+0
//int my_strlen(char* str)//str是一个指针变量
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1); 
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是首元素的地址
//	printf("len = %d\n", len);
//	return 0;
//}
//9、函数迭代
//例如：求n的阶乘。（不考虑溢出）
//循环实现：!n = 1 * 2 * 3 * 4 * ... * n
//int Fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}

//循环实现：!n = n * n-1 * n-2 * n-3 * ... * 1
int factorial(int n)
{
	int result = 1;
	while (n > 1)
	{
		result *= n;
		n -= 1;
	}
	return result;
}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac(n);
//	printf("%d\n", ret);
//	return 0;
//}
//递归实现
//数学公式：
//Fac(n) = 1 (n <= 1)
//Fac(n) = n * Fac(n - 1) (n > 1)
//int Fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac(n);
//	printf("%d\n", ret);
//	return 0;
//}

//例如：求第n个斐波那契数。（不考虑溢出）1 1 2 3 5 8 13 21 34 55... （前两个数之和等于第三个数）
//数学公式：
//Fib(n) = 1 (n <= 2)
//Fib(n) = Fib(n - 1)+Fib(n - 2) (n > 2)
//再怎么实现这个函数
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	//先怎么用这个函数，再怎么实现这个函数---TDD测试驱动开发
//	ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}
//缺点：当测试的数越大，计算机执行的结果也久
//如：50
//50
//49 48
//48 47 47 46
//47 46 46 45 46 45 45 44
//...
//假设测40，观察第三个斐波那契数重复计算了多少次
//int count = 0;
//int Fib(int n)
//{
//	if (n == 3)//测试第三个斐波那契数的计算次数
//		count++;
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	//先怎么用这个函数，再怎么实现这个函数-- - TDD测试驱动开发
//		ret = Fib(n);
//	printf("ret = %d\n", ret);
//	printf("count = %d\n", count);
//	return 0;
//}
//当求第40个斐波那契数，发现第三个斐波那契数重复计算了39088169次

//修改代码：
//循环实现
// 1 1 2 3 5 8 13 21 34 55...
// a b c
// 1 1 2 3 5 8 13 21 34 55... 
//   a b c
// 1 1 2 3 5 8 13 21 34 55... 
//     a b c
// 1 1 2 3 5 8 13 21 34 55... 
//       a b c...
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;//c = 1不能初始化为0，否则n<=2，则c=0
//	while (n > 2)
//	{
//		c = a + b;//先计算c，再移动a和b
//		a = b;
//		b = c;
//		n--;//注意每次循环都要接近n > 2
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	//先怎么用这个函数，再怎么实现这个函数-- - TDD测试驱动开发
//		ret = Fib(n);
//	printf("ret = %d\n", ret);
//	return 0;
//}
//注意整型溢出和栈溢出
//注意：并不是递归的两个条件都满足的代码就一定没有问题
//如：
//void test(int n)
//{
//	if (n < 10000)
//		test(n + 1);
//}
//int main()
//{
//	test(1);
//	return 0;
//}
//调试，会发生栈溢出

//经典问题;
//1、汉诺塔问题
//2、青蛙跳台阶问题---来自一本书《剑指offer》
