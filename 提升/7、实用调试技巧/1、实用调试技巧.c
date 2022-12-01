#define _CRT_SECURE_NO_WARNINGS 1
//调试相关的知识 
//1、调试版本：
//前提：代码加system("pause")和对应的头文件#include <stdlib.h>
//创建一个源文件，当为Debug时，
//编译后，存放代码的文件夹中会出现Debug文件夹，里面包含了源文件编译好的Debug版本的可执行文件.exe
//点击该文件可以运行，如果没有包含system("pause")和#include <stdlib.h>会一闪而过

//2、发布版本：
//前提：代码加system("pause")和对应的头文件#include <stdlib.h>
//创建一个源文件，当为Release时，
//编译后，存放代码的文件夹中会出现Release文件夹，里面包含了源文件编译好的Release版本的可执行文件.exe
//点击该文件可以运行，如果没有包含system("pause")和#include <stdlib.h>会一闪而过

//观察两种版本的可执行文件，发现二者的可执行文件大小不一样，Debug编译的可执行文件较大
//此调试版本的源程序（源代码）可调试，因为文件中包含了调试的相关信息，所以文件大小较大

//如何调试？
//1、在代码编辑(VS2019)上，将解决方案配置改为Debug，按Fn+F10逐过程调试，Fn+F11进入函数中逐语句调试
//2、将解决方案配置改为Release，发现不能调试

//Debug 通常称为调试版本，它包含调试信息，并且不作任何优化，便于程序员调试程序。
//Release 称为发布版本，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用。
//调试的是Debug版本，测试的是Release版本

//Debug和Release配置在功能上的区别
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("hehe\n");
		arr[i] = 0;
	}
	system("pause");
	return 0;
}
*/
//1、Debug编译时，会出现死循环
//2、Release编译时，由于会对程序进行优化，故正常结束

//调试的基本步骤
//1、发现程序错误的存在
//2、以隔离、消除等方式对错误进行定位
//3、确定错误产生的原因
//4、提出纠正错误的解决办法
//5、对程序错误予以改正，重新测试

//调试：
//1、将解决方案配置该为Debug
//2、最常使用的几个快捷键：
	//Fn + F5，这个按键要搭配断点使用
	//启动调试，经常用来直接跳到（逻辑意义上）下一个断点处。
	//第一次按F5直接跳到第一个断点处，之后再按F5跳到下一个断点处
	//Fn + F9
	//在光标所在行，创建断点和取消断点
	//断点的重要作用，可以在程序的任意位置设置断点。
	//这样就可以使得程序跳过断点前的逻辑，在想要的位置随意停止执行，继而一步步执行下去。
	//测试代码：
	/*#include <stdio.h>
	int main()
	{
		int i = 0;
		for (i = 0; i < 100; i++)
		{
			printf("%d ", i);
		}
		for (i = 0; i < 100; i++)
		{
			printf("%d ", 10 - i);
		}
		return 0;
	}*/
	//假设能肯定错误不在第一个for循环，为了快速找到问题
	//在printf("%d ", 10 - i);此行按F9设置一个断点（红点）
	//再按F5，发现执行直接来到断点标记的位置，且程序打印了前面逻辑的执行结果
	//注意：F5是跳到执行逻辑的下一个断点，若再按F5，此时会执行第二个for循环的语句来到断点处
	//此时再按F10逐语句执行，一步一步发现问题
	
	//F10
	//启动调试，并逐过程，通常用来处理一个过程，一个过程可以是一次函数调用，或者是一条语句。
	//F11
	//启动调试，并逐语句，就是每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑进入函数内部（这是最
	//长用的）。
	//测试代码：
	/*#include <stdio.h>
	int Add(int x,int y)
	{
		int z = x + y;
		return z;
	}
	int main()
	{
		printf("hehe\n");
		int a = 10;
		int b = 20;
		int c = Add(a, b);
		return 0;
	}*/
	//按F11一般不能进入库函数进行逐语句执行
	//shifit + F11，跳出函数
	
	//CTRL + F5
	//开始执行不调试（直接编译并运行，注意Ctrl+F7编译），如果你想让程序直接运行起来而不调试就可以直接使用。
	//Shift + F5停止调试
//3、调试的时候查看程序当前信息（注意：需要先打开调试）
//查看临时变量的值：在调试开始之后，用于观察变量的值。
//    调试-窗口-自动窗口：程序的一些变量会自动展现
//    调试-窗口-局部变量：自动展示局部范围内的相关信息
//缺点：不能任意添加想展示的内容，随着程序的进行，部分展示的内容会消失
//调试-窗口-监视：满足了以上缺点

//查看内存信息：在调试开始之后，用于观察内存信息。(变量地址或者指针指向的地址，解引用数据在内存中的布局)
//    调试-窗口-内存：数据的存放是倒序 - 十六进制形式显示，每两个十六进制代表一个字节，即8位二进制数
//通过F10/F11搭配使用，观察不同阶段的变化
/*
#include <stdio.h>
int main()
{
	{
		int tmp = 0;
		printf("tmp = %d\n", tmp);
	}
	int arr[10] = { 0 };
	int i = 1;
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	return 0;
}
*/
//注意：监视和内存的区别：监视查看的是变量中存的值的变化。内存查看的是地址指向的数据对应的空间布局变化。

//查看调用堆栈：通过调用堆栈，可以清晰的反应函数的调用关系以及当前调用所处的位置。
//    调试-窗口-调试堆栈
/*
#include <stdio.h>
void test1()
{
	printf("hehe\n");
}
void test()
{
	test1();
}
int main()
{
	test();
	return 0;
}
*/
//通过F10/F11搭配使用，观察不同阶段的变化
//发现每进入一个函数，栈内栈顶加一个信息，每退出一个函数，栈内栈顶减少一个信息
//由此可知，递归有压栈(进栈),出栈的开销

//调试-窗口-反汇编：查看汇编信息
//调试-窗口-寄存器：查看寄存器信息

//实例一
//实现代码：求 1！+2！+3！ ...+ n! ；不考虑溢出。
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);
	for (i = 1; i <= n; i++)//外层循环是阶乘的和
	{
		int j = 0;
		//ret = 1;
		for (j = 1; j <= i; j++)//这里是求阶乘，故这里设置条件断点i == 3
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}
*/
//1、捋清楚代码的执行过程
//2、调试-窗口-监视搭配F10/F11：观察i、sum、n、ret和打印窗口
//3、通过调试观察并分析每一个变量的值的变化是否正确，i == 3时，ret = 12，本应该为6，故错误了
//4、找到了是i==3时，计算出错，为了快捷，此时错过了错误，结束调试。
//5、在for (j = 1; j <= i; j++)设置断点，右键，点击条件，输入：i==3，按F5，直接执行到断点处。屏幕上，输入3回车，监视信息
//6、此时需要求3的阶乘1*2*3，发现ret为2，上次结果留下的2，故ret错误，置为1
//7、修改代码ret = 1放在int j = 0处。ctrl+F5运行

//实例二--出自《C陷阱和缺陷》
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}
*/
//1、捋清楚代码的执行过程
//2、调试-窗口-监视搭配F10/F11：观察i、arr、和打印窗口
//3、通过调试观察并分析每一个变量的值的变化是否正确，此时i的值随着i++，不断加1。arr数组的个元素被改为了0
//再往后调试，此时就会非法访问，当i=10,11,12，观察arr[10]、arr[11]、arr[12]被改为了0，当arr[12]==0时，i也==0了，故错误了
//为什么arr[12]赋值为0的同时，i也改变为0了？猜测：这两个变量的地址相同，通过观察&arr[12]和&i，发现它们的地址相同。
//为什么它们是同一块空间？
//分析：
//局部变量存放在栈区中
//1、栈区的默认使用：先使用高地址处的空间，再使用低地址处的空间
//2、数组随着下标的增长，每个元素的地址是由低到高变化的
//画出i,arr在内存中的布局图：
//假设：栈的高地址的某地址0xFF120A0C为变量i开辟的空间，arr数组每个元素开辟的空间从0xFF120A00-0xFF120A09
//当i++到10时，数组越界访问，0xFF120A0A、0xFF120A0B、0xFF120A0C地址的空间，并将其内容改为0
//恰巧i分配的地址与i++访问越界的地址相同，从而造成了死循环

//由于程序忙着死循环，故不会报错
//对于不同的机器内存布局不同，死循环的条件就不同。vc++6.0环境下，i<=10,gcc环境下，i<=11就会死循环
//vc++6.0环境下，i<=10的内存布局图是，i和arr存放的位置相邻
//将int i = 0;放在数组定义的后面，就不会出现死循环，但会报错
//因为内存的布局是，arr先在上，i在下，就不会导致arr越界访问是访问i的地址
//注意：int i = 0;放在for()中定义，C语言语法不支持这种书写，很多编译器是无法编译通过，此为C++的定义

//如果改为Release配置，不会死循环，编译器对该程序优化了
//如何优化的？
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	printf("%p\n", &i);
	printf("%p\n", arr);
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}
*/
//1、Debug配置下，发现i的地址大于arr的地址
//2、Release配置下，发现i的地址小于arr的地址

//注意：Debug版本运行正常，而未来Release版本可能会对原本Debug版本的代码进行优化，导致Release版本出错，
//程序员应该对两个版本进行测试，以确保Debug和Release版本下都没有问题
//从事测试的人员，应该记录测试出错结果的证据，防止这个错误下次没有出现

//如何写出好（易于调试）的代码。
//优秀的代码：
//1. 代码运行正常
//2. bug很少
//3. 效率高
//4. 可读性高
//5. 可维护性高
//6. 注释清晰
//7. 文档齐全

//常见的coding技巧：
//1. 使用assert
//2. 尽量使用const
//3. 养成良好的编码风格
//4. 添加必要的注释
//5. 避免编码的陷阱。

/*
#include <stdio.h>
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit";
	strcpy(arr1, arr2);//将arr2的内容拷贝到arr1中，包括'\0'，可以通过调试-窗口-监视观察arr1，arr2的内容
	printf("%s\n", arr1);
	return 0;
}
*/
//模拟实现strcpy
/*
#include <stdio.h>
void my_strcpy(char* destination, char* scoure)
{
	while (*scoure != '\0')
	{
		*destination = *scoure;
		scoure++;
		destination++;
	}
	*destination = *scoure;//将'\0'拷贝至目的地字符串数组中
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);//将arr2的内容拷贝到arr1中，包括'\0'
	printf("%s\n", arr1);
	return 0;
}
*/

//优化：
/*
void my_strcpy(char* destination, char* scoure)
{
	while (*scoure != '\0')
	{
		*destination++ = *scoure++;//即*(destination++) = *(scoure++);
	}
	*destination = *scoure;//将'\0'拷贝至目的地字符串数组中
}
*/

//再优化：
/*
void my_strcpy(char* destination, char* scoure)
{
	while (*destination++ = *scoure++)//*scoure == '\0',*destination == '\0',ASCII值为0，循环停止
	{
		;
	}
}
*/

//继续优化：使用指针前一定要判断指针是否有效
/*
#include <stdio.h>
void my_strcpy(char* destination, char* scoure)
{
	//防止传入空指针，导致程序崩溃，引起其他程序出错，所以加上if判断
	//这样虽然提高了代码的健壮性，但是让错误规避掉了
	if (*destination != NULL && *scoure != NULL)
	{
		while (*destination++ = *scoure++)//*destination = '\0',ASCII值为0，循环停止
		{
			;
		}
	}
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);//将arr2的内容拷贝到arr1中，包括'\0'
	printf("%s\n", arr1);
	my_strcpy(arr1, NULL);//NULL相当于0
	printf("%s\n", arr1);

	return 0;
}
*/

//继续优化：判断指针的有效性，使用assert断言代替if判断
/*
#include <stdio.h>
#include <assert.h>
void my_strcpy(char* destination, char* scoure)
{
	//抛出异常
	assert(destination != NULL);//为真则不发生，为假则报错
	assert(scoure != NULL);//为真则不发生，为假则报错
	//因为需要指针不能为空，作用断言时，条件为"不能等于NULL"
	while (*destination++ = *scoure++)//*destination = '\0',ASCII值为0，循环停止
	{
		;
	}
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);//将arr2的内容拷贝到arr1中，包括'\0'
	printf("%s\n", arr1);
	my_strcpy(arr1, NULL);//NULL相当于0
	printf("%s\n", arr1);

	return 0;
}
*/

//再优化：
/*
void my_strcpy(char* destination, const char* scoure)
{
	//抛出异常
	assert(destination && scoure);//断言
	while (*destination++ = *scoure++)//防止误写成while (*scoure++ = *destination++)
		;
}
*/

/*
#include <stdio.h>
int main()
{
	int num = 10;
	int* p = &num;
	*p = 20;
	printf("%d\n", num);

	return 0;
}
*/
//const的作用
//const修饰的变量，不允许变量值修改
/*
#include <stdio.h>
int main()
{
	const int num = 10;//不想num的值被修改
	int* p = &num;
	*p = 20;//非法访问
	printf("%d\n", num);

	return 0;
}
*/
//此时仍能修改，说明*p = 20非法访问了

//如何既让p获取到num的地址，又不让*p修改num的值？
/*
#include <stdio.h>
int main()
{
	const int num = 10;
	const int* p = &num;
	*p = 20;//此时编译报错
	int n = 100;
	p = &n;//编译通过
	printf("%d\n", num);

	return 0;
}
*/
//总结1：
//1、const int* p = &num;const放在指针变量的*左边时，修饰的是*p，即不能通过*p改变num的值
//2、p = &n，p可以改变

/*
#include <stdio.h>
int main()
{
	int num = 10;
	int* const p = &num;
	*p = 20;////编译可以通过
	int n = 100;
	p = &n;//此时编译报错
	printf("%d\n", num);

	return 0;
}
*/
//总结2：
//1、int* const p = &num;const放在指针变量的*右边时，修饰的是指针变量p，即不能修改p中地址
//2、*p = 20;*p可以改变
//3、const int* const p = &num;即修饰*p，又修饰p
//最左边表示指针变量是const的，p左边表示指针变量解引用的值是const
//结论：
//const修饰指针变量的时候：
//1. const如果放在 * 的左边，修饰的是指针指向的内容，保证指针指向的内容不能通过指针来改变。
//但是指针变量本身的内容可变。
//2. const如果放在 * 的右边，修饰的是指针变量本身，保证了指针变量的内容不能修改，
//但是指针指向的内容，可以通过指针改变。

//再继续优化：
/*
#include <stdio.h>
#include <assert.h>
char* my_strcpy(char* destination, const char* scoure)
{//const在*的左边，修饰*scoure，不允许改变。使用const的目的：防止误写成*scoure++ = *destination++
	
	char* ret = destination;
	//抛出异常
	assert(destination && scoure);//断言
	while (*destination++ = *scoure++)
		;
	return ret;//不是直接返回destination的地址，因为destination的地址已经改变了。
	//返回的是destination最初的起始地址
}
int main()
{
	char arr1[] = "###########";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);//将arr2的内容拷贝到arr1中，包括'\0'
	printf("%s\n", arr1);
	
	my_strcpy(arr1, NULL);//NULL相当于0
	printf("%s\n", arr1);

	printf("%s\n", my_strcpy(arr1, arr2));//打印arr1的起始地址
	//链式访问：函数的返回值作为另一个函数的参数
	return 0;
}
*/
//注意：
//1. 分析参数的设计（命名，类型），返回值类型的设计
//2. 这里讲解野指针，空指针的危害。
//3. assert的使用，这里介绍assert的作用
//4. 参数部分 const 的使用，这里讲解const修饰指针的作用
//常见的coding技巧：
//1. 使用assert
//2. 尽量使用const
//3. 养成良好的编码风格
//4. 添加必要的注释
//5. 避免编码的陷阱。

//《高质量C/C++编程》：模拟实现strlen
//考虑是否假设const和assert断言，以提高健壮性
/*
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)//防止*str被修改
{
	int count = 0;
	assert(str != NULL);//保证指针的有效性
	while (*str !='\0')//判断字符串是否结束
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	const char* p = "abcdef";
	//测试
	int len = my_strlen(p);
	printf("len = %d\n", len);
	return 0;
}
*/

//编程常见的错误
//1 编译型错误：即语法错误
//直接看错误提示信息（双击错误，就会来到错误的一行），解决问题。或者凭借经验就可以搞定。相对来说简单。
//2 链接型错误
//看错误提示信息，主要在代码中找到错误信息中的标识符，然后定位问题所在。一般是标识符名不存在或者拼写错误，是否引用头文件等等。
//如：常表现为：无法解析的外部符号
//测试代码：
/*
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);//无法解析的外部符号 _Add，函数 _main 中引用了该符号
	printf("sum = %d\n", sum);//无法解析的外部符号 _printf，函数 _main 中引用了该符号
	return 0;
}
*/
//3 运行时错误
//借助调试，逐步定位问题。最难搞。