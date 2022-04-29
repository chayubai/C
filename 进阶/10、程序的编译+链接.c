#define _CRT_SECURE_NO_WARNINGS 1
//程序环境和预处理
//C代码(ASCII码，文本文件)       编译     链接          二进制的信息(二进制文件)           运行
//test.c源文件(源程序)      ------------------------->            test.exe        ---------------------->
//                           翻译环境（编译器、链接器）                                   运行环境
//test.c                           test.obj/test.o                    a.out
//add.c                            add.obj（Linux目标文件默认为add.o）a.out（Linux可执行文件默认为a.out）                              
//            编译     ------   目标文件  -------   链接  ------ 可执行文件
//      预编译  编译  汇编   
//预处理过程(文本操作)：头文件的包含的处理，#define、注释删除即使用空格替换注释...     
//Linux  gcc -E test.c将test.c进行预处理/预编译
//gcc -E test.c > test.i将预编译产生的信息输出到test.i中
//编译过程：语法分析、词法分析、语义分析、符号汇总
//Linux  gcc -S test.i将test.i进行编译，产生test.s的汇编代码。即将C语言代码翻译成汇编代码
//编译原理 - 《程序员的自我修养》
//汇编过程：形成符号表，将汇编代码转换成二进制指令
//Linux  gcc -c test.s将test.s进行编译，产生test.o的二进制代码(即obj的目标文件)
//链接过程：合并段表、符号表的合并和重定位

//1、程序的翻译环境
//在ANSI C的任何一种实现中，存在两个不同的环境。
//第1种是翻译环境，在这个环境中源代码被转换为可执行的机器指令。
//第2种是执行环境，它用于实际执行代码。

//2、详解：C语言程序的编译 + 链接
//翻译环境
//组成一个程序的每个源文件通过编译过程分别转换成目标代码（object code）。
//每个目标文件由链接器（linker）捆绑在一起，形成一个单一而完整的可执行程序。
//链接器同时也会引入标准C函数库中任何被该程序所用到的函数，而且它可以搜索程序员个人的程序库，
//将其需要的函数也链接到程序中。
//如：
//创建test.c文件，写入以下代码
//#include <stdio.h>
//int main()
//{
//	extern int Add(int x, int y);
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
////创建add.c文件，写入以下代码
//int Add(int x, int y)
//{
//	return  x + y;
//}

//sum.c
//int g_val = 2016;
//void print(const char* str)
//{
//	printf("%s\n", str);
//}
////test.c
//#include <stdio.h>
//int main()
//{
//	extern void print(char* str);
//	extern int g_val;
//	printf("%d\n", g_val);
//	print("hello bit.\n");
//	return 0;
//}

//编译本身也分为几个阶段
//1. 预处理 选项 gcc -E test.c -o test.i
//预处理完成之后就停下来，预处理之后产生的结果都放在test.i文件中。
//2. 编译 选项 gcc - S test.c
//编译完成之后就停下来，结果保存在test.s中。
//3. 汇编 gcc - c test.c
//汇编完成之后就停下来，结果保存在test.o中。

//运行环境
//程序执行的过程：
//1. 程序必须载入内存中。在有操作系统的环境中：一般这个由操作系统完成。在独立的环境中，
//程序的载入必须由手工安排，也可能是通过可执行代码置入只读内存来完成。
//2. 程序的执行便开始。接着便调用main函数。
//3. 开始执行程序代码。这个时候程序将使用一个运行时堆栈（stack），存储函数的局部变量和返回地址。
//程序同时也可以使用静态（static）内存，存储于静态内存中的变量在程序的整个执行过程一直保留他们的值。
//4. 终止程序。正常终止main函数；也有可能是意外终止。
//注：介绍一本书《程序员的自我修养》

//预编译详解
//预定义符号
//__FILE__      //进行编译的源文件
//__LINE__     //文件当前的行号
//__DATE__    //文件被编译的日期
//__TIME__    //文件被编译的时间
//__STDC__    //如果编译器遵循ANSI C，其值为1(gcc)，否则未定义(VS)
//这些预定义符号都是语言内置的。
//#include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);//源文件的绝对路径
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//  printf("%s\n", __FUNCTION__);//获取函数名
//	return 0;
//}

//写日志文件
//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("log.txt", "w");
//	int arr[10] = { 0 };
//    int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//预编译阶段详讲：预处理指令详解
//3、预处理指令 #define
//#define
//#include
//#pragma
//#if
//#endif
//#ifdef    
//...

//#define 定义标识符
//语法：
//#define name stuff
//如：
//#include <stdio.h>
//#define MAX 100
//#define STR "hehe"
//#define reg register          //为 register这个关键字，创建一个简短的名字
//#define do_forever for(;;)    //用更形象的符号来替换一种实现
//#define CASE break;case       //在写case语句的时候自动把 break写上。
//// 如果定义的 stuff过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。
//#define DEBUG_PRINT printf("file:%s\tline:%d\t\date:%s\ttime:%s\n",\__FILE__,__LINE__ ,__DATE__,__TIME__ )  
//
//int main()
//{
//    register int a;
//    reg int b;
//    printf("%s\n", STR);
//    do_forever;//相当于for (;;);
//    //for(;;)不写分号，循环体的内容为return 0;
//    return 0;
//}

//提问：在define定义标识符的时候，要不要在最后加上; ?
//#include <stdio.h>
//#define A 100
//#define MAX 100;
//int main()
//{
//    int a = A;//预编译时会将A替换为100
//    int b = MAX;//预编译时会将MAX替换为100;
//    //即int b = MAX;;
//    //printf("%d\n", MAX);//此时就会报错
//    if(1)
//      max = MAX;//报错：替换为了100;语句块含两条语句，需用大括号
//    else
//      max = 0;
//    return 0;
//}
//建议不要加上 ; ,这样容易导致问题。

//#define 定义宏
//#define 机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（define macro）。
//下面是宏的申明方式：
//#define name( parament-list ) stuff
//其中的 parament - list 是一个由逗号隔开的符号表，它们可能出现在stuff中。
//注意：
//参数列表的左括号必须与name紧邻。
//如果两者之间有任何空白存在，参数列表就会被解释为stuff的一部分。
//如：
//#define SQUARE(x) x * x
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5);
//    //即：int ret = 5*5;
//    printf("%d\n", ret);//25
//    return 0;
//}

//宏是替换不是传参
//#define SQUARE(x) x * x
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5+1);
//    //即：int ret = 5+1*5+1;
//    printf("%d\n", ret);//11
//    return 0;
//}
//改正
//#define SQUARE(x) (x) * (x)
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5 + 1);
//    //即：int ret = (5+1)*(5+1);
//    printf("%d\n", ret);//36
//    return 0;
//}

//不要吝啬括号
//#define DOUBLE(x) x + x
//#include <stdio.h>
//int main()
//{
//    int a = 5;
//    int ret = 10 * DOUBLE(a);
//    //即：int ret = 10 * a+a;
//    printf("%d\n", ret);//55
//    return 0;
//}
//#define DOUBLE(x) ((x) + (x))
//#include <stdio.h>
//int main()
//{
//    int a = 5;
//    int ret = 10 * DOUBLE(a);
//    //即：int ret = 10 * ((a)+(a));
//    printf("%d\n", ret);//100
//    return 0;
//}

//#define 替换规则
//在程序中扩展#define定义符号和宏时，需要涉及几个步骤。
//1. 在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，它们首先被替换。
//2. 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
//3. 最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程。
//注意：
//1. 宏参数和#define 定义中可以出现其他#define定义的变量。但是对于宏，不能出现递归。
//2. 当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索。
//#include <stdio.h>
//void Print(int x)
//{
//	printf("the value of a is %d\n", x);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Print(a);
//	Print(b);
//	return 0;
//}

//#include <stdio.h>
//#define PRINT(x) printf("the value of x is %d\n", x)
//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");
//	printf("hel" "lo" " world\n");
//
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}
//3、预处理操作符#和##的介绍
//如何把参数插入到字符串中？
//#的作用
//#include <stdio.h>
//#define PRINT(x) printf("the value of "#x" is %d\n", x)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//即printf("the value of ""a"" is %d\n",a);
//	PRINT(b);
//	//即printf("the value of ""b"" is %d\n",b);
//
//	return 0;
//}

//## 的作用
//##可以把位于它两边的符号合成一个符号。它允许宏定义从分离的文本片段创建标识符。#include <stdio.h>
//#include <stdio.h>
//#define CAT(X, Y) X##Y
//int main()
//{
//	int Class84 = 2019;
//	printf("%d\n", Class84);
//	printf("%d\n", CAT(Class, 84));
//	//即printf("%d\n", Class##84);
//	//printf("%d\n", Class84);
//
//	return 0;
//}
//注：这样的连接必须产生一个合法的标识符。否则其结果就是未定义的。

//带副作用的宏参数
//当宏参数在宏的定义中出现超过一次的时候，如果参数带有副作用，那么你在使用这个宏的时候就可能出现危险，
//导致不可预测的后果。副作用就是表达式求值的时候出现的永久性效果。
//x+1;//不带副作用
//x++;//带有副作用
//#include <stdio.h>
//#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//即int max = ((a++)>(b++)?(a++):(b++))
//	//           a = 10   b = 11      b = 13     
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//
//	return 0;
//}

//4、宏和函数的对比
//宏通常被应用于执行简单的运算。比如在两个数中找出较大的一个。#define MAX(a, b) ((a) > (b) ? (a) : (b))
//那为什么不用函数来完成这个任务？
//原因有二：
//1. 用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需要的时间更多。所以宏比
//函数在程序的规模和速度方面更胜一筹。
//2. 更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之
//这个宏怎可以适用于整形、长整型、浮点型等可以用于 > 来比较的类型。宏是类型无关的。
//#include <stdio.h>
////函数-1
//int Max1(int x, int y)
//{
//	return (x > y ? x : y);
//}
////函数-2
//float Max2(float x, float y)
//{
//	return (x > y ? x : y);
//}
////宏
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 2.0f;
//	float d = 3.0f;
//
//  //函数在调用的时候，会有函数调用和返回的开销
//	int max = Max1(a, b);
//	printf("max = %d\n", max);
//	max = MAX(a, b);
//	printf("max = %d\n", max);
//
//	max = Max2(c, d);
//	printf("max = %d\n", max);
//	max = MAX(c, d);
//	printf("max = %d\n", max);
//	
//	return 0;
//}

//当然和宏相比函数也有劣势的地方：
//1. 每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
//2. 宏是没法调试的。
//3. 宏由于类型无关，也就不够严谨。
//4. 宏可能会带来运算符优先级的问题，导致程容易出现错。
//宏有时候可以做函数做不到的事情。比如：宏的参数可以出现类型，但是函数做不到。
//#include <stdio.h>
//#define SIZEOF(type) sizeof(type) 
//int main()
//{
//	int ret = SIZEOF(int);
//	return 0;
//}

//#include <stdio.h>
//#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
//int main()
//{
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	
//	int* p2 = MALLOC(10, int);//类型作为参数
//	//预处理器替换之后：int* p2 = (int*)malloc(10 * sizeof(int));
//	return 0;
//}

//宏和函数的一个对比:
//属
//性          #define定义宏                                            函数
//
//代
//码			每次使用时，宏代码都会被插入到程序中。除了非常           函数代码只出现于一个地方；每次使用这个函数时，
//长			小的宏之外，程序的长度会大幅度增长						 都调用那个地方的同一份代码
//度        
//                        
//执
//行			更快													 存在函数的调用和返回的额外开
//速																	 销，所以相对慢一些
//度
// 
//操
//作			宏参数的求值是在所有周围表达式的上下文环境里，           函数参数只在函数调用的时候求
//符			除非加上括号，否则邻近操作符的优先级可能会产生			 值一次，它的结果值传递给函
//优			不可预料的后果，所以建议宏在书写的时候多些括号。         数。表达式的求值结果更容易预测。
//先
//级
//
//带
//有
//副			参数可能被替换到宏体中的多个位置，所以带有副作			 函数参数只在传参的时候求值一
//作			用的参数求值可能会产生不可预料的结果。					 次，结果更容易控制。
//用
//的
//参
//数
//
//参
//数			宏的参数与类型无关，只要对参数的操作是合法的，			 函数的参数是与类型有关的，如
//类			它就可以使用于任何参数类型。							 果参数的类型不同，就需要不同
//型																     的函数，即使他们执行的任务是不同的。
//
//调			宏是不方便调试的										 函数是可以逐语句调试的
//试
// 
//递
//归			宏是不能递归的											 函数是可以递归的

//命名约定
//一般来讲函数和宏的使用语法很相似。所以语言本身没法帮我们区分二者。
//那我们平时的一个习惯是：
//把宏名全部大写
//函数名不要全部大写

//5、预处理指令 #undef
//这条指令用于移除一个宏定义。
//#undef NAME
//如果现存的一个名字需要被重新定义，那么它的旧名字首先要被移除。

//6、命令定义
//许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。
//例如：当我们根据同一个源文件要编译出不同的一个程序的不同版本的时候，这个特性有点用处。
//（假定某个程序中声明了一个某个长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另外一
//个机器内存大写，我们需要一个数组能够大写。）
//在Linux中写入programe.c
//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}
//编译指令：gcc - D ARRAY_SIZE = 10 programe.c
//./a.out
//gcc - D ARRAY_SIZE = 100 programe.c
//./a.out

//7、条件编译
//在编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令。
//比如说：
//调试性的代码，删除可惜，保留又碍事，所以我们可以选择性的编译。
//#include <stdio.h>
//#define DEBUG//定义DEBUG
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef DEBUG//如果DEBUG定义了，则编译，否则不编译
//		printf("%d\n", arr[i]);//为了观察数组是否赋值成功。 
//#endif
//	}
//	return 0;
//}

//常见的条件编译指令：
//1.
//#if 常量表达式
//...
//#endif
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#if 1-1//如果为真，则编译，否则不编译
//		printf("%d\n", arr[i]);
//#endif
//	}
//	return 0;
//}
//常量表达式由预处理器求值。
//如：
//#define __DEBUG__ 1
//#if __DEBUG__
//..
//#endif

//2.多个分支的条件编译
//#if 常量表达式
//...
//#elif 常量表达式
//...
//#else
//...
//#endif
//#include <stdio.h>
//int main()
//{
//#if 1==2//如果DEBUG定义了，则编译，否则不编译
//	printf("haha\n"); 
//#elif 2==1
//	printf("hehe\n")
//#else 
//	printf("嘿嘿\n");
//#endif
//
//	return 0;
//}

//3.判断是否被定义
//#if defined(symbol)//定义了参与编译
//#ifdef symbol
//以上两种相同
//#if !defined(symbol)//没有定义参与编译
//#ifndef symbol
//以上两种相同
//#include <stdio.h>
//#define DEBUG//定义DEBUG
//int main()
//{
//#ifdef DEBUG//如果DEBUG定义了，则编译，否则不编译
//	printf("hehe\n"); 
//#endif
//#if defined(DEBUG)
//	printf("haha\n");
//#endif
//#ifndef DEBUG//如果DEBUG定义了，则编译，否则不编译
//	printf("hehe\n");
//#endif	
//#if !defined(DEBUG)
//	printf("haha\n");
//#endif
//	return 0;
//}

//4.嵌套指令
//#if defined(OS_UNIX)
//	#ifdef OPTION1
//		unix_version_option1();
//	#endif
//	#ifdef OPTION2
//		unix_version_option2();
//	#endif
//#elif defined(OS_MSDOS)
//	#ifdef OPTION2
//		msdos_version_option2();
//	#endif
//#endif

//8、预处理指令 #include
//我们已经知道， #include 指令可以使另外一个文件被编译。就像它实际出现于 #include 指令的地方一样。
//这种替换的方式很简单：
//预处理器先删除这条指令，并用包含文件的内容替换。
//这样一个源文件被包含10次，那就实际被编译10次。

//头文件被包含的方式：
//本地文件包含，即自己创建的.h文件
//#include "filename"
//查找策略：先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。
//如果找不到就提示编译错误。
//Linux环境的标准头文件的路径： / usr / include
//VS环境的标准头文件的路径：C : \Program Files(x86)\Microsoft Visual Studio 12.0\VC\include。注意按照自己的安装路径去找。

//库文件包含
//#include <filename.h>
//查找策略：查找头文件直接去标准路径下去查找，如果找不到就提示编译错误。
//这样是不是可以说，对于库文件也可以使用 “” 的形式包含？答案是肯定的，可以。
//但是这样做查找的效率就低些，当然这样也不容易区分是库文件还是本地文件了。
//故库文件的头文件也可以用""

//嵌套文件包含：当库头文件被包含多次时，预编译会拷贝多份，导致代码冗余
//如何解决这个问题？答案：条件编译。
//每个头文件的开头写：
//#ifndef __TEST_H__  //如果没有定义过__TEST_H__为真，执行下面语句
//#define __TEST_H__  //定义__TEST_H__
//头文件的内容		  //编译内容，否则不编译
//#endif

//或者：#pragma once - 现代的写法，老编译器可能编译无法通过
//就可以避免头文件的重复引入。
//注：推荐《高质量C / C++编程指南》中附录的考试试卷（很重要）。
//笔试题：
//1. 头文件中的 ifndef / define / endif是干什么用的 ?//防止头文件被重复多次包含
//2. #include <filename.h> 和 #include "filename.h"有什么区别 ?引用场景、查找策略不同

//8. 其他预处理指令
//#error
//#pragma
//#line
//...
//不做介绍，自己去了解。
//#pragma pack()在结构体部分介绍。
//参考《C语言深度解剖》学习

//百度面试题：
//#include <stdio.h>
//#include <stddef.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//int main()
//{
//	//offsetof-宏 - 计算结构体成员的偏移量
//	printf("%d\n", offsetof(struct S, c1));//宏参数为结构体的名称、成员变量名
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, c2));
//	return 0;
//}

//模拟实现offsetof
//思路：假设0地址就是结构体变量的地址，则成员变量的地址即为各自的偏移量
//#include <stdio.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
////将0强制类型转化为结构体指针的地址
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c2));
//	return 0;
//}