#define _CRT_SECURE_NO_WARNINGS 1
//作业：
//1、有如下宏定义和结构定义
//#include <stdio.h>
//#define MAX_SIZE A+B
//
//struct _Record_Struct//占三个字节
//{
//	//位段，由于是char，每次开辟1个字节空间
//	unsigned char ENv_Alarm_ID : 4;//占用4位，剩余4bit
//	unsigned char Paral : 2;//占用2位，剩余2bit
//	unsigned char state;//开辟1个字节
//	unsigned char avail : 1;//开辟1个字节，剩余7个字节
//}*Env_Alarm_Record;
//int main()
//{
//	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//	//即3 * 2 + 3
//	return 0;
//}
//当A = 2,B = 3时，pointer分配多少个字节的空间：
//A、20
//B、15
//C、11
//正确答案D、9

//2、下面代码的结果是：
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPiml;//占1个字节
//		unsigned char ucData0 : 1;//占1bit，剩余7bit
//		unsigned char ucData1 : 2;//占2bit，剩余5bit
//		unsigned char ucData2 : 3;//占3bit，剩余2bit
//	}*pstPimData;//pstPimData位段式结构体struct tagPIM指针变量
//	pstPimData = (struct tagPIM*)puc;//让指针指向puc的地址
//	memset(puc, 0, 4);//将数组puc空间的4个字节，设置为0，即00000000 00000000 00000000 00000000
//	//指针指向的空间，以位段一次使用
//	pstPimData->ucPiml = 2;//00000010
//	pstPimData->ucData0 = 3;//00000011 - 1
//	pstPimData->ucData1 = 4;//00000100 - 00
//	pstPimData->ucData2 = 5;//00000001 - 001
//	//即(00000010) (00 101 00 1) (00000000) (00000000)
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	//%02x - 打印两位十六进制数
//	return 0;
//}
//A、02 03 04 05
//正确答案B、02 29 00 00
//C、02 25 00 00
//D、02 29 04 00

//3、下面代码的结果是：
//#include <stdio.h>
//union Un//占16个字节
//{
//	short s[7];//14
//	int n;//4
//};//最终是最大对齐数的整数倍
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
//A、14
//B、4
//正确答案C、16
//D、18

//4、在X86下，有下列程序
//#include <stdio.h>
//int main()
//{
//	union//占两个字节
//	{
//		short k;//2
//		char i[2];//2
//	}*s, a;
//	//s联合体指针变量
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	//低地址   高地址
//	//     i[0] i[1]
//	//s->a  39   38
//	printf("%x\n", a.k);//0x3839
//	return 0;
//}
//正确答案A、3839
//B、3938
//C、380039
//D、不确定

//5、下面代码的结果是：
//enum
//{
//	X1,//0
//	Y1,//1
//	Z1 = 255,
//	A1,//256
//	B1,//257
//};
//enum enumA = Y1;
//enum enumB = B1;
//printf("%d %d\n", enumA, enumB);
//A、1 4
//正确答案B、1 257
//C、2 257
//D、2 5

//6、通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//1、添加联系人信息
//2、删除指定联系人信息
//3、查找指定联系人信息
//4、修改指定联系人信息
//5、显示所有联系人信息
//6、清空所有联系人
//以名字排序所有联系人

//7、课堂代码练习与本主题博客
//整理核心知识点，进行博客编写

//1、关于动态内存函数的说法错误的是：
//A、malloc函数向内存申请一块连续的空间，并返回起始地址
//B、malloc申请空间失败，返回NULL指针
//C、malloc可以向内存申请0字节的空间
//正确答案D、malloc申请的内存空间，不进行释放也不会对程序有影响

//2、关于动态内存相关函数说法错误的是：
//A、malloc函数和calloc函数的功能是相似的，都是申请一块连续的空间
//B、malloc函数申请的空间不初始化，calloc函数申请的空间会被初始化为0
//C、realloc函数可以调整动态申请内存的大小，可大可小
//正确答案D、free函数不可以释放realloc调整后的空间

//3、动态申请的内存在内存的哪个区域？
//A、栈区
//正确答案B、堆区
//C、静态区
//D、文字常量区

//4、关于下面代码描述错误的是：
//#include <stdio.h>
//#include <stdlib.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf("str");
//}
//正确答案A、上面代码没有问题
//B、上面代码存在内存泄露
//C、上面代码可能会崩溃，即使GetMomory函数返回，str依旧为NULL
//D、GetMemory函数无法把malloc开辟的100个字节带回来

//5、以下哪个不是动态内存常见的错误：
//正确答案A、free参数为NULL
//B、对非动态内存的free释放
//C、对动态内存的多次释放
//D、对动态内存的越界访问

//6、关于下面代码描述正确的是：
//#include <stdio.h>
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf("str");
//}
//A、printf函数使用有问题
//B、程序正常打印hello world
//正确答案C、GetMemory函数的地址无法正常使用//使用二级指针接收返回值
//D、程序存在内存泄露//没有动态开辟空间，故不存在内存泄露

//7、模拟实现strncpy
//8、模拟实现strncat

//9、找单身狗 - 来自《剑指offer》
//一个数组中只有两个数字是出现一次，其他所有数字都出现两次。
//编写一个函数找出这两个只出现一次的数字
//思路：
//把所有的数字异或，找出第几位为1，以这一位为0和为1分成两组，分别两组异或得到各自的单身数

//10、博客，总结核心知识点

//1、C语言以二进制方式打开一个文件的方法是：
//A、FILE* f = fwrite("test.bin","b");
//B、FILE* f = fopenb("test.bin","w");
//C、FILE* f = fopen("test.bin","wb");
//D、FILE* f = fwriteb("test.bin");

//2、关于fopen函数说法不正确的是：
//A、fopen打开文件的方式是"r"，如果文件不存在，则会打开失败
//B、fopen打开文件的方式是"w"，如果文件不存在，则创建该文件，打开成功
//C、fopen函数的返回值无需判断
//D、fopen打开的文件需要fclose来关闭

//3、下列关于文件名及路径的说法中错误的是：
//A、文件名中有一些禁止使用的字符
//B、文件名中一定包含后缀名
//C、文件的后缀名决定了一个文件的默认打开方式
//D、文件路径指的是从盘符到该文件所经历的路径中各符号名的集合

//4、C语言中关于文件读写函数说法不正确的是：
//A、fgetc是适用于所有输入流字符输入函数
//B、getchar也是适用于所有流的字符输入函数
//C、fputs是适用于所有输出流的文本行输出函数
//D、fread是适用于文本输入流的二进制输入函数

//5、下面程序的功能是什么？
//#include <stdio.h>
//int main()
//{
//	long num = 0;
//	FILE* fp = NULL;
//	if ((fp = fopen("fname.dat", "r")) == NULL)
//	{
//		printf("Can't open the file!");
//		exit(0);
//	}
//	while (fgetc(fp) != EOF)
//	{
//		num++;
//	}
//	printf("num = %d\n", num);
//	fclose(fp);
//
//	return 0;
//}
//A、拷贝文件
//B、统计文件的字符数
//C、统计文件的单词数
//D、统计文件的行数

//6、下面说法不正确的是：
//A、scanf和printf是针对标准输入、输出流的格式化输入、输出语句
//B、fscanf和fprintf是针对所有输入、输出流的格式化输入、输出语句
//C、sscanf是从字符串中读取格式化的数据
//D、sprintf是把格式化的数据写到输出流中

//7、关于feof函数描述不正确的是：
//A、feof函数是用来判断文件是否读取结束的
//B、feof函数是在文件读取结束的时候，检测是否是因为遇到了文件结束标志EOF，而读取结束
//C、读取文本判断是否结束时，fgetc看返回值是否为EOF，fgets看返回值是否为NULL
//D、二进制文件判断读取结束，看实际读取个数是否小于要求读取个数

//8、通讯录3
//在之前的通讯录上增加两个函数，实现数据可以保存到文件，也可以从文件中加载数据
//a、添加一个函数，在退出通讯录的时候把信息保存到文件中
//b、添加一个函数，在通讯录打开时，可以把文件中的信息加载到通讯录中

//9、博客，总结核心知识点

//1、下面哪个不是预处理指令：
//A、#define
//B、#if
//C、#undef
//D、#end

//2、下面哪个不是预定义符号：
//A、__FILE__
//B、__TIME__
//C、__DATE__
//D、__MAIN__

//3、（）的作用是将源程序文件进行处理，生成一个中间文件，编译系统将对此中间文件进行编译并生成目标代码：
//A、编译预处理
//B、汇编
//C、生成安装文件
//D、编译

//4、由于多个源文件组成的C程序，经过编辑、预处理、编译、链接等阶段会生成最终的可执行程序
//下面哪个阶段可以发现被调用的函数未被定义：
//A、预处理
//B、编译
//C、链接
//D、执行

//5、设有以下宏定义：
//#define N 4
//#define Y(n) ((N+2)*n)
//则执行语句：z = 2*(N+Y(5+1));后，z的值为：
//A、出错
//B、60
//C、48
//D、70

//1、下面代码执行的结果是：
//#define A 2+2
//#define B 3+3
//#define C A*B
//int main()
//{
//	printf("%d\b", C);
//	return 0;
//}
//A、24
//B、11
//C、10
//D、23