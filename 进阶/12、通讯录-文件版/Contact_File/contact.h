
#define DEFAULT_SZ 3//扩容大小
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//qsort库函数的头文件
#include <stdlib.h>
#include <errno.h>
//对switch设置枚举常量，提高可读性
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
	SAVE
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
//struct Contact
//{
//	//将其封装在一起，方便传参
//	struct PeoInfo data[MAX];//创建一个存放1000个好友的信息的空间data
//	int size;//用来记录当前通讯录多少个好友信息
//};
struct Contact
{
	//由于此行声明一个MAX大小的数组，一次给它开辟了这么大的空间让它存1000人的信息
	//如果没有存1000个人的信息，则造成内存的浪费
	//如果想要保存超过1000个人的信息，又保存不了。导致使用空间的不灵活
	//改为动态增长的版本
	//默认可以放3个人的信息
	//当发现当前通讯录满的时候，进行扩容，每次增加2个空间

	struct PeoInfo* data;//创建一个存放1000个好友的信息的空间data
	int size;//用来记录当前通讯录多少个好友信息
	int capacity;//用来记录当前通讯录的容量最多能存多少好友信息
};


//声明初始化通讯录的函数
void InitContact(struct Contact *ps);
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
//void SortContact(struct Contact* ps);

void DestoryContact(struct Contact* ps);

//保存好友信息
void SaveContact(struct Contact* ps);
//加载文件中的信息到通讯录
void LoadContact(struct Contact* ps);