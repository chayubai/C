#define _CRT_SECURE_NO_WARNINGS 1
//�����ַ����ַ����Ŀ⺯�������MSDN�ֲ�ѧϰ��
//C�����ж��ַ����ַ����Ĵ������Ƶ��������C���Ա�����û���ַ������͵ģ�
//�ַ���ͨ�����ڳ����ַ����л����ַ������С�������'\0'������־��
//�ַ���������������Щ���������޸ĵ��ַ�������.

//һ�����ַ�������strlen
//ԭ�����ַ���/�ַ��������Ԫ���ң����ַ�������'\0'�����������һ��ֱ������'\0'��������('\0'������)
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);//6
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	int len = strlen(arr);
//	printf("%d\n", len);//���ֵ
//	return 0;
//}

//size_t strlen(const char* str);
//�ַ����� '\0' ��Ϊ������־��strlen�������ص������ַ����� '\0' ǰ����ֵ��ַ������������� '\0' )��
//����ָ����ַ�������Ҫ�� '\0' ������
//ע�⺯���ķ���ֵΪsize_t�����޷��ŵģ��״�
//ѧ��strlen������ģ��ʵ��
//ԭ�����ַ���/�ַ��������Ԫ���ң����ַ�������'\0'�����������һ��ֱ������'\0'��������('\0'������)
//1���������ķ���
//2���ݹ�(��������ʱ����count�����ַ�������)
//3��ָ��-ָ��
//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str)//ȷ��strָ����ַ���ֵ���޸ģ�ʹ��const����*str
//{
//	int count = 0;
//	assert(str != NULL );//�����ָ�룬ȷ����Ч��
//	while (*str != '\0')//while(*str) - *str == '\0'������'\0'ASCIIΪ0
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);//6
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)//-3�������޷�����
//		printf("hehe\n");//hehe
//	else
//		prnitf("haha\n");
//	return 0;
//}
//size_t��ѡ��-ת������
//�⺯������unsigned���ǿ��ǵ�str�ĳ��Ȳ������Ǹ���

//�������Ȳ������Ƶ��ַ�������strcpy��strcat��strcmp
//1��strcpy�ַ�����������
//ԭ����Դ�ַ�����ÿһ��Ԫ�ذ���'\0'����ֵ��Ŀ�ĵ��ַ���
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	strcpy(arr1, arr2);//��arr2������arr1�У�����arr2�е�'\0'
//	//ͨ�����Է���'\0'��������arr1����
//	return 0;
//}

//char* strcpy(char* destination, const char* source);
//Copies the C string pointed by source into the array pointed by destination, including the
//terminating null character(and stopping at that point).
//Դ�ַ��������� '\0' ��������Դ�ַ������ܳ�ʼ��Ϊ�ַ����飬������ܻᵼ��Խ��
//�ὫԴ�ַ����е� '\0' ������Ŀ��ռ䡣
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ�����
//Ŀ��ռ����ɱ䡣��Ŀ�ĵ��ַ������ܳ�ʼ��Ϊ�����ַ���
//ѧ��ģ��ʵ�֡�
//ԭ����Դ�ַ�����ÿһ��Ԫ�ذ���'\0'����ֵ��Ŀ�ĵ��ַ���
//#include <stdio.h>
//#include <assert.h>
////�⺯���ķ���������char*������Ŀ�ĵ���ʼ��ַ����
//char* my_strcpy(char* dest, const char* src)//����Դ�ַ������ܱ��ı䣬��const����
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = *src;//��'\0'���ƹ�ȥ
//	char* ret = dest;//��ֹdest����ʼ��ַ���ı�
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;//����Ŀ�ĵؿռ����ʼ��ַ
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//2��strcat�ַ���׷�Ӻ���
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//char arr1[] = "hello";
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);//��arr2���ַ���׷�ӵ�arr1�ַ����ĺ���
//	printf("%s\n",arr1);//����Ŀ�ĵؿռ��㹻��
//	return 0;
//}

//'\0'�Ƿ�ᱻ׷�ӵ�Ŀ�ĵ��ַ����У�
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	
//	char arr1[30] = "hello\0xxxxxxxx";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//���Է���'\0'�ᱻ׷�ӵ�Ŀ�ĵ��ַ�����

//char* strcat(char* destination, const char* source);
//Appends a copy of the source string to the destination string.The terminating null character
//in destination is overwritten by the first character of source, and a null - character is included
//at the end of the new string formed by the concatenation of both in destination.
//Դ�ַ��������� '\0' ������
//Ŀ��ռ�������㹻�Ĵ���������Դ�ַ��������ݡ�
//Ŀ��ռ������޸ģ�����'\0'������
//�ַ����Լ����Լ�׷�ӣ���Σ�-- ���ܣ�����Ŀ�ĵ��ַ�����'\0'�������ˣ�����Ѱ��'\0'����ѭ��
//ģ��ʵ��strcat����
//ԭ����Ŀ�ĵ��ַ�����'\0'Ԫ�ص�ַλ������׷�ӵ����棬ֱ��Դ�ַ�����'\0'����׷��('\0'ҲҪ׷��)
//#include <stdio.h>
//#include <assert.h>
////�⺯���ķ�������Ϊchar*������Ŀ�ĵ���Ԫ�صĵ�ַ���Ա�֪��Ŀ�ĵؿռ��Ƿ����˱仯
//char* my_strcat(char* dest, const char* src)//����Դ�ַ������ܱ��ı䣬��const���Σ���ֵֹ���޸�
//{
//	char* ret = dest;
//	//assert(dest && src);//NULL == 0
//	assert(dest != NULL);
//	assert(src);
//	//1���ҵ�Ŀ�ĵ��ַ�����'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}	
//	//2��׷�ӣ�����'\0'Ϊ��ʼ��ַ����
//	while (*dest++ = *src++)
//		;
//	return ret;
//}
//int main()
//{
//	
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//3��strcmp�ַ����ȽϺ���
//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "sqwer";
//	//if("abcedf"=="sqwer")//"=="�ǱȽ����ݵģ����ַ�����ʾ��Ԫ�صĵ�ַ�����ڵ�ַ�϶��ǲ�һ����
//	int ret = strcmp(p1, p2);
//	//strcmp�Ƚ�p1��p2��ָ����ַ�����p1>p2,���ش���0�����֣�p1=p2�����ص���0�����֣�p1<p2������С��0������
//	//����VS - p1>p2,����1��p1=p2������0��p1<p2������-1
//	//����Linux - gcc����������������������p1>p2,���ش���0�����֣�p1=p2�����ص���0�����֣�p1<p2������С��0������
//	//�ʣ�
//	//�������´���ͻ������⣬Ӧ����C���Ա�׼���
//	/*if (strcmp(p1, p2) == 1)
//		printf("p1>p2\n");
//	else if (strcmp(p1, p2) == 0)
//		printf("p1=p2\n");
//	else if (strcmp(p1, p2) == -1)
//		printf("p1<p2\n");*/
//	//strcmp�Ƚϵ��Ǹ����ַ���ASCII�����ͬλ��ASCII��ͬ����Ƚ���һλ��Ӧ�ַ��������ǱȽ��ַ����ĳ���
//	return 0;
//}

//int strcmp ( const char * str1, const char * str2 );
//This function starts comparing the first character of each string.If they are equal to each
//other, it continues with the following pairs until the characters differ or until a terminating
//null - character is reached.
//C��׼�涨��
//��һ���ַ������ڵڶ����ַ������򷵻ش���0������
//��һ���ַ������ڵڶ����ַ������򷵻�0
//��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������
//ģ��ʵ��strcmp����
//ԭ���Ƚ϶�Ӧλ���ַ�ASCII�����ͬλ���ַ�ASCII��ȣ����αȽ���һλ�����ĳһλ��ͬ����ֹͣ������֪���Ƚϵ����Ե�'\0'�ַ�Ϊֹ(\0Ҳ��Ƚ�)

//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)//str1��str2������ı�
//{
//	assert(str1 && str2);//��ָ֤�����Ч��
//	while (*str1 == *str2)
//	{	
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//Linux�µ�ʵ��
//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1, const char* str2)//str1��str2������ı�
//{ 
//	assert(str1 && str2);//��ָ֤�����Ч��
//	while (*str1 == *str2)
//	{	
//	if (*str1 == '\0')
//		return 0;
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "abqwe";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//�������ϳ��Ȳ������Ƶ��ַ�������������ʱ��'\0'��Ϊ������־�����ܳ��ȵ����ƣ�����Ҳ���ܵ���һЩ����
//�磺strcat��Ŀ�ĵؿռ䲻�������º�������ȫ
//#include <stdio.h>
//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "hello bit";
//	//strcpy(arr1, arr2);
//	return 0;
//}

//���������Ƶ��ַ�����������strncpy��strncat��strncmp
//1��strncpy
//char* strncpy(char* destination, const char* source, size_t num);num��λ���ֽ�
//which is signaled by a null - character) is found before num characters have been copied,
//destination is padded with zeros until a total of num characters have been written to it.
//����num���ַ���Դ�ַ�����Ŀ��ռ䡣
//���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��\0��ֱ��num����
//#include <stdio.h>
//int main()
//{
//	//char arr1[10] = "abcdef";
//	//char arr2[] = "hello bit";
//	//strncpy(arr1, arr2, 4);
//	
//	char arr1[10] = "abcdefgh";
//	char arr2[] = "bit";
//	strncpy(arr1, arr2, 6);
//  //ͨ�����Թ۲���
//	return 0;
//}
//ģ��ʵ��strncpy
//�ڰ�װ·���µ�VC/crt/src�в鿴

//2��strncat
//char* strncat(char* destination, const char* source, size_t num);num��λ���ֽ�
//Appends the first num characters of source to destination, plus a terminating null - character.
//If the length of the C string in source is less than num, only the content up to the terminating
//null - character is copied.
//#include <stdio.h>
//int mian()
//{
//	//char arr1[30] = "hello\0xxxxxxxxxxxxxx";
//	//char arr2[] = "world";
//	//strncat(arr1, arr2, 3);
//	//���Թ۲��������ֵ�׷����󣬻���Ŀ�ĵؿռ���������һ��\0
//	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 8);
//	//���Թ۲��������ֵ�Դ�ַ���׷�ӵ��ַ���������Դ�ַ����ĳ��ȣ�������\0
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str1[20];
//    char str2[20];
//    strcpy(str1, "To be ");
//    strcpy(str2, "or not to be");
//    strncat(str1, str2, 6);
//    puts(str1);
//    return 0;
//}

//ģ��ʵ��strncat
//�ڰ�װ·���µ�VC/crt/src�в鿴

//3��strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );num��λ���ֽ�
//�Ƚ�ǰnum���ַ�
//strncmp�ķ���ֵ�趨��strcmp��ͬ
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//    int n;
//    puts("Looking for R2 astromech droids...");
//    for (n = 0; n < 3; n++)
//        if (strncmp(str[n], "R2xx", 2) == 0)
//        {
//            printf("found %s\n", str[n]);
//        }
//    return 0;
//}

//�ַ�������strstr��strtok
//1��strstr�����ַ���
//char* strstr(const char* str1, const char* str2);
//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
//ע�⣺�ĵ��е�NULL��ʾ��ָ�룬NUL/null/'\0'��ʾ'\0'
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* p1 = "abcdefghi";
//	char* p2 = "def";
//	char* ret = strstr(p1, p2);//strstr����ҵ����Ӵ������صĸ��Ӵ���Ŀ�ĵؿռ���Ӵ���Ԫ�صĵ�ַ�����򷵻�NULL��ָ��
//	if (ret == NULL)
//		printf("�Ӵ�������\n");
//	else
//		printf("%s\n", ret);//�����Ӵ���Ԫ�صĵ�ַ
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = strstr(p1, p2);//���ص�һ���Ӵ���Ԫ�صĵ�ַ
//	if (ret == NULL)
//		printf("�Ӵ�������\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
//}

//ģ��ʵ��strstr
//ԭ����Ŀ�ĵؿռ��ҵ���Դ�ַ�����Ԫ����ͬ���ַ�������Ӽӣ�ֱ���ҵ���Ȼ��Դ�ַ�����Ŀ�ĵ��ַ����ĵ�ַͬʱ�ң�
//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);//p2����Ϊ��ָ��
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur = (char*)p1;//������¼��ǰ�����ַ�ȫƥ��ɹ����ַ��ĵ�ַ
//	//�ж�p2�Ƿ�Ϊ���ַ���
//	if (*p2 == '\0')//��if(!*p2)
//		return (char*)p1;//p1��const char*������char*����ᱨ����
//	while (*cur)
//	{
//		//�磺abbcdef bbc
//		s1 = cur;//�����һ�β���ʧ�ܣ��ڶ��δ�cur����һ��λ������ƥ����ң�ָ��ع�
//		s2 = (char*)p2;//ָ��ع�
//		while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//s1�ַ���s2�ַ�ͬʱ��
//		//1��p1��ǰ����\0����ҽ�������abc abcdef	2��p2��ǰ����\0����ҽ�������abcdeqwer def  
//		{
//			s1++;
//			s2++;
//		}
//		//����������һ������ѭ������������������
//		if (*s2 == '\0')
//			return cur;//�ҵ��Ӵ�
//		if (*s1 == '\0')
//			return NULL;
//		cur++;
//	}
//	//��ÿһ�ζ�û�ҵ��Ӵ���ѭ������
//	return NULL;
//}
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//		printf("�Ӵ�������\n");
//	else
//		printf("%s\n", ret);
//	return 0;
//}
//�˽�KMP�㷨

//2��strtok�ַ����ָ��
//char * strtok ( char * str, const char * sep );
//sep�����Ǹ��ַ����������������ָ������ַ�����
//��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
//strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β������һ��ָ����������һ���ַ���ָ�롣
//��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
//strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�(��static��̬������ס��ǵ�λ��)
//strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
//��ע����һ����������һ�δ��ַ������׵�ַ���ڶ����Լ�֮��NULL��
//����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//    char arr[] = "zpw@bitedu.tech";
//    char* p = "@.";
//    char buf[1024] = { 0 };
//    strcpy(buf, arr);//�����ݿ���һ�ݣ�����buf���������
//    //�и�buf�е��ַ���
//    char* ret = strtok(buf, p);//����һ��ָ����������һ���ַ���ָ��
//    printf("%s\n", ret); 
//
//    ret = strtok(NULL, p);//����һ��ָ����������һ���ַ���ָ��
//    printf("%s\n", ret);
//
//    ret = strtok(NULL, p);//����һ��ָ����������һ���ַ���ָ��
//    printf("%s\n", ret);
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char arr[] = "zpw@bitedu.tech";
//    char* p = "@.";
//    char buf[1024] = { 0 };
//    strcpy(buf, arr);//�����ݿ���һ�ݣ�����buf���������
//    //�и�buf�е��ַ���
//    char* ret = NULL;//����strtok�����ķ���ֵ
//
//    for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//    {//ret = strtok(arr, p)ֻ��ִ��һ��
//        printf("%s\n", ret);
//    }
//    return 0;
//}
//#include <stdio.h>

//#include <string.h>
//int main()
//{
//    char str[] = "- This, a sample string.";
//    char* pch;
//    printf("Splitting string \"%s\" into tokens:\n", str);
//    pch = strtok(str, " ,.-");
//    while (pch != NULL)
//    {
//        printf("%s\n", pch);
//        pch = strtok(NULL, " ,.-");
//    }
//    return 0;
//}

//������Ϣ����strerror��
//char * strerror ( int errnum );
//���ã����ش����룬����Ӧ�Ĵ�����Ϣ��
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//���������ͷ�ļ�
//int main()
//{
//    //������      �������Ӧ�Ĵ�����Ϣ
//    //0           No error
//    //1           Operation not permitted
//    //2           No such file or directory
//    //...
//    char* str = strerror(0);
//    printf("%s\n", str);
//
//    char* str = strerror(1);
//    printf("%s\n", str);
//
//    char* str = strerror(2);
//    printf("%s\n", str);
//
//    return 0;
//}

//errno��һ��ȫ�ֵĴ�����ı���
//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ������errno��
//��ʱͨ���鿴errno��������Ϣ��֪���������ԭ��
//char* str = strerror(errno);
//ѡ��errnoת�����壬���Բ鿴������
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>//���������ͷ�ļ�
//int main()
//{
//    //���ļ�fopen("�ļ���.��׺","r")   r��ʾ���ļ���w��ʾд�ļ�
//    //fopen����ļ����ڣ�����һ��FILE*���͵�ָ�룬����ļ������ڣ���᷵��NULL
//    FILE* pf = fopen("D:/Desktop/����/�����ֲ�.txt", "r");//fopen��·���Ǿ���·����ע���ļ���֮��ķָ���/
//    if (pf == NULL)
//        printf("%s\n", strerror(errno));
//    else
//        printf("open file success\n");
//    return 0;
//}

//�ַ�����
//1���ַ����ຯ�����ж��ַ��Ƿ����ڸ����ַ�
//����			������Ĳ����������������ͷ�����(��0)������Ϊ�ٷ���0
//iscntrl		�κο����ַ�
//isspace		�հ��ַ����ո� ������ҳ��\f��������'\n'���س���\r�����Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
//isdigit		ʮ�������� 0~9
//isxdigit		ʮ���������֣���������ʮ�������֣�Сд��ĸa~f����д��ĸA~F
//islower		Сд��ĸa~z
//isupper		��д��ĸA~Z
//isalpha		��ĸa~z��A~Z
//isalnum		��ĸ�������֣�a~z, A~Z, 0~9
//ispunct		�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
//isgraph		�κ�ͼ���ַ�
//isprint		�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    char ch = 'w';
//    int ret = islower(ch);
//    printf("%d\n", ret);
//    return 0;
//}

//2���ַ�ת������
//int tolower(int c);����ĸתСд
//int toupper(int c);����ĸת��д
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    char ch = tolower('Q');
//    puchar(ch);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    int i = 0;
//    char arr[] = "I Am A Student";
//    while (arr[i])
//    {
//        if (isupper(arr[i]))
//            arr[i] = tolower(arr[i]);
//        i++;
//    }
//    printf("%s\n", arr);
//    return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    int i = 0;
//    char str[] = "Test String.\n";
//    char c;
//    while (str[i])
//    {
//        c = str[i];
//        if (isupper(c))
//            c = tolower(c);
//        putchar(c);
//        i++;
//    }
//    return 0;
//}

//�ڴ��������memcpy��memmove��memset��memcmp
//���Ϻ��������Ķ������ַ����������ʵ�ֲ�ͬ����֮��Ĳ����أ�
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	//char* dest,const char* src
//	strcpy(arr2, arr1);
//	return 0;
//}
//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//strcpy���ַ�һ��һ���Ŀ�����Ŀ�ĵؿռ䣬�ʻ��01������arr2�С���������00��'\0'�ͻ�������ʽ��Ϊ1

//1��memcpy�ڴ濽��
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));//memcpy(arr2, arr1,5*sizeof(int));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S arr1[] = { {"����",20},{"����",30} };
//	struct S arr2[3] = { 0 };
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//struct {
//	char name[40];
//	int age;
//} person, person_copy;
//int main()
//{
//	char myname[] = "Pierre de Fermat";
//	/* using memcpy to copy string: */
//	memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 46;
//	/* using memcpy to copy structure: */
//	memcpy(&person_copy, &person, sizeof(person));
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//	return 0;
//}

//void * memcpy ( void * destination, const void * source, size_t num );num�ĵ�λ�ֽ�
//���������������strncpy����
//����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
//������������� '\0' ��ʱ�򲢲���ͣ������
//���source��destination���κε��ص������ƵĽ������δ����ġ�
//ģ��ʵ��memcpy
//#include <stdio.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{//void*���͵ı������ܽ����ò���������++����������+/-��������
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;//����dest����ʼ��ַ
//	while (num--)
//	{
//		//��Դ�ռ�����ݰ��ֽ�һ��һ���ķ���Ŀ�ĵؿռ䣬��Ҫ��num�ֽڸ�����
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//ͬһ���ȼ������������ϣ�����((char*)dest)++
//		++(char*)src;
//		//ֱ��д��*((char*)dest)++ = *((char*)src)++
//	}
//	return ret;//����dest����ʼ��ַ
//}
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	struct S arr3[] = { {"����",20},{"����",30} };
//	struct S arr4[3] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	//ͨ�����Թ۲���
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;//����dest����ʼ��ַ
//	while (num--)
//	{
//		//��Դ�ռ�����ݰ��ֽ�һ��һ���ķ���Ŀ�ĵؿռ䣬��Ҫ��num�ֽڸ�����
//		*(char*)dest = *(char*)src;
//		++(char*)dest;//ͬһ���ȼ������������ϣ�����((char*)dest)++
//		++(char*)src;
//		//ֱ��д��*((char*)dest)++ = *((char*)src)++
//	}
//	return ret;//����dest����ʼ��ַ
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memcpy(arr+2, arr, 20);//��1 2 3 4 5������3 4 5 6 7 8��
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//�����Ԥ�ڵĲ�һ����Ϊʲô��
//	//1  2  3  4  5  6  7  8  9  10
//	//      1  2  3  4  5			//����
//	//      1  2  1  2  1
//	//����1��2������3��4��
//	//��ʱ���ڽ�3����5���ͱ���˽�1����5������4����6���ͱ���˽�2����6������5����7����ɽ�1����7��
//	return 0;
//}
//���ʵ������������أ�--memmove()

//2��memmove
//�����ڴ��ص��ĸ�������
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr+2, arr, 20);//��1 2 3 4 5������3 4 5 6 7 8��
//	//ʹ��memcpyҲ����
//	//C���Ա�׼�涨��
//	//memcpy��ֻҪ�����ص����ڴ濽������
//	//memmove�����ڴ����ص��ڴ�Ŀ���
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str);
//	return 0;
//}

//void * memmove ( void* destination, const void* source, size_t num );
//��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
//���Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������
//ģ��ʵ��memmove
//1 2 3 4 5 6 7 8 9 10
//����Ҫ��srcԴ�ռ��4 5 6 7 8������Ŀ�ĵ�dest�ռ�
//�����4 5 6 7 8������srcԴ�ռ�����ʱ����dest<srcʱ����ǰ���󿽱�
//�������4 5 6 7 8������srcԴ�ռ���ұ�ʱ���Ӻ���ǰ����
//�������4 5 6 7 8������srcԴ�ռ�����˵��ұ�ʱ����ǰ���󿽱������ߴӺ���ǰ��������
//��һ�֣�
//if(dest<src){ǰ-��}else{��-ǰ}
//�ڶ��֣�
//if(dest<src || dest>(char*)src+count){ǰ-��}else{��-ǰ}
//#include <stdio.h>
//#include <assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	void* ret = dest;
//	if (dest < src)
//	{
//		//ǰ - ��
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//�� - ǰ
//		//���裺��34567 ������56789
//		//03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00 09 00 00 00 0a 00 00 00
//		//�Ƚ�07 00 00 00 ���򿽱���09 00 00 00��
//		//(char*)src + 20 -1��Ϊ7�����һ���ֽڵĵ�ַ
//		//(char*)dest + 20 -1��Ϊ9�����һ���ֽڵĵ�ַ
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 20);//��1 2 3 4 5������3 4 5 6 7 8��
//	
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//3��memcmp
//int memcmp(const void* ptr1,const void* ptr2,size_t num);num��λ���ֽ�
//�Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�
//����ֵ��strcmp��ͬ
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 8);//�Ƚ�ǰ8���ֽ�
//	printf("%d\n", ret);
//	ret = memcmp(arr1, arr2, 9);//�Ƚ�ǰ9���ֽ�
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char buffer1[] = "DWgaOtP12df0";
//	char buffer2[] = "DWGAOTP12DF0";
//	int n;
//	n = memcmp(buffer1, buffer2, sizeof(buffer1));
//	if (n > 0) 
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	else if (n < 0) 
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	else 
//		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	return 0;
//}

//4��memset�ڴ�����
//void* memset(void* dest, int c, size_t num);

//#include <stdio.h>
//int main()
//{
//	//char arr[10] = "";
//	//memset(arr, '#', 10);//��arr��ǰ10���ֽ�����Ϊ#
//	//���Թ۲���
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);//��arr��ǰ10���ֽ�����Ϊ1
//	//���Թ۲���
//	//arr��40���ֽ�
//	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 00 00 00...
//	//ǰ10�ֽڣ�������Ϊ��1
//	//arr[0] = 0x01010101;
//	//arr[1] = 0x01010101;
//	//arr[2] = 0x01010000;
//	return 0;
//}

//���ԣ���ѧϰ���˽�⺯��