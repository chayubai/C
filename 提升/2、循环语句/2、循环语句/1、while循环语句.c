#define _CRT_SECURE_NO_WARNINGS 1

//ѭ���ṹ--ѭ�����while/for/do-while
//whileѭ��
//if (1)//������ִֻ��һ��	while (1)//ִ�������Σ���ѭ����
//{								{
//	��䣻 == = >					��䣻
//}	
//								}

//while�﷨�ṹ��
//while (���ʽ)
//{
//	ѭ����䣻
//}
//�����ʽΪ��ʱ��ִ��ѭ�����
// { }�����ͬif��ͬ����whileû��{ }ʱ��ֻ����һ�д���

//��ӡ1-10
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
//���Թ۲�i�ı仯

//break��continue��ѭ������е����ã�
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);
//		i++;
//	}
// //����ѭ�������������һ��breakֻ�������Լ���ѭ��
//	return 0;
//}
//��ȷ�����1 2 3 4
//ͨ�����Թ۲��֪����while�У�i== 5ʱ����break��break���������Ҳ��ִ�У�ֱ������ѭ����������ֹѭ��
//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}
//��ȷ�����1 2 3 4 ������ѭ��
//ԭ����������Թ۲��֪����i == 5ʱ������continue���������κ������䣬����������printf("%d ",i)��i++;��������һ��ѭ������ʱiһֱ����5
//��whileѭ���У�continue������ʱ��������ѭ��continue��ߵĴ��룬ֱ��ȥ�жϲ��֣����Ƿ������һ��ѭ��
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		
//	}
//	return 0;
//}
//��ȷ���Ϊ��1 2 3 4 6 7 8 9 10
//�ܽ�break��whileѭ���е����ã���ʵ��ѭ����ֻҪ����break����ֹͣ���ڵ�����ѭ����ֱ����ֹѭ�������ԣ�while�е�break������������ֹѭ����
//�ܽ�continue��whileѭ���е����ã�continue��������ֹ����ѭ���ģ�Ҳ���Ǳ���ѭ���е�continue����Ĵ��벻����ִ��
//����ֱ����ת��while�����жϲ��֣�������һ��ѭ��������ж�

//��չ��
//#include <stdio.h>
//int main()
//{
//	int ch = getchar();//getchar����һ�����̵��ַ�
//	putchar(ch);//���һ���ַ��������ỻ�С������ַ�����ֻ��ӡһ���ַ�
//	printf("%c\n", ch);//ͬputchar
//	return 0;//
//}
//��MSDN����--win32 API:Platform SDK������getchar/putchar
// getc,getwc,getchar,getwchar��������:Read a character from a stream(getc,getwc),or get a character from stdin(getchar,getwchar)
// ��һ��stream��������stdin����׼���룬�磺���̣��л�ȡһ���ַ�
// int getchar(void);����ֵ����Ϊint�����ö���int ch����getchar�ķ���ֵ
// Required Headerͷ�ļ���<stdio.h>
// Return Value����ֵ��Each of these functions returns the character read.To indicate an read error or end-of-file condition,
// getc and getchar return EOF,and getc and getwchar return WEOF.For getc and getchar,use ferror of feof to check for an error or for end of file.
// getchar���ͣ�������һ�����뻺������������������뻺��������Ϊ�գ�����ȴ����룬������һ���ַ�A�ְ���һ���س������൱�ڰ�A\n�����˻������У�getchar��ȡA��ӡ�󣬼�����\n��ӡ���У������س�����Ҳ���ַ���getcharҲ���ȡ
//�磺
//#include <stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	printf("���������룺>");
//	scanf("%s", password);//����123456--�ַ���"123456"
//	printf("��ȷ�����루Y/N��:>");
//	int ch = getchar();//���Թ۲�ch��֪��ch��ŵ�ֵΪ10����'\n'��ASCII��ֵ
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}
//����123456���س���ʾ�������ȷ�ϣ�Y/N��:>ȷ��ʧ��
//����ԭ�����飺�������һ����ַ������Ҫ��&ȡ��ַ������������123456ʱ���������൱��123456\n��
// ��ʱ��һ��sacnf��123456����password�У�getcharû�еȴ���ֱ����\n��������Y�������ȷ��ʧ�ܡ�
//#include <stdio.h>
//int main()
//{
//	printf("%d",'\n');
//	return 0;
//}//���Ϊ��10˵����\n����ASCII��ֵ��10
// scanf��getchar���뺯�����ͣ�������һ�����뻺������������������뻺��������Ϊ�գ�����ȴ����룬
// ������һ���ַ���123456�ְ���һ���س������൱�ڰ�123456\n�����˻������У�sacnf��ȡ123456��ӡ��getchar������\n��ӡ���У�
// �����س�����Ҳ���ַ���getcharҲ���ȡ
//��ʱY/N�����ȴ����ж�'\n'��'Y'�Ƿ���ȣ���������ȷ��ʧ��
//getchar��putchar�����������������Ҫ��stdio.h

//�������´��룺
//����1��
//#include <stdio.h>
//int main()
//{
//	int ch = 0;
// //EOF--enf of file �ļ�������־
//	while ((ch = getchar()) != EOF)//��������ȼ�
// //VS2019�༭��������EOF��ѡ����һ���꣬����ת�����壬�鿴EOFֵΪ - 1
//		putchar(ch);
//	return 0;
//}
// �����ʵ�����ã���������һ���ַ�--�൱�ڿ��������ַ���,������EOF��Ҳ�Ǵ�ӡEOF
// ��Ҫ�����������CTRL+Z���൱��getchar��ȡ����һ��EOF
//�������룬ȷ������

//ʵ�����壺�������ϴ�����޸ģ�
//#include <stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	printf("���������룺>");
//	scanf("%s", password);//����123456--�ַ���"123456"
//	//������ʣ��һ��'\n'
//	//��ȡһ��'\n'
//	getchar();//���������е�һ���ַ�������'\n'
//	printf("��ȷ�����루Y/N��:>");
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	printf("���������룺>");
//	scanf("%s", password);//����123456 ABCD\n
//	//������ʣ��һ��'\n'
//	//��ȡһ��'\n'
//	//��ջ������ж���ַ�
//	int temp = 0;
//	while ((temp = getchar()) != '\n')//ѭ����ȡ�ַ�
//	{
//		;//�����
//	}
//	printf("��ȷ�����루Y/N��:>");
//	int ch = getchar();//����һ��A
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");//���ճ�����������
//	}
//	return 0;
//}
//����2��
//ֻ��ӡ0-9�е�һ��
//#include <stdio.h>
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')//ASCII��ֵ48��'0'��-57��'9'�������ֵ�����
//			continue;
//		putchar(ch);
//	}	
//	return 0;
//}
//���ϴ���ֻ���ӡ�����ַ�
