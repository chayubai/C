#define _CRT_SECURE_NO_WARNINGS 1

//1��������ʲô���������ĳ���ض�����Ĵ����
/*
#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main() 
{
	int a = 10;
	int b = 20;
	int sum = Add(a , b);
	printf("%d\n",sum);

	return 0;
}
*/
//��������main����֮ǰ�����Բ�������

//2���⺯����C�����ṩ����ҪƵ��ʹ�õĹ���/����
//I/O�����������������������stdio.hͷ�ļ��£��磺printf��scanf��getchar��putchar
//�ַ�����������������string.hͷ�ļ��£��磺strcpy��strlen
//�ַ������������磺��дתСд
//�ڴ�����������磺memset
//ʱ��/���ں������磺time
//��ѧ����������math.hͷ�ļ��£��磺sqrt
//...

//���ѧ���������裺
//1��ʹ��cplusplus.com����API�ĵ�MSDN����cppreference.com������������strcpy
//2����⺯���Ĳ������������͡�������������
//3��char * strcpy ( char * destination, const char * source );
//char* �ַ���ָ�����ͣ�������ŵ�ַ�ġ�������destinationĿ�ĵء�sourceԴͷ
//4����⺯���Ĺ�������
//5��Copies the C string pointed by source into the array pointed by destination, including the terminating null character
//����ͨ��Դͷָ����Ǹ�C�ַ�������ͨ��Ŀ�ĵ���ָ����Ǹ������У�����������'\0'�ַ�(null-'\0')
//6��Parameters����
//destination
//Pointer to the destination array where the content is to be copied.
//source
//C string to be copied.
//7��Return Value
//destination is returned.
//8�����Ժ�������ͷ�ļ�
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//strlen    -string length
	//strcpy	-string copy
	char arr1[] = "bit";
	char arr2[20] = "########";//�±�Ϊ8-19������Ԫ�ؾ�Ϊ0
	strcpy(arr2, arr1);//������������һ����ַ
	printf("%s\n", arr2);

	return 0;
}
*/
//����Fn+F5�����Ϊbit
//�������Ƿ�\0�ַ���������
//Fn+F10����57�к�ѡ�����ѡ�-����-���ӣ����Դ���
//����arr1��arr2���۲��֪
//arr1��b��i��t��0
//arr2��########000000000000
//�ٰ�һ��Fn+F10��������58��
//�۲�arr2��Ԫ�ؿ�֪��Ϊbit0####000000000000
//����\0�ַ�Ҳ�������ˣ���\0�ǽ�����־�����Դ�ӡ�Ľ��\0���治���
//ע�⣺Դͷ�Ŀռ��Ŀ�ĵصĿռ䳤�������

//1��ʹ��cplusplus.com����API�ĵ�MSDN����cppreference.com������������memset
//2����⺯���Ĳ������������͡�������������
//3��void * memset ( void * ptr, int value, size_t num );
//void* ָ�����ͣ�������ŵ�ַ�ġ�������value��num
//4����⺯���Ĺ�������
//5��Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
//�����ʼnum���ֽڱ�ptrָ����ڴ�ռ�Ϊvalue������ptr��ָ����Ǹ��ڴ��ռ��ǰnum���ֽڵ����ݶ�����Ϊָ����valueֵ
//6��Parameters����
//ptr
//Pointer to the block of memory to fill.
//value
//Value to be set.
//num
//Number of bytes to be set to the value.
//size_t is an unsigned integral type.
//7��Return Value
//ptr is returned.
//8�����Ժ�������ͷ�ļ�
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//memset    -memory set
	char arr[] = "hello world";
	memset(arr,'*', 5); //��arrǰ����ַ�������Ϊ�ַ�'*'��value = '*'ʵ���Ͼ���һ������
	printf("%s\n", arr);//***** world

	return 0;
}
*/

//3. �Զ��庯��
//�����Ļ������
//int Add(int x,int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//ret_type fun_name(para1,*)
//{//������
//	statement;//�����
//  return value;
//}
//ret_type��������
//fun_name ������
//para1 ��������
//�磺дһ�����������ҳ����������е����ֵ
//���庯��
/*
#include <stdio.h>
int get_max(int x, int y)
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
	//������ʹ��
	int max = get_max(a,b);
	printf("max = %d\n",max);
	max = get_max(100,300);
	printf("max = %d\n",max);
	return 0;
}
*/
//�磺дһ���������Խ����������ͱ���������
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int tmp = 0;
	printf("a = %d b = %d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("a = %d b = %d\n", a, b);
	return 0;
}
*/
/*
#include <stdio.h>
void Swap(int x,int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("a = %d b = %d\n", a, b);
	Swap(a,b);//��ֵ����
	printf("a = %d b = %d\n", a, b);
	return 0;
}
*/
//���ԣ�F10���۲캯���ڲ�F11
//�۲�a��b��&a��&b��x��y��&x��&y��tmp
//����&a��&b����&x��&y�ĵ�ַ��ͬ����a��b��x��y�洢�������������Ŀռ�
//��ʹ�����ڲ�x��y��ֵ�Ѿ������ˣ����ǲ���Ӱ�쵽&a��&b�ĵ�ַ�ڵ�ֵ����û�н���

//֪ʶ�ع�
/*
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;//*�����ò�����ͨ��pa�ĵ�ַ�ҵ�a�����ݣ����޸�a��ֵ
	printf("%d\n",a);
	return 0;
}
*/
//�޸ĺ�Ĵ���
/*
#include <stdio.h>
void Swap(int* pa,int* pb)
{
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("a = %d b = %d\n", a, b);
	Swap(&a,&b);//��ַ����
	printf("a = %d b = %d\n", a, b);
	return 0;
}
*/
//��ʵ�δ����βε�ʱ���β���ʵ��ʵ�ε�һ����ʱ���������βε��޸��ǲ���ı�ʵ�ε�

//4. ��������
//ʵ�Σ���ʵ���������Ĳ�������ʵ�Ρ�
//ʵ�ο����ǣ�����(get_max(10,20))������(�磺get_max(a,b))�����ʽ(�磺get_max(100,300+1))������(�磺get_max(get_max(10,20),30)�ȡ�
//����ʵ���Ǻ������͵������ڽ��к�������ʱ�����Ƕ�������ȷ����ֵ���Ա����Щֵ���͸��βΡ�
//ʵ�Σ���Swap(&a,&b)�е�&a��&b
//�βΣ���Swap(int* pa,int* pb)�е�pa��pb
//��ʽ������ָ�������������еı�������Ϊ��ʽ����ֻ���ں��������õĹ����в�ʵ�����������ڴ浥Ԫ�������Խ���ʽ������
//��ʽ�����������������֮����Զ������ˡ������ʽ����ֻ�ں�������Ч��

//5. ��������
//��ֵ����:
//�������βκ�ʵ�ηֱ�ռ�в�ͬ�ڴ�飬���βε��޸Ĳ���Ӱ��ʵ�Ρ�
//��ַ����:
//��ַ�����ǰѺ����ⲿ�����������ڴ��ַ���ݸ�����������һ�ֵ��ú����ķ�ʽ��
//���ִ��η�ʽ�����ú����ͺ�����ߵı�����������������ϵ��Ҳ���Ǻ����ڲ�����ֱ�Ӳ��������ⲿ�ı�����
//ʲôʱ��ʹ�ô�ֵ���ã�ʲôʱ��ʹ�ô�ַ���ã�
//---���������Ҫʵ�ֵĹ�����Ҫ�ı����ֵ�����ݣ���ʹ�ô�ַ����
//---���������Ҫʵ�ֵĹ���ֻ�ǻ�ȡ������ֵ��������Ҫ�ı�ֵ�����ݣ����ô�ֵ����
//��ϰ
//1. дһ�����������ж�һ�����ǲ���������
/*
#include <stdio.h>
int main()
{
	int i = 0;
	for (i = 100;i <= 200;i++)
	{
		int j = 0;
		for (j = 2;j <= i-1;j++)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
			printf("%d ",i);
	}
}
*/

//�ж�i�Ƿ�Ϊ�����ĺ���
//���躯������ֵΪ1����������������ֵΪ0����������
/*
#include <stdio.h>
#include <math.h>
int is_prime(int i)
{
	int j = 0;
	for (j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;//return��breakǿ��returnֱ�ӽ���������break����ֹ��ѭ��
	}
	//if (j == i)//����Ҫ���д��룬��Ϊreturn 0;��ִ�У�һ����ִ��return 1;ִ��return 1;�Ͳ���ִ��return 0;
		return 1;
}
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{	
		//�ж�i�Ƿ�Ϊ����
		//���躯������ֵΪ1����������������ֵΪ0����������
		if (is_prime(i) == 1)
			printf("%d ", i);
	}
	return 0;
}
*/

//2. дһ�������ж�һ���ǲ������ꡣ
/*
#include <stdio.h>
int is_leap_year(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
}
//��������ƣ�Ҫ��һ���������磺��Ҫ�ں����ڴ�ӡ
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{	
		//�ж�year�Ƿ�Ϊ����
		//���躯������ֵΪ1���������꣬����ֵΪ0����������
		if (1 == is_leap_year(year))
			printf("%d ", year);
	}
	return 0;
}
*/

//3. дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�
//���ֲ��ң���һ�����������в��Ҿ����ĳ����
//����ҵ��˷�����������±꣬�Ҳ�������-1
//1��ȥ�Ĳ���	2��Ҫ����˭	3�����Һ�Ľ��
//����ʵ��:
/*
#include <stdio.h>
int binary_search(int arr[], int k)//ע�⣺ʵ�κ��βΣ�������arr��һ��ָ��
{
	//�㷨ʵ��--���ֲ���
	int sz = sizeof(arr) / sizeof(arr[0]);//sizeof(arr)�������ָ���С��win32��4���ֽڣ�arr[0]��int�ͣ�Ҳ��4���Լ�����sz = 4 / 4 = 1
	int left = 0;
	int right = sz - 1;
	while (left <= right)//��ζ��ֲ���
	{
		//һ�ζ��ֲ���
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 7;
	//1��ȥ�Ĳ���:arr	2��Ҫ����˭:k	3�����Һ�Ľ��ret
	int ret = binary_search(arr,k);//���ݹ�ȥ��������arr��Ԫ�صĵ�ַ
	//����ҵ��˷�����������±꣬�Ҳ�������-1
	if (ret == -1)
		printf("�Ҳ���ָ��������\n");
	else
		printf("�ҵ��ˣ��±���%d\n",ret);
	return 0;
}
*/
//�����������
//����������
//���ι۲�arr��k��sz
//����sz�����������ǰ�������Ϊ�������뺯�����β��У�����ʹ��sizeof(arr)/sizeof(arr[0])��������Ԫ�صĸ���
//ԭ��������Ϊ����������Ľ����ǵ�һ��Ԫ�صĵ�ַ������ʱ�����������������Ԫ�صĵ�ַ
//�޸Ĵ��룺�ü���Ԫ�ظ������ں����⣨�������ڣ�,��Ԫ�ظ�����Ϊ�������뺯����
/*
#include <stdio.h>
int binary_search(int arr[], int k, int sz)//ע�⣺ʵ�κ��βΣ�������arr��һ��ָ��
{
	//�㷨ʵ��--���ֲ���
	int left = 0;
	int right = sz - 1;
	while (left <= right)//��Ҫ��ȣ��������7��ʱ��©����7
	{
		//һ�ζ��ֲ���
		int mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int k = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr,k,sz);//���ݹ�ȥ��������arr��Ԫ�صĵ�ַ
	//����ҵ��˷�����������±꣬�Ҳ�������-1
	if (ret == -1)
		printf("�Ҳ���ָ��������\n");
	else
		printf("�ҵ��ˣ��±���%d\n",ret);
	return 0;
}
*/
//��ʱ�β�arr[]�����ã���Ϊ�˻�ȡarr[mid]��������Ҫ��һ��int arr[]�Ĳ���

//4. дһ��������ÿ����һ������������ͻὫ num ��ֵ����1��
/*
#include <stdio.h>
void Add(int* p)
{
	(*p)++;//++�����ȼ�����*
}
int main()
{
	int num = 0;
	Add(&num);//������Ҫ����ʵ�ε�ֵ��ʹ�ô�ַ����
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	return 0;
}
*/

//6. ������Ƕ�׵��ú���ʽ����
//������Ƕ�׵��ã������ͺ���֮������л������
/*
#include <stdio.h>
void line()
{
	printf("hehe\n");
}
void three_line()
{
	int i = 0;
	for (i = 1; i <= 3; i++)
	{
		line();
	}
}
int main()
{
	three_line();
	return 0;
}
*/
//��������ʽ���ʣ���һ�������ķ���ֵ��Ϊ��һ�������Ĳ���
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//1��
	int len = 0;
	len = strlen("abc");
	printf("%d\n", len);
	//2����ʽ����
	printf("%d\n", strlen("abc"));
	return 0;
}
*/
//�磺
/*
#include <stdio.h>
int main()
{
	printf("%d",printf("%d",printf("%d",43)));
}
*/
//��MSDN����printf
//����ֵ������int��
//Return Value
//Each of these functions returns the number of characters printed, or a negative value if an error occurs.
//���ش�ӡ���ַ��ĸ���(��Ӧ���ֽ���)�������һ�������ַ����򷵻�2��Ҳ����˵�����ش�ӡ���ֽ�����������\0�ַ�
//printf("%d", 43)�Ľ����ӡ43����ӡ�������ַ�������ֵ��2
//printf("%d",printf("%d",43))�Ľ����ӡ2����ӡ��һ���ַ�������ֵ��1
//printf("%d",printf("%d",printf("%d",43)))�Ľ����ӡ1
//�ʽ��Ϊ4321
//ע�����ֺ����ķ���ֵ���ͺ����Ľ��

//7. �����������Ͷ���
//����������
//1. ���߱�������һ��������ʲô��������ʲô������������ʲô�����Ǿ����ǲ��Ǵ��ڣ����������������ˡ�
//2. ����������һ������ں�����ʹ��֮ǰ��Ҫ������������ʹ�á�
//3. ����������һ��Ҫ����ͷ�ļ��еġ�
//�������壺
//�����Ķ�����ָ�����ľ���ʵ�֣����������Ĺ���ʵ�֡�

//��������
/*
int Add(int, int);//Ҳ������int Add(int x,int y)
int main() 
{
	int a = 10;
	int b = 20;
	//��������
	int sum = Add(a , b);
	printf("%d\n",sum);

	return 0;
}
*/
//�����Ķ���
/*
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
*/
//�����������main���棬����ᱨ����
//�Զ��庯���������������棬��Ҫ��������������������ǰ�棬����Ҫ��������

//�������������壺
//1����ѡ��ͷ�ļ����һ�����һ���ļ���add.h
//�ļ�д����룺
//�������� 
/*int Add(int, int);*/
//2����ѡ��Դ�ļ����һ��½�һ���ļ���add.c
//�����Ķ��壺
/*
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
*/
//3����������
//��test.c��ʹ��add()
/*
#include "add.h"//�Լ�������ͷ�ļ���""��C�����ṩ��ͷ�ļ���<>
int main()
{
	int a = 10;
	int b = 20;
	//��������
	int sum = Add(a, b);
	printf("%d\n", sum);

	return 0;
}
*/
//�磺ʵ��һ���������ĳ���
//�����ܲ�ֳɣ��ӷ����ܡ��������ܡ��˷����ܡ���������
//Aʵ�֣�add.c��add.h��Bʵ�֣�sub.c��sub.h��Cʵ�֣�mul.c��mul.h��Dʵ�֣�div.c��div.h
//ʹ�õ�ʱ�������ϼ���
//ע�⣺.hͷ�ļ��ŵ��Ǻ���������.cԴ�ļ��ŵ��Ǻ�������
//����������Ҳ������ôд��
/*
#ifndef __ADD_H__//if not define Add.h��Ϊ�棬��ִ�еڶ��У�Ϊ�������д��벻������룬�������һ��end if
#define __ADD_H__//define Add.h
//����������
int Add(int x,int y);
#endif // !__ADD_H__
*/
//Ŀ�ģ���ֹͬһ��ͷ�ļ����ظ������Σ���ͷ�ļ�������

//8. �����ݹ飺�����������
//�磺
/*
#include <stdio.h>
int main()
{
	printf("hehe\n");
	main();
	return 0;
}
*/
//ͨ�����Է��֣�����Stack overflow 
//�ݹ鳣���Ĵ���ջ���
//���ڴ滮��Ϊջ������������̬��
//ջ�����žֲ��������ڴ桢�����βε��ڴ棬�������õ��ڴ�
//�������Ŷ�̬���ٵ��ڴ棬�磺malloc��calloc
//��̬������ȫ�ֱ������ڴ棬�磺static���εı���
//stackoverflow.com---����Ա��֪�������ʡ����

//���磺����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�����룺1234����� 1 2 3 4
//˼·һ������õ�4�������ȶ���%ģ10�õ�4����10ȥ����4��ѭ��3�Σ��ٽ����ĸ�������һ�������У����Ŵ�ӡ����
//˼·�������ݹ�˼�룩
//ͨ����һ�����͸��ӵ�������ת��Ϊһ����ԭ�������ƵĹ�ģ��С�����������
//print(1234)�����ڴ�ӡĩλ�����Ƚ����ף����Խ���ӡ���������
//print(123) 4//�Ƚ�123��ÿλ��ӡ���ٴ�ӡ4
//print(12) 3 4//�Ƚ�12��ÿλ��ӡ���ٴ�ӡ3���ٴ�ӡ4
//print(1) 2 3 4//�Ƚ�1��ӡ���ٴ�ӡ2���ٴ�ӡ3���ٴ�ӡ4
/*
#include <stdio.h>
void print(unsigned int n)
{
	if (n > 9)//˵��n��һ����λ�����ϵ���
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
//ģ10�����ö�Ӧλ�ϵ�������10��������λ����һλ
int main()
{
	unsigned int num = 0;
	scanf("%d", &num);//1234
	//���õݹ麯��
	print(num);
	return 0;
}
*/
//�ݹ��������Ҫ����:
//1�����������������������������������ʱ�򣬵ݹ�㲻�ټ�����
//2��ÿ�εݹ����֮��Խ��Խ�ӽ��������������

//���磺��д��������������ʱ���������ַ����ĳ��ȡ�
/*
#include <stdio.h>
int main()
{
	char arr[] = "bit";
	int len = strlen(arr);
	printf("len = %d\n", len);
	return 0;
}
*/

/*
#include <stdio.h>
int my_strlen(char* str)//str��һ��ָ�����
{
	int count = 0;
	while (*str != '\0')
	{
		count++;//������ʱ����
		str++;//ָ��ĵ�ַ��1������ÿһ��Ԫ�صĵ�ַ�ǰ�˳�����е�
	}
	return count;
}
int main()
{
	//ģ��ʵ��һ��strlen����
	char arr[] = "bit";
	int len = my_strlen(arr);//arr�����飬���鴫�Σ�����ȥ�Ĳ����������飬������Ԫ�صĵ�ַ
	printf("len = %d\n", len);
	return 0;
}
*/

//�ݹ�˼�룺���»�С
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("\0")
//1+1+1+0
/*
#include <stdio.h>
int my_strlen(char* str)//str��һ��ָ�����
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1); 
	else
		return 0;
}
int main()
{
	//ģ��ʵ��һ��strlen����
	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("len = %d\n", len);
	return 0;
}
*/

//9������������ѭ�����ӣ�һ����һ����
//���磺��n�Ľ׳ˡ��������������
/*
//ѭ������ʵ�֣�!n = 1 * 2 * 3 * 4 * ... * n
#include <stdio.h>
int Fac(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}
//ѭ������ʵ�֣�!n = n * n-1 * n-2 * n-3 * ... * 1
int factorial(int n)
{
	int result = 1;
	while (n > 1)
	{
		result *= n;
		n -= 1;
	}
	return result;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}
*/
//�ݹ�ʵ��
//�׳���ѧ��ʽ��
//Fac(n) = 1 (n <= 1)
//Fac(n) = n * Fac(n - 1) (n > 1)
/*
#include <stdio.h>
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}
*/

//���磺���n��쳲����������������������1 1 2 3 5 8 13 21 34 55... ��ǰ������֮�͵��ڵ���������
//쳲���������ѧ��ʽ��
//Fib(n) = 1 (n <= 2)
//Fib(n) = Fib(n - 1)+Fib(n - 2) (n > 2)
/*
#include <stdio.h>
//����ôʵ���������
int Fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);//����ô���������������ôʵ���������---TDD������������
	printf("%d\n", ret);
	return 0;
}
*/
//ȱ�㣺�����Ե���Խ�󣬼����ִ�еĽ��ҲԽ��
//�磺50
//            50
//	    49         48
//	48    47    47    46
//47 46 46 45 46 45 45 44
//...
//�����40���۲������쳲��������ظ������˶��ٴ�
/*
#include <stdio.h>
int count = 0;
int Fib(int n)
{
	if (n == 3)//���Ե�����쳲��������ļ������
		count++;
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret = %d\n", ret);
	printf("count = %d\n", count);
	return 0;
}
*/
//�����40��쳲������������ֵ�����쳲��������ظ�������39088169��

//�޸Ĵ��룺
//ѭ������ʵ��
// 1 1 2 3 5 8 13 21 34 55...
// a b c
// 1 1 2 3 5 8 13 21 34 55... 
//   a b c
// 1 1 2 3 5 8 13 21 34 55... 
//     a b c
// 1 1 2 3 5 8 13 21 34 55... 
//       a b c...
/*
#include <stdio.h>
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;//c = 1���ܳ�ʼ��Ϊ0������n<=2����c=0
	while (n > 2)
	{
		c = a + b;//�ȼ���c�����ƶ�a��b
		a = b;
		b = c;
		n--;//ע��ÿ��ѭ����Ҫ�ӽ�n > 2
	}
	
	return c;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret = %d\n", ret);
	return 0;
}
*/
//ע�����������ջ���
//ע�⣺�����ǵݹ����������������Ĵ����һ��û������
//�磺
/*
#include <stdio.h>
void test(int n)
{
	if (n < 10000)
		test(n + 1);
}
int main()
{
	test(1);
	return 0;
}
*/
//���ԣ��ᷢ��ջ���

//��������;
//1����ŵ������
//��3�����ӣ����е�һ�������ϰ��մ�С�����˳������ 64 ���ƽ�Բ�̡�
//�����е�Բ���ƶ�����һ�������ϣ��ƶ������б����������¹���
//1. ÿ��ֻ���ƶ�������˵�һ��Բ�̣�
//2. ÿ�������ϣ�СԲ����ԶҪλ�ڴ�Բ��֮�ϣ�

//A,B,C��������
//��ʼʱ������AΪ��ʼ����BΪĿ������CΪ������
//��1��Բ��Ϊ����
//1��ֱ�ӽ���ʼ����Բ���ƶ���Ŀ������

//��2��Բ��Ϊ����
//1���Ƚ���ʼ����ǰ1��Բ�̣��Ƶ��������ϣ��ٽ���ʼ�����һ��Բ�̷ŵ�Ŀ�����ϣ�
//2����󽫸������ϵ�Բ�̷ŵ�Ŀ�����ϡ�

//��3Բ��Ϊ����
//1����ʼ��A��3��Բ��,�Ƚ���ʼ��A��ǰ2��Բ�̷ŵ�������C�ϣ��ٽ���ʼ��A���һ��Բ�̷ŵ�Ŀ����B��,
	//����ν���ʼ��Aǰ2��Բ�̷ŵ�������C�ϣ�
	//3����ʼ��A��2��Բ��,�Ƚ���ʼ��A��ǰ1��Բ�̷ŵ�������C�ϣ��ٽ���ʼ��A���һ��Բ�̷ŵ�Ŀ����B��,
	//4����ʱ������C��1��Բ��,��󽫸������ϵ�Բ�̷ŵ�Ŀ����B�ϡ�
//2����ʱ������C��2��Բ��,��󽫸������ϵ�Բ�̷ŵ�Ŀ����B�ϡ�
	//����ν�������Cǰ2��Բ�̷ŵ�Ŀ����B�ϣ�
	//5��������C��Ϊ��ʼ������ʼ��A��Ϊ��������
	//������ʼ����C��2��Բ��,�Ƚ���ʼ��C��ǰ1��Բ�̷ŵ�������A�ϣ��ٽ���ʼ��C���һ��Բ�̷ŵ�Ŀ����B��,
	//6����󽫸�����A�ϵ�Բ�̷ŵ�Ŀ����B�ϡ�

/*
���ɣ����ڼ��蹲��n�����ӣ���n>=2����ʱ����n�����������n-1������
��Ϊһ�����壬��������n-1���Ӻ͵�n���ӣ�����Ϊ��
1. �Ȱ�����һ���n-1���ӷŵ�B���棬C��Ϊ������(��ʱA����ʼ�㣬B��Ŀ��㣬C�Ǹ�����)
2. ������n���Ӵ�Aֱ���ƶ�C����
3. �ٰ�B�������һ���n-1���Ӵ�B�ƶ���C���棬A��Ϊ����(��ʱBΪ�����㣬CΪĿ��㣬AΪ������)
*/

//1��Բ���Ƶ�1��  2^1-1
//2��Բ���Ƶ�3��  2^2-1
//3��Բ���Ƶ�7��  2^3-1
//n��Բ���Ƶ� 2^n-1 ��
/*
#include <stdio.h>
//ͳ���ƶ�����
int i = 1;
void move(char sou, char tar)
{
	printf("��%-2d��:�� %c �ƶ��� %c\n", i, sou, tar);
}
//sou��ʼ��    tarԲ��Ҫ�ƶ�����������    aux������
void hanoi(int num, char sou, char tar, char aux) {
	//���Բ���������� 1 ������ֱ�Ӵ���ʼ���ƶ���Ŀ����
	if (num == 1) {
		move(sou, tar);
		i++;
	}
	else {
		//�ݹ���� hanoi() �������� num-1 ��Բ�̴���ʼ���ƶ�����������
		hanoi(num - 1, sou, aux, tar);
		//����ʼ����ʣ������һ����Բ���ƶ���Ŀ������
		move(sou, tar);
		i++;
		//�ݹ���� hanoi() ���������������ϵ� num-1 Բ���ƶ���Ŀ������
		hanoi(num - 1, aux, tar, sou);
	}
}
int main()
{
	//���ƶ� 3 ��Բ��Ϊ������ʼ����Ŀ�������������ֱ��� A��B��C ��ʾ
	hanoi(3, 'A', 'B', 'C');
	return 0;
}
*/

//2��������̨������---����һ���顶��ָoffer��
/*��һֻ���ܣ�ÿ�ο�����1��̨�ף�Ҳ������2��̨�ף�������n��̨�ף��ʸ�ֻ����һ���ж������㷨��*/
//�������˼·��������̨�׵�������ʵ�ǳ�����쳲��������е�����

//���裺��n�ֱ����0,1,ʱ,����f(n)�����м�������?
//n = 0ʱ��f(0) = 0;
//n = 1ʱ��f(1) = 1;
//n = 2ʱ��f(2) = 3;
//n = 3ʱ��f(3) = f(2) + f(1);
//n = 4ʱ��f(4) = f(3) + f(2);
//...
//n = nʱ��f(n) = f(n-1) + f(n-2);

//�ݹ�ʵ��:
/*
#include <stdio.h>
int Func(int n){
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1 ;
	}
	if (n == 2){
		return 2;
	}
	if (n>=3){
		return Func(n-1) + Func(n-2);
	}
}
int main(){
	int n = 0;
	printf("����������һ��Ҫ����̨������: \n");
	scanf("%d",&n);
	printf("%d\n", Func(n));
	return 0;
}
*/

//ѭ������ʵ��
//̨���� 0 1 2 3 4 5 6  7  8  9...    n
//������ 0 1 2 3 5 8 13 21 34 55...
//		   a b c
//       0 1 2 3 5 8 13 21 34 55...
//           a b c
//       0 1 2 3 5 8 13 21 34 55...
//             a b c
// 1 1 2 3 5 8 13 21 34 55... 
//               a b c...
/*
#include <stdio.h>
int Func(int n){
	// i������̨������ n����һ����̨������
	int last1 = 1;
	int last2 = 2;
	int cur;
	int i;
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1 ;
	}
	if (n == 2){
		return 2;
	}
	for (i = 3;i<= n;i++){
		cur = last1 + last2;
		last1 = last2;
		last2 = cur;
	}
	return  cur ;
}
int Func(int n){
   //n����һ����̨������
	int a = 1;
	int b = 2;
	int c = 0;
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1 ;
	}
	if (n == 2){
		return 2;
	}
	while(n >= 3) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return  c ;
}
int Func(int n) {
	//n����һ����̨������
	int a = 1;
	int b = 2;
	int c = 0;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	int i = 3;//��3λ�ÿ�ʼ�ƶ�
	while (i <= n)
	{
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	return  c;
}
int main(){
	int n ;
	printf("����������һ��Ҫ����̨������: \n");
	scanf("%d",&n);
	printf("%d\n", Func(n));
	return 0;
}
*/