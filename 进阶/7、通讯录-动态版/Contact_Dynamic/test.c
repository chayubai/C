#define _CRT_SECURE_NO_WARNINGS 1
//枚举用在选择模式，描述信息用结构体
//1、存放1000个好友的信息
//信息包含：名字、电话、性别、住址、年龄
//2、增加好友信息
//3、删除指定名字的好友信息
//4、查找好友信息
//5、修改好友信息
//6、打印好友信息
//7、排序
#include "contact.h"
void menu()
{
	printf("***************************************************\n");
	printf("********   1、add              2、del     *********\n");
	printf("********   3、search           4、modify  *********\n");
	printf("********   5、show             6、sort    *********\n");
	printf("********   0、exit                        *********\n");
	printf("***************************************************\n");

}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//定义一个通讯录con，包含data指针和size、capacity
	//初始化通讯录
	InitContact(&con);//1、结构体传址效率高 2、传址方便改变函数外部某些变量的值
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
			//当case越多，可读性越差，使用枚举常量增加可读性
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);//尽管打印信息不会改变con的值，但使用传址效率更高
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			//销毁通讯录-释放动态开辟的内存
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}