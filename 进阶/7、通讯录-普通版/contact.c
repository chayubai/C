#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//初始化通讯录
void InitContact(struct Contact* ps)
{
	//将data[1000]数组都初始化为0
	memset(ps->data, 0, sizeof(ps->data));//将data大小的字节空间的值全设置为0
	//将size初始化为0
	ps->size = 0;//设置通讯录最初只有0个元素
}

//增加好友信息
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)//当前元素个数 == 通讯录容量，则通讯录满了
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		//这里的添加本质上是对ps->data[ps->size]这个元素进行赋值操作，
		//即: 用元素中的成员变量接收scanf输入的值，并只是暂时保存在内存中
		//也就是说：只是临时保存到con中，当程序退出，con销毁，数据就没有了
		
		//将新增的好友信息放在下标为size的位置
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);//name是数组名
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);//tele是数组名
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);//addr是数组名
		//注意：由于数组名就是首元素的地址，不需要&

		ps->size++;//记录加1
		printf("添加成功\n");
	}
}

//打印好友信息
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		//打印所有好友信息
		int i = 0;
		//打印表头
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)//注意条件是i < ps->size，而不是i < 1000
		{
			//打印信息
			printf("%-20s\t%-20d\t%-20s\t%-20s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//对于删除、查找、修改功能都需要用到查找某个元素的信息，可以单独封装成为一个函数，减少代码冗余
//实现查找信息的函数，使用static只是用于对删除、查找、修改便利而创建的，
//而并不希望暴露这个接口，被其他文件使用，只能在当前contact.c所在的文件中使用，增加安全性.且定义函数需在使用之前。
//因此，也不需要把这个接口放在头文件中进行声明。
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//找到了返回名字所在元素的下标
		}
	}
	return -1;//找不到
}

//删除指定的好友信息
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1、查找要删除的人在什么位置
	//方法1：for遍历查找 方法2：qsort排序再二分查找 方法3：strstr函数匹配查找(只适用于字符串匹配查找)
	/*
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			break;
		}
	}
	//2、删除
	//break跳到这里有两种情况：1、找到了,i是对应要删除的元素 2、循环结束没找到
	if (i == ps->size)//没找到
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		//思路：将找到的信息为基点，后面的信息往前面覆盖
		//方法1：上面思路 方法2：memmove函数
		int j = 0;
		for (j = i; j < ps->size-1; j++)//注意条件，j < ps->size则会越界
		{
			//覆盖
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//元素个数减1，不要放在for循环里，否则最后一个删不了
		printf("删除成功\n");
	}
	//注意：这里删除最后一个元素是可以删除的，因为for循环进不去，直接--。
	//注意：删除名字相同的就可能会有问题
	*/

	//1、查找要删除的人在什么位置
	//找到了返回名字所在元素的下标
	//没找到返回-1
	int pos = FindByName(ps, name);//测试驱动开发 (Test- Driven Development), 简称TDD
	//2、删除
	//跳到这里有两种情况：1、找到了 2、循环结束没找到
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		//思路：将找到的信息为基点，后面的信息往前面覆盖
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)//注意条件，j < ps->size则会越界
		{
			//覆盖
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//元素个数减1
		printf("删除成功\n");
	}
}

//查找指定好友信息
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//1、查找要查找的人在什么位置
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查到人的信息不存在\n");
	}
	else
	{
		//找到了，即pos是该要查找的元素的下标，打印指定条件的好友信息
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-20d\t%-20s\t%-20s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

//指定要修改好友信息
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//1、查找要修改的人在什么位置
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		//找到了，即pos是该要查找的元素的下标，修改指定条件的好友信息
		//即重新输入一次，如果想要实现修改指定的数据，可以使用switch
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");
	}
}
//注意：添加的数据只是保存在内存中，当程序关闭了数据就没了，如果想保存数据，可借助数据库或文件

int comparePeoInfo_by_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}
int comparePeoInfo_by_name(const void* e1, const void* e2)
{
	//比较字符串，不能使用关系运算符，使用strcmp库函数，结果大于0，恰好返回大于0的数，结果小于0，返回小于0的数，等于0返回等于0的数。
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
void SortContact(struct Contact* ps)
{
	//输出
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("*******   1、按名字排序    2、按年龄排序    *******\n");
		int input = 0;
		printf("请选择一种方式排序：>");
		scanf("%d", &input);

		//int sz = sizeof(ps->data) / sizeof(ps->data[0]);//4 / 4 = 1，需要在函数外计算好，作为参数传入
		switch (input)
		{
		case 1:
			//传入compareStu_by_age的地址，先调用int(* compare)(const void* elem1, const void* elem2)，再指向具体的比较函数
			//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
			qsort(ps->data,ps->size, sizeof(ps->data[0]), comparePeoInfo_by_name);
			break;
		case 2:
			qsort(ps->data, ps->size, sizeof(ps->data[0]), comparePeoInfo_by_age);
			break;
		default:
			printf("选择错误\n");
			break;
		}
		//打印所有好友信息
		ShowContact(ps);
	}
}