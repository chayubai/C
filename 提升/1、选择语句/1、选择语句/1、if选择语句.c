#define _CRT_SECURE_NO_WARNINGS 1

//C�����ǽṹ���ĳ���������ԣ�
//˳��ṹ
//ʲô����䣿C��������һ���ֺţ������ľ���һ����䣬�磺; ����䡢1 + 2��
//#include <stdio.h>
//int main()
//{
//	;//�����
//	return 0;
//}

//ѡ��ṹ--��֧���if/switch
//C��������α�ʾ��ͼٵ��أ���0��ʾ�棬0��ʾ��
//���ʽΪ��ʱ�����ִ��
//1������֧���
//�﷨�ṹ��
//if(���ʽ)
//	��䣻

//���ӣ�
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age < 18)
//		printf("δ����\n");
//	return 0;
//}

//2��˫��֧���
// �﷨�ṹ��
//if(���ʽ)
//	���1��
//else
//	���2��

//����1��
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//		printf("δ����\n");
//	else
//		printf("����\n");
//	return 0;
//}
// 

//����2��
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age >= 18)
//		printf("����\n");
//	else 
//		printf("δ����\n");
//		printf("����̸����\n");
//
//	return 0;
//}
//��������:
//ִ�н����
// ����
// ����̸����

//�ܽ᣺
//û�д����ţ�ֻ�ܹ���һ�����.��Ҫ���ƶ�����䣬�ô��������Ʒ�Χ.
// �������������Ҫִ�ж�����䣬Ӧ��ʹ�ô���飬һ��{ }����һ�������
//#include <stdio.h>
//int main()
//{
//	if (���ʽ)
//	{
//		����б�1��
//	}
//	else
//	{
//		����б�2��
//	}
//	return 0;
//}
//�磺����֧���
//#include <stdio.h>
//int main()
//{
//	int age = 20;
//	if (age < 18)
//	{
// 		printf("δ����\n");
//	}
//	return 0;
//}
//���磺˫��֧���
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//	{
//		printf("δ����\n");
//	}
//	else
//	{
// 		printf("����\n");
//	}
//	return 0;
//}
//�޸ĺ�Ĵ��룺
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	if (age >= 18)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("δ����\n");
//		printf("����̸����\n");
//	}
//	return 0;
//}
//���磺���֧���
//#include <stdio.h>
//int main()
//{
//	int age = 10;
//	if (age < 18)
//	{
//		printf("����\n");
//	}
//	else if(age > 18 && age < 26)
//	{
//	 	printf("������\n");
//	}
//	return 0;
//}

//3�����֧���
//�﷨�ṹ��
//if(���ʽ1)
//	���1��
//else if(���ʽ2)
//	���2��
//else
//	���3��

//���ӣ� 
//#include <stdio.h>
//int main()
//{
//	int age = 60;
//	if (age < 18)
//		printf("����\n");
//	else if (18 <= age < 26)
//		printf("����\n");
//
//	return 0;
//}
//��ӡ���������
//���������
//age = 60����18 <= age ����������Ϊ����Ϊ1��1 < 26�������������Ϊ�棬ִ����䣬��ӡ�����ꡱ
//�޸Ĵ��룺
//#include <stdio.h>
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	if (age < 18)
//	{
//		printf("����\n");
//	}
//	//else if (age >= 18 && age < 26)
//	else if (18 <= age && age < 26)//�˷�ʽ���Լ���bug
//	{
//		printf("����\n");
//	}
//	else if (age >= 26 && age < 40)
//	{
//		printf("����\n");
//	}
//	else if (age >= 40 && age < 60)
//	{
//		printf("׳��\n");
//	}
//	else if (age >= 60 && age < 100)
//	{
//		printf("����\n");
//	}
//	//else
//	//{
//	//	printf("�ϲ���\n");//���һ��else���Բ�д��else�Ǳ���
//	//}
//	return 0;
//}

//ifǶ��
//#include <stdio.h>
//int main()
//{
//	int age = 60;
//	if (age < 18)
//		printf("����\n");
//	else
//	{
//		if (18 <= age < 26)
//			printf("����\n");
//	}
//	return 0;
//}

//����else
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//	else
//		printf("haha\n");
//	return 0;
//}
//������:��
//�������룺
//a = 0������1�����Ϊ��
//�ܽ᣺
//else �����δƥ���if����ƥ��
//���������ͬ��
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	return 0;
//}
//Ҳ��ͬ�ڵ���֧���
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	return 0;
//}
//�����hehe
//�ܽ᣺����Ĵ�����д����Ҫ���ʵ�ʹ��{ }����ʹ������߼��������
//������
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//	{
//		if (b == 2)
//		{
//			printf("hehe\n");
//		}
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}

//�磺
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if (num == 5)//= ��ֵ���ţ�== �ж����
//	{
//		printf("hehe\n");
//	}
//}
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if (num = 5)//����û�б���
//	{
//		printf("hehe\n");
//	}
//}
//���鳣��������ߣ���д��if(5 == num)������д��һ����=��ʱ���ͻᱨ��������д���ã����ٴ���ʧ�����ڼ�����
//#include <stdio.h>
//int main()
//{
//	int num = 4;
//	if(5 == num)
//	{
//		printf("hehe\n");
//	}
//}


//if��д��ʽ�ĶԱ�
//1������1
//if (condition) {
//	return x;
//}
//return y;
//2������2
//if (condition)
//{
//	return x;
//}
//else
//{
//	return y;
//}
//����1�ʹ���2������˼��ͬ�������������㷵��x�����������㷵��y����Ϊֻ����һ������ֵ
//���磺
//#include <stdio.h>
//int test() 
//{
//	if (1)
//		return 0;
//	printf("hehe\n");
//	return 1;
//}
//int main()
//{
//	test();
//	return 0;
//}
//������գ�����0����ִ��printf����return 1��
//�ܽ᣺������Կɶ��Ժ���Ҫ
//#include <stdio.h>
//int test()
//{
//	if (0)
//		return 0;
//	//printf("hehe\n");
//	return 1;
//}
//int  main()
//{
//	test();
//	return 0;
//}
//������գ�����0--����������0
//���Բ鿴�������ִ�й��̣���Fn+F11
 
//��ϰ��
/*1���ж�һ�����Ƿ�Ϊ����*/
//˼·���жϳ���2֮��������ȡģ���Ƿ�Ϊ0����Ϊ0����������������ż��
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	if (num % 2 != 0)
//	{
//		printf("%d������", num);
//	}
//	return 0;
//}

/*2�����1-100֮�������*/
//˼·��ѭ���ж�1-100�����Ƿ�Ϊ����
//#include <stdio.h>
//int main()
//{
	/*int num = 0;
	int count = 0;
	for (num = 1; num <= 100; num++)
	{
		if (num % 2 == 1)
		{
			printf("%d ", num);
			count++;
		}
	}
	printf("\ncount = %d\n", count);*/

	/*for (num = 1; num <= 100; num += 2)
	{
		printf("%d ", num);
	}*/
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 1;
//	while (num <= 100)
//	{
//		printf("%d\n", num);
//		num += 2;
//	}
//	return 0;
//}

//ע����forѭ���У������Ķ���ͳ�ʼ��
//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	for (int num = 1; num <= 100; num++)
//	//�ڣ� ���ڶ��������C++�����֧��C99��׼�ı�������֧�����ֶ���
//	{
//		printf("%d ", num);
//	}
//	return 0;
//}

//��ϰ��
/*�ж�һ�������Ƿ��ܱ�5����*/
//�����������������һ������M(1 <= M <= 100000)
//����������������һ�У����M���Ա�5���������YES���������NO
//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	if (m % 5 == 0)
//		printf("YES");
//	else
//		printf("NO");
//	return 0;
//}