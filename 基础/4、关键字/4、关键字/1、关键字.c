//����C�������õĹؼ��֣�
// 1��C�����ṩ�ģ������Լ������ؼ���
// 2���ؼ��ֲ�����������
//auto��break��case��char��const��continue��default��do��double��else��enum��
//extern��flaot��for��goto��if��int��long��register��return��short��signed��
//sizeof��static��struct��switch��typedef��union��unsigned��void��volatile��while
/*
#include <stdio.h>
int main()
{
	//auto--�Զ��ģ�ÿ���ֲ���������auto���ε�
	{
		int a = 10;//a���ֲ�����һ�㣩�Զ��������Զ����� --�Զ�������һ�㶼ʡȥauto
		auto int a = 10;
	}
	return 0;
}
*/
//break��ѭ����䣬��switch-case�����
//case��switch-case���
//const�����εĳ�����
//continue��������ѭ����ʹ��
//default��Ĭ�ϣ�switch-case���
//do��do-whileѭ��
//else��if-else���
//enum��ö�ٹؼ���
//extern������//�����ⲿ����
//goto��goto���
//register���Ĵ����ؼ���
/*
#include <stdio.h>
int main()
{
	//��������ݴ��λ�ã��Ĵ��������ٻ��棬�ڴ棬Ӳ��
	register int num = 100;//��a����ɼĴ���������
	//����num��ֵ����ڼĴ����У������Ƿ����Ĵ����У��ɱ���������
	//Ϊʲô��������뵽�Ĵ����У��ڴ��ȡ�ٶ�����CPU�ٶȿ죬���Ĵ����ٶȱ��ڴ�죬������Ƶ�������ݽ������Ĵ�����-�����CPU�Ľ����ٶ�

	return 0;
}
*/
//signed���з��ŵģ�unsigned���޷��ŵ�
/*
#include <stdio.h>
int main()
{
	int a = 10;//int����ı������з��ŵģ�ԭ��Ϊsigned int
	signed int a = 10��
	a = -2;
	unsigned int num = -1;//num�Ľ����Ϊ1
	return 0;
}
*/
//static����̬�ģ����������α����ͺ�����
//1��static���ξֲ�����-��̬�ֲ�����--�ı��˱�������������
//2��static����ȫ�ֱ���-��̬ȫ�ֱ���--�ı��˱�����������
//3��static���κ���-��̬����--�ı��˺�������������
/*1��
#include <stdio.h>
void test()
{
	int a = 1;//a�Ǿֲ��������ص㣺����ʱ��a��������ȥʱ��a����
	a++;
	printf("%d ",a);
} 
int main()
{
	int i = 0;
	while (i < 10)
	{
		test();//ÿ���ú�����a���´������ٴ�����
		i++;
	}
	return 0;
}
//�����2 2 2 2 2 2 2 2 2 2
*/
/*
#include <stdio.h>
void test()
{
	static int a = 1;//a��static���εľֲ��������ص㣺����ʱ��a��������ȥʱ��aû������
	a++;
	printf("%d ", a);//2
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		test();//aû�д�����û������
		i++;
	}

	return 0;
}
//�����2 3 4 5 6 7 8 9 10 11
//���Թ۲�i��a�ı仯
//static���ξֲ��������ֲ��������������ڱ䳤
//static���εľֲ��������ı��˾ֲ��������������ڣ��������Ǹı��˱����Ĵ洢���ͣ� ���þ�̬�ľֲ�����������������Ȼ���ڣ�������������������ڲŽ���
//�ڴ��Ϊ�������򣬲�ͬ�������в�ͬ���ص㣨1��ջ�����洢���Ǿֲ������������Ĳ�����2���������洢���Ƕ�̬�ڴ����ģ�3����̬�����洢����ȫ�ֱ�����static���εľ�̬����
//��a����û�б�static����ʱ���洢��ջ������static����ʱ�洢�ھ�̬�����ı��˴洢����
//static���εľ�̬�������������ں�ȫ�ֱ�������������һ�������������������������
*/
/*2��
//�½�һ��Դ�ļ���add.c,����һ�д��룺int g_val = 2020;//ȫ�ֱ���
//��test.cԴ�ļ�ʹ��g_val
#include <stdio.h>
//extern�����ⲿ����
extern int g_val;//����g_val��ʶ��
int main()
{
	printf("%d\n", g_val);//����"g_val":Ϊδ�����ı�ʶ��.����������ⲿ����extern int g_val;

	return 0;
}
*/
/*
//��add.c�ļ�����static����int g_val = 2020;����static int g_val = 2020;
//��test.cԴ�ļ�ʹ��g_val
#include <stdio.h>
extern int g_val;
int main()
{
	printf("%d\n", g_val);//�����޷��������ⲿ����g_val

	return 0;
}
//static����ȫ�ֱ������þ�̬��ȫ�ֱ���ֻ�������ڵ�Դ�ļ��ڲ�ʹ�ã�����Դ�ļ����޷���ʹ��
//ȫ�ֱ�����������Դ�ļ��ڲ����Ա�ʹ�ã�����Ϊȫ�ֱ��������ⲿ��������
//���Ǳ�static����֮�󣬾ͱ�����ڲ��������ԣ�����Դ�ļ��Ͳ������ӵ������̬��ȫ�ֱ���
*/
/*3��*/
//�½�һ��Դ�ļ���add.c,�������:
/*
	int Add(int x,int y)
	{
		int z = x + y;
		return z;
	}
*/
/*
//��test.cԴ�ļ�ʹ��Add()
#include <stdio.h>
//extern�����ⲿ����
extern int Add(int, int);//����extern int Add(int x,int y);//����Add()
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);//����"Add"δ���塣����������ⲿ����
	printf("sum = %d\n", sum);
	return 0;
}
*/
//��add.c�ļ�����static����
/*
	static int Add(int x,int y)
	{
		int z = x + y;
		return z;
	}
*/
/*
//��test.cԴ�ļ�ʹ��Add()
#include <stdio.h>
extern int Add(int, int);//����extern int Add(int x,int y);
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);//�����޷��������ⲿ����_Add������_main�������˸÷���
	printf("sum = %d\n", sum);
	return 0;
}
//static���κ������ı��˺������������ԣ�ʹ�ú���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ�ã�����������Դ�ļ��ڲ�ʹ��
//�����ϣ���ͨ���������ⲿ�������ԣ�static�ǽ��������ⲿ�������Ա�����ڲ��������ԣ���static����ȫ�ֱ���һ����
*/
//struct���ṹ��ؼ���
//switch��switch-case���
//typedef�����Ͷ���/����������--type define
/*
#include <stdio.h>
typedef unsigned int u_int;//��unsigned int ����ȡ��һ������/������u_int�����Ͳ���
int main()
{
	unsigned int num1 = 100;//num������unsigned int̫���ӣ����¶���һ������
	u_int num2 = 100;//u_intҲ��һ��������
	//num1��num2������������һ����
	return 0;
}
*/
//union��������/������
//void����/��
//volatile������C���Զ�λ�Ĺؼ���

//ע�⣺define��include���ǹؼ��֣�������Ԥ����ָ��
/*#define���峣���ͺ�*/
/*
//1��define�����ʶ������
#define MAX 1000
//2��define�����
#define ADD(x,y) ((x)+(y))//��ADD(x,y)���滻�� ((x)+(y))--(x)�ͣ�y�����������ʽ
#define SUM(a,b) a+b//��ADD(a,b)���滻�� a+b
#include <stdio.h>
int mian()
{
	printf("%d\n", MAX);
	int sum = SUM(2, 3);//2+3=5
	printf("sum = %d\n", sum);
	int c = ADD(2, 3);//((2)+(3))=5
	printf("%d\n",c);
	sum = 10 * SUM(2, 3);//10*2+3=23
	printf("sum = %d\n", sum);
	int c = 10 * ADD(2, 3);//10*((2)+(3))=50
	printf("%d\n",c);

	return 0;
}
*/
/*
//�ú���ʵ���������Ĵ�С��
#include <stdio.h>
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a, b);
	printf("max = %d\n",max);

	return 0;
}
*/
/*
//�ú�ʵ���������Ĵ�С��
#define Max(X,Y) (X>Y?X:Y)//��Max(X,Y)���滻�� (X>Y?X:Y)
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int max = Max(a, b);//���滻��a>b?a:b
	printf("max = %d\n",max);

	return 0;
}
*/