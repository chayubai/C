#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	//��data[1000]����ʼ��Ϊ0
	memset(ps->data, 0, sizeof(ps->data));//��data��С���ֽڿռ�����Ϊ0
	//��size��ʼ��Ϊ0
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

//���Ӻ�����Ϣ
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		//�������ĺ�����Ϣ�����±�Ϊsize��λ��
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);
		//����������������Ԫ�صĵ�ַ������Ҫ&

		ps->size++;//��¼��1
		printf("��ӳɹ�\n");
	}
}

//��ӡ������Ϣ
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		//��ӡ���к�����Ϣ
		int i = 0;

		//��ӡ��ͷ
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)//ע������
		{
			//��ӡ��Ϣ
			printf("%-20s\t%-20d\t%-20s\t%-20s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//����ɾ�������ҡ��޸Ĺ��ܶ���Ҫ�õ�����ĳ��Ԫ�ص���Ϣ�����Ե�����װ��Ϊһ�����������ٴ�������
//ʵ�ֲ�����Ϣ�ĺ�����ʹ��staticֻ�����ڶ�ɾ�������ҡ��޸ı����������ģ�
//����ϣ�������ط��ĺ���ʹ������ֻ�������ڵ��ļ���ʹ�ã����Ӱ�ȫ��.�Ҷ��庯������ʹ��֮ǰ��
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;//�Ҳ���
}

//ɾ��ָ���ĺ�����Ϣ
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//1������Ҫɾ��������ʲôλ��
	/*int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			break;
		}
	}*/

	//2��ɾ��
	//�������������������1���ҵ���,i�Ƕ�ӦҪɾ����Ԫ�� 2��ѭ������û�ҵ�
	//if (i == ps->size)
	//{
	//	printf("Ҫɾ�����˲�����\n");
	//}
	//else
	//{
	//	//ɾ������
	//	//˼·�����ҵ�����ϢΪ���㣬�������Ϣ��ǰ�渲��
	//	int j = 0;
	//	for (j = i; j < ps->size-1; j++)//ע�������������Խ��
	//	{
	//		//����
	//		ps->data[j] = ps->data[j + 1];
	//	}
	//	ps->size--;//Ԫ�ظ�����1
	//	printf("ɾ���ɹ�\n");
	//}
	//ע�⣺����ɾ�����һ��Ԫ�أ�����ɾ��������ͬ�ľͿ��ܻ�������

	//1������Ҫɾ��������ʲôλ��
	//�ҵ��˷�����������Ԫ�ص��±�
	//û�ҵ�����-1
	int pos = FindByName(ps, name);
	//2��ɾ��
	//�������������������1���ҵ��� 2��ѭ������û�ҵ�
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		//˼·�����ҵ�����ϢΪ���㣬�������Ϣ��ǰ�渲��
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)//ע�������������Խ��
		{
			//����
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;//Ԫ�ظ�����1
		printf("ɾ���ɹ�\n");
	}
}

//����ָ��������Ϣ
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//1������Ҫ������ʲôλ��
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�鵽�˵���Ϣ������\n");
	}
	else
	{
		//�ҵ��ˣ���pos�Ǹ�Ҫ���ҵ�Ԫ�ص��±꣬��ӡָ�������ĺ�����Ϣ
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-20d\t%-20s\t%-20s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

//ָ��Ҫ�޸ĺ�����Ϣ
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//1������Ҫ������ʲôλ��
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else
	{
		//�ҵ��ˣ���pos�Ǹ�Ҫ���ҵ�Ԫ�ص��±꣬�޸�ָ�������ĺ�����Ϣ
		//����������һ�Σ������Ҫʵ���޸�ָ�������ݣ�����ʹ��switch
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}
//ע�⣺��ӵ�����ֻ�Ǳ������ڴ��У�������ر������ݾ�û�ˣ�����뱣�����ݣ��ɽ������ݿ���ļ�

//int comparePeoInfo_by_age(const void* e1, const void* e2)
//{
//	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
//}
//int comparePeoInfo_by_name(const void* e1, const void* e2)
//{
//	//�Ƚ��ַ���������ʹ�ù�ϵ�������ʹ��strcmp�⺯�����������0��ǡ�÷��ش���0���������С��0������С��0����������0���ص���0������
//	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
//}
//void SortContact(struct Contact* ps)
//{
//	//���
//	if (ps->size == 0)
//	{
//		printf("ͨѶ¼Ϊ��\n");
//	}
//	else
//	{
//
//		printf("*******   1������������    2������������    *******\n");
//		int input = 0;
//		printf("��ѡ��һ�ַ�ʽ����>");
//		scanf("%d", &input);
//
//		int sz = sizeof(ps->data) / sizeof(ps->data[0]);
//		switch (input)
//		{
//		case 1:
//			//����compareStu_by_age�ĵ�ַ���ȵ���int(* compare)(const void* elem1, const void* elem2)����ָ�����ıȽϺ���
//			qsort(ps->data, sz, sizeof(ps->data[0]), comparePeoInfo_by_name);
//			break;
//		case 2:
//			qsort(ps->data, sz, sizeof(ps->data[0]), comparePeoInfo_by_age);
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//		//��ӡ���к�����Ϣ
//		int i = 0;
//		//��ӡ��ͷ
//		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
//		for (i = 0; i < ps->size; i++)//ע������
//		{
//			//��ӡ��Ϣ
//			printf("%-20s\t%-20d\t%-20s\t%-20s\t%-20s\n",
//				ps->data[i].name,
//				ps->data[i].age,
//				ps->data[i].sex,
//				ps->data[i].tele,
//				ps->data[i].addr);
//		}
//	}
//
//}

//qsort������ʹ�ã�MSDN����qsort
//void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));
//��һ��������void* base - base:Start of target arrayĿ���������Ԫ�ص�ַ
//�����������������Ԫ�ص�ַ
//�ڶ���������size_t num - num:Array size in elements�����Ԫ�ظ���
//���������������Ԫ�ظ���
//������������size_t width - width:Element size in bytesԪ�صĴ�С
//�����������ÿ��Ԫ�صĴ�С-��λ�ֽ�
//���ĸ�������int(* compare)(const void* elem1, const void* elem2) - compare�������Ǻ���ָ������
//���ĸ�������ָ������Ҫʵ�ֵıȽϺ��������ڽ��յĺ����Ĳ����Ǻ���ָ�����ͣ�����ƱȽϺ���Ӧ��
//��ָ��ĺ�����Ҫ���ǣ�
//1������������int(������)(const void* elem1, const void* elem2)���������͵�����ֵ֮��ıȽ�
//2��������ַ�ȽϵĽ������0�����ش���0���������С��0������С��0����������0���ص���0������
//��������ָ�룬�Ƚ�����Ԫ�ص����Ժ����ĵ�ַ-�������ʹ�����Լ�ʵ��
//����ָ������������ǣ����Ƚϵ�����Ԫ�صĵ�ַ
//#include <stdio.h>
//#include <stdlib.h>//qsort�⺯����ͷ�ļ�
//#include <string.h>
//struct PeoInfo
//{
//	char name[20];
//	int age;
//	char sex[6];
//};
//int comparePeoInfo_by_age(const void* e1, const void* e2)
//{
//	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
//}
//void test4()
//{
//
//	struct PeoInfo p[3] = { {"zhangsan",12,"��"},{"lisi",15,"Ů"},{"wanger",5,"��"} };
//	int sz = sizeof(p) / sizeof(p[0]);
//	qsort(p, sz, sizeof(p[0]), comparePeoInfo_by_age);
//	//���
//	int i = 0;
//	//��ӡ��ͷ
//	printf("%-20s\t%-20s\t%-20s\n", "����", "����", "�Ա�");
//	for (i = 0; i < 3; i++)//ע������
//	{
//		//��ӡ��Ϣ
//		printf("%-20s\t%-20d\t%-20s\n",
//			p[i].name,
//			p[i].age,
//			p[i].sex);
//	}
//}
//
//int main()
//{
//	test4();
//	return 0;
//}