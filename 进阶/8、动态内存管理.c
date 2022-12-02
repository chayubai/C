#define _CRT_SECURE_NO_WARNINGS 1
//动态内存管理

//1、为什么存在动态内存分配
//栈区：局部变量，函数的形式参数，函数调用也会在栈区开辟内存
//堆区：动态内存分配（malloc）
//静态区：全局变量，静态变量

//当前我们知道的内存的使用方式：
//1、创建一个变量 
//int a = 10;//局部变量 - 在栈空间上开辟四个字节
//int g_a = 10;//全局变量 - 静态区

//2、创建一个数组
//int arr[10];//局部变量 - 在栈空间上开辟40个字节的连续空间
//int g_arr[10];//全局变量 - 静态区
//注意：全局数组不初始化内容默认为0，局部数组不初始化内容是随机值,静态变量不初始化也是0

//上述的开辟空间的方式有两个特点：
//1. 空间开辟大小是固定的。
//2. 数组在声明的时候，必须指定数组的长度，它所需要的内存在编译时分配。
//但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，
//那数组在编译时开辟空间的方式就不能满足了。这时候就只能试试动态内存开辟了。

//对于创建一个数组，应该给多大的空间是不确定的，可能导致空间浪费，或者空间不足
//解决办法：应该想要多大的空间，给多大的内存空间，由此可以创建变长数组
//但是，Linux-gcc编译器才支持C99标准，编译的执行命令：gcc 文件名.c -std=c99
/*
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];//报错，不支持C99变长数组
    for(int i = 0;i < n;i++)
    {
        arr[i] = i;
    }
    for(int i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
}
*/
//因此，可以使用动态内存分配的方式

//2、动态内存函数的介绍(结合MSDN)
//使用malloc、calloc、realloc、free函数在堆区中申请的空间，这些函数都声明在 stdlib.h 头文件中。

//malloc函数：
//函数原型如下：void* malloc(size_t size);向堆区申请size个字节的空间(单位是字节)，并将该空间的起始地址(void*类型)返回
//注意：
//1、这个函数向内存申请一块连续可用的空间，并返回指向这块空间的指针。
//2、如果开辟成功，则返回一个指向开辟好空间的指针。
//3、如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查。否则后面的操作全都是无效的
//4、返回值的类型是 void* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定。
//5、如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器。

//free函数：
//C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的，
//函数原型如下：void free (void* ptr);释放ptr指向的空间
//注意：
//1、free函数用来释放动态开辟的内存。
//2、如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的。即只有动态开辟的空间变量才需要free，不能取释放不是动态开辟的空间变量
//3、如果参数 ptr 是NULL指针，则函数什么事都不做。
//4、形参类型是 void* ，说明可以接收任意类型的指针，不需要强转。
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	//向内存申请连续的10个整型大小(40个字节)的空间，即可以存放10个整型数据，相当于10个元素的整型数组
	//因为希望存放10个整型数据，所以通过int*指针接收，来维护这块空间，也可以这样写int* p = (int*)malloc(40)
	int* p = (int*)malloc(10 * sizeof(int));
	//malloc申请空间成功，返回申请的空间的起始地址，地址的类型为void*，因此，使用int*接收需要强转
	//否则，malloc申请空间失败，返回NULL
	//注意：空指针是无法解引用操作的
	if (p == NULL)//开辟失败。检查是否开辟成功
	{
		//打印错误原因的一个方式
		printf("%s\n", strerror(errno));//打印错误码信息
	}
	else
	{
		//使用这个可以连续存放10个int型数据的空间
		int i = 0;
		for (i = 0; i < 10; i++)//对该空间初始化，malloc没有初始化时空间的内容是随机值
		{
			*(p + i) = i;//p + 1，跳过一个int字节大小，调试-窗口-内存-观察p中的地址对应的内存空间值的变化
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//调试-窗口-监视发现p不是空指针，说明空间申请成功。
	//将10 * sizeof(int)换成INT_MAX，运行结果为Not enough space，
	//此时调试-窗口-监视-观察p的值为0x00000000即空指针，则申请失败。
	
	//当动态申请的空间不再使用的时候，就应该还给操作系统
	free(p);//即使没有这行代码，等程序生命周期结束，也会自动回收该空间，但是对于不退出的程序，如果不回收就会占用堆区资源。这样很危险
	//此时调试-窗口-监视-观察p的值不是空指针，指针指向的内容由0变为了随机值。

	//即使将p的空间还回去了，调试发现p的值，p仍指向那个空间，就有能力找到该空间，而访问该空间，就会造成安全隐患，此时需要将其置成NULL
	p = NULL;//空指针是无法解引用操作的，避免了隐患

	//总结：malloc和free函数成对出现，谁使用谁释放
	return 0;
}
*/

//calloc函数：
//C语言还提供了一个函数叫 calloc ， calloc 函数也用来动态内存分配。
//函数原型如下：void* calloc(size_t num, size_t size);开辟num个，每个大小为size字节(单位是字节)的空间
//注意：
//1、函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
//2、与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0
//3、calloc申请空间成功，返回申请的空间的起始地址，地址的类型为void*。否则，返回NULL。
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	//malloc(10*sizeof(int))
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)//检查是否开辟成功
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	free(p);//free函数是用来释放动态开辟的空间的
	p = NULL;//置空指针
	//当使用malloc函数时，调试-窗口-内存-观察p(p中对应的地址)指向的开辟的内存空间值都是随机值
	//当使用calloc函数时，调试-窗口-内存-观察p(p中对应的地址)指向的开辟的内存空间值都是0
	
	//所以，如果我们对申请的内存空间的内容要求初始化，那么可以很方便的使用calloc函数来完成任务。
	//由于calloc有初始化操作，开辟空间时，相对于malloc函数效率略差一些。
	
	//总结：calloc和free函数成对出现，谁使用谁释放
	return 0;
}
*/

//realloc函数：
//有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的使用内存
//我们一定会对内存的大小做灵活的调整。那 realloc 函数就可以做到对动态开辟内存大小的调整。
//函数原型如下：void* realloc(void* ptr, size_t size);调整ptr指向的动态内存块的大小为size字节
//注意：
//1、ptr 是要调整的内存地址。ptr为NULL，功能和malloc相同
//2、size 调整之后整个动态开辟的空间大小
//3、返回值为调整之后的内存起始位置。
//4、这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到 新 的空间。
//5、调整malloc或calloc函数开辟的动态内存空间的大小，也可以自己直接申请。realloc函数的出现让动态内存管理更加灵活。
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	//开辟了5个整型大小的空间
	int* p = (int*)malloc(20);
	if (p == NULL)//检查是否开辟成功
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	//假设执行到这里，malloc开辟的20个字节的空间不满足我们的使用
	//希望能够有40个字节的空间
	//使用realloc来调整动态开辟的内存空间
	int* p2 = (int*)realloc(p, 40);//将原空间用p2来维护，这样使得程序很乱。如果使用p来维护，又会出现一些问题。解决方法如下：情况3
	//realloc函数是在原基础上，重新申请更大的空间，而不是追加空间。
	//也就是说，原来有20个字节，realloc申请40个字节。总大小还是申请了40个字节。而不是60个字节。

	int i = 0;
	for (i = 5; i < 10; i++)
	{
		*(p2 + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p2 + i));
	}
	return 0;
}
*/

//realloc使用的注意事项：
//realloc在调整内存空间的时候存在三种情况：
//情况1：如果malloc开辟的原有空间之后有足够大的空间可以追加，则直接追加，并返回之前malloc的旧地址，即地址没有发生变化
//使用完空间需要free释放，指针需要置NULL
//情况2：如果malloc开辟的原有空间之后没有足够大的空间可以追加，则realloc会重新开辟一个全新的足够大的空间，同时将原空间的数据拷贝到新空间中
//且原空间会释放掉，并返回新开辟的空间的起始地址。即地址发生变化
//原空间自动释放，但原空间维护的变量还没有销毁，可以用来接收新空间的地址，当新空间使用完需要free释放，指针需要置NULL
//情况3：realloc调整的空间太大，可能会调整失败，会返回NULL
//此时如果用之前维护原空间的指针接收，当指针接收了NULL后，导致找不到原空间，而内存泄漏，故使用realloc前使用临时指针接收函数的返回值

//情况1：
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	p = (int*)realloc(p, 40);
	//原空间仍用p来维护，此时再申请20字节的空间。
	//调试-监视-观察p的值：发现p的值没有发生变化。
	//调试-内存-观察p的值：发现p指向的空间后面又追加了20个字节。
	//说明原空间后面足够大
	//此时p接收的还是原来的地址
	int i = 0;
	for (i = 5; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	//使用完，释放，置空指针
	free(p);
	p = NULL;
	return 0;
}
*/

//情况2：
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	p = (int*)realloc(p, 4000);
	//原空间仍用p来维护，此时再申请3920字节的空间
	//调试-监视-观察p的值：发现p的值发生变化
	//说明原空间后面不能够直接申请新的空间，如果强行申请则会导致后面别人在使用的空间被非法访问
	//虽然原空间被自动释放掉，但维护的变量没有销毁，因此需要将新空间用一个原变量来维护，不需要创建新变量
	int i = 0;
	for (i = 5; i < 10; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	//使用完，释放，置空指针
	free(p);
	p = NULL;
	return 0;
}
*/

//情况3：
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
	}
	int* ptr = (int*)realloc(p, INT_MAX);//使用临时指针接收realloc返回的值
	if (ptr != NULL)//判断是否能调整成功
	{
		//追加成功，并使用
		p = ptr;
		int i = 0;
		for (i = 5; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//使用完，释放，置空指针
	free(p);
	//1、没有调整成功，当p使用完后也能释放。 
	//2、调整成功，旧空间自动释放了，当p使用完后新空间也能释放。
	//3、ptr不用释放，如果没有调整成功，ptr为空指针。如果调整成功，p和ptr指向同一块空间，释放p就释放了ptr
	p = NULL;
	return 0;
}
*/

//realloc可以直接申请空间
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = realloc(NULL, 40);//相当于malloc

	return 0;
}
*/
//realloc函数的返回值为调整之后的内存起始位置。

//3、常见的动态内存错误
//情况1：对NULL指针的解引用操作
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//申请空间
	int* p = (int*)malloc(40);
	//注意使用malloc之前，要判断是否能申请成功
	//如果申请失败，则p被赋值NULL，后续的使用空间的解引用代码都没有用

	//正确操作：malloc后加上一个判断语句 - 判断malloc申请是否成功
	
	//使用申请的空间
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	return 0;
}
*/

//情况2：对动态开辟空间的越界访问
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//申请空间
	int* p = (int*)malloc(5 * sizeof(int));//5个int, 下标为0~4
	//正确使用malloc后加上一个判断语句 - 判断malloc申请是否成功
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		//使用申请的空间
		int i = 0;
		for (i = 0; i < 10; i++)//err这里的条件越界了，因为只开辟了5个整型元素的空间
		{
			*(p + i) = i;
		}
	}
	free(p);
	p = NULL;
	return 0;
}
*/

//情况3：对非动态开辟内存使用free释放
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 10;//栈区的空间
	int* p = &a;//p指向的是栈区的空间
	*p = 20;

	free(p);//err
	p = NULL;
	return 0;
}
*/

//情况4：使用free释放一块动态开辟内存的一部分
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		return 0;
	}
	//使用申请的空间
	int i = 0;
	for (i = 0; i < 10; i++)//改成i < 5，同样free(p)报错
	{
		*p++ = i;//正确操作：改成*(p+i) = i，就不会改变p，free(p)不报错
	}
	//来到这里，p不再指向动态内存的起始位置,p指向开辟空间的下一个地址
	//不允许释放动态开辟空间的一部分，或者别人的空间了，只能释放malloc开辟的空间的起始地址
	free(p);//err
	p = NULL;
	return 0;
}
*/

//情况5：对同一块动态内存多次释放
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//申请空间
	int* p = (int*)malloc(5 * sizeof(int));
	//正确使用malloc后加上一个判断语句 - 判断malloc申请是否成功
	if (p == NULL)
	{
		return 0;
	}

	//free(p);
	//...
	//free(p);//重复释放，以为自己没有释放，再次释放导致错误

	//正确操作
	//1、谁申请谁释放
	//2、避免自己导致犯错，可以free后，p置空
	free(p);
	p = NULL;
	//...
	free(p);//以为自己没有释放，此时free不会干什么。避免了犯错
	
	return 0;
}
*/

//情况6：动态开辟内存忘记释放（内存泄漏）
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	while (1)
	{
		malloc(1);
		//无限吃内存，观察任务管理器-内存变化
		//忘记释放不再使用的动态开辟的空间会造成内存泄漏。
        //切记：动态开辟的空间一定要释放，并且正确释放 。
	}
	return 0;
}
*/

//4、几个经典的笔试题
//题目1：请问运行Test 函数会有什么样的结果？--来自《高质量C++/C编程指南》
/*
#include <stdio.h>
#include <stdlib.h>
void GetMemory(char* p)//开辟了一个空间p(临时拷贝)，里面为NULL。
{
    p = (char*)malloc(100);//申请了一块动态空间，将空间地址给了p，此时p里面为该空间的地址
}//p为栈区上的局部变量，出了函数p变量自动销毁，此时空间还在，但该空间没人管理，导致内存泄漏
void Test(void)
{
    char* str = NULL;//开辟了一个空间str，里面为NULL
    GetMemory(str);//将str的内容NULL作为参数传入GetMemory函数，即传值调用
    strcpy(str, "hello world");//此时str的值没有改变，仍为NULL，将字符串拷贝到无效的空间，就会程序崩溃
    printf(str);

    //char* str = "abcdef";
	//printf(str);//这种写法没有没有问题
	//printf("abcdef");
	//printf("%s\n", str);
}
int main()
{
    Test();
    //1、运行代码程序会出现崩溃的现象
    //2、程序存在内存泄漏的问题
    //str以值传递的形式给p
    //p是GetMemory函数的形参，只能函数内部有效，等GetMemory函数返回之后，动态开辟的内存未释放
    //并且无法找到，所以会造成内存泄漏
    return 0;
}
*/

//改正：1
/*
#include <stdio.h>
#include <stdlib.h>
void GetMemory(char** p)
{
    *p = (char*)malloc(100);//通过*p找到str，并将动态开辟的空间地址存入str中
}//p自动销毁之前，把地址传给了str
void Test(void)
{
    char* str = NULL;
    GetMemory(&str);//函数内部改变函数外部某些变量的值，传址调用
	//判断str是否为空，即malloc如果开辟失败，str为NULL
    strcpy(str, "hello world");//此时strcpy中dest++，str的地址没有发生变化
    printf(str);

    free(str);
    str = NULL;
}
int main()
{
    Test();
    return 0;
}
*/
//改正：2
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* GetMemory(char* p)//无参函数比较合理
{
    //加一个判断动态空间是否申请成功
    p = (char*)malloc(100);
    return p;
}//p自动销毁之前，把地址返回给了str
void Test(void)
{
    char* str = NULL;
    str = GetMemory(str);//不传参比较合理
	//判断str是否为空，即malloc如果开辟失败，str为NULL
    strcpy(str, "hello world");
    printf(str);
    free(str);
    str = NULL;
}
int main()
{
    Test();
    return 0;
}
*/
/*
#include <stdio.h>
void changstr(char* p)
{
	*p = 'x';
}
void Test(void)
{
	//char* pc = "abcd";//不允许修改常量字符串"abcd"，通过二级指针也无法修改
	char c1 = 'a';
	char c2 = 'b';

	char* pc = &c1;
	changstr(pc);//传值调用，即传入pc的内容&c。p和pc都指向&c
	printf("%c",c1);//x

	changstr(&c2);//传址调用，即传入&c。p指向&c
	printf("%c",c2);//x
}
int main()
{
	Test();
	return 0;
}
*/
//注意：传址和传值的区别：传值是传的是变量本身(的内容)。传址是传的是变量本身的地址。

//题目2：请问运行Test 函数会有什么样的结果？
/*
#include <stdio.h>
char* GetMemory(void)
{
    char p[] = "hello world";//局部变量，栈区上开辟了一块数组空间，里面放了hello world（//加上static修饰则正确）
    return p;//返回栈空间的地址问题，栈空间出了作用域自动回收。
}//p数组出函数，变量内容被销毁了，但空间还在
void Test(void)
{
    char* str = NULL;//开辟了一块空间
    str = GetMemory();//str接收到了p的地址，此时地址所指向的空间是未知的内容，即野指针的非法访问
    printf(str);//打印随机值
}
int main()
{
    Test();
    return 0;
}
*/
//类似的问题
/*
#include <stdio.h>
int* test()
{
    int a = 10;//加上static修饰则正确，变量a在静态区，出了函数a变量的内容不销毁
    return &a;//返回栈空间的地址
}
int* f1(void)
{
	int* ptr;//ptr保存了一个随机地址，ptr未初始化，是一个野指针
	*ptr = 10;//非法访问 - 将随机地址的空间改为10
	return ptr;
}
int main()
{
    int* p = test();
    *p = 20;//p是野指针，非法访问内存
    return 0;
}
*/
//没有问题的代码
/*
#include <stdio.h>
#include <stdlib.h>
int* test()
{
    int* ptr = malloc(100);//堆区上开辟空间
    return ptr;//返回堆区空间的地址
}//ptr自动销毁，但是所指向的空间没有销毁
int main()
{
    int* p = test();
    free(p);
    p = NULL;
    return 0;
}
*/

//题目3：请问运行Test 函数会有什么样的结果？
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetMemory(char** p, int num)
{
    *p = (char*)malloc(num);
}
void Test(void)
{
    char* str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");//此时strcpy中dest++，str的地址没有发生变化
    printf(str);
    //忘记释放动态开辟的内存，导致内存泄漏
}
int main()
{
    Test();
	//1、判断str是否为空，即malloc如果开辟失败，str为NULL
	//2、使用完堆区空间后，未释放空间导致内存泄漏，同时指针未置空
    return 0;
}
*/

//题目4：请问运行Test 函数会有什么样的结果？
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Test(void)
{
    char* str = (char*)malloc(100);
    strcpy(str, "hello");//此时strcpy中dest++，str的地址没有发生变化
    free(str);//free释放str指向的空间后，并不会把str置为NULL
    //将动态开辟的空间释放了(将空间的使用权还给了操作系统，但空间还在)，此时str仍指向该空间，即仍保留该空间的地址
    //由于没有将str置空，str!=NULL为真
    if (str != NULL)
    {
        strcpy(str, "world");//str野指针，非法访问
        printf(str);
    }
}
int main()
{
    Test();
	//1、判断str是否为空，即malloc如果开辟失败，str为NULL
	//2、使用完堆区空间后，指针未置空
	//3、str野指针，非法访问
    return 0;
}
*/

//C/C++程序的内存开辟
//C / C++程序内存分配的几个区域：
//1、内核区   2、用户区（用户区包括：栈区、内存映射段、堆区、静态区(数据段)、代码段）
//1. 栈区（stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。
//栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。 
//栈区主要存放运行函数而分配的局部变量、函数参数、函数调用、返回数据、返回地址等。内存的分配方式：向下增长，即优先分配高地址，再分配低地址。
//2. 堆区（heap）：动态函数、一般由程序员分配释放， 若程序员不释放，程序结束时可能由内核回收 。分配方式类似于链表。
//内存的分配方式：向上增长，即优先分配低地址，再分配高地址。
//3. 数据段（静态区）（static）存放全局变量、静态数据。程序结束后由系统释放。
//4. 代码段：存放常量、函数体（类成员函数和全局函数）的二进制代码。
//因此，我们就可以更好的理解在《C语言初识》中讲的static关键字修饰局部变量的例子了。
//实际上普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。
//但是被static修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，直到程序结束才销毁，所以生命周期变长。

//5、柔性数组
//C99 中，结构（结构体）中的最后一个元素允许是未知大小的数组，这就叫做『柔性数组』成员。
/*
#include <stdio.h>
struct S
{
    int n;
    int arr[];//最后一个成员， 未知大小的数组 - 柔性数组成员，或者写成int arr[0];
    //这个柔性数组大小是可以调整的
};
int main()
{
    struct S s;
    printf("%d\n", sizeof(s));//4
	//注意：计算包含柔性数组的结构体大小时，不包含柔性数组空间大小
    return 0;
}
*/

//柔性数组的特点：
//1、结构中的柔性数组成员前面必须至少一个其他成员。
//2、sizeof 返回的这种结构大小不包括柔性数组的内存。
//3、包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

//柔性数组的使用
/*
#include <stdio.h>
#include <stdlib.h>
struct S
{
    int n;//4
    int arr[];//20
};
int main()
{
    //动态内存开辟一个结构体大小的空间：结构体大小(int大小) + 5个int元素的数组大小
    struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//24个字节的空间是连续的
    //使用空间
    ps->n = 100;//将n空间赋值为100。注意：判断是否开辟成功
    //将数组元素的空间赋值0、1、2、3、4
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ps->arr[i] = i;
    }
	//调试-内存-观察ps指向的内存布局。前4个字节分配给n，后20个字节分配给arr数组。

    //当空间不够使用时，调整空间(调整数组空间)大小
    struct S* ptr = realloc(ps, 44);//使用临时变量ptr接收
    //判断是否开辟成功
    if (ptr != NULL)
    {
        ps = ptr;
		//使用空间
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", ps->arr[i]);
		}
    }   
    //释放，置空
    free(ps);
    ps = NULL;
    return 0;
}
*/

//其他方式实现柔性数组的功能
/*
#include <stdio.h>
#include <stdlib.h>
struct S
{
    int n;
    int* arr;
};
int main()
{
    //动态内存开辟一个结构体大小的空间：结构体大小(int大小) + 一个int*的指针大小
    struct S* ps = (struct S*)malloc(sizeof(struct S));//也可以直接在栈上创建一个struct S s变量，再对结构体成员s->arr申请动态空间
    //开辟5个元素大小的空间，用arr维护
    ps->arr = (int*)malloc(5 * sizeof(int));
    //对malloc申请是否成功的判断
    
    //使用空间
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ps->arr[i] = i;//arr维护的是连续空间可以当作数组
    }
    //当空间不够使用时，调整空间(调整数组空间)大小
    int* ptr = (int*)realloc(ps->arr, 10*sizeof(int));//使用临时变量ptr接收
    //判断是否开辟成功
    if (ptr != NULL)
    {
        ps->arr = ptr;
		//使用空间
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", ps->arr[i]);
		}
    }
    //释放，置空
    free(ps->arr);//必须先释放ps->arr，否则如果释放ps，就会导致ps->arr开辟的空间，找不到，导致内存泄漏
    ps->arr = NULL;
    free(ps);
    ps = NULL;
    return 0;
}
*/
//第二种方式：
//1、malloc次数越多，增加许多内存碎片，内存利用率较低
//2、释放空间有先后顺序，且多处需要释放，容易给人造成错误
//3、两个空间不是连续的，访问效率降低。
//当CPU访问某位置的数据时，根据局部性原理(下一次CPU80%的可能性会访问周边的数据。)会先将周边的数据从内存中加载到cache中，
//再将cache的数据加载到寄存器中。而CPU访问的数据优先从寄存器中读取，这样当下一次CPU想访问其他数据的时候，命中率就会提高。

//上述两种方式都可以完成同样的功能，但是柔性数组的实现有两个好处：
//第一个好处是：方便内存释放
//如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。
//用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发现这个事。
//所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
//第二个好处是：这样有利于访问速度.
//连续的内存有益于提高访问速度，也有益于减少内存碎片。