#define _CRT_SECURE_NO_WARNINGS 1
//各种操作符的介绍。

//1. 操作符分类：
//算术操作符：+ - * / %
/*
#include <stdio.h>
int main() 
{
	int a = 5 / 2;//商2
	printf("%d\n", a);
	int b = 5 % 2;//余1
	printf("%d\n", b);
	//如果想要结果为小数，除数和被除数至少一个为小数
	double c = 5 / 2.0;
	printf("%lf\n", c);//默认6位小数 
	//注意：%两边都必须是整型,结果的正负只与%左端的数的正负有关.右端不能是0或负数
	//double d = 5 % 2.0;//报错

	return 0;
}
*/
//1. 除了 % 操作符之外，其他的几个操作符可以作用于整数和浮点数。
//2. 对于 / 操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
//3. % 操作符的两个操作数必须为整数。返回的是整除之后的余数。

//移位操作符：<< 左移操作符、>> 右移操作符。把操作数的二进制补码向左或向右移位
//移位操作符操作的是二进制补码运算，即存储在内存的是补码.运算和存储的是补码，打印和显示的是原码
/*
#include <stdio.h>
int main()
{
	//位移操作符：
	//1、算术移位：符号位不参与移位
	//a << b 将a左移b位，丢弃被移出位，右边空位（正数和负数）用0填充
	//a >> b 将a右移b位，丢弃被移出位，左边最高位（正数）用0或（负数）1填充
	// 算术右移：正数、负数，右边丢弃，左边补原符号位，即：符号位不动，空出来的位补一个符号位
	// 算术左移：正数、负数，左边丢弃，右边均补0
	//右移一位，结果除2，左移一位，结果乘2
	//2、逻辑移位：符号位参与移位
	//右边丢弃，左边补0
	int a = 16;
	int b = a >> 1;//算术移位
	//int型：16 = 00000000 00000000 00000000 00010000
	printf("%d\n",b);
	printf("%d\n",a);
	//移位操作符并没有改变操作数的大小

	int c = -1;
	int d = c >> 1;//算术移位
	printf("%d\n", d);
	//int型：-1 = 10000000 00000000 00000000 00000001
	//原码：1 0000000 00000000 00000000 00000001
	//反码：1 1111111 11111111 11111111 11111110
	//补码：1 1111111 11111111 11111111 11111111
	//调试：窗口--内存，在地址栏，输入&c，观察地址对应的值FF FF FF FF
	//右移一位：补码移位后：1 11111111 11111111 11111111 1111111(符号位不参与移位)
	//转为原码打印：1 0000000 00000000 00000000 00000001 = -1

	int e = -1;
	int f = e << 1;//算术移位
	printf("%d\n", f);
	//补码：1 1111111 11111111 11111111 11111111
	//左移一位：补码移位后：1 111111 11111111 11111111 11111110(符号位不参与移位)
	//转为原码打印：1 0000000 00000000 00000000 00000100 = -2
	return 0;
}
*/
//注：移位操作符的操作数只能是整数。对于移位运算符，不要移动负数个位，这个是标准未定义的。
//如：
//int num = 10;
//num >> -1;//error

//位操作符：& 按位与、| 按位或、^ 按位异或.把操作数的二进制补码进行按位操作
//注：他们的操作数必须是整数。
//移位操作符操作的也是二进制补码运算，即存储在内存的是补码
/*
#include <stdio.h>
int main()
{
	//&：有一个为0，则结果为0
	int a = 3;
	int b = 5;
	int c = a & b;
	printf("%d\n",c);
	//|：有一个为1，则结果为1
	int d = a | b;
	printf("%d\n", d);
	//^：相同为0，相异为1
	int e = a ^ b;
	printf("%d\n", e);
	//3的补码 = .... 00000011
	//5的补码 = .... 00000101
	//  3 ^ 5 = .... 00000110 
	//则打印3 ^ 5结果的原码也为00000110，即6
	return 0;
}
*/
//练习一下：
//例如：不能创建临时变量（第三个变量），实现两个数的交换。
/*
//#include <stdio.h>
//int main()
//{
	int a = 3;
	int b = 5;
	printf("before:a = %d,b = %d\n", a, b);
	/*
	//有临时变量
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	*/

	/*
	//无临时变量
	a = a + b;//a = 8,b = 5
	b = a - b;//b = 3,a = 8
	a = a - b;//a = 5,b = 3;
	//当两个数超级大时，相加的结果可能会有溢出
	*/
	
	/*
	//异或方法，兼容了以上两种
	//a ^ b ^ b = a，a ^ b ^ a = b
	//0 ^ a = a, a ^ a = 0
	a = a ^ b;
	b = a ^ b;//a ^ b ^ b = a
	a = a ^ b;//a ^ b ^ a = b 
	*/
//	printf("after: a = %d,b = %d\n", a, b);
//	return 0;
//}

//练习：
//例如：编写代码实现：求一个整数存储在内存中的二进制中1的个数。(即求一个数补码中1的个数)
//思考：对于十进制数，想要得到每一位，则先%10得到个位，再/10去掉了个位...循环操作
//同理，对于二进制数，想要得到每一位，则先%2得到个位，再/2去掉了个位...循环操作
/*
#include <stdio.h>
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d",&num);
	//统计二进制num中的1
	while (num)
	{
		if (num % 2 == 1)
			count++;
		num = num / 2;
	}
	printf("%d\n", count);
	return 0;
}
//以上方法不适合负数的补码。因为负数%2不可能为1，count++不可能++。如假设这个数为-1，则补码有32个1.
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	//统计二进制num的补码中的1
	int i = 0;
	for (i = 0; i < 32; i++)//必须循环32次，因为是int型占32位
	{
		if (1 == (num >> i) & 1)
		// 00000000 00000000 00000000 00000011
		//&00000000 00000000 00000000 00000001
		//将数右移一位，再&1，如果是1，则二进制位为1
			count++;
	}
	printf("%d\n", count);
	return 0;
}
*/

//单目操作符
/*
#include <stdio.h>
int main()
{
	int a = 10;
	if (a)//a为真则执行
	{
		printf("hehe\n");
	}
	if (!a)//a为假则执行
	{
		printf("hehe\n");
	}
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = 10;
	char c = 'c';
	char* p = &c;
	int arr[10] = { 0 };

	printf("%d\n", sizeof(a));//4，等同于printf("%d\n",sizeof(int))，等同于printf("%d\n",sizeof a)
	printf("%d\n", sizeof(c));//1，等同于printf("%d\n",sizeof(char))，等同于printf("%d\n",sizeof c)
	printf("%d\n", sizeof(p));//32 - 4/64 - 8，等同于printf("%d\n",sizeof(char*))
	printf("%d\n", sizeof(arr));//40，等同于printf("%d\n",sizeof(int [10]))
	//注意：可以通过变量名，和变量类型计算变量的空间大小
	//数组的变量类型是：类型 [元素个数]
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	short s = 0;
	int a = 10;
	printf("%d\n", sizeof(s = a + 5));//s为short型，占2个字节
	printf("%d\n", s);//虽然没有溢出，但是s = a + 5在sizeof()中表达式是不会发生运算，即s = 0
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = 0;
	printf("%d\n", ~a);
	//按位取反，运算了也是二进制位的补码。包括符号位在内一起取反
	//0的补码：00000000 000000000 00000000 00000000
	//补码取反：11111111 111111111 11111111 11111111
	//打印的是原码：10000000 00000000 00000000 00000001 = -1

	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = 11;
	//00000000 000000000 00000000 00001011
	//00000000 000000000 00000000 00001111
	//如何将右边倒数第3位的0，改为1？
	//只需要按位或上00000000 000000000 00000000 00000100这个操作数
	//如何得到这个操作数？对于要改的数值很大，每次计算这个操作数是不现实的。可以将1进行左移得到该操作数
	
	a = a | (1 << 2);
	printf("%d\n", a);

	//00000000 000000000 00000000 00001111
	//00000000 000000000 00000000 00001011
	//如何将右边倒数第3位的1，改回0？
	//只需要按位与11111111 111111111 11111111 11111011
	//如何得到这个操作数？可以将1进行左移，然后进行取反得到该操作数
	//00000000 000000000 00000000 00000100按位取反即可
	//11111111 111111111 11111111 11111011
	a = a & (~(1 << 2));
	printf("%d\n", a);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = 10;
	printf("%d\n", ++a);//11
	printf("%d\n", a++);//10
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = (int)3.14;//会报警告：从“double”转换到“int”，可能丢失数据。
	//如果不需要看到警告，可以强制类型转换
	//注意：不是int a = int(3.14)//error
	return 0;
}
*/
/*
#include <stdio.h>
void test1(int arr[])//此时真正的是用int* arr指针变量接收，所以sizeof(arr)计算的arr是一个指针的大小
{
	printf("%d\n", sizeof(arr));//32位 - 4字节/64位 - 8字节
}
void test2(char ch[])//此时真正的是用char* ch指针变量接收
{
	printf("%d\n", sizeof(ch));//32位 - 4字节/64位 - 8字节
}
int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//40
	printf("%d\n", sizeof(ch));//4
	test1(arr);//作为参数时，传入的时首元素的地址
	test2(ch);//作为参数时，传入的时首元素的地址

	//注意：数组传参，本质上是指针传参，如：int arr[] ,int *arr,所以函数里面sizeof(arr)计算的是sizeof(int*)
	return 0;
}
*/

//逻辑操作符：&& 逻辑与、|| 逻辑或
//区分逻辑与和按位与
//1 && 2 -----> 1
//1 & 2  -----> 0
//区分逻辑或和按位或
//1 || 2 -----> 1
//1 | 2  -----> 3
//按位运算：是二进制位的补码运算
//逻辑运算：是逻辑真假的运算
//逻辑与：如果左边操作数为0，则右边的表达式不执行--短路与
//逻辑或：如果左边操作数为1，则右边的表达式不执行--短路或
//注意：逻辑结果1为真，0为假。但数值为非0代表真，数值为0代表假
/*
//程序输出的结果是什么？
#include <stdio.h>
int main()
{
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++;//a++ = 0，此时后面的操作不执行
	printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);//1 2 3 4

    i = a++ || ++b || d++;
    printf("a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);//1 3 3 4
    return 0;
}
*/

//条件操作符：exp1？exp2：exp3
/*
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	if (a > 5)
		b = 3;
	else
		b = -3;
	//转换成条件表达式，是什么样？
	b = (a > 5 ? 3 : -3);
	//b = (a > 5 ? b = 3 : b = -3);//这种书写是错的，报错“ = ”: 左操作数必须为左值

	return 0;
}
*/
/*
//使用条件表达式实现找两个数中较大值。
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	//1.
	if (a > b)
		max  = a;
	else
		max = b;
	//2.
	max = (a > b ? a : b);

	return 0;
}
*/

//逗号表达式：exp1,exp2,exp3...expN
//逗号表达式，就是用逗号隔开的多个表达式。
//逗号表达式，从左向右依次执行。整个表达式的结果是最后一个表达式的结果。
/*
#include <stdio.h>
int main()
{
    //代码1
    int a = 1;
    int b = 2;
    int c = (a > b, a = b + 10, a, b = a + 1);//逗号表达式
    //c是多少？//13
        
    //代码2
    int d = 10;
    if (a = b + 1, c = a / 2, d > 0)
    
    //代码3
    a = get_val();
    count_val(a);
    while (a > 0)
    {
        //业务处理
        a = get_val();
        count_val(a);
    }
    //如果使用逗号表达式，改写：
    while (a = get_val(), count_val(a), a > 0)
    {
        //业务处理
    }
    
    return 0;
}
*/

//下标引用、函数调用和结构成员
//1. [ ] 下标引用操作符
//操作数：一个数组名 + 一个索引值
/*
#include <stdio.h>
int main()
{
	int arr[10];//创建数组
	arr[9] = 10;//使用下标引用操作符。
	//[] 的两个操作数是arr和9。

	return 0;
}
*/
//2. ( ) 函数调用操作符
//接收一个或者多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数。
/*
#include <stdio.h>
int get_max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int a = 10;
	int b = 20;
	int max = get_max(a,b);//操作数有3个，get_max,a,b
	printf("max = %d\n", max);
	return 0;
}
*/
/*
#include <stdio.h>
void test1()
{
	printf("hehe\n");
}
void test2(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	test1();            //使用（）作为函数调用操作符。操作数只有1个，test1
	test2("hello bit.");//使用（）作为函数调用操作符。操作数有2个，test2,"hello bit."
	return 0;
}
*/

//3. 访问一个结构的成员 :	“.”结构体.成员名、“->”结构体指针->成员名
//自定义类型：如创建一个学生这样的类型struct Stu
//创建类型的目的，是为了创建变量
//创建了一个结构体类型-struct Stu
/*
#include <stdio.h>
struct Stu
{
	char name[20];
	int age;
	char id[20];
};
int main()
{
	//使用struct Stu这个类型创建了一个学生变量/对象s1，并初始化，即类似于面向对象中的类和对象
	//对于变量的属性有很多时，使用{}进行初始化，如：数组的初始化
	struct Stu s1 = { "张三",20,"2022010116" };
	//使用.操作符访问结构体成员属性
	printf("%s\n",s1.name);
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);
	//struct Stu*结构体指针变量的类型
	struct Stu* p = &s1;
	//通过指针变量解引用找到变量的内容
	//*p找到了结构体变量s1, (*p).成员变量通过指针解引用找到结构体变量的具体属性的内容
	printf("%s\n", (*p).name);
	printf("%d\n", (*p).age);
	printf("%s\n", (*p).id);
	//为了书写方便:结构体指针->成员名
	printf("%s\n", p->name);
	printf("%d\n", p->age);
	printf("%s\n", p->id);
	return 0;
}
*/
/*
#include <stdio.h>
struct Stu
{
	char name[10];
	int age;
	char sex[5];
	double score;
};
void set_age1(struct Stu stu)
{
	stu.age = 18;//结构成员访问
}
void set_age2(struct Stu* pStu)
{
	pStu->age = 18;//结构成员访问
}
int main()
{
	struct Stu stu;
	struct Stu* pStu = &stu;

	stu.age = 20;//结构成员访问
	set_age1(stu);

	pStu->age = 20;//结构成员访问
	set_age2(pStu);
	return 0;
}
*/

//2. 表达式求值
//隐式类型转换
//C的整型算术运算总是至少以缺省整型类型的精度来进行的。
//为了获得这个精度，表达式中的 字符型char 和 短整型short 操作数在使用之前被转换为普通整型，这种转换称为整型提升。
//char和short达不到int大小就会发生整型提升，即比int大的或相等的不要整型提升。一般ALU中操作数的字节长度为int类型，所以小于int要整型提升
//例如：
//char a, b, c;
//...
//a = b + c;
//b和c的值被提升为普通整型，然后再执行加法运算。
//加法运算完成之后，结果仍为整型，然后将被截断，再存储于a中。

//如何进行整型提升呢？
//整形提升是按照变量的数据类型的符号位来提升的
//1. 负数的整形提升
//char c1 = -1;
//-1 = 10000000000000000000000000000001//原码
//-1 = 11111111111111111111111111111111//补码
//变量c1的二进制位(补码)中只有8个比特位：
//c1 = 1111111
//因为 char 为有符号的 char，而符号位为1
//所以c1整型提升的时候，高位补充符号位，即为1
//提升之后的结果是：1 1111111111111111111111111111111
//2. 正数的整形提升
//char c2 = 1;
//1 = 00000000000000000000000000000001//原码
//1 = 00000000000000000000000000000001//补码
//变量c2的二进制位(补码)中只有8个比特位：
//c2 = 00000001
//因为 char 为有符号的 char，而符号位为0
//所以c2整型提升的时候，高位补充符号位，即为0
//提升之后的结果是：0 0000000000000000000000000000001
//注意：无符号整型提升，高位补0
/*
#include <stdio.h>
int main()
{
	char a = 3;
	//3的补码
	//00000000 00000000 00000000 00000011 = 3
	//a的补码
	//0 0000011 = a
	char b = 127;
	//127的补码
	//00000000 00000000 00000000 01111111 = 3
	//b的补码
	//0 1111111 = b
	char c = a + b;
	//发现a和b都是char类型，都没有达到int类型大小，所以需要整形提升
	//补码a + 补码b，相加时，补码a和b整型提升，为普通整型
	//a和b根据变量的数据类型的符号位来提升
	//a = 0 0000000 00000000 00000011（a是char类型，是有符号字符类型，符号位为0，整型提升前面补0）
	//b = 0 0000000 00000000 01111111（b是char类型，是有符号字符类型，符号位为0，整型提升前面补0）
	//a + b = 0 0000000 00000000 10000010//补码
	//c = 1 0000010//补码，结果截断
	//由于打印c时是以%dint型打印，故需要对c进行整型提升（c是char类型，是有符号字符类型，符号位为1，整型提升前面补1）
	//符号位为0补0，符号位为1补1
	//c = 1 1111111 11111111 10000010//补码
	//c的原码：1 0000000 00000000 01111110 = -126
	return 0;
}
*/

//整形提升的例子 :
//实例1
/*
#include <stdio.h>
int main()
{
	char a = 0xb6;//0xb6 == 0000000 00000000 00000000 10110110（正数）
	short b = 0xb600;//0xb600 == 0000000 00000000 10110110 00000000（正数）
	int c = 0xb6000000;//0xb6000000 == 10110110 00000000 0000000 00000000 (负数)
	if (a == 0xb6)//a与0xb6比较，会进行整型提升
		printf("a == %d", a);
	if (b == 0xb600)//b与0xb600比较，会进行整型提升
		printf("b == %d", b);
	if (c == 0xb6000000)//c与0xb6000000比较，不会进行整型提升
		printf("c == %d", c);
	return 0;
}
*/
//0xb6 = 0000000 00000000 00000000 10110110
//则该数的补码为：0000000 00000000 00000000 10110110
//a存放的补码为：10110110
//a与0xb6比较，会进行整型提升
//a整型提升后为：11111111 11111111 11111111 10110110（补码）
//同理：
//b存放的补码为：10110110 00000000
//b整型提升后为：11111111 11111111 10110110 00000000（补码）
//实例1中的a, b要进行整形提升, 但是c不需要整形提升
//a, b整形提升之后, 变成了负数, 所以表达式 a == 0xb6, b == 0xb600 的结果是假, 但是c不发生整形提升, 
//则表达式 c == 0xb6000000 的结果是真.
//所以程序输出的结果是 :c

//实例2
/*
#include <stdio.h>
int main()
{
	char c = 1;
	printf("%u\n", sizeof(+c));//4，计算c的类型大小，c的类型提升为整型
	printf("%d\n", c);//1
	printf("%u\n", sizeof(-c));//4，计算c的类型大小，c的类型提升为整型
	printf("%d\n", c);//1
	printf("%u\n", sizeof(!c));//4，gcc中为4，以gcc为准
	printf("%d\n", c);//1
	return 0;
}
*/
//实例2中的, c只要参与表达式"运算", 就会发生整形提升, 表达式 +c, 就会发生整型提升, 所以 sizeof(+c) 计算的是整型大小是4个字节.
//同理，表达式 -c 也会发生整型提升, 所以 sizeof(-c) 是4个字节, 但是sizeof(c) sizeof(!c) 就是1个字节
//注意：+c,-c,!c没有参与运算，但会发生整型提升，而结果类型是推导出来的，所以都为int类型，但是没有计算
//如 sizeof（s = a + 3）
//sizeof计算出的结果为unsigned int类型 用 %u 打印
/*
#include <stdio.h>
int main()
{
	int a = 1;
	int b = 2;
	a + b;//每个变量都有两个属性，一个值属性和一个类型属性。类型属性可以推导出来。
	//由于a，b都是int，所以类型自动推导结果也为int类型

	short s = 5;
	printf("%d\n",sizeof(s = a + 3));//s的类型为short，计算的是变量的类型大小，所以为2byte
	printf("%d\n", s);//5
	return 0;
}
*/

//整型提升的意义：
//表达式的整型运算要在CPU的相应运算器件内执行，CPU内整型运算器(ALU)的操作数的字节长度
//一般就是int的字节长度，同时也是CPU的通用寄存器的长度。
//因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。
//通用CPU（general - purpose CPU）是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。
//所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。

//算术转换
//如果某个操作符的各个操作数属于不同的类型，那么除非其中一个操作数的转换为另一个操作数的类型，否则操作就无法进行。
//下面的层次体系称为寻常算术转换。即占字节小的类型可以转为占字节大的类型，精度小的可以转为精度大的
//long double
//double
//float
//unsigned long int
//long int
//unsigned int
//int
//如果某个操作数的类型在上面这个列表中排名较低，那么首先要转换为另外一个操作数的类型后执行运算。
//如：两个long int 和int类型的数进行运算，会隐式将int类型的数据转为long int类型。
/*
#include <stdio.h>
int main()
{
	float f = 3.14f;
	int i = 2;
	f + i;//会将i隐式提升为float类型，再进行运算
	return 0;
}
*/
//警告：但是算术转换要合理，要不然会有一些潜在的问题。
//float f = 3.14;
//int num = f;//隐式转换，会有精度丢失

//操作符的属性
//复杂表达式的求值有三个影响的因素。
//1. 操作符的优先级
//2. 操作符的结合性//从左向右结合，从右向左结合
//3. 是否控制求值顺序。
//两个相邻的操作符先执行哪个？取决于他们的优先级。如果两者的优先级相同，取决于他们的结合性。

//一些问题表达式
//表达式的求值部分由操作符的优先级决定。
//表达式1：a* b + c * d + e * f
//注释：代码1在计算的时候，由于*比+的优先级高，只能保证，*的计算是比+早，但是优先级并不能决定第三个 * 比第一个 + 早执行。
//此时不同的表达式计算，可能会影响后续的计算，即是有问题的表达式。
//所以表达式的计算顺序就可能是：a*b  c*d a*b+c*d e*f (a*b+c*d)+e*f或者a*b c*d e*f a*b+c*d (a*b+c*d)+e*f(只要满足相邻操作符优先级高的先执行)
//当a b c d e f如果为表达式，就不同的顺序所求的结果可能存在问题

//表达式2：c + --c;
//如先c = 1，此时--c = 0，整个结果为1
//如c = 1先--c = 0,c = 0，整个结果为0
//注释：同上，操作符的优先级只能确定自减--的运算在+的运算的前面，但是我们并没有办法得知，
//+ 操作符的左操作数的获取在右操作数之前还是之后求值，所以结果是不可预测的，是有歧义的。

//代码3-非法表达式
/*
#include <stdio.h>
int main()
{
	int i = 10;
	i = i-- - --i * (i = -3) * i++ + ++i;
	printf("i = %d\n", i);
	return 0;
}
*/
//表达式3在不同编译器中测试结果，可能不一样

//代码4
/*
#include <stdio.h>
int fun()
{
    static int count = 1;
    return ++count;
}
int main()
{
    int answer;
    answer = fun() - fun() * fun();
    printf("%d\n", answer);//输出多少？
    return 0;
}
*/
//这个代码有没有实际的问题？有问题！
//虽然在大多数的编译器上求得结果都是相同的。
//但是上述代码 answer = fun() - fun() * fun(); 中我们只能通过操作符的优先级得知：先算乘法，再算减法。
//但函数的调用先后顺序无法通过操作符的优先级确定。
//比如上面：fun()调用了三次，结果分别为2，3，4.但结果可以是answer = 2 - 3 * 4或answer = 3 - 2 * 4...等等顺序的结果

//代码5
/*
#include <stdio.h>
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("%d\n", ret);
	printf("%d\n", i);
	return 0;
}
*/
//尝试在linux环境gcc编译器为10，4，在vs2013环境下执行为12，4
//这段代码中的第一个 + 在执行的时候，第三个++是否执行，这个是不确定的，因为依靠操作符的优先级
//和结合性是无法决定第一个 + 和第三个前置 ++ 的先后顺序。

//总结：我们写出的表达式如果不能通过操作符的属性确定唯一的计算路径，那这个表达式就是存在问题的。
//未来写代码，要表达一个计算结果，分步骤进行拆分书写。