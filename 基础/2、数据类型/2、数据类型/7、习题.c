#define _CRT_SECURE_NO_WARNINGS 1

//ϰ�⣺
/*1�������ĸ�����C�������õ��������ͣ�*/
//A.char
//B.double
//��ȷ���C.struct Stu
//D.short

/*2���ֲ��������������ǣ�*/
//A.main�����ڲ�
//B.��������
//C.main����֮ǰ
//��ȷ���D.�ֲ��������ڵľֲ���Χ

/*3�������������Ľ���ǣ�*/
/*
#include <stdio.h>
int num = 10�� 
int main()
{
	int num = 1;
	printf("num = %d\n", num);
	return 0;
}
*/
//A.���������⣬���ܱ���
//��ȷ���B.���1
//C.���10
//D.���0

/*4���ַ����Ľ�����־�ǣ�*/
//A.��'0'
//B.��EOF
//��ȷ���C.��'\0'
//D.�ǿո�

/*���֣�'\0', 0, '0', EOF*/
// '\0' ת���ַ���ASCII��ֵΪ0
//   0  ����0���൱��'\0'
//  '0' �ַ�0��ASCII��ֵΪ48
//  EOF end of file �ļ�������־��ֵΪ��-1

/*5���������Ľ���ǣ�*/
/*
#include <stdio.h>
int main()
{
	char arr[] = { 'b','i','t' };
	printf("%d\n", strlen(arr));

	return 0;
}
*/
//A.3
//B.4
//��ȷ���C.���ֵ
//D.5

/*6�������Ǹ�����ת���ַ���*/
//A.'\n'
//B.'\060'
//��ȷ���C.'\q'
//D.'\b'

/*7��������������������ǣ�*/
//A.������һ����ͬ����Ԫ�صļ���
//��ȷ���B.������±��Ǵ�1��ʼ��
//C.������±��Ǵ�0��ʼ��
//D.���������ʼ�������Բ�ָ������Ĵ�С

/*8��C�����������Ǹ�����Ĵ����Ǵ���ģ�*/
//A.int arr[10] = {0};
//��ȷ���B.int n = 10;int arr[n] = {0};
//C.int arr[] = {1,2,3,4,5,6,7,8,9,0};
//D.char ch[10] = "hello bit";
//VS2019��֧��C99��׼�еı䳤����

/*9���������Ľ���ǣ�*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", strlen("C:\test\121"));
	return 0;
}
*/
//��ȷ���A.7
//B.8
//C.9
//D.10

/*10��дһ���������������еĽϴ�ֵ*/
/*
int main()
{
	int num1 = 10;
	int num2 = 20;
 if(num1 > num2)
		printf("�ϴ�ֵ�ǣ�%d\n", num1);
 else
		printf("�ϴ�ֵ�ǣ�%d\n", num2);
	return 0;
}
*/

/*------------------------------------*/
/*
#include <stdio.h>
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//һ�㲻����Ѻ�����д��ȫ��д
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int m = max(a, b);
	printf("max = %d\n", m);
	return 0;
}
*/