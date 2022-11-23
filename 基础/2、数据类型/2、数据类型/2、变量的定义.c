#define _CRT_SECURE_NO_WARNINGS 1
//变量和常量
//常量：如，圆周率、血型、身份证号码等，不可以被改变的量
//变量：如，年龄、工资、体重，可以被改变的量

//变量：
/*
#include <stdio.h>
int main()
{
	//变量的定义
	short age = 18;//向内存申请2字节（16bit），用来存放18
	float weight = 95.6f;
	char ch = 'w';

	age = age + 1;
	weight = weight - 10;

	printf("%d\n", age);//由此可知，变量age，变量weight是可变的
	printf("%f\n", weight);
	return 0;
}
*/
//解读：
//变量的定义，即创建一个变量：①类型 变量名 = 初始值；②类型 变量名；推荐初始化
//float和double类型，显示时，默认小数点后6位
//float weight = 95.6;含义：向内存申请4个字节的空间，即创建了一个空间，名为weight，存放小数95.6，（编译器小数默认为double类型）
//此时会出现警告：“初始化”：从“double”到“float”截断，存入float中会发生精度丢失，解决方法：float weight = 95.6f
//输出格式：%d整型、%f单精度浮点型、%lf双精度浮点型、%c字符型、%s字符串