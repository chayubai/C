#define _CRT_SECURE_NO_WARNINGS 1
//ָ��ĸ�� 
//1. ָ����Ǹ�������������ŵ�ַ����ַΨһ��ʶһ���ڴ�ռ䡣
//2. ָ��Ĵ�С�ǹ̶���4 / 8���ֽڣ�32λƽ̨ / 64λƽ̨����
//3. ָ���������ͣ�ָ������;�����ָ��� +/-�����Ĳ�����ָ������ò�����ʱ���Ȩ�ޡ�
//4. ָ������㣺ָ��+/-������ָ���ϵ���㡢ָ��-ָ��
/*
#include <stdio.h>
void test(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);//sz = 4 / 4 = 1
	//����sizeof(arr) = 4���ֽڣ�����Ԫ�ص�ַ�Ĵ�С��sizeof(arr[0]) = 4���ֽڣ���һ��Ԫ�صĴ�С
	printf("%d\n", sz);
}
int main()
{
	int arr[10] = { 0 };
	test(arr);
	return 0;
}
*/
//�����ù�����-����������ƽ̨��ΪX64�����Ϊ2��
//��sizeof(arr) = 8���ֽڣ�����Ԫ�ص�ַ�Ĵ�С��sizeof(arr[0]) = 4���ֽڣ���һ��Ԫ�صĴ�С

//1. �ַ�ָ��char *p;
/*
#include <stdio.h>
int main()
{
	char ch = 'w';
	char *pc = &ch;
	char *p = "abcdef";//���ַ�������Ԫ�صĵ�ַ��ֵ��p

	char arr[] = "abcdef";
	char *p = arr;//�����������ַ�������Ԫ�صĵ�ַ��ֵ��p�������p��arr��ֵ��ͬ
	printf("%s\n", arr);//��ӡ�ַ���
	printf("%s\n", p);//��ӡ�ַ���
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	//char *p = "abcdef";//"abcdef"��һ�������ַ����������ַ�������Ԫ�صĵ�ַ��ֵ��p
	//printf("%c\n", *p);//��ӡ��Ԫ��
	//printf("%s\n", p);//��ӡ�ַ���
	//char* pc = "abc def";
	//printf("%s\n", pc);//' ','\0',0,'0'������
	//printf("%d\n", ' ');//32
	//printf("%d\n", '\0');//0

	//ע�⣺�����scanf����һ�����ո���ַ����������ʲô�����أ�
	//char c1[] = { 0 };
	//scanf("%s", c1);//������abc def
	//printf("%s\n", c1);//���a�ַ��ĵ�ַ��ʼ,������'\0'������Խ����ʣ��������

	//char* c2 = NULL;
	//scanf("%s", c2);//������abc def
	//printf("%s\n", c2);//���a�ַ��ĵ�ַ��ʼ,������'\0'������Խ����ʣ��������
	return 0;
}
*/
//ע�⣺%s��ӡ����p��%c��ӡ����*p.
//�����ѡ��Ϊ%sʱ �����ǰ������� ����'\0'���� Ҳ����˵�ַ�������ʱֻҪ�����׵�ַ ������\0ʱ���Զ�����
/*
#include <stdio.h>
int main()
{
	char *p1 = "abcdef";//"abcdef"��һ�������ַ����������ַ�������Ԫ�صĵ�ַ��ֵ��p1�������ǽ��ַ�������p1��
	//*p1 = 'W';//��Ϊ"abcdef"�ǳ����ַ������ǲ������޸ĵģ�������޸ĳ������� ---Segment fault�δ���
	//www.stackoverflow.com
	//segmentfault.com
	printf("%s\n", p1);//��ӡ�ַ���
	
	//��ȷ��д��
	const char *p2 = "abcdef";
	//*p2 = 'W';//��ʱ�ͻᱨ��
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	char arr1[] = "abcdef";//����arr1[]����ַ���abcdef����ͬ�ı���������ͬ�Ŀռ�
	char arr2[] = "abcdef";//����arr2[]����ַ���abcdef����ͬ�ı���������ͬ�Ŀռ�
	if (arr1 == arr2)//����arr1��arr2����Ԫ�صĵ�ַ��������ͬ�ı�������������Է���������ڴ�ռ䣬�ʵ�ַ�϶���һ��
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");//��ӡhaha
	}
	if (*arr1 == *arr2)//*arr1 == 'a' *arr2 == 'a',����ASCII��ͬ���������
	{//��ע�⣺�ַ����ıȽϣ�*arr1 == *arr2���ֱȽ��Ǵ����,��Ӧ��ʹ��strcmp(arr1,arr2) - int strcmp( const char *string1, const char *string2 );
		printf("hehe\n");//��ӡhehe
	}
	else
	{
		printf("haha\n");
	}
	const char *p1 = "abcedf";//�����ַ��������ܱ��޸ģ�ֻ��Ҫ��һ�ݼ���
	const char *p2 = "abcedf";//��ͬ�ĳ����ַ�����ʹ�õ���ͬһ��ռ䣬��ʡ�ռ�
	if (p1 == p2)//p1��p2��ŵ���ͬһ��ռ����Ԫ�ص�ַ����Ԫ�ص�ַ��ͬ
	{
		printf("hehe\n");//��ӡhehe
	}
	else
	{
		printf("haha\n");
	}
	if (*p1 == *p2)//*p1 == 'a' *p2 == 'a',����ASCII��ͬ���������
	{//��ע�⣺�ַ����ıȽϣ�*p1 == *p2���ֱȽ��Ǵ����,��Ӧ��ʹ��strcmp(p1,p2)
		printf("hehe\n");//��ӡhehe
	}
	else
	{
		printf("haha\n");
	}
	return 0;
	//���ԡ���ָoffer��
}*/
//C/C++��ѳ����ַ����洢��������һ���ڴ����򣬵�����ָ��ָ��ͬһ�������ַ�����ʱ������ʵ�ʻ�ָ��ͬһ���ڴ档
//��������ͬ�ĳ����ַ���ȥ��ʼ����ͬ�������ʱ��ͻῪ�ٳ���ͬ���ڴ�顣

//2. ָ�����飺��һ�����ָ�루��ַ��������
//int* arr1[10]; //�������ָ�������
//char* arr2[4]; //���һ���ַ�ָ�������
//char** arr3[5];//�����ַ�ָ�����飬���ڴ���ַ�ָ��ĵ�ַ������
/*
#include <stdio.h>
int main()
{
	int arr[4] = { 0 };//��������
	char ch[5] = { 0 };//�ַ�����
	int* parr[4];//����ָ������-�������ָ�������
	char* pch[5];//�ַ�ָ������-����ַ�ָ�������
	
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 20;
	int d = 40;
	int* parr[4] = { &a,&b,&c,&d };//ÿ��Ԫ�ض���int*���͵�ָ��
	//����-���ӣ�&a,&b,&c,&d��parr
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(parr[i]));//parr[i]�ҵ��������±�Ϊi��Ԫ�ص�����(��ַ)
	}
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[] = { arr1,arr2,arr3 };//����ָ������
	//parr[0]:arr1[0],arr1[1],arr1[2],arr1[3],arr1[4]
	//parr[1]:arr2[0],arr2[1],arr2[2],arr2[3],arr2[4]
	//parr[2]:arr3[0],arr3[1],arr3[2],arr3[3],arr3[4]
	//�����ڶ�ά����
	int i = 0;
	for (i = 0; i < 3; i++)//��ӡÿһ������
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));//��ӡ����ĸ���Ԫ��
			//parr[i]�ҵ��˾����������Ԫ�ص�����(��ַ)
		}
		printf("\n");
	}
	return 0;
}
*/

//3. ����ָ�룺�ܹ�ָ�������ָ�롣
/*
#include <stdio.h>
int main()
{
	int *pi = NULL;//pi������ָ�룺�ܹ�ָ���������ݵ�ָ�룬���Դ�����͵ĵ�ַ��
	char *pc = NULL;//pc���ַ�ָ�룺�ܹ�ָ���ַ������ݵ�ָ�룬���Դ���ַ��ĵ�ַ
	//����ָ�룺ָ�������ָ�룬���Դ��(����)����ĵ�ַ
	//int arr[10] = { 0 };
	//arr - ��Ԫ�صĵ�ַ��&arr[0] - ��Ԫ�صĵ�ַ��&arr - ����ĵ�ַ
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//[]��*���ȼ���
	int (*pa)[10] = &arr;//�������ĵ�ַ,�Ⱥ�*pa��ϣ���Ϊָ�룬paΪ����ָ��
	//int[10] *pa = &arr//����д���Ǵ����

	int *p;//pΪ����ָ��
	int* parr[10];//�Ⱥ�parr[10]��ϣ���Ϊ���飬parrΪָ������
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	//�ַ����飬Ԫ��Ϊ�ַ���
	char arr1[5];
	//�ַ������ָ�룬����ָ�������char(*)[]
	char (*pa)[5] = &arr1;

	//�ַ�ָ������飬
	char* arr2[5];
	//�ַ�ָ�������ָ�룬ָ���ַ�ָ������ĵ�ַ
	char* (*pa)[5] = &arr2;
	//�������ĵ�ַ��������ָ��
	//pa������ָ�����������
	//*˵��pa��ָ��
	//[5]˵��paָ���������5��Ԫ��
	//char*˵��paָ��������Ԫ��������char*
	return 0;
}
*/
//ָ�����飺���飺���ָ��(��ַ)�����飬�磺int a;int b;int c;int* arr[3] = {&a��&b��&c};����int *pa = &a;int *pb = &b;int *pc = &c;int* arr[3] = {pa��pb��pc};
//����ָ�룺ָ�룺ָ�������ַ��ָ�룬�磺int arr[3] = {a, b, c};int (*pa)[3] = &arr;
//ָ�������ָ�룺ָ�룺ָ���ָ�������ַ��ָ�룬�磺int* arr[3] = {&a��&b��&c};int* (*ppa)[3] = &arr;
//����ָ������飺���飺�������ָ��(��ַ)�����飬�磺int (*pa)[2] = &arr1;int (*pb)[2] = &arr2;int (*pc)[2] = &arr3;int (*p[3])[2]={pb,pb,pc};
//ע�⣺������˵��ָ�붼��һ��ָ�룬int (*p[3])[2]={&pb,&pb,*pc};�Ǵ���ģ���Ϊ��ŵ�&pa,&pb,&pc��ָ��ĵ�ַ��Ӧ���ö�������ָ��

//&��������������
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("arr = %p\n", arr);
	printf("&arr= %p\n", &arr);
	printf("arr+1 = %p\n", arr + 1);
	printf("&arr+1= %p\n", &arr + 1);
	return 0;
}
*/
//��Ȼ��������&��������ӡ�ĵ�ַ��һ���ġ��ֱ��һ���������ֽ�����ͬ��arr+1����һ�����͵��ֽڣ�&arr+1����һ��������ֽ�
//ʵ���ϣ�&arr��ʾ��������ĵ�ַ��������������Ԫ�صĵ�ַ��
//������&arr�������ǣ�int(*)[10]����һ������ָ�����ͣ�����ĵ�ַ+1��������������Ĵ�С������&arr+1�����&arr�Ĳ�ֵ��40.

//����ָ���ʹ��
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//��������ĸ���Ԫ��
	//1��ʹ�����ּ�㣬ָ��
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p+i));
	}
	//2������ָ��
	int (*p)[10] = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(*p+i));//p == &arr,*p == arr
	}
	//3������ָ��
	int (*p)[10] = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*p)[i]);//*p��ʾ�õ������飬�൱����Ԫ�صĵ�ַ
	}
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int *p = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);//�����±�Ϊi��Ԫ��
		printf("%d ", *(p + i));//*(p+i)����pΪ��ʼ��ַ��ƫ��i�����ȣ����ҵ��±�Ϊi�ĵ�ַ������
		printf("%d ", *(arr + i));//p = arr,˵��p�����ݺ�arr��ͬ
		printf("%d ", p[i]);//��pΪ��ʼ��ַ�������±�Ϊi��Ԫ��
		//arr[i] == *(arr + i) == *(p + i) == p[i]
		//�������ַ����ȼ�
	}
	return 0;
}
*/
/*
#include <stdio.h>
void Print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void Print2(int (*p)[5], int x, int y)//p��ʾһ�У�p+1���ʵ���һ�У�p = arr
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));//*(p + i)��ʾ�ҵ���i��,*(*(p + i) + j)��ʾ�ҵ��˵�j��Ԫ��
			printf("%d ", (*(p + i))[j]);
			printf("%d ", *(p[i] + j));
			printf("%d ", p[i][j]);
			//*(p + i) == p[i]
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	Print1(arr, 3, 5);//arr��ά����������Ԫ�صĵ�ַ(����&��sizeof)����arr[0][i]�����Ԫ�أ������һά���飩
	Print2(arr, 3, 5);//arr�Ƕ�ά������Ԫ�صĵ�ַ��������(��Ԫ��)һά����ĵ�ַ���β�������ָ�����
	return 0;
}
*/

//int arr[5]; //arr��һ��5������Ԫ�ص�����
//int *parr1[10]; //parr1��һ�����飬������10��Ԫ�أ�ÿ��Ԫ�ص�������int*��parr1��ָ������
//int (*parr2)[10]; //parr2��һ��ָ�룬��ָ��ָ����һ�����飬������10��Ԫ�أ�ÿ��Ԫ�ص�������int��parr2������ָ��
//int (*parr3[10])[5]; //parr3��һ�����飬��������10��Ԫ�أ�ÿ��Ԫ����һ������ָ�룬����ָ��ָ���������5��Ԫ�أ�ÿ��Ԫ����int
//ע�⣺�������ʱ�����ֱ��������ȸ��ݽ�����ж���ָ�뻹�����飬���жϱ������ͱ������ͣ�����������ȥ����������ʣ��Ĳ���

//4. ���鴫�κ�ָ�봫��
//�ѡ����顿���ߡ�ָ�롿�����������Ǻ����Ĳ����������ƣ�
//һά���鴫��
/*
#include <stdio.h>
void test(int arr[])//������գ�ok
{}
void test(int arr[10])//������գ�ok
{}
void test(int arr[6])//������գ�ok��д��Ҳ����ϵ��������д������������
{}
void test(int *arr)//ָ����գ�ok
{}
void test2(int* arr[20])//������գ�ok
{}
void test2(int* arr[])//������գ�ok
{}
void test2(int* *arr)//ָ����գ�ok
{}
int main()
{
    int arr[10] = { 0 };//������͵�����
    int* arr2[20] = { 0 };//���ָ�������
    test(arr);//���������Ԫ�ص�ַ�������͵�ַ��ʹ��ָ������β�
    test2(arr2);//���������Ԫ�ص�ַ������Ԫ����int*���͵�ָ�룬
	//��Ԫ�صĵ�ַ�������һ��ָ��ĵ�ַ��ʹ�ö���ָ������β�
}
*/
//�ܽ᣺һά���鴫�Σ������Ĳ�������Ϊ���飬Ҳ����Ϊָ��
//��Ϊ��ָ�����ʱ���β�ֱ����*p����arr[]

//��ά���鴫��
/*
void test(int arr[3][5])//������գ�ok
{}
void test(int arr[][])//error
{}
void test(int arr[3][])//error
{}
void test(int arr[][5])//������գ�ok
{}
//�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
//��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
void test(int* arr)//error����ŵ�������ָ��ĵ�ַ
{}
void test(int* arr[5])//error�����飬��ŵ���ָ��ĵ�ַ
{}
void test(int (*arr)[5])//����ָ�룬������5��Ԫ�أ�ok
{}
void test(int* *arr)//error����ŵ���һ��ָ������ĵ�ַ
{}
int main()
{
	int arr[3][5] = { 0 };
	test(arr);//��ά���鴫�Σ���Ԫ�ص�ַ��һά����(5��Ԫ��)�ĵ�ַ
}
*/
//�ܽ᣺��ά���鴫�Σ������Ĳ�������Ϊ���飬Ҳ����Ϊָ��
//��Ϊ��ָ�����ʱ���β�������ָ�룬ע������Ԫ�ظ���

//һ��ָ�봫��
/*
#include <stdio.h>
void Print(int* p, int sz)//��һ��ָ�����
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *(p + i));
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int *p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//һ��ָ��p����������
	Print(p, sz);
	return 0;
}
*/
//�ܽ᣺һ��ָ�봫�Σ������Ĳ���Ϊһ��ָ��

//˼������һ�������Ĳ�������Ϊһ��ָ���ʱ�򣬺����ܽ���ʲô������
//----1��������ַ��2��һ��ָ�������3��һά������
/*
#include <stdio.h>
void test(int* p)
{}
void test2(char* p)
int main()
{
	int a = 10;
	int* p = &a;
	test(&a);//ok
	test(p);//ok
	char ch = 'w';
	char* pc = &ch;
	test2(&ch);//ok
	test2(pc);//ok
	return 0;
}
*/

//����ָ�봫��
//----1��һ��ָ������ĵ�ַ��2������ָ�������3��ָ��������
/*
#include <stdio.h>
void test(int** p)
{}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);//ok
	test(&p);//ok
	int* arr[10];
	test(arr);//ok
	return 0;
}
*/
//�ܽ᣺����ָ�봫�Σ������Ĳ��������Ƕ���ָ��
//������������Ƕ���ָ�룬���ο����Ƕ���ָ�����pp��һ��ָ��ĵ�ַ&p��������ָ��������(һ��ָ�������)

//5. ����ָ�룺ָ������ָ�룬������Ǻ����ĵ�ַ
//����ָ�� - ��ָ�������ָ��
//����ָ�� - ��ָ������ָ��
//ָ�뺯�� - ������������Ϊָ�����͵ĺ���
/*
#include <stdio.h>
int Add(int x,int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	
	//int arr[10] = { 0 };
	//&arr
	//arr
	printf("%p\n", &Add);
	printf("%p\n", Add);
	//&������ �� ���������Ǻ����ĵ�ַ����ͬ�ĸ���
	return 0;
}
*/
/*
#include <stdio.h>
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int arr[10] = { 0 };
	int (*pa)[10] = &arr;
	//[10]����ָ��ָ��������飬10���������Ԫ�ظ���
	//int[10] *pa = &arr//����д���Ǵ����

	int a = 10;
	int b = 20;
	//int* p(int, int) = Add;
	//�������ָ�룬()��*���ȼ��ߣ�Ϊ�˱�֤��ָ�����ͣ�*p�Ƚ��
	int (*p)(int,int) = Add;//int (*p)(int x,int y) = Add;Ҳ����
	//(int,int)����ָ��ָ����Ǻ�����int,int�������Ĳ�������
	//p�Ǵ��Add�ĵ�ַ����
	printf("%d\n",(*p)(2, 3));
	return 0;
}
*/
/*
#include <stdio.h>
void Print(char* str)
{
	printf("%s\n", str);
}
int main()
{
	void (*p)(char*) = Print;//����ָ��p�����ͣ�void (*)(char*)
	(*p)("hello bit");//"hello bit"������������ַ��ĵ�ַ
	return 0;
}
*/

//�Ķ�������Ȥ�Ĵ��룺
//ע : �Ƽ���C�����ȱ�ݡ�--�Ȿ�����ἰ���������롣
//����1
//( * ( void (*)() ) 0 )(); //void (*)()-����ָ������
//���ͣ�
//��0ǿ������ת����void (*)()����ָ�����ͣ�0����һ�������ĵ�ַ�������0����ĳ�����ĵ�ַ
//������*(void(*)())0�õ�ַ�ҵ��ú������ٵ��øú�������Ϊ�ú������޲εģ�����ֵΪvoid����(*(void(*)())0) ()
//������0��ַ���Ĳ���Ϊ�޲Σ�����ֵΪvoid�ĺ���

//����2
//void ( *signal(int, void(*)(int)) )(int);
//���ͣ�
//�������һ��������������
//������Ϊsignal�������Ĳ�������һ������Ϊ����int���ڶ�������Ϊ����ָ������void(*)(int)���ú���ָ��ָ��ĺ����Ĳ�����int������������void
//���ú���signal���ص�����Ҳ��void (*)(int)����ָ�����ͣ��ú���ָ������Ҳָ��ĺ����Ĳ�����int������������void
//void(*)(int) signal(int, void(*)(int));��������������,���ں���ָ�����͵ĺ�����������������д
//����2̫���ӣ���μ򻯣�
//typedef void(* pfun )(int);//�������Ϊtypedef void(*)(int) pfun;
//pfun signal(int, pfun);
//������typedef unsigned int u_int;
/*
#include <stdio.h>
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int (*p)(int,int) = Add;
	printf("%d\n",(*p)(2, 3));
	//��Ϊp�����Add���ʶ������
	printf("%d\n", p(2, 3));//����p = Add������������ָ�룬��p(2, 3) == Add(2, 3)
	//����ָ����ÿ��Բ������ã����߶�ν����ö�����ͬ��Ч��
	printf("%d\n", (**p)(2, 3));
	printf("%d\n", (***p)(2, 3));
	return 0;
}
*/

//6. ����ָ������ - ��ź���ָ��(��ַ)������
//int* arr[10];
//�����ÿ��Ԫ�ص����Ͷ���int*
/*
#include <stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//ָ������ - ���ָ�������
	int* arr[5];
	//����ָ��p1��p2��p3��p4
	//int (*p1)(int,int) = Add;
	//int (*p2)(int, int) = Sub;
	//int (*p3)(int, int) = Mul;
	//int (*p4)(int, int) = Div;
	//����ʹ��һ�����飬������ĸ�������ָ��(��ַ)��������ָ������
	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };
	//�����Ϊ��int(*)(int,int) parr[4];����������д�Ǵ����
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", (*parr[i])(2, 3));//���Բ�д*��parr[i](2, 3)��������i�±�ĺ�����ַ�������ú���
		//printf("%d\n", parr[i](2, 3));
	}
	return 0;
}
*/

//���磺char* my_strcpy(char* dest, const char* src);
//дһ������ָ��pf��ָ��my_strcpy
//char* my_strcpy(char* dest, const char* src);
//char* (*pf)(char*, const char*) = my_strcpy;
//дһ������ָ������pfArr�����4��my_strcpy�����ĵ�ַ
//char* (*pfArr[4])(char*, const char*) = { my_strcpy };

//����ָ���������;��Ҳ��ת�Ʊ�
//���ӣ�����������
/*
#include <stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}
void menu()
{
	printf("********  0��EXIT  ********\n");
	printf("***** 1��Add   2��Sub *****\n");
	printf("***** 3��Mul   4��Div *****\n");
	printf("********  5��Xor   ********\n");
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do 
	{
		menu();
		printf("ѡ�������>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�����������β�������>");
			scanf("%d%d", &x, &y);
			printf("%d + %d = %d\n", x, y, Add(x, y));
			break;
		case 2:
			printf("�����������β�������>");
			scanf("%d%d", &x, &y);
			printf("%d - %d = %d\n", x, y, Sub(x, y));
			break;
		case 3:
			printf("�����������β�������>");
			scanf("%d%d", &x, &y);
			printf("%d �� %d = %d\n", x, y, Mul(x, y));
			break;
		case 4:
			printf("�����������β�������>");
			scanf("%d%d", &x, &y);
			printf("%d �� %d = %d\n", x, y, Div(x, y));
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);	
}
*/
//ȱ�㣺1���������� 2����ӹ��ܲ�����
/*
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int (*pArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
	do
	{
		menu();
		printf("ѡ�������>");
		scanf("%d", &input);
		
		if (input >= 1 && input <= 5)//���5����ݺ����ĸ�������
		{
			printf("�����������β�������>");
			scanf("%d%d", &x, &y);
			int ret = pArr[input](x, y);//���Բ�д*��((*pArr)[input])(x,y)
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("ѡ���������ѡ��\n");
		}
	} while (input);
	return 0;
}
*/

//7. ָ����ָ�������ָ��
//ָ����ָ�������ָ����һ��ָ��.ָ��ָ��һ�� ����ָ������ĵ�ַ �������Ԫ�ض��� ����ָ��
/*
#include <stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int arr[10] = { 0 };
	int (*pArr)[10] = &arr;//����ָ��

	int (*pf)(int,int) = Add;//pf�Ǻ���ָ��

	int (*pfArr[4])(int, int);//pfArr��һ������ָ������

	int (*(*ppfArr)[4])(int, int)=&pfArr;//���溯��ָ�������ַ��ָ��
	//��*��ppfArr��һ��ָ�룬������int (*[4])(int, int)
	//ppfArr��һ������ָ�룬ָ����������ĸ�Ԫ�أ������ÿ��Ԫ�ص�������һ������ָ��int(*)(int, int)

	return 0;
}
*/

//8. �ص�����
//�ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��������
//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã�
//�������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��
/*
#include <stdio.h>
void test(void (*p)(char*))//�ú���ָ����ղ���
{
	printf("test\n");
	p("bit");//pָ��Print����������Print()
}
void Print(char *str)//Print�ǻص�����
{
	printf("%s\n",str);
}
int main()
{
	test(Print);//��ַ��Ϊ����, Print��ͨ������ָ��p���õ�
	return 0;
}
*/

//���ٴ��������
/*
#include <stdio.h>
void Calc(int (*pfun)(int ,int))//ʹ�ú���ָ��
{
	int x = 0;
	int y = 0;
	printf("�����������β�������>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pfun(x, y));
}
int Add(int x, int y)//�ص�����
{
	return x + y;
}
int Sub(int x, int y)//�ص�����
{
	return x - y;
}
int Mul(int x, int y)//�ص�����
{
	return x * y;
}
int Div(int x, int y)//�ص�����
{
	return x / y;
}
void menu()
{
	printf("********  0��EXIT  ********\n");
	printf("***** 1��Add   2��Sub *****\n");
	printf("***** 3��Mul   4��Div *****\n");
	printf("***************************\n");
}
int main()
{
	int input = 0;
	do 
	{
		menu();
		printf("ѡ�������>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);//��������Ϊ��ַ����
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);	
}
*/

//������ָ��
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	//char* pc = &a;//������
	char ch = 'w';

	void* p = &a;//�������棬void* ���͵�ָ�룬���Խ����������͵ĵ�ַ(����Ͱ/����ָ��)
	p = &ch;
	//*p = 0;//����void*���͵�ָ�룬���ܽ��н����ò�������Ϊ��֪�����ʼ����ֽ�
	//p++;//Ҳ�ᱨ��void*���͵�ָ�룬���ܽ���ָ��+/-�����Ĳ�������Ϊ��֪���������ʼ����ֽ�
	return 0;
}
*/

//��ǰ��ð������ֻ�����������ݣ�C�����ṩ��һ���⺯����qsort - �ú����ײ�ʹ�õ������㷨��quick sort(��������)������ʵ���������ݵ�����
/*
#include <stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)//�����ƱȽϵ�����
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//������ÿ���ų��������
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//qsort������ʹ�ã�MSDN����qsort
//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
//��һ��������void* base - base:Start of target arrayĿ���������Ԫ�ص�ַ
//�����������������Ԫ�ص�ַ
//�ڶ���������size_t num - num:Array size in elements�����Ԫ�ظ���
//���������������Ԫ�ظ���
//������������size_t width - width:Element size in bytesԪ�صĴ�С
//���������������ÿ��Ԫ�صĴ�С - ��λ�ֽ�
//���ĸ�������int(* compare)(const void* elem1, const void* elem2) - compare��һ������ָ�룬��ָ��������Ǻ���ָ������
//���ĸ�������ָ������Ҫʵ�ֵıȽϺ��������ڽ��յĺ����Ĳ����Ǻ���ָ�����ͣ�����ƱȽϺ���Ӧ��
//�ú���ָ��ָ��ĺ�����Ҫ���ǣ�
//1������������int ������(const void* elem1, const void* elem2)���������͵�����ֵ֮��ıȽ�
//2��������ַ�ȽϵĽ������0�����ش���0���������С��0������С��0����������0���ص���0������
//��������ָ�룬�Ƚ�����Ԫ����ָ��ĵ�ַ��ֵ - ���������ʹ�����Լ�ʵ�� - �ص�������ʵ��
//����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
/*
#include <stdio.h>
#include <stdlib.h>//qsort�⺯����ͷ�ļ�
#include <string.h>
//�����������ַ��ָ������ݱȽϣ������ص�ֵʵ��������Ϊqsort�����ײ������if�ж��������̶�ʹ��qsortʵ��������
int compare_int(const void* e1, const void* e2)//�ص�����
{
	return *((int*)e1) - *((int*)e2);//���ڿ�ָ�����Ͳ��ܽ����ã�����Ҫǿ������ת��Ϊint*���͵ĵ�ַ���ٽ�����
}
void test1()
{
	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), compare_int);//����compare_int�ĵ�ַ���ȵ���compare(elem1, elem2)����ָ�����ıȽϺ���
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int compare_float(const void* e1, const void* e2)
{
	//retrun (int)(*((float*)e1) - *((float*)e2));//���ַ�����ȱ�ݣ���������ֵ���0 < *e1 - *e2 < 1,�ͻ᷵��0
	if (*((float*)e1) == *((float*)e2))
		return 0;
	else if (*((float*)e1) > *((float*)e2))
		return 1;
	else
		return -1;
}
void test2()
{
	float f[10] = { 2.0,4.0,7.0,3.0,5.0,8.0,9.0,1.0,0.0,6.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), compare_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}
struct Stu
{
	char name[20];
	int age;
};
int compareStu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3() 
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };//�ṹ������
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), compareStu_by_age);
	//���
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}
int compareStu_by_name(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���������ʹ�ù�ϵ�������
	//ʹ��strcmp�⺯�����������0��ǡ�÷��ش���0���������С��0������С��0����������0���ص���0������
	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}
void test4()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };//�ṹ������
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), compareStu_by_name);
	//���
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}
*/

//ģ��ʵ��qsort���������躯����Ϊbubble_sort���ײ�������㷨��ð������
/*
#include <stdio.h>
//һ��һ���ֽڵĽ���
//����Ԫ�ص����Ͳ�ͬ���������ͱ�תΪ��char*���������ԭ��С������width
//���磺char ����ֻ��Ҫ����1�Ρ���int ���;���Ҫ����4�Σ����ܱ�֤�������ݽ�����
//���磺 ����a = 0x11 22 33 44  b = 0x 00 99 88 77
//a��b�������ǣ�a = 0x 00 99 88 77 b = 0x11 22 33 44
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
//bubble_sort��ʵ��
void bubble_sort(void* base, int sz, int width, int (*compare)(void* e1, void* e2))
{
	//void* base :��֤���Խ����������͵���Ԫ�ص�ַ���磺����arr��s����Ϊvoid*
	//int sz :�Ա�Ԫ��֮��Ƚ�����Ҫ��������ÿ�ֵĴ�������Ϊsz
	//int width :���ڲ��ܴ������ͣ�������Ҫ֪��Ԫ�ص����ͣ�ͨ��Ԫ�صĴ�С����֤��������Ԫ��֮���ϵ����ͨ������ʵ�֣���Ϊwidth
	//int (*compare)(void* e1,void* e2) :���ڲ�ͬ������֮��Ԫ�صıȽ��ǲ�ͬ�ġ�Ϊ��ʵ��ͨ���ԣ�ʹ�ú���ָ�룬ָ��ȽϹ��ܵĺ�������compareָ����������������͵ĺ���
	//��������Ϊint���жϽ���Ĵ�С����ȷ�����������ʽ�ǴӴ�С�����Ǵ�С����
	//ʵ��bubble_sort�����ĳ���Ա����֪��ʹ����δ�������������������һ�֡�����ԱҲ��֪�������Ƚϵ�����Ԫ�ص����ͣ���Ϊvoid* e1,void* e2
	int i = 0;
	for (i = 0; i < sz - 1; i++)//�����ƱȽϵ�����
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//������ÿ���ų��������
		{
			//������Ԫ�صıȽ�
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//�ɴ˿�֪���ص��������ش���0��������ʾ������if�ж��壬ʵ�ִ�С��������
																					//����С��0��������ʾ��������if�ж��壬ʵ�ִӴ�С����
																					//���ص���0��������ʾ��������if�ж��壬������
				//���ʵ����������Ԫ�صıȽ�
				//compare(base,base+1)//error:void*���� ����ָ��+/-��������
				//compare(base,(int*)base+1)//error:ֻ�ʺ��������飬����������������Ԫ�صıȽ�
				//compare(base,(char*)base+width)//�������ͣ������1��2����Ԫ�صıȽ�
				//compare((char*)base+j*width,(char*)base+(j+1)*width)//�������͵�Ԫ�أ�width�ǲ�ͬ�ģ�ÿ������Ԫ�رȽ�֮������width���ֽ�
			{
				//����Ԫ�صĹ���
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
int compare_int(const void* e1, const void* e2)//�ص�����
{
	return *((int*)e1) - *((int*)e2);
}
void test1()
{
	int arr[10] = { 2,4,7,3,5,8,9,1,0,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô���͵�����
	//��Ӧ��֪����αȽϴ����������е�Ԫ��
	bubble_sort(arr, sz, sizeof(arr[0]), compare_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
struct Stu
{
	char name[20];
	int age;
};
int compareStu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3() 
{
	struct Stu s[3] = { {"zhangsan",30},{"lisi",10},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), compareStu_by_age);
	//���
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", s[i].name, s[i].age);
	}
}
int main()
{
	test1();
	return 0;
}
*/
//����"�����ض��壬��ͬ�Ļ�����"�������ڻ�δ�����ĵط���ʹ���ˡ�����ʹ�õĵط��붨��ĵط�������ͬһ��.c�ļ��У�����û�б�δ�����Ĵ���
//�����������ʵ�ַŵ�ʹ�õ�ǰ�棬������include���ͺ궨�������Ϻ�������

//�ܽ�һ�£�������Ϊ��
/*
//����ָ��
int a = 0; int b = 0; int c = 0;
int *pa = &a;//�����͵Ļ����ϣ�������ָ�룬����*p���������

//����ָ������
int arr[10] = { 0 };
int *(parr[5]) = { &a,&b,&c };//������ָ��Ļ����ϣ����������飬����arr[]���������������[]��*�Ƚ�ϣ�����ʡ��int *parr[5] = { &a,&b,&c };

//����ָ�������ָ��
int *((*Parr)[5])=&parr;//������ָ������Ļ����ϣ�������ָ�룬����*p���������������[]��*�Ƚ�ϣ�����ʡ��int *(*Parr)[5]=&parr;

//��������ָ��
int arr[10];
int (*pa)[10]=&arr; int (*pb)[10] = &arr; int (*pc)[10] = &arr;//����������Ļ����ϣ�������ָ�룬����*p���������

//��������ָ�������
int (*(pArr[]))[10] = { &pa,&pb,&pc };//����������ָ��Ļ����ϣ����������飬����arr[]���������������[]��*�Ƚ�ϣ�����ʡ��int (*pArr[])[10] = { &pa,&pb,&pc };
*/

/*
//����ָ��
int Add(int x, int y); int Sub(int x, int y); int Div(int x, int y);
int (*pFa)(int, int) = Add; int (*pFb)(int, int) = Sub; int (*pFc)(int, int) = Div;//�ں����Ļ����ϣ�������ָ�룬����*p���溯����

//����ָ������
int (*(pFArr[]))(int, int) = {Add,Sub,Div};//�ں���ָ��Ļ����ϣ����������飬����arr[]���������������[]��*�Ƚ�ϣ�����ʡ��int (*pFArr[])(int, int) = {Add,Sub,Div};

//����ָ�������ָ��
int (*((*PFArr)[]))(int, int) = &pFArr;//�ں���ָ������Ļ����ϣ�������ָ�룬����*p���������������[]��*�Ƚ�ϣ�����ʡ��int (*(*pFArr)[])(int, int);
*/