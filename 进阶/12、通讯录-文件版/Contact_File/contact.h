
#define DEFAULT_SZ 3//���ݴ�С
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//qsort�⺯����ͷ�ļ�
#include <stdlib.h>
#include <errno.h>
//��switch����ö�ٳ�������߿ɶ���
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT,//6
	SAVE
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
//struct Contact
//{
//	//�����װ��һ�𣬷��㴫��
//	struct PeoInfo data[MAX];//����һ�����1000�����ѵ���Ϣ�Ŀռ�data
//	int size;//������¼��ǰͨѶ¼���ٸ�������Ϣ
//};
struct Contact
{
	//���ڴ�������һ��MAX��С�����飬һ�θ�����������ô��Ŀռ�������1000�˵���Ϣ
	//���û�д�1000���˵���Ϣ��������ڴ���˷�
	//�����Ҫ���泬��1000���˵���Ϣ���ֱ��治�ˡ�����ʹ�ÿռ�Ĳ����
	//��Ϊ��̬�����İ汾
	//Ĭ�Ͽ��Է�3���˵���Ϣ
	//�����ֵ�ǰͨѶ¼����ʱ�򣬽������ݣ�ÿ������2���ռ�

	struct PeoInfo* data;//����һ�����1000�����ѵ���Ϣ�Ŀռ�data
	int size;//������¼��ǰͨѶ¼���ٸ�������Ϣ
	int capacity;//������¼��ǰͨѶ¼����������ܴ���ٺ�����Ϣ
};


//������ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact *ps);
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
//void SortContact(struct Contact* ps);

void DestoryContact(struct Contact* ps);

//���������Ϣ
void SaveContact(struct Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);