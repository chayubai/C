#define _CRT_SECURE_NO_WARNINGS 1
//处理字符和字符串的库函数（结合MSDN手册学习）
//C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，
//字符串通常放在常量字符串中或者字符数组中。但都有'\0'结束标志。
//字符串常量适用于那些对它不做修改的字符串函数.

//一、求字符串长度strlen
//原理：从字符串/字符数组的首元素找，该字符若不是'\0'，则计数器加一，直到遇到'\0'结束计数('\0'不计入)
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);//6
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	int len = strlen(arr);
//	printf("%d\n", len);//随机值
//	return 0;
//}

//size_t strlen(const char* str);
//字符串以 '\0' 作为结束标志，strlen函数返回的是在字符串中 '\0' 前面出现的字符个数（不包含 '\0' )。
//参数指向的字符串必须要以 '\0' 结束。
//注意函数的返回值为size_t，是无符号的（易错）
//学会strlen函数的模拟实现
//原理：从字符串/字符数组的首元素找，该字符若不是'\0'，则计数器加一，直到遇到'\0'结束计数('\0'不计入)
//1、计数器的方法
//2、递归(不创建临时变量count，求字符串长度)
//3、指针-指针
//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str)//确保str指向的字符串值被修改，使用const修饰*str
//{
//	int count = 0;
//	assert(str != NULL );//传入的指针，确保有效性
//	while (*str != '\0')//while(*str) - *str == '\0'，由于'\0'ASCII为0
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);//6
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)//-3被当作无符号数
//		printf("hehe\n");//hehe
//	else
//		prnitf("haha\n");
//	return 0;
//}
//size_t，选中-转到定义
//库函数设置unsigned，是考虑到str的长度不可能是负数

//二、长度不受限制的字符串函数strcpy、strcat、strcmp
//1、strcpy字符串拷贝函数
//原理：将源字符串的每一个元素包括'\0'都赋值给目的地字符串
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);//将arr2拷贝到arr1中，包括arr2中的'\0'
//	//通过调试发现'\0'被拷贝到arr1中了
//	return 0;
//}

//char* strcpy(char* destination, const char* source);
//Copies the C string pointed by source into the array pointed by destination, including the
//terminating null character(and stopping at that point).
//源字符串必须以 '\0' 结束。即源字符串不能初始化为字符数组，否则可能会导致越界
//会将源字符串中的 '\0' 拷贝到目标空间。
//目标空间必须足够大，以确保能存放源字符串。
//目标空间必须可变。即目的地字符串不能初始化为常量字符串
//学会模拟实现。
//原理：将源字符串的每一个元素包括'\0'都赋值给目的地字符串
//#include <stdio.h>
//#include <assert.h>
////库函数的返回类型是char*，即将目的地起始地址返回
//char* my_strcpy(char* dest, const char* src)//由于源字符串不能被改变，用const修饰
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//将'\0'复制过去
//	char* ret = dest;//防止dest的起始地址被改变
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//返回目的地空间的起始地址
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//2、strcat字符串追加函数
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//char arr1[] = "hello";
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);//将arr2的字符串追加到arr1字符串的后面
//	printf("%s\n",arr1);//报错，目的地空间足够大
//	return 0;
//}

//'\0'是否会被追加到目的地字符串中？
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	
//	char arr1[30] = "hello\0xxxxxxxx";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//调试发现'\0'会被追加到目的地字符串中

//char* strcat(char* destination, const char* source);
//Appends a copy of the source string to the destination string.The terminating null character
//in destination is overwritten by the first character of source, and a null - character is included
//at the end of the new string formed by the concatenation of both in destination.
//源字符串必须以 '\0' 结束。
//目标空间必须有足够的大，能容纳下源字符串的内容。
//目标空间必须可修改，且以'\0'结束。
//字符串自己给自己追加，如何？-- 不能，由于目的地字符串的'\0'被覆盖了，导致寻找'\0'而死循环
//模拟实现strcat函数
//原理：将目的地字符串的'\0'元素地址位置依次追加到后面，直到源字符串的'\0'结束追加('\0'也要追加)
//#include <stdio.h>
//#include <assert.h>
////库函数的返回类型为char*，返回目的地首元素的地址，以便知道目的地空间是否发生了变化
//char* my_strcat(char* dest, const char* src)//由于源字符串不能被改变，用const修饰，防止值被修改
//{
//	char* ret = dest;
//	//assert(dest && src);//NULL == 0
//	assert(dest != NULL);
//	assert(src);
//	//1、找到目的地字符串的'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}	
//	//2、追加，即以'\0'为起始地址拷贝
//	while (*dest++ = *src++)
//		;
//	return ret;
//}
//int main()
//{
//	
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//3、strcmp字符串比较函数
//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "sqwer";
//	//if("abcedf"=="sqwer")//"=="是比较内容的，而字符串表示首元素的地址，由于地址肯定是不一样的
//	int ret = strcmp(p1, p2);
//	//strcmp比较p1、p2所指向的字符串，p1>p2,返回大于0的数字，p1=p2，返回等于0的数字，p1<p2，返回小于0的数字
//	//对于VS - p1>p2,返回1，p1=p2，返回0，p1<p2，返回-1
//	//对于Linux - gcc，上述不成立，但都满足p1>p2,返回大于0的数字，p1=p2，返回等于0的数字，p1<p2，返回小于0的数字
//	//故：
//	//对于以下代码就会有问题，应按照C语言标准设计
//	/*if (strcmp(p1, p2) == 1)
//		printf("p1>p2\n");
//	else if (strcmp(p1, p2) == 0)
//		printf("p1=p2\n");
//	else if (strcmp(p1, p2) == -1)
//		printf("p1<p2\n");*/
//	//strcmp比较的是各个字符的ASCII，如果同位的ASCII相同，则比较下一位对应字符，而不是比较字符串的长度
//	return 0;
//}

//int strcmp ( const char * str1, const char * str2 );
//This function starts comparing the first character of each string.If they are equal to each
//other, it continues with the following pairs until the characters differ or until a terminating
//null - character is reached.
//C标准规定：
//第一个字符串大于第二个字符串，则返回大于0的数字
//第一个字符串等于第二个字符串，则返回0
//第一个字符串小于第二个字符串，则返回小于0的数字
//模拟实现strcmp函数
//原理：比较对应位的字符ASCII，如果同位的字符ASCII相等，依次比较下一位，如果某一位不同，则停止，否则知道比较到各自的'\0'字符为止(\0也会比较)

//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)//str1，str2不允许改变
//{
//	assert(str1 && str2);//保证指针的有效性
//	while (*str1 == *str2)
//	{	
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//Linux下的实现
//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)//str1，str2不允许改变
//{ 
//	assert(str1 && str2);//保证指针的有效性
//	while (*str1 == *str2)
//	{	
//	if (*str1 == '\0')
//		return 0;
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//对于以上长度不受限制的字符串函数，操作时以'\0'作为结束标志，不受长度的限制，但是也可能导致一些问题
//如：strcat，目的地空间不够，导致函数不安全
//#include <stdio.h>
//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "hello bit";
//	//strcpy(arr1, arr2);
//	return 0;
//}

//长度受限制的字符串函数介绍strncpy、strncat、strncmp
//1、strncpy
//char* strncpy(char* destination, const char* source, size_t num);num单位是字节
//which is signaled by a null - character) is found before num characters have been copied,
//destination is padded with zeros until a total of num characters have been written to it.
//拷贝num个字符从源字符串到目标空间。
//如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加\0，直到num个。
//#include <stdio.h>
//int main()
//{
//	//char arr1[10] = "abcdef";
//	//char arr2[] = "hello bit";
//	//strncpy(arr1, arr2, 4);
//	
//	char arr1[10] = "abcdefgh";
//	char arr2[] = "bit";
//	strncpy(arr1, arr2, 6);
//  //通过调试观察结果
//	return 0;
//}
//模拟实现strncpy
//在安装路径下的VC/crt/src中查看

//2、strncat
//char* strncat(char* destination, const char* source, size_t num);num单位是字节
//Appends the first num characters of source to destination, plus a terminating null - character.
//If the length of the C string in source is less than num, only the content up to the terminating
//null - character is copied.
//#include <stdio.h>
//int mian()
//{
//	//char arr1[30] = "hello\0xxxxxxxxxxxxxx";
//	//char arr2[] = "world";
//	//strncat(arr1, arr2, 3);
//	//调试观察结果，发现当追加完后，会在目的地空间主动加上一个\0
//	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 8);
//	//调试观察结果，发现当源字符串追加的字符个数大于源字符串的长度，不会多加\0
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str1[20];
//    char str2[20];
//    strcpy(str1, "To be ");
//    strcpy(str2, "or not to be");
//    strncat(str1, str2, 6);
//    puts(str1);
//    return 0;
//}

//模拟实现strncat
//在安装路径下的VC/crt/src中查看

//3、strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );num单位是字节
//比较前num个字符
//strncmp的返回值设定和strcmp相同
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//    int n;
//    puts("Looking for R2 astromech droids...");
//    for (n = 0; n < 3; n++)
//        if (strncmp(str[n], "R2xx", 2) == 0)
//        {
//            printf("found %s\n", str[n]);
//        }
//    return 0;
//}

//字符串查找strstr、strtok
//1、strstr查找字符串
//char* strstr(const char* str1, const char* str2);
//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
//注意：文档中的NULL表示空指针，NUL/null/'\0'表示'\0'
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* p1 = "abcdefghi";
//	char* p2 = "def";
//	char* ret = strstr(p1, p2);//strstr如果找到了子串，返回的该子串在目的地空间的子串首元素的地址，否则返回NULL空指针
//	if (ret == NULL)
//		printf("子串不存在\n");
//	else
//		printf("%s\n", ret);//返回子串首元素的地址
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = strstr(p1, p2);//返回第一个子串首元素的地址
//	if (ret == NULL)
//		printf("子串不存在\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
//}

//模拟实现strstr
//原理：在目的地空间找到与源字符串首元素相同的字符，否则加加，直到找到，然后源字符串和目的地字符串的地址同时找，
//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);//p2不能为空指针
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur = (char*)p1;//用来记录当前两个字符全匹配成功的字符的地址
//	//判断p2是否为空字符串
//	if (*p2 == '\0')//即if(!*p2)
//		return (char*)p1;//p1是const char*，返回char*否则会报警告
//	while (*cur)
//	{
//		//如：abbcdef bbc
//		s1 = cur;//如果第一次查找失败，第二次从cur的下一个位置重新匹配查找，指针回归
//		s2 = (char*)p2;//指针回归
//		while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//s1字符和s2字符同时找
//		//1、p1提前遇到\0则查找结束，如abc abcdef	2、p2提前遇到\0则查找结束，如abcdeqwer def  
//		{
//			s1++;
//			s2++;
//		}
//		//三个条件其一不满足循环都结束，来到这里
//		if (*s2 == '\0')
//			return cur;//找到子串
//		if (*s1 == '\0')
//			return NULL;
//		cur++;
//	}
//	//当每一次都没找到子串，循环结束
//	return NULL;
//}
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//		printf("子串不存在\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
//了解KMP算法

//2、strtok字符串分割函数
//char * strtok ( char * str, const char * sep );
//sep参数是个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
//strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记下一个字符的指针。
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
//strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。(用static静态变量记住标记的位置)
//strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
//（注：第一个参数：第一次传字符串的首地址，第二次以及之后传NULL）
//如果字符串中不存在更多的标记，则返回 NULL 指针。
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char arr[] = "zpw@bitedu.tech";
//    char* p = "@.";
//    char buf[1024] = { 0 };
//    strcpy(buf, arr);//将数据拷贝一份，处理buf数组的内容
//    //切割buf中的字符串
//    char* ret = strtok(buf, p);//返回一个指向这个标记下一个字符的指针
//    printf("%s\n", ret); 
//
//    ret = strtok(NULL, p);//返回一个指向这个标记下一个字符的指针
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, p);//返回一个指向这个标记下一个字符的指针
//    printf("%s\n", ret);
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char arr[] = "zpw@bitedu.tech";
//    char* p = "@.";
//    char buf[1024] = { 0 };
//    strcpy(buf, arr);//将数据拷贝一份，处理buf数组的内容
//    //切割buf中的字符串
//    char* ret = NULL;//接收strtok函数的返回值
//
//    for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//    {//ret = strtok(arr, p)只会执行一次
//        printf("%s\n", ret);
//    }
//    return 0;
//}
//#include <stdio.h>

//#include <string.h>
//int main()
//{
//    char str[] = "- This, a sample string.";
//    char* pch;
//    printf("Splitting string \"%s\" into tokens:\n", str);
//    pch = strtok(str, " ,.-");
//    while (pch != NULL)
//    {
//        printf("%s\n", pch);
//        pch = strtok(NULL, " ,.-");
//    }
//    return 0;
//}

//错误信息报告strerror：
//char * strerror ( int errnum );
//作用：返回错误码，所对应的错误信息。
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//必须包含的头文件
//int main()
//{
//    //错误码      错误码对应的错误信息
//    //0           No error
//    //1           Operation not permitted
//    //2           No such file or directory
//    //...
//    char* str = strerror(0);
//    printf("%s\n", str);
//
//    char* str = strerror(1);
//    printf("%s\n", str);
//
//    char* str = strerror(2);
//    printf("%s\n", str);
//
//    return 0;
//}

//errno是一个全局的错误码的变量
//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码赋值到变量errno中
//此时通过查看errno变量的信息可知道出问题的原因
//char* str = strerror(errno);
//选择errno转到定义，可以查看错误码
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//必须包含的头文件
//int main()
//{
//    //打开文件fopen("文件名.后缀","r")   r表示读文件。w表示写文件
//    //fopen如果文件存在，返回一个FILE*类型的指针，如果文件不存在，则会返回NULL
//    FILE* pf = fopen("D:/Desktop/考研/考研手册.txt", "r");//fopen的路径是绝对路径，注意文件夹之间的分隔符/
//    if (pf == NULL)
//        printf("%s\n", strerror(errno));
//    else
//        printf("open file success\n");
//    return 0;
//}

//字符操作
//1、字符分类函数：判断字符是否属于该类字符
//函数			如果他的参数符合下列条件就返回真(非0)，条件为假返回0
//iscntrl		任何控制字符
//isspace		空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车‘\r’，制表符'\t'或者垂直制表符'\v'
//isdigit		十进制数字 0~9
//isxdigit		十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
//islower		小写字母a~z
//isupper		大写字母A~Z
//isalpha		字母a~z或A~Z
//isalnum		字母或者数字，a~z, A~Z, 0~9
//ispunct		标点符号，任何不属于数字或者字母的图形字符（可打印）
//isgraph		任何图形字符
//isprint		任何可打印字符，包括图形字符和空白字符
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    char ch = 'w';
//    int ret = islower(ch);
//    printf("%d\n", ret);
//    return 0;
//}

//2、字符转换函数
//int tolower(int c);将字母转小写
//int toupper(int c);将字母转大写
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    char ch = tolower('Q');
//    puchar(ch);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    int i = 0;
//    char arr[] = "I Am A Student";
//    while (arr[i])
//    {
//        if (isupper(arr[i]))
//            arr[i] = tolower(arr[i]);
//        i++;
//    }
//    printf("%s\n", arr);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    int i = 0;
//    char str[] = "Test String.\n";
//    char c;
//    while (str[i])
//    {
//        c = str[i];
//        if (isupper(c))
//            c = tolower(c);
//        putchar(c);
//        i++;
//    }
//    return 0;
//}

//内存操作函数memcpy、memmove、memset、memcmp
//以上函数操作的对象都是字符串，那如何实现不同类型之间的操作呢？
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	//char* dest,const char* src
//	strcpy(arr2, arr1);
//	return 0;
//}
//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//strcpy把字符一个一个的拷贝到目的地空间，故会把01拷贝到arr2中。由于遇到00即'\0'就会结束，故结果为1

//1、memcpy内存拷贝
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//memcpy(arr2, arr1,5*sizeof(int));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S arr1[] = { {"张三",20},{"李四",30} };
//	struct S arr2[3] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct {
//	char name[40];
//	int age;
//} person, person_copy;
//int main()
//{
//	char myname[] = "Pierre de Fermat";
//	/* using memcpy to copy string: */
//	memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 46;
//	/* using memcpy to copy structure: */
//	memcpy(&person_copy, &person, sizeof(person));
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//	return 0;
//}

//void * memcpy ( void * destination, const void * source, size_t num );num的单位字节
//函数参数的设计与strncpy相似
//函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
//这个函数在遇到 '\0' 的时候并不会停下来。
//如果source和destination有任何的重叠，复制的结果都是未定义的。
//模拟实现memcpy
//#include <stdio.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{//void*类型的变量不能解引用操作，不能++操作，不能+/-整数操作
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;//保存dest的起始地址
//	while (num--)
//	{
//		//将源空间的内容按字节一个一个的放入目的地空间，需要放num字节个次数
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//同一优先级，自右向左结合，或者((char*)dest)++
//		++(char*)src;
//		//直接写成*((char*)dest)++ = *((char*)src)++
//	}
//	return ret;//返回dest的起始地址
//}
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	struct S arr3[] = { {"张三",20},{"李四",30} };
//	struct S arr4[3] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	//通过调试观察结果
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;//保存dest的起始地址
//	while (num--)
//	{
//		//将源空间的内容按字节一个一个的放入目的地空间，需要放num字节个次数
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//同一优先级，自右向左结合，或者((char*)dest)++
//		++(char*)src;
//		//直接写成*((char*)dest)++ = *((char*)src)++
//	}
//	return ret;//返回dest的起始地址
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memcpy(arr+2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7 8处
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//结果和预期的不一样，为什么？
//	//1  2  3  4  5  6  7  8  9  10
//	//      1  2  3  4  5			//错误
//	//      1  2  1  2  1
//	//由于1和2放在了3和4中
//	//此时，在将3放入5处就变成了将1放入5处，将4放入6处就变成了将2放入6处，将5放入7处变成将1放入7处
//	return 0;
//}
//如何实现上面的问题呢？--memmove()

//2、memmove
//处理内存重叠的复制问题
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr+2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7 8处
//	//使用memcpy也可以
//	//C语言标准规定：
//	//memcpy，只要处理不重叠的内存拷贝即可
//	//memmove，用于处理重叠内存的拷贝
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str);
//	return 0;
//}

//void * memmove ( void* destination, const void* source, size_t num );
//和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
//如果源空间和目标空间出现重叠，就得使用memmove函数处理。
//模拟实现memmove
//1 2 3 4 5 6 7 8 9 10
//假设要将src源空间的4 5 6 7 8拷贝到目的地dest空间
//如果将4 5 6 7 8拷贝到src源空间的左边时，即dest<src时，从前往后拷贝
//如果将将4 5 6 7 8拷贝到src源空间的右边时，从后往前拷贝
//如果将将4 5 6 7 8拷贝到src源空间的最后端的右边时，从前往后拷贝，或者从后往前拷贝均可
//第一种：
//if(dest<src){前-后}else{后-前}
//第二种：
//if(dest<src || dest>(char*)src+count){前-后}else{后-前}
//#include <stdio.h>
//#include <assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	if (dest < src)
//	{
//		//前 - 后
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//后 - 前
//		//假设：将34567 拷贝到56789
//		//03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00 09 00 00 00 0a 00 00 00
//		//先将07 00 00 00 逆序拷贝到09 00 00 00处
//		//(char*)src + 20 -1即为7的最后一个字节的地址
//		//(char*)dest + 20 -1即为9的最后一个字节的地址
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 20);//将1 2 3 4 5拷贝到3 4 5 6 7 8处
//	
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//3、memcmp
//int memcmp(const void* ptr1,const void* ptr2,size_t num);num单位是字节
//比较从ptr1和ptr2指针开始的num个字节
//返回值和strcmp相同
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 8);//比较前8个字节
//	printf("%d\n", ret);
//	ret = memcmp(arr1, arr2, 9);//比较前9个字节
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char buffer1[] = "DWgaOtP12df0";
//	char buffer2[] = "DWGAOTP12DF0";
//	int n;
//	n = memcmp(buffer1, buffer2, sizeof(buffer1));
//	if (n > 0) 
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	else if (n < 0) 
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	else 
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	return 0;
//}

//4、memset内存设置
//void* memset(void* dest, int c, size_t num);

//#include <stdio.h>
//int main()
//{
//	//char arr[10] = "";
//	//memset(arr, '#', 10);//将arr的前10个字节设置为#
//	//调试观察结果
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);//将arr的前10个字节设置为1
//	//调试观察结果
//	//arr有40个字节
//	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 00 00 00...
//	//前10字节：都设置为了1
//	//arr[0] = 0x01010101;
//	//arr[1] = 0x01010101;
//	//arr[2] = 0x01010000;
//	return 0;
//}

//后言：多学习和了解库函数