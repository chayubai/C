#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000	//ͨѶ¼����
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//qsort�⺯����ͷ�ļ�

//��switch����ö�ٳ�������߿ɶ���
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};

//����һ��������Ϣ������
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//����һ��ͨѶ¼����
struct Contact
{
	//�����װ��һ�𣬷��㴫��
	struct PeoInfo data[MAX];//����һ�����1000�����ѵ���Ϣ�Ŀռ�data��ÿ��Ԫ�ض���һ��struct PeoInfo�ṹ��
	int size;//������¼��ǰͨѶ¼���ٸ�������Ϣ
};

//������ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps);
//�������Ӻ�����Ϣ�ĺ���
void AddContact(struct Contact* ps);
//������ӡ������Ϣ�ĺ���
void ShowContact(const struct Contact* ps);//const������
//����ɾ��ָ���ĺ�����Ϣ�ĺ���
void DelContact(struct Contact* ps);
//��������ָ��������Ϣ�ĺ���
void SearchContact(const struct Contact* ps);

//����ָ��Ҫ�޸ĺ�����Ϣ�ĺ���
void ModifyContact(struct Contact* ps);
//����ָ�������ĺ�����Ϣ��������
void SortContact(struct Contact* ps);

//�ó����ʵ�֣������ú���ָ�룬��һ������ָ������飬�ͺñ�֮ǰ���ļ�����
//�������ֻ�ʺϲ�ͬ������ɾ�Ĳ������

//������
//1��Ϊʲôʹ��#define MAX 1000?
//2��ΪʲôҪ����int size;?
//3��Ϊʲô��struct PeoInfo[MAX]��int size;���з�װ��
//4��Ϊʲôcase��ʹ��ö�ٳ�����
//5��struct PeoInfo[MAX]�е�MAX��ʲô���ã�
//6��ΪʲôҪ��װһ��FindByName������Ϊʲôʹ��const���Σ�Ϊʲôʹ��static���Σ�
//7��Ϊʲô�����˳������ݾͲ������ˣ���ɾ�Ĳ鱾�ʲ�������ʲô��
//8������ͬ��Ԫ�أ����ң�ɾ�����޸�Ӧ����β����� - ѭ�����ң�ѭ��ɾ����