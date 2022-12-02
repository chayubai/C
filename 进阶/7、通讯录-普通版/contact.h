#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000	//通讯录容量
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//qsort库函数的头文件

//对switch设置枚举常量，提高可读性
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};

//声明一个好友信息的类型
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//声明一个通讯录类型
struct Contact
{
	//将其封装在一起，方便传参
	struct PeoInfo data[MAX];//创建一个存放1000个好友的信息的空间data，每个元素都是一个struct PeoInfo结构体
	int size;//用来记录当前通讯录多少个好友信息
};

//声明初始化通讯录的函数
void InitContact(struct Contact* ps);
//声明增加好友信息的函数
void AddContact(struct Contact* ps);
//声明打印好友信息的函数
void ShowContact(const struct Contact* ps);//const的修饰
//声明删除指定的好友信息的函数
void DelContact(struct Contact* ps);
//声明查找指定好友信息的函数
void SearchContact(const struct Contact* ps);

//声明指定要修改好友信息的函数
void ModifyContact(struct Contact* ps);
//声明指定条件的好友信息的排序函数
void SortContact(struct Contact* ps);

//该程序的实现：可以用函数指针，造一个函数指针的数组，就好比之前讲的计算器
//这个程序只适合不同名的增删改查操作。

//分析：
//1、为什么使用#define MAX 1000?
//2、为什么要定义int size;?
//3、为什么将struct PeoInfo[MAX]和int size;进行封装？
//4、为什么case中使用枚举常量？
//5、struct PeoInfo[MAX]中的MAX有什么作用？
//6、为什么要封装一个FindByName函数？为什么使用const修饰，为什么使用static修饰？
//7、为什么程序退出，数据就不存在了？增删改查本质操作的是什么？
//8、对于同名元素，查找，删除，修改应该如何操作？ - 循环查找，循环删除，