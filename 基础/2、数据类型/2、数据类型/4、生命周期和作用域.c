#define _CRT_SECURE_NO_WARNINGS 1
//������������

//�ֲ�������������
/*
#include <stdio.h>
int main()
{
	int num = 0;
	printf("%d\n", num);//����������У�˵��num����������{ }�����ʹ��
	//��num�����������������{ }��
	return 0;
}
*/

/*
#include <stdio.h>
int main()
{
	{
		int num = 0;
	}
	
	printf("%d\n", num);//���������У�����numδ�����ı�ʶ��,˵��num�������������ڵ�{ }�����ʹ��
	//��num����������������{ }�ڵ�{ }��
	return 0;
}
#include <stdio.h>
int main()
{
	{
		int num = 0;
		printf("%d\n", num);
	}
	//��ʱ�������������
	return 0;
}
*/

//ȫ�ֱ�����������
/*
#include <stdio.h>
int g_val = 2021;//ȫ�ֱ���
//printf("2:%d\n", g_val);//����ִ�����������ں�����

int main()
{
	printf("1:%d\n", g_val);//ȫ�ֱ�������������������
	printf("��ӡ�ַ�a\n");
	{
		int a = 10;//�ֲ�����
		printf("a = %d\n", a);//�ֲ������������򣺾��Ǳ������ڵľֲ���Χ
		printf("2:%d\n", g_val);//ȫ�ֱ�������������������
	}
	//printf("a = %d", a);//���б����ֲ������������򣺾��Ǳ������ڵľֲ���Χ
	printf("3:%d\n", g_val);//ȫ�ֱ�������������������

	return 0;
}
*/

//���磺
//1���纯��ʹ��ȫ�ֱ���
/*
#include <stdio.h>
int global = 2020;//ȫ�ֱ���
 void test()
 {
	printf("test()-%d\n",global);//ȫ�ֱ�������������������
 }
int main()
{
	test();
	printf("%d\n",global);//ȫ�ֱ�������������������

	return 0;
}
*/

//2�����ļ�ʹ��ȫ�ֱ���
//����add.c�ļ�	//��ͼ-���������Դ������-Դ�ļ�-�½���-C++�ļ���.cpp��-������.c��β
//����add.c�ļ�����ӡ�int g_val = 2022;��������.c�ļ��У���ӡ��ʹ�ñ���g_val��
/*int g_val = 2022;//g_val��ȫ�ֱ���*/
//��test.c�ļ� //��test.c�ļ���ʹ��g_val,��ʱ������g_val����δ�����ı�ʶ��
/*
#include <stdio.h>
int main()
{
	printf("g_val = %d", g_val);
	return 0;
}
*/
//������g_val����δ�����ı�ʶ��

//�����޸ģ�
/*
#include <stdio.h>
//extern�����ⲿ����
extern int g_val;//����add.c�ļ����ⲿ�ļ����ı�������Ըñ�����������
int main()
{
	printf("g_val = %d", g_val);//������������
	return 0;
}
*/

//�������������ڣ������Ĵ���������֮���ʱ���
/*
#include <stdio.h>
int main()//ȫ�ֱ��������������ǣ�main�������������ڣ������������������
{
	{//����ֲ���Χ������ʼ
		int a = 10;//�ֲ�����
		printf("%d\n", a);//�ֲ����������������ǣ�����ֲ���Χ������ʼ�����ֲ���Χ��������
	}//���ֲ���Χ��������
	//printf("%d\n", a);//��������a���ֲ���Χ��������
	 
	return 0;
}
*/

//���磺
/*
#include <stdio.h>
void test()
{
	int b = 20;//�ֲ���������������test()������
}
int main()
{
	int a = 10;//�ֲ���������������main������

	return 0;
}
*/