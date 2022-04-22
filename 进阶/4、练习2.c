#define _CRT_SECURE_NO_WARNINGS 1
//作业：
//1、下列程序段的输出结果为：
//#include <stdio.h>
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//	//	6		7		8		9		10
//	//	|pulPtr					|pulPtr + 3
//	//*(pulPtr + 3) = 9
//	//假设*(pulPtr + 3) = y，即y += 3;y = 12 
//	return 0;
//}
//A.9,12
//B.6,9
//正确答案C.6,12
//D.6,10

//2、关于二级指针描述正确的是：
//A.二级指针也是指针，只不过比一级指针更大
//正确答案B.二级指针也是指针，是用来保存一级指针的地址
//C.二级指针是用来存放数组的地址
//D.二级指针的大小是4个字节

//3、下面关于指针运算说法正确的是：
//A.整型指针+1，向后偏移一个字节
//B.指针-指针得到的是指针和指针之间的字节个数（应该为元素个数）
//正确答案C.整型指针解引用操作访问4个字节
//D.指针不能比较大小

//4、下面哪个是指针数组：
//正确答案A.int* arr[10];
//B.int* arr[];
//C.int** arr;
//D.int (*arr)[10];//数组指针

//5、字符串逆序
//写一个函数，可以逆序一个字符串的内容
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	scanf("%s", arr);//不能有空格，否则遇到空格不在读取后面的字符
//	reverse(arr);
//	printf("%s\n", arr);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);
//	gets(arr);//读取一行，MSDN查看gets的使用，将数据放入buffer，后读取一行
//	reverse(arr);
//	printf("%s\n", arr);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//void reverse(char arr[]) //adcdf\0
//{
//	assert(arr);
//	int len = strlen(arr);
//	char left = 0;
//	char right = len - 1;
//	while (left < right)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);
//	gets(arr);//读取一行，MSDN查看gets的使用，将数据放入buffer，后读取一行
//	reverse(arr);
//	printf("%s\n", arr);
//
//	return 0;
//}

//6、计算求和
//求Sn = a+aa+aaa+aaaa+aaaaa的前5项之和，其中a的是一个数字
//例如：2+22+222+2222+22222
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int sum = 0;
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		//2
//		//2 + 22
//		//2 + 22 + 222
//		//2 + 22 + 222 + 2222
//		//2 + 22 + 222 + 2222 +22222
//		//后一项 = 前一项a * 10 + a
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//7、打印水仙花数
//求出0-100000之间的所有“水仙花数”并输出
//“水仙花数”是指一个n位数，其各位数字的n次方之和恰好等于该数本身
//如：153 = 1^3 + 5^3 + 3^3，则153是一个“水仙花数”
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断i是否为水仙花数（自幂数）
//		//1、计算i的位数 - n位数
//		int n = 1;
//		//123/10，n++
//		//12/10，n++
//		//1/10
//		int tmp = i;
//		while (tmp /= 10)//这里tmp不能直接用i，否则改变了i的值
//		{
//			n++;
//			//i /= 10;
//			//这里的循环条件：i/10,可以和i /= 10;合并，故为tmp /= 10
//		}
//		//2、计算i,得到的每一位，并求每一位的n次方之和 - sum
//		//123%10 = 3，3^n
//		//123/10 = 12
//		//12%10 = 2，2^n
//		//12/10 = 1
//		//1%10 = 0，1^n
//		int sum = 0;
//		tmp = i;//重新置tmp为i
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);//次方函数，返回一个double型的数，可以强制类型转换
//			tmp /= 10;
//		}
//		//3、比较i与和sum的大小
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//8、打印菱形
//用C语言在屏幕上输出以下图案
//n是要打印的行数，假设为7
//                       n-1-i    i=0     2*i+1     
//                      空格个数           *个数 
//          &&&&&&*          6 - 第一行0 - 1
//          &&&&&***         5 - 第二行1 - 3
//          &&&&*****        4 - 第三行2 - 5
//          &&&*******       3 - 第四行3 - 7
//          &&*********      2 - 第五行4 - 9
//          &***********     1 - 第六行5 - 11
//          *************    0 - 第七行6 - 13
//          &***********     1 - 第一行0 - 11 = 2*6-1
//          &&*********      2 - 第二行1 - 9  = 2*5-1
//          &&&*******       3 - 第三行2 - 7  = 2*4-1
//          &&&&*****        4 - 第四行3 - 5  = 2*3-1
//          &&&&&***         5 - 第五行4 - 3  = 2*2-1
//          &&&&&&*          6 - 第六行5 - 1  = 2*1-1
//                           i    i=0      2*(n-1-i)-1
//#include <stdio.h> 
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//打印上半部分，七行
//	int i = 0;
//	for (i = 0; i < line; i++)//外层控制行
//	{
//		int j = 0;
//		//1、打印空格
//		for (j = 0; j < line - 1 - i; j++)//控制每一行的空格数
//		{
//			printf(" ");
//		}
//		//2、打印星号
//		for (j = 0; j < 2 * i + 1; j++)//控制每一行的星号数
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//打印下半部分，六行
//	for (i = 0; i <= line - 1; i++)//外层控制行
//	{
//		int j = 0;
//		//1、打印空格
//		for (j = 0; j <= i; j++)//控制每一行的空格数
//		{
//			printf(" ");
//		}
//		//2、打印星号
//		for (j = 1; j <= 2 * (line - 1 - i) - 1; j++)//控制每一行的星号数
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//1、如有以下代码：
//struct student
//{
//	int num;
//	char name[32];
//	float score;
//}stu;
//则下面的叙述不正确的是：
//A.struct是结构体类型的关键字
//B.struct student 是用户定义的结构体类型
//C.num，score都是结构体成员名
//正确答案D.stu是用户定义的结构体类型名

//2、下面程序要求输出结构体成员a的数据，以下不能填入横线处的内容是：
//#include <stdio.h>
//struct S
//{
//	int a;
//	int b;
//};
//int main()
//{
//	struct S a, *p = &a;
//	a.a = 99;
//	printf("%d\n", ______);
//	return 0;
//}
//A.a.a
//正确答案B.*p.a//.的优先级高
//C.p->a
//D.(*p).a

//3、下面程序的输出结果是：
//#include <stdio.h>
//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//void fun(struct stu* p)
//{
//	printf("%s\n", (*p).name);
//}
//int main()
//{
//	struct stu students[3] = { {9801,"zhang",20},{9802,"wang",19},{9803,"zhao",18} };
//	fun(students + 1);
//	return 0;
//}
//A.zhang
//正确答案B.wang
//C.zhao
//D.18

//4、结构体访问成员的操作符不包含：
//A..操作符
//B.->操作符
//C.*解引用操作符
//正确答案D.sizeof

//5、喝汽水问题
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
//  20元 - 20瓶喝掉 - 20空瓶
//换10瓶 - 10瓶喝掉 - 10空瓶
//换 5瓶  - 5瓶喝掉 -  5空瓶
//换 2瓶  - 2瓶喝掉 -  2+1=3空瓶
//换 1瓶  - 1瓶喝掉 -  1+1=2空瓶
//换 1瓶  - 1瓶喝掉 -  1空瓶
//#include <stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;//喝掉的总数
//	int empty = 0;//空瓶的个数
//	scanf("%d", &money);
//	//买回来的汽水喝掉的数量
//	total = money;
//	empty = money;
//	//换回来的汽水
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("total = %d\n", total);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;//喝掉的总数
//	int empty = 0;//空瓶的个数
//	scanf("%d", &money);
//	//money和total存在：total = 2 * money - 1的关系
//	if (money == 0)
//		total = 0;
//	else
//		total = 2 * money - 1;
//	printf("total = %d\n", total);
//	return 0;
//}

//1、C程序常见的错误分类不包含：
//A.编译错误
//B.链接错误
//正确答案C.栈溢出
//D.运行时错误

//2、关于VS调试快捷键说法错误的是：
//正确答案A.F5是开始执行，不调试
//B.F10是逐过程调试，遇到函数不进入函数
//C.F11是逐语句调试，可以观察调试的每个细节
//D.F9是设置断点和取消断点
//注意：F5开始调试，ctrl + F5开始执行，不调试

//3、关于Debug和Release的区别说法错误的是：
//A.Debug被称为调试版本，程序调试找bug的版本
//B.Release被成为发布版本，测试人员测试的就是Release版本
//C.Debug版本包含调试信息，不做优化
//正确答案D.Release版本也可也调试，只是往往会优化，程序大小和运行速度上效果最优

//4、以下关于指针的说法正确的是：
//A.int *const p与int const *p等价
//B.const int *p与int *const p等价
//正确答案C.const int *p与int const *p等价
//D.int *p[10]与int (*p)[10]等价
//注意：const在*的同一边，修饰的效果相同

//5、以下哪一种形式声明了一个指向char类型变量的指针p，p的值不可以修改，但p指向的变量的值可以修改？
//A.const char *p
//B.char const *p
//正确答案C.char *const p
//D.const char *const p

//6、程序死循环解释
//VS开发环境调试下面的代码，画图解释下面代码的问题
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit\n");
//	}
//	return 0;
//}
//越界访问，导致i = 12时&arr[12]与&i的地址相同

//7、strlen实现
//模拟实现库函数strlen

//8、strcpy实现
//模拟实现库函数strcpy 

//9、调整奇数偶数顺序
//调整数组使奇数全部都位于偶数前面
//输入一个整型数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分.
//10 3 6 8 7 9 4 3 5 1
//1.从左边找一个偶数
//2.从右边找一个奇数
//3.二者交换
//#include <stdio.h>
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while ((left < right) && (arr[left] % 2 == 1))//(left < right)这个附加条件,必须要满足,否则可能(数组全奇数)访问越界
//		{//如果是奇数就找下一个
//			left++;
//		}
//		while ((left < right) && (arr[right] % 2 == 0))//(left < right)这个附加条件,必须要满足,否则可能(数组全偶数)访问越界
//		{//如果是偶数就找下一个
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//			
//		}
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	Print(arr, sz);
//	return 0;
//}

//1、原码、反码、补码说法错误的是：
//A.一个数的原码是这个数的直接转换成二进制
//B.反码是原码的二进制符号位不变，其余位按位取反
//C.补码是反码的二进制加1
//正确答案D.原码、反码、补码的最高位是0表示负数，最高位是1表示正数

//2、关于大小端字节序的描述正确的是：
//A.大小端字节序指的是数据在电脑上存储的二进制顺序
//正确答案B.大小端字节序指的是数据在电脑存储的字节顺序
//C.大端字节序是把数据的高字节内容存放到高地址，低字节内容存放在低地址处
//D.小端字节序是把数据的高字节内容存放到低地址，低字节内容存放在高地址处

//3、程序的执行结构为：
//#include <stdio.h>
//int main()
//{
//	//unsigned char - 1个字节-8bit（0-255）
//	unsigned char a = 200;
//	//200 - 00000000 00000000 00000000 11001000
//	//a = 11001000
//	unsigned char b = 100;
//	//100 - 00000000 00000000 00000000 01100100
//	//b = 01100100
//	unsigned char c = 0;
//	c = a + b;
//	//a + b整型提升，由于a和b是无符号char类型，高位补0
//	//a = 00000000 00000000 00000000 11001000
//	//b = 00000000 00000000 00000000 01100100
//  //a+b = 00000000 00000000 00000001 00101100 
//	//c = 00101100 
//	printf("%d %d", a + b, c);
//	//%d - 以十进制有符号形式打印
//	//a+b的补码 = 00000000 00000000 00000001 00101100 
//	//a + b ：没有存入内存，故为300
//	//c以%d打印，故又发生整型提升，且c是无符号cha类型，高位补0
//	//c = 00000000 00000000 00000000 00101100 
//	//故c为44
//	//注意：所有的运算操作都是以数的补码运算，打印的是原码
//	return 0;
//}
//A.300 300
//B.44 44
//正确答案C.300 44
//D.44 300

//4、在 32位大端模式处理器上变量b等于：
//#include <stdio.h>
//int main()
//{
//	unsigned int a = 0x1234; //4个十六进制位，等于16个二进制位，两个字节
//	//0x1234 = 0x00 00 12 34
//	//内存的存储方式：低地址00 00 12 34高地址
//	unsigned char b = *(unsigned char*)&a;//*解引用访问一个字节的空间
//	//由于强制类型转换，不会改变值的大小，但解引用访问一个字节，故b = 0x00
//	printf("%x\n", b);
//	return 0;
//}
//正确答案A.0x00
//B.0x12
//C.0x34
//D.0x1234

//5、下面代码的结构是：
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//有符号char的范围是-128 - 127
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		a[i] = -1 - i;
//	}
//	//由于会将结果保存在char中，故每个元素的值都在char的范围内
//	//a[1000] = {-1,-2,...,-128,127,126,125...1,0,...}
//	printf("%d\n", strlen(a));
//	return 0;
//}
//A.1000
//B.999
//正确答案C.255
//D.256

//6、杨辉三角
//在屏幕上打印杨辉三角
//    1
//   1 1
//  1 2 1
// 1 3 3 1
//1 4 6 4 1

//将其抽象为打印以下形式，再添加空格
//0 1 2 3 4列
//
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//观察发现：第一列和对角线都是1
//用二维数组
//#include <stdio.h>
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	int j = 0;
//	//对二维数组进行初始化
//	for (i = 0; i < 10; i++)//控制行
//	{
//		for (j = 0; j < 10; j++)//控制列
//		{
//			//初始化第一列
//			if(j == 0)
//				arr[i][j] = 1;
//			//初始化对角线
//			if (i == j)
//				arr[i][j] = 1;
//			//初始化剩余元素
//			if (i >= 2 && j >= 1)
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d\t", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//7、猜凶手
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4格嫌疑犯的一个
//以下为4格嫌疑犯的供词：
//A说：不是我
//B说：是C
//C说：是D
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//假设以某个人为凶手，对每个人的话(条件)进行判断真假，为真则是1，为假则是0
//假设凶手是A，
//A说的话是假话0
//B说的话是假话0
//C说的话是假话0
//D说的话是真话1
//说明A不是凶手，否则不满足3真，1假

//假设凶手是B，
//A说的话是真话1
//B说的话是假话0
//C说的话是假话0
//D说的话是真话1
//说明B不是凶手，否则不满足3真，1假

//假设凶手是C，
//A说的话是真话1
//B说的话是真话1
//C说的话是假话0
//D说的话是真话1

//假设凶手是D，
//A说的话是真话1
//B说的话是假话0
//C说的话是真话1
//D说的话是假话0

//#include <stdio.h>
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		//将每句话进行条件相加如果结果为3
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//			printf("killer = %c\n", killer);
//	}
//	return 0;
//}
//面试经常会考这种类型的题。
//赛马问题：有36匹马，有6个跑道，没有计时器，请赛马确定，36匹马中的前三名。
//请问最少比赛几次？
//一、6 - 1次 二、6 - 1次 三、6 - 1次 四、6 - 1次 五、6 - 1次 六、6 - 1次 共6次
//假设第一组在六组中：第一名，第二组在六组中：第二名，第三组在六组中：第三名...
//再将每一组的第一名比1次
//最后，将第一名的第一组前3名、第二名的第二组的前两名、第三名的第三组的前1名比1次
//则共6+1+1 = 8次

//赛马问题：有25匹马，有5个跑道，没有计时器，请赛马确定，25匹马中的前三名。
//请问最少比赛几次？

//烧香问题
//有一种香，材质不均匀，但是每一根这种香，燃烧完恰好是1个小时。
//先给你2根香，帮我确定一个15分钟的时间段
//第一根香两端同时都点燃，第二根香也同时点燃一端，故第一根香需要半个小时燃尽，第二根香也点燃了半个小时
//第一根香快燃完，即半个小时后，再同时点燃第二根香的另一端，故需要烧15分钟
//牛客网刷这类题。

//8、猜名次
//5为运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三
//B选手说：我第二，E第四
//C选手说：我第一，D第二
//D选手说：C最后，我第三
//E选手说：我第四，A第一
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次 
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a * b * c * d * e == 120)//这里行是必要的，否则会出现重名次的现象
//								printf("a = %d b = %d c = %d d = %d e = %d", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//45p简历的书写

//9、课堂代码练习与本主题博客
//1.请同学们自主完成课堂代码的编写
//2.根据本节课讲解，将涉及到的核心知识点，进行整理并写一篇博客
//3.以博客链接的方式，提交博客作业
//简历上贴博客链接和gitub链接

//1、下面关于“指针”的描述不正确的是：
//正确答案A.当使用free释放掉一个指针内容后，指针变量的值被置为了NULL
//B.32位系统下任何类型的指针的长度都是4个字节
//C.指针的数据类型声明的是指针实际指向内容的数据类型
//D.野指针是指向未分配或者已经释放的内存地址
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//申请空间
//	int *p = (int*)malloc(10 * sizeof(int));//malloc向内存申请10个int大小的空间
//	//由于malloc返回类型是：void*，malloc的返回值：将申请的空间的地址返回，故用指针int*类型接收，且需要对地址进行强制类型转换
//	
//	//使用空间
//	//......
//
//	//释放空间
//	free(p);//释放p指向的空间，通过调试，发现执行到这里是，p的内容没有被置为NULL
//	p = NULL;
//	return 0;
//}

//2、关于下面代码描述正确的是：
//char* p = "hello bit";
//A.把字符串hello bit存在p变量中
//B.把字符串hello bit的第一个字符存放在p变量中
//正确答案C.把字符串hello bit的第一个字符的地址存放在p变量中
//D.*p等价于hello bit（*p等价于h）

//3、关于数组指针的描述正确的是：
//A.数组指针是一种数组
//B.数组指针是一种存放数组的指针（存放的是数组的地址，是指向数组的指针，而不是存放的是数组指针）
//正确答案C.数组指针是一种指针
//D.指针数组是一种指向数组的指针
//int arr[10];//数组
//int (*p)[10] = &arr;//数组指针
//int (*(*pointer))[10] = &p;//数组指针的指针

//4、下面哪个是数组指针：
//A.int** arr[10]
//B.int (*arr[10])
//正确答案C.char *(*arr)[10]
//D.char (*)arr[10]

//5、下面哪个代码是错误的？
//#include <stdio.h>
//int mian()
//{
//	int* p = NULL;
//	int arr[10] = { 0 };
//	
//	return 0;
//}
//A.p = arr;
//B.int (*ptr)[10] = &arr;
//C.p = &arr[0];
//正确答案D.p = &arr;(否则必须强制类型转换为int*)

//6、下面代码关于数组名描述不正确的是：
//#include <stdio.h>
//int mian()
//{
//	int arr[10] = { 0 };
//
//	return 0;
//}
//正确答案A.数组名arr和&arr是一样的
//B.sieof(arr)，此时arr表示整个数组
//C.&arr，此时arr表示整个数组
//D.除了sizeof(arr)和&arr中的数组名，其他地方出现的数组名arr，都是数组首元素的地址

//7、如何定义一个int类型的指针数组，数组元素个数为10个：
//A.int a[10];
//B.int (*a)[10];
//正确答案C.int *a[10];
//D.int (*a[10])(int);//函数指针数组

//8、下面代码执行结果是：
//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit";//变量字符串
//	char str2[] = "hello bit";//常量字符串
//	char* str3 = "hello bit";
//	char* str4 = "hello bit";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}
//A.str1 and str2 are same      str3 and str4 are same
//B.str1 and str2 are same      str3 and str4 are not same
//正确答案C.str1 and str2 are not same  str3 and str4 are same
//D.str1 and str2 are not same  str3 and str4 are not same
//==比较的是内容，str1、str2、str3、str4分别有自己独立的存储空间和地址
//由于str1、str2的内容存放的是变量字符串的首元素的地址，故地址是不相同的
//由于str3、str4指向的是常量字符串，存放的是常量字符串的首元素的地址，故地址是相同的

//1、下面哪个是函数指针？
//A.int* fun(int a, int b);//函数声明
//B.int(*)fun(int a, int b);
//正确答案C.int (*fun)(int a, int b);//函数指针
//D.(int*)fun(int a, int b);//函数声明

//2、定义一个函数指针，指向的函数有两个int形参并且返回一个函数指针，
//返回的指针指向一个有一个int形参且返回int的函数？下面哪个是正确的？(*F)(int,int)
//正确答案A.int (*(*F)(int,int))(int)//返回类型是int (*)(int)
//B.int (*F)(int,int)//返回类型是int
//C.int (*(*F)(int,int))
//D.*(*F)(int,int)(int)

//int Add(int a, int b);
//int (*pF)(int, int) = Add;//函数指针
//int arr[10];
//int (*pA)[10] = &arr;//数组指针

//3、在游戏设计中，经常会根据不同的游戏状态调用不同的函数，我们可以通过函数指针来实现这一功能，
//下面哪个是：一个参数为int*，返回值为int的函数指针：
//A.int (*fun)(int)
//正确答案B.int (*fun)(int*)
//C.int* fun(int*)
//D.int* (*fun)(int*)

//4、声明一个指向含有10个元素的数组的指针，其中每一个元素是一个函数指针，该函数的返回值是int
//参数是int*，正确的是：int *arr[10];函数指针数组的指针，int (*F)(int*),int (*(*Farr)[10])(int*)
//A.(int *p[10])(int*)
//B.int [10]*p(int*)
//正确答案C.int(*(*p)[10](int*))
//D.int ((int*)[10])*p

//5、设有以下函数void fun(int n,char *s){......}则下面对函数指针的定义和赋值均是正确的是：
//A.void (*pf)(int,char);pf = &fun;
//正确答案B.void (*pf)(int n,char *s); pf = fun;
//C.void *pf();*pf = fun;
//D.void *pf();pf = fun;

//1、关于回调函数描述错误的是：
//A.回调函数就是一个通过函数指针调用的函数
//B.回调函数一般通过函数指针实现
//C.回调函数一般不是函数的实现方调用，而是在特定的场景下，由另一方调用
//正确答案D.回调函数是调用函数指针指向函数的函数

//2、下面test函数设计正确的是：(多选题)BD
//char* arr[5] = { "hello","bit" };
//test(arr);
//A.void test(char* arr);
//B.void test(char** arr);
//C.void test(char arr[5]);
//D.void test(char* arr[5]);
//注意：传入的参数是数组名，设计函数时形参可以是数组，也可也是指针

//3、下面代码中print_arr函数参数设计哪个是正确的？
//int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
//print_arr(arr,3,5);
//A.void print_arr(int arr[][],int row,int col);
//B.void print_arr(int* arr,int row,int col);
//正确答案C.void print_arr(int (*arr)[5],int row,int col);
//D.void print_arr(int (*arr)[3],int row ,int col);

//4、下面程序的结果是：
//#include <stdio.h>
//int main()
//{
//	int a[5] = { 5,4,3,2,1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//A.5,1
//正确答案B.4,1
//C.4,2
//D.5,2

//5、qsort使用练习
//练习使用库函数，qsort排序各种类型的数据

//6、qsort模拟实现
//模仿qsort的功能实现一个通用的冒泡排序

//1、下面程序的结果是：
//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));//*(aa+1) == aa[1]，此处的强制类型转换没有意义
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//正确答案A.1,6
//B.10,5
//C.10,1
//D.1,5

//2、旋转字符串（以左旋为例）
//实现一个函数，可以左旋字符串中的k个字符
//例如：ABCD左旋一个字符得到BCDA。ABCD左旋两个字符得到CDAB
//假设字符数组内容为：abcdef\0
//第一步：取出a
//第二步：bcedf往前移动
//第三步：将a放在原先的f处
//同理：如果要旋转两次，则进行以上类似的操作(循环2次)

//暴力求解法：指针求解
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	//左旋k个字符
//	for (i = 0; i < k; i++)
//	{
//		//这里面实现左旋1个字符
//		//1、拿走a
//		char tmp = *arr;
//		//2、bcedf往前移动
//		int j = 0;
//		int len = strlen(arr);
//		for (j = 0; j < len - 1; j++)//假设len = 6，下标最大为5，如果j < len，j = 5使，下标最大arr[6]越界，故小于len-1
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3、将a放在原先的f处
//		*(arr + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s\n", arr);
//	return 0;
//}

//暴力求解法：数组求解
//#include <stdio.h>
//#include <string.h>
//void left_move(char arr[], int k)
//{
//	int i = 0;
//	//左旋k个字符
//	for (i = 0; i < k; i++)
//	{
//		//这里面实现左旋1个字符
//		//1、拿走a
//		char tmp = arr[0];
//		//2、bcedf往前移动
//		int j = 0;
//		int len = strlen(arr);
//		for (j = 0; j < len - 1; j++)//假设len = 6，下标最大为5，如果j < len，j = 5使，下标最大arr[6]越界，故小于len-1
//		{
//			arr[j] = arr[j+1];
//		}
//		//3、将a放在原先的f处
//		arr[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 3);
//	printf("%s\n", arr);
//	return 0;
//}

//三步翻转法
//abcdef
//第一步左边逆序：ba
//第二步右边逆序：fedc
//第三步整体逆序：cdefab
//注意：逆序功能的实现是，已知两端的下标，值进行交换
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
////逆序字符串函数
//void reverse(char* left, char* right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
////旋转字符串函数
//void left_move(char* arr,int k)
//{
//	assert(arr);//判断指针是否为空-断言
//	int len = strlen(arr);
//	assert(k < len);
//	reverse(arr, arr + k - 1);//逆序左边
//	reverse(arr + k, arr + len - 1);//逆序右边
//	reverse(arr, arr + len - 1);//逆序整体
//}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 3);//对于旋转的个数不能大于字符串的长度
//	printf("%s\n", arr);
//	return 0;
//}

//3、字符串旋转结果--来自《程序员编程艺术》：http://blog.csdn.net/v_july_v
//写一个函数，判断一个字符串释放为另外一个字符串旋转之后的字符串
//例如：给定s1 = AABCD和s2 = BCDAA，返回1.给定s1 = abcd和s2 = ABCD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	//左旋k个字符
//	for (i = 0; i < k; i++)
//	{
//		//这里面实现左旋1个字符
//		//1、拿走a
//		char tmp = *arr;
//		//2、bcedf往前移动
//		int j = 0;
//		int len = strlen(arr);
//		for (j = 0; j < len - 1; j++)//假设len = 6，下标最大为5，如果j < len，j = 5使，下标最大arr[6]越界，故小于len-1
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3、将a放在原先的f处
//		*(arr + len - 1) = tmp;
//	}
//}
//int is_left_move(char* s1, char* s2)
//{
//	//将s1旋转1-k次的所有可能结果，都分别与s2比较是否有相等的
//	//旋转的可能性由字符串的长度决定
//	int len = strlen(s1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(s1, 1);
//		//这里left_move(s1, 1)是1，不是i，否则没每次旋转结果都会发生改变
//		//比如：当i = 0时，没有旋转
//		//当i = 1时，旋转1次，结果为bcedfa
//		//当i = 2时，则会在bcdefa的基础上，再旋转两次
//		
//		//比较每次旋转后的s1和s2
//		int ret = strcmp(s1, s2);
//		if (ret == 0)
//			return 1;
//	}
//	//每一个可能性都不满足后，来到这里
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";//不能使用char* arr1 ="abcdef";和char* arr2 ="cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}

//abcdefabcdef
//对s1追加一个字符串，此时它里面的内容包含了所有旋转可能的字符串
//再判断s2是否包含在s1中
//#include <stdio.h>
//#include <string.h>
//int is_left_move(char* str1, char* str2)
//{
//	//1、在str1字符串中追加一个str1字符串
//	//strcat(s1,s2)：将s2追加到是s1后面
//	//原理：abc\0，将def\0追加到abc\0后面，d放到\0上，ef\0放到d后面，直到def字符串的\0放入最后，停止最佳
//	//如果：abc\0，将abc\0追加到abc\0后面，此时a放到\0上，bc放到a后面，而此时abc的\0被a覆盖了，就会无限最佳，直到程序奔溃
//	//故：strcat(s1,s2)不能给自己追加，即不能strcat(s1,s1)
//	//通过MSDN观察strcat和strncat的参数区别,count参数是指追加字符的个数
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	strncat(str1, str1, len1);
//	//2、判断str2指向的字符串是否是str1指向的字符串的子串
//	//strstr：找子串，如果找到了，返回找到的字符串首元素的地址，否则返回空指针
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)//NULL字符串是指stdio.h中定义的
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[30] = "abcdef";//使用更大的空间
//	char arr2[] = "cdef";//这里arr2中的长度必须和arr1的长度一致，否则arr1旋转的结果都是得不到的arr2
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	return 0;
//}
//未来面试中能用库函数尽量用库函数实现

//4、杨氏矩阵--来自《剑指offer》
//有一个数字矩阵，矩阵的每一行从左到右是递增的，每一列矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求时间复杂度小于O(N)，假设以下矩阵，最坏需要找9次找到，时间复杂度是9，故不能通过遍历二维数组，否则时间复杂度等于O(N)
//如：
//      x
//      0     1     2
//  y
//  0   1     2     3
//  1   4     5     6
//  2   7     8     9
//x <=2,y>=0

//1、二分查找
//2、小的去掉行，大的去掉列(右上角、左下角都可以作为参考，但是左上角、右下角不可以，作为参考的必须能排除一行或一列)
//假设要找的数是k，通过右上角的3与k比较，如果3小，则这一行都没有，排除这一行
//继续新的右上角的数6与k比较，如果6小，也排除这一行，
//如果新的右上角比k大，则这一列都没有，排除这一列，直到锁定最后一个数，判断是否相等
//#include <stdio.h>
//int FindNum(int arr[3][3], int k, int row, int col)
//{
//	//右上角的坐标
//	int x = 0;
//	int y = col - 1;
//	while (x <= row - 1 && y >= 0)//注意查找的条件，以查找7为例，行慢慢减为2，列从2变为0
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			//printf("%d %d",x,y);//打印坐标，但是函数一般不使用打印函数直接打印
//			return 1;//找到了
//	}
//	//当循环结束时，没有找到
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 17;
//	int ret = FindNum(arr, k, 3, 3);//找到了，返回1，没找到，返回0
//	if (ret == 1)
//		printf("找到了\n");
//	else
//		printf("找不到\n");
//	return 0;
//}

//代码改进：
//#include <stdio.h>
//int FindNum(int arr[3][3], int k, int *px, int *py)
//{
//	//右上角的坐标
//	int x = 0;
//	int y = *py - 1;
//	while (x <= *px - 1 && y >= 0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//		{	//1、printf("%d %d",x,y);//打印坐标，但是函数一般不使用打印函数直接打印
//			//2、改掉函数外的x，y的值
//			*px = x;
//			*py = y;
//			return 1;//找到了
//		}
//	}
//	//当循环结束时，没有找到
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 17;
//	int x = 3;
//	int y = 3;
//	//返回型参数：&x，&y
//	int ret = FindNum(arr, k, &x, &y);//通过传址调用的方式，可以通过地址操作函数外的x，y的值
//	if (ret == 1)
//	{
//		printf("找到了\n");
//		printf("下标时：%d %d\n", x, y);
//	}
//	else
//		printf("找不到\n");
//	return 0;
//}