#define _CRT_SECURE_NO_WARNINGS 1

//�����ķ���
//1�����泣����ûɶʵ�����壩�磺3.14��10����a������abcde��
//2��const���εĳ�����

/*
#include <stdio.h>
int main()
{
	int num = 10;
	num = 20;
	printf("num = %d\n", num);//numΪ�����������Ըı����
	return 0;
}
*/

//const���εı����ǲ��ܸı��
/*
#include <stdio.h>
int main()
{
	const int num = 10;//numΪ��������const���εĳ�����
	num = 20;//������ֵָ��const���󣬼���ߵı�����const���Σ���ֵ���ܱ��޸�
	printf("num = %d\n", num);
	return 0;
}
*/
//���������г����ԣ������ܱ��ı������

/*
#include <stdio.h>
int main()
{
	int arr[10] = {0};//arr����10��Ԫ�أ�ÿ��Ԫ��Ϊ��������
	int n = 10;
	int arr2[n] = {0};//����Ӧ���볣�����ʽ��˵��n�Ǳ���

	return 0;
}
//������Ҳ�Ǳ���
#include <stdio.h>
int main()
{
	const int n = 10;
	int arr2[n] = {0};//�������ʽ���뺬�г���ֵ��Ӧ���볣�����ʽ��˵��n�Ǳ��������г�����
	return 0;
}
*/

//3��#define����ı�ʶ������
/*
#include <stdio.h>
#define Max 10000//��βû�зֺţ�����������������⣬�����ܷ���#include <stdio.h>ǰ
int main()
{
	//Max = 2000;//���������޸�
	int n = Max;
	printf("n = %d\n", n);

	return 0;
}
*/
/*
#include <stdio.h>
#define Max 10
int main()
{
	int arr[Max];//���棺��arr��δ���õľֲ���������arr����δ��ʼ������arr[Max]��ʼ������int arr[Max] = {0};
	//˵����Max�ǳ���
	return 0;
}
*/

//4��ö�ٳ���������һһ�оٵĳ������磺Ѫ�͡����ڡ��Ա�
//ö�ٹؼ���--enum
/*
#include <stdio.h>
enum Sex//Sex��ö�ٱ���
{	//���Ա�Ŀ���ȡֵһһ�оٳ���
	MALE,
	FEMALE,
	SECRET
	//��Щ��ö�ٳ�����������ö�����ͣ�����Ϊenum Sex�������ı������磺s����δ�����ܵ�ȡֵ
};//��βҪ�ֺ�
int main()
{
	enum Sex s = MALE;//s ����ö�����ʹ����ı���
	printf("%d\n", MALE);//0
	printf("%d\n", FEMALE);//1
	printf("%d\n", SECRET);//2
	//ö�ٳ�����ֵĬ�ϴ�0��ʼ
	return 0;
}
*/
//���磺
/*
#include <stdio.h>
enum Color
{
	RED = 4,//���Ը���ֵ
	YELLOW,
	BULE
};
int main()
{
	enum Color color = BULE;
	color = YELLOW;
	//BLUE = 6;������=�������������Ϊ��ֵ����ö�ٳ������ܸı��С

	return 0;
}
*/