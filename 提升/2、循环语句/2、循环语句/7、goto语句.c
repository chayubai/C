#define _CRT_SECURE_NO_WARNINGS 1
//C�������ṩ�˿����������õ� goto���ͱ����ת�ı�š�
//����з����������goto��䣬������ʹ��goto���
/*
#include <stdio.h>
int main()
{
again:
	printf("hello bit\n");
	goto again;
	return 0;
}//��ѭ��
*/
//goto����ʹ�ó������̱�����
/*
#include <stdio.h>
int main()
{
	printf("hello bit\n");
	goto again;
	printf("���\n");
again:
	printf("hehe\n");
	return 0;
}
*/

//�������� goto�����û�б�Ҫ�ģ�ʵ����û��goto���Ҳ���Ժ����׵�д�����롣
//����ĳЩ������goto��仹���õ��ŵģ�������÷�������ֹ������ĳЩ���Ƕ�׵Ľṹ�Ĵ�����̡�
//���磺һ�������������ѭ����
//���ѭ���������ʹ��break�Ǵﲻ��Ŀ�ĵġ���ֻ�ܴ����ڲ�ѭ���˳�����һ���ѭ����
//goto���������ʺϵĳ������£�
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
��
error :
    if (disaster)
        // ����������
*/
//breakֻ�������Լ���ѭ��
//ʹ��break�������ѭ��ʱ����Ҫ���break�������ܷ�����

//�ػ�����
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[10] = { 0 };
    //system()--ִ��ϵͳ����--stdlib.h
    system("shutdown -s -t 60");//-s���ùػ���-t����ʱ��
again:
    printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
    scanf("%s", input);
    if (0 == strcmp(input, "������"))//strcmp()--string compare--�Ƚ������ַ���---string.h
    {
        system("shutdown -a");//ȡ���ػ�
    }
    else
    {
        goto again;
    }

    return 0;
}
*/
//��ѭ���滻goto���
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
        printf("���Խ���1�����ڹػ���������룺��������ȡ���ػ�!\n������:>");
        scanf("%s", input);
        if (0 == strcmp(input, "������"))
        {
            system("shutdown -a");
            break;
        }
    }
    return 0;
}
*/

//goto���ֻ����һ��������Χ����ת�����ܿ纯��
/*
#include <stdio.h>
void test()
{
flag:
    printf("test\n");
}
int main()
{
    goto flag;//���������˱�ǩ����δ������ж���
    return 0;
}
*/