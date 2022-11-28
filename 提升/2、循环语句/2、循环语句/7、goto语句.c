#define _CRT_SECURE_NO_WARNINGS 1
//C语言中提供了可以随意滥用的 goto语句和标记跳转的标号。
//如果有方法可以替代goto语句，不建议使用goto语句
/*
#include <stdio.h>
int main()
{
again:
	printf("hello bit\n");
	goto again;
	return 0;
}//死循环
*/
//goto语句会使得程序流程被打乱
/*
#include <stdio.h>
int main()
{
	printf("hello bit\n");
	goto again;
	printf("你好\n");
again:
	printf("hehe\n");
	return 0;
}
*/

//从理论上 goto语句是没有必要的，实践中没有goto语句也可以很容易的写出代码。
//但是某些场合下goto语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过程。
//例如：一次跳出两层或多层循环。
//多层循环这种情况使用break是达不到目的的。它只能从最内层循环退出到上一层的循环。
//goto语言真正适合的场景如下：
/*
for (...)
    for (...)
    {
        for (...)
        {
            if (disaster)
                goto error;
        }
    }
…
error :
    if (disaster)
        // 处理错误情况
*/
//break只能跳出自己的循环
//使用break跳出多个循环时，需要多个break，这样很繁琐。

//关机程序
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[10] = { 0 };
    //system()--执行系统命令--stdlib.h
    system("shutdown -s -t 60");//-s设置关机，-t设置时间
again:
    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
    scanf("%s", input);
    if (0 == strcmp(input, "我是猪"))//strcmp()--string compare--比较两个字符串---string.h
    {
        system("shutdown -a");//取消关机
    }
    else
    {
        goto again;
    }

    return 0;
}
*/
//用循环替换goto语句
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[10] = { 0 };
    system("shutdown -s -t 60");
    while (1)
    {
        printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
        scanf("%s", input);
        if (0 == strcmp(input, "我是猪"))
        {
            system("shutdown -a");
            break;
        }
    }
    return 0;
}
*/

//goto语句只能在一个函数范围内跳转，不能跨函数
/*
#include <stdio.h>
void test()
{
flag:
    printf("test\n");
}
int main()
{
    goto flag;//报错：引用了标签但是未对其进行定义
    return 0;
}
*/