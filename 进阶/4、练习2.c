#define _CRT_SECURE_NO_WARNINGS 1
//��ҵ��
//1�����г���ε�������Ϊ��
/*
#include <stdio.h>
int main()
{
	unsigned long pulArray[] = { 6,7,8,9,10 };
	unsigned long* pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 3) += 3;
	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
	//	6		7		8		9		10
	//	|pulPtr					|pulPtr + 3
	//*(pulPtr + 3) = 9
	//����*(pulPtr + 3) = y����y += 3;y = 12 
	return 0;
}
*/
//A.9,12
//B.6,9
//��ȷ��C.6,12
//D.6,10

//2�����ڶ���ָ��������ȷ���ǣ�
//A.����ָ��Ҳ��ָ�룬ֻ������һ��ָ�����
//��ȷ��B.����ָ��Ҳ��ָ�룬����������һ��ָ��ĵ�ַ
//C.����ָ���������������ĵ�ַ
//D.����ָ��Ĵ�С��4���ֽ�

//3���������ָ������˵����ȷ���ǣ�
//A.����ָ��+1�����ƫ��һ���ֽ�
//B.ָ��-ָ��õ�����ָ���ָ��֮����ֽڸ�����Ӧ��ΪԪ�ظ�����
//��ȷ��C.����ָ������ò�������4���ֽ�
//D.ָ�벻�ܱȽϴ�С

//4�������ĸ���ָ�����飺
//��ȷ��A.int* arr[10];
//B.int* arr[];
//C.int** arr;
//D.int (*arr)[10];//����ָ��

//5���ַ�������
//дһ����������������һ���ַ���������
#include <stdio.h>
#include <string.h>
#include <assert.h>
/*
void reverse(char arr[]) //adcdf\0
{
	assert(arr);
	int len = strlen(arr);//������\0
	char left = 0;//��һ��Ԫ�ص��±�
	char right = len - 1;//���һ����\0Ԫ�ص��±�
	while (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
*/
/*
void reverse(char* str)
{
	assert(str);//��ָ֤�����Ч��
	int len = strlen(str);
	char* left = str;//��һ��Ԫ�صĵ�ַ
	char* right = str + len - 1;//���һ����\0Ԫ�صĵ�ַ
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
*/
/*
int main()
{
	char arr[256] = { 0 };
	scanf("%s", arr);//scanf�����������ַ��������пո񣬷��������ո��ڶ�ȡ������ַ�
	reverse(arr);//����Ҫ��Ԫ�ظ������ַ�������ͨ��strlen��֪Ԫ�ظ��������ʹ��sizeof()��Ҫ��Ԫ�ظ���
	printf("%s\n", arr);

	return 0;
}
*/
/*
int main()
{
	char arr[256] = { 0 };
	//scanf("%s", arr);
	//char* gets( char* buffer );�ӱ�׼�������ж�ȡһ�У����ӱ�׼�������ж�ȡ�����ݷ��뵽buffer��
	gets(arr);//��ȡһ�У�MSDN�鿴gets��ʹ�ã������ݷ���buffer
	reverse(arr);
	printf("%s\n", arr);

	return 0;
}
*/

//6���������
//��Sn = a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a����һ������
//���磺2+22+222+2222+22222
/*
#include <stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	scanf("%d%d", &a, &n);
	int sum = 0;
	int i = 0;
	int ret = 0;
	for (i = 0; i < n; i++)
	{
		//2
		//2 + 22
		//2 + 22 + 222
		//2 + 22 + 222 + 2222
		//2 + 22 + 222 + 2222 +22222
		//��һ�� = ǰһ��a * 10 + a
		ret = ret * 10 + a;
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;
}
*/

//7����ӡˮ�ɻ���
//���0-100000֮������С�ˮ�ɻ����������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ǡ�õ��ڸ�������
//�磺153 = 1^3 + 5^3 + 3^3����153��һ����ˮ�ɻ�����
/*
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�i�Ƿ�Ϊˮ�ɻ�������������
		//1������i��λ�� - nλ��
		int n = 1;//�����ʼ��Ϊ1
		//123/10��n++
		//12/10��n++
		//1/10
		int tmp = i;
		//while (i / 10)//���ﲻ��ֱ����i������ı���i��ֵ����Ϊ���滹Ҫ�õ�i��ԭʼֵ
		//{
		//	n++;
		//	i /= 10;//��λ
		//	//�����ѭ��������i/10 iû�иı�,���Ժ�i /= 10;�ϲ�����Ϊtmp /= 10
		//}
		while (tmp /= 10)//����tmp����ֱ����i������ı���i��ֵ
		{
			n++;
			//i /= 10;
			//�����ѭ��������i/10 iû�иı�,���Ժ�i /= 10;�ϲ�����Ϊtmp /= 10
		}
		//2������i,�õ�ÿһλ������ÿһλ��n�η�֮�� - sum
		//123%10 = 3��3^n
		//123/10 = 12
		//12%10 = 2��2^n
		//12/10 = 1
		//1%10 = 0��1^n
		int sum = 0;
		tmp = i;//������tmpΪi
		while (tmp)
		{
			sum += pow(tmp % 10, n);//�η�����������һ��double�͵���������ǿ������ת��
			tmp /= 10;
		}
		//3���Ƚ�i���sum�Ĵ�С
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
*/

//8����ӡ����
//��C��������Ļ�������������ͼ��
//n��Ҫ��ӡ������������Ϊ7
//                       n-1-i    i=0     2*i+1     
//                      �ո����           *���� 
//          &&&&&&*          6 - ��һ��0 - 1
//          &&&&&***         5 - �ڶ���1 - 3
//          &&&&*****        4 - ������2 - 5
//          &&&*******       3 - ������3 - 7
//          &&*********      2 - ������4 - 9
//          &***********     1 - ������5 - 11
//          *************    0 - ������6 - 13
//          &***********     1 - ��һ��0 - 11 = 2*6-1
//          &&*********      2 - �ڶ���1 - 9  = 2*5-1
//          &&&*******       3 - ������2 - 7  = 2*4-1
//          &&&&*****        4 - ������3 - 5  = 2*3-1
//          &&&&&***         5 - ������4 - 3  = 2*2-1
//          &&&&&&*          6 - ������5 - 1  = 2*1-1
//                           i    i=0      2*(n-1-i)-1
/*
#include <stdio.h> 
int main()
{
	int line = 0;
	scanf("%d", &line);//������������Ǵ�ӡ������һ��
	//��ӡ�ϰ벿�֣�����
	int i = 0;
	for (i = 0; i < line; i++)//��������
	{
		int j = 0;
		//1����ӡ�ո�
		for (j = 0; j < line - 1 - i; j++)//����ÿһ�еĿո���
		{
			printf(" ");
		}
		//2����ӡ�Ǻ�
		for (j = 0; j < 2 * i + 1; j++)//����ÿһ�е��Ǻ���
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿�֣�����
	for (i = 0; i < line - 1; i++)//��������
	{
		int j = 0;
		//1����ӡ�ո�
		for (j = 0; j <= i; j++)//����ÿһ�еĿո���
		{
			printf(" ");
		}
		//2����ӡ�Ǻ�
		for (j = 1; j <= 2 * (line - 1 - i) - 1; j++)//����ÿһ�е��Ǻ���
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
*/

//1���������´��룺
/*
struct student
{
	int num;
	char name[32];
	float score;
}stu;
*/
//���������������ȷ���ǣ�
//A.struct�ǽṹ�����͵Ĺؼ���
//B.struct student ���û�����Ľṹ������
//C.num��score���ǽṹ���Ա��
//��ȷ��D.stu���û�����Ľṹ��������

//2���������Ҫ������ṹ���Աa�����ݣ����²���������ߴ��������ǣ�
/*
#include <stdio.h>
struct S
{
	int a;
	int b;
};
int main()
{
	struct S a, *p = &a;
	a.a = 99;
	printf("%d\n", ______);
	return 0;
}
*/
//A.a.a
//��ȷ��B.*p.a//.�����ȼ���*��
//C.p->a
//D.(*p).a

//3�����������������ǣ�
/*
#include <stdio.h>
struct stu
{
	int num;
	char name[10];
	int age;
};
void fun(struct stu* p)
{
	printf("%s\n", (*p).name);
}
int main()
{
	struct stu students[3] = { {9801,"zhang",20},{9802,"wang",19},{9803,"zhao",18} };
	fun(students + 1);
	return 0;
}
*/
//A.zhang
//��ȷ��B.wang
//C.zhao
//D.18

//4���ṹ����ʳ�Ա�Ĳ�������������
//A..������
//B.->������
//C.*�����ò�����
//��ȷ��D.sizeof

//5������ˮ����
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ
//  20Ԫ - 20ƿ�ȵ� - 20��ƿ
//��10ƿ - 10ƿ�ȵ� - 10��ƿ
//�� 5ƿ  - 5ƿ�ȵ� -  5��ƿ
//�� 2ƿ  - 2ƿ�ȵ� -  2+1=3��ƿ
//�� 1ƿ  - 1ƿ�ȵ� -  1+1=2��ƿ
//�� 1ƿ  - 1ƿ�ȵ� -  1��ƿ
/*
#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;//�ȵ�������
	int empty = 0;//��ƿ�ĸ���
	scanf("%d", &money);
	//���������ˮ�ȵ�������
	total = money;
	empty = money;
	//����������ˮ
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;//�һ�����ˮ��ƿ + ���²��ܶһ���ƿ
	}
	printf("total = %d\n", total);
	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;//�ȵ�������
	int empty = 0;//��ƿ�ĸ���
	scanf("%d", &money);
	//money��total���ڣ�total = 2 * money - 1�Ĺ�ϵ
	if (money == 0)
		total = 0;
	else
		total = 2 * money - 1;
	printf("total = %d\n", total);
	return 0;
}
*/

//1��C���򳣼��Ĵ�����಻������
//A.�������
//B.���Ӵ���
//��ȷ��C.ջ���
//D.����ʱ����

//2������VS���Կ�ݼ�˵��������ǣ�
//��ȷ��A.F5�ǿ�ʼִ�У�������
//B.F10������̵��ԣ��������������뺯��
//C.F11���������ԣ����Թ۲���Ե�ÿ��ϸ��
//D.F9�����öϵ��ȡ���ϵ�
//ע�⣺F5��ʼ���ԣ�ctrl + F5��ʼִ�У�������

//3������Debug��Release������˵��������ǣ�
//A.Debug����Ϊ���԰汾�����������bug�İ汾
//B.Release����Ϊ�����汾��������Ա���Եľ���Release�汾
//C.Debug�汾����������Ϣ�������Ż�
//��ȷ��D.Release�汾Ҳ��Ҳ���ԣ�ֻ���������Ż��������С�������ٶ���Ч������

//4�����¹���ָ���˵����ȷ���ǣ�
//A.int *const p��int const *p�ȼ�
//B.const int *p��int *const p�ȼ�
//��ȷ��C.const int *p��int const *p�ȼ�
//D.int *p[10]��int (*p)[10]�ȼ�
//ע�⣺const��*��ͬһ�ߣ����ε�Ч����ͬ

//5��������һ����ʽ������һ��ָ��char���ͱ�����ָ��p��p��ֵ�������޸ģ���pָ��ı�����ֵ�����޸ģ�
//A.const char *p
//B.char const *p
//��ȷ��C.char *const p
//D.const char *const p

//6��������ѭ������
//VS����������������Ĵ��룬��ͼ����������������
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hello bit\n");
	}
	return 0;
}
*/
//Խ����ʣ�����i = 12ʱ&arr[12]��&i�ĵ�ַ��ͬ

//7��strlenʵ��
//ģ��ʵ�ֿ⺯��strlen
/*
#include <assert.h>
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
*/

//8��strcpyʵ��
//ģ��ʵ�ֿ⺯��strcpy 
/*
#include <assert.h>
char* my_strcpy(char* dest, const char* sour)
{
	assert(dest && sour);
	char* tmp = dest;
	while (*sour != '\0')
	{
		*dest++ = *sour++;
	}
	*dest = *sour;

	return tmp;
}
*/

//9����������ż��˳��
//��������ʹ����ȫ����λ��ż��ǰ��
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��.
//10 3 6 8 7 9 4 3 5 1
//1.�������һ��ż��
//2.���ұ���һ������
//3.���߽���
/*
#include <stdio.h>
void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//�����ż��
		while ((left < right) && (arr[left] % 2 == 1))//(left < right)�����������,����Ҫ����,������ܷ���Խ��(����ȫ����)
		{//���������������һ��
			left++;
		}
		//�ҵ����������±�

		//�ұ�������
		while ((left < right) && (arr[right] % 2 == 0))//(left < right)�����������,����Ҫ����,������ܷ���Խ��(����ȫż��)
		{//�����ż��������һ��
			right--;
		}
		//�ҵ���ż�����±�

		//1 3 4 5 8 0 2
		if (left < right)//����жϿ���ʡ����Ϊ����left��right�±���ȣ�ֻ�Ƕ�����һ�ν�������
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	Print(arr, sz);
	return 0;
}
*/

//1��ԭ�롢���롢����˵��������ǣ�
//A.һ������ԭ�����������ֱ��ת���ɶ�����
//B.������ԭ��Ķ����Ʒ���λ���䣬����λ��λȡ��
//C.�����Ƿ���Ķ����Ƽ�1
//��ȷ��D.ԭ�롢���롢��������λ��0��ʾ���������λ��1��ʾ����

//2�����ڴ�С���ֽ����������ȷ���ǣ�
//A.��С���ֽ���ָ���������ڵ����ϴ洢�Ķ�����˳��
//��ȷ��B.��С���ֽ���ָ���������ڵ��Դ洢���ֽ�˳��
//C.����ֽ����ǰ����ݵĸ��ֽ����ݴ�ŵ��ߵ�ַ�����ֽ����ݴ���ڵ͵�ַ��
//D.С���ֽ����ǰ����ݵĸ��ֽ����ݴ�ŵ��͵�ַ�����ֽ����ݴ���ڸߵ�ַ��
//���ֽ����ݷ��ڵ͵�ַ�� - ��� 
//���ֽ����ݷ��ڵ͵�ַ�� - С��

//3�������ִ�н��Ϊ��
/*
#include <stdio.h>
int main()
{
	//unsigned char - 1���ֽ�-8bit��0-255��
	unsigned char a = 200;
	//200 - 00000000 00000000 00000000 11001000(����)
	//a = 11001000(����)
	unsigned char b = 100;
	//100 - 00000000 00000000 00000000 01100100(����)
	//b = 01100100(����)
	unsigned char c = 0;
	c = a + b;
	//a + b��������������a��b���޷���char���ͣ���λ��0
	//a = 00000000 00000000 00000000 11001000(����)
	//b = 00000000 00000000 00000000 01100100(����)
  //a+b = 00000000 00000000 00000001 00101100(����) 
	//c = 00101100(����) 
	printf("%d %d", a + b, c);
	//%d - ��ʮ�����з���ԭ����ʽ��ӡ
	//a+b�Ĳ��� = 00000000 00000000 00000001 00101100 
	//a + b ��û�д����ڴ棬��Ϊ300
	//c��%d��ӡ�����ַ���������������c���޷���char���ͣ���λ��0
	//c = 00000000 00000000 00000000 00101100(����) 
	//��cΪ44
	//ע�⣺���е�����������������Ĳ������㣬��ӡ����ԭ��
	return 0;
}
*/
//A.300 300
//B.44 44
//��ȷ��C.300 44
//D.44 300
//�عˣ�
//Ϊ�˻��������ȣ����ʽ�е� �ַ� �� ������ ��������ʹ��֮ǰ��ת��Ϊ��ͨ���ͣ�����ת����Ϊ����������
//���ĳ���������ĸ������������ڲ�ͬ�����ͣ���ô��������һ����������ת��Ϊ��һ�������������ͣ�����������޷����С�����ת����Ϊ����ת����

//4���� 32λ���ģʽ�������ϱ���b���ڣ�
/*
#include <stdio.h>
int main()
{
	unsigned int a = 0x1234; //4��ʮ������λ������16��������λ�������ֽ�
	//0x1234 = 0x00 00 12 34
	//�ڴ�Ĵ洢��ʽ���͵�ַ00 00 12 34�ߵ�ַ
	unsigned char b = *(unsigned char*)&a;//*�����÷���һ���ֽڵĿռ�
	//����ǿ������ת��������ı�ֵ�Ĵ�С���������÷���һ���ֽڣ���b = 0x00
	printf("%x\n", b);
	//%x - ��ʮ�������з���ԭ����ʽ��ӡ
	return 0;
}
*/
//��ȷ��A.0x00
//B.0x12
//C.0x34
//D.0x1234

//5���������Ľ���ǣ�
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//�з���char�ķ�Χ��-128 ~ 127
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	//���ڻὫ���������char�У���ÿ��Ԫ�ص�ֵ����char�ķ�Χ��
	//a[1000] = {-1,-2,...,-128,127,126,125...1,0,...}
	printf("%d\n", strlen(a));
	return 0;
}
*/
//A.1000
//B.999
//��ȷ��C.255
//D.256

//6���������
//����Ļ�ϴ�ӡ������ǣ���������������ӵ����������
//					����n   �ո���
//    1             ��0��   4 = 4 - 0       
//   1 1			��1��   3 = 4 - 1
//  1 2 1			��2��   2 = 4 - 2
// 1 3 3 1			��3��   1 = 4 - 3
//1 4 6 4 1         ��4��   0 = 4 - 4
//                  ��i��   (n-1) - i

//�������Ϊ��ӡ������ʽ������������ʹ�õĿո񣬼�Ϊ�������
//0 1 2 3 4��
//
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//�۲췢�֣���һ�кͶԽ��߶���1
//�ö�ά����
/*
#include <stdio.h>
int main()
{
	int arr[5][5] = { 0 };
	int i = 0;
	int j = 0;
	//�Զ�ά������г�ʼ��
	for (i = 0; i < 5; i++)//������
	{
		for (j = 0; j < 5; j++)//������
		{
			//��ʼ����һ��
			if(j == 0)
				arr[i][j] = 1;
			//��ʼ���Խ���
			if (i == j)
				arr[i][j] = 1;
			//��ʼ��ʣ��Ԫ��
			if (i >= 2 && j >= 1)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	//��ӡ
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5 - 1 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/
//%2d:��ӡʱ����λ���Ҷ��룬������λ����߿ո��롣
//%-2d:��ӡʱ����λ������룬������λ���ұ߿ո��롣
//%.f:��ӡʱ������ʾС��λ����
//%.2f:��ӡʱ����ʾ��λС����

//7��������
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ��
//����Ϊ4�����ɷ��Ĺ��ʣ�
//A˵��������   ����1��killer != 'a'
//B˵����C		����2��killer == 'c'
//C˵����D		����3��killer == 'd'
//D˵��C�ں�˵	����4��killer != 'd'
//��֪3����˵���滰��1����˵���Ǽٻ�
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//������ĳ����Ϊ���֣���ÿ���˵Ļ�(����)�����ж���٣�Ϊ������1��Ϊ������0
//����������A��
//A˵�Ļ��Ǽٻ�0
//B˵�Ļ��Ǽٻ�0
//C˵�Ļ��Ǽٻ�0
//D˵�Ļ����滰1
//˵��A�������֣���������3�棬1��

//����������B��
//A˵�Ļ����滰1
//B˵�Ļ��Ǽٻ�0
//C˵�Ļ��Ǽٻ�0
//D˵�Ļ����滰1
//˵��B�������֣���������3�棬1��

//����������C��
//A˵�Ļ����滰1
//B˵�Ļ����滰1
//C˵�Ļ��Ǽٻ�0
//D˵�Ļ����滰1

//����������D��
//A˵�Ļ����滰1
//B˵�Ļ��Ǽٻ�0
//C˵�Ļ����滰1
//D˵�Ļ��Ǽٻ�0
/*
#include <stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		//��ÿ�仰�����������������Ϊ3
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf("killer = %c\n", killer);
	}
	return 0;
}
*/
//���Ծ����ῼ�������͵��⡣
//�������⣺��36ƥ����6���ܵ���û�м�ʱ����������ȷ����36ƥ���е�ǰ������
//�������ٱ������Σ�
//һ��6 - 1�� ����6 - 1�� ����6 - 1�� �ġ�6 - 1�� �塢6 - 1�� ����6 - 1�� �����飬6��
//�ٽ�ÿһ��ĵ�һ����1�Σ��õ�ǰ6��
//�����һ���һ����6���У���һ�����ڶ����һ����6���У��ڶ������������һ����6���У�������...
//��󣬽���һ���ĵ�һ��ǰ3�����ڶ����ĵڶ����ǰ�������������ĵ������ǰ1����1�Σ�ʵ����ֻ��Ҫ��һ��ĵ�2�͵�3�����ڶ���ĵ�1��2����������ĵ�1���ٱ�һ��
//��Ϊ��һ������һ��ǰ���������ܱȵڶ�������һ���һ���졣�ڶ�������һ��ǰ���������ܱȵ���������һ���һ���졣
//��6+1+1 = 8��

//�������⣺��25ƥ����5���ܵ���û�м�ʱ����������ȷ����25ƥ���е�ǰ������
//�������ٱ������Σ�
//5 5 5 5 5 - ���
//1 1 1 1 1 - 5 - һ��
//2 2 1 - 5 - һ��
//��5+1+1 = 8��

//�������⣺
//��һ���㣬���ʲ����ȣ�����ÿһ�������㣬ȼ����ǡ����1��Сʱ���ָ���2���㣬����ȷ��һ��15���ӵ�ʱ��Ρ�
//��һ��������ͬʱ����ȼ���ڶ�����Ҳͬʱ��ȼ��ֻ��ȼһ�ˣ��ʵ�һ������Ҫ���Сʱȼ�����ڶ�����Ҳ��ȼ�˰��Сʱ
//��һ�����ȼ�꣬�����Сʱ����ͬʱ��ȼ�ڶ��������һ�ˣ�����Ҫ��15����
//ţ����ˢ�����⡣--������/˼ά��

//8��������
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ���  ����1��b==2 ����2��a==3
//Bѡ��˵���ҵڶ���E����  ����1��b==2 ����2��e==4
//Cѡ��˵���ҵ�һ��D�ڶ�  ����1��c==1 ����2��d==2
//Dѡ��˵��C����ҵ���  ����1��c==5 ����2��d==3
//Eѡ��˵���ҵ��ģ�A��һ  ����1��e==4 ����2��a==1
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������ 
//ÿ�仰����������֮��Ϊ1����þ仰Ϊ��
/*
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3) == 1) &&
							((b == 2) + (e == 4) == 1) &&
							((c == 1) + (d == 2) == 1) &&
							((c == 5) + (d == 3) == 1) &&
							((e == 4) + (a == 1) == 1))
						{
							//�������εĳ˻� = 1 * 2 * 3 * 4 * 5 = 120
							if (a * b * c * d * e == 120)//��һ���Ǳ�Ҫ�ģ��������������ε�����
								printf("a = %d b = %d c = %d d = %d e = %d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	return 0;
}
*/

//9�����ô�����ϰ�뱾���ⲩ��
//1.��ͬѧ��������ɿ��ô���ı�д
//2.���ݱ��ڿν��⣬���漰���ĺ���֪ʶ�㣬��������дһƪ����
//3.�Բ������ӵķ�ʽ���ύ������ҵ
//���������������Ӻ�gitub����

//1��������ڡ�ָ�롱����������ȷ���ǣ�
//��ȷ��A.��ʹ��free�ͷŵ�һ��ָ�����ݺ�ָ�������ֵ����Ϊ��NULL
//B.32λϵͳ���κ����͵�ָ��ĳ��ȶ���4���ֽ�
//C.ָ�������������������ָ��ʵ��ָ�����ݵ���������
//D.Ұָ����ָ��δ��������Ѿ��ͷŵ��ڴ��ַ
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//����ռ�
	int *p = (int*)malloc(10 * sizeof(int));//malloc���ڴ�����10��int��С�Ŀռ�
	//����malloc�������������ǣ�void*��
	//malloc�����ķ���ֵ��������Ŀռ�ĵ�ַ���أ�����ָ��int*���ͽ��գ�����Ҫ�Ե�ַ����ǿ������ת��
	
	//ʹ�ÿռ�
	//......
	*p = 10;//���ռ�ĵ�һ��int�ռ���Ϊ10

	//�ͷſռ�
	free(p);//�ͷ�pָ��Ŀռ��ַ��ͨ�����ԣ�����ִ�е������ǣ�p������û�б���ΪNULL
	//ʵ�����ǣ���pָ��ĸÿռ�ʹ��Ȩ�����˲���ϵͳ����ʱpָ��ĸÿռ��ַ�����Ǹ���ַ��ָ��Ŀռ�����ݱ�Ϊ�����ֵ
	p = NULL;
	return 0;
}
*/

//2�������������������ȷ���ǣ�
/*  char* p = "hello bit";  */
//A.���ַ���hello bit����p������
//B.���ַ���hello bit�ĵ�һ���ַ������p������
//��ȷ��C.���ַ���hello bit�ĵ�һ���ַ��ĵ�ַ�����p������
//D.*p�ȼ���hello bit��*p�ȼ���h��

//3����������ָ���������ȷ���ǣ�
//A.����ָ����һ������
//B.����ָ����һ�ִ�������ָ�루��ŵ�������ĵ�ַ����ָ�������ָ�룬�����Ǵ�ŵ�������ָ��,��������ָ�룬Ӧ��������ָ������飩
//��ȷ��C.����ָ����һ��ָ��
//D.ָ��������һ��ָ�������ָ��
//int arr[10];//����
//int (*p)[10] = &arr;//����ָ��
//int (*(*pointer))[10] = &p;//����ָ���ָ��
//int (*(pointer[5]))[10] = { p };//����ָ�������

//4�������ĸ�������ָ�룺
//A.int** arr[10]
//B.int (*arr[10])
//��ȷ��C.char* (*arr)[10]
//D.char (*)arr[10]

//5�������ĸ������Ǵ���ģ�
/*
#include <stdio.h>
int mian()
{
	int* p = NULL;
	int arr[10] = { 0 };
	
	return 0;
}
*/
//A.p = arr;
//B.int (*ptr)[10] = &arr;
//C.p = &arr[0];
//��ȷ��D.p = &arr;(�������ǿ������ת��Ϊint*)

//6��������������������������ȷ���ǣ�
/*
#include <stdio.h>
int mian()
{
	int arr[10] = { 0 };

	return 0;
}
*/
//��ȷ��A.������arr��&arr��һ����
//B.sizeof(arr)����ʱarr��ʾ��������
//C.&arr����ʱarr��ʾ��������
//D.����sizeof(arr)��&arr�е��������������ط����ֵ�������arr������������Ԫ�صĵ�ַ

//7����ζ���һ��int���͵�ָ�����飬����Ԫ�ظ���Ϊ10����
//A.int a[10];
//B.int (*a)[10];
//��ȷ��C.int *a[10];
//D.int (*a[10])(int);//����ָ������

//8���������ִ�н���ǣ�
/*
#include <stdio.h>
int main()
{
	char str1[] = "hello bit";//�����ַ���
	char str2[] = "hello bit";//�����ַ���
	char* str3 = "hello bit";
	char* str4 = "hello bit";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	return 0;
}
*/
//A.str1 and str2 are same      str3 and str4 are same
//B.str1 and str2 are same      str3 and str4 are not same
//��ȷ��C.str1 and str2 are not same  str3 and str4 are same
//D.str1 and str2 are not same  str3 and str4 are not same

//1�������ĸ��Ǻ���ָ�룿
//A.int* fun(int a, int b);//��������
//B.int(*)fun(int a, int b);//err
//��ȷ��C.int (*fun)(int a, int b);//����ָ��
//D.(int*)fun(int a, int b);//��������

//2������һ������ָ�룬ָ��ĺ���������int�ββ��ҷ���һ������ָ�룬 
//���ص�ָ��ָ��һ����һ��int�β��ҷ���int�ĺ����������ĸ�����ȷ�ģ�  - - ȥ��(*F)(int,int)��ʣ��ľ��Ǻ���ָ��ķ�������
//��ȷ��A.int (*(*F)(int,int))(int)//����������int(*)(int)
//B.int (*F)(int,int)//����������int
//C.int (*(*F)(int,int))
//D.*(*F)(int,int)(int)
//�عˣ�
//int(*)(int) (*pf)(int, int);������д�Ǵ����
//int (*(*F)(int, int))(int);
//int Add(int a, int b);
//int (*pF)(int, int) = Add;//����ָ��
//int arr[10];
//int (*pA)[10] = &arr;//����ָ��

//3������Ϸ����У���������ݲ�ͬ����Ϸ״̬���ò�ͬ�ĺ��������ǿ���ͨ������ָ����ʵ����һ���ܣ�
//�����ĸ��ǣ�һ������Ϊint*������ֵΪint�ĺ���ָ�룺
//A.int (*fun)(int)
//��ȷ��B.int (*fun)(int*)
//C.int* fun(int*)
//D.int* (*fun)(int*)

//4������һ��ָ����10��Ԫ�ص������ָ�룬����ÿһ��Ԫ����һ������ָ�룬�ú����ķ���ֵ��int
//������int*����ȷ���ǣ�- - ��������һ��ָ�룬����ָ�������ָ�룬int (*F)(int*),int (*(*Farr)[10])(int*)
//A.(int *p[10])(int*)
//B.int [10]*p(int*)
//��ȷ��C.int(*(*p)[10](int*))
//D.int ((int*)[10])*p

//5���������º���void fun(int n,char *s){......}������Ժ���ָ��Ķ���͸�ֵ������ȷ���ǣ�
//A.void (*pf)(int,char);pf = &fun;
//��ȷ��B.void (*pf)(int n,char *s); pf = fun;
//C.void *pf();*pf = fun;
//D.void *pf();pf = fun;

//1�����ڻص���������������ǣ�
//A.�ص���������һ��ͨ������ָ����õĺ���
//B.�ص�����һ��ͨ������ָ��ʵ��
//C.�ص�����һ�㲻�Ǻ�����ʵ�ַ����ã��������ض��ĳ����£�����һ������
//��ȷ��D.�ص������ǵ��ú���ָ��ָ�����ĺ���

//2������test���������ȷ���ǣ�(��ѡ��)BD
/*
	char* arr[5] = {"hello","bit"};
	test(arr);
*/
//A.void test(char* arr);
//B.void test(char** arr);
//C.void test(char arr[5]);
//D.void test(char* arr[5]);
//ע�⣺����Ĳ���������������ƺ���ʱ�βο��������飬Ҳ��Ҳ��ָ��

//3�����������print_arr������������ĸ�����ȷ�ģ�
/*
	int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
	print_arr(arr,3,5);
*/
//A.void print_arr(int arr[][],int row,int col);
//B.void print_arr(int* arr,int row,int col);
//��ȷ��C.void print_arr(int (*arr)[5],int row,int col);
//D.void print_arr(int (*arr)[3],int row ,int col);

//4���������Ľ���ǣ�
/*
#include <stdio.h>
int main()
{
	int a[5] = { 5,4,3,2,1 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}
*/
//A.5,1
//��ȷ��B.4,1
//C.4,2
//D.5,2

//5��qsortʹ����ϰ
//��ϰʹ�ÿ⺯����qsort����������͵�����
/*
#include <stdio.h>
#include <stdlib.h >
struct Test
{
	char name[64];
	int age;
};
int compare_by_name(const void* elem1, const void* elem2)
{
	return strcmp(((struct Test*)elem1)->name, ((struct Test*)elem2)->name);
}
int main()
{
	struct Test t[3] = { {"xiaohua",20},{"xiaozhang",28},{"xiaoming",23} };
	//void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2) );
	qsort(t, sizeof(t)/ sizeof(t[0]), sizeof(t[0]), compare_by_name);
	return 0;
}
*/

//6��qsortģ��ʵ��
//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
/*
#include <stdio.h>
struct Test
{
	char name[64];
	int age;
};
int compare_by_name(const void* elem1, const void* elem2)
{
	return strcmp(((struct Test*)elem1)->name, ((struct Test*)elem2)->name);
}
void Swap(char* str1, char* str2, size_t width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *str1;
		*str1 = *str2;
		*str2 = tmp;
		str1++;
		str2++;
	}
}
void my_qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2) )
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare( (char*)base+width*j,(char*)base+width*(j+1) ) > 0)
			{
				//����
				Swap((char*)base + width * j, (char*)base + width * (j + 1), width);
			}
		}
	}
}
int main()
{
	struct Test t[3] = { {"xiaohua",20},{"xiaozhang",28},{"xiaoming",23} };
	//void qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2) );
	my_qsort(t, sizeof(t) / sizeof(t[0]), sizeof(t[0]), compare_by_name);
	return 0;
}
*/

//1���������Ľ���ǣ�
/*
#include <stdio.h>
int main()
{
	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));//*(aa+1) == aa[1]��aa[1]�ǵڶ�������������������ڶ�����Ԫ�صĵ�ַ���˴���ǿ������ת��û������
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
*/
//��ȷ��A.1,6
//B.10,5
//C.10,1
//D.1,5

//2����ת�ַ�����������Ϊ����
//ʵ��һ�����������������ַ����е�k���ַ�
//���磺ABCD����һ���ַ��õ�BCDA��ABCD���������ַ��õ�CDAB
//�����ַ���������Ϊ��abcdef\0
//��һ����ȡ��a
//�ڶ�����bcedf��ǰ�ƶ�
//����������a����ԭ�ȵ�f��
//ͬ�����Ҫ��ת���Σ�������������ƵĲ���(ѭ��2��)
//abcdef  0
//bcdefa  1
//cdefab  2
//defabc  3
//efabcd  4
//fabcde  5
//abcdef  6

//������ⷨ��ָ�����
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void left_move(char* arr, int k)
{
	assert(arr);
	int i = 0;
	//����k���ַ�
	for (i = 0; i < k%strlen(arr); i++)//k > strlen(arr)
	{
		//������ʵ������1���ַ�
		//1������a
		char tmp = *arr;
		//2��bcedf��ǰ�ƶ�
		int j = 0;
		int len = strlen(arr);
		for (j = 0; j < len - 1; j++)//����len = 6���±����Ϊ5�����j < len��j = 5���±�(j+1) = 6Խ�磬��С��len-1
		{
			*(arr + j) = *(arr + j + 1);//����±���len - 1����j���Ϊlen - 1 - 1
		}
		//3����a����ԭ�ȵ�f��
		*(arr + len - 1) = tmp;
	}
}
int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);
	printf("%s\n", arr);
	return 0;
}
*/

//������ⷨ���������
/*
void left_move(char arr[], int k)
{
	int i = 0;
	//����k���ַ�
	for (i = 0; i < k % strlen(arr); i++)
	{
		//������ʵ������1���ַ�
		//1������a
		char tmp = arr[0];
		//2��bcedf��ǰ�ƶ�
		int j = 0;
		int len = strlen(arr);//��Ҫ֪��Ԫ�صĸ���������ͨ��sizeof���룬�������ַ�����Ҳ������strlen
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j+1];
		}
		//3����a����ԭ�ȵ�f��
		arr[len - 1] = tmp;
	}
}
*/

//������ת��
//abcdef
//��һ���������ba
//�ڶ����ұ�����fedc
//��������������cdefab
//ע�⣺�����ܵ�ʵ���ǣ���֪���˵��±ֵ꣬���н���
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
//�����ַ�������
//adcb  -  bcda
void reverse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
//��ת�ַ�������
//   0 k-1 k  len-1  
//   abc   def
void left_move(char* arr,int k)
{
	assert(arr);//�ж�ָ���Ƿ�Ϊ��-����
	int len = strlen(arr);
	assert(k >= 0);//k����С��0
	k %= len;//������ת�ĸ��������ַ����ĳ��ȵĴ���

	reverse(arr, arr + k - 1);//�������
	reverse(arr + k, arr + len - 1);//�����ұ�
	reverse(arr, arr + len - 1);//��������
}
int main()
{
	char arr[] = "abcdef";
	//left_move(arr, 3);
	left_move(arr, 6);
	printf("%s\n", arr);
	return 0;
}
*/

//3���ַ�����ת��� --���ԡ�����Ա��������������������߲��� http://blog.csdn.net/v_july_v
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//���磺����s1 = AABCD��s2 = BCDAA������1.����s1 = abcd��s2 = ABCD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
//AABCD���������ַ��õ�CDAAB
//AABCD���������ַ��õ�BCDAA
//˼·����s1�ַ�����ת1 ~ strlen(s1)�Σ�ÿ����תһ���ַ���Ľ����s2�Ƚϡ�ֻ��Ҫ�ж�һ���������ת����
//��Ϊ����ת�õ�����������ͨ������ת�õ���
//s1          s1��ת����ܵĽ��
//BCDAA   1   CDAAB
//CDAAB   1   DAABC
//DAABC   1   AABCD
//AABCD   1   ABCDA
//ABCDA   1   BCDAA

//����1����ٷ�
//����������תΪ����
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>
void left_move(char* arr, int k)
{
	assert(arr);
	int i = 0;
	//����k���ַ�
	for (i = 0; i < k; i++)
	{
		//������ʵ������1���ַ�
		//1������a
		char tmp = *arr;
		//2��bcedf��ǰ�ƶ�
		int j = 0;
		int len = strlen(arr);
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//3����a����ԭ�ȵ�f��
		*(arr + len - 1) = tmp;
	}
}
int is_left_move(char* s1, char* s2)
{
	//��s1��ת1~k�ε����п��ܽ�������ֱ���s2�Ƚ��Ƿ�����ȵ�
	//��ת�Ŀ��������ַ����ĳ��Ⱦ������磺�ַ����ĳ���Ϊ6������ת�Ŀ��ܽ����6��
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)//��תlen��
	{
		left_move(s1, 1);//ÿ����תһ���ַ�
		//����left_move(s1, 1)��1������i����Ϊÿ����תs1�Ľ�����ᷢ���ı�
		//���磺left_move(s1, i)ʱ
		//��i = 0ʱ��û����ת
		//��i = 1ʱ����ת1�Σ����Ϊbcedfa
		//��i = 2ʱ�������bcdefa�Ļ����ϣ�����ת����
		
		//�Ƚ�ÿ����ת���s1��s2
		int ret = strcmp(s1, s2);
		if (ret == 0)
			return 1;
	}
	//ÿһ�������Զ����������������
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	//����ʹ��char* arr1 ="abcdef";��char* arr2 ="cdefab";
	//��Ϊarr1��arr2ָ��������������ַ����������ַ�����ֵ�������޸�
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
*/

//����2��
//abcdefabcdef
//��s1׷��һ���ַ�������ʱ����������ݰ�����������ת���ܵ��ַ���
//���ж�s2�Ƿ������s1��
/*
#include <stdio.h>
#include <string.h>
int is_left_move(char* str1, char* str2)
{
	//1����str1�ַ�����׷��һ��str1�ַ���
	//strcat(s1,s2)����s2׷�ӵ���s1����
	//ԭ��abc\0����def\0׷�ӵ�abc\0���棬d�ŵ�\0�ϣ�e�ŵ�d�ĺ��棬��f�ŵ�e�ĺ��棬\0�ŵ�f���棬���ַ�\0�������ֹͣ׷��
	//�����abc\0����abc\0׷�ӵ�abc\0���棬a�ŵ�\0�ϣ�b�ŵ�a�ĺ��棬��c�ŵ�b�ĺ��棬����ʱ��һ���ַ�\0��a�����ˣ��ͻ�����׷�ӣ�ֱ��������
	//�����ϣ�������Ϊs1��s2ָ�����ͬһ��ռ䣬����ʹ��strcpy����һ�ݣ���׷��
	//�ܽ᣺����strcat(s1,s1)�������ܸ��Լ�׷��
	//ͨ��MSDN�۲�strcat��strncat�Ĳ�������,count������ָ׷���ַ��ĸ���
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)//��Ҫ��һ���жϳ����Ƿ���ȣ����򣬻�����ֻҪ���Ӵ�������ת�����ģ���Ȼ�����ʡ��磺"bcd"��"abcdefab"
		return 0;
	strncat(str1, str1, len1);
	//2���ж�str2ָ����ַ����Ƿ���str1ָ����ַ������Ӵ�
	//strstr(s1,s2)����s1�У���s2�Ӵ�������ҵ��ˣ������ҵ����ַ�����Ԫ�صĵ�ַ�����򷵻ؿ�ָ��
	char* ret = strstr(str1, str2);
	if (ret == NULL)//NULL�ַ�����ָstdio.h�ж����
		return 0;
	else
		return 1;
}
int main()
{
	char arr1[30] = "abcdef";//ʹ�ø���Ŀռ�
	//char arr2[] = "cdefab";
	char arr2[] = "cdef";//���ַ�������"abcdef"��ת��������Ҫ��һ�����ȵ��жϡ�
	//����arr2�еĳ��ȱ����arr1�ĳ���һ�£������������⡣
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
*/
//ע�⣺δ�����������ÿ⺯�������ÿ⺯��ʵ��

//4�����Ͼ���--���ԡ���ָoffer��
//��һ�����־��󣬾����ÿһ�д������ǵ����ģ�ÿһ�о�����ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�Ҫ��ʱ�临�Ӷ�С��O(N)
//�������¾�����һ���������Ҫ��9���ҵ���ʱ�临�Ӷ���9��
//���һ��������һ���������Ҫ��N���ҵ���ʱ�临�Ӷȵ���O(N)���ʲ���ͨ��������ά����ķ�����
//�磺
//			 y
//			 0     1     2
//  x
//  0		 1     2     3
//  1		 4     5     6
//  2		 7     8     9
//x <=2,y>=0

//			 y
//			 0     1     2
//  x
//  0		 1     2     3
//  1		 2     3     4
//  2		 3     4     5

//1�����ֲ���
//2��k��(���Ͻ�С)ȥ���У�kС(���ϽǴ�)ȥ����(���Ͻǡ����½Ƕ�������Ϊ�ο����������Ͻǡ����½ǲ����ԣ���Ϊ�ο��ı������ų�һ�л�һ��)
//����Ҫ�ҵ�����k��ͨ�����Ͻ�(����������)��3��k�Ƚϣ����3Сk������һ��û��Ҫ�ҵ�Ԫ�أ��ų���һ��
//�����µ����Ͻǵ���6��k�Ƚϣ����6Сk��Ҳ�ų���һ�У�
//����µ����Ͻ�(������С����)��k�󣬼�kС������һ��û��Ҫ�ҵ�Ԫ�أ��ų���һ�У�ֱ���������һ�������ж��Ƿ����
//ע�⣺��������һ�����Ͻǻ����½����ų���(��)�����ų���(��)��Ҳ����ͬʱ�������ϽǺ����½ǣ��к���ͬʱ�ų�
/*
#include <stdio.h>
int FindNum(int arr[3][3], int k, int row, int col)
{
	//���Ͻǵ�����
	int x = 0;
	int y = col - 1;
	while (x <= row - 1 && y >= 0)//ע����ҵ��������Բ���7Ϊ������������Ϊ2���д�2��Ϊ0
	{
		//һ�β���
		if (arr[x][y] > k)
			y--;//ȥ��һ��
		else if (arr[x][y] < k)
			x++;//ȥ��һ��
		else
			//printf("%d %d",x,y);//���ԣ���ӡ���꣬���Ǻ���һ�㲻ʹ�ô�ӡ����ֱ�Ӵ�ӡ
			return 1;//�ҵ���
	}
	//��ѭ������ʱ��û���ҵ�
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	//int k = 7;
	int k = 17;
	int ret = FindNum(arr, k, 3, 3);//�ҵ��ˣ�����1��û�ҵ�������0
	if (ret == 1)
		printf("�ҵ���\n");
	else
		printf("�Ҳ���\n");
	return 0;
}
*/

//����Ľ���
//��β��ں����д�ӡ�ҵ��������±�(x,y) ?
//����1������ṹ��struct XY{ int x;int y};Ȼ�󷵻�����ṹ�����
/*
#include <stdio.h>
struct XY
{
	int x;
	int y;
};
struct XY* FindNum(int arr[3][3], int k, int row, int col, struct XY* p)//�������� - p
{
	//���Ͻǵ�����
	int x = 0;
	int y = col - 1;
	while (x <= row - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			p->x = x;
			p->y = y;
			return p;//�ҵ���
		}
	}
	//��ѭ������ʱ��û���ҵ�
	return NULL;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	//int k = 7;
	int k = 17;
	struct XY st = { 0 };
	//�������� - &st
	struct XY* ret = FindNum(arr, k, 3, 3, &st);//ͨ����ַ���õķ�ʽ������ͨ����ַ�����������st��ֵ
	if (ret == NULL)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ���\n");
		printf("�±�ʱ��(%d, %d)\n", ret->x, ret->y);
	}
	return 0;
}
*/

//����2��
/*
#include <stdio.h>
int FindNum(int arr[3][3], int k, int *px, int *py)//���봫������ - px py
{
	//���Ͻǵ�����
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{	//1��printf("%d %d",x,y);//��ӡ���꣬���Ǻ���һ�㲻ʹ�ô�ӡ����ֱ�Ӵ�ӡ
			//2���ĵ��������x��y��ֵ
			*px = x;
			*py = y;
			return 1;//�ҵ���
		}
	}
	//��ѭ������ʱ��û���ҵ�
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	//sockfd �� �������
	//addr �� ��������
	//addrlen �����봫������ 
	//int bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
	//sockfd �� �������
	//addr �� �������
	//addrlen �� �������
	//�����Ͳ�����&x��&y -- ���봫������
	int ret = FindNum(arr, k, &x, &y);//ͨ����ַ���õķ�ʽ������ͨ����ַ�����������x��y��ֵ
	if (ret == 1)
	{
		printf("�ҵ���\n");
		printf("�±�ʱ��(%d,%d)\n", x, y);
	}
	else
		printf("�Ҳ���\n");
	return 0;
}
*/