#define _CRT_SECURE_NO_WARNINGS 1
//���򻷾���Ԥ����
//C����(ASCII�룬�ı��ļ�)       ����     ����          �����Ƶ���Ϣ(�������ļ�)           ����
//test.cԴ�ļ�(Դ����)      ------------------------->            test.exe        ---------------------->
//                           ���뻷��������������������                                   ���л���
//test.c                           test.obj/test.o                    a.out
//add.c                            add.obj��LinuxĿ���ļ�Ĭ��Ϊadd.o��a.out��Linux��ִ���ļ�Ĭ��Ϊa.out��                              
//            ����     ------   Ŀ���ļ�  -------   ����  ------ ��ִ���ļ�
//      Ԥ����  ����  ���   
//Ԥ�������(�ı�����)��ͷ�ļ��İ����Ĵ���#define��ע��ɾ����ʹ�ÿո��滻ע��...     
//Linux  gcc -E test.c��test.c����Ԥ����/Ԥ����
//gcc -E test.c > test.i��Ԥ�����������Ϣ�����test.i��
//������̣��﷨�������ʷ�������������������Ż���
//Linux  gcc -S test.i��test.i���б��룬����test.s�Ļ����롣����C���Դ��뷭��ɻ�����
//����ԭ�� - ������Ա������������
//�����̣��γɷ��ű���������ת���ɶ�����ָ��
//Linux  gcc -c test.s��test.s���б��룬����test.o�Ķ����ƴ���(��obj��Ŀ���ļ�)
//���ӹ��̣��ϲ��α����ű�ĺϲ����ض�λ

//1������ķ��뻷��
//��ANSI C���κ�һ��ʵ���У�����������ͬ�Ļ�����
//��1���Ƿ��뻷���������������Դ���뱻ת��Ϊ��ִ�еĻ���ָ�
//��2����ִ�л�����������ʵ��ִ�д��롣

//2����⣺C���Գ���ı��� + ����
//���뻷��
//���һ�������ÿ��Դ�ļ�ͨ��������̷ֱ�ת����Ŀ����루object code����
//ÿ��Ŀ���ļ�����������linker��������һ���γ�һ����һ�������Ŀ�ִ�г���
//������ͬʱҲ�������׼C���������κα��ó������õ��ĺ�����������������������Ա���˵ĳ���⣬
//������Ҫ�ĺ���Ҳ���ӵ������С�
//�磺
//����test.c�ļ���д�����´���
//#include <stdio.h>
//int main()
//{
//	extern int Add(int x, int y);
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
////����add.c�ļ���д�����´���
//int Add(int x, int y)
//{
//	return  x + y;
//}

//sum.c
//int g_val = 2016;
//void print(const char* str)
//{
//	printf("%s\n", str);
//}
////test.c
//#include <stdio.h>
//int main()
//{
//	extern void print(char* str);
//	extern int g_val;
//	printf("%d\n", g_val);
//	print("hello bit.\n");
//	return 0;
//}

//���뱾��Ҳ��Ϊ�����׶�
//1. Ԥ���� ѡ�� gcc -E test.c -o test.i
//Ԥ�������֮���ͣ������Ԥ����֮������Ľ��������test.i�ļ��С�
//2. ���� ѡ�� gcc - S test.c
//�������֮���ͣ���������������test.s�С�
//3. ��� gcc - c test.c
//������֮���ͣ���������������test.o�С�

//���л���
//����ִ�еĹ��̣�
//1. ������������ڴ��С����в���ϵͳ�Ļ����У�һ������ɲ���ϵͳ��ɡ��ڶ����Ļ����У�
//���������������ֹ����ţ�Ҳ������ͨ����ִ�д�������ֻ���ڴ�����ɡ�
//2. �����ִ�б㿪ʼ�����ű����main������
//3. ��ʼִ�г�����롣���ʱ�����ʹ��һ������ʱ��ջ��stack�����洢�����ľֲ������ͷ��ص�ַ��
//����ͬʱҲ����ʹ�þ�̬��static���ڴ棬�洢�ھ�̬�ڴ��еı����ڳ��������ִ�й���һֱ�������ǵ�ֵ��
//4. ��ֹ����������ֹmain������Ҳ�п�����������ֹ��
//ע������һ���顶����Ա������������

//Ԥ�������
//Ԥ�������
//__FILE__      //���б����Դ�ļ�
//__LINE__     //�ļ���ǰ���к�
//__DATE__    //�ļ������������
//__TIME__    //�ļ��������ʱ��
//__STDC__    //�����������ѭANSI C����ֵΪ1(gcc)������δ����(VS)
//��ЩԤ������Ŷ����������õġ�
//#include <stdio.h>
//int main()
//{
//	printf("%s\n", __FILE__);//Դ�ļ��ľ���·��
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//  printf("%s\n", __FUNCTION__);//��ȡ������
//	return 0;
//}

//д��־�ļ�
//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("log.txt", "w");
//	int arr[10] = { 0 };
//    int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d date:%s time:%s i=%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//Ԥ����׶��꽲��Ԥ����ָ�����
//3��Ԥ����ָ�� #define
//#define
//#include
//#pragma
//#if
//#endif
//#ifdef    
//...

//#define �����ʶ��
//�﷨��
//#define name stuff
//�磺
//#include <stdio.h>
//#define MAX 100
//#define STR "hehe"
//#define reg register          //Ϊ register����ؼ��֣�����һ����̵�����
//#define do_forever for(;;)    //�ø�����ķ������滻һ��ʵ��
//#define CASE break;case       //��дcase����ʱ���Զ��� breakд�ϡ�
//// �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
//#define DEBUG_PRINT printf("file:%s\tline:%d\t\date:%s\ttime:%s\n",\__FILE__,__LINE__ ,__DATE__,__TIME__ )  
//
//int main()
//{
//    register int a;
//    reg int b;
//    printf("%s\n", STR);
//    do_forever;//�൱��for (;;);
//    //for(;;)��д�ֺţ�ѭ���������Ϊreturn 0;
//    return 0;
//}

//���ʣ���define�����ʶ����ʱ��Ҫ��Ҫ��������; ?
//#include <stdio.h>
//#define A 100
//#define MAX 100;
//int main()
//{
//    int a = A;//Ԥ����ʱ�ὫA�滻Ϊ100
//    int b = MAX;//Ԥ����ʱ�ὫMAX�滻Ϊ100;
//    //��int b = MAX;;
//    //printf("%d\n", MAX);//��ʱ�ͻᱨ��
//    if(1)
//      max = MAX;//�����滻Ϊ��100;���麬������䣬���ô�����
//    else
//      max = 0;
//    return 0;
//}
//���鲻Ҫ���� ; ,�������׵������⡣

//#define �����
//#define ���ư�����һ���涨������Ѳ����滻���ı��У�����ʵ��ͨ����Ϊ�꣨macro������꣨define macro����
//�����Ǻ��������ʽ��
//#define name( parament-list ) stuff
//���е� parament - list ��һ���ɶ��Ÿ����ķ��ű����ǿ��ܳ�����stuff�С�
//ע�⣺
//�����б�������ű�����name���ڡ�
//�������֮�����κοհ״��ڣ������б�ͻᱻ����Ϊstuff��һ���֡�
//�磺
//#define SQUARE(x) x * x
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5);
//    //����int ret = 5*5;
//    printf("%d\n", ret);//25
//    return 0;
//}

//�����滻���Ǵ���
//#define SQUARE(x) x * x
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5+1);
//    //����int ret = 5+1*5+1;
//    printf("%d\n", ret);//11
//    return 0;
//}
//����
//#define SQUARE(x) (x) * (x)
//#include <stdio.h>
//int main()
//{
//    int ret = SQUARE(5 + 1);
//    //����int ret = (5+1)*(5+1);
//    printf("%d\n", ret);//36
//    return 0;
//}

//��Ҫ��������
//#define DOUBLE(x) x + x
//#include <stdio.h>
//int main()
//{
//    int a = 5;
//    int ret = 10 * DOUBLE(a);
//    //����int ret = 10 * a+a;
//    printf("%d\n", ret);//55
//    return 0;
//}
//#define DOUBLE(x) ((x) + (x))
//#include <stdio.h>
//int main()
//{
//    int a = 5;
//    int ret = 10 * DOUBLE(a);
//    //����int ret = 10 * ((a)+(a));
//    printf("%d\n", ret);//100
//    return 0;
//}

//#define �滻����
//�ڳ�������չ#define������źͺ�ʱ����Ҫ�漰�������衣
//1. �ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ�����κ���#define����ķ��š�����ǣ��������ȱ��滻��
//2. �滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ�滻��
//3. ����ٴζԽ���ļ�����ɨ�裬�������Ƿ�����κ���#define����ķ��š�����ǣ����ظ�����������̡�
//ע�⣺
//1. �������#define �����п��Գ�������#define����ı��������Ƕ��ں꣬���ܳ��ֵݹ顣
//2. ��Ԥ����������#define����ķ��ŵ�ʱ���ַ������������ݲ�����������
//#include <stdio.h>
//void Print(int x)
//{
//	printf("the value of a is %d\n", x);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Print(a);
//	Print(b);
//	return 0;
//}

//#include <stdio.h>
//#define PRINT(x) printf("the value of x is %d\n", x)
//int main()
//{
//	printf("hello world\n");
//	printf("hello " "world\n");
//	printf("hel" "lo" " world\n");
//
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}
//3��Ԥ���������#��##�Ľ���
//��ΰѲ������뵽�ַ����У�
//#������
//#include <stdio.h>
//#define PRINT(x) printf("the value of "#x" is %d\n", x)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	//��printf("the value of ""a"" is %d\n",a);
//	PRINT(b);
//	//��printf("the value of ""b"" is %d\n",b);
//
//	return 0;
//}

//## ������
//##���԰�λ�������ߵķ��źϳ�һ�����š�������궨��ӷ�����ı�Ƭ�δ�����ʶ����#include <stdio.h>
//#include <stdio.h>
//#define CAT(X, Y) X##Y
//int main()
//{
//	int Class84 = 2019;
//	printf("%d\n", Class84);
//	printf("%d\n", CAT(Class, 84));
//	//��printf("%d\n", Class##84);
//	//printf("%d\n", Class84);
//
//	return 0;
//}
//ע�����������ӱ������һ���Ϸ��ı�ʶ����������������δ����ġ�

//�������õĺ����
//��������ں�Ķ����г��ֳ���һ�ε�ʱ������������и����ã���ô����ʹ��������ʱ��Ϳ��ܳ���Σ�գ�
//���²���Ԥ��ĺ���������þ��Ǳ��ʽ��ֵ��ʱ����ֵ�������Ч����
//x+1;//����������
//x++;//���и�����
//#include <stdio.h>
//#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	//��int max = ((a++)>(b++)?(a++):(b++))
//	//           a = 10   b = 11      b = 13     
//	printf("%d\n", max);//12
//	printf("%d\n", a);//11
//	printf("%d\n", b);//13
//
//	return 0;
//}

//4����ͺ����ĶԱ�
//��ͨ����Ӧ����ִ�м򵥵����㡣���������������ҳ��ϴ��һ����#define MAX(a, b) ((a) > (b) ? (a) : (b))
//��Ϊʲô���ú���������������
//ԭ���ж���
//1. ���ڵ��ú����ʹӺ������صĴ�����ܱ�ʵ��ִ�����С�ͼ��㹤������Ҫ��ʱ����ࡣ���Ժ��
//�����ڳ���Ĺ�ģ���ٶȷ����ʤһ�
//2. ��Ϊ��Ҫ���Ǻ����Ĳ�����������Ϊ�ض������͡����Ժ���ֻ�������ͺ��ʵı��ʽ��ʹ�á���֮
//��������������������Ρ������͡������͵ȿ������� > ���Ƚϵ����͡����������޹صġ�
//#include <stdio.h>
////����-1
//int Max1(int x, int y)
//{
//	return (x > y ? x : y);
//}
////����-2
//float Max2(float x, float y)
//{
//	return (x > y ? x : y);
//}
////��
//#define MAX(a, b) ((a) > (b) ? (a) : (b))
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 2.0f;
//	float d = 3.0f;
//
//  //�����ڵ��õ�ʱ�򣬻��к������úͷ��صĿ���
//	int max = Max1(a, b);
//	printf("max = %d\n", max);
//	max = MAX(a, b);
//	printf("max = %d\n", max);
//
//	max = Max2(c, d);
//	printf("max = %d\n", max);
//	max = MAX(c, d);
//	printf("max = %d\n", max);
//	
//	return 0;
//}

//��Ȼ�ͺ���Ⱥ���Ҳ�����Ƶĵط���
//1. ÿ��ʹ�ú��ʱ��һ�ݺ궨��Ĵ��뽫���뵽�����С����Ǻ�Ƚ϶̣�������ܴ�������ӳ���ĳ��ȡ�
//2. ����û�����Եġ�
//3. �����������޹أ�Ҳ�Ͳ����Ͻ���
//4. ����ܻ������������ȼ������⣬���³����׳��ִ�
//����ʱ����������������������顣���磺��Ĳ������Գ������ͣ����Ǻ�����������
//#include <stdio.h>
//#define SIZEOF(type) sizeof(type) 
//int main()
//{
//	int ret = SIZEOF(int);
//	return 0;
//}

//#include <stdio.h>
//#define MALLOC(num, type) (type *)malloc(num * sizeof(type))
//int main()
//{
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	
//	int* p2 = MALLOC(10, int);//������Ϊ����
//	//Ԥ�������滻֮��int* p2 = (int*)malloc(10 * sizeof(int));
//	return 0;
//}

//��ͺ�����һ���Ա�:
//��
//��          #define�����                                            ����
//
//��
//��			ÿ��ʹ��ʱ������붼�ᱻ���뵽�����С����˷ǳ�           ��������ֻ������һ���ط���ÿ��ʹ���������ʱ��
//��			С�ĺ�֮�⣬����ĳ��Ȼ���������						 �������Ǹ��ط���ͬһ�ݴ���
//��        
//                        
//ִ
//��			����													 ���ں����ĵ��úͷ��صĶ��⿪
//��																	 �������������һЩ
//��
// 
//��
//��			���������ֵ����������Χ���ʽ�������Ļ����           ��������ֻ�ں������õ�ʱ����
//��			���Ǽ������ţ������ڽ������������ȼ����ܻ����			 ֵһ�Σ����Ľ��ֵ���ݸ���
//��			����Ԥ�ϵĺ�������Խ��������д��ʱ���Щ���š�         �������ʽ����ֵ���������Ԥ�⡣
//��
//��
//
//��
//��
//��			�������ܱ��滻�������еĶ��λ�ã����Դ��и���			 ��������ֻ�ڴ��ε�ʱ����ֵһ
//��			�õĲ�����ֵ���ܻ��������Ԥ�ϵĽ����					 �Σ���������׿��ơ�
//��
//��
//��
//��
//
//��
//��			��Ĳ����������޹أ�ֻҪ�Բ����Ĳ����ǺϷ��ģ�			 �����Ĳ������������йصģ���
//��			���Ϳ���ʹ�����κβ������͡�							 �����������Ͳ�ͬ������Ҫ��ͬ
//��																     �ĺ�������ʹ����ִ�е������ǲ�ͬ�ġ�
//
//��			���ǲ�������Ե�										 �����ǿ����������Ե�
//��
// 
//��
//��			���ǲ��ܵݹ��											 �����ǿ��Եݹ��

//����Լ��
//һ�����������ͺ��ʹ���﷨�����ơ��������Ա���û�����������ֶ��ߡ�
//������ƽʱ��һ��ϰ���ǣ�
//�Ѻ���ȫ����д
//��������Ҫȫ����д

//5��Ԥ����ָ�� #undef
//����ָ�������Ƴ�һ���궨�塣
//#undef NAME
//����ִ��һ��������Ҫ�����¶��壬��ô���ľ���������Ҫ���Ƴ���

//6�������
//���C �ı������ṩ��һ���������������������ж�����š���������������̡�
//���磺�����Ǹ���ͬһ��Դ�ļ�Ҫ�������ͬ��һ������Ĳ�ͬ�汾��ʱ����������е��ô���
//���ٶ�ĳ��������������һ��ĳ�����ȵ����飬��������ڴ����ޣ�������Ҫһ����С�����飬��������һ
//�������ڴ��д��������Ҫһ�������ܹ���д����
//��Linux��д��programe.c
//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}
//����ָ�gcc - D ARRAY_SIZE = 10 programe.c
//./a.out
//gcc - D ARRAY_SIZE = 100 programe.c
//./a.out

//7����������
//�ڱ���һ�������ʱ���������Ҫ��һ����䣨һ����䣩������߷����Ǻܷ���ġ���Ϊ��������������ָ�
//����˵��
//�����ԵĴ��룬ɾ����ϧ�������ְ��£��������ǿ���ѡ���Եı��롣
//#include <stdio.h>
//#define DEBUG//����DEBUG
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef DEBUG//���DEBUG�����ˣ�����룬���򲻱���
//		printf("%d\n", arr[i]);//Ϊ�˹۲������Ƿ�ֵ�ɹ��� 
//#endif
//	}
//	return 0;
//}

//��������������ָ�
//1.
//#if �������ʽ
//...
//#endif
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#if 1-1//���Ϊ�棬����룬���򲻱���
//		printf("%d\n", arr[i]);
//#endif
//	}
//	return 0;
//}
//�������ʽ��Ԥ��������ֵ��
//�磺
//#define __DEBUG__ 1
//#if __DEBUG__
//..
//#endif

//2.�����֧����������
//#if �������ʽ
//...
//#elif �������ʽ
//...
//#else
//...
//#endif
//#include <stdio.h>
//int main()
//{
//#if 1==2//���DEBUG�����ˣ�����룬���򲻱���
//	printf("haha\n"); 
//#elif 2==1
//	printf("hehe\n")
//#else 
//	printf("�ٺ�\n");
//#endif
//
//	return 0;
//}

//3.�ж��Ƿ񱻶���
//#if defined(symbol)//�����˲������
//#ifdef symbol
//����������ͬ
//#if !defined(symbol)//û�ж���������
//#ifndef symbol
//����������ͬ
//#include <stdio.h>
//#define DEBUG//����DEBUG
//int main()
//{
//#ifdef DEBUG//���DEBUG�����ˣ�����룬���򲻱���
//	printf("hehe\n"); 
//#endif
//#if defined(DEBUG)
//	printf("haha\n");
//#endif
//#ifndef DEBUG//���DEBUG�����ˣ�����룬���򲻱���
//	printf("hehe\n");
//#endif	
//#if !defined(DEBUG)
//	printf("haha\n");
//#endif
//	return 0;
//}

//4.Ƕ��ָ��
//#if defined(OS_UNIX)
//	#ifdef OPTION1
//		unix_version_option1();
//	#endif
//	#ifdef OPTION2
//		unix_version_option2();
//	#endif
//#elif defined(OS_MSDOS)
//	#ifdef OPTION2
//		msdos_version_option2();
//	#endif
//#endif

//8��Ԥ����ָ�� #include
//�����Ѿ�֪���� #include ָ�����ʹ����һ���ļ������롣������ʵ�ʳ����� #include ָ��ĵط�һ����
//�����滻�ķ�ʽ�ܼ򵥣�
//Ԥ��������ɾ������ָ����ð����ļ��������滻��
//����һ��Դ�ļ�������10�Σ��Ǿ�ʵ�ʱ�����10�Ρ�

//ͷ�ļ��������ķ�ʽ��
//�����ļ����������Լ�������.h�ļ�
//#include "filename"
//���Ҳ��ԣ�����Դ�ļ�����Ŀ¼�²��ң������ͷ�ļ�δ�ҵ���������������ҿ⺯��ͷ�ļ�һ���ڱ�׼λ�ò���ͷ�ļ���
//����Ҳ�������ʾ�������
//Linux�����ı�׼ͷ�ļ���·���� / usr / include
//VS�����ı�׼ͷ�ļ���·����C : \Program Files(x86)\Microsoft Visual Studio 12.0\VC\include��ע�ⰴ���Լ��İ�װ·��ȥ�ҡ�

//���ļ�����
//#include <filename.h>
//���Ҳ��ԣ�����ͷ�ļ�ֱ��ȥ��׼·����ȥ���ң�����Ҳ�������ʾ�������
//�����ǲ��ǿ���˵�����ڿ��ļ�Ҳ����ʹ�� ���� ����ʽ���������ǿ϶��ģ����ԡ�
//�������������ҵ�Ч�ʾ͵�Щ����Ȼ����Ҳ�����������ǿ��ļ����Ǳ����ļ��ˡ�
//�ʿ��ļ���ͷ�ļ�Ҳ������""

//Ƕ���ļ�����������ͷ�ļ����������ʱ��Ԥ����´����ݣ����´�������
//��ν��������⣿�𰸣��������롣
//ÿ��ͷ�ļ��Ŀ�ͷд��
//#ifndef __TEST_H__  //���û�ж����__TEST_H__Ϊ�棬ִ���������
//#define __TEST_H__  //����__TEST_H__
//ͷ�ļ�������		  //�������ݣ����򲻱���
//#endif

//���ߣ�#pragma once - �ִ���д�����ϱ��������ܱ����޷�ͨ��
//�Ϳ��Ա���ͷ�ļ����ظ����롣
//ע���Ƽ���������C / C++���ָ�ϡ��и�¼�Ŀ����Ծ�����Ҫ����
//�����⣺
//1. ͷ�ļ��е� ifndef / define / endif�Ǹ�ʲô�õ� ?//��ֹͷ�ļ����ظ���ΰ���
//2. #include <filename.h> �� #include "filename.h"��ʲô���� ?���ó��������Ҳ��Բ�ͬ

//8. ����Ԥ����ָ��
//#error
//#pragma
//#line
//...
//�������ܣ��Լ�ȥ�˽⡣
//#pragma pack()�ڽṹ�岿�ֽ��ܡ�
//�ο���C������Ƚ��ʡ�ѧϰ

//�ٶ������⣺
//#include <stdio.h>
//#include <stddef.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//int main()
//{
//	//offsetof-�� - ����ṹ���Ա��ƫ����
//	printf("%d\n", offsetof(struct S, c1));//�����Ϊ�ṹ������ơ���Ա������
//	printf("%d\n", offsetof(struct S, a));
//	printf("%d\n", offsetof(struct S, c2));
//	return 0;
//}

//ģ��ʵ��offsetof
//˼·������0��ַ���ǽṹ������ĵ�ַ�����Ա�����ĵ�ַ��Ϊ���Ե�ƫ����
//#include <stdio.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
////��0ǿ������ת��Ϊ�ṹ��ָ��ĵ�ַ
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c2));
//	return 0;
//}