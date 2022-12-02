#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//�������ݺ����ں��涨�壬ǰ��ʹ��������
void CheckCapacity(struct Contact* ps);
//���ڼ��غ����ں��涨�壬ǰ��ʹ��������
void LoadContact(struct Contact* ps);

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	//����Ĭ�϶�̬����3���ռ�(�洢3���˵���Ϣ)����data��ָ�򣬲�ά��
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	//�ж��Ƿ񿪱ٳɹ�
	if (ps->data == NULL)
	{
		return;
	}
	//��size��ʼ��Ϊ0
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
	//��capacity��ʼ��Ϊ3
	ps->capacity = DEFAULT_SZ;

	//���ļ����Ѿ���ŵ���Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}

void LoadContact(struct Contact* ps)
{
	struct PeoInfo  tmp = { 0 };//��ʱ��Ŷ�ȡ������
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ�����ŵ�ͨѶ¼��
	//1������ʱ��������������������
	//2������ʲôʱ�����
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))//fread����ֵ��ʾʵ�ʶ�ȡ�������ݸ���������ȡΪ0ʱ����
	{
		//�жϣ�������
		CheckCapacity(ps);
		//��������
		ps->data[ps->size] = tmp;//����ʱ���ݷ��뵽ͨѶ¼��
		ps->size++;//Ԫ�ؼ�1
	}

	fclose(pfRead);
	pfRead = NULL;
}
//��ν���Ϣд�����ݿ��� - C���Բ���MySOL���ݿ�

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		//���ݳɹ�
		if (ptr != NULL)
		{
			ps->data = ptr;//����dataά��
			ps->capacity += 2;//��������ǩ��Ϊ���ݺ��ֵ
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}
//���Ӻ�����Ϣ
void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1������������ӿռ�
	//2�����������ɶ�¶�����
	CheckCapacity(ps);

	//��������
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

	//��ӳɹ���ͬʱ���浽�ļ���
	//fwrite(&(ps->data[ps->size]), sizeof(struct PeoInfo), 1, pfWrite);//���Ǵ��ļ��ķ�ʽ������׷�ӷ�ʽ
	//���ߵ���fseekָ���ļ����ָ��ƫ�Ƶ��ļ�β�������
	SaveContact(ps);//��ӳɹ��ͱ��棬Ч�ʵ�
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

	//ɾ���ɹ��󣬲�����
	SaveContact(ps);//Ч�ʵ�
	//ͬʱ����ʹ�õ�һ����ķ�ʽ���б��档
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

		//�޸ĳɹ��󣬲�����
		SaveContact(ps);//Ч�ʵ�
		//ͬʱ����ʹ�õ�һ����ķ�ʽ���������޸ĵ����ݣ��Դ�ŵ��ļ���ԭʼλ�á�
		//�ļ�ֻ��׷�ӵ����棬�����ļ���ԭʼ���������ݻ���

		printf("�޸ĳɹ�\n");
	}
}
//ע�⣺��ӵ�����ֻ�Ǳ������ڴ��У�������ر������ݾ�û�ˣ�����뱣�����ݣ��ɽ������ݿ���ļ�

int comparePeoInfo_by_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}
int comparePeoInfo_by_name(const void* e1, const void* e2)
{
	//�Ƚ��ַ���������ʹ�ù�ϵ�������ʹ��strcmp�⺯�����������0��ǡ�÷��ش���0���������С��0������С��0����������0���ص���0������
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
void SortContact(struct Contact* ps)
{
	//���
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("*******   1������������    2������������    *******\n");
		int input = 0;
		printf("��ѡ��һ�ַ�ʽ����>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//����compareStu_by_age�ĵ�ַ���ȵ���int(* compare)(const void* elem1, const void* elem2)����ָ�����ıȽϺ���
			qsort(ps->data, ps->size, sizeof(ps->data[0]), comparePeoInfo_by_name);
			break;
		case 2:
			qsort(ps->data, ps->size, sizeof(ps->data[0]), comparePeoInfo_by_age);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
		//��ӡ���к�����Ϣ
		ShowContact(ps);
	}
}

void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps -> data = NULL;
 }

//�����ļ�-��д�ļ�
void SaveContact(struct Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;//���ڴ˺���û�з���ֵ����return����
	}
	//дͨѶ¼�е����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//��&(ps->data[i])��ַ������Ϣ����Ϣ��СΪsizeof(struct PeoInfo)��һ��дһ����pfWrite��ָ����ļ���
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}
	//����ʹ��fwrite(p->data, sizeof(struct PeoInfo), p->size, pfWrite);
	fclose(pfWrite);
	pfWrite = NULL;
}

//��չ��C���Բ���MySQL���ݿ�