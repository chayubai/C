#define _CRT_SECURE_NO_WARNINGS 1
//C�����ļ�����
//1. Ϊʲôʹ���ļ�
//����ǰ��ѧϰ�ṹ��ʱ��д��ͨѶ¼�ĳ��򣬵�ͨѶ¼����������ʱ�򣬿��Ը�ͨѶ¼�����ӡ�ɾ����
//�ݣ���ʱ�����Ǵ�����ڴ��У��������˳���ʱ��ͨѶ¼�е�������Ȼ�Ͳ������ˣ����´�����ͨѶ¼�����ʱ�������ֵ�����¼�룬���ʹ��������ͨѶ¼�ͺ����ܡ�
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
//���磺 c : \code\test.txt
//Ϊ�˷���������ļ���ʶ������Ϊ�ļ�����

//3. �ı��ļ��Ͷ������ļ�
//�������ݵ���֯��ʽ�������ļ�����Ϊ�ı��ļ����߶������ļ���
//�������ڴ����Զ����Ƶ���ʽ�洢���������ת�����������棬���Ƕ������ļ���
//���Ҫ�����������ASCII�����ʽ�洢������Ҫ�ڴ洢ǰת������ASCII�ַ�����ʽ�洢���ļ������ı��ļ���
//һ���������ڴ�������ô�洢���أ�
//�ַ�һ����ASCII��ʽ�洢����ֵ�����ݼȿ�����ASCII��ʽ�洢��Ҳ����ʹ�ö�������ʽ�洢��
//��������10000�������ASCII�����ʽ��������̣��������ռ��5���ֽڣ�ÿ���ַ�һ���ֽڣ�������������ʽ��������ڴ�����ֻռ4���ֽڣ�VS2013���ԣ���
//�磺�ڴ��еĴ洢��ʽ��10000(ʮ����)�Ķ����ƴ洢 - 00000000 00000000 00100111 00010000
//�ı��ļ�����ASCII��ʽ�洢��00110001(1) 00110000(0) 00110000(0) 00110000(0) 00110000(0)
//�������ļ����Զ�������ʽ�洢��00000000 00000000 00100111 00010000
//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//��test.txt�ļ����Զ�������ʽд����ļ������ļ�������ʱ��fopen�ᴴ���ļ�
//	fwrite(&a, 4, 1, pf);//fwriteд�ļ�����a��ַ�������ݣ�дһ��4���ֽڵ����ݣ�����pfά����ָ�����ڵ��ļ���
//	fclose(pf);//�ر��ļ�
//	pf = NULL;
//	return 0;
//}
//���к�ʹ��VS���ļ��鿴
//��test.txt�ļ���ӵ����̺�"Դ�ļ�" - "���" - "������"
//ѡ��test.txt���Ҽ��Զ����Ʊ༭���򿪣�������С�˴洢�ʣ�10 27 00 00
//���ڿ�������ʮ���������ݣ����ײ�洢���Ƕ���������
//��ʮ������00 00 27 10  = ʮ����10000

//4. �ļ�������
//ANSIC ��׼���á������ļ�ϵͳ������������ļ��ģ���ν�����ļ�ϵͳ��ָϵͳ�Զ������ڴ���Ϊ����
//��ÿһ������ʹ�õ��ļ�����һ�顰�ļ��������������ڴ������������ݻ����͵��ڴ��еĻ�������
//װ�����������һ���͵������ϡ�����Ӵ����������������ݣ���Ӵ����ļ��ж�ȡ�������뵽�ڴ滺
//��������������������Ȼ���ٴӻ���������ؽ������͵���������������������ȣ����������Ĵ�С����C����ϵͳ�����ġ�
//#include <stdio.h>
//#include <windows.h>
////VS2013 WIN10��������
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//�Ƚ�����������������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
//	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	fclose(pf);
//	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
//	pf = NULL;
//	return 0;
//}
//������Եó�һ�����ۣ���Ϊ�л������Ĵ��ڣ�C�����ڲ����ļ���ʱ����Ҫ��ˢ�»������������ļ�����������ʱ��ر��ļ���
//������������ܵ��¶�д�ļ������⡣

//5���ļ�ָ��
//�����ļ�ϵͳ�У��ؼ��ĸ����ǡ��ļ�����ָ�롱����ơ��ļ�ָ�롱��
//ÿ����ʹ�õ��ļ������ڴ��п�����һ����Ӧ���ļ���Ϣ������������ļ��������Ϣ�����ļ������֣��ļ�״̬���ļ���ǰ��λ�õȣ���
//��Щ��Ϣ�Ǳ�����һ���ṹ������еġ��ýṹ����������ϵͳ�����ģ�ȡ��FILE.
//���磬VS2013���뻷���ṩ�� stdio.h ͷ�ļ��������µ��ļ���������������FILE��ת�����壬�ɲ鿴FILE�ṹ��������Ϣ
//��ͬ��C��������FILE���Ͱ��������ݲ���ȫ��ͬ�����Ǵ�ͬС�졣
//ÿ����һ���ļ���ʱ��ϵͳ������ļ�������Զ�����һ��FILE�ṹ�ı�������������е���Ϣ��ʹ���߲��ع���ϸ�ڡ�
//һ�㶼��ͨ��һ��FILE��ָ����ά�����FILE�ṹ�ı���������ʹ���������ӷ��㡣

//�������ǿ��Դ���һ��FILE*��ָ�����:FILE* pf;//�ļ�ָ�����
//����pf��һ��ָ��FILE�������ݵ�ָ�����������ʹpfָ��ĳ���ļ����ļ���Ϣ������һ���ṹ���������
//ͨ�����ļ���Ϣ���е���Ϣ���ܹ����ʸ��ļ���Ҳ����˵��ͨ���ļ�ָ������ܹ��ҵ������������ļ���

//6. �ļ��Ĵ򿪺͹ر�
//�ļ��ڶ�д֮ǰӦ���ȴ��ļ�����ʹ�ý���֮��Ӧ�ùر��ļ���
//�ڱ�д�����ʱ���ڴ��ļ���ͬʱ�����᷵��һ��FILE* ��ָ�����ָ����ļ���Ҳ�൱�ڽ�����ָ����ļ��Ĺ�ϵ��
//ANSIC �涨ʹ��fopen���������ļ���fclose���ر��ļ���
//���ļ�
//FILE* fopen(const char* filename, const char* mode);
//�򿪳ɹ��������ļ���Ӧ��ָ�룬���򷵻�NULL
//�ر��ļ�
//int fclose(FILE* stream);
//�򿪷�ʽ���£�
//�ļ�ʹ�÷�ʽ      ����                                           ���ָ���ļ�������
//��r����ֻ����     Ϊ���������ݣ���һ���Ѿ����ڵ��ı��ļ�       ����
//��w����ֻд��     Ϊ��������ݣ���һ���ı��ļ�                 ����һ���µ��ļ�
//��a����׷�ӣ�     ���ı��ļ�β�������                           ����һ���µ��ļ�
//��rb����ֻ����    Ϊ���������ݣ���һ���������ļ�               ����
//��wb����ֻд��    Ϊ��������ݣ���һ���������ļ�               ����һ���µ��ļ�
//��ab����׷�ӣ�    ��һ���������ļ�β�������                     ����
//��r + ������д��  Ϊ�˶���д����һ���ı��ļ�                   ����
//��w + ������д��  Ϊ�˶���д������һ���µ��ļ�                   ����һ���µ��ļ�
//��a + ������д��  ��һ���ļ������ļ�β���ж�д                 ����һ���µ��ļ�
//��rb + ������д�� Ϊ�˶���д��һ���������ļ�                   ����
//��wb + ������д�� Ϊ�˶���д���½�һ���µĶ������ļ�             ����һ���µ��ļ�
//��ab + ������д�� ��һ���������ļ������ļ�β���ж���д         ����һ���µ��ļ�

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pFile;
//    //���·��
//    //..��ʾ��һ��·��
//    //.��ʾ��ǰ·��
//    //��ǰ·������һ������һ��·��
//    //../..
//    
//    //���ļ�
//    pFile = fopen("myfile.txt", "r");//�򿪵�ǰ·���µ��ļ� - ���·��
//    //pFile = fopen("D:\\VS2019\\code\\text\\myfile.txt", "w");//����·��
//    //�ļ�����
//    if (pFile == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //�ر��ļ�
//    fclose(pFile);//���ṹ���ļ���Ϣ������Դ�ͷŵ�������ָ�뻹�ڣ���Ҫ�ͷ�
//    pFile = NULL;
//    return 0;
//}
//ע�⣺fopen("myfile.txt", "w");
//��myfile.txt������Ϣ���Ὣ����Ϣ���ٵ�

//7. �ļ���˳���д�����MSDN��
//����           ������       ������
//�ַ����뺯��   fgetc        ����������    - д��һ���ַ�
//�ַ��������   fputc        ���������    - ��ȡһ���ַ�  
//�ı������뺯�� fgets        ����������    - д��һ���ַ�
//�ı���������� fputs        ���������    - ��ȡһ���ַ�
//��ʽ�����뺯�� fscanf       ����������    - ��ʽ����ʽд���ַ�
//��ʽ��������� fprintf      ���������    - ��ʽ����ʽ��ȡ�ַ�
//����������     fread        �ļ�
//���������     fwrite       �ļ�
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pfWrite;
//    pfWrite = fopen("myfile.txt", "w");//pfWrite��ָ����ļ���д�ķ�ʽ�򿪣����ļ������
//    if (pfWrite == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //д�ļ�
//    fputc('b', pfWrite);
//    fputc('i', pfWrite);
//    fputc('t', pfWrite);
//    //�ر��ļ�
//    fclose(pfWrite);
//    pfWrite = NULL;
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pfRead;
//    pfRead = fopen("myfile.txt", "r");//pfWrite��ָ����ļ��Զ��ķ�ʽ�򿪣����ļ�������
//    if (pfRead == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //���ļ�
//    printf("%c", fgetc(pfRead));//fgetc����һ��ASCII��ֵ
//    printf("%c", fgetc(pfRead));
//    printf("%c", fgetc(pfRead));
//    //�ر��ļ�
//    fclose(pfRead);//���ṹ���ļ���Ϣ������Դ�ͷŵ�������ָ�뻹�ڣ���Ҫ�ͷ�
//    pfRead = NULL;
//    return 0;
//}

//�Ӽ�������
//�������Ļ
//���̺���Ļ�����ⲿ�豸
//���� - �Ǳ�׼�����豸 - stdin(����ΪFile*)
//��Ļ - �Ǳ�׼����豸 - stdout(����ΪFile*)
//��һ������Ĭ�ϴ򿪵��������豸
//�������ļ��������豸����Ҫ��׼�豸Ĭ�ϲ���Ҫ�򿪺͹ر�
//#include <stdio.h>
//int main()
//{
//	//fgetc��fputc��������������������
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    char buf[1024] = { 0 };
//    FILE* pf;
//    pf = fopen("myfile.txt", "r");//�ļ���д��bit����hello
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //���ļ�
//    //fgets(buf, 1024, pf);//��pf��ָ����ļ��ж�ȡ���1024���ַ�,����buf��
//    //printf("%s", buf);//����bit���У����\nҲ����buf�У��ʽ���ỻ��
//    //fgets(buf, 1024, pf);
//    //printf("%s", buf);//����hello��û�л��У��ʽ�����ỻ��
//    fgets(buf, 1024, pf);
//    puts(buf);//���ַ�����һ�У��������Ļ�ϣ�������
//    fgets(buf, 1024, pf);
//    puts(buf);
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    char buf[1024] = { 0 };
//    FILE* pf;
//    pf = fopen("myfile.txt", "w");//д��bit����hello
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //д�ļ�
//    fputs("hello", pf);
//    fputs("world", pf);
//    fputs("hello\n", pf);
//    fputs("world", pf);
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    //�Ӽ��̶�ȡһ���ı���Ϣ
//    char buf[1024] = { 0 };
//    fgets(buf, 1024, stdin);//�ӱ�׼�����ȡ
//    fputs(buf, stdout);//�������׼���
//    //�ȼ�����
//    gets(buf);
//    puts(buf);
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//struct S
//{
//    int n;
//    float score;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 100,2.14f,"bit" };
//    FILE* pf = fopen("test.txt", "w");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //��ʽ������ʽд�ļ�
//    fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//struct S
//{
//    int n;
//    float score;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 0 };
//    FILE* pf = fopen("test.txt", "r");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //��ʽ������ʽ������
//    fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//    printf("%d %f %s", s.n, s.score, s.arr);
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//struct S
//{
//    int n;
//    float score;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 0 };
//    fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//    fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
//    return 0;
//}

//�Ա�һ�麯����
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
//scanf / fscanf����printf / fprintf����ֻ��һ��ָ���ļ�����
//fscanf��fprintf�ȿ������ڱ�׼����������ĸ�ʽ�����������䣬Ҳ���������ļ�����ʽ��������������
//scanf��printfֻ�����ڱ�׼����������ĸ�ʽ������������
//sscanf���ַ����ж�ȡ��ʽ��������ת���ɽṹ���Ա��Ϣ
//sprintf�Ѹ�ʽ�������ݴ洢���ַ���

//#include <stdio.h>
//struct S
//{
//    int n;
//    float score;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 100,3.14f,"abcdef" };
//    struct S tmp = { 0 };
//    char buf[1024] = { 0 };
//    //�Ѹ�ʽ��������ת�����ַ����洢��buf��
//    sprintf(buf, "%d %.2f %s", s.n, s.score, s.arr);
//    printf("%s\n", buf);
//    //��buf�ж�ȡ��ʽ�������ݵ��ṹ��tmp��
//    sscanf(buf, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//    printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//    return 0;
//}

//#include <stdio.h>
//struct S
//{
//    char name[20];
//    int age;
//    double score;
//};
//int main()
//{
//    struct S s = { "����",20,55.6 };
//    FILE* pf = fopen("test.txt", "wb");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //�����Ƶ���ʽд�ļ�
//    fwrite(&s, sizeof(struct S), 1, pf);//��1��sizeof(struct S)��С�Ķ���s����Ϣд�뵽pf��
//    fclose(pf);
//    pf = NULL;
//    //�����һ�����飬�Ϳ���д������Ϣ
//    return 0;
//}

//#include <stdio.h>
//struct S
//{
//    char name[20];
//    int age;
//    double score;
//};
//int main()
//{
//    struct S s = { 0 };
//    FILE* pf = fopen("test.txt", "rb");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //���ļ��ж�ȡ��Ϣ
//    fread(&s, sizeof(struct S), 1, pf);//��1��sizeof(struct S)��С�Ķ���s����Ϣ��pf��ָ����ļ��ж���
//    //��Ȼ�Զ�������ʽд�뿴���������ǿ��Դ��ļ����Զ�������ʽ����
//    printf("%s %d %lf\n", s.name, s.age, s.score);
//    fclose(pf);
//    pf = NULL;
//    //�����һ�����飬�Ϳ��Զ�ȡ�����Ϣ
//    return 0;
//}

//8. �ļ��������д
//1 fseek:int fseek(FILE * stream, long int offset, int origin);
//���ݵ�ǰ�ļ�ָ��stream��λ��origin��ƫ����offset����λ�ļ�ָ�롣
//origin��SEEK_CUR�ļ�ָ��ĵ�ǰλ�á� SEEK_END�ļ�ָ���ĩβλ�á�SEEK_SET�ļ�ָ�����ʼλ�ã�Ĭ�ϣ�
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //1����λ�ļ�ָ��
//    fseek(pf, 4, SEEK_CUR);
//    //2����ȡ�ļ�
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//e
//
//    fseek(pf, -2, SEEK_END);//��������Ϊ2
//    //2����ȡ�ļ�
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//e
//
//    fclose(pf);
//    pf = NULL;
//    //�����һ�����飬�Ϳ��Զ�ȡ�����Ϣ
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}

//2 ftell:long int ftell(FILE* stream);
//����ֵ�������ļ�ָ���������ʼλ�õ�ƫ����
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    fseek(pf, -2, SEEK_END);
//    int pos = ftell(pf);
//    printf("%d\n", pos);//4
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    int pos = ftell(pf);
//    printf("%d\n", pos);//0
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //��ȡ�ļ�
//    int ch = fgetc(pf);
//    int pos = ftell(pf);//1
//    printf("%d\n", pos);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    FILE* pFile;
//    long size;
//    pFile = fopen("myfile.txt", "rb");
//    if (pFile == NULL) 
//        perror("Error opening file");
//    else
//    {
//        fseek(pFile, 0, SEEK_END);   // non-portable
//        size = ftell(pFile);
//        fclose(pFile);
//        printf("Size of myfile.txt: %ld bytes.\n", size);
//    }
//    return 0;
//}

//3 rewind��void rewind(FILE * stream);
//���ļ�ָ���λ�ûص��ļ�����ʼλ��
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //��ȡ�ļ�
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//a����ʱָ��ָ���b
//    rewind(pf);
//    ch = fgetc(pf);
//    printf("%c\n", ch);//a
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n;
//    FILE* pFile;
//    char buffer[27];
//    pFile = fopen("myfile.txt", "w+");
//    for (n = 'A'; n <= 'Z'; n++)
//        fputc(n, pFile);
//    rewind(pFile);
//    fread(buffer, 1, 26, pFile);
//    fclose(pFile);
//    buffer[26] = '\0';
//    puts(buffer);
//    return 0;
//}

//9. �ļ���ȡ�������ж�
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt��û������
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //��ȡ�ļ�
//    int ch = fgetc(pf);
//    printf("%d\n", ch);//-1
//    
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//������ʹ�õ�feof��
//�μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ����Ƿ������
//����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܶ����������������ļ�βEOF��������
//��feof�������ж��ļ��Ƿ��Ƕ�ȡEOF���������
//feof��û�ж����ʱ�򣬷���0���ڶ����ʱ�򷵻�-1��Ҳ���Ƿ���EOF��
//1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF��ʹ��fgetc��ȡ�ַ�������EOF��-1��������NULL��fgets��ȡ�ַ���������NULL��
//���磺
//fgetc �ж��Ƿ�Ϊ EOF .
//fgets �жϷ���ֵ�Ƿ�Ϊ NULL .
//2. �������ļ��Ķ�ȡ�������жϣ�fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//���磺
//fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    //strerror(errno):���ش������Ӧ�Ĵ�����Ϣ���ַ�����ַ����
//    printf("%s\n", strerror(errno));
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test2.txt", "r");
//    if (pf == NULL)
//    {
//        perror("open file test2.txt");//perrorʹ�ô�����Ϣ��������
//        return 0;
//    }
//    //...
//    fclose(pf);
//    pf = NULL;
//}

//��ȷ��ʹ�ã�
//�ı��ļ������ӣ�
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test2.txt", "r");
//    if (pf == NULL)
//    {
//        perror("open file test2.txt");//perrorʹ�ô�����Ϣ��������
//        return 0;
//    }
//    //...
//    int ch = 0;
//    while ((ch = fgetc(pf) != EOF))//EOF=-1��ת������
//    {
//        putchar(ch);//�ع�putc������ʹ��
//    }
//    if (ferror(pf))
//        printf("error\n");
//    else if (feof(pf))
//        printf("end of file\n");
//    fclose(pf);
//    pf = NULL;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//    //�����Ķ��������ǰ��Ϻã���Ϊ�в��ֱ�������֧�ֱ߶����ʹ��
//    int c; // ע�⣺int����char��Ҫ����EOF
//    FILE* fp = fopen("test.txt", "r");//test.txt�к���abcdef�ı�
//    if (!fp) //fpΪNULLʱ������
//    {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//    {
//        putchar(c);
//    }
//    //�ж���ʲôԭ�������
//    if (ferror(fp))
//        puts("I/O error when reading");
//    else if (feof(fp))
//        puts("End of file reached successfully");
//    fclose(fp);
//    fp = NULL;
//}

//�������ļ������ӣ�
//#include <stdio.h>
//enum { SIZE = 5 };
//int main(void)
//{
//    double a[SIZE] = { 1.,2.,3.,4.,5. };
//    FILE* fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
//    fwrite(a, sizeof * a, SIZE, fp); // д double ������
//    fclose(fp);
//    double b[SIZE];
//    fp = fopen("test.bin", "rb");
//    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // �� double ������
//    if (ret_code == SIZE) {
//        puts("Array read successfully, contents: ");
//        for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
//        putchar('\n');
//    }
//    else { // error handling
//        if (feof(fp))
//            printf("Error reading test.bin: unexpected end of file\n");
//        else if (ferror(fp)) {
//            perror("Error reading test.bin");
//        }
//    }
//    fclose(fp);
//}