#define _CRT_SECURE_NO_WARNINGS 1
//��ҵ
//1��ģ��ʵ��strstr
//2��ģ��ʵ��memcpy
//3��ģ��ʵ��memmove
//4�����ô�����ϰ�뱾���ⲩ��(���ô���ı�д���漰���ĺ���֪ʶ�������Բ������ӷ�ʽ)

//5����VS2013�£�����ṹ����ռ�ռ��С�Ƕ��ٸ��ֽڣ�
//typedef struct 
//{
//	int a;//4  0-3
//	char b;//1  4
//	short c;//2  +1 5   6-7
//	short d;//2  8-9
//}AA_t;//12
//int main()
//{
//	printf("%d\n", sizeof(AA_t));
//	return 0;
//}
//A��16
//B��9
//��ȷ��C��12
//D��8

//6����32λϵͳ�����£�����ѡ��Ϊ4�ֽڶ��루Ĭ�϶�����Ϊ4������ôsizeof(A)��sizeof(B)�ǣ�
//struct A
//{
//	int a;//4   0-3 
//	short b;//2  4-5
//	int c;//4  +2 6-7  8-11
//	char d;//1  12
//};//16
//struct B
//{
//	int a;//4   0-3
//	short b;//2  4-5
//	char c;//1  6
//	int d;//4  +1 7  8-11
//};//12
//A��16 16
//B��13 12
//��ȷ��C��16 12
//D��11 16

//6���������Ľ���ǣ�
//#pragma pack(4)/*����ѡ���ʾ4�ֽڶ���*/
//#include <stdio.h>
//int main(int argc, char* argv[])
//{
//	struct tagTest1
//	{
//		short a;//2  0-1
//		char d;//1  2
//		long b;//4  +1 3 4-7  
//		long c;//4  8-11  
//	};//12
//	struct tagTest2
//	{
//		long b;//4  0-3
//		short c;//2 4-5
//		char d;//1 6
//		long a;//4 +1 7  8-11
//	};//12
//	struct tagTest3
//	{
//		short c;//2  0-1
//		long b;//4  +2 2-3 4-7
//		char d;//1 8
//		long a;//4 +3 9-11 12-15
//	};//16
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//
//	return 0;
//}
//#pragma pack()
//A��12 12 16
//B��11 11 11
//C��12 11 16
//D��11 11 16