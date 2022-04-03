#define _CRT_SECURE_NO_WARNINGS 1

//switch语句
//应用场景：输入对应的数字，打印对应的星期数
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	if (1 == day)//当常量和变量比较时，常量在左边比较好
//		printf("星期一\n");
//	else if (2 == day)
//		printf("星期二\n");
//	else if (3 == day)
//		printf("星期三\n");
//	else if (4 == day)
//		printf("星期四\n");
//	else if (5 == day)
//		printf("星期五\n");
//	else if (6 == day)
//		printf("星期六\n");
//	else if (7 == day)
//		printf("星期日\n");
//	else
//		printf("输入错误！\n");
//	return 0;
//}
//以上用if-else语句比较繁琐

//使用switch语句---常用于多分支情况
//switch结构：
//switch (整型表达式)
//{
//	语句项；
//}
//语句项是什么？是一些case语句
//case结构：
//case 整型常量表达式：
//	语句；
//  break;
//注意：整型表达式和整型常量表达式

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//3
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//	case 2:
//		printf("星期二\n");
//	case 3:
//		printf("星期三\n");
//	case 4:
//		printf("星期四\n");
//	case 5:
//		printf("星期五\n");
//	case 6:
//		printf("星期六\n");
//	case 7:
//		printf("星期日\n");
//	}
//		
//	return 0;
//}
//输入3，结果打印星期一，星期二，星期三。
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//3
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//	case 2:
//		printf("星期二\n");
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//	case 5:
//		printf("星期五\n");
//	case 6:
//		printf("星期六\n");
//	case 7:
//		printf("星期日\n");
//	}
//		
//	return 0;
//}
// 调试观察day和运行的变化--遇到break直接跳出switch语句

//上述代码改为：
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	default:
//		printf("输入错误!\n");
//		break;
//	}
//		
//	return 0;
//}
//总结：case决定入口，break决定出口，break跳出switch语句，实现分支

//#include <stdio.h>
//int main()
//{
//	float day = 0.0;//day定义为非整型类型
//	scanf("%d", &day);
//	switch (day)//报错：（ ）内必须为整型表达式
//	{
//	case 1:
////		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
////	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	default:
//		printf("输入错误!\n");
//		break;
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1.0://报错：case后面必须是整型常量表达式（也可以跟字符型，字符型存储的是ASCII码值，也是整型常量）
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	default:
//		printf("输入错误!\n");
//		break;
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	int n = 1;
//	switch (day)
//	{
//	case n://报错：case后面必须为整型且常量表达式
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	default:
//		printf("输入错误!\n");
//		break;
//	}
//
//	return 0;
//}
//注意：break根据需求添加或不加（非必须加上）,但代码习惯，在最后一个case语句后面加上break，防止误以为忘记添加，后续再添加case时，容易出问题

//非必须加上break，例如：
//假设输入1-5时为工作日，输入6-7时为休息日
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;//最后一个case语句，习惯上加break。
//		//假设再加一个case 8：语句，若case 7：没有加break，则会执行case：7和case 8:的语句，
//	default://当所有都不匹配时，才执行。
//		printf("输入错误!\n");
//		break;//建议加上break
//	}
//
//	return 0;
//}
// default:当表达式的值与所有的case标签的值都不匹配时，才会执行这条语句，故每条switch语句中只能出现一条default子句
//default语句根据需求可有可无，case和default语句的位置随意
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)//7
//	{
//	default:
//		printf("输入错误!\n");
//
//	case 2:
//		printf("星期二\n");
//	case 3:
//		printf("星期三\n");
//	case 7:
//		printf("星期日\n");
//	case 1:
//		printf("星期一\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	}
//
//	return 0;
//}//输入7时，打印结果：星期日，星期一。输入8时，打印结果：输入错误！，星期二，星期三，星期日，星期一
//总结：不管case和default的顺序，都是从匹配的case或者default进入，一直往下穿透，直到遇到第一个break出来
//故：建议default加上break
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	default:
//		printf("输入错误!\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	case 1:
//		printf("星期一\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	}
//
//	return 0;
//}
//总结：在switch中，可以有case，break，default，if

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//  int n = 1;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		if( n == 1)
//			printf("今天");
//		printf("星期一\n");//case语句管理的是后面多行语句
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	}
//	return 0;
//}

//练习：
/*1、用在switch语句中的关键字不包括哪个？*/
//正确结果A.continue
//B.break
//C.default
//D.if
/*2、下面代码的执行结果为：*/
//#include <stdio.h>
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;//m = 3
//	case 2:
//		n++;//n = 2
//	case 3:
//		switch (n)// n = 2
//		{//switch允许嵌套使用
//		case 1:
//			n++;
//		case 2:
//			m++;//m = 4
//			n++;//n = 3
//			break;
//		}
//	case 4:
//		m++;//m = 5
//		break;
//	default:
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0; 
//}
//正确结果为：m = 5, n = 3