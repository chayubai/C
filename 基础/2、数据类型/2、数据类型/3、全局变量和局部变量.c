#define _CRT_SECURE_NO_WARNINGS 1
//变量的分类：全局变量和局部变量
/*
#include <stdio.h>

int a = 100;//全局变量：大括号{}外部定义的变量

int main()
{
	int a = 10;//局部变量：大括号{}内部定义的变量，局部变量不一定放在主函数内部
	printf("%d\n", a);

	return 0;
}
*/
//注意：当局部变量和全局变量名字冲突时（相同时），局部变量优先，不建议全局变量和局部变量名相同

/*
#include <stdio.h>
int main()
{
	{
		int a = 10;//局部变量：大括号{}内部定义的变量
	}
	printf("%d\n", a);

	return 0;
}
*/
//报错：“a”：为声明的标识符，局部范围定义的变量，不能在局部范围外使用

//若改为全局变量，则不会报错
/*
#include <stdio.h>
int a = 100;//全局变量：大括号{}外部定义的变量
int main()
{
	printf("%d\n", a);

	return 0;
}
*/

//变量的使用：
//问题：计算两个数的和
/*
#include <stdio.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1,&num2);//输入数据，&取地址符号，即分别将输入的两个数放在num1，num2地址处，输入如：10 20
	int sum = 0;//报错：C++代码，哪里需要哪里定义。C语言规定，变量的定义，要放在当前代码块的最前面
	sum = num1 + num2;
	printf("sum = %d\n", sum);

	return 0;
}
*/
//scanf()输入函数：
//scanf("%d%d",&num1,&num2)：两个%d表示输入两个整型数据（输入的两个数据，空格隔开）
//&num1,&num2，表示取两地址，把输入的数据分别放在各自的地址处

//53行可能会报错，解决办法：将变量的定义定义在代码块的最前面。
//C语言规定，变量的定义，要放在当前代码块的最前面