#define _CRT_SECURE_NO_WARNINGS 1

//switch���
//Ӧ�ó����������Ӧ�����֣���ӡ��Ӧ��������
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	if (1 == day)//�������ͱ����Ƚ�ʱ����������߱ȽϺ�
//		printf("����һ\n");
//	else if (2 == day)
//		printf("���ڶ�\n");
//	else if (3 == day)
//		printf("������\n");
//	else if (4 == day)
//		printf("������\n");
//	else if (5 == day)
//		printf("������\n");
//	else if (6 == day)
//		printf("������\n");
//	else if (7 == day)
//		printf("������\n");
//	else
//		printf("�������\n");
//	return 0;
//}
//������if-else���ȽϷ���

//ʹ��switch���---�����ڶ��֧���
//switch�ṹ��
//switch (���ͱ��ʽ)
//{
//	����
//}
//�������ʲô����һЩcase���
//case�ṹ��
//case ���ͳ������ʽ��
//	��䣻
//  break;
//ע�⣺���ͱ��ʽ�����ͳ������ʽ

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//3
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//	case 2:
//		printf("���ڶ�\n");
//	case 3:
//		printf("������\n");
//	case 4:
//		printf("������\n");
//	case 5:
//		printf("������\n");
//	case 6:
//		printf("������\n");
//	case 7:
//		printf("������\n");
//	}
//		
//	return 0;
//}
//����3�������ӡ����һ�����ڶ�����������
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);//3
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//	case 2:
//		printf("���ڶ�\n");
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//	case 5:
//		printf("������\n");
//	case 6:
//		printf("������\n");
//	case 7:
//		printf("������\n");
//	}
//		
//	return 0;
//}
// ���Թ۲�day�����еı仯--����breakֱ������switch���

//���������Ϊ��
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("�������!\n");
//		break;
//	}
//		
//	return 0;
//}
//�ܽ᣺case������ڣ�break�������ڣ�break����switch��䣬ʵ�ַ�֧

//#include <stdio.h>
//int main()
//{
//	float day = 0.0;//day����Ϊ����������
//	scanf("%d", &day);
//	switch (day)//������ ���ڱ���Ϊ���ͱ��ʽ
//	{
//	case 1:
////		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
////	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("�������!\n");
//		break;
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1.0://����case������������ͳ������ʽ��Ҳ���Ը��ַ��ͣ��ַ��ʹ洢����ASCII��ֵ��Ҳ�����ͳ�����
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("�������!\n");
//		break;
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	int n = 1;
//	switch (day)
//	{
//	case n://����case�������Ϊ�����ҳ������ʽ
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("�������!\n");
//		break;
//	}
//
//	return 0;
//}
//ע�⣺break����������ӻ򲻼ӣ��Ǳ�����ϣ�,������ϰ�ߣ������һ��case���������break����ֹ����Ϊ������ӣ����������caseʱ�����׳�����

//�Ǳ������break�����磺
//��������1-5ʱΪ�����գ�����6-7ʱΪ��Ϣ��
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//	case 7:
//		printf("��Ϣ��\n");
//		break;//���һ��case��䣬ϰ���ϼ�break��
//		//�����ټ�һ��case 8����䣬��case 7��û�м�break�����ִ��case��7��case 8:����䣬
//	default://�����ж���ƥ��ʱ����ִ�С�
//		printf("�������!\n");
//		break;//�������break
//	}
//
//	return 0;
//}
// default:�����ʽ��ֵ�����е�case��ǩ��ֵ����ƥ��ʱ���Ż�ִ��������䣬��ÿ��switch�����ֻ�ܳ���һ��default�Ӿ�
//default������������п��ޣ�case��default����λ������
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)//7
//	{
//	default:
//		printf("�������!\n");
//
//	case 2:
//		printf("���ڶ�\n");
//	case 3:
//		printf("������\n");
//	case 7:
//		printf("������\n");
//	case 1:
//		printf("����һ\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	}
//
//	return 0;
//}//����7ʱ����ӡ����������գ�����һ������8ʱ����ӡ�����������󣡣����ڶ����������������գ�����һ
//�ܽ᣺����case��default��˳�򣬶��Ǵ�ƥ���case����default���룬һֱ���´�͸��ֱ��������һ��break����
//�ʣ�����default����break
//#include <stdio.h>
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	default:
//		printf("�������!\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	case 1:
//		printf("����һ\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	}
//
//	return 0;
//}
//�ܽ᣺��switch�У�������case��break��default��if

//#include <stdio.h>
//int main()
//{
//	int day = 0;
//  int n = 1;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		if( n == 1)
//			printf("����");
//		printf("����һ\n");//case��������Ǻ���������
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	}
//	return 0;
//}

//��ϰ��
/*1������switch����еĹؼ��ֲ������ĸ���*/
//��ȷ���A.continue
//B.break
//C.default
//D.if
/*2����������ִ�н��Ϊ��*/
//#include <stdio.h>
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;//m = 3
//	case 2:
//		n++;//n = 2
//	case 3:
//		switch (n)// n = 2
//		{//switch����Ƕ��ʹ��
//		case 1:
//			n++;
//		case 2:
//			m++;//m = 4
//			n++;//n = 3
//			break;
//		}
//	case 4:
//		m++;//m = 5
//		break;
//	default:
//		break;
//	}
//	printf("m = %d, n = %d\n", m, n);
//	return 0; 
//}
//��ȷ���Ϊ��m = 5, n = 3