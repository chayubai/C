#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//指针
//1. 指针是什么
//指针是什么？
//指针理解的2个要点：
//1. 指针是内存中一个最小单元的编号，也就是地址
//2. 平时口语中说的指针，通常指的是指针变量，是用来存放内存地址的变量
//总结：指针就是地址，口语中说的指针通常指的是指针变量。

//指针
//指针是变量，存放内存单元的地址(编号)，是用来存放地址的变量（存放在指针中的值都被当成地址处理）
//指针变量
//我们可以通过& （取地址操作符）取出变量在内存中的起始地址，把地址可以存放到一个变量中，这个变量就是指针变量
/*
#include <stdio.h>
int main()
{
    int a = 10;//在内存中开辟一块空间
    int* p = &a;//这里我们对变量a，取出它的地址，可以使用&操作符。
    //a变量占用4个字节的空间，这里是将a的4个字节的第一个字节的地址存放在p变量中，p就是一个指针变量。
        
    return 0;
}
*/
//在32位的机器上，地址是32个0或1组成二进制序列，那地址就得用4个字节的空间来存储，所以一个指针变量的大小就应该是4个字节。
//那如果在64位机器上，就有64个地址线，每个地址是由64个0或1组成的二进制序列，那一个指针变量的大小是8个字节，才能存放一个地址。
//总结：
//指针是用来存放地址的，地址是唯一标识一块地址空间的。
//指针的大小在32位平台是4个字节，在64位平台是8个字节。

//指针的大小
/*
#include <stdio.h>
int main()
{
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(double*));

	return 0;
}
*/

//2. 指针和指针类型
//这里我们再讨论一下：指针的类型
//我们都知道，变量有不同的类型，整形，浮点型等。那指针有没有类型呢？
//准确的说：有的。
//int num = 10;
//p = &num;
//要将& num（num的地址）保存到p中，我们知道p就是一个指针变量，那它的类型是怎样的呢？
//我们给指针变量相应的类型。
//char* pc = NULL;
//int* pi = NULL;
//short* ps = NULL;
//long* pl = NULL;
//float* pf = NULL;
//double* pd = NULL;
//这里可以看到，指针的定义方式是： type + *。
//其实：
//char* 类型的指针是为了存放 char 类型变量的地址。
//short* 类型的指针是为了存放 short 类型变量的地址。
//int* 类型的指针是为了存放 int 类型变量的地址。

//指针类型的意义1：
//1个十六进制位是4个二进制位，2个十六进制位占1字节
/*
#include <stdio.h>
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("%p\n", pa);
	printf("%p\n", pc);//pa 和pc都是用来存放地址的，所以结果相同，但会报警告
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	int a = 0x11223344;
	printf("%x\n", a);//11223344
	printf("%p\n", &a);

	int* pa = &a;
	*pa = 0;
	printf("%x\n", a);//0
	printf("%p\n", pa);
	return 0;
}
*/
//调试Fn+F10-窗口-内存，输入&a得到a变量的地址指向的内容为“44 33 22 11”（地址指向的内存中的数据的存放顺序可能顺的可能倒的）
//当调试到*pa = 0;&a地址指向的内容变为了“00 00 00 00”

/*
#include <stdio.h>
int main()
{
	int a = 0x11223344;
	printf("%x\n", a);//11223344
	printf("%p\n", &a);

	char* pa = &a;
	*pa = 0;
	printf("%x\n", a);//11223300
	printf("%p\n", pa);
	return 0;
}
*/
//调试Fn+F10-窗口-内存，输入&a得到a变量的地址指向的内容为“44 33 22 11”（地址指向的内存中的数据的存放顺序可能顺的可能倒的）
//当调试到*pa = 0;&a地址的内容变为了“00 33 22 11”

//指针类型的意义：指针类型决定了指针进行解引用操作的时候，能够访问到的空间的大小
//当为int*，p解引用能够访问4个字节
//当为char*，p解引用能够访问1个字节
//当为double*，p解引用能够访问8个字节

//指针类型的意义2：
/*
#include <stdio.h>
int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("%p\n", pa);
	printf("%p\n", pa+1);
	printf("%p\n", pc);
	printf("%p\n", pc+1);

	return 0;
}
*/
//指针类型的意义：指针的类型决定了指针向前或者向后走一步有多大（距离）。
//当为int*，p+1向后偏移了4个字节
//当为char*，p+1向后偏移了1个字节
//当为double*，p+1向后偏移了8个字节

/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = arr;//数组名，首元素地址
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;//每次步长为4个字节，即指向下一个int元素的地址
	}

	return 0;
}
*/
//调试-窗口-监视：arr、i
//发现数组的每个元素,每循环一次就被改为了1
//调试-窗口-内存：arr
//发现数组的每个元素由“00 00 00 00”,每循环一次就被改为了“01 00 00 00”

/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	char* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)//每次步长1个字节，即指向下一个1个字节的地址
	{
		*(p + i) = 1;
	}

	return 0;
}
//调试-窗口-内存：arr
//循环一次，改变一个字节，发现只有前十个字节被改为了“01”后，直接跳出程序
*/

//3. 野指针：非法访问，是不正确的
//概念： 野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）
//1. 指针未初始化
/*
#include <stdio.h>
int main()
{
    int a;//局部变量不初始化，默认随机值 
    int* p;//局部变量指针未初始化，默认为随机地址
    *p = 20;//通过随机地址试图改变地址指向的内容，非法访问
    return 0;
}
*/

//2. 指针越界访问
/*
#include <stdio.h>
int main()
{
    int arr[10] = { 0 };
    int* p = arr;
    int i = 0;
    for (i = 0; i <= 11; i++)
    {
        //当指针指向的范围超出数组arr的范围时，即i = 10、11的时候，p就是野指针
        *(p++) = i;//即*p++ = i;先执行p++,再执行*p相当于*p = i;p++;
    }
    return 0;
}
*/

//3. 指针指向的空间被释放
/*
#include <stdio.h>
int* test()
{
    int a = 10;//局部变量出作用域，内存被销毁
    return &a;
    int arr[10] = { 0 };//局部变量出作用域，内存被销毁
    //return arr;
}
int main()
{
   int* p =  test();//接收到了a或arr的地址，此时a或arr的地址被内存回收了，该地址可能被其他进程使用
   printf("%d\n",*p);//非法访问
   *p = 20;//再通过该指针里面的地址访问（操作）指向的空间内容，此时访问（操作）的是别人的空间，不再是a的空间（已经回收了）
    return 0;
}
*/
//这种是正确的
/*
#include <stdio.h>
int* test()
{
    static int a = 10;//静态变量出作用域，内存不被销毁
    return &a;
}
int main()
{
    int* p = test();//接收到了a的地址，
    *p = 20;
    return 0;
}
*/

//如何规避野指针
//1. 指针初始化
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//初始化

	//当不知道给指针初始化什么地址时，赋值空指针
	int* p = NULL;//必须大写

	//转到定义：#define NULL ((void *)0)，把0强制转换为void*类型
	return 0;
}
*/
//2. 小心指针越界
//3. 指针指向空间使用完后进行释放，并置NULL，防止再操作该指针，操作空指针会报错
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//初始化
	*pa = 20;
	//使用完pa后，置值为NULL
	pa = NULL;
	return 0;
}
*/
//4. 避免返回局部变量的地址
//5. 指针使用之前检查有效性
/*
#include <stdio.h>
int main()
{
	int* pa = NULL;//初始化
	int a = 10;
	pa = &a;
	if (pa != NULL)
	{
		*pa = 20;
	}
	return 0;
}
*/

//4. 指针运算
//指针 +/-整数
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", *p);
	//	p = p + 1;//也可以是p++
	//}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *p);//1 3 5 7 9
		p += 2;//注意指针越界
	}
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = &arr[9];
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *p);//10 8 6 4 2
		p  -= 2;
	}
	
	return 0;
}
*/
/*
#define N_VALUES 5
#include <stdio.h>
int main()
{
	float values[N_VALUES];//创建数组values[5]
	float* vp;//创建指针
	//指针+/-整数；指针的关系运算
	for (vp = &values[0]; vp < &values[N_VALUES];)//指针初始化，调整部分用vp++，放在了循环体中
	{
		*vp++ = 0;//先执行vp++（先赋值，再++），再执行*vp
		//即*vp = 0;vp++;
	}
	return 0;
}
*/

//指针 - 指针
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("%d\n", &arr[9] - &arr[0]);//9
	//&arr[0]                                      &arr[9]
	//[ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ][ 8 ][ 9 ]
	printf("%d\n", &arr[0] - &arr[9]);//-9
	//同一块空间的指针：大地址-小地址 = 中间元素的个数
	//int ch[5] = { 0 };
	//printf("%d\n", &arr[9] - &ch[0]);//无意义
	return 0;
}
*/

//模拟实现strlen()函数，求字符串长度
#include <stdio.h>
//1、计数器方法
/*
int my_strlen(char* str)
{
	char* p = str;
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
		//p++;
	}
	return count;
}
*/
//2、递归方法
//bit
//strlen("bit");
//= 1 + strlen("it");
//= 1 + 1 + strlen("t");
//= 1 + 1 + 1 + strlen("")
/*
int my_strlen(char* str)
{
	char* p = str;

	if (*p != '\0')
	{
		p++;
		return 1 + strlen(p);
	}
}
*/
//3、指针 - 指针
/*
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;//此时，即'\0'的地址-'\b'的地址
}
int main()
{

	
	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("%d\n", len);

	return 0; 
}
*/

//指针的关系运算
/*
#define N_VALUES 5
#include <stdio.h>
int main()
{
	float values[N_VALUES];//创建数组values[5]
	float* vp;//创建指针
	//指针+/-整数；指针的关系运算
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;//先执行--vp（先--，再赋值），再执行*vp
	}
	//支持上面这种书写，但不支持下面这种书写
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
	{
		*vp = 0;
	}
	//实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写
	//标准规定：
		//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。
		//如：vp不可以和数组最后一个元素的越界的地址&arr[-1]比较，但可以与第一个元素的越界的地址&arr[5]比较
	return 0;
}
*/

//5. 指针和数组
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", arr + 1);
	//相差一个int型的字节的大小，即4个字节
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0] + 1);
	//相差一个int型的大小，即4个字节
	//总结：数组名表示的是数组首元素的地址。
	printf("%p\n", &arr);
	printf("%p\n", &arr + 1);
	//相差一个int[10]数组的字节的大小，即40个字节
	//1、&arr ： &数组名 ，数组名不是首元素的地址 ，数组名表示整个数组 ，&数组名取出的是整个数组的地址
	//2、sizeof(arr) ： sizeof(数组名) ，数组名表示整个数组 ，sizeof(数组名)计算的是整个数组的大小
	
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("&arr[%d] = %p   <====>   p+%d = %p\n", i, &arr[i], i, p + i);//&arr[i]和p+i的地址相同
	}
	return 0;
}
*/
//注意：内存的空间大小，是按字节编址的，
//但是存放的数据类型不同所占用的空间不同，此时相邻元素的地址编号就不一定是相邻的，可能差某个倍数关系
//如：int arr[5];假设&arr[0] = 0x11223300
//则&arr[1] = 0x11223304，&arr[2] = 0x11223308，arr[3] = 0x1122330c
//如：char arr[5];假设&arr[0] = 0x11223300
//则&arr[1] = 0x11223301，&arr[2] = 0x11223302，&arr[3] = 0x11223303
//既然可以把数组名当成地址存放到一个指针中，我们使用指针来访问每一个元素就成为了可能。
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	int* p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	//用下标遍历数组元素
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	//用指针遍历数组元素，并赋值
	for (i = 0; i < sz; i++)
	{
		*(p + i) = i;
		printf("%d ", *(p+i));//p+i 其实计算的是数组 arr 下标为i的地址。
	}
	return 0;
}
*/

//6. 二级指针
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;//pa存放的是a的地址，pa的类型是int*，指向的对象里面存储的是int类型的数据
	int* * ppa = &pa;//ppa存放的是pa的地址，即ppa是二级指针，ppa的类型是int**，指向的对象里面存储的是int*类型的数据
	int** * pppa = &ppa;//三级指针

	//二级指针的使用
	* *ppa = 20;
	printf("%d\n", **ppa);
  //*ppa 通过对ppa中保存的地址进行解引用，这样找到的是pa ， *ppa 其实访问的就是 pa .
  //**ppa 先通过 *ppa 找到 pa ,然后对 pa 进行解引用操作： *pa ，那找到的是 a .
	printf("%d\n",a);

	return 0;
}
*/

//7. 指针数组
//整型数组，字符数组，指针数组
//整型数组-数组里面存放的是整型
//字符数组-数组里面存放的是字符
//指针数组-数组里面存放的是同一类指针类型的指针变量，如：int* p[10];char* p[10];...
//数组指针-存放数组地址的指针，如：int arr[10];int (*p)[10] = &arr;
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int arr[3];//整型数组

	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	int* p[3] = { &a,&b,&c };//指针数组
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", * (p[i]));//对地址解引用找到对应元素的值
	}
	return 0;
}
*/