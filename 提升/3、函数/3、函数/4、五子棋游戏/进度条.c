#define _CRT_SECURE_NO_WARNINGS 1
//������
//ԭ������ʾ#���ڰѹ��ص��ʼ�������#���ٹ��ص��ʼ���������ϴ�ӡ�����ϻس������и��ǣ���������
//�����ת����ͬһ��λ�ã���ͬ��̬�ĸ�������:[ | ][ / ][ - ][ \ ]

#include <stdio.h>
#include <string.h>
#include <windows.h>
void process_bar()
{
	char bar[101];//������101��Ϊ�˴�ӡ��0-100��ʾ���±����Ϊ0-100
	memset(bar, '\0', sizeof(bar));
	const char* lable = "|/-\\";//ע�⣺�����ѡ�\\������һ���ַ�
	
	int i = 0;
	while (i <= 100)
	{
		//[                 ###############][53%]
		//printf("[%100s]\r", bar);//������������ҪԤ���ռ�ģ�%100s��Ĭ��100��λ�������ǰ�油�ո�
		//[###############                 ][53%]
		printf("[%-100s][%-3d%%][%c]\r", bar, i, lable[i % 4]); // ���︲�ǣ���ʹ��%-100s����ʾ��������룬����λ���ұ߲��ո�
		fflush(stdout);//����ˢ�»�����
		bar[i] = '#';//��������
		i++;
		Sleep(1);//��λ��
	}
	printf("\n");//���û����һ�У�������##############################][100%]
	//��һ�е�Ŀ���ǣ��س���������ʾ
}
int main()
{
	process_bar();
	return 0;
}


//����ʱ
//#include <stdio.h>
//#include <windows.h>
//void process_bar()
//{
//	int i = 10;
//	while (i >= 0)
//	{
//		printf("%d\r", i);
//		fflush(stdout);
//		i--;
//		Sleep(1);//��λ��
//	}
//	printf("hello Makefile!");
//	fflush(stdout);
//	Sleep(1);
//}
//int main()
//{
//	process_bar();
//	return 0;
//}