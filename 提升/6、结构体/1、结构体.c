#define _CRT_SECURE_NO_WARNINGS 1
//������ʶ�ṹ��
//1���ṹ�����͵�����
//�ṹ�Ļ���֪ʶ
//�ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա�������ṹ��ÿ����Ա�����ǲ�ͬ���͵ı�����
//�ṹ�����͵�������ʽ1��
//struct tag
//{
//	member - list;
//}[variable - list];//[variable - list]��ʡ��
//�ֺŲ��ܶ�

//��������ѧ���Ľṹ�����ͣ����������䡢�绰���Ա�
//struct�ṹ��ؼ���	Stu�ṹ���ǩ	struct Stu�ṹ������
//struct Stu
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}s1, s2, s3;//�����ṹ�����͵�ͬʱ�����ṹ�������s1,s2,s3������ȫ�ֵĽṹ�����
//int main()
//{
//	//�����ֲ��Ľṹ�����
//	struct Stu s;
//	return 0;
//}
//ע�⣺�����ٶ���ȫ�ֱ���
//���͵Ĵ�����ռ�ڴ�ռ䣬ֻҪͨ�����ʹ����˱�������ʱ�����͵ı����Ż�ռ�ÿռ�

//�ṹ�����͵�������ʽ2��
//typedef struct tag
//{
//	member - list;
//}tag;
//�ֺŲ��ܶ�

//typedef struct Stu
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;//���ṹ������struct Stu �����ض���ΪStu����
//int main()
//{
//	//�����ֲ��Ľṹ�����
//	struct Stu s1;
//	Stu s2;
//	return 0;
//}

//2���ṹ���ʼ��
//typedef struct Stu
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;//���ṹ������struct Stu �����ض���ΪStu����
//int main()
//{
//	//�����ֲ��Ľṹ�����
//	struct Stu s1 = { "����",20,"18866668888","��" };//����������ͬʱ��ʼ��
//	Stu s2 = { "����",30,"16688886666","����" };
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;//�ṹ���Ա�����������ṹ�����
//	//struct S* ps;//�ṹ�����͵�ָ�����
//	//struct T* pt;//�����ṹ�����͵�ָ�����
//	char* pc;
//}t1 = { "hehe",{100,'w',"hello",3.14},NULL };
//int main()
//{
//
//	char arr[] = "hello bit\n";
//	struct T t2 = { "hehe",{100,'w',"hello",3.14},arr };
//
//}
//�ṹ�ĳ�Ա�����Ǳ��������顢ָ�룬�����������ṹ�塣

//3���ṹ���Ա����
//����1��
//�ṹ��������ʳ�Ա��
//�ṹ�����ĳ�Ա��ͨ�����������.�����ʵġ������������������������
//#include <stdio.h>
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//struct T
//{
//	char ch[10];
//	struct S s;//�ṹ���Ա�����������ṹ�����
//	char* pc;
//};
//int main()
//{
//	char arr[] = "hello bit\n";
//	struct T t = { "hehe",{100,'w',"hello",3.14},arr };
//	printf("%s\n", t.ch);//hehe
//	printf("%s\n", t.s.arr);//hello//�ṹ���Ա�еı�����ֻ���ڽṹ����ʹ�ã�����������ͬ��������Ӱ��
//	printf("%lf\n", t.s.d);//3.14
//	printf("%p\n", t.pc);//00EFF8D0
//	printf("%s\n", t.pc);//hello bit//���ﲻ��Ҫ*pc�����򱨴�
//
//}

//����2��
//�ṹ��ָ�����ָ������ĳ�Ա
//��ʱ�����ǵõ��Ĳ���һ���ṹ�����������ָ��һ���ṹ���ָ�롣
//#include <stdio.h>
//typedef struct Stu
//{
//	char name[20];
//	short age;
//	char tel[12];
//	char sex[5];
//}Stu;
//void Print1(Stu tmp)
//{
//	printf("name: %s\n", tmp.name);
//	printf("age: %d\n", tmp.age);
//	printf("tel: %s\n", tmp.tel);
//	printf("sex: %s\n", tmp.sex);
//}
//void Print2(Stu* ps)
//{
//	printf("name: %s\n", (*ps).name);
//	printf("age: %d\n", (*ps).age);
//	printf("tel: %s\n", (*ps).tel);
//	printf("sex: %s\n", (*ps).sex);
//
//	printf("name: %s\n", ps->name);
//	printf("age: %d\n", ps->age);
//	printf("tel: %s\n", ps->tel);
//	printf("sex: %s\n", ps->sex);//->�Դ������ò���
//}
//int main()
//{
//	Stu s = { "����",40,"18899998888","��" };
//	//��ӡ�ṹ������
//	Print1(s);//���ṹ�����
//	Print2(&s);//���ṹ������ĵ�ַ
//	//Print1��Print2����Print2����;
//	//��һ�ַ�������Ϊ�β���ʵ�ε�һ����ʱ�������βλ������ʵ�εȴ�Ŀռ䣬
//	//���ʵ����Դ�ϴ������Դ�˷ѽϴ�ͬʱ����Ҳ��Ҫʱ�����Ľϴ�
//	//�ڶ��ַ��������ڴ�����ǵ�ַ���򱣴��ַ�Ŀռ����
//
//	//�ܽ᣺�ṹ�崫�ε�ʱ��Ҫ���ṹ��ĵ�ַ��
//	return 0;
//}

//4���ṹ�崫��
//�ڴ�ֳɣ�ջ������������̬��
//ջ������ŵ��У��ֲ���������������ʽ��������������Ҳ���ٿռ�
//��������̬�ڴ���䣺malloc/free��realloc��calloc
//��̬������ŵ��У�ȫ�ֱ������ֲ�����
//�������ε�ʱ�򣬲�������Ҫѹջ�ġ�
//�������һ���ṹ������ʱ�򣬽ṹ����󣬲���ѹջ�ĵ�ϵͳ�����Ƚϴ����Իᵼ�����ܵ��½���