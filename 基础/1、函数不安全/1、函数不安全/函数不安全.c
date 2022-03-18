/*第一个C语言程序*/
//1、创建一个新项目
//2、项目里创建一个源文件
//3、写C语言代码
//4、编译和运行代码

/*写代码：*/
/*基本框架：写出主函数（main函数）*/
/*
int main()
{
	//这里完成任务
	return 0;
}
*/
//解读：
//main函数：函数的书写格式“函数名()”，C语言是从主函数的第一行开始执行，主函数是程序的入口，mian函数，必须有且仅有一个
//如何证明main函数时程序的入口：Fn+F10,可实现主函数内单步执行，每按一次执行一句代码，可知程序的执行时从main函数的第一行开始执行
//int main()：int是整型类型，main是函数名，main前面的int表示main函数调用之后，返回类型为一个整型值
//{......}：表示函数体，用来完成任务
//return 0：与前面的int呼应，表示返回整数0，每一句都以英文的分号结束
/*
void main()
{
	//这里完成任务
}
*/
/******这是一种过时的写法******/

/*问题：在屏幕上打印“hello world！--你好，世界！”*/
//#include <stdio.h>//使用printf函数，引用此头文件
//int main()
//{
//	printf("hello world!--你好，世界！\n");
// 
//	return 0;
//}
//解读：
//printf函数-print function：报错“printf未定义”，printf是C语言提供的一个库函数--打印函数，如果要使用printf时，需要引用头文件stdio.h--standard input output，即，包含一个叫stdio.h的文件
//编译+链接+运行代码：Ctrl+F5/Fn+Ctrl+F5，或者单击“调试”选项卡，选择“开始执行（不调试）”
//如果显示结果一闪而过怎么解决,针对vs2013，vs2019不需要设置：
//（每创建一个新项目都需要设置属性）由于程序执行太快，为了看到结果，可设置一下属性，单击项目名称右键-->选择“属性”-->在“配置属性”下选择“链接器”-->在“链接器”下单击“系统”-->在“子系统”中选择“控制台”-->应用--确定
//或者在return 0;上一行（倒数第二行），添加System("pause")，此时需要引用头文件,#include <stdlib.h>，否则报错：“system”未定义错误

/*常见问题：*/
//1、函数“int main()”(已有主体)：一个工程中出现了多个main函数。注意：一个工程中可以有多个.c文件，但多个.c文件只能有一个main函数
//2、使用scanf()报错：'scanf':This function or variable may be unsafe, use“_CRT_SECURE_NO_WARNINGS ”，即第一行添加#define _CRT_SECURE_NO_WARNINGS 1
//3、vs报错函数还有，scanf、strcpy、strcat、sscanf、fopen...这些函数不安全

/*问题：为什么函数不安全*/
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	char arr[5] = { 0 };//arr数组中只能放5个字符
//	scanf("%s",arr);//输入的时候超过5个字符
//	printf("%s\n",arr);
//
//	return 0;
//}

//当输入大于5个字符时，报错Run-Time Check Failure #2 - Stack around the variable 'arr' was corrupted.“空间被破坏，数组越界访问”
//函数或变量不安全的原因：scanf函数对空间的读取，不关心空间大小，把所有的输入字符全部放入arr数组，arr数组越界，栈空间被破坏所以scanf函数不安全，即没有空间越界判断
//报错提示信息：error C4996：'scanf':This function or variable may be unsafe, Consider using scanf_s instead,To disable deprecation,use“_CRT_SECURE_NO_WARNINGS ”，即第一行添加#define _CRT_SECURE_NO_WARNINGS

//解决方法：
//1、考虑使用scanf_s()函数，级将scanf函数替换为vs提供的scanf_s函数，注意：scanf_s函数不是C语言提供的，不具备跨平台性，对其他编译器不兼容
//2、定义预定义符号：每新建一个源文件都要添加这行代码，#define __CRT_SECURE_NO_WARNINGS 1
//3、在vs的安装路径下找到newc++file.cpp文件(在VC下搜索newc++file即可)，在该文件里添加一行代码#define __CRT_SECURE_NO_WARNINGS 1，使用notepad++编辑并保存以后创建的新文件都会自动生成这一句代码
//4、设置项目属性的预处理：单击项目名称右键，选择“属性”，在“配置属性”中选择“C/C++”，在“C/C++”中选择“预处理器”，在“预处理器定义”中添加“;_CRT_SECURE_NO_WARNINGS”，注意：每个项目中都要设置
//5、在创建项目的时候关闭安全提示：“文件”选项卡，单击“新建”，选择“项目”后，选择以“控制台应用”创建源文件，单击“下一步”，取消勾选“预编译头”和“安全开发生命周期检查”，单击“完成”，注意：此方法虽然会出现警告，但不会报错，不影响运行

//其他函数的不安全报错例子，解决方案同理
//#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[10] = { 0 };
//	strcpy(arr, "hello");//拷贝hello，放入arr中，使用strcpy函数，需要引用#include <string.h>头文件
//	printf("%s\n", arr);
//
//	return 0;
//}