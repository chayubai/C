//常见C语言内置的关键字：
// 1、C语言提供的，不能自己创建关键字
// 2、关键字不能做变量名
//auto、break、case、char、const、continue、default、do、double、else、enum、
//extern、flaot、for、goto、if、int、long、register、return、short、signed、
//sizeof、static、struct、switch、typedef、union、unsigned、void、volatile、while
/*
#include <stdio.h>
int main()
{
	//auto--自动的，每个局部变量都是auto修饰的
	{
		int a = 10;//a（局部变量一般）自动创建，自动销毁 --自动变量，一般都省去auto
		auto int a = 10;
	}
	return 0;
}
*/
//break：循环语句，和switch-case语句中
//case：switch-case语句
//const：修饰的常变量
//continue：继续，循环中使用
//default：默认，switch-case语句
//do：do-while循环
//else：if-else语句
//enum：枚举关键字
//extern：声明//引入外部符号
//goto：goto语句
//register：寄存器关键字
/*
#include <stdio.h>
int main()
{
	//计算机数据存放位置：寄存器，高速缓存，内存，硬盘
	register int num = 100;//把a定义成寄存器变量。
	//建议num的值存放在寄存器中，最终是否放入寄存器中，由编译器决定
	//为什么想把它存入到寄存器中？内存读取速度慢，CPU速度快，而寄存器速度比内存快，将大量频繁的数据建议放入寄存器中-提高与CPU的交流速度

	return 0;
}
*/
//signed：有符号的，unsigned：无符号的
/*
#include <stdio.h>
int main()
{
	int a = 10;//int定义的变量是有符号的，原型为signed int
	signed int a = 10；
	a = -2;
	unsigned int num = -1;//num的结果仍为1
	return 0;
}
*/
//static：静态的，是用来修饰变量和函数的
//1、static修饰局部变量-静态局部变量--改变了变量的生命周期
//2、static修饰全局变量-静态全局变量--改变了变量的作用域
//3、static修饰函数-静态函数--改变了函数的链接属性
/*1、
#include <stdio.h>
void test()
{
	int a = 1;//a是局部变量，特点：进入时，a创建，出去时，a销毁
	a++;
	printf("%d ",a);
} 
int main()
{
	int i = 0;
	while (i < 10)
	{
		test();//每调用函数，a重新创建，再次销毁
		i++;
	}
	return 0;
}
//结果：2 2 2 2 2 2 2 2 2 2
*/
/*
#include <stdio.h>
void test()
{
	static int a = 1;//a是static修饰的局部变量，特点：进入时，a创建，出去时，a没有销毁
	a++;
	printf("%d ", a);//2
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		test();//a没有创建，没有销毁
		i++;
	}

	return 0;
}
//结果：2 3 4 5 6 7 8 9 10 11
//调试观察i和a的变化
//static修饰局部变量：局部变量的生命周期变长
//static修饰的局部变量，改变了局部变量的生命周期（本质上是改变了变量的存储类型） ，让静态的局部变量出了作用域依然存在，到程序结束，生命周期才结束
//内存分为三大区域，不同的区域有不同的特点（1）栈区：存储的是局部变量、函数的参数（2）堆区：存储的是动态内存分配的（3）静态区：存储的是全局变量、static修饰的静态变量
//当a变量没有被static修饰时，存储在栈区，被static修饰时存储在静态区，改变了存储类型
//static修饰的静态变量的生命周期和全局变量的生命周期一样长，即整个程序的生命周期
*/
/*2、
//新建一个源文件，add.c,加入一行代码：int g_val = 2020;//全局变量
//在test.c源文件使用g_val
#include <stdio.h>
//extern声明外部符号
extern int g_val;//声明g_val标识符
int main()
{
	printf("%d\n", g_val);//报错："g_val":为未声明的标识符.解决：声明外部符号extern int g_val;

	return 0;
}
*/
/*
//若add.c文件加入static修饰int g_val = 2020;即：static int g_val = 2020;
//在test.c源文件使用g_val
#include <stdio.h>
extern int g_val;
int main()
{
	printf("%d\n", g_val);//报错：无法解析的外部符号g_val

	return 0;
}
//static修饰全局变量，让静态的全局变量只能在所在的源文件内部使用，出了源文件就无法再使用
//全局变量，在其它源文件内部可以被使用，是因为全局变量具有外部链接属性
//但是被static修饰之后，就变成了内部链接属性，其他源文件就不能链接到这个静态的全局变量
*/
/*3、*/
//新建一个源文件，add.c,加入代码:
/*
	int Add(int x,int y)
	{
		int z = x + y;
		return z;
	}
*/
/*
//在test.c源文件使用Add()
#include <stdio.h>
//extern声明外部函数
extern int Add(int, int);//或者extern int Add(int x,int y);//声明Add()
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);//报错："Add"未定义。解决：声明外部函数
	printf("sum = %d\n", sum);
	return 0;
}
*/
//若add.c文件加入static修饰
/*
	static int Add(int x,int y)
	{
		int z = x + y;
		return z;
	}
*/
/*
//在test.c源文件使用Add()
#include <stdio.h>
extern int Add(int, int);//或者extern int Add(int x,int y);
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);//报错：无法解析的外部符号_Add，函数_main中引用了该符号
	printf("sum = %d\n", sum);
	return 0;
}
//static修饰函数，改变了函数的链接属性，使得函数只能再自己所在的源文件内部使用，不能在其他源文件内部使用
//本质上：普通函数具有外部链接属性，static是将函数的外部链接属性变成了内部链接属性（和static修饰全局变量一样）
*/
//struct：结构体关键字
//switch：switch-case语句
//typedef：类型定义/类型重命名--type define
/*
#include <stdio.h>
typedef unsigned int u_int;//将unsigned int 重新取了一个名字/别名叫u_int，类型不变
int main()
{
	unsigned int num1 = 100;//num的类型unsigned int太复杂，重新定义一个类型
	u_int num2 = 100;//u_int也是一个类型名
	//num1和num2变量的类型是一样的
	return 0;
}
*/
//union：联合体/共用体
//void：空/无
//volatile：提升C语言段位的关键字

//注意：define、include不是关键字，它们是预处理指令
/*#define定义常量和宏*/
/*
//1、define定义标识符常量
#define MAX 1000
//2、define定义宏
#define ADD(x,y) ((x)+(y))//宏ADD(x,y)被替换成 ((x)+(y))--(x)和（y）是两个表达式
#define SUM(a,b) a+b//宏ADD(a,b)被替换成 a+b
#include <stdio.h>
int mian()
{
	printf("%d\n", MAX);
	int sum = SUM(2, 3);//2+3=5
	printf("sum = %d\n", sum);
	int c = ADD(2, 3);//((2)+(3))=5
	printf("%d\n",c);
	sum = 10 * SUM(2, 3);//10*2+3=23
	printf("sum = %d\n", sum);
	int c = 10 * ADD(2, 3);//10*((2)+(3))=50
	printf("%d\n",c);

	return 0;
}
*/
/*
//用函数实现两个数的大小：
#include <stdio.h>
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a, b);
	printf("max = %d\n",max);

	return 0;
}
*/
/*
//用宏实现两个数的大小：
#define Max(X,Y) (X>Y?X:Y)//宏Max(X,Y)被替换成 (X>Y?X:Y)
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a, b);//被替换成a>b?a:b
	printf("max = %d\n",max);

	return 0;
}
*/