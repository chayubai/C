#define _CRT_SECURE_NO_WARNINGS 1
//��ҵ2�� 
//1��ͳ�ƶ�������1�ĸ���
//дһ���������ز�����������(����)1�ĸ���
//�磺15(00000 11111)���4��1   
//����1���˷����ɻ�ȡʮ����ÿλ������������������ڸ����Ĳ��룬���ѷ���λҲ���ǽ�ȥ��
// num/2������num��һλ  %2������ȡnum�����λ����
/*
int count_bit_one(int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}
	return count;
}
*/
//����2��������λͬ����λ��λ��ͬ
//�磺-1���з����������԰��������޷���������
/*
int count_bit_one(unsigned int n)//-1 ���޷��� 11111111 11111111 11111111 11111111 n = 4,294,967,295
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
	}
	return count;
}
*/
//����3����ÿһλ���õ�����0100 0111��0 & 1 = 0 ��1 & 1 = 1
/*
int count_bit_one(int n)
{
	int count = 0;
	int i = 0;
	for(i = 0;i < 32;i++)//i��0��ʼ��ֻ��Ҫ��31�Σ���Ϊn��int���ͣ�ռ4���ֽ�
	{//ע�⣺ѭ�������޷����Ż�
		if (((n >> i) & 1 )== 1)
		{
			count++;
		}
	}
	return count;
}
*/
//����4��
//�磺13 - 1101
//n = 1101
//n-1 = 1100
//n & n-1 = 1100//��һ��ѭ��
//n = 1100�����һ�ε�n��ȣ���λ��1��ʧ��
//n-1 = 1011
//n & n-1 = 1000//�ڶ���ѭ��
//n = 1000����ڶ��ε�n��ȣ���λ��1��ʧ��
//n-1 = 0111
//n & n-1 = 0000//������ѭ��
//n = 0000��������ε�n��ȣ���λ��1��ʧ��
/*
int count_bit_one(int n)
{
	int count = 0;
	while(n)
	{
		n = n & (n - 1);//ÿ�ζ�����ʣ��Ķ�����λ���ұߵ�1��ʧ
		count++;
	}
	return count;
}
#include <stdio.h>
int main()
{
	int a = -1;
	scanf("%d", &a);
	int count = count_bit_one(a);
	//system("pause");//system�⺯��-#include <stdlib.h>-ִ��ϵͳ����-pause(��ͣ)
	return 0;
}
*/

//2�����������Ķ������в�ͬλ�ĸ���
//���ʵ�֣�����int(32λ)����m��n�Ķ����Ʊ���У��ж��ٸ�λ��ͬ��
//�磺����1999 2299�����7
//����1��
//�ֱ�õ�m��n���������е�ÿһλ�����бȽϣ������ͬ��count++
/*
int count_bit_diff(unsigned int m, unsigned n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((n % 2 == 1 && m % 2 == 0) || (n % 2 == 0 && m % 2 == 1))
			count++;
		n /= 2;
		m /= 2;
	}

	//for (int i = 0; i < 32; i++)
	//{
	//	if (((n >> i & 1) == 1 && (m >> i & 1) == 0) || ((n >> i & 1) == 0 && (m >> i & 1) == 1))
	//		count++;
	//}

	return count;
}
*/
//����2��
//��m��n���������������ý���ж�ÿһλ�����1��˵�����ǰ����������ͬλ�Ķ���������ͬ����count++��������1�ĸ���
/*
int count_bit_one(int n)
{
	int count = 0;
	while(n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}
int get_diff_bit(int m,int n)
{
	int tmp = m ^ n;
	return count_bit_one(tmp);
}
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	//int count = count_bit_diff(m, n);
	int count = get_diff_bit(m, n);
	
	printf("count = %d\n", count);
	return 0;
}
*/

//3����ӡ���������Ƶ�����λ��ż��λ
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//˼·�����ڴ�ӡ�����з��ŵĶ����Ʋ��룬����Ҫ������+��λ�������ȡÿһλ�������
/*
#include <stdio.h>
void Print(int m)
{
	int i = 0;
	//����Ҫ�������Ƶĸ�λ����λ���δ�ӡ���ʵ���ѭ�����
  //0-31λ
	printf("����λ��\n");//i��ʼ��Ϊ0��i = 1ż��λ��i = 2����λ��i = 30������λ
	for (i = 30; i >= 0; i -= 2)
	{//01011001010110010101100101011001
		//01011001  ��0λ
		//00101100
		//00010110  ��2λ
		//00001011
		//00000101  ��4λ
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
	printf("ż��λ��\n");//i��ʼ��Ϊ0��i = 1ż��λ��i = 31��ż��λ
	for (i = 31; i >= 1; i -= 2)
	{//01011001010110010101100101011001
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	Print(m);
	return 0;
}
//ע�⣺�������㱾����ı�����е���ֵ��С����ֵ�����Ż�ı�����е���ֵ
*/

//4��������������(��������ʱ����)
//����������ʱ������������������������
//a = a ^ b
//b = a ^ b //b = a ^ b ^ b
//a = a ^ b //a = a ^ b ^ a
//a = a + b
//b = a - b //b = a + b -b
//a = a - b //a = a + b -a

//5��ʹ��ָ���ӡ��ֵ����
//дһ��������ӡarr��ֵ�����ݣ���ʹ�������±꣬ʹ��ָ�롣arr��һ������һά���顣
/*
#include <stdio.h>
void Print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr,sz);
	return 0;
}
*/

//6����������ݹ麯�������ú���Fun(2)������ֵ�Ƕ��٣�
/*
int Fun(int n)
{ 
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}
*/
//A.2
//B.4
//C.8
//��ȷ��D.16
//���ɣ�����������ͬ�Ĵ��룬˳��ݹ飬���򷵻�

//7�����ڵݹ������������ǣ�
//A.���������������������������������ʱ�򣬵ݹ�㲻�ټ���
//B.ÿ�εݹ����֮��Խ��Խ�ӽ������������
//��ȷ��C.�ݹ�������޵ݹ���ȥ
//D.�ݹ���̫������ջ�������

//8�������ж�����
//ʵ��һ���������ж�һ�����ǲ�������
//��������ʵ�ֵĺ�����ӡ100-200֮�������
//�Գ�������ǩ��

//9�������ж�����
//ʵ�ֺ����ж�year�ǲ�������

//10��������������
//ʵ��һ��������������������������

//11���˷��ھ���
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9*9�ھ�������12�����12*12�ĳ˷��ھ���
/*
#include <stdio.h>
void print_table(int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d ", j, i, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	print_table(n);
	return 0;
}
*/

//12����ӡһ������ÿһλ
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһ��
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

//13����׳�
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//ѭ������ʵ�֣�!n = 1 * 2 * 3 * 4 * ... * n
/*
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
*/
//�ݹ�ʵ��
//�׳���ѧ��ʽ��
//		Fac(n) = 1 (n <= 1)
//		Fac(n) = n * Fac(n - 1) (n > 1)
/*
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}
*/

//14��strlen��ģ��
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
/*
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
*/
//�ݹ�˼�룺���»�С
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("\0")
//1+1+1+0
/*
int my_strlen(char* str)//str��һ��ָ�����
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
}
*/

//15���ַ������򣨵ݹ�ʵ�֣�
//��дһ������reverse_string(char* string)
//�������ַ����е��ַ���������
//����ʹ��C�������е��ַ�����������
//����1�����������������ã�ʹ�ÿ⺯��strlen
/*
#include <stdio.h>
#include <string.h>
void reverse_string(char arr[])//����char* arrҲ����
{
	int left = 0;
	int right = strlen(arr) - 1;//�������ַ���������ʹ��strlen�������ַ�������
	//���ʹ��sizeof(arr) / sizeof(arr[0]) = 7(Ԫ�ظ�����'\0'Ҳ��Ԫ�ظ���)����Ҫ��2
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}
*/
//����2��
#include <stdio.h>
//��ʹ��strlen��ʹ���Լ�ʵ�ֵ�my_strlen
//���ַ����ĳ��ȷ����ܽ᣺
//1��������
//2���ݹ�
//3��ָ��-ָ��
/*
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;//��ʱ����'\0'�ĵ�ַ-'\b'�ĵ�ַ
}
void reverse_string(char arr[])
{
	int left = 0;
	int right = my_strlen(arr) - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
*/
//����3��
//�ݹ�ʵ��
#include <stdio.h>
//����Ϊreverse_string("abcdef")
//�ֽ��������
//��һ����a��f�Ľ���
//�ڶ���������reverse_string("bcde")
//�������������������Ʋ���
//		1��a����tmp��
//		2��f����aλ����
//		3��'\0'����fλ���У�Ŀ�ģ���ֹ��һ�εݹ飬��֪��e��λ�ã�
//      4��reverse_string("bcde")
//      5��tmp����fλ��
//ע�⣺�ݹ����н�������
/*
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse_string(char arr[])
{
	char tmp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (my_strlen(arr + 1) >= 2)//��������ַ�������С��1����ż�����ַ��м��ַ�������Ϊ0���������ַ����м��ַ�������Ϊ1������ֹͣ�ݹ�
	{
		reverse_string(arr + 1);//��Ԫ��ָ����һ��Ԫ�صĵ�ַ
	}
	arr[len - 1] = tmp;
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}
*/

//16������һ������ÿһλ֮��(�ݹ�ʵ��)
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//�磺����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ǵĺ���19
//˼·��ͨ���ݹ��ȡÿһλ�������
//DigitSum(1729)
//DigitSum(172) + 1729 % 10
//DigitSum(17) + 172 % 10 + 1792 % 10
//DigitSum(1) + 17 % 10 + 172 % 10 + 1792 % 10
/*
#include <stdio.h>
int DigitSum(unsigned int num)
{
	if (num > 9)//��λ������
	{
		return DigitSum(num / 10) + num % 10;//ͨ��/10ȥ��β����ͨ��%10���ÿһλ��ÿһλ���
	}
	else
	{
		return num;
	}
}
int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	int sum = DigitSum(num);
	printf("sum = %d\n", sum);
	return 0;
}
*/

//17���ݹ�ʵ��n��k�η�
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
/*
#include <stdio.h>
double Pow(int n, int k)
{
	//n^k
	//��k = 0ʱ�����Ϊn^k = 1
	//��k > 0ʱ�����Ϊn^k = n * n^(k - 1)
	//��k < 0ʱ�����Ϊn^k = 1/n^k
	if (k < 0)
	{
		return (1.0 / (Pow(n, -k)));
	}
	else if (k == 0)
	{
		return 1.0;
	}
	else
	{
		return n * Pow(n, k - 1);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	double ret = Pow(n, k);
	printf("ret = %lf\n", ret);
	return 0;
}
*/

//18������쳲�������
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//�磺����5�����5������10�����55
//�ݹ�ʵ��
//쳲���������ѧ��ʽ��
//Fib(n) = 1 (n <= 2)
//Fib(n) = Fib(n - 1)+Fib(n - 2) (n > 2)
/*
int Fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
//---TDD������������
//����ô���������������ôʵ���������
//����ôʵ���������
*/
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
*/