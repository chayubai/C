#define _CRT_SECURE_NO_WARNINGS 1
/*1������while(�������ʽ)ѭ����,����������ȷ���ǣ�)�t������ѭ��������û��break,continue��return��goto�ȵ����)*/
//A.ѭ����ĵ��д������Ǳ��������ʽ��ִ�д�����һ��
//��ȷ��B.�������ʽ��ִ�д������Ǳ�ѭ�����ִ�д�����һ��
//C.�������ʽ��ִ�д�����ѭ�����ִ�д���һ��
//D.�������ʽ��ִ�д�����ѭ�����ִ�д����޹�

/*2�������³��򣬳�������Ľ���ǣ�*/
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20)
//			break;
//		if (b % 3 == 1) //1 4 7 10 13 16 19 22
//		{				//1 2 3  4  5  6  7  8
//			b = b + 3;//��Զ����ִ��
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//
//	return 0;
//}
//A.10
//B.9
//��ȷ���C.8
//D.7

/*3����д������һ��1-100�����������г��ֶ��ٸ�����9*/
//˼·��
//		1����λΪ9��ģ10����9
//		2��ʮλΪ9����10����9
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		else if (i / 10 == 9)
//			count++;
//	}
//	printf("count = %d\n", count);
//	return 0;
//}
//9 19 29 39 49 59 69 79 89 99
//90 91 92 93 94 95 96 97 98 99
//����20����99��2��9��

//�����޸ģ�
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100.i++)
//	{
//		if (i % 10 == 9)
//			count++;
//		if (i / 10 == 9)
//			count++;
//	}
//	printf("count = %d\n", count);
//	return 0;
//}

/*4������1/1-1/2+1/3-1/4+1/5 ......+ 1/99 - 1/100��ֵ����ӡ�����*/
//�ȼ��㣺����1/1+1/2+1/3+1/4+1/5 ......+ 1/99 + 1/100��ֵ����ӡ�����
//˼·��ѭ���ۼ�
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1 / i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//���Ϊ1
//ԭ�������
//1/1+1/2+1/3...=1
//1+0+0+0...
//Ҫ��ӡС�������������������һ����С��

//�����޸ģ�
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	double sum = 0.0;//��ֵΪdouble���͵ĳ�ʼֵ
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1.0 / i;//iΪ���ͣ���b��Ϊdouble����
//	}
//	printf("%lf\n", sum);//��ӡ��ʽΪlf
//	return 0;
//}
//�ټ��㣺1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ...... + 1 / 99 - 1 / 100��ֵ
//˼·������һ�����������������ţ���ѭ���ۼ�
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//������������ӣ�ż������ӣ�����������

/*5����10�������е����ֵ*/
//˼·������һ�����ֵ��������Ԫ�ظ�����ѭ����֮�Ƚ�
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = 0;//����Ϊ���ֵ
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i <= sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d\n",max);
//	return 0;
//}
//�������и���ʱ����������
//max����ֵʱ������Ϊ�����е�����һ���Ե�һ��Ԫ��Ϊ���ֵ

//�����޸ģ�
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];//��������ĵ�һ��Ԫ�ص�ֵΪ���ֵ
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i <= sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d\n",max);
//	return 0;
//}

/*6����ӡ�žų˷���*/
//˼·��ѭ����ӡÿ���е�ÿ�У��ȴ�ӡһ�У��ٴ�ӡһ���еĸ���
//�к�*�к�
//1 * 1 = 1
//2 * 1 = 2 2 * 2 = 4
//3 * 1 = 3 3 * 2 = 6 3 * 3 = 9 4 * 1 = 4 .....
//....
//9 * 1 = 9 ..
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	//��ӡ9��
//	for (i = 1; i <= 9; i++)
//	{
//		//ÿ��ӡһ�У���ӡi��
//		int j = 1;//�����������
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i,j,i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//%2d:��λ���Ҷ��룬������λ���ո��롣
//%-2:��λ�������

/*7����������Ϸ*/
//˼·��
//		1������һ�������
//		2��������
//			a.�¶��ˣ��͹�ϲ�㣬��Ϸ����
//			b.��´��ˣ�����߲´��ˣ����ǲ�С�ˣ�ֱ���¶�
//		3����Ϸһֱ�棬�����˳���Ϸ
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//void menu()
//{
//	printf("**********************************\n");
//	printf("*********** 1.play     ***********\n");
//	printf("*********** 0.exit     ***********\n");
//	printf("**********************************\n");
//}
//
//void game()
//{//��������Ϸ��ʵ��
//
//	//1������һ�������
//	//ʹ��MSDN�����У�����rand
//	//rand---stdlib.h
//	//Generates a pseudorandom number.
//	//int rand(void):�����޲���������һ������
//	//Return Value��
//	//rand returns a pseudorandom number, as described above.There is no error return.
//	//Remarks��
//	//The rand function returns a pseudorandom integer in the range 0 to RAND_MAX.
//	//��һ��0-RAND_MAX�ķ�Χ�ڣ�rand��������һ���������
//	//RAND_MAX--rand�����ܷ���һ��0-32767֮���������
//	//����ͷ�ļ�stdlib.h��RAND_MAXѡ���һ���ת�����壬#define RAND_MAX 0x7fff    = 32767
//	
	/*
	//�۲�������������ص�
	int ret = rand();//�����������������--rand()---stdlib.h
	printf("%d\n", ret);//���ɵ��������ÿ�����г�����������ͬ
	*/
//
//	//Use the srand function to seed the pseudorandom-number generator before calling rand.
//	//�ڵ���rand֮ǰ��ʹ��srand�������������������������
//	//ʹ��MSDN����������srand
//	//srand---stdlib.h
//	//Sets a random starting point.
//	//void srand( unsigned int seed )���޷���ֵ������Ϊunsigned int��
//
	/*int ret = 0;
	srand(1);//��srand�����Ĳ����ڱ仯ʱ����ӡ�Ľ���ű仯����֮������ֵ��ͬ���ʲ���Ӧ������仯��ֵ--�����ϵ�ʱ��
	ret = rand();//���ܱ���ȱ�١�����(�ڡ����͡���ǰ��)���������������Ӧ�����ڴ�������ǰ��
	printf("%d\n", ret);//ÿ�����ɵ������������ͬ
	*/
//
//	//ʱ�������ǰ�������ʱ�� - ���������ʼʱ�䣨1970��1��1��0ʱ0��0�룩= xxx��
//	//��ʱ��������������������ʼ�㣬��ȡʱ�������srand(time())
//	//ʹ��MSDN����������time
//	//time---time.h
//	//Gets the system time.
//	//time()������ȡϵͳʱ�䡣
//	//time_t time( time_t *timer )���������ͣ�time_t��time_t*ָ������
//	//time_tת�����壬�ض���typedef __time32_t time_t,��ת�����壬����Ϊlong����
	
//	//��srand()����time()��time������һ����ָ��������õ��ķ���ֵǿ������ת����unsigned int��
//	//��srand((unsigned int)time(NULL))

	/*
	int ret = 0��
	srand((unsigned int)time(NULL));//NULL�����ָ��
	ret = rand();
	printf("%d\n", ret);//���ɵ���������������ܽӽ�
//	//�����������srand((unsigned int)time(NULL));��������������ʱ���������������һ�μ���
	*/
//
	//int ret = rand() % 100 + 1;//���ó�1-100���������ģ100��������0-99
//	//2��������
	//int guess = 0;//���ղµ�����
	//while (1)
	//{
	//	printf("������µ�����>:");//���ַ��²�
	//	scanf("%d", &guess);
	//	if (guess > ret)
	//	{
	//		printf("�´���\n");
	//	}
	//	else if (guess < ret)
	//	{
	//		printf("��С��\n");
	//	}
	//	else
	//	{
	//		printf("��ϲ�㣬�¶���\n");
	//		break;
	//	}
	//}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));//����������㣬��������
// 
//	do
//	{//�����
//		menu();
//		printf("��ѡ��>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����,����������!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}