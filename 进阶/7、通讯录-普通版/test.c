#define _CRT_SECURE_NO_WARNINGS 1
//ע�⣺ö������ѡ��ģʽ��������Ϣ�ýṹ��

//1���������1000�����ѵ���Ϣ�����������֡��绰���Ա�סַ������
//2�����Ӻ�����Ϣ
//3��ɾ��ָ�����ֵĺ�����Ϣ
//4�����Һ�����Ϣ
//5���޸ĺ�����Ϣ
//6����ӡ������Ϣ
//7������
#include "contact.h"
void menu()
{
	printf("***************************************************\n");
	printf("********   1��add              2��del     *********\n");
	printf("********   3��search           4��modify  *********\n");
	printf("********   5��show             6��sort    *********\n");
	printf("********   0��exit                        *********\n");
	printf("***************************************************\n");
}
int main()
{
	int input = 0;
	/*
	//��ʽ1��
	//����ͨѶ¼
	struct PeoInfo con[MAX];//����һ�����1000�����ѵ���Ϣ�Ŀռ�data
	int size;//������¼��ǰͨѶ¼���ٸ�������Ϣ��������ɾ�Ĳ����
	//��ʼ��ͨѶ¼
	InitContact(con, &size);
	AddContact(con, &size);
	DelContact(con, &size);

	//����������ƣ������漰��size�ĺ�������Ҫ����size���Ӷ�ʹ�ó�����鷳�����Խ�������װ��һ���ṹ��
	*/

	//����2��
	//����ͨѶ¼
	struct Contact con;//����һ��ͨѶ¼con�����Դ�1000�����ѣ�һ�����Ѱ��������Ϣ
	//��ʼ��ͨѶ¼
	InitContact(&con);//1���ṹ�崫ַЧ�ʸ� 2����ַ����ı亯���ⲿĳЩ������ֵ
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
			//��caseԽ�࣬�ɶ���Խ�ʹ��ö�ٳ������ӿɶ���
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);//���ܴ�ӡ��Ϣ����ı�con��ֵ����ʹ�ô�ַЧ�ʸ���
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
