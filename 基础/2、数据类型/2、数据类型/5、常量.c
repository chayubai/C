#define _CRT_SECURE_NO_WARNINGS 1

//常量的分类
//1、字面常量（没啥实际意义）如：3.14、10、‘a’、“abcde”
//2、const修饰的常变量

/*
#include <stdio.h>
int main()
{
	int num = 10;
	num = 20;
	printf("num = %d\n", num);//num为变量，即可以改变的量
	return 0;
}
*/

//const修饰的变量是不能改变的
/*
#include <stdio.h>
int main()
{
	const int num = 10;//num为常变量，const修饰的常变量
	num = 20;//报错：左值指定const对象，即左边的变量被const修饰，则值不能被修改
	printf("num = %d\n", num);
	return 0;
}
*/
//常变量具有常属性，即不能被改变的属性

/*
#include <stdio.h>
int main()
{
	int arr[10] = {0};//arr中有10个元素，每个元素为整型类型
	int n = 10;
	int arr2[n] = {0};//报错：应输入常量表达式。说明n是变量

	return 0;
}
//常变量也是变量
#include <stdio.h>
int main()
{
	const int n = 10;
	int arr2[n] = {0};//报错：表达式必须含有常量值，应输入常量表达式。说明n是变量，具有常属性
	return 0;
}
*/

//3、#define定义的标识符常量
/*
#include <stdio.h>
#define Max 10000//结尾没有分号，此行须放在主函数外，但不能放在#include <stdio.h>前
int main()
{
	//Max = 2000;//报错：不能修改
	int n = Max;
	printf("n = %d\n", n);

	return 0;
}
*/
/*
#include <stdio.h>
#define Max 10
int main()
{
	int arr[Max];//警告：“arr”未引用的局部变量，即arr数组未初始化，将arr[Max]初始化，如int arr[Max] = {0};
	//说明：Max是常量
	return 0;
}
*/

//4、枚举常量：可以一一列举的常量，如：血型、星期、性别
//枚举关键字--enum
/*
#include <stdio.h>
enum Sex//Sex是枚举变量
{	//把性别的可能取值一一列举出来
	MALE,
	FEMALE,
	SECRET
	//这些是枚举常量，是这种枚举类型（类型为enum Sex）创建的变量（如：s）的未来可能的取值
};//结尾要分号
int main()
{
	enum Sex s = MALE;//s 是拿枚举类型创建的变量
	printf("%d\n", MALE);//0
	printf("%d\n", FEMALE);//1
	printf("%d\n", SECRET);//2
	//枚举常量的值默认从0开始
	return 0;
}
*/
//又如：
/*
#include <stdio.h>
enum Color
{
	RED = 4,//可以赋初值
	YELLOW,
	BULE
};
int main()
{
	enum Color color = BULE;
	color = YELLOW;
	//BLUE = 6;报错：“=”左操作数必须为左值。但枚举常量不能改变大小

	return 0;
}
*/