#define _CRT_SECURE_NO_WARNINGS 1
/*1������C���Թؼ���˵����ȷ���ǣ�*/
//A.�ؼ��ֿ����Լ�����
//��ȷ��B.�ؼ��ֲ����Լ�����
//C.�ؼ��ֿ�����������
//D.typedef���ǹؼ���

/*2������switch�����еĹؼ��ֲ������ĸ���*/
//��ȷ��A.continue
//B.break
//C.default
//D.if

/*3�������ĸ����ǹؼ��֣�*/
//A.int
//B.struct
//��ȷ��C.default //default����Ԥ����ָ��
//D.continue

/*4������ָ��˵����ȷ���ǣ�*/
//A.sizeof(char*)��Сһ����1
//��ȷ��B.ָ���Ǳ�����������ŵ�ַ
//C.ָ������Ĵ�С����4���ֽ�
//D.ָ�벻�Ǳ���

/*5������static˵������ȷ���ǣ�*/
//A.static�������ξֲ�����
//B.static��������ȫ�ֱ���
//��ȷ��C.static���εı������ܸı�
//D.static�������κ���

/*6���������Ľ���ǣ�*/
/*
#include <stdio.h>
int sum(int a)
{
	int c = 0;//�ֲ�����c���ӽ��룬���������������󣬱�����
	static int b = 3;//��static���εľֲ�����b���ӽ��룬����������������û������
	c += 1;
	b += 2;
	return (a + b + c);//a = 2,b = 5,c = 1// a = 2,b = 7,c = 1
}
int main()
{
	int i;
	int a = 2;
	for (i = 0; i < 5; i++)
	{
		printf("%d,", sum(a));
	}
	return 0;
}
*/
//A.6,8,10,12,14
//��ȷ���B.8,10,12,14,16
//C.10,12,14,16,18
//D.12,14,16,18,20

/*6���������ִ�еĽ���ǣ�*/
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)//�ж����������
	{
		if (i = 5)
			printf("%d ", i);
	}
	return 0;
}
*/
//A.1 2 3 4 5 6 7 8 9 10
//B.5 5 5 5 5 5 5 5 5 5 
//��ȷ���C.��ѭ���Ĵ�ӡ5
//D.0 1 2 3 4 5 6 7 8 9 

/*7������if���˵����ȷ���ǣ�*/
//A.if������ֻ�ܸ�һ�����
//B.if�����0��ʾ�٣�1��ʾ��
//��ȷ���C.if�����һ�ַ�֧��䣬����ʵ�ֵ���֧��Ҳ����ʵ�ֶ��֧
//D.else������Ǻ����Ķ����if���ƥ��

/*8������switch˵������ȷ���ǣ�*/
//A.switch����е�default�Ӿ���Է�������λ��
//B.switch����е�case��ı��ʽֻ�������ͳ������ʽ
//��ȷ���C.switch����е�case�Ӿ������default�Ӿ�֮ǰ
//D.switch����е�case���ʽ��Ҫ��˳��

/*9���������ִ�еĽ���ǣ�*/
/*
#include <stdio.h>
int func(int a)
{
	int b;
	switch (a)
	{
	case 1:
		b = 30;
	case 2:
		b = 20;
	case 3:
		b = 16;
	default:
		b = 0;
	}
	return b;
}
int main()
{
	printf("%d\n", func(1));
	return 0;
}
*/
//A.30
//B.20
//C.16
//��ȷ���D.0 

/*10��switch(c)����У�c��������ʲô����*/
//A.int
//B.long  
//C.char
//��ȷ���D.float 

/*11���������ִ�еĽ���ǣ�*/
/*
#include <stdio.h>
int main()
{
	int x = 3;
	int y = 3;
	switch (x % 2)
	{
	case 1:
		switch (y)
		{
		case 0:
			printf("first");
		case 1:
			printf("second");
			break;
		default:
			printf("hello");
		}
	case 2:
		printf("third");
	}
	return 0;
}
*/
//A.secondthird
//B.hello
//C.firstsecond
//��ȷ���D.hellothird

/*12��д���뽫���������Ӵ�С���*/
//˼·�������������Ƚϣ��ҵ������ϴ�ֵ���������ϴ�ֵ�бȽϣ�ȷ����Сֵ����Сֵ
//����a < b ��b��ֵ��a < c ��c��ֵ��b < c ��c��ֵ���b��ֵ��֮��a��ֵ��С
//��������������ֵ��ȷ�������п��������ֵ���м�ֵ����Сֵ�����Թ̶���ĳ�����洢���ֵ���м�ֵ����Сֵ
/*
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);//scanf�в��ӿո�ͼӿո�����ĸ�ʽ��һ����
	//ͨ������˳��ʵ�֣�a�����ֵ��b��֮��c����Сֵ
	if (a < b)
	{//a��b�Ƚϣ���b����a��b��ֵ��������ʱa��b�У�a��ֵ�ϴ�
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{//a��c�Ƚϣ���c����a��c��ֵ��������ʱa��c�У�a��ֵ�ϴ�
	 //a��b��c�У�a��ֵΪ���ֵ
		int temp = a;
		a = c;
		c = temp;
	}
	if (b < c)
	{//b��c�Ƚϣ���c����b��c��ֵ��������ʱb��c�У�b��ֵ��֮��c��ֵΪ��Сֵ
		int temp = b;
		b = c;
		c = temp;
	}
	//������a��b��c�ķ�ʽ��ӡ����a���b��֮��c��С
	printf("%d %d %d",a,b,c);
	return 0;
}
*/
//��������дһ����������������

/*13��дһ�������ӡ1-100֮������3�ı���������*/
//˼·��ѭ����1-100���жϣ�����3�������Ƿ�Ϊ0����Ϊ0����Ϊ3�ı���
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{//�ж�i�Ƿ�Ϊ3�ı���
		if (i % 3 == 0)
			printf("%d ", i);
	}
	return 0;
}
//��������
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 3; i <= 100; i+=3)
	{
			printf("%d ", i);
	}
	return 0;
}
*/

/*14�����������������������������Լ��*/
//˼·��
//����һ���Գ���
//�ҳ�����ͬʱ��������������������24 18��Ȼ��Ҫ�Ǹ�������
//���Լ�����ᳬ���������������Ľ�С����
//���ҳ����еĽ�Сֵ�����������������������ͬʱ����������������ӽ�Сֵ���μ������ٳ������������Ƿ�������ֱ��������
//����һ���ҵ���ͬʱ�������������������������һ�������Լ��
/*
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int max = 0;//���������Լ�����������Ľ�С����
	//�������Լ������m��n�Ľ�С��
	//int max = m > n ? n : m;
	if (m > n)
		max = n;
	else
		max = m;

	while (1)
	{
		if (m % max == 0 && n % max == 0)
		{
			printf("���Լ���ǣ�%d\n", max);
			break;
		}
		//����ͬʱ�������򣨴Ӵ�С������һ����
		max--;
	}

	return 0;
}
*/

//��ȣ�����С������
//�ҳ�����ͬʱ����������������������24 18��Ȼ��Ҫ�Ǹ���С����
//��С������һ���ᳬ���������������Ľϴ����
//���ҳ����еĽϴ�ֵ��Ȼ�������������ԣ��������ͬʱ������������������ӽϴ�ֵ���μӼӣ�Ȼ�����������������Ƿ�������ֱ��������
//����һ���ҵ���ͬʱ���������������������������һ������С������
/*
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d", &m, &n);
	int min = 0;//��������С���������������Ľϴ����
	//������С����������m��n�Ľϴ���
	if (m > n)
		min = m;
	else
		min = n;

	while (1)
	{
		if (min % n == 0 && min % m == 0)
		{
			printf("��С�������ǣ�%d\n", min);
			break;
		}

		//����д���Ǵ���ģ���Ϊmin��min * n == min * mִ��ǰ���Ѿ���������ˣ�min * n == min * m������ͬ��������һ����ͬ���������ԶΪ��
		//if ((min != 0) && (min * n == min * m))
		//{
		//	printf("��С�������ǣ�%d\n", min);
		//	break;
		//}
		
		//����ͬʱ���������򣨴Ӵ�һֱ������һ����
		min++;
	}

	return 0;
}
*/
//����֮�⣬����С�������Ĺ�ʽ����С������ = m * n / ���Լ��
//ʹ������С�������Ĺ�ʽ��Ȼ�������Լ�����з�װ��һ�������󣬽��е���

//��������շת�������m % n��������Ϊ�㣬��n��Ϊ��������������Ϊ������ȡģ�Ƿ�Ϊ0����Ϊ����������ϲ�����ֱ������Ϊ0�������Ϊ���Լ��
/*
#include <stdio.h>
int main()
{
	int m = 24;
	int n = 18;
	int r = 0;//��������
	scanf("%d%d", &m, &n);//�����������m��n������������У��ڶ��λụ����С�����޴�С˳��
	while (m % n) //����Ϊ0������Ϊ�٣������ѭ��
	{
		r = m % n;
		m = n;
		n = r;
	}
	printf("%d\n", n);
	return 0;
}
*/
//�����Ż���
/*
#include <stdio.h>
int main()
{
	int m = 24;
	int n = 18;
	int r = 0;
	scanf("%d%d", &m, &n);
	while (r = m % n)
	{	
		m = n;
		n = r;
	}
	printf("%d\n", n);
	return 0;
}
*/

/*14����ӡ1000��-2000��֮�������*/
//˼·���ж�ĳһ���Ƿ�Ϊ���꣬��ѭ���ж�1000-2000��������Ƿ�Ϊ����
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;//���ܷ����ж������
	for (year = 1000; year <= 2000; year++)
	{
		//�ж�year�Ƿ�Ϊ����
		//1.�ܱ�4�������Ҳ��ܱ�100����������
		//2.�ܱ�400����������
		//int count = 0;//���ܷ���������ӡcount�Ľ��������count��δ�����ı�ʶ��
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount = %d\n",count);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if((year % 4 == 0)&&(year % 100 != 0)||(year % 400 == 0))
		{
			printf("%d ", year);
			count++;

		}
	}
	printf("\ncount = %d\n",count);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if(year % 4 == 0)
		{
			if (year % 100 != 0)
			{
				printf("%d ", year);
				count++;
			}
		}
		if (year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount = %d\n",count);
 
	return 0;
}
*/

/*15��дһ�����룺��ӡ100-200֮�������*/
//˼·���ж�ĳһ���Ƿ�Ϊ��������ѭ���ж�100-200�������Ƿ�Ϊ����
//����һ���Գ������ж�����
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		//�ж�i�Ƿ�Ϊ����
		//�����жϵĹ���ֻ�ܱ�1������������ 
		//����2-��i-1�������֣�ȡ�Գ�i�����ܲ�������
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}		
		}
		//��������
	 	if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/
//�����Ż���
//i = a * b
//16 = 2 * 8 = 4 * 4�����ж�2����16���Ͳ���Ҫ�ж�8�Ƿ�����16�ˣ��������жϴ���
//����a/b������һ������ <= ��ƽ��i
/*
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		//�ж�i�Ƿ�Ϊ����
		//�����жϵĹ���
		//����2-��i-1�������֣�����i
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)//������sqrt--math.h
		{
			if (i % j == 0)
			{
				break;
			}		
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/
//���Ż���
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)//��ż��ֱ���޳�
	{		
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/

//����������ǩ��
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 101; i <= 200; i+=2)//��ż��ֱ���޳�
	{		
		int j = 0;
		int flag = 1;//����i��������
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;//���i�����������ı�����ֵ
				break;
			}
		}
		if (flag == 1)//flag��ֵû�иı䣬˵����i������
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}
*/