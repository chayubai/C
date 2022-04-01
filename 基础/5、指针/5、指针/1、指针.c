//内存的地址是如何产生的？
//以32位机为例：32位机有32根地址线，地址线是物理线，通电有正电1/负电0
//电信号转换为数字信号：1和0组成的二进制序列
//32根地址线产生可能的二进制序列有：
//0000 0000 0000 0000 0000
//0000 0000 0000 0000 0001
//0000 0000 0000 0000 0010
// ...
//1111 1111 1111 1111 1111
//一共有2^32个二进制序列，都可以作为内存的编号，把这个编号称为内存单元的地址

//一个地址/内存单元的空间多大？
//假设：一个内存单元是1bit，则有2^32bit的地址空间，可转化为0.5GB的内存大小
//假设：一个内存单元是1byte，则有2^32byte的地址空间，可转化为4GB的内存大小
//最终：一个内存单元为一个字节，每个字节来分配一个地址

//#include <stdio.h>
//int main()
//{
//	int a = 10;//向内存申请连续的4字节的空间，空间名为a，来存放10
//	//按F10调试至return 0；语句后，点击“调试”选项卡，单击“窗口”，选择“内存”，选择任意内存，在地址栏输入&a
//	//点击“调试”选项卡，单击“窗口”，选择“监视”，选择任意监视，在名称输入&a
//	//四个字节都要地址，&a指的是，取四个字节的第一个字节的地址
//	
//	printf("%p\n",&a);//打印a的地址-只打印首地址（较小的地址）
//	//每打印地址都可能会变化，因为内存有限，当申请的空间不使用时，内存空间会回收，再创建变量时，重新分配空间
//	//%p是一地址的形式打印
//	int* p = &a;//p用来存a的地址&a（有一种变量专门用来存放地址的--指针变量），p的类型是int*
//	//p是一个变量，也有自己的类型，为int*，指针变量的类型取决于，存放的地址所指向的对象的类型
//	//* 说明p是指针变量
//	//int 说明p指向的对象是int类型
//	printf("%p\n",&a);
//	prinf("%p\n", p);//结果相同
//	*p = 20;
//	//* 是解引用操作符/间接访问操作符，对p进行解引用操作找到它所指向的对象a
//	//*p = 20 是通过p里边的地址找到a里边的值改成20，可以理解为*p即为a
//	printf("a = %d\n",a);//20
//
//	return 0;
//}

/*
又如： 
#include <stdio.h>
int main()
{
	char ch = 'w';
	char* pointer = &ch;
	printf("%p\n", &ch);//打印ch的地址
	printf("%p\n",pointer);//打印ch的地址
	printf("%p\n",&pointer);//打印pointer的地址
	*pointer = 'a';
	printf("%c\n", ch);//打印ch
	printf("%c\n", *pointer);//打印ch
	printf("%d\n", sizeof(pointer));

	return 0;
}
*/
/*指针变量的大小
#include <stdio.h>
int main()
{
	printf("%d\n", sizeof(char*));//4
	printf("%d\n", sizeof(short*));//4
	printf("%d\n", sizeof(int*));//4
	printf("%d\n", sizeof(long*));//4
	printf("%d\n", sizeof(long long*));//4
	printf("%d\n", sizeof(float*));//4
	printf("%d\n", sizeof(double*));//4
	//将Debug右侧，改为x64，结果为8

	return 0;
}
//不同类型的指针的空间大小都是相同的
//指针变量是用来存放地址的
//指针变量的空间有多大，取决于地址的存储需要多大空间
//32位机，地址需要32bit的空间，指针变量就需要32bit的空间，即4byte
//64位机，地址需要64bit的空间，指针变量就需要64bit的空间，即8byte
*/
//结构体：使得C语言有能力描述【复杂对象】--用来描述同一类复杂对象
//比如：描述学生，学生包括：名字+年龄+性别+学号... 这几项信息
//比如：描述书，书包括：书名+作者+出版社+定价+书号...
//结构体可以让C语言创建新的类型出来,复杂对象--可以通过结构体描述，即我们自己可以创造一种类型来描述
//创建一个结构体类型（学生类型）
//#include <stdio.h>
//#include <string.h>
//
//struct Stu//结构体类型
//{
//	//学生的相关属性：name、age、sex、id、score为成员变量名
//	char name[20];//姓名
//	int age;//年龄
//	char sex[5];//性别
//	char id[15];//学号
//	double score;//成绩
//};//分号结束类型定义
////创建一个的书的类型
//struct Book
//{
//	char name[20];//书名
//	float price;//价格
//	char id[30];//书号
//};
//int main()
//{
//	//利用结构体类型创建一个该类型的结构体变量---结构体的创建和初始化：
//	struct Stu student = { "张三", 20, 85.5 };//拿创建的结构体类型（学生类型），创建一个变量student
//	//结构体的使用：结构体变量名.成员变量名
//	//. 结构成员访问操作符：取类型的属性
//	printf("1：%s %d %lf\n", student.name, student.age, student.score);
//	struct Stu* pointer = &student;//结构体类型的指针变量pointer存储student的地址，结构体类型指针变量，它的类型是struct Stu*
//	//*pointer解引用找到student
//	printf("2：%s %d %lf\n", (*pointer).name, (*pointer).age, (*pointer).score);
//	//结构体指针变量->成员变量名
//	printf("3：%s %d %lf\n", pointer->name, pointer->age, pointer->score);
//
//	student.age = 18;//修改年龄---age为变量，可直接修改值
//	printf("修改后的年龄:%d\n岁", student.age);
//	//student.name = "李四";//char name[20]可知，name为数组名，本质上是一个地址，不能直接修改
//	strcpy(student.name, "李四");//strcpy-string copy:字符串拷贝-库函数，使用时须引入头文件#include <string.h>
//	//strcpy(A,B)：表示把B拷贝到A里面
//	printf("%s\n", student.name);
//
//	return 0;
//}




