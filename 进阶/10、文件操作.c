#define _CRT_SECURE_NO_WARNINGS 1
//C�����ļ�����
//1. Ϊʲôʹ���ļ�
//����ǰ��ѧϰ�ṹ��ʱ��д��ͨѶ¼�ĳ��򣬵�ͨѶ¼����������ʱ�򣬿��Ը�ͨѶ¼�����ӡ�ɾ�����ݣ�
//��ʱ�����Ǵ�����ڴ��У��������˳���ʱ��ͨѶ¼�е�������Ȼ�Ͳ������ˣ����´�����ͨѶ¼�����ʱ�������ֵ�����¼�룬���ʹ��������ͨѶ¼�ͺ����ܡ�
//���������Ȼ��ͨѶ¼��Ӧ�ð���Ϣ��¼������ֻ�������Լ�ѡ��ɾ�����ݵ�ʱ�����ݲŲ������ڡ�
//����漰�������ݳ־û������⣬����һ�����ݳ־û��ķ����У������ݴ���ڴ����ļ�����ŵ����ݿ�ȷ�ʽ��
//ʹ���ļ����ǿ��Խ�����ֱ�Ӵ���ڵ��Ե�Ӳ���ϣ����������ݵĳ־û���

//2. ʲô���ļ�
//�����ϵ��ļ����ļ���
//�����ڳ�������У�����һ��̸���ļ������֣������ļ��������ļ������ļ����ܵĽǶ�������ģ���
//1 �����ļ�:����Դ�����ļ�����׺Ϊ.c��, Ŀ���ļ���windows������׺Ϊ.obj��, ��ִ�г���windows������׺Ϊ.exe����
//2 �����ļ�:�ļ������ݲ�һ���ǳ��򣬶��ǳ�������ʱ��д�����ݣ��������������Ҫ���ж�ȡ���ݵ��ļ�������������ݵ��ļ���
//�������۵��������ļ���
//����ǰ�������������ݵ���������������ն�Ϊ����ģ������ն˵ļ����������ݣ����н����ʾ����ʾ���ϡ�
//��ʵ��ʱ�����ǻ����Ϣ����������ϣ�����Ҫ��ʱ���ٴӴ����ϰ����ݶ�ȡ���ڴ���ʹ�ã����ﴦ��ľ��Ǵ������ļ���
//3 �ļ���:һ���ļ�Ҫ��һ��Ψһ���ļ���ʶ���Ա��û�ʶ������á�
//�ļ�������3���֣��ļ�·�� + �ļ������� + �ļ���׺
//���磺 c:\code\test.txt
//Ϊ�˷���������ļ���ʶ������Ϊ�ļ�����

//3. �ı��ļ��Ͷ������ļ�
//�������ݵ���֯��ʽ�������ļ�����Ϊ�ı��ļ����߶������ļ���
//�������ڴ����Զ����Ƶ���ʽ�洢���������ת������������ �����ڴ��е�����ֱ�ӷŵ��ļ��У����Ƕ������ļ���
//���Ҫ�����������ASCII�����ʽ�洢������Ҫ�ڴ洢ǰת��(�����ڴ��е�����ת��Ϊ�ַ�)����ASCII�ַ�����ʽ�洢���ļ������ı��ļ���
//Ҳ����˵���ı��ļ����ǿ��Կ��ö��ġ����������ļ����ǿ������ġ�
//һ���������ڴ�������ô�洢���أ�
//�ַ�һ����ASCII��ʽ�洢����ֵ�����ݼȿ�����ASCII��ʽ�洢��Ҳ����ʹ�ö�������ʽ�洢��
//�磺�ڴ���������10000
//1�������ASCII�����ʽ���������(���ڴ��е�����10000ת���ַ�'1''0''0''0''0''0'�洢��������)���������ռ��5���ֽڣ�ÿ���ַ�һ���ֽڣ���
//2������Զ�������ʽ���������(���ڴ��е�����10000ֱ�Ӵ洢��������)����Ϊ���������ͣ����ڴ�����ֻռ���ʹ�С�Ŀռ䣬��4���ֽڡ�
//������
//1���ڴ��еĴ洢��ʽ��10000(ʮ����)�Ķ����ƴ洢 - 00000000 00000000 00100111 00010000
//2���ı��ļ�����ASCII��ʽ�洢��00110001(1) 00110000(0) 00110000(0) 00110000(0) 00110000(0)
//3���������ļ����Զ�������ʽ�洢��00000000 00000000 00100111 00010000
/*
#include <stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//write binary ��test.txt�ļ����Զ�������ʽд����ļ������ļ�������ʱ��fopen�ᴴ���ļ�
	fwrite(&a, 4, 1, pf);//fwriteд�ļ�����a��ַ�������ݣ�дһ��4���ֽڵ����ݣ�����pfָ��ά�������ڵ��ļ���
	fclose(pf);//�ر��ļ�
	pf = NULL;
	return 0;
}
*/
//���к�ʹ���ı��༭������һ������ġ�ʹ��VS���ļ��鿴
//��test.txt�ļ���ӵ����̺�"Դ�ļ�" - "���" - "������"��ѡ��test.txt���Ҽ�-�򿪷�ʽ���Զ����Ʊ༭���򿪡�
//����00 00 27 10��С�˴洢���ʸ���Ϊ��0x10 27 00 00
//ע�⣺��Ȼ��������ʮ���������ݣ���������ײ�洢�Ļ��Ƕ���������(��0��1��ɵ�����)
//����ʮ������0x10270000  = ʮ����10000

//4. �ļ�������
//ANSIC ��׼(��׼C)���á������ļ�ϵͳ�����������ļ��ġ�
//��ν�����ļ�ϵͳ��ָϵͳ�Զ������ڴ���Ϊ������ÿһ������ʹ�õ��ļ�����һ�顰�ļ�����������
//���ڴ������������ݻ����͵��ڴ��е������������װ�����������һ���͵������ϡ�
//����Ӵ����������������ݣ���Ӵ����ļ��ж�ȡ�������뵽�ڴ����뻺��������������������Ȼ���ٴӻ���������ؽ������͵���������������������ȣ���
//�������Ĵ�С����C����ϵͳ�����ġ�
//�����������ã����CPU�Ĳ���Ч�ʡ����磺ÿ��д��һ���ַ����ļ��У��м�û�л��塣���Ƶ����д��ͻ�ʹ��CPU���������������޷����CPU.����Ȱ�һЩ����
//�ŵ��������ϣ���ʹ��CPU,�������ó�CPU��ʹ��CPU�����������

//��������Ϊ��
//1��ȫ����������������׼I/O�����Ž���ʵ��I/O������(�磺ȫ����ĵ��ʹ����ǶԴ����ļ��Ķ�д��)
//2���л����������������������������з�ʱ��ִ��������I/O������(���ʹ����Ǳ�׼����(stdin)�ͱ�׼���(stdout)��)ע�⣺���з�Ҳ�����뻺������
//3�����������������ʹ����Ǳ�׼����stderr

//ˢ�»�������(��ջ��������������ݽ�������)
//1�����������ˣ���ˢ��
//2���л������� '\n' ��ˢ�£�
//3������ fflush()������
//4������ fclose();
//�������������������������ݣ����в�������ĵ���
/*
#include <stdio.h>
//Linux��������
int main()
{
	while (1)
	{
		sleep(1);//��λ����
		printf("hehe\n");
	}
	return 0;
}
*/
//���������1�룬�ն�Ҳû�д�ӡ��hehe��.ֻ�е�������������ˣ��Ż���ʾ
//���������������� ����Ļ(Ҳ��һ���ļ�)֮����һ���������������printf������Ƚ����ݷŵ����������
//ֻ�е�������������ˣ��ŻὫ�����������ݷŵ���Ļ�ϡ�
/*
#include <stdio.h>
#include <windows.h>
//WIN10��������
int main()
{
	FILE* pf = fopen("test.txt", "w");
	//Write a string to a stream.
	//int fputs(const char* string, FILE * stream);

	fputs("abcdef", pf);//�Ƚ����ݷ������������
	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
	Sleep(10000);//��λ������
	printf("ˢ�»�����\n");
	//Flushes a stream.
	//int fflush(FILE * stream);

	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
	//ע��fflush �ڸ߰汾��VS�Ͽ��ܲ���ʹ����
	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
	Sleep(10000);
	fclose(pf);
	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
	pf = NULL;
	return 0;
}
*/
//������Եó�һ�����ۣ���Ϊ�л������Ĵ��ڣ�C�����ڲ����ļ���ʱ����Ҫ��ˢ�»������������ļ�����������ʱ��ر��ļ���
//������������ܵ��¶�д�ļ������⡣

//5���ļ�ָ��
//�����ļ�ϵͳ�У��ؼ��ĸ����ǡ��ļ�����ָ�롱����ơ��ļ�ָ�롱��
//ÿ����ʹ�õ��ļ������ڴ��п�����һ����Ӧ���ļ���Ϣ������������ļ��������Ϣ�����ļ������֣��ļ�״̬���ļ���ǰ��λ�õȣ���
//��Щ��Ϣ�Ǳ�����һ���ṹ������еġ��ýṹ����������ϵͳ�����ģ�ȡ��FILE.
//���磬VS2013���뻷���ṩ�� stdio.h ͷ�ļ��������µ��ļ���������������FILE��ת�����壬�ɲ鿴FILE�ṹ��������Ϣ
//��ͬ��C��������FILE���Ͱ��������ݲ���ȫ��ͬ�����Ǵ�ͬС�졣
//ÿ��fopen������һ���ļ���ʱ��ϵͳ������ļ�������Զ�����һ��FILE�ṹ�ı�����(�����ڲ�����FILE���͵Ľṹ�����������ά���ļ���Ϣ����������һ���ļ���Ϣ���ռ����ʼ��ַ)
//��������е���Ϣ��ʹ���߲��ع���ϸ�ڡ�
//һ�㶼��ͨ��һ��FILE��ָ����ά�����FILE�ṹ�ı���������ʹ���������ӷ��㡣

//�������ǿ��Դ���һ��FILE*��ָ�����:FILE* pf;//pf�ļ�ָ�����
//����pf��һ��ָ��FILE�������ݵ�ָ�����������ʹpfָ��ĳ���ļ����ļ���Ϣ������һ���ṹ���������
//ͨ�����ļ���Ϣ���е���Ϣ���ܹ����ʸ��ļ���Ҳ����˵��ͨ���ļ�ָ������ܹ��ҵ������������ļ���

//6. �ļ��Ĵ򿪺͹ر�
//�ļ��ڶ�д֮ǰӦ���ȴ��ļ�����ʹ�ý���֮��Ӧ�ùر��ļ���
//�ڱ�д�����ʱ���ڴ��ļ���ͬʱ�����᷵��һ��FILE* ��ָ�����ָ����ļ���Ҳ�൱�ڽ�����ָ����ļ��Ĺ�ϵ��
//ANSIC �涨ʹ��fopen���������ļ���fclose���ر��ļ���
//1��fopen���ļ���
//FILE* fopen(const char* filename, const char* mode);
//mode�������򿪷�ʽ
//�򿪳ɹ��������ļ���Ӧ��ָ�룬��ʧ�ܣ��򷵻�NULL
//2��fclose�ر��ļ���
//int fclose(FILE* stream);
//ע�⣺fopen��fclose��������stdio.h��

//�򿪷�ʽ���£�
/*
	�ļ�ʹ�÷�ʽ    ����                                           ���ָ���ļ�������			���似��			��⼼��
	��r����ֻ����   Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�       ����							read				��ֻ���ķ�ʽ���ı��ļ����ļ��������
	��w����ֻд��   Ϊ��������ݣ���һ���ı��ļ�(�����ؽ�д)     ����һ���µ��ļ�				write				��ֻд�ķ�ʽ���ı��ļ����ļ�������������ļ����ݴ��ļ�ͷ����ʼд����������������ļ����������ļ���ֻд��
	��a����׷�ӣ�   ���ı��ļ�β�������(׷��д)                   ����һ���µ��ļ�				append				��ֻд�ķ�ʽ���ı��ļ����ļ�����������ļ�β����׷�ӵķ�ʽ��ʼд���ļ�ԭ�����ڵ����ݲ�������������ļ�β��־EOF������������������ļ����������ļ���ֻд��
	��rb����ֻ����  Ϊ���������ݣ���һ���������ļ�               ����							read binary			�������ļ�ģʽ��
	��wb����ֻд��  Ϊ��������ݣ���һ���������ļ�               ����һ���µ��ļ�				write binary		�������ļ�ģʽд
	��ab����׷�ӣ�  ��һ���������ļ�β�������                     ����һ���µ��ļ�				append binary		�������ļ�ģʽ׷��
	��r+������д��  Ϊ�˶���д����һ���ı��ļ�                   ����							read+write			�Կɶ�д�ķ�ʽ���ı��ļ����ļ��������
	��w+������д��  Ϊ�˶���д���½�һ���µ��ļ�                   ����һ���µ��ļ�				write+read			�Կɶ�д�ķ�ʽ���ı��ļ���������wһ��
	��a+������д��  ��һ���ļ������ļ�β���ж�д                 ����һ���µ��ļ�				append+read+write	�Կɶ�д�ķ�ʽ���ı��ļ���������aһ��
	��rb+������д�� Ϊ�˶���д��һ���������ļ�                   ����							read binary+write binary					
	��wb+������д�� Ϊ�˶���д���½�һ���µĶ������ļ�             ����һ���µ��ļ�				write binary+read binary
	��ab+������д�� ��һ���������ļ������ļ�β���ж���д         ����һ���µ��ļ�				append binary+read binary+write binary
	//���򿪶������ļ������ں���Ӹ�bע��������һ������rb��r+b����rb+����
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE* pFile;
    //���·��
    //..��ʾ��һ��·��
    //.��ʾ��ǰ·��
    //��ǰ·������һ������һ��·��
    //../..
    
    //���ļ�
    pFile = fopen("myfile.txt", "w");//�򿪵�ǰ·���µ��ļ� - ���·��
    //pFile = fopen("D:\\VS2019\\code\\text\\myfile.txt", "w");//����·��
	//pFile = fopen("D:/VS2019/code/text/myfile.txt", "w");//����·��
    if (pFile == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;//�ü�return 0;����fclose(pFile);��һ�лᱨ���棺pFile����Ϊ0
		//��Ϊ���pFileΪ�պ󣬻������fclose(pFile);����
    }
	//�ļ����� - �ļ��Ķ�д����
	//...
	
    //�ر��ļ�
    fclose(pFile);//���ṹ���ļ���Ϣ������Դ�ͷŵ�������ָ�뻹�ڣ���Ҫ�ÿ�
    pFile = NULL;
    return 0;
}
//ע�⣺fopen("myfile.txt", "w");
//��myfile.txt������Ϣ���Ὣ���ļ����٣����½������ļ�����д��
*/

//7. �ļ���˳���д�����MSDN��
/*
	����           ������       ������			����							����ԭ��
	�ַ����뺯��   fgetc        ����������    - �����ж�ȡһ���ַ�				int fgetc( FILE *stream );
	�ַ��������   fputc        ���������    - ������д��һ���ַ�				int fputc(int c, FILE * stream);
	�ı������뺯�� fgets        ����������    - �����ж�ȡһ���ַ�				char *fgets( char *string, int n, FILE *stream );
	�ı���������� fputs        ���������    - ������д��һ���ַ�				int fputs( const char *string, FILE *stream );
	��ʽ�����뺯�� fscanf       ����������    - ��ʽ����ʽ�����ж�ȡ�ַ�		int fscanf( FILE *stream, const char *format [, argument ]... );
	��ʽ��������� fprintf      ���������    - ��ʽ����ʽ������д���ַ�		int fprintf( FILE *stream, const char *format [, argument ]...);
	����������     fread        �ļ�		  - ���ļ��ж�ȡ					size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
	���������     fwrite       �ļ�		  - ���ļ���д��					size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
	//������ļ����ԣ���������ǣ�������д�뵽�ļ�����������������ݴ��ļ����ó�������
	//����ڳ�����ԣ���������ǣ������ݴӳ����зŵ��ļ��������������д�뵽������������
	//ע�⣺���ڴ��е��������ļ���д�룬��д���������ļ������ǣ�������������ļ��ж����ݵ��ڴ棬�Ƕ����������ļ������ǣ����������
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE* pfWrite;
    pfWrite = fopen("myfile.txt", "w");//pfWrite��ָ����ļ���д�ķ�ʽ�򿪣����ļ������
    if (pfWrite == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //д�ļ�
	//int fputc(int c, FILE * stream);	
    fputc('b', pfWrite);//�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)������������ļ�ָ�����ƫ��1
    fputc('i', pfWrite);//�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)������������ļ�ָ�����ƫ��1
    fputc('t', pfWrite);//�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)������������ļ�ָ�����ƫ��1
    //�ر��ļ�
    fclose(pfWrite);//�ر��ļ�����ˢ��������������ļ��вŻ������ݣ����ļ���Ϣ�����ָ�븴ԭ
    pfWrite = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE* pfRead;
    pfRead = fopen("myfile.txt", "r");//pfRead��ָ����ļ��Զ��ķ�ʽ�򿪣����ļ�������
    if (pfRead == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //���ļ�
	//int fgetc( FILE *stream );  fgetc����һ��ASCII��ֵ
    printf("%c", fgetc(pfRead));//b		fgetc(pfRead)�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)���뻺�������ļ�ָ�����ƫ��1		printf("%c",'b');�ŵ�(Ϊ�ļ�stdout���ٵ�)������������ļ�ָ�����ƫ��1
    printf("%c", fgetc(pfRead));//i		fgetc(pfRead)�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)���뻺�������ļ�ָ�����ƫ��1		printf("%c",'i');�ŵ�(Ϊ�ļ�stdout���ٵ�)������������ļ�ָ�����ƫ��1
    printf("%c", fgetc(pfRead));//t		fgetc(pfRead)�ŵ�(Ϊ�ļ�myfile.txt���ٵ�)���뻺�������ļ�ָ�����ƫ��1		printf("%c",'t');�ŵ�(Ϊ�ļ�stdout���ٵ�)������������ļ�ָ�����ƫ��1
    //�ر��ļ�
    fclose(pfRead);//�ر��ļ�����ˢ���������������Ļ�ϲŻ������ݣ����ļ���Ϣ�����ָ�븴ԭ
	//���ṹ���ļ���Ϣ������Դ�ͷŵ�������ָ�뻹�ڣ���Ҫ�ÿ�
    pfRead = NULL;
    return 0;
}
*/

//�Ӽ�������
//�������Ļ
//���̺���Ļ�����ⲿ�豸�������ϻ��Ǹ��ļ���Ҳ�����豸��
//���� - �Ǳ�׼�����豸 - stdin(����ΪFile*)
//��Ļ - �Ǳ�׼����豸 - stdout(����ΪFile*)
//ÿ��һ������ stdin stdout stderr �������ļ���ָ��Ĭ�ϴ򿪵ġ�����ͨ�ļ��Ƚϣ���׼�豸Ĭ�ϲ���Ҫ�򿪺͹ر�
/*
#include <stdio.h>
int main()
{
	//fgetc��fputc�������������������������������ļ�����Ҳ���������豸
	int ch = fgetc(stdin);//�Ӽ��̻�ȡ���ݣ�(��stdin��ȡ���ݣ����ڻ�����û��������Ҫ�����ȴ�)
	fputc(ch, stdout);//�������������Ļ,(������д�뵽stdout��)
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    char buf[1024] = { 0 };
    FILE* pf;
    pf = fopen("myfile.txt", "r");//�ļ���д��bit����hello
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //���ļ�
	//char* fgets(char* string, int n, FILE * stream);  

    //fgets(buf, 1024, pf);//��ȡ��һ�У���pf��ָ����ļ��ж�ȡ���1024���ַ�,����buf��
    //printf("%s", buf);//����bit���У����\nҲ����buf�У��ʽ���ỻ��
    
    //fgets(buf, 1024, pf);//��ȡ�ڶ���
    //printf("%s", buf);//����hello��û�л��У��ʽ�����ỻ��
	//ע�⣺���ֻ��һ�У���ȡ���Σ����ν����һ���ġ�����ж��У���ÿ�ζ�ȡ�Ľ������һ��

    fgets(buf, 1024, pf);
	//int puts( const char *string );
    puts(buf);//���ַ�����һ�У��������Ļ�ϣ�������

    fgets(buf, 1024, pf);
    puts(buf);//���ַ�����һ�У��������Ļ�ϣ�������
    //ע�⣺putsд��(���)����������
	//ע�⣺���ֻ��һ�У���ȡ���Σ����ν����һ���ġ�����ж��У���ÿ�ζ�ȡ�Ľ������һ��
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    char buf[1024] = { 0 };
    FILE* pf;
    pf = fopen("myfile.txt", "w");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return 0;
    }
    //д�ļ�
    //int fputs( const char *string, FILE *stream );
    fputs("hello", pf);
    fputs("world", pf);
    fputs("hello\n", pf);
    fputs("world", pf);
    //ע�⣺fputsд�벻���������У�д��'\n'�Żỻ��
    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    //fgets��fputs������������
    //��stdin��ȡһ���ı���Ϣ
    char buf[1024] = { 0 };
    fgets(buf, 1024, stdin);//�ӱ�׼�����ȡ��(���ڻ�����û�����������ȴ�����)
    fputs(buf, stdout);//�������׼���
    
    //�ȼ����£���Ϊgets��puts�Ǳ�׼�����������
    //gets(buf);//�ú����Ѿ���̭��
    puts(buf);
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
struct S
{
    int n;
    float score;
    char arr[10];
};
int main()
{
    struct S s = { 100, 2.14f, "bit" };
    FILE* pf = fopen("test.txt", "w");
    if (pf == NULL)
    {
        return 0;
    }
    //��ʽ������ʽд�ļ�
    //               int printf( const char *format [, argument]... );
    //int fprintf( FILE *stream, const char *format [, argument ]...);
    fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
struct S
{
    int n;
    float score;
    char arr[10];
};
int main()
{
    struct S s = { 0 };
    FILE* pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        return 0;
    }
    //��ʽ������ʽ���ļ�
    //               int scanf( const char *format [,argument]... );
    //int fscanf( FILE *stream, const char *format [, argument ]...);
    fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
    printf("%d %f %s", s.n, s.score, s.arr);
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
struct S
{
    int n;
    float score;
    char arr[10];
};
int main()
{
    //fscanf��fprintf������������
    struct S s = { 0 };
    fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);//�ӱ�׼�����ȡ��(���ڻ�����û�����������ȴ�����)
    fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);//�������׼���
    return 0;
}
*/

//�Ա�һ�麯����
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
//scanf / fscanf ���� printf / fprintf����ֻ��һ��ָ���ļ�����
//scanf��printfֻ�����ڱ�׼������/��׼������ĸ�ʽ������/������
//fscanf��fprintf�ȿ������ڱ�׼������/��׼������ĸ�ʽ������/�����䣬Ҳ���������ļ�����ʽ���ĸ�ʽ������/������
//sscanf���ַ����ж�ȡ��ʽ��������
//sprintf�Ѹ�ʽ������������ɣ��洢�ɣ��ַ���

//sscanf/sprintf
//���뺯�� - ��ȡbuf����buf�е��ַ���ת���ɸ�ʽ��������
//int sscanf( const char *buffer, const char *format [, argument ] ... );
//������� - ����ʽ��������ת�����ַ�����д��buf��
//int sprintf( char *buffer, const char *format [, argument] ... );
/*
#include <stdio.h>
struct S
{
    int n;
    float score;
    char arr[10];
};
int main()
{
    struct S s = { 100,3.14f,"abcdef" };
    struct S tmp = { 0 };
    char buf[1024] = { 0 };
    //�Ѹ�ʽ��������ת�����ַ����洢��buf��
    sprintf(buf, "%d %.2f %s", s.n, s.score, s.arr);
    printf("%s\n", buf);//"100 3.140000 abcdef"

    //��buf�ж�ȡ�ַ���ת���ɸ�ʽ��������
    sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
    printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    char buf[1024] = "GET test.c HTTP/1.1";
    char reqType[16] = { 0 };
    char fileName[255] = { 0 };
    char protocal[16] = { 0 };
    sscanf(buf, "%[^ ] %[^ ] %[^ ]", reqType, fileName, protocal);
    printf("%s %s %s\n", reqType, fileName, protocal);

    int code = 404;
    char* messages = "NOT FOUND";
    sprintf(buf, "%s %d %s", protocal, code, messages);
    printf("%s", buf);
    return 0;
}
*/

/*
#include <stdio.h>
struct S
{
    char name[20];
    int age;
    double score;
};
int main()
{
    struct S s = { "����",20,55.6 };
    FILE* pf = fopen("test.txt", "wb");
    if (pf == NULL)
    {
        return 0;
    }
    //�����Ƶ���ʽд�ļ�
    //size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );//��buffer��ַ����size���ֽڵ���������д��count������stream��
    //size�������������ֽ�������Ϊһ��Ԫ��д��
    //count������Ҫ����д��Ĵ���
    //����ֵ��ʵ��д�뵽�ĸ������磺��21���ַ���ÿ��д��5����ǰ4�η���5�����һ�η���1
    fwrite(&s, sizeof(struct S), 1, pf);//��1��sizeof(struct S)��С�Ķ���s����Ϣд�뵽pfָ����ļ���
    fclose(pf);
    pf = NULL;

    //���s��һ�����飬�Ϳ���д�������Ϣ
    return 0;
}
*/
/*
#include <stdio.h>
struct S
{
    char name[20];
    int age;
    double score;
};
int main()
{
    struct S s = { 0 };
    FILE* pf = fopen("test.txt", "rb");
    if (pf == NULL)
    {
        return 0;
    }
    //���ļ��ж�ȡ��Ϣ
    //size_t fread(void* buffer, size_t size, size_t count, FILE * stream);//��stream��������ȡcount������size���ֽڵ����ݵ�buffer��ַ��
    //size�������������ֽ�������Ϊһ��Ԫ�ض�ȡ
    //count������Ҫ������ȡ�ĸ���
    //����ֵ��ʵ�ʶ�ȡ���ĸ������磺��21���ַ���ÿ�ζ�ȡ5����ǰ4�η���5�����һ�η���1
    fread(&s, sizeof(struct S), 1, pf);//��1��sizeof(struct S)��С�Ķ���s����Ϣ��pf��ָ����ļ��ж���
    //��Ȼ�Զ�������ʽд�뿴���������ǿ��Դ��ļ����Զ�������ʽ����
    printf("%s %d %lf\n", s.name, s.age, s.score);
    fclose(pf);
    pf = NULL;
    //ע�⣺�����������ݣ�s�����������Ŷ�����ݡ��磺fread(&s, sizeof(struct S), 3, pf);s������������3���������ݵĿռ�
    
    //���s��һ�����飬�Ϳ��Զ�ȡ�����Ϣ
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    int arr[] = { 48,49,50,51,52};
    FILE* pf = fopen("test15.txt", "w+");//����ģʽ�򿪣������rewind����������ʵ�ֶ���д����
    if (pf == NULL)
    {
        return 0;
    }
    int buf[255] = { 0 };
    //����1��
    //fwrite(arr, sizeof(int), 5, pf);//�ӵ�һ��Ԫ�صĵ�ַ��ʼ������д��5�Σ�ÿ��д��4���ֽڵ�pfָ����ļ���
    //rewind(pf);
    //fread(buf, sizeof(int), 5, pf);//�ӵ�һ��Ԫ�صĵ�ַ��ʼ����������5�Σ�ÿ�ζ���4���ֽڵ�bufָ����ļ���
    //printf("%d %d %d %d %d", buf[0], buf[1], buf[2], buf[3], buf[4]);
    
    //����2��
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        fwrite(&arr[i], sizeof(int), 1, pf);//fwrite(arr, sizeof(int), 1, pf); - ���Ǵ����
    }
    fclose(pf);//���ַ�ʽʵ�ֶ�д����Ҫ���´��ļ�
    pf = fopen("test15.txt", "r");
    for (i = 0; i < 5; i++)
    {
        fread(&buf[i], sizeof(int), 1, pf);//fread(buf, sizeof(int), 1, pf); - ���Ǵ����
        printf("%d ", buf[i]);
    }
    fclose(pf);
    pf = NULL;

    //���s��һ�����飬�Ϳ��Զ�ȡ�����Ϣ
    return 0;
}
*/
//ע�⣺���Ϻ��������д��һ���ַ��������ļ���������һ���ո�����ո�����ַ�����\0

//�ܽ᣺
//fgetc/fputc	        ���������������ն�����س���fgetc���Զ�ȡ���س���
//fgets/fputs	        ������������    fgets��ȡһ���ַ��������ȡ�س�����ͬʱ�����ַ�����β�Զ����\0. fputs��������������С�
//getc/putc	            ���������������ն�����س���getc���Զ�ȡ���س���      
//getchar/putchar       ���������������ն�����س���getchar���Զ�ȡ���س���  
//gets/puts             �Ǳ�׼�������	�ӱ�׼����������ж�/ȡ����.puts������Զ������һ�����С�
//scanf/printf	        �Ǳ�׼�������	�ӱ�׼����������ж�/ȡ���ݡ�scanf��ȡ���ո���ַ����������ո����.gets����̭�ˡ�
//scanf��ȡ�ն��ϵ�����ʱ�������ȡ�س������������ַ�����β�Զ����\0
//fscanf/fprintf	    ������������ 	fscanf��ȡ���ո���ַ����������ո������fscanf�����ȡ�س������������ַ�����β�Զ����\0
//fread/fwrite          �������ļ���	fread(buf, sizeof(buf),1, stdin);��Ȼû�б��������޷�����

//sscanf/sprintf        ��ʽ���������ַ������໥ת�������������������
//ע�⣺����������ն�����Ļس���������ߡ�Windows�µ�IO�����������Ǵ�����ġ�ֻ��puts�����ʱ����Զ������һ������
//���⣺�����������ݶ��ߺ󣬻�����
//������Ϊ�ǲ����ˣ���ʵ�ǻ��ڵģ�
//����ܾ��漰����ϵͳ��ʵ���ˣ�����Ϊϵͳ�������϶���һ�� buffer����һ��ָ��ά�������buffer���ݣ�
//�������һ������ʱ��ָ��϶�������һ��λ�ã��������ݻ����ڵģ������������ݽ��뻺�������ǵ����λ���ϵ����ݡ�
//���ǣ���Щά��buffer��ָ��ֵ���ǿ϶����ʲ����������˵������һ�����ݺ󣬼�ʹ�ǻ����ڵģ�����Ҳ�޷��ٷ����ˣ���ͬ�� ���ݱ����ߺ�Ͳ����ˡ�

//ע�⣺ʹ�ú���ʱ����Ҫ�˽⣬�βΣ�����ֵ��

//8. �ļ��������д
//1 fseek
//int fseek(FILE * stream, long int offset, int origin);
//��originΪ��㣬����ƫ����offset���������ļ�ָ��stream��λ�á�
//origin��SEEK_CUR�ļ�ָ��ĵ�ǰλ�á� SEEK_END�ļ�ָ���ĩβλ�á�SEEK_SET�ļ�ָ�����ʼλ�ã�Ĭ�ϣ�
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (pf == NULL)
    {
        return 0;
    }
    //1����λ�ļ�ָ��
    fseek(pf, 4, SEEK_CUR);//��SEEK_CURλ�ã����ƫ��4
    //2����ȡ�ļ�
    int ch = fgetc(pf);
    printf("%c\n", ch);//e

    fseek(pf, -2, SEEK_END);//��SEEK_ENDλ�ã���ǰƫ��2����������Ϊ2
    //2����ȡ�ļ�
    ch = fgetc(pf);
    printf("%c\n", ch);//e

    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	FILE* pFile;
	pFile = fopen("example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);//This is a sample.
	fclose(pFile);
	return 0;
}
*/

//2 ftell
//long int ftell(FILE* stream);
//����ֵ�������ļ�ָ���������ʼλ�õ�ƫ����
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (pf == NULL)
    {
        return 0;
    }
    fseek(pf, -2, SEEK_END);
    int pos = ftell(pf);
    printf("%d\n", pos);//4

    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (pf == NULL)
    {
        return 0;
    }
    int pos = ftell(pf);
    printf("%d\n", pos);//0

    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (pf == NULL)
    {
        return 0;
    }
    //��ȡ�ļ�
    fgetc(pf);
    int pos = ftell(pf);//1
    printf("%d\n", pos);

    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    FILE* pFile;
    long size;
    pFile = fopen("myfile.txt", "rb");//myfile.txt�к���bit�ı�
    if (pFile == NULL) 
        perror("Error opening file");
    else
    {
        fseek(pFile, 0, SEEK_END);   // non-portable
        size = ftell(pFile);
        fclose(pFile);
        printf("Size of myfile.txt: %ld bytes.\n", size);//3
    }
    return 0;
}
*/

//3 rewind
//void rewind(FILE * stream);
//���ļ�ָ���λ�ûص��ļ�����ʼλ��
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (pf == NULL)
    {
        return 0;
    }
    //��ȡ�ļ�
    int ch = fgetc(pf);
    printf("%c\n", ch);//a����ʱָ��ָ���b
    rewind(pf);
    ch = fgetc(pf);
    printf("%c\n", ch);//a

    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    int n;
    FILE* pFile;
    char buffer[27];
    pFile = fopen("myfile.txt", "w+");
    for (n = 'A'; n <= 'Z'; n++)
        fputc(n, pFile);
    rewind(pFile);
    fread(buffer, 1, 26, pFile);
    fclose(pFile);
    buffer[26] = '\0';
    puts(buffer);//ABCDEF...Z
    return 0;
}
*/

//9. �ļ���ȡ�������ж�
/*
#include <stdio.h>
int main()
{
    //EOF - end of file == -1
    FILE* pf = fopen("test.txt", "r");//test.txt��û������(���ļ�)
    if (pf == NULL)
    {
        return 0;
    }
    //��ȡ�ļ�
    int ch = fgetc(pf);
    printf("%d\n", ch);//-1��˵���ļ���ȡ����
    
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
//������ʹ�õ�feof��
//�μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ����Ƿ������
//����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡ��������������������ļ�βEOF��������
//����feof�������ж��ļ��Ƿ�����Ϊ��ȡEOF���������
//feof��û�ж����ʱ�򣬷���0���ڶ����ʱ�򷵻�-1��Ҳ���Ƿ���EOF��
//1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF��ʹ��fgetc��ȡ�ַ�������EOF��-1��������NULL��fgets��ȡ�ַ���������NULL��
//���磺
//  fgetc �ж��Ƿ�ΪEOF��˵����ȡ�����ˡ�
//  fgetc �����ڶ�ȡ������ʱ�򣬻᷵��EOF,������ȡ��ʱ�򣬷��ض�ȡ�����ַ���ASCIIm��ֵ
//  fgets �жϷ���ֵ�Ƿ�Ϊ NULL��˵����ȡ�����ˡ�
//  fgets �����ڶ�ȡ������ʱ�򣬻᷵��NULL,������ȡ��ʱ�򣬷��ش���ַ����ռ����ʼ��ַ
//2. �������ļ��Ķ�ȡ�������жϣ�fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//���磺fread�жϷ���ֵС��ʵ��Ҫ���ĸ�����˵����ȡ�����ˡ�
//  fread �����ڶ�ȡ��ʱ�򣬷��ص���ʵ�ʶ�ȡ��������Ԫ�صĸ�����������ֶ�ȡ����������Ԫ�ظ���С��
//ָ����Ԫ�ظ�������������һ�ζ�ȡ�ˡ�
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    //strerror(errno):���ش������Ӧ�Ĵ�����Ϣ���ַ�����ַ����
    printf("%s\n", strerror(errno));

    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test2.txt", "r");
    if (pf == NULL)
    {
        perror("open file test2.txt");//perrorʹ�ô�����Ϣ��������
        //��ӡ��open file test2.txt��No such file or directory
        return 0;
    }
    //...
    fclose(pf);
    pf = NULL;
}
*/

//��ȷ��ʹ�ã�
//�ı��ļ������ӣ�
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test2.txt", "r");
    if (!pf)
    {
        perror("open file test2.txt");//perrorʹ�ô�����Ϣ��������
        return 0;
    }
    //...
    int ch = 0;
    while ((ch = fgetc(pf) != EOF))//EOF=-1��ת�����塣ע�⣺EOF���߼��������
    {
        putchar(ch);//�ع�putc������ʹ��
    }
    if (ferror(pf))
        printf("error\n");
    else if (feof(pf))
        printf("end of file\n");
    fclose(pf);
    pf = NULL;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //�����Ķ��������ǰ��Ϻã���Ϊ�в��ֱ�������֧�ֱ߶����ʹ��
    int c; // ע�⣺int����char��Ҫ����EOF
    FILE* fp = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
    if (!fp) //fpΪNULLʱ������
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    //fread����������
    //fread����ʵ�ʶ�ȡ����������������������������ڵ������֮ǰ�����ļ���β�������������С�ڼ�����
    //ʹ��feof��feror���������ֶ�ȡ������ļ���������������С�����Ϊ0����fread����0�����������ݲ��䡣

    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
    {
        putchar(c);
    }
    //�ж���ʲôԭ�������
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
    fp = NULL;
}
*/

//�������ļ������ӣ�
/*
#include <stdio.h>
enum { SIZE = 5 };
int main(void)
{
    double a[SIZE] = { 1,2,3,4,5 };
    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
    fwrite(a, sizeof(*a), SIZE, fp); // д double ������
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // �� double ������
    if (ret_code == SIZE) {
        puts("Array read successfully, contents: ");
        for (int n = 0; n < SIZE; ++n) 
            printf("%f ", b[n]);
        putchar('\n');
    }
    else { // error handling
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else if (ferror(fp)) {
            perror("Error reading test.bin");
        }
    }
    fclose(fp);
}
*/
/*
#include <stdio.h>
enum { SIZE = 5 };
int main(void)
{
    double a[SIZE] = { 1,2,3,4 ,5 };
    size_t ret_code = 0;
    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
    fwrite(a, sizeof(*a), SIZE, fp); // д double ������
    fclose(fp);
    double b = 0.0;
    fp = fopen("test.bin", "rb");
    while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
    {
        printf("%lf\n", b);
    }
    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    if (feof(fp))
        printf("Error reading test.bin: unexpected end of file\n");
    else if (ferror(fp)) //int ferror( FILE *stream );  Tests for an error on a stream.
    {
        perror("Error reading test.bin");
    }
    fclose(fp);
}
*/

//ע�⣺ʹ�ú���ʱ����Ҫ�˽⣬�βΣ�����ֵ��