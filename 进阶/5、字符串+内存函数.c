#define _CRT_SECURE_NO_WARNINGS 1
//处理字符和字符串的库函数（结合MSDN手册学习）
//如：strlen strcpy strcat strcmp strncpy strncat strncmp strstr strtok strerror memcpy memmove memcmp
//C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，
//字符串通常放在 常量字符串 中或者 字符数组 中。但都有'\0'结束标志。
//注意：字符串常量适用于那些对它不做修改的字符串函数.
/*
#include <stdio.h>
int main() 
{
	char *p1 = "abcdef";//"abcdef"是一个常量字符串，即将字符串的首元素的地址赋值给p1，而不是将字符串放入p1中
	//*p1 = 'W';//因为"abcdef"是常量字符串，是不允许修改的，故如果修改程序会崩溃 ---Linux下报错：Segment fault段错误
	//www.stackoverflow.com
	//segmentfault.com
	printf("%s\n", p1);//打印字符串

	//正确书写：
	const char *p2 = "abcdef";
	//*p2 = 'W';//此时就会报错
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char* str = strcat("abcdef","abc");//注意：字符串常量适用于那些对它不做修改的字符串函数.
	printf("%s\n", str);//程序奔溃了
	return 0;
}
*/

//一、求字符串长度strlen
//原理：从字符串/字符数组的首元素找，该字符若不是'\0'，则计数器加一，直到遇到'\0'结束计数('\0'不计入)
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int len = strlen("abcdef");
	printf("%d\n", len);//6
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//错误示范
	char arr[] = { 'a','b','c','d','e','f' };
	int len = strlen(arr);
	printf("%d\n", len);//随机值
	return 0;
}
*/

//strlen函数：
//size_t strlen(const char* str);
//字符串以 '\0' 作为结束标志，strlen函数返回的是在字符串中 '\0' 前面出现的字符个数（不包含 '\0' )。
//参数指向的字符串必须要以 '\0' 结束。
//注意：函数的返回值为size_t，是无符号的（易错）

//strlen函数的模拟实现
//原理：从字符串/字符数组的首元素找，该字符若不是'\0'，则计数器加一，直到遇到'\0'结束计数('\0'不计入)
//方法1、计数器的方法
//方法2、递归(不创建临时变量count，求字符串长度)
//方法3、指针-指针
/*
//方法1：
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)//确保str指向的字符串值被修改，使用const修饰*str
{
	int count = 0;
	assert(str != NULL );//传入的指针，确保有效性
	while (*str != '\0')//while(*str) - 当*str == '\0'，由于'\0'ASCII为0，循环结束
	{
		count++;
		str++;//这一行可以写在条件中，while(*str++)
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);//6
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//无符号数 - 无符号数 = 无符号数
	if (strlen("abc") - strlen("abcdef") > 0)//-3被当作无符号数
		printf("hehe\n");//hehe
	else
		prnitf("haha\n");
	return 0;
}
*/
//size_t，选中-转到定义  size_t == unsigned int
//strlen库函数返回类型为unsigned int，是考虑到str的长度不可能是负数，但却会带来以上这种问题
//使用自己实现的my_strlen，由于返回类型是int，所以避免了这种问题发生。

//方法2：(不创建临时变量count，求字符串长度)
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("\0")
//1+1+1+0
/*
#include <assert.h>
int my_strlen(const char* str)//str是一个指针变量
{
	assert(str);
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
	//if (*str != '\0')
	//{
	//	str++;
	//	return my_strlen(str) + 1;
	//}
	//else
	//	return 0;
}
//方法3：
int my_strlen(const char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;//这一行不能写在条件了，否则会多执行一次++，后面要--回去
	}
	return end - start;//此时，即'\0'的地址-'\b'的地址
}
*/

//二、长度不受限制的字符串函数strcpy、strcat、strcmp
//1、strcpy字符串拷贝函数
//原理：将源字符串的每一个元素包括'\0'都赋值给目的地字符串
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	strcpy(arr1, arr2);//将arr2拷贝到arr1中，包括arr2中的'\0'
	//通过调试发现'\0'被拷贝到arr1中了
	return 0;
}
*/

//strcpy函数：
//char* strcpy(char* destination, const char* source);
//Copies the C string pointed by source into the array pointed by destination, 
//including the terminating null character(and stopping at that point).
//注意：
//1、源字符串必须以 '\0' 结束。即源字符串不能初始化为字符数组，否则可能会导致越界
//2、会将源字符串中的 '\0' 拷贝到目标空间。
//3、目标空间必须足够大，以确保能存放源字符串。
//4、目标空间必须可变。即目的地字符串不能初始化为常量字符串

//strcpy模拟实现。
//原理：将源字符串的每一个元素包括'\0'都赋值给目的地字符串
/*
#include <stdio.h>
#include <assert.h>
//库函数的返回类型是char*，即将目的地起始地址返回
char* my_strcpy(char* dest, const char* src)//由于源字符串不能被改变，用const修饰
{
	assert(dest != NULL);
	assert(src != NULL);

	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	//*dest = *src;//将'\0'复制过去
	char* ret = dest;//用临时变量保存dest的起始地址，因为dest在运行过程中会发生改变
	while (*dest++ = *src++)
	{
		;
	}
	return ret;//返回目的地空间的起始地址
}
int main()
{
	//错误示范
	//char* arr1 = "abcdefghi";
	char arr1[] = "abcdefghi";
	//错误示范
	//char arr2[] = {'b','i','t'};
	char arr2[] = "bit";//或者char* arr2 = "bit";
	my_strcpy(arr1, arr2);//注意：这里传入的是数组名，即首元素地址，是传址调用
	printf("%s\n", arr1);//注意arr1的地址没有变化，dest的地址变化了，只是一开始都是指向相同的地址。
	return 0;
}
*/

//2、strcat字符串追加函数
//原理：从源字符串的首元素开始，一个个的放到目的字符串'\0'位置，及之后位置
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//错误示范
	//char arr1[] = "hello";
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);//将arr2的字符串追加到arr1字符串的后面
	printf("%s\n",arr1);//报错，因为目的地空间足够大，强行追加导致越界访问
	return 0;
}
*/
//源字符串的'\0'是否会被追加到目的地字符串中？ - 会
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[30] = "hello\0xxxxxxxx";
	char arr2[] = "world";
	strcat(arr1, arr2);//从目的地字符串中的第一个'\0'开始追加
	printf("%s\n", arr1);
	return 0;
}
*/
//调试发现源字符串的'\0'会被追加到目的地字符串中

//strcat函数：
//char* strcat(char* destination, const char* source);
//Appends a copy of the source string to the destination string.
//The terminating null character in destination is overwritten by the first character of source, 
//and a null - character is included at the end of the new string formed by the concatenation of both in destination.
//注意：
//1、源字符串必须以 '\0' 结束。
//2、目标空间必须有足够的大，能容纳下源字符串的内容。
//3、目标空间必须可修改，且以'\0'结束。
//4、字符串自己给自己追加，如何？
//	-- 不能，由于目的字符串和源字符串的首地址指向同一个空间。当目的地字符串的'\0'被覆盖了，导致源地址就会因为找不到'\0'而死循环追加

//模拟实现strcat函数
//原理：将目的地字符串的'\0'元素地址位置依次追加到后面，直到源字符串的'\0'结束追加('\0'也要追加)
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>
//库函数的返回类型为char*，返回目的地首元素的地址，以便知道目的地空间是否发生了变化
char* my_strcat(char* dest, const char* src)//由于源字符串不能被改变，用const修饰，防止*src修改值
{
	char* ret = dest;
	//assert(dest && src);//NULL == 0
	//等价以下两句断言
	assert(dest != NULL);
	assert(src);
	//1、找到目的地字符串的'\0'
	while (*dest != '\0')//while(*dest)，不能合并为while(*dest++)，否则会++一次
	{
		dest++;
	}	
	//2、追加，即以'\0'为起始地址拷贝
	while (*dest++ = *src++)
		;
	//strcpy(dest,src);//以上追加操作可以换成这一行
	return ret;
}
int main()
{
	char arr1[30] = "hello";
	//char arr2[] = "world";
	char* arr2 = "world";
	my_strcat(arr1, arr2);
	//my_strcat(arr1, arr1);//调试发现，在死循环追加，当追加到最后没有空间时就会越界访问，死循环导致来不急报错
	//目的字符串和源字符串的首地址指向同一个空间，修改*dest就会修改*src就与const char*矛盾？这种说法是错误的
	//虽然dest和src指向的是同一个空间，但指向的不是字符串常量，
	//所以即使src被const修饰，但是src的指向是可以改变的，就算通过*dest修改字符串，src指向的字符串可以发生改变，
	//只是不能通过*src直接改变当前的值，即不能*src='x';全过程，没有*src='x';操作，故不会出问题。

	//注意区分：
	//const char *p = "abcdef";//"abcdef"这个字符串的值不能修改
	//char arr[] = "world"; const char *p  = arr;//"world"这个字符串的值可以修改
	printf("%s\n", arr1);
	return 0;
}
*/
//查看库函数的源码：VS安装路径 - VC/crt/src

//3、strcmp字符串比较函数
//原理：strcmp比较的是各个字符的ASCII，如果同位的ASCII相同，则比较下一位对应字符
/*
#include <stdio.h>
int main()
{
	char* p1 = "abcdef";
	char* p2 = "aqwer";
	//if("abcedf"=="aqwer")//两个字符串是用首元素的地址表示，因为两个首元素的地址肯定是不一样的
	int ret = strcmp(p1, p2);
	//strcmp比较p1、p2所指向的字符串，p1>p2,返回大于0的数字，p1=p2，返回等于0的数字，p1<p2，返回小于0的数字
	//对于Windows - VS而言，如果p1>p2,返回1，p1=p2，返回0，p1<p2，返回-1
	//对于Linux - gcc而言，上述不成立，但都满足p1>p2,返回大于0的数字，p1=p2，返回等于0的数字，p1<p2，返回小于0的数字
	//错误示范：对于以下代码在linux下就会有问题
	if (strcmp(p1, p2) == 1)
		printf("p1>p2\n");
	else if (strcmp(p1, p2) == 0)
		printf("p1=p2\n");
	else if (strcmp(p1, p2) == -1)
		printf("p1<p2\n");
	
	//正确示范：应按照C语言标准设计
	if (strcmp(p1, p2) > 0)
		printf("p1>p2\n");
	else if (strcmp(p1, p2) == 0)
		printf("p1=p2\n");
	else if (strcmp(p1, p2) < 0)
		printf("p1<p2\n");	//不是比较字符串的长度
	//故：使用strcmp的返回值判断字符串大小

	return 0;
}
*/

//strcmp函数：
//int strcmp ( const char * str1, const char * str2 );
//This function starts comparing the first character of each string.If they are equal to each other, 
//it continues with the following pairs until the characters differ or until a terminating null - character is reached.
//C标准规定：
//第一个字符串大于第二个字符串，则返回大于0的数字
//第一个字符串等于第二个字符串，则返回0
//第一个字符串小于第二个字符串，则返回小于0的数字

//模拟实现strcmp函数
//原理：比较对应位的字符ASCII，如果同位的字符ASCII相等，依次比较下一位，如果某一位不同，则停止，否则直到比较到各自的'\0'字符为止(\0也会比较)
/*
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)//str1，str2不允许改变
{
	assert(str1 && str2);//保证指针的有效性
	while (*str1 == *str2)
	{	
		//str1:abcdef  str2:abcdef
		if (*str1 == '\0')//如果所有字符都相等，则str1和str2都来到了'\0',比较结束
			return 0;
		str1++;
		str2++;
		//if放在++下面，少循环一次。if放在++上面，多循环一次
		//if((*str1 == '\0') && (*str2 == '\0'))
		//	return 0;
	}
	//来到这里，则有同位上的字符，不相等
	//str1:abcdef  str2:abcd
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}
*/
//Linux下的实现
/*
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)//str1，str2不允许改变
{ 
	assert(str1 && str2);//保证指针的有效性
	while (*str1 == *str2)
	{	
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}
*/
//对于以上长度不受限制的字符串函数，操作时以'\0'作为结束标志，不受长度的限制，但是也可能导致一些问题
//如：strcpy、strcat，目的地空间不够，导致使用函数时候不安全
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[5] = "abc";
	char arr2[] = "hello bit";
	//strcpy(arr1, arr2);//即使空间不足，该函数依旧把"hello bit"全部拷贝到arr1中
	//strcat(arr1, arr2);//即使空间不足，该函数依旧把"hello bit"全部追加到arr1中
	printf("%s\n", arr1);
	return 0;
}
*/

//三、长度受限制的字符串函数介绍strncpy、strncat、strncmp
//1、strncpy
//char* strncpy(char* destination, const char* source, size_t num);拷贝num个字符(字节)从源字符串到目标空间。
//which is signaled by a null - character) is found before num characters have been copied,
//destination is padded with zeros until a total of num characters have been written to it.
//注意：
//1、num单位是字节
//2、如果源字符串的长度大于num，则只拷贝前num个字符，后面不会主动补一个\0
//3、如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加'\0'或0，直到num个。
/*
#include <stdio.h>	
#include <string.h>
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hello bit";
	strncpy(arr1, arr2, 4);//在拷贝完后，后面不会补一个\0
	//通过调试观察结果,arr1的内容变化 - arr1:"hellef\0\0\0\0"

	char arr3[10] = "abcdefgh";
	char arr4[] = "bit";
	strncpy(arr3, arr4, 6);//不够拷贝的字节，用'\0'填充
	//通过调试观察结果,arr1的内容变化 - arr1:"bit\0\0\0gh\0\0"
	return 0;
}
*/

//模拟实现strncpy
//原理：一个字符一个字符的拷贝
//num小于源字符串长度，即如果count提前为0，则结束拷贝；
//num大于源字符串长度，即如果count没有提前为0，则拷贝到源字符串结束后('\0')，再继续将剩余的count个的字符都拷贝为'\0'
#include <stdio.h>	
#include <assert.h>
/*
char* my_strncpy(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	//拷贝3个字节
	//abcdefgh\0
	//bit\0
	//bitdefgh\0
	//拷贝6个字节
	//abcdefgh\0    
	//bit\0
	//bitdefgh\0 
	while (count != 0)//6 5 4 3
	{
		*strDest++ = *strSource++;
		count--;
		if(*strSource == '\0')
			break;
	}
	//count没有提前结束
	//3
	//bit\0\0\0gh\0 
	if (count != 0)
	{
		while (count != 0)//3 2 1 0
		{
			*strDest++ = '\0';
			count--;
		}
	}
	//count提前结束、count没有提前结束而是遇到\0结束
	return ret;
}
*/
/*
char* my_strncpy(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	while (count && (*strDest++ = *strSource++))//短路效果：当count为0直接不进入循环。
			//当count不为0，*strSource=='\0'时，*strDest == '\0'也不进入循环(这里多执行了一次(*strDest++ = *strSource++)，*strDest赋值了一个\0)
	{
		count--;
	}
	if (count)
	{
		//这里是--count，因为上面循环多执行了一次(*strDest++ = *strSource++)，已经赋值了一个‘\0’进去，所以这里要少放一个‘\0’，所以用前置减减
		while (--count)//2 1 0
		{
			*strDest++ = '\0';
		}
	}
	return ret;
}
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hello bit";
	my_strncpy(arr1, arr2, 4);//在拷贝完后，后面不会补一个\0
	//通过调试观察结果,arr1的内容变化 - arr1:"hellef\0\0\0\0"

	char arr3[10] = "abcdefgh";
	char arr4[] = "bit";
	my_strncpy(arr3, arr4, 6);//不够拷贝的字节，用'\0'填充
	//通过调试观察结果,arr1的内容变化 - arr1:"bit\0\0\0gh\0\0"

	//注意：拷贝0个，也适用
	return 0;
}
*/
//查看源码：在安装路径下的VC/crt/src中查看
//注意：strncpy的实现也可以参考memcpy实现。即一个字节一个字节的拷贝

//2、strncat
//char* strncat(char* destination, const char* source, size_t num);从源字符串前num个字符(字节)追加到目标空间。
//Appends the first num characters of source to destination, plus a terminating null - character.
//If the length of the C string in source is less than num, only the content up to the terminatingnull - character is copied.
//注意：
//1、num单位是字节
//2、发现当追加完后，会在目的地空间主动多加上一个\0
//3、发现当源字符串追加的字符个数大于源字符串的长度，将源字符串追加完后，不会多加\0
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
	char arr2[] = "world";
	strncat(arr1, arr2, 3);// - hellowor\0xxxxxxxxxxx
	//调试观察结果，发现当追加完后，会在目的地空间主动多加上一个\0
	char arr3[30] = "hello\0xxxxxxxxxxxxxx";
	char arr4[] = "world";
	strncat(arr3, arr4, 8);// - helloworld\0xxxxxxxxx
	//调试观察结果，发现当源字符串追加的字符个数大于源字符串的长度，不会多加\0
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20];
    char str2[20];
    strcpy(str1, "To be ");
    strcpy(str2, "or not to be");
    strncat(str1, str2, 6);
    puts(str1);//写一个字符串到标准输出流中，会自动换行(接收回车符)。
	//与getchar、putchar对比，详见“提升篇-1、while循环语句”
	//与gets、puts、scanf对比，详见“test11.c”“test12.c”
	//scanf中输入带空格的字符串，详见“test9.c”
	//同时借助MSDN比较
    return 0;
}
*/

//模拟实现strncat
//原理：一个字符一个字符的追加
//num小于源字符串长度，即如果count提前为0，则结束追加，再继续追加一个'\0'；
//num大于源字符串长度，即如果count没有提前为0，则追加到源字符串结束后('\0')，也再继续追加一个'\0'
#include <stdio.h>
#include <assert.h>
/*
char* my_strncat(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	//追加3个字节
	//abcdefgh\0xxxxxxxx\0
	//hello\0
	//abcdefghhel\0xxxxx\0
	//追加8个字节
	//abcdefgh\0xxxxxxxx\0
	//hello\0
	//abcdefghhello\0xxx\0
	char* ret = strDest;
	//找到目的字符串的'\0'
	while (*strDest != '\0')
		strDest++;
	while (count)
	{
		*strDest++ = *strSource++;//下一个字符是\0,但没有赋值给strDest
		count--;
		if (*strSource == '\0')
			break;
	}
	//count提前结束，count没有提前结束而是遇到\0结束
	*strDest = '\0';
	return ret;
}
*/
/*
char* my_strncat(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	//找到目的字符串的'\0'
	while (*strDest++)
		;
	strDest--;//由于while (*strDest++)多加了一次，需要--回去
	//while (count && (*strDest++ = *strSource++))//这里当count不为0时，(*strDest++ = *strSource++)多执行了一次，*strDest赋值了一个\0
	//{
	//	count--;
	//}
	//*strDest = '\0';//这里又多执行了一次，因此最后会出现两个\0

	while (count--)
	{
		if (!(*strDest++ = *strSource++))//这里有多执行了一次
			return ret;
	}
	*strDest = '\0';
	return ret;
}
int main()
{
	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
	char arr2[] = "world";
	my_strncat(arr1, arr2, 3);// - hellowor\0xxxxxxxxxxx
	//调试观察结果，发现当追加完后，会在目的地空间主动多加上一个\0
	char arr3[30] = "hello\0xxxxxxxxxxxxxx";
	char arr4[] = "world";
	my_strncat(arr3, arr4, 8);// - helloworld\0xxxxxxxxx
	//调试观察结果，发现当源字符串追加的字符个数大于源字符串的长度，不会多加\0

	//注意：追加0个，也适用
	return 0;
}
*/
//查看源码：在安装路径下的VC/crt/src中查看

//3、strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );比较前num个字符(字节)
//注意：
//1、num单位是字节
//2、strncmp的返回值设定和strcmp相同
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	int ret = strncmp(arr1, arr2, 3);
	printf("%d\n", ret);

	char arr3[] = "abcdef";
	char arr4[] = "abcdef";

	ret = strncmp(arr3, arr4, 8);
	printf("%d\n", ret);

	char arr5[] = "abcd";
	char arr6[] = "abcdef";

	ret = strncmp(arr5, arr6, 8);
	printf("%d\n", ret);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts("以R2开头的字符串...");//自动换行
    for (n = 0; n < 3; n++)
        if (strncmp(str[n], "R2xx", 2) == 0)
        {
            printf("found %s\n", str[n]);
        }
    return 0;
}
*/

//模拟实现strncmp
//原理：一个字符一个字符的比较
//num小于源字符串长度，即如果count提前为0，则结束比较；
//num大于源字符串长度，即如果count没有提前为0，则比较到源字符串结束后('\0')，则结束比较
#include <stdio.h>
#include <assert.h>
/*
int my_strncmp(const char* string1, const char* string2, int count)
{
	//比较3个字符
	//abcdef\0
	//abcabc\0
	//返回0
	//比较8个字符
	//abcdef\0
	//abcabc\0
	//返回d-a
	//abcdef\0
	//abcdef\0
	//返回0
	assert(string1 && string2);
	while (count != 0)
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
			count--;
			if (*string2 == '\0')
				break;
		}
		else
		{
			return *string1 - *string2;
		}
	}
	
	//count没有提前结束
	if (count != 0)
	{
		if (*string1 != *string2)
		{
			return *string1 - *string2;
		}
	}

	//count提前结束了，count没有提前结束而是遇到\0结束
	return 0;
}
*/
/*
int my_strncmp(const char* string1, const char* string2, int count)
{
	assert(string1 && string2);
	if (count == 0)
		return 0;
	//while (count && *string1 == *string2)//短路效果
	//{
	//	string1++;
	//	string2++;
	//	count--;
	//	if (*string2 == '\0')
	//		break;
	//}
	while (--count && *string1 && *string1 == *string2)//短路效果
	{
		string1++;
		string2++;
	}
	//count提前结束了，count没有提前结束而是遇到\0结束
	return *string1 - *string2;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	int ret = my_strncmp(arr1, arr2, 3);
	printf("%d\n", ret);

	char arr3[] = "abcdef";
	char arr4[] = "abcdef";

	ret = my_strncmp(arr3, arr4, 8);
	printf("%d\n", ret);

	char arr5[] = "abcd";
	char arr6[] = "abcdef";

	ret = my_strncmp(arr5, arr6, 8);
	printf("%d\n", ret);

	//注意：比较0个，也适用
	return 0;
}
*/

//四、字符串查找strstr、strtok
//1、strstr查找字符串
//char* strstr(const char* str1, const char* str2);
//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
//注意：文档中的NULL表示空指针，而NUL、null、'\0'表示'\0'
//1、从str1串中，查找子串str2
//2、返回查找到的第一个子串首元素的地址
//3、如果str2为空串，则返回str1的首元素地址
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char* p1 = "abcdef";
	char* p2 = "def";
	char* ret = strstr(p1, p2);//返回子串首元素的地址
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);//def

	char* p3 = "abcdefghi";
	char* p4 = "def";
	ret = strstr(p3, p4);//strstr如果找到了子串，返回的该子串在目的地空间的子串首元素的地址，否则返回NULL空指针
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);//defghi - 返回子串首元素的地址，从首地址开始，直到\0结束

	char* p5 = "abcdefabcdef";
	char* p6 = "def";
	ret = strstr(p5, p6);//返回第一个子串首元素的地址
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);//defabcdef

	char* p7 = "abcdefabcdef";
	char* p8 = "";
	ret = strstr(p7, p8);//返回第一个子串首元素的地址
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("[%s]\n", ret);//[abcdefabcdef]
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = strstr(str, "simple");
	if(pch != NULL)//指针使用前，要判断有效性
		strncpy(pch, "sample", 6);
	puts(str);
	return 0;
}
*/

//模拟实现strstr
//原理：在目的地空间找到与源字符串首元素相同的字符，若不相同，则目的地指针++，直到找到，然后源字符串和目的地字符串的地址同时找，
//1、str1提前遇到\0，str1查找完了，则查找结束，没找到。如abc abcdef	
//2、str2提前遇到\0，str2匹配完了，则查找结束，找到了。如abcdef def 
//3、str1和str2不相等，匹配结束，说明以d开始的地址，没有查找到子串，从d/b下一个地址处，开始进行下一轮查找。如abcdeqwer def、 abbbcdef bbc
#include <stdio.h>
#include <assert.h>
/*
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);//p1不能为空指针
	assert(p2 != NULL);//p2不能为空指针
	char* s1 = NULL;//用于记录p1的变化，回归指针到cur(可以直接使用p1，因为cur记录了p1)
	char* s2 = NULL;//用于记录p2的变化，防止p2发生变化，否则无法回归指针到p2
	char* cur = (char*)p1;//用来记录目的地字符串中，两个字符第一次匹配成功的字符地址
	//判断p2是否为空字符串，空串只有一个\0
	if (*p2 == '\0')//即if(!*p2)
		return (char*)p1;//p1是const char*，返回char*，进行强转否则会报警告
	//abcdef  def
	while (*cur)//p1不能是空串，否则无法从p1中查找p2子串
	{
		//如：abbbcdef bbc
		s1 = cur;//如果第一次查找失败，第二次从cur的下一个位置重新匹配查找，p1指针回归到cur的下一个位置(cur++)
		s2 = (char*)p2;//p2指针回归到起始位置
		while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//s1字符和s2字符同时找，短路效果：当count为0直接不进入循环。
		//1、p1提前遇到\0，p1查找完了，则查找结束，没找到。如abc abcdef	
		//2、p2提前遇到\0，p2匹配完了，则查找结束，找到了。如abcdef def 
		//3、p1和p2不相等，匹配结束，说明以d开始的地址，没有查找到子串，从d/b下一个地址处，开始进行下一轮查找。如abcdeqwer def、 abbbcdef bbc
		{
			s1++;
			s2++;
		}
		//三个条件其一不满足循环都结束，来到这里
		if (*s2 == '\0')//如：abc abc、abcd abc
			return cur;//找到子串
		//如：abcdef  gi
		//当每一次都没找到子串，目的字符串遇到\0，没有找到。或者提前遇到\0
		if (*s1 == '\0')//这两个判断顺序不能反，如：abc abc
			return NULL;
		
		//p1和p2不相等，++，直到相等，cur保存的是首个相同字符的地址
		cur++;
	}
	//p1为空串
	return NULL;
}
*/
/*
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* s1 = NULL,* s2 = NULL;
	char* cur = (char*)str1;
	if (!*str2)//*str2 == '\0'为真。*str2为0，!*str2为真
		return (char*)str1;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2))//*s1 != '\0'为真。*s1不为0，*s1为真
		{//*s1 == *s2为真。*s1 - *s2为0，!(*s1 - *s2)为真
			s1++;
			s2++;
		}
		if (!*s2)
			return cur;

		//if (*s1 == '\0')
		//	return NULL;
		//这两行可以不要，只是加上可以提前终止循环，否则会多进行几次无效循环
		cur++;
	}
	return NULL;
}
int main()
{
	//注意p1为空串，则返回NULL
	char* p1 = "abcdefabcdef";
	//char* p2 = "";//p2为空串
	char* p2 = "def";
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);

	char* p3 = "abbbcdef";
	char* p4 = "bbc";
	ret = my_strstr(p3, p4);
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);//注意：打印字符串，打印的是从起始地址开始，直到第一个\0结束的所有字符
	return 0;
}
*/
//了解KMP算法  - 数据结构(C语言版)清华大学-P80

//2、strtok字符串分割函数
//char * strtok ( char * str, const char * sep );
//注意：
//1、第二个参数sep是字符串的起始地址，指向的字符串定义了用作分隔符的字符集合
//2、第一个参数str指定一个字符串的起始地址，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
//strtok函数的用法：
//如：str: "zpw@bitedu.tech"    sep: "@."
//第一次调用strtok函数时，从"zpw@bitedu.tech"中找'@'，然后用\0将其替代后，(同时记住标记的位置)，返回指向这个标记的起始地址的指针"zpw"
//第二次调用strtok函数时，从"bitedu.tech"中找'.'，然后用\0将其替代后，(同时记住标记的位置),返回指向这个标记的起始地址的指针"bitedu"
//第三次调用strtok函数时，从"tech"中找'.'，然后用\0将其替代后，(同时记住标记的位置),返回指向这个标记的起始地址的指针"tech"
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分字符串时，一般复制一份临时拷贝的内容，再其上对齐进行修改。）
//3、strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存标记在字符串中的位置。(用static静态变量记住标记的位置)
//即：第一次调用strtok函数时，第一个参数传入的是str(非空)
//4、strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
//即：第二次及之后调用strtok函数时，第一个参数传入的是NULL
//（注：第一个参数：第一次传字符串的首地址，第二次以及之后传NULL）
//5、如果字符串中不存在更多的标记，则返回 NULL 指针。
//即：当所有的标记都找到后，再调用strtok函数，会返回NULL
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = "2946053797@qq.com";
    char* p = "@.";
    char buf[1024] = { 0 };
    strcpy(buf, arr);//将数据拷贝一份，处理buf数组的内容

    //切割buf中的字符串
    char* ret = strtok(buf, p);
    printf("%s\n", ret); //2946053797

    ret = strtok(NULL, p);
    printf("%s\n", ret);//qq

    ret = strtok(NULL, p);
    printf("%s\n", ret);//com

	ret = strtok(NULL, p);
	printf("%s\n", ret);//null
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = "192.168.33.128";
	//char arr[] = "123@123.@123";//[123] [123] [123],没有[]
    char* p = ".";
    char buf[1024] = { 0 };
    strcpy(buf, arr);//将数据拷贝一份，处理buf数组的内容
    //切割buf中的字符串
    char* ret = NULL;//接收strtok函数的返回值

    for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
    {//ret = strtok(buf, p)只会执行一次
        printf("%s\n", ret);
    }
	//思考一下：第二次及以后调用strtok函数，是如何知道切割谁
	//函数内部会记录标记的位置的指针，且该指针是有“记忆”功能，即static指针变量
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "- This, a sample string.";
    char* pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok(str, ",.- ");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, ",.- ");
    }
    return 0;
}
*/

//五、错误信息报告函数strerror：
//char * strerror ( int errnum );
//errnum错误码
//作用：返回错误码所对应的错误信息。
//注意：
//所在头文件 #include <errno.h>
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>//必须包含的头文件
int main()
{
    //错误码      错误码对应的错误信息
    //0           No error
    //1           Operation not permitted
    //2           No such file or directory
    //...
    char* str = strerror(0);
    printf("%s\n", str);

    char* str = strerror(1);
    printf("%s\n", str);

    char* str = strerror(2);
    printf("%s\n", str);

    return 0;
}
*/

//strerror的使用场景：
//用于调用函数时，返回的结果可能并不是我们希望的，这个时候打印该errno对应的信息，查看错误原因。
/*	 char* str = strerror(errno);	*/
//errno是一个全局的错误码的变量
//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值到变量errno中，此时, 通过查看errno变量的信息可知道出问题的原因
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>//必须包含的头文件
int main()
{
    //打开文件fopen("文件名.后缀","r")   r表示读文件  w表示写文件。这样写，则默认从当前项目所在路径下找该文件
    //fopen，如果文件存在，返回一个FILE*类型的指针，如果文件不存在，则返回NULL
    FILE* pf = fopen("test.txt", "r");//fopen的路径是相对路径
	//FILE* pf = fopen("D:\\VS2019\\code\\提升\\3、函数\\3、函数\\test12.txt", "r");//fopen的路径是绝对路径，注意文件夹之间的分隔符\，转义\\
	//FILE* pf = fopen("D:\\VS2019\\code\\提升\\3、函数\\3、函数\\test12.txt", "r");
	//FILE* pf = fopen("D:/VS2019/code/提升/3、函数/3、函数/test12.txt", "r");//fopen的路径是绝对路径，注意文件夹之间的分隔符/，不需要转义
	if (pf == NULL)
        printf("open file filed: %s\n", strerror(errno));//当文件打开失败后(发生了错误)，就会把对应的错误码赋值到变量errno中
	//注意：选中errno转到定义，可以查看错误码
    else
        printf("open file success\n");
    return 0;
}
*/

//六、字符操作
//注意：
//以下函数所在头文件 #include <errno.h>
//1、字符分类函数：判断字符是否属于该类字符
/********************************************************************************************
	函数			如果他的参数符合下列条件就返回真(非0)，条件为假返回0
	iscntrl			任何控制字符
	isspace			空白字符：空格' '，换页'\f'，换行'\n'，回车'\r'，制表符'\t'或者垂直制表符'\v'
	isdigit			十进制数字 0~9
	isxdigit		十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
	islower			小写字母a~z
	isupper			大写字母A~Z
	isalpha			字母a~z或A~Z
	isalnum			字母或者数字，a~z, A~Z, 0~9
	ispunct			标点符号，任何不属于数字或者字母的图形字符（可打印）
	isgraph			任何图形字符
	isprint			任何可打印字符，包括图形字符和空白字符
**********************************************************************************************/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch = 'w';
    int ret = islower(ch);
    printf("%d\n", ret);
    return 0;
}
*/

//2、字符转换函数
//int tolower(int c);将字母转小写
//int toupper(int c);将字母转大写
//注意：小写转大写 -32 大写转小写 +32
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch = tolower('Q');
    putchar(ch);//输出一个字符
    return 0;
}
*/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char arr[] = "I Am A Student";
	for (int i = 0; i < strlen(arr); i++)
	{
		if (islower(arr[i]))//判断小写字母
			arr[i] = toupper(arr[i]);
	}
	printf("%s\n", arr);
	
	while (arr[i])
	{
		if (isupper(arr[i]))
			arr[i] = tolower(arr[i]);
		i++;
	}
    printf("%s\n", arr);
    return 0;
}
*/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char str[] = "Test String.\n";
    char c;
    while (str[i])
    {
        c = str[i];
        if (isupper(c))
            c = tolower(c);
        putchar(c);
        i++;
    }
    return 0;
}
*/

//七、内存操作函数memcpy、memmove、memset、memcmp
//上面学过的strlen、strcpy...等函数操作的对象都是字符串，那如何实现不同类型之间的操作呢？
//此时，就需要使用到内存操作函数。由于可以操作任意类型的数据，所以函数形参的类型设置为void*
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	//char* dest,const char* src
	strcpy(arr2, arr1);//报警告，类型不兼容，因为整型数组的类型是int[5]
	//调试观察arr1 arr2的变化
	return 0;
}
*/
//arr1数组元素在内存中的局部：
//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//strcpy把字符一个一个的拷贝到目的地空间，故会把01拷贝到arr2中。由于遇到00即'\0'，把\0拷贝到arr2后，就会结束，故结果为1
//注意：字符操作函数和内存操作函数的区别：结束的条件不同
//1、字符操作函数，是一个字节一个字节的操作，但遇到'\0'或0，停止操作
//2、内存操作函数，是一个字节一个字节的操作，当操作完num个字节后，停止操作

//1、memcpy内存拷贝
//原理：将num个字节，一个字节一个字节的从source拷贝到destination中。拷贝完num个字节，然后停止拷贝
/*
//拷贝普通数据类型
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));//等价memcpy(arr2, arr1,5*sizeof(int));或memcpy(arr2, arr1, 25);
	//调试观察arr1 arr2的变化
	return 0;
}
int main()
{
	char arr1[] = "abcd";
	char arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));//等价memcpy(arr2, arr1,strlen(arr1)+1);把\0也拷贝进去
	//调试观察arr1 arr2的变化

	char arr3[] = { 'a','b','c','d' };
	char arr4[5] = { 0 };
	memcpy(arr4, arr3, 3);//只拷贝3个字节
	//调试观察arr3 arr4的变化
	return 0;
}
*/
/*
//拷贝自定义数据类型
#include <stdio.h>
#include <string.h>
struct S
{
	char name[20];
	int age;
};
int main()
{
	struct S arr1[] = { {"张三",20},{"李四",30} };
	struct S arr2[3] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	//调试观察arr1 arr2的变化
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
struct {
	char name[40];
	int age;
} person, person_copy;
int main()
{
	char myname[] = "Pierre de Fermat";
	// using memcpy to copy string: 
	memcpy(person.name, myname, strlen(myname) + 1);//把\0也拷贝进去
	person.age = 46;
	// using memcpy to copy structure: 
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	return 0;
}
*/

//memcpy函数：
//void * memcpy ( void * destination, const void * source, size_t num );将source的num个字节拷贝到destination中
//注意：
//1、num的单位字节
//2、函数参数的设计与strncpy相似
//3、函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
//4、这个函数在遇到 '\0' 的时候并不会停下来。
//5、如果source和destination有任何的重叠，复制的结果都是未定义的。

//模拟实现memcpy
//原理：将num个字节，一个字节一个字节的从source拷贝到destination中。拷贝完num个字节，然后停止拷贝
/*
#include <stdio.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{//void*类型的变量不能解引用操作，不能++操作，不能+/-整数操作
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//保存dest的起始地址
	while (num--)
	{
		//将源空间的内容按字节一个一个的放入目的地空间，需要放num字节个次数
		*(char*)dest = *(char*)src;//强转为char*, 可以实现一个字节一个字节的拷贝
		++(char*)dest;//同一优先级，自右向左结合，或者((char*)dest)++
		++(char*)src;
		//以上代码可以直接写成*((char*)dest)++ = *((char*)src)++
	}
	return ret;//返回dest的起始地址
}
struct S
{
	char name[20];
	int age;
};
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	struct S arr3[] = { {"张三",20},{"李四",30} };
	struct S arr4[3] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	//通过调试观察结果
	return 0;
}
*/

//思考题：
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//使用my_memcpy函数将1 2 3 4 5拷贝到3 4 5 6 7处
/*
#include <stdio.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//保存dest的起始地址，如果用char* ret接收，下面dest就可以不需要强转
	while (num--)
	{
		//将源空间的内容按字节一个一个的放入目的地空间，需要放num字节个次数
		*(char*)dest = *(char*)src;
		++(char*)dest;//同一优先级，自右向左结合，或者((char*)dest)++
		++(char*)src;
		//直接写成*((char*)dest)++ = *((char*)src)++
	}
	return ret;//返回dest的起始地址
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memcpy(arr+2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7处
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	//结果和预期的不一样，为什么？
	//1  2  3  4  5  6  7  8  9  10
	//      1  2  3  4  5			//错误
	//      1  2  1  2  1
	//由于1和2放在了3和4中
	//此时，在将3拷贝放入5处就变成了将1放入5处，将4放入6处就变成了将2放入6处，将5放入7处变成将1放入7处
	return 0;
}
*/
//如何将1 2 3 4 5拷贝到3 4 5 6 7 ？？？
//1、从后往前拷贝
//1  2  3  4  5  6  7  8  9  10
//      1  2  3  4  5
//5拷贝到7上，4拷贝到6上，3拷贝到5上，2拷贝到4上，1拷贝到3上
//如何将3 4 5 6 7拷贝到1 2 3 4 5 ？？？
//2、从前往后拷贝
//1  2  3  4  5  6  7  8  9  10
//3  4  5  6  1
//因此针对不同的拷贝，要求不同的拷贝顺序，这就是memmove()的作用

//2、memmove内存移动
//作用：处理内存重叠的复制问题
//原理：将num个字节，一个字节一个字节的从source拷贝到destination中。拷贝完num个字节，然后停止拷贝
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memmove(arr+2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7处
	memcpy(arr+2, arr, 20);
	//使用标准的memcpy也可以做到
	//C语言标准规定：
	//memcpy函数的功能，只要处理不重叠的内存拷贝就可以。当前VS编译器的memcpy功能更强大，但不一定满足所有的平台
	//memmove函数的功能，用于处理重叠内存的拷贝
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}
*/

//memmove函数：
//void * memmove ( void* destination, const void* source, size_t num );将source的num个字节拷贝到destination中
//注意：
//1、num单位是字节
//2、和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
//3、如果源空间和目标空间出现重叠，就得使用memmove函数处理。

//模拟实现memmove
//原理：将num个字节，一个字节一个字节的从source拷贝到destination中。拷贝完num个字节，然后停止拷贝
//1、当dest < src时，src中的数据应该从最前一个数据开始往后依次拷贝到dest中
//2、当src < dest < src+num时，src中的数据应该从最后数据开始往前依次拷贝到dest中
//3、当dest > src时，即不重叠拷贝，src中的数据拷贝到dest中可以从前往后，也可以从后往前
//假设：要将src源空间的4 5 6 7 8拷贝到目的地dest空间
//1 2 3 4 5 6 7 8 9 10
//如果将4 5 6 7 8拷贝到src源空间的左边时，即dest<src时，从4开始往后依次拷贝
//如果将将4 5 6 7 8拷贝到src源空间的右边时，从8开始往前依次拷贝
//如果将将4 5 6 7 8拷贝到src源空间的最后端的右边时，从前往后拷贝，或者从后往前拷贝均可
//第一种：将1作为一种情况，2，3合并
//if(dest<src){前-后}else{后-前}
//第二种：将2作为一种情况，1，3合并
//if(dest<src || dest>(char*)src+count){前-后}else{后-前}
//注意：边界值可以放在任意一种情况里面。
/*
#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;
	if (dest < src)//void*类型比较的时候，不会报警告
	{
		//前 - 后
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//后 - 前
		//假设：将34567 拷贝到56789
		//03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00 09 00 00 00 0a 00 00 00
		//先将07 00 00 00 逆序拷贝到09 00 00 00处：
		//一个字节一个字节的拷贝，则从7的最后一个字节00开始，拷贝到9的最后一个字节00处
		//(char*)src + 20 -1即为7的最后一个字节00的地址
		//(char*)dest + 20 -1即为9的最后一个字节00的地址
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);//while(count){ *((char*)dest + count-1) = *((char*)src + count-1); count--; }
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7 8处
	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//3、memcmp内存比较
//int memcmp(const void* ptr1,const void* ptr2,size_t num);将source的num个字节与destination比较
//原理：将num个字节，一个字节一个字节的从source与destination中。比较完num个字节，然后停止比较
//注意：
//1、num单位是字节
//2、比较从ptr1和ptr2指针开始的num个字节
//3、返回值的设定和strcmp相同
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	//arr1和arr2在内存中的布局
	//arr1：01 00 00 00 02 00 00 00 ...
	//arr2：01 00 00 00 02 00 00 00 ...
	int ret = memcmp(arr1, arr2, 8);//比较前8个字节
	printf("%d\n", ret);

	//arr1和arr2在内存中的布局
	//arr1：01 00 00 00 02 00 00 00 03 00 00 00 ...
	//arr2：01 00 00 00 02 00 00 00 05 00 00 00 ...
	ret = memcmp(arr1, arr2, 9);//比较前9个字节
	printf("%d\n", ret);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n > 0) 
		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n < 0) 
		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else 
		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int size = sz;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (1)
	{
		printf("请输入要删除的数：");
		scanf("%d", &num);//2

		int i = 0;
		for (i = 0; i < size - 1; i++)//arr[i+1]  i==9越界
		{
			if (arr[i] == num)//i == 2是第三个元素  *(arr+i) == arr[i] 
			{
				memmove(arr + i, arr + i + 1, (size - i - 1) * sizeof(int));//10 - 2 - 1
				size--;
				break;
			}
		}

		if (i == size - 1)//如果是最后一个元素
		{
			if (arr[i] != num)//没找到
			{
				printf("要删除的数不存在\n");
				continue;
			}
			//找到了
			size--;
		}
		for (int i = 0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
*/

//4、memset内存设置
//void* memset(void* dest, int c, size_t num);
//The memset function sets the first count bytes of dest to the character c.设置dest前num个字节为字符c
//参数dest：Pointer to destination要设置的指向目的地址的指针
//参数c：Character to set要设置的字符
//返回值：memset returns the value of dest.返回设置后的目的地址
//作用：初始化变量
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[10] = "";//所有的元素初始化为0(\0)
	memset(arr1, '#', 10);//将arr的前10个字节设置为#
	//调试观察arr1

	int arr2[10] = { 0 };//所有的元素初始化为1.int arr2[10] = { 1 };只会将第一元素初始化为1，剩余元素都为0
	//数组元素类型为int默认初始化为0，double默认初始化为0.00000000，char默认初始化为'\0'
	memset(arr2, 1, 10);//将arr的前10个字节设置为1
	//调试观察arr2
	//arr2有40个字节，arr2在内存中的布局
	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 00 00 00...
	//前10字节：都设置为了1
	//arr[0] = 0x01010101 == 16843009
	//arr[1] = 0x01010101 == 16843009
	//arr[2] = 0x01010000 == 257
	return 0;
}
*/
//后言：多学习和了解库函数
//https://cplusplus.com/reference/clibrary/

//作业
//1、模拟实现strstr
//2、模拟实现memcpy
//3、模拟实现memmove
//4、课堂代码练习与本主题博客(课堂代码的编写、涉及到的核心知识点整理、以博客链接方式)