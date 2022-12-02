#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//由于增容函数在后面定义，前面使用需声明
void CheckCapacity(struct Contact* ps);
//由于加载函数在后面定义，前面使用需声明
void LoadContact(struct Contact* ps);

//初始化通讯录
void InitContact(struct Contact* ps)
{
	//假设默认动态开辟3个空间(存储3个人的信息)，用data所指向，并维护
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	//判断是否开辟成功
	if (ps->data == NULL)
	{
		return;
	}
	//将size初始化为0
	ps->size = 0;//设置通讯录最初只有0个元素
	//将capacity初始化为3
	ps->capacity = DEFAULT_SZ;

	//把文件中已经存放的信息加载到通讯录中
	LoadContact(ps);
}

void LoadContact(struct Contact* ps)
{
	struct PeoInfo  tmp = { 0 };//临时存放读取的数据
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中
	//1、加载时，容量不够，存在扩容
	//2、加载什么时候结束
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))//fread返回值表示实际读取到的数据个数，当读取为0时结束
	{
		//判断，并增容
		CheckCapacity(ps);
		//加入数据
		ps->data[ps->size] = tmp;//将临时数据放入到通讯录中
		ps->size++;//元素加1
	}

	fclose(pfRead);
	pfRead = NULL;
}
//如何将信息写入数据库中 - C语言操作MySOL数据库

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//扩容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		//增容成功
		if (ptr != NULL)
		{
			ps->data = ptr;//仍用data维护
			ps->capacity += 2;//把容量标签改为增容后的值
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}
//增加好友信息
void AddContact(struct Contact* ps)
{
	//检测当前通讯录的容量
	//1、如果满了增加空间
	//2、如果不满，啥事都不干
	CheckCapacity(ps);

	//增加数据
	//将新增的好友信息放在下标为size的位置
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);
	//由于数组名就是首元素的地址，不需要&

	ps->size++;//记录加1
	printf("添加成功\n");

	//添加成功，同时保存到文件中
	//fwrite(&(ps->data[ps->size]), sizeof(struct PeoInfo), 1, pfWrite);//但是打开文件的方式必须是追加方式
	//或者调用fseek指向文件里的指针偏移到文件尾，在添加
	SaveContact(ps);//添加成功就保存，效率低
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
		for (i = 0; i < ps->size; i++)//注意条件
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
//并不希望其他地方的函数使用他，只能在所在的文件中使用，增加安全性.且定义函数需在使用之前。
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//找不到
}

//删除指定的好友信息
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1、查找要删除的人在什么位置
	/*int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			break;
		}
	}*/

	//2、删除
	//跳到这里有两种情况：1、找到了,i是对应要删除的元素 2、循环结束没找到
	//if (i == ps->size)
	//{
	//	printf("要删除的人不存在\n");
	//}
	//else
	//{
	//	//删除数据
	//	//思路：将找到的信息为基点，后面的信息往前面覆盖
	//	int j = 0;
	//	for (j = i; j < ps->size-1; j++)//注意条件，否则会越界
	//	{
	//		//覆盖
	//		ps->data[j] = ps->data[j + 1];
	//	}
	//	ps->size--;//元素个数减1
	//	printf("删除成功\n");
	//}
	//注意：这里删除最后一个元素，或者删除名字相同的就可能会有问题

	//1、查找要删除的人在什么位置
	//找到了返回名字所在元素的下标
	//没找到返回-1
	int pos = FindByName(ps, name);
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
		for (j = pos; j < ps->size - 1; j++)//注意条件，否则会越界
		{
			//覆盖
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//元素个数减1
		printf("删除成功\n");
	}

	//删除成功后，并保存
	SaveContact(ps);//效率低
	//同时不能使用单一保存的方式进行保存。
}

//查找指定好友信息
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//1、查找要的人在什么位置
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
	//1、查找要的人在什么位置
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

		//修改成功后，并保存
		SaveContact(ps);//效率低
		//同时不能使用单一保存的方式，将具体修改的数据，仍存放到文件的原始位置。
		//文件只能追加到后面，但是文件中原始的那条数据还在

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

		switch (input)
		{
		case 1:
			//传入compareStu_by_age的地址，先调用int(* compare)(const void* elem1, const void* elem2)，再指向具体的比较函数
			qsort(ps->data, ps->size, sizeof(ps->data[0]), comparePeoInfo_by_name);
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

void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps -> data = NULL;
 }

//保存文件-即写文件
void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;//由于此函数没有返回值，故return即可
	}
	//写通讯录中的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//将&(ps->data[i])地址处的信息，信息大小为sizeof(struct PeoInfo)，一次写一个到pfWrite所指向的文件中
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	//可以使用fwrite(p->data, sizeof(struct PeoInfo), p->size, pfWrite);
	fclose(pfWrite);
	pfWrite = NULL;
}

//扩展：C语言操作MySQL数据库