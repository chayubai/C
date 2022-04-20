#define _CRT_SECURE_NO_WARNINGS 1
//指针的概念：
//1. 指针就是个变量，用来存放地址，地址唯一标识一块内存空间。
//2. 指针的大小是固定的4 / 8个字节（32位平台 / 64位平台）。
//3. 指针是有类型，指针的类型决定了指针的 +/-整数的步长，指针解引用操作的时候的权限。
//4. 指针的运算。：指针+/-整数、指针关系运算、指针-指针
//#include <stdio.h>
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//这里sizeof(arr) = 4个字节，即首元素地址的大小，sizeof(arr[0]) = 4个字节，即一个元素的大小
//	printf("%d\n", sz);
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}
//将配置管理器-即活动解决方案平台改为X64，结果为2。
//即sizeof(arr) = 8个字节，即首元素地址的大小，sizeof(arr[0]) = 4个字节，即一个元素的大小

//1. 字符指针char *p;
//#include <stdio.h>
//int main()
//{
//	char ch = 'w';
//	char *pc = &ch;
//
//	char arr[] = "abcdef";
//	char *p = arr;//数组名，即字符串的首元素的地址赋值给p，则变量p和arr的值等同
//	printf("%s\n", arr);//打印字符串
//	printf("%s\n", p);//打印字符串
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char *p = "abcdef";//"abcdef"是一个常量字符串，即将字符串的首元素的地址赋值给p
//	printf("%c\n", *p);//打印首元素
//	printf("%s\n", p);//打印字符串
//	return 0;
//}
//注意：%s打印的是p，%c打印的是*p.
//当输出选择为%s时 程序是按流输入 遇到'/0'结束 也就是说字符串输入时只要给出首地址 但遇到\0是就自动结束

//#include <stdio.h>
//int main()
//{
//	char *p1 = "abcdef";//"abcdef"是一个常量字符串，即将字符串的首元素的地址赋值给p1，而不是将字符串放入p1中
//	//*p1 = 'W';//由于是常量字符串，是不允许修改的，故程序会崩溃 ---Segment fault段错误
//  //www.stackoverflow.com
//  //segmentfault.com
//	printf("%s\n", p1);//打印字符串
//	
//	//正确书写：
//	const char *p2 = "abcdef";
//	//*p2 = 'W';//此时就会报错
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";//创建arr1[]存放字符串abcdef，不同的变量创建不同的空间
//	char arr2[] = "abcdef";//创建arr2[]存放字符串abcdef，不同的变量创建不同的空间
//	if (arr1 == arr2)//arr1和arr2是首元素的地址，两个变量内存空间的地址肯定不一样
//	{//等于号比较的是内容？？？arr1和arr2存放的是首元素的地址，但是首元素的地址不同
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");//打印haha
//	}
//	const char *p1 = "abcedf";//常量字符串
//	const char *p2 = "abcedf";//相同的常量字符串，使用的是同一块空间，节省空间
//	if (p1 == p2)//p1和p2存放的是同一块空间的首元素地址，首元素地址相同
//	{
//		printf("hehe\n");//打印hehe
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//	//来自《剑指offer》
//}//注意：arr1、arr2、p1、p2四个变量的地址是独立的，是不同
//C/C++会把常量字符串存储到单独的一个内存区域，当几个指针指向同一个字符串的时候，他们实际会指向同一块内存。
//但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。

//2. 指针数组：是一个存放指针（地址）的数组
//int* arr1[10]; //整形指针的数组
//char* arr2[4]; //一级字符指针的数组
//char** arr3[5];//二级字符指针的数组
//#include <stdio.h>
//int main()
//{
//	int arr[4] = { 0 };//整型数组
//	char ch[5] = { 0 };//字符数组
//	int* parr[4];//整型指针数组-存放整型指针的数组
//	char* pch[5];//字符指针数组-存放字符指针的数组
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 20;
//	int d = 40;
//	int* parr[4] = { &a,&b,&c,&d };//每个地址都是int*类型的指针
//	//调试-监视：&a,&b,&c,&d和parr
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", *(parr[i]));
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//指针数组
//	//parr[0]:arr1[0],arr1[1],arr1[2],arr1[3],arr1[4]
//	//parr[1]:arr2[0],arr2[1],arr2[2],arr2[3],arr2[4]
//	//parr[2]:arr3[0],arr3[1],arr3[2],arr3[3],arr3[4]
//	//类似于二维数组
//	int i = 0;
//	for (i = 0; i < 3; i++)//打印每一个数组
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));//打印数组的各个元素
//		}
//		printf("\n");
//	}
//	return 0;
//}

//3. 数组指针：能够指向数组的指针。
//#include <stdio.h>
//int main()
//{
//	int *p = NULL;//p是整形指针：能够指向整形数据的指针，可以存放整型的地址。
//	char *pc = NULL;//pc是字符数组：能够指向字符型数据的指针，可以存放字符的地址
//	//数组指针：指向数组的指针，可以存放(整个)数组的地址
//	//int arr[10] = { 0 };
//	//arr - 首元素的地址，&arr[0] - 首元素的地址，&arr - 数组的地址
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//[]比*优先级高
//	int (*p)[10] = &arr;//存放数组的地址,先和*p结合，故为指针，p为数组指针
//	int *p;//p为整型指针
//	int* p[10];//先和p[10]结合，故为数组，p为指针数组
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	//字符数组，元素为字符型
//	char arr[5];
//	//字符数组的指针，数组指针的类型char(*)[]
//	char (*pa)[5] = &arr;
//
//	//字符指针的数组，
//	char* arr[5];
//	//字符指针数组的指针
//	char* (*pa)[5] = &arr;
//	//存放数组的地址，用数组指针
//	//pa是数组指针变量的名字
//	//*说明pa是指针
//	//[5]说明pa指向的数组是5个元素
//	//char*说明pa指向的数组的元素类型是char*
//	return 0;
//}
//指针数组：数组：存放指针(地址)的数组，如：int* arr[3] = {&a，&b，&c}
//数组指针的数组：数组：存放数组指针(地址)的数组，如：
//数组指针：指针：存放数组地址的指针，如：int (*pa)[5] = &arr
//指针数组的指针：指针：存放的指针数组地址的指针，如：char* (*pa)[5] = &arr;

//&数组名和数组名
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);
//	printf("&arr= %p\n", &arr);
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	return 0;
//}
//虽然数组名和&数组名打印的地址是一样的。分别加一，跳过的字节数不同，arr+1跳过一个整型的字节，&arr+1跳过一个数组的字节
//实际上：&arr表示的是数组的地址，而不是数组首元素的地址。
//本例中&arr的类型是：int(*)[10]，是一种数组指针类型，数组的地址+1，跳过整个数组的大小，所以&arr+1相对于&arr的差值是40.

//数组指针的使用
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//遍历数组的各个元素
//	//1、使用这种简便，指针
//	/*int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//	}*/
//	//2、指针数组
//	//int (*p)[10] = &arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(*p+i));//*p == arr
//	//}
//	//3、指针数组
//	//int (*p)[10] = &arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", (*p)[i]);//*p表示拿到了数组，相当于首元素的地址
//	//}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int *p = arr;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);//数组下标为i的元素
//		printf("%d ", *(p + i));//*(p+i)下标为i的地址解引用
//		printf("%d ", *(arr + i));//p = arr说明p和arr相同
//		printf("%d ", p[i]);//以p为起始地址，访问下标为i的元素
//		//arr[i] == *(arr + i) == *(p + i) == p[i]
//		//以上四种方法等价
//	}
//	return 0;
//}

//#include <stdio.h>
//void Print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void Print(int (*p)[5], int x, int y)//p表示一行，p+1访问的是一行
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p + i) + j));//*(p + i)表示找到了i行,*(*(p + i) + j)表示找到了第j个元素
//			printf("%d ", (*(p + i))[j]);
//			printf("%d ", *(p[i] + j));
//			printf("%d ", p[i][j]);
//			//*(p + i) == p[i]
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	Print1(arr, 3, 5);//arr二维数组名：首元素的地址(除了&，sizeof)，即arr[0][i]有五个元素（想象成一维数组）
//	Print2(arr, 3, 5);//arr是首元素的地址，即传入(首元素)一维数组的地址，形参用数组指针接收
//	return 0;
//}

//int arr[5]; //arr是一个5个整型元素的数组
//int *parr1[10]; //parr1是一个数组，数组有10个元素，每个元素的类型是int*，parr1是指针数组
//int (*parr2)[10]; //parr2是一个指针，该指针指向了一个数组，数组有10个元素，每个元素的类型是int，parr2是数组指针
//int (*parr3[10])[5];//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，数组指针指向的数组有5个元素，每个元素是int
//注意：定义变量时，区分变量名。先根据结合性判断是指针还是数组，再判断变量名和变量类型，变量类型是去掉变量名后剩余的

//4. 数组传参和指针传参
//把【数组】或者【指针】传给函数，那函数的参数该如何设计？
//一维数组传参
//#include <stdio.h>
//void test(int arr[])//数组接收，ok
//{}
//void test(int arr[10])//数组接收，ok
//{}
//void test(int arr[6])//数组接收，ok，写错也不关系，不建议写错，容易引起误导
//{}
//void test(int *arr)//指针接收，ok
//{}
//void test2(int* arr[20])//数组接收，ok
//{}
//void test2(int* arr[])//数组接收，ok
//{}
//void test2(int* *arr)//指针接收，ok
//{}
//int main()
//{
//    int arr[10] = { 0 };//存放整型的数组
//    int* arr2[20] = { 0 };//存放指针的数组
//    test(arr);//传入的是地址，使用指针接收形参
//    test2(arr2);//传入的是一级指针地址，使用二级指针接收形参
//}
//总结：一维数组传参，函数的参数可以为数组，也可以为指针
//当为用指针接收时，形参直接用*p代替arr[]

//二维数组传参
//void test(int arr[3][5])//数组接收，ok
//{}
//void test(int arr[][])//error
//{}
//void test(int arr[3][])//error
//{}
//void test(int arr[][5])//数组接收，ok
//{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//void test(int* arr)//error，存放的是整型指针的地址
//{}
//void test(int* arr[5])//error，数组，存放的是指针的地址
//{}
//void test(int (*arr)[5])//数组指针，数组有5个元素，ok
//{}
//void test(int* *arr)//error，存放的是一级指针变量的地址
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);//二维数组传参，一维数组(5个元素)的地址
//}
//总结：二维数组传参，函数的参数可以为数组，也可以为指针
//当为用指针接收时，形参用数组指针，注意数组元素个数

//一级指针传参
//#include <stdio.h>
//void Print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int *p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	Print(p, sz);
//	return 0;
//}
//总结：一级指针传参，函数的参数为一级指针

//思考：当一个函数的参数部分为一级指针的时候，函数能接收什么参数？
//----1、变量，2、一级指针，3、一维数组
//#include <stdio.h>
//void test(int* p)
//{}
//void test2(char* p)
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	test(&a);//ok
//	test(p);//ok
//	char ch = 'w';
//	char* pc = &ch;
//	test2(&ch);//ok
//	test2(pc);//ok
//	return 0;
//}

//二级指针传参
//#include <stdio.h>
//void test(int** p)
//{}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);//ok
//	test(&p);//ok
//	int* arr[10];
//	test(arr);//ok
//	return 0;
//}
//总结：二级指针传参，函数的参数可以是二级指针
//如果函数参数是二级指针，传参可以是二级指针变量pp，一级指针的地址&p，可以是指针数组名(一级指针的数组)

//5. 函数指针：存放函数地址的指针
//数组指针 - 是指向数组的指针
//函数指针 - 是指向函数的指针
//#include <stdio.h>
//int Add(int x,int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	//int arr[10] = { 0 };
//	//&arr
//	//arr
//	printf("%p\n", &Add);
//	printf("p%\n", Add);
//	//&函数名 和 函数名，相同的概念
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*pa)[10] = &arr;
//
//	int a = 10;
//	int b = 20;
//	//int* p(int, int) = Add;
//	//类比数组指针，()比*优先级高，为了保证是指针类型，*p先结合
//	int (*p)(int,int) = Add;//int (*p)(int x,int y) = Add;也可以
//	//p存放的是Add的地址变量
//	printf("%d\n",(*p)(2, 3));
//	return 0;
//}

//#include <stdio.h>
//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	void (*p)(char*) = Print;//p变量的void (*)(char*)类型
//	(*p)("hello bit");//"hello bit"传入的本身是首字符的地址
//	return 0;
//}

//阅读两段有趣的代码：
//注 : 推荐《C陷阱和缺陷》-这本书中提及这两个代码。
//代码1
//( * ( void (*)() ) 0 )(); //void (*)()-函数指针类型
//解释：
//把0强制类型转换成函数指针类型void (*)()，0就是一个函数的地址，即想把0当作某函数的地址
//解引用*(void(*)())0该地址找到该函数，调用函数(*(void(*)())0) ()
//即调用0地址处的参数为无参返回值为void的函数

//代码2
//void (*signal(int, void(*)(int)))(int);
//解释：
//函数名为signal，函数的参数：第一个参数为整型int，第二个参数为函数指针类型void(*)(int)，该函数指针指向的函数的参数是int，返回类型是void
//函数的声明：即该函数signal返回的类型也是void (*)(int)函数指针，该函数指针也指向的函数的参数是int，返回类型是void
//代码2太复杂，如何简化：
//typedef void(* pfun )(int);//可以理解为typedef void(*)(int) pfun;
//pfun signal(int, pfun);
//类似与typedef unsigned int u_int;

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int (*p)(int,int) = Add;
//	printf("%d\n",(*p)(2, 3));
//	//因为p存的是Add，故二者相等
//	printf("%d\n", p(2, 3));//即：p = Add，类似与数组指针，即p(2, 3) = Add(2, 3)
//	//函数指针调用可以不解引用，或者多次解引用都是相同的效果
//	printf("%d\n", (**p)(2, 3));
//	printf("%d\n", (***p)(2, 3));
//	return 0;
//}

//6. 函数指针数组 - 存放函数指针地址的数组
//int* arr[10];
//数组的每个元素是int*

//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	//指针数组 - 存放指针地址的数组
//	int* arr[5];
//	//函数指针p1、p2、p3、p4
//	/*int (*p1)(int,int) = Add;
//	int (*p2)(int, int) = Sub;
//	int (*p3)(int, int) = Mul;
//	int (*p4)(int, int) = Div;*/
//	//可以使用一个数组，存放这四个函数的指针地址，即函数指针数组
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	//可理解为：int(*)(int,int) parr[4]
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", (*parr[i])(2, 3));//可以不写*，parr[i](2, 3)，解引用i下标的函数地址，并调用函数
//		//printf("%d\n", parr[i](2, 3));
//	}
//	return 0;
//}

//例如：char* my_strcpy(char* dest, const char* src);
//写一个函数指针pf，指向my_strcpy
//char* my_strcpy(char* dest, const char* src);
//char* (*pf)(char*, const char*) = my_strcpy;
//写一个函数指针数组pfArr，存放4个my_strcpy函数的地址
//char* (*pfArr[4])(char*, const char*) = { my_strcpy };

//函数指针数组的用途：也叫转移表
//例子：（计算器）
//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//void menu()
//{
//	printf("********  0、EXIT  ********\n");
//	printf("***** 1、Add   2、Sub *****\n");
//	printf("***** 3、Mul   4、Div *****\n");
//	printf("********  5、Xor   ********\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do 
//	{
//		menu();
//		printf("选择操作：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("输入两个整形操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d + %d = %d\n", x, y, Add(x, y));
//			break;
//		case 2:
//			printf("输入两个整形操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d - %d = %d\n", x, y, Sub(x, y));
//			break;
//		case 3:
//			printf("输入两个整形操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d × %d = %d\n", x, y, Mul(x, y));
//			break;
//		case 4:
//			printf("输入两个整形操作数：>");
//			scanf("%d%d", &x, &y);
//			printf("%d ÷ %d = %d\n", x, y, Div(x, y));
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误，重新选择！\n");
//			break;
//		}
//	} while (input);	
//}
//缺点：1、代码冗余 2、添加功能不方便

//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int (*pArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("选择操作：>");
//		scanf("%d", &input);
//		
//		if (input >= 1 && input <= 5)//这个5需根据函数的个数而定
//		{
//			printf("输入两个整形操作数：>");
//			scanf("%d%d", &x, &y);
//			int ret = pArr[input](x, y);//可以不写*，((*pArr)[input])(x,y)
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误，重新选择！\n");
//		}
//	} while (input);
//	return 0;
//}

//7. 指向函数指针数组的指针
//指向函数指针数组的指针是一个指针.指针指向一个 数组 ，数组的元素都是 函数指针
//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*pArr)[4] = &arr;//数组指针
//
//	int (*pf)(int,int)=Add;//pf是函数指针
//	int (*pfArr[4])(int, int);//pfArr是一个函数指针数组
//
//	int (*(*ppfArr)[4])(int, int)=&pfArr;//保存函数指针数组地址的指针
//	//即*ppfArr是一个指针，类型是int (*[4])(int, int)
//	//ppfArr是一个数组指针，指向的数组有四个元素
//	//指向的数组的每个元素的类型是一个函数指针int(*)(int, int)
//
//	return 0;
//}

//8. 回调函数
//回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，
//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，
//而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
//#include <stdio.h>
//void test(void (*p)(char*))//用函数指针接收参数
//{
//	printf("test\n");
//	p("bit");//p指向Print函数，调用Print
//}
//void Print(char *str)//Print是回调函数
//{
//	printf("%s\n",str);
//}
//int main()
//{
//	test(Print);//地址作为参数
//	return 0;
//}

//减少代码的冗余
//#include <stdio.h>
//void Calc(int (*pfun)(int ,int))//使用函数指针
//{
//	int x = 0;
//	int y = 0;
//	printf("输入两个整形操作数：>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pfun(x, y));
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("********  0、EXIT  ********\n");
//	printf("***** 1、Add   2、Sub *****\n");
//	printf("***** 3、Mul   4、Div *****\n");
//	printf("***************************\n");
//}
//int main()
//{
//	int input = 0;
//	do 
//	{
//		menu();
//		printf("选择操作：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);//将函数作为地址传入
//			break;
//		case 2:
//			Cala(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误，重新选择！\n");
//			break;
//		}
//	} while (input);	
//}

//无类型指针
//#include <stdio.h>
//{
//	int a = 10;
//	int* pa = &a;
//	//char* pc = &a;
//	char ch = 'w';
//
//	void* p = &a;//void* 类型的指针，可以接收任意类型的地址
//	p = &ch;
//	*p = 0;//报错，void*类型的指针，不能进行解引用操作，因为不知道访问几个字节
//	p++;//也会报错，void*类型的指针，不能进行指针+/-整数的操作，因为不知道步长访问几个字节
//	return 0;
//}

//以前的冒泡排序只能排整形数据，C语言提供了一个库函数：qsort - quick sort函数可以实现任意数据的排序
//#include <stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//外层控制比较的轮数
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//里层控制每轮排出的最大数
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//qsort函数的使用：MSDN搜索qsort
//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
//第一个参数：void* base - base:Start of target array目标数组的首元素地址
//即：待排序数组的首元素地址
//第二个参数：size_t num - num:Array size in elements数组的元素个数
//即：待排序数组的元素个数
//第三个参数：size_t width - width:Element size in bytes元素的大小
//待排序数组的每个元素的大小-单位字节
//第四个参数：int(* compare)(const void* elem1, const void* elem2) - compare的类型是函数指针类型
//第四个参数是指向我们要实现的比较函数，由于接收的函数的参数是函数指针类型，故设计比较函数应：
//该指向的函数的要求是：
//1、函数类型是int(函数名)(const void* elem1, const void* elem2)，具体类型的数据值之间的比较
//2、两个地址比较的结果大于0，返回大于0的数，结果小于0，返回小于0的数，等于0返回等于0的数。
//即：函数指针，比较两个元素的所以函数的地址-这个函数使用者自己实现
//函数指针的两个参数是：待比较的两个元素的地址
//#include <stdio.h>
//#include <stdlib.h>//qsort库函数的头文件
//#include <string.h>
//int compare_int(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);//由于不能解引用，故需要强制类型转换为int*类型的地址
//}
//void test1()
//{
//	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), compare_int);//传入compare_int的地址，先调用int(* compare)(const void* elem1, const void* elem2)，再指向具体的比较函数
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int compare_float(const void* e1, const void* e2)
//{
//	//retrun (int)(*((float*)e1) - *((float*)e2));//这种方法有缺陷
//	if (*((float*)e1) == *((float*)e2))
//	{
//		return 0;
//	}
//	else if (*((float*)e1) > *((float*)e2))
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//void test2()
//{
//	float f[10] = { 2.0,4.0,7.0,3.0,5.0,8.0,9.0,1.0,0.0,6.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), compare_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int compareStu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//void test3() 
//{
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",20} };//结构体数组
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), compareStu_by_age);
//	//输出
//}
//int compareStu_by_name(const void* e1, const void* e2)
//{
//	//比较字符串，不能使用关系运算符，使用strcmp库函数，结果大于0，恰好返回大于0的数，结果小于0，返回小于0的数，等于0返回等于0的数。
//	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
//}
//void test4()
//{
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",20} };//结构体数组
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), compareStu_by_name);
//	//输出
//}
//
//int main()
//{
//	test1();
//	test2();
//	test3();
//	test4();
//	return 0;
//}

//模拟实现qsort函数，假设函数名为bubble_sort
//#include <stdio.h>
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
////bubble_sort的实现
//void bubble_sort(void* base, int sz, int width, int (*compare)(void* e1, void* e2))
//{
//	//void* base :保证可以接收任意类型的首元素地址，如：接收arr、s，故为void*
//	//int sz :以便元素之间比较所需要的轮数和每轮的次数，故为sz
//	//int width :由于不能传入类型，而有需要知道元素的类型，通过元素的大小即保证任意类型元素之间可以实现步长，故为width
//	//int (*compare)(void* e1,void* e2) :指向实现比较功能的函数，即compare指向任意具体数据类型的函数
//	//返回类型为int，判断结果的大小
//	//实现bubble_sort函数的程序员，不知道未来排序的数据类型。程序员也不知道，待比较的两个元素的类型，故为void* e1,void* e2
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//外层控制比较的轮数
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//里层控制每轮排出的最大数
//		{
//			//两相邻元素的比较
//			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//				//如何实现两两相邻元素的比较
//				//compare(base,base+1)//error:void* 不能指针+/-整数
//				//compare(base,(int*)base+1)//error:不适用于任意类型元素的比较
//				//compare((char*)base+j*width,(char*)base+(j+1)*width)//任意类型的元素，width是不同的，每次相邻元素比较之后，跳过width个字节
//			{
//				//交换元素的功能
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//int compare_int(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//void test1()
//{
//	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//使用bubble_sort的程序员一定知道自己排序的是什么类型的据
//	//就应该知道如何比较待排序数组中的元素
//	bubble_sort(arr, sz, sizeof(arr[0]), compare_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int compareStu_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//void test3() 
//{
//	struct Stu s[3] = { {"zhangsan",20},{"lisi",10},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), compareStu_by_age);
//	//输出
//}
//int main()
//{
//	test1();
//	return 0;
//}
//错误"函数重定义，不同的基类型"：方法在还未声明的地方就使用了。由于使用的地方与定义的地方都是在同一个.c文件中，所以没有报未声明的错误。
//解决方法：把实现放到使用的前面，或者在include语句和宏定义后面加上函数声明

//总结一下：以整形为例
//整形指针
//int a = 0; int b = 0; int c = 0;
//int *pa = &a;//在整型的基础上，由于是指针，则用*p代替变量名
////整形指针数组
//int arr[10] = { 0 };
//int *(parr[5]) = { &a,&b,&c };//在整型指针的基础上，由于是数组，则用arr[]代替变量名，由于[]比*先结合，可以省略int *parr[5] = { &a,&b,&c };
////整型指针数组的指针
//int *((*Parr)[5])=&parr;//在整型指针数组的基础上，由于是指针，则用*p代替变量名，由于[]比*先结合，可以省略int *(*Parr)[5]=&parr;
//
////整型数组指针
//int arr[10];
//int (*pa)[10]=&arr; int (*pb)[10] = &arr; int (*pc)[10] = &arr;//在整型数组的基础上，由于是指针，则用*p代替变量名
////整型数组指针的数组
//int (*(pArr[]))[10] = { &pa,&pb,&pc };//在整型数组指针的基础上，由于是数组，则用arr[]代替变量名，由于[]比*先结合，可以省略int (*pArr[])[10] = { &pa,&pb,&pc };
//
////函数指针
//int Add(int x, int y); int Sub(int x, int y); int Div(int x, int y);
//int (*pFa)(int, int) = Add; int (*pFb)(int, int) = Sub; int (*pFc)(int, int) = Div;//在函数的基础上，由于是指针，则用*p代替函数名
////函数指针数组
//int (*(pFArr[]))(int, int) = {Add,Sub,Div};//在函数指针的基础上，由于是数组，则用arr[]代替变量名，由于[]比*先结合，可以省略int (*pFArr[])(int, int) = {Add,Sub,Div};
////函数指针数组的指针
//int (*((*PFArr)[]))(int, int) = &pFArr;//在函数指针数组的基础上，由于是指针，则用*p代替变量名，由于[]比*先结合，可以省略int (*(*pFArr)[])(int, int);
//