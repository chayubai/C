#define _CRT_SECURE_NO_WARNINGS 1
//初步认识结构体
//1、结构体类型的声明
//结构的基础知识
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。
//结构体类型的声明格式1：
//struct tag
//{
//	member - list;
//}[variable - list];//[variable - list]可省略
//分号不能丢

//创建描述学生的结构体类型：姓名、年龄、电话、性别
//struct结构体关键字	Stu结构体标签	struct Stu结构体类型
//struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}s1, s2, s3;//创建结构体类型的同时创建结构体变量，s1,s2,s3是三个全局的结构体变量
//int main()
//{
//	//创建局部的结构体变量
//	struct Stu s;
//	return 0;
//}
//注意：尽量少定义全局变量
//类型的创建不占内存空间，只要通过类型创建了变量，此时该类型的变量才会占用空间

//结构体类型的声明格式2：
//typedef struct tag
//{
//	member - list;
//}tag;
//分号不能丢

//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;//将结构体类型struct Stu 类型重定义为Stu类型
//int main()
//{
//	//创建局部的结构体变量
//	struct Stu s1;
//	Stu s2;
//	return 0;
//}

//2、结构体初始化
//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;//将结构体类型struct Stu 类型重定义为Stu类型
//int main()
//{
//	//创建局部的结构体变量
//	struct Stu s1 = { "张三",20,"18866668888","男" };//创建变量的同时初始化
//	Stu s2 = { "旺财",30,"16688886666","保密" };
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;//结构体成员可以是其他结构体变量
//	//struct S* ps;//结构体类型的指针变量
//	//struct T* pt;//其他结构体类型的指针变量
//	char* pc;
//}t1 = { "hehe",{100,'w',"hello",3.14},NULL };
//int main()
//{
//
//	char arr[] = "hello bit\n";
//	struct T t2 = { "hehe",{100,'w',"hello",3.14},arr };
//
//}
//结构的成员可以是变量、数组、指针，甚至是其他结构体。

//3、结构体成员访问
//方法1、
//结构体变量访问成员：
//结构变量的成员是通过点操作符（.）访问的。点操作符接受两个操作数。
//#include <stdio.h>
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;//结构体成员可以是其他结构体变量
//	char* pc;
//};
//int main()
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe",{100,'w',"hello",3.14},arr };
//	printf("%s\n", t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello//结构体成员中的变量名只能在结构体中使用，对主函数的同名变量无影响
//	printf("%lf\n", t.s.d);//3.14
//	printf("%p\n", t.pc);//00EFF8D0
//	printf("%s\n", t.pc);//hello bit//这里不需要*pc，否则报错
//
//}

//方法2、
//结构体指针访问指向变量的成员
//有时候我们得到的不是一个结构体变量，而是指向一个结构体的指针。
//#include <stdio.h>
//typedef struct Stu
//{
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;
//void Print1(Stu tmp)
//{
//	printf("name: %s\n", tmp.name);
//	printf("age: %d\n", tmp.age);
//	printf("tel: %s\n", tmp.tel);
//	printf("sex: %s\n", tmp.sex);
//}
//void Print2(Stu* ps)
//{
//	printf("name: %s\n", (*ps).name);
//	printf("age: %d\n", (*ps).age);
//	printf("tel: %s\n", (*ps).tel);
//	printf("sex: %s\n", (*ps).sex);
//
//	printf("name: %s\n", ps->name);
//	printf("age: %d\n", ps->age);
//	printf("tel: %s\n", ps->tel);
//	printf("sex: %s\n", ps->sex);//->自带解引用操作
//}
//int main()
//{
//	Stu s = { "李四",40,"18899998888","男" };
//	//打印结构体数据
//	Print1(s);//传结构体变量
//	Print2(&s);//传结构体变量的地址
//	//Print1和Print2而言Print2更好;
//	//第一种方法，因为形参是实参的一份临时拷贝，形参会产生与实参等大的空间，
//	//如果实参资源较大，则对资源浪费较大，同时传递也需要时间消耗较大
//	//第二种方法：由于传入的是地址，则保存地址的空间较少
//
//	//总结：结构体传参的时候，要传结构体的地址。
//	return 0;
//}

//4、结构体传参
//内存分成：栈区、堆区、静态区
//栈区：存放的有：局部变量、函数的形式参数、函数调用也开辟空间
//堆区：动态内存分配：malloc/free、realloc、calloc
//静态区：存放的有：全局变量、局部变量
//函数传参的时候，参数是需要压栈的。
//如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。