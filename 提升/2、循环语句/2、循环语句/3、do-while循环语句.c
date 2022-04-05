#define _CRT_SECURE_NO_WARNINGS 1

//do...while()循环
//do语句的语法：
//do
//{
//	循环语句；
//}while(表达式);
// 当没有{ }时，do只管理一条语句
//注意：do...while();后面的分号结束标志不能少
//特点：先进行一次循环后，再判断（至少执行一次）
//意义：先执行语句，再判断

//do...while循环打印1-10
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}

//do...while循环中break和continue的作用
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}
//正确结果：打印1 2 3 4
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	} while (i <= 10);
//	return 0;
//}
//正确结果：1 2 3 4后面不打印死循环