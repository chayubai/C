#define _CRT_SECURE_NO_WARNINGS 1
//作业2：
//1、统计二进制中1的个数
//写一个函数返回参数二进制中(补码)1的个数
//如：15(00000 11111)输出4个1
//方法1：此方法由获取十进制每位联想而来，确定不适用于负数的补码，即把符号位也考虑进去的
//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//方法2：将符号位同其他位地位相同
//int count_bit_one(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n = n / 2;
//	}
//	return count;
//}
//方法3：将每一位都拿到
//int count_bit_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for(i = 0;i < 32;i++)//i从0开始，只需要移31次
//	{
//		if (((n >> i) & 1 )== 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//方法4：
//如：13 - 1101
//n = 1101，n-1 = 1100
//n & n-1 = 1100//第一次循环
//n = 1100，n-1 = 1011
//n & n-1 = 1000//第二次循环
//n = 1000，n-1 = 0111
//n & n-1 = 0000//第三次循环
//int count_bit_one(int n)
//{
//	int count = 0;
//	while(n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int count = count_bit_one(a);
//	//system("pause");//system库函数-#include <stdlib.h>-执行系统命令-pause(暂停)
//	return 0;
//}

//2、求两个数的二进制中不同位的个数
//编程实现：两个int(32位)整数m和n的二进制表达中，有多少个位不同？
//如：输入1999 2299，输出7
//方法1：
//分别得到m和n二进制数中的每一位，进行比较，如果不同则count++
//方法2：
//将m和n进行异或操作，所得结果判断每一位如果是1则说明异或前的两个数相同位的二进制数不同，则count++
//int count_bit_one(int n)
//{
//	int count = 0;
//	while(n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int get_diff_bit(int m,int n)
//{
//	int tmp = m ^ n;
//	return count_bit_one(tmp);
//}
//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	int count = get_diff_bit(m, n);
//	printf("count = %d\n", count);
//	return 0;
//}

//3、打印整数二进制的奇数位和偶数位
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//由于打印的是有符号的二进制补码，故需要用右移+按位与操作获取每一位，并输出
//#include <stdio.h>
//void Print(int m)
//{
//	int i = 0;
//	//由于要按二进制的高位到低位依次打印，故倒序循环输出
//  //0-31位
//	printf("奇数位：\n");//i初始化为0，i = 30是奇数位
//	for (i = 30; i >= 0; i -= 2)
//	{//01011001010110010101100101011001
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//	printf("偶数位：\n");//i初始化为0，i = 31是偶数位
//	for (i = 31; i >= 1; i -= 2)
//	{//01011001010110010101100101011001
//		printf("%d ", (m >> i) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	Print(m);
//	return 0;
//}
//注意：算术运算本身不会改变变量中的数值大小，赋值操作才会改变变量中的数值

//4、交换两个变量(不创建临时变量)
//不允许创建临时变量，交换两个整数的内容

//5、使用指针打印数值内容
//写一个函数打印arr数值的内容，不使用数组下标，使用指针。arr是一个整型一维数组。
//#include <stdio.h>
//void Print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr,sz);
//	return 0;
//}

//6、根据下面递归函数：调用函数Fun(2)，返回值是多少：
//int Fun(int n)
//{ 
//	if (n == 5)
//		return 0;
//	else
//		return 2 * Fun(n + 1);
//}
//A.2
//B.4
//C.8
//正确答案D.16
//技巧：画出几个相同的代码，顺序递归，逆序返回

//7、关于递归的描述错误的是：
//A.存在限制条件，当满足这个限制条件的时候，递归便不再继续
//B.每次递归调用之后越来越接近这个限制条件
//正确答案C.递归可以无限递归下去
//D.递归层次太深，会出现栈溢出现象

//8、函数判断素数
//实现一个函数，判断一个数是不是素数
//利用上面实现的函数打印100-200之间的素数


//9、函数判断闰年
//实现函数判断year是不是闰年

//10、交换两个整数
//实现一个函数来交换两个整数的内容

//11、乘法口诀表
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9*9口诀表，输入12，输出12*12的乘法口诀表
//#include <stdio.h>
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-3d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}

//12、打印一个数的每一位
//递归方式实现打印一个整数的每一个

//13、求阶乘
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）

//14、strlen的模拟
//递归和非递归分别实现strlen

//15、字符串逆序（递归实现）
//编写一个函数reverse_string(char* string)
//将参数字符串中的字符反向排列
//不能使用C函数库中的字符串操作函数
//方法1：类似整型数组逆置
//#include <stdio.h>
//#include <string.h>
//void reverse_string(char arr[])//这里char* arr也可以
//{
//	int left = 0;
//	int right = strlen(arr) - 1;//由于是字符串，所有使用strlen函数求字符串长度
//	//如果使用sizeof(arr) / sizeof(arr[0]) = 7(元素个数，'\0'也算元素个数)，需要减2
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//方法2：
//#include <stdio.h>
////模拟求字符串的长度
////1、计数器
////2、递归
////3、指针-指针
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char arr[])
//{
//	int left = 0;
//	int right = my_strlen(arr) - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//方法3：
#include <stdio.h>
//假设为reverse_string("abcdef")
//第一步：a存入tmp中
//第二步：f存入a中
//第三步：'\0'存入f中
//第四步：reverse_string("bcde")
//继续上面类似步骤
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//void reverse_string(char arr[])
//{
//	char tmp = arr[0];
//	int len = my_strlen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (my_strlen(arr + 1) >= 2)//当逆序的字符串长度小于1（即偶数个字符中间字符串长度为0，奇数个字符串中间字符串长度为1），则停止递归
//	{
//		reverse_string(arr + 1);//首元素指向下一个元素的地址
//	}
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//16、计算一个数的每一位之和(递归实现)
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//如：调用DigitSum(1729)，则应该返回1+7+2+9，它们的和是19
//思路：通过递归获取每一位，相加
//DigitSum(1729)
//DigitSum(172) + 1729 % 10
//DigitSum(17) + 172 % 10 + 1792 % 10
//DigitSum(1) + 17 % 10 + 172 % 10 + 1792 % 10
//#include <stdio.h>
//int DigitSum(unsigned int num)
//{
//	if (num > 9)//两位数以上
//	{
//		return DigitSum(num / 10) + num % 10;//通过/10去掉尾数，通过%10获得每一位后，每一位相加
//	}
//	else
//	{
//		return num;
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	int sum = DigitSum(num);
//	printf("sum = %d\n", sum);
//	return 0;
//}

//17、递归实现n的k次方
//编写一个函数实现n的k次方，使用递归实现
//#include <stdio.h>
//double Pow(int n, int k)
//{
//	//n^k
//	//当k = 0时，结果为n^k = 1
//	//当k > 0时，结果为n^k = n * n^(k - 1)
//	//当k < 0时，结果为n^k = 1/n^k
//	if (k < 0)
//	{
//		return (1.0 / (Pow(n, -k)));
//	}
//	else if (k == 0)
//	{
//		return 1.0;
//	}
//	else
//	{
//		return n * Pow(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("ret = %lf\n", ret);
//	return 0;
//}

//18、计算斐波那契数
//递归和非递归分别实现求第n个斐波那契数
//如：输入5，输出5。输入10，输出55