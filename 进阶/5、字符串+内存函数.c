#define _CRT_SECURE_NO_WARNINGS 1
//�����ַ����ַ����Ŀ⺯�������MSDN�ֲ�ѧϰ��
//�磺strlen strcpy strcat strcmp strncpy strncat strncmp strstr strtok strerror memcpy memmove memcmp
//C�����ж��ַ����ַ����Ĵ������Ƶ��������C���Ա�����û���ַ������͵ģ�
//�ַ���ͨ������ �����ַ��� �л��� �ַ����� �С�������'\0'������־��
//ע�⣺�ַ���������������Щ���������޸ĵ��ַ�������.
/*
#include <stdio.h>
int main() 
{
	char *p1 = "abcdef";//"abcdef"��һ�������ַ����������ַ�������Ԫ�صĵ�ַ��ֵ��p1�������ǽ��ַ�������p1��
	//*p1 = 'W';//��Ϊ"abcdef"�ǳ����ַ������ǲ������޸ĵģ�������޸ĳ������� ---Linux�±���Segment fault�δ���
	//www.stackoverflow.com
	//segmentfault.com
	printf("%s\n", p1);//��ӡ�ַ���

	//��ȷ��д��
	const char *p2 = "abcdef";
	//*p2 = 'W';//��ʱ�ͻᱨ��
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char* str = strcat("abcdef","abc");//ע�⣺�ַ���������������Щ���������޸ĵ��ַ�������.
	printf("%s\n", str);//��������
	return 0;
}
*/

//һ�����ַ�������strlen
//ԭ�����ַ���/�ַ��������Ԫ���ң����ַ�������'\0'�����������һ��ֱ������'\0'��������('\0'������)
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int len = strlen("abcdef");
	printf("%d\n", len);//6
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//����ʾ��
	char arr[] = { 'a','b','c','d','e','f' };
	int len = strlen(arr);
	printf("%d\n", len);//���ֵ
	return 0;
}
*/

//strlen������
//size_t strlen(const char* str);
//�ַ����� '\0' ��Ϊ������־��strlen�������ص������ַ����� '\0' ǰ����ֵ��ַ������������� '\0' )��
//����ָ����ַ�������Ҫ�� '\0' ������
//ע�⣺�����ķ���ֵΪsize_t�����޷��ŵģ��״�

//strlen������ģ��ʵ��
//ԭ�����ַ���/�ַ��������Ԫ���ң����ַ�������'\0'�����������һ��ֱ������'\0'��������('\0'������)
//����1���������ķ���
//����2���ݹ�(��������ʱ����count�����ַ�������)
//����3��ָ��-ָ��
/*
//����1��
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)//ȷ��strָ����ַ���ֵ���޸ģ�ʹ��const����*str
{
	int count = 0;
	assert(str != NULL );//�����ָ�룬ȷ����Ч��
	while (*str != '\0')//while(*str) - ��*str == '\0'������'\0'ASCIIΪ0��ѭ������
	{
		count++;
		str++;//��һ�п���д�������У�while(*str++)
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);//6
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//�޷����� - �޷����� = �޷�����
	if (strlen("abc") - strlen("abcdef") > 0)//-3�������޷�����
		printf("hehe\n");//hehe
	else
		prnitf("haha\n");
	return 0;
}
*/
//size_t��ѡ��-ת������  size_t == unsigned int
//strlen�⺯����������Ϊunsigned int���ǿ��ǵ�str�ĳ��Ȳ������Ǹ�������ȴ�����������������
//ʹ���Լ�ʵ�ֵ�my_strlen�����ڷ���������int�����Ա������������ⷢ����

//����2��(��������ʱ����count�����ַ�������)
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+my_strlen("\0")
//1+1+1+0
/*
#include <assert.h>
int my_strlen(const char* str)//str��һ��ָ�����
{
	assert(str);
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
	//if (*str != '\0')
	//{
	//	str++;
	//	return my_strlen(str) + 1;
	//}
	//else
	//	return 0;
}
//����3��
int my_strlen(const char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;//��һ�в���д�������ˣ�������ִ��һ��++������Ҫ--��ȥ
	}
	return end - start;//��ʱ����'\0'�ĵ�ַ-'\b'�ĵ�ַ
}
*/

//�������Ȳ������Ƶ��ַ�������strcpy��strcat��strcmp
//1��strcpy�ַ�����������
//ԭ����Դ�ַ�����ÿһ��Ԫ�ذ���'\0'����ֵ��Ŀ�ĵ��ַ���
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	strcpy(arr1, arr2);//��arr2������arr1�У�����arr2�е�'\0'
	//ͨ�����Է���'\0'��������arr1����
	return 0;
}
*/

//strcpy������
//char* strcpy(char* destination, const char* source);
//Copies the C string pointed by source into the array pointed by destination, 
//including the terminating null character(and stopping at that point).
//ע�⣺
//1��Դ�ַ��������� '\0' ��������Դ�ַ������ܳ�ʼ��Ϊ�ַ����飬������ܻᵼ��Խ��
//2���ὫԴ�ַ����е� '\0' ������Ŀ��ռ䡣
//3��Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ�����
//4��Ŀ��ռ����ɱ䡣��Ŀ�ĵ��ַ������ܳ�ʼ��Ϊ�����ַ���

//strcpyģ��ʵ�֡�
//ԭ����Դ�ַ�����ÿһ��Ԫ�ذ���'\0'����ֵ��Ŀ�ĵ��ַ���
/*
#include <stdio.h>
#include <assert.h>
//�⺯���ķ���������char*������Ŀ�ĵ���ʼ��ַ����
char* my_strcpy(char* dest, const char* src)//����Դ�ַ������ܱ��ı䣬��const����
{
	assert(dest != NULL);
	assert(src != NULL);

	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	//*dest = *src;//��'\0'���ƹ�ȥ
	char* ret = dest;//����ʱ��������dest����ʼ��ַ����Ϊdest�����й����лᷢ���ı�
	while (*dest++ = *src++)
	{
		;
	}
	return ret;//����Ŀ�ĵؿռ����ʼ��ַ
}
int main()
{
	//����ʾ��
	//char* arr1 = "abcdefghi";
	char arr1[] = "abcdefghi";
	//����ʾ��
	//char arr2[] = {'b','i','t'};
	char arr2[] = "bit";//����char* arr2 = "bit";
	my_strcpy(arr1, arr2);//ע�⣺���ﴫ�����������������Ԫ�ص�ַ���Ǵ�ַ����
	printf("%s\n", arr1);//ע��arr1�ĵ�ַû�б仯��dest�ĵ�ַ�仯�ˣ�ֻ��һ��ʼ����ָ����ͬ�ĵ�ַ��
	return 0;
}
*/

//2��strcat�ַ���׷�Ӻ���
//ԭ����Դ�ַ�������Ԫ�ؿ�ʼ��һ�����ķŵ�Ŀ���ַ���'\0'λ�ã���֮��λ��
/*
#include <stdio.h>
#include <string.h>
int main()
{
	//����ʾ��
	//char arr1[] = "hello";
	char arr1[30] = "hello";
	char arr2[] = "world";
	strcat(arr1, arr2);//��arr2���ַ���׷�ӵ�arr1�ַ����ĺ���
	printf("%s\n",arr1);//������ΪĿ�ĵؿռ��㹻��ǿ��׷�ӵ���Խ�����
	return 0;
}
*/
//Դ�ַ�����'\0'�Ƿ�ᱻ׷�ӵ�Ŀ�ĵ��ַ����У� - ��
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[30] = "hello\0xxxxxxxx";
	char arr2[] = "world";
	strcat(arr1, arr2);//��Ŀ�ĵ��ַ����еĵ�һ��'\0'��ʼ׷��
	printf("%s\n", arr1);
	return 0;
}
*/
//���Է���Դ�ַ�����'\0'�ᱻ׷�ӵ�Ŀ�ĵ��ַ�����

//strcat������
//char* strcat(char* destination, const char* source);
//Appends a copy of the source string to the destination string.
//The terminating null character in destination is overwritten by the first character of source, 
//and a null - character is included at the end of the new string formed by the concatenation of both in destination.
//ע�⣺
//1��Դ�ַ��������� '\0' ������
//2��Ŀ��ռ�������㹻�Ĵ���������Դ�ַ��������ݡ�
//3��Ŀ��ռ������޸ģ�����'\0'������
//4���ַ����Լ����Լ�׷�ӣ���Σ�
//	-- ���ܣ�����Ŀ���ַ�����Դ�ַ������׵�ַָ��ͬһ���ռ䡣��Ŀ�ĵ��ַ�����'\0'�������ˣ�����Դ��ַ�ͻ���Ϊ�Ҳ���'\0'����ѭ��׷��

//ģ��ʵ��strcat����
//ԭ����Ŀ�ĵ��ַ�����'\0'Ԫ�ص�ַλ������׷�ӵ����棬ֱ��Դ�ַ�����'\0'����׷��('\0'ҲҪ׷��)
/*
#include <stdio.h>
#include <string.h>
#include <assert.h>
//�⺯���ķ�������Ϊchar*������Ŀ�ĵ���Ԫ�صĵ�ַ���Ա�֪��Ŀ�ĵؿռ��Ƿ����˱仯
char* my_strcat(char* dest, const char* src)//����Դ�ַ������ܱ��ı䣬��const���Σ���ֹ*src�޸�ֵ
{
	char* ret = dest;
	//assert(dest && src);//NULL == 0
	//�ȼ������������
	assert(dest != NULL);
	assert(src);
	//1���ҵ�Ŀ�ĵ��ַ�����'\0'
	while (*dest != '\0')//while(*dest)�����ܺϲ�Ϊwhile(*dest++)�������++һ��
	{
		dest++;
	}	
	//2��׷�ӣ�����'\0'Ϊ��ʼ��ַ����
	while (*dest++ = *src++)
		;
	//strcpy(dest,src);//����׷�Ӳ������Ի�����һ��
	return ret;
}
int main()
{
	char arr1[30] = "hello";
	//char arr2[] = "world";
	char* arr2 = "world";
	my_strcat(arr1, arr2);
	//my_strcat(arr1, arr1);//���Է��֣�����ѭ��׷�ӣ���׷�ӵ����û�пռ�ʱ�ͻ�Խ����ʣ���ѭ����������������
	//Ŀ���ַ�����Դ�ַ������׵�ַָ��ͬһ���ռ䣬�޸�*dest�ͻ��޸�*src����const char*ì�ܣ�����˵���Ǵ����
	//��Ȼdest��srcָ�����ͬһ���ռ䣬��ָ��Ĳ����ַ���������
	//���Լ�ʹsrc��const���Σ�����src��ָ���ǿ��Ըı�ģ�����ͨ��*dest�޸��ַ�����srcָ����ַ������Է����ı䣬
	//ֻ�ǲ���ͨ��*srcֱ�Ӹı䵱ǰ��ֵ��������*src='x';ȫ���̣�û��*src='x';�������ʲ�������⡣

	//ע�����֣�
	//const char *p = "abcdef";//"abcdef"����ַ�����ֵ�����޸�
	//char arr[] = "world"; const char *p  = arr;//"world"����ַ�����ֵ�����޸�
	printf("%s\n", arr1);
	return 0;
}
*/
//�鿴�⺯����Դ�룺VS��װ·�� - VC/crt/src

//3��strcmp�ַ����ȽϺ���
//ԭ��strcmp�Ƚϵ��Ǹ����ַ���ASCII�����ͬλ��ASCII��ͬ����Ƚ���һλ��Ӧ�ַ�
/*
#include <stdio.h>
int main()
{
	char* p1 = "abcdef";
	char* p2 = "aqwer";
	//if("abcedf"=="aqwer")//�����ַ���������Ԫ�صĵ�ַ��ʾ����Ϊ������Ԫ�صĵ�ַ�϶��ǲ�һ����
	int ret = strcmp(p1, p2);
	//strcmp�Ƚ�p1��p2��ָ����ַ�����p1>p2,���ش���0�����֣�p1=p2�����ص���0�����֣�p1<p2������С��0������
	//����Windows - VS���ԣ����p1>p2,����1��p1=p2������0��p1<p2������-1
	//����Linux - gcc���ԣ���������������������p1>p2,���ش���0�����֣�p1=p2�����ص���0�����֣�p1<p2������С��0������
	//����ʾ�����������´�����linux�¾ͻ�������
	if (strcmp(p1, p2) == 1)
		printf("p1>p2\n");
	else if (strcmp(p1, p2) == 0)
		printf("p1=p2\n");
	else if (strcmp(p1, p2) == -1)
		printf("p1<p2\n");
	
	//��ȷʾ����Ӧ����C���Ա�׼���
	if (strcmp(p1, p2) > 0)
		printf("p1>p2\n");
	else if (strcmp(p1, p2) == 0)
		printf("p1=p2\n");
	else if (strcmp(p1, p2) < 0)
		printf("p1<p2\n");	//���ǱȽ��ַ����ĳ���
	//�ʣ�ʹ��strcmp�ķ���ֵ�ж��ַ�����С

	return 0;
}
*/

//strcmp������
//int strcmp ( const char * str1, const char * str2 );
//This function starts comparing the first character of each string.If they are equal to each other, 
//it continues with the following pairs until the characters differ or until a terminating null - character is reached.
//C��׼�涨��
//��һ���ַ������ڵڶ����ַ������򷵻ش���0������
//��һ���ַ������ڵڶ����ַ������򷵻�0
//��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������

//ģ��ʵ��strcmp����
//ԭ���Ƚ϶�Ӧλ���ַ�ASCII�����ͬλ���ַ�ASCII��ȣ����αȽ���һλ�����ĳһλ��ͬ����ֹͣ������ֱ���Ƚϵ����Ե�'\0'�ַ�Ϊֹ(\0Ҳ��Ƚ�)
/*
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)//str1��str2������ı�
{
	assert(str1 && str2);//��ָ֤�����Ч��
	while (*str1 == *str2)
	{	
		//str1:abcdef  str2:abcdef
		if (*str1 == '\0')//��������ַ�����ȣ���str1��str2��������'\0',�ȽϽ���
			return 0;
		str1++;
		str2++;
		//if����++���棬��ѭ��һ�Ρ�if����++���棬��ѭ��һ��
		//if((*str1 == '\0') && (*str2 == '\0'))
		//	return 0;
	}
	//�����������ͬλ�ϵ��ַ��������
	//str1:abcdef  str2:abcd
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}
*/
//Linux�µ�ʵ��
/*
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)//str1��str2������ı�
{ 
	assert(str1 && str2);//��ָ֤�����Ч��
	while (*str1 == *str2)
	{	
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	return 0;
}
*/
//�������ϳ��Ȳ������Ƶ��ַ�������������ʱ��'\0'��Ϊ������־�����ܳ��ȵ����ƣ�����Ҳ���ܵ���һЩ����
//�磺strcpy��strcat��Ŀ�ĵؿռ䲻��������ʹ�ú���ʱ�򲻰�ȫ
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[5] = "abc";
	char arr2[] = "hello bit";
	//strcpy(arr1, arr2);//��ʹ�ռ䲻�㣬�ú������ɰ�"hello bit"ȫ��������arr1��
	//strcat(arr1, arr2);//��ʹ�ռ䲻�㣬�ú������ɰ�"hello bit"ȫ��׷�ӵ�arr1��
	printf("%s\n", arr1);
	return 0;
}
*/

//�������������Ƶ��ַ�����������strncpy��strncat��strncmp
//1��strncpy
//char* strncpy(char* destination, const char* source, size_t num);����num���ַ�(�ֽ�)��Դ�ַ�����Ŀ��ռ䡣
//which is signaled by a null - character) is found before num characters have been copied,
//destination is padded with zeros until a total of num characters have been written to it.
//ע�⣺
//1��num��λ���ֽ�
//2�����Դ�ַ����ĳ��ȴ���num����ֻ����ǰnum���ַ������治��������һ��\0
//3�����Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��'\0'��0��ֱ��num����
/*
#include <stdio.h>	
#include <string.h>
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hello bit";
	strncpy(arr1, arr2, 4);//�ڿ�����󣬺��治�Ჹһ��\0
	//ͨ�����Թ۲���,arr1�����ݱ仯 - arr1:"hellef\0\0\0\0"

	char arr3[10] = "abcdefgh";
	char arr4[] = "bit";
	strncpy(arr3, arr4, 6);//�����������ֽڣ���'\0'���
	//ͨ�����Թ۲���,arr1�����ݱ仯 - arr1:"bit\0\0\0gh\0\0"
	return 0;
}
*/

//ģ��ʵ��strncpy
//ԭ��һ���ַ�һ���ַ��Ŀ���
//numС��Դ�ַ������ȣ������count��ǰΪ0�������������
//num����Դ�ַ������ȣ������countû����ǰΪ0���򿽱���Դ�ַ���������('\0')���ټ�����ʣ���count�����ַ�������Ϊ'\0'
#include <stdio.h>	
#include <assert.h>
/*
char* my_strncpy(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	//����3���ֽ�
	//abcdefgh\0
	//bit\0
	//bitdefgh\0
	//����6���ֽ�
	//abcdefgh\0    
	//bit\0
	//bitdefgh\0 
	while (count != 0)//6 5 4 3
	{
		*strDest++ = *strSource++;
		count--;
		if(*strSource == '\0')
			break;
	}
	//countû����ǰ����
	//3
	//bit\0\0\0gh\0 
	if (count != 0)
	{
		while (count != 0)//3 2 1 0
		{
			*strDest++ = '\0';
			count--;
		}
	}
	//count��ǰ������countû����ǰ������������\0����
	return ret;
}
*/
/*
char* my_strncpy(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	while (count && (*strDest++ = *strSource++))//��·Ч������countΪ0ֱ�Ӳ�����ѭ����
			//��count��Ϊ0��*strSource=='\0'ʱ��*strDest == '\0'Ҳ������ѭ��(�����ִ����һ��(*strDest++ = *strSource++)��*strDest��ֵ��һ��\0)
	{
		count--;
	}
	if (count)
	{
		//������--count����Ϊ����ѭ����ִ����һ��(*strDest++ = *strSource++)���Ѿ���ֵ��һ����\0����ȥ����������Ҫ�ٷ�һ����\0����������ǰ�ü���
		while (--count)//2 1 0
		{
			*strDest++ = '\0';
		}
	}
	return ret;
}
int main()
{
	char arr1[10] = "abcdef";
	char arr2[] = "hello bit";
	my_strncpy(arr1, arr2, 4);//�ڿ�����󣬺��治�Ჹһ��\0
	//ͨ�����Թ۲���,arr1�����ݱ仯 - arr1:"hellef\0\0\0\0"

	char arr3[10] = "abcdefgh";
	char arr4[] = "bit";
	my_strncpy(arr3, arr4, 6);//�����������ֽڣ���'\0'���
	//ͨ�����Թ۲���,arr1�����ݱ仯 - arr1:"bit\0\0\0gh\0\0"

	//ע�⣺����0����Ҳ����
	return 0;
}
*/
//�鿴Դ�룺�ڰ�װ·���µ�VC/crt/src�в鿴
//ע�⣺strncpy��ʵ��Ҳ���Բο�memcpyʵ�֡���һ���ֽ�һ���ֽڵĿ���

//2��strncat
//char* strncat(char* destination, const char* source, size_t num);��Դ�ַ���ǰnum���ַ�(�ֽ�)׷�ӵ�Ŀ��ռ䡣
//Appends the first num characters of source to destination, plus a terminating null - character.
//If the length of the C string in source is less than num, only the content up to the terminatingnull - character is copied.
//ע�⣺
//1��num��λ���ֽ�
//2�����ֵ�׷����󣬻���Ŀ�ĵؿռ����������һ��\0
//3�����ֵ�Դ�ַ���׷�ӵ��ַ���������Դ�ַ����ĳ��ȣ���Դ�ַ���׷����󣬲�����\0
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
	char arr2[] = "world";
	strncat(arr1, arr2, 3);// - hellowor\0xxxxxxxxxxx
	//���Թ۲��������ֵ�׷����󣬻���Ŀ�ĵؿռ����������һ��\0
	char arr3[30] = "hello\0xxxxxxxxxxxxxx";
	char arr4[] = "world";
	strncat(arr3, arr4, 8);// - helloworld\0xxxxxxxxx
	//���Թ۲��������ֵ�Դ�ַ���׷�ӵ��ַ���������Դ�ַ����ĳ��ȣ�������\0
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20];
    char str2[20];
    strcpy(str1, "To be ");
    strcpy(str2, "or not to be");
    strncat(str1, str2, 6);
    puts(str1);//дһ���ַ�������׼������У����Զ�����(���ջس���)��
	//��getchar��putchar�Աȣ����������ƪ-1��whileѭ����䡱
	//��gets��puts��scanf�Աȣ������test11.c����test12.c��
	//scanf��������ո���ַ����������test9.c��
	//ͬʱ����MSDN�Ƚ�
    return 0;
}
*/

//ģ��ʵ��strncat
//ԭ��һ���ַ�һ���ַ���׷��
//numС��Դ�ַ������ȣ������count��ǰΪ0�������׷�ӣ��ټ���׷��һ��'\0'��
//num����Դ�ַ������ȣ������countû����ǰΪ0����׷�ӵ�Դ�ַ���������('\0')��Ҳ�ټ���׷��һ��'\0'
#include <stdio.h>
#include <assert.h>
/*
char* my_strncat(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	//׷��3���ֽ�
	//abcdefgh\0xxxxxxxx\0
	//hello\0
	//abcdefghhel\0xxxxx\0
	//׷��8���ֽ�
	//abcdefgh\0xxxxxxxx\0
	//hello\0
	//abcdefghhello\0xxx\0
	char* ret = strDest;
	//�ҵ�Ŀ���ַ�����'\0'
	while (*strDest != '\0')
		strDest++;
	while (count)
	{
		*strDest++ = *strSource++;//��һ���ַ���\0,��û�и�ֵ��strDest
		count--;
		if (*strSource == '\0')
			break;
	}
	//count��ǰ������countû����ǰ������������\0����
	*strDest = '\0';
	return ret;
}
*/
/*
char* my_strncat(char* strDest, const char* strSource, int count)
{
	assert(strDest && strSource);
	char* ret = strDest;
	//�ҵ�Ŀ���ַ�����'\0'
	while (*strDest++)
		;
	strDest--;//����while (*strDest++)�����һ�Σ���Ҫ--��ȥ
	//while (count && (*strDest++ = *strSource++))//���ﵱcount��Ϊ0ʱ��(*strDest++ = *strSource++)��ִ����һ�Σ�*strDest��ֵ��һ��\0
	//{
	//	count--;
	//}
	//*strDest = '\0';//�����ֶ�ִ����һ�Σ���������������\0

	while (count--)
	{
		if (!(*strDest++ = *strSource++))//�����ж�ִ����һ��
			return ret;
	}
	*strDest = '\0';
	return ret;
}
int main()
{
	char arr1[30] = "hello\0xxxxxxxxxxxxxx";
	char arr2[] = "world";
	my_strncat(arr1, arr2, 3);// - hellowor\0xxxxxxxxxxx
	//���Թ۲��������ֵ�׷����󣬻���Ŀ�ĵؿռ����������һ��\0
	char arr3[30] = "hello\0xxxxxxxxxxxxxx";
	char arr4[] = "world";
	my_strncat(arr3, arr4, 8);// - helloworld\0xxxxxxxxx
	//���Թ۲��������ֵ�Դ�ַ���׷�ӵ��ַ���������Դ�ַ����ĳ��ȣ�������\0

	//ע�⣺׷��0����Ҳ����
	return 0;
}
*/
//�鿴Դ�룺�ڰ�װ·���µ�VC/crt/src�в鿴

//3��strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );�Ƚ�ǰnum���ַ�(�ֽ�)
//ע�⣺
//1��num��λ���ֽ�
//2��strncmp�ķ���ֵ�趨��strcmp��ͬ
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	int ret = strncmp(arr1, arr2, 3);
	printf("%d\n", ret);

	char arr3[] = "abcdef";
	char arr4[] = "abcdef";

	ret = strncmp(arr3, arr4, 8);
	printf("%d\n", ret);

	char arr5[] = "abcd";
	char arr6[] = "abcdef";

	ret = strncmp(arr5, arr6, 8);
	printf("%d\n", ret);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts("��R2��ͷ���ַ���...");//�Զ�����
    for (n = 0; n < 3; n++)
        if (strncmp(str[n], "R2xx", 2) == 0)
        {
            printf("found %s\n", str[n]);
        }
    return 0;
}
*/

//ģ��ʵ��strncmp
//ԭ��һ���ַ�һ���ַ��ıȽ�
//numС��Դ�ַ������ȣ������count��ǰΪ0��������Ƚϣ�
//num����Դ�ַ������ȣ������countû����ǰΪ0����Ƚϵ�Դ�ַ���������('\0')��������Ƚ�
#include <stdio.h>
#include <assert.h>
/*
int my_strncmp(const char* string1, const char* string2, int count)
{
	//�Ƚ�3���ַ�
	//abcdef\0
	//abcabc\0
	//����0
	//�Ƚ�8���ַ�
	//abcdef\0
	//abcabc\0
	//����d-a
	//abcdef\0
	//abcdef\0
	//����0
	assert(string1 && string2);
	while (count != 0)
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
			count--;
			if (*string2 == '\0')
				break;
		}
		else
		{
			return *string1 - *string2;
		}
	}
	
	//countû����ǰ����
	if (count != 0)
	{
		if (*string1 != *string2)
		{
			return *string1 - *string2;
		}
	}

	//count��ǰ�����ˣ�countû����ǰ������������\0����
	return 0;
}
*/
/*
int my_strncmp(const char* string1, const char* string2, int count)
{
	assert(string1 && string2);
	if (count == 0)
		return 0;
	//while (count && *string1 == *string2)//��·Ч��
	//{
	//	string1++;
	//	string2++;
	//	count--;
	//	if (*string2 == '\0')
	//		break;
	//}
	while (--count && *string1 && *string1 == *string2)//��·Ч��
	{
		string1++;
		string2++;
	}
	//count��ǰ�����ˣ�countû����ǰ������������\0����
	return *string1 - *string2;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	int ret = my_strncmp(arr1, arr2, 3);
	printf("%d\n", ret);

	char arr3[] = "abcdef";
	char arr4[] = "abcdef";

	ret = my_strncmp(arr3, arr4, 8);
	printf("%d\n", ret);

	char arr5[] = "abcd";
	char arr6[] = "abcdef";

	ret = my_strncmp(arr5, arr6, 8);
	printf("%d\n", ret);

	//ע�⣺�Ƚ�0����Ҳ����
	return 0;
}
*/

//�ġ��ַ�������strstr��strtok
//1��strstr�����ַ���
//char* strstr(const char* str1, const char* str2);
//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
//ע�⣺�ĵ��е�NULL��ʾ��ָ�룬��NUL��null��'\0'��ʾ'\0'
//1����str1���У������Ӵ�str2
//2�����ز��ҵ��ĵ�һ���Ӵ���Ԫ�صĵ�ַ
//3�����str2Ϊ�մ����򷵻�str1����Ԫ�ص�ַ
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char* p1 = "abcdef";
	char* p2 = "def";
	char* ret = strstr(p1, p2);//�����Ӵ���Ԫ�صĵ�ַ
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);//def

	char* p3 = "abcdefghi";
	char* p4 = "def";
	ret = strstr(p3, p4);//strstr����ҵ����Ӵ������صĸ��Ӵ���Ŀ�ĵؿռ���Ӵ���Ԫ�صĵ�ַ�����򷵻�NULL��ָ��
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);//defghi - �����Ӵ���Ԫ�صĵ�ַ�����׵�ַ��ʼ��ֱ��\0����

	char* p5 = "abcdefabcdef";
	char* p6 = "def";
	ret = strstr(p5, p6);//���ص�һ���Ӵ���Ԫ�صĵ�ַ
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);//defabcdef

	char* p7 = "abcdefabcdef";
	char* p8 = "";
	ret = strstr(p7, p8);//���ص�һ���Ӵ���Ԫ�صĵ�ַ
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("[%s]\n", ret);//[abcdefabcdef]
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "This is a simple string";
	char* pch;
	pch = strstr(str, "simple");
	if(pch != NULL)//ָ��ʹ��ǰ��Ҫ�ж���Ч��
		strncpy(pch, "sample", 6);
	puts(str);
	return 0;
}
*/

//ģ��ʵ��strstr
//ԭ����Ŀ�ĵؿռ��ҵ���Դ�ַ�����Ԫ����ͬ���ַ���������ͬ����Ŀ�ĵ�ָ��++��ֱ���ҵ���Ȼ��Դ�ַ�����Ŀ�ĵ��ַ����ĵ�ַͬʱ�ң�
//1��str1��ǰ����\0��str1�������ˣ�����ҽ�����û�ҵ�����abc abcdef	
//2��str2��ǰ����\0��str2ƥ�����ˣ�����ҽ������ҵ��ˡ���abcdef def 
//3��str1��str2����ȣ�ƥ�������˵����d��ʼ�ĵ�ַ��û�в��ҵ��Ӵ�����d/b��һ����ַ������ʼ������һ�ֲ��ҡ���abcdeqwer def�� abbbcdef bbc
#include <stdio.h>
#include <assert.h>
/*
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);//p1����Ϊ��ָ��
	assert(p2 != NULL);//p2����Ϊ��ָ��
	char* s1 = NULL;//���ڼ�¼p1�ı仯���ع�ָ�뵽cur(����ֱ��ʹ��p1����Ϊcur��¼��p1)
	char* s2 = NULL;//���ڼ�¼p2�ı仯����ֹp2�����仯�������޷��ع�ָ�뵽p2
	char* cur = (char*)p1;//������¼Ŀ�ĵ��ַ����У������ַ���һ��ƥ��ɹ����ַ���ַ
	//�ж�p2�Ƿ�Ϊ���ַ������մ�ֻ��һ��\0
	if (*p2 == '\0')//��if(!*p2)
		return (char*)p1;//p1��const char*������char*������ǿת����ᱨ����
	//abcdef  def
	while (*cur)//p1�����ǿմ��������޷���p1�в���p2�Ӵ�
	{
		//�磺abbbcdef bbc
		s1 = cur;//�����һ�β���ʧ�ܣ��ڶ��δ�cur����һ��λ������ƥ����ң�p1ָ��ع鵽cur����һ��λ��(cur++)
		s2 = (char*)p2;//p2ָ��ع鵽��ʼλ��
		while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//s1�ַ���s2�ַ�ͬʱ�ң���·Ч������countΪ0ֱ�Ӳ�����ѭ����
		//1��p1��ǰ����\0��p1�������ˣ�����ҽ�����û�ҵ�����abc abcdef	
		//2��p2��ǰ����\0��p2ƥ�����ˣ�����ҽ������ҵ��ˡ���abcdef def 
		//3��p1��p2����ȣ�ƥ�������˵����d��ʼ�ĵ�ַ��û�в��ҵ��Ӵ�����d/b��һ����ַ������ʼ������һ�ֲ��ҡ���abcdeqwer def�� abbbcdef bbc
		{
			s1++;
			s2++;
		}
		//����������һ������ѭ������������������
		if (*s2 == '\0')//�磺abc abc��abcd abc
			return cur;//�ҵ��Ӵ�
		//�磺abcdef  gi
		//��ÿһ�ζ�û�ҵ��Ӵ���Ŀ���ַ�������\0��û���ҵ���������ǰ����\0
		if (*s1 == '\0')//�������ж�˳���ܷ����磺abc abc
			return NULL;
		
		//p1��p2����ȣ�++��ֱ����ȣ�cur��������׸���ͬ�ַ��ĵ�ַ
		cur++;
	}
	//p1Ϊ�մ�
	return NULL;
}
*/
/*
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* s1 = NULL,* s2 = NULL;
	char* cur = (char*)str1;
	if (!*str2)//*str2 == '\0'Ϊ�档*str2Ϊ0��!*str2Ϊ��
		return (char*)str1;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2))//*s1 != '\0'Ϊ�档*s1��Ϊ0��*s1Ϊ��
		{//*s1 == *s2Ϊ�档*s1 - *s2Ϊ0��!(*s1 - *s2)Ϊ��
			s1++;
			s2++;
		}
		if (!*s2)
			return cur;

		//if (*s1 == '\0')
		//	return NULL;
		//�����п��Բ�Ҫ��ֻ�Ǽ��Ͽ�����ǰ��ֹѭ������������м�����Чѭ��
		cur++;
	}
	return NULL;
}
int main()
{
	//ע��p1Ϊ�մ����򷵻�NULL
	char* p1 = "abcdefabcdef";
	//char* p2 = "";//p2Ϊ�մ�
	char* p2 = "def";
	char* ret = my_strstr(p1, p2);
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);

	char* p3 = "abbbcdef";
	char* p4 = "bbc";
	ret = my_strstr(p3, p4);
	if (ret == NULL)
		printf("�Ӵ�������\n");
	else
		printf("%s\n", ret);//ע�⣺��ӡ�ַ�������ӡ���Ǵ���ʼ��ַ��ʼ��ֱ����һ��\0�����������ַ�
	return 0;
}
*/
//�˽�KMP�㷨  - ���ݽṹ(C���԰�)�廪��ѧ-P80

//2��strtok�ַ����ָ��
//char * strtok ( char * str, const char * sep );
//ע�⣺
//1���ڶ�������sep���ַ�������ʼ��ַ��ָ����ַ��������������ָ������ַ�����
//2����һ������strָ��һ���ַ�������ʼ��ַ����������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
//strtok�������÷���
//�磺str: "zpw@bitedu.tech"    sep: "@."
//��һ�ε���strtok����ʱ����"zpw@bitedu.tech"����'@'��Ȼ����\0���������(ͬʱ��ס��ǵ�λ��)������ָ�������ǵ���ʼ��ַ��ָ��"zpw"
//�ڶ��ε���strtok����ʱ����"bitedu.tech"����'.'��Ȼ����\0���������(ͬʱ��ס��ǵ�λ��),����ָ�������ǵ���ʼ��ַ��ָ��"bitedu"
//�����ε���strtok����ʱ����"tech"����'.'��Ȼ����\0���������(ͬʱ��ס��ǵ�λ��),����ָ�������ǵ���ʼ��ַ��ָ��"tech"
//��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����з��ַ���ʱ��һ�㸴��һ����ʱ���������ݣ������϶�������޸ġ���
//3��strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�(��static��̬������ס��ǵ�λ��)
//������һ�ε���strtok����ʱ����һ�������������str(�ǿ�)
//4��strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
//�����ڶ��μ�֮�����strtok����ʱ����һ�������������NULL
//��ע����һ����������һ�δ��ַ������׵�ַ���ڶ����Լ�֮��NULL��
//5������ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
//���������еı�Ƕ��ҵ����ٵ���strtok�������᷵��NULL
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = "2946053797@qq.com";
    char* p = "@.";
    char buf[1024] = { 0 };
    strcpy(buf, arr);//�����ݿ���һ�ݣ�����buf���������

    //�и�buf�е��ַ���
    char* ret = strtok(buf, p);
    printf("%s\n", ret); //2946053797

    ret = strtok(NULL, p);
    printf("%s\n", ret);//qq

    ret = strtok(NULL, p);
    printf("%s\n", ret);//com

	ret = strtok(NULL, p);
	printf("%s\n", ret);//null
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[] = "192.168.33.128";
	//char arr[] = "123@123.@123";//[123] [123] [123],û��[]
    char* p = ".";
    char buf[1024] = { 0 };
    strcpy(buf, arr);//�����ݿ���һ�ݣ�����buf���������
    //�и�buf�е��ַ���
    char* ret = NULL;//����strtok�����ķ���ֵ

    for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
    {//ret = strtok(buf, p)ֻ��ִ��һ��
        printf("%s\n", ret);
    }
	//˼��һ�£��ڶ��μ��Ժ����strtok�����������֪���и�˭
	//�����ڲ����¼��ǵ�λ�õ�ָ�룬�Ҹ�ָ�����С����䡱���ܣ���staticָ�����
    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "- This, a sample string.";
    char* pch;
    printf("Splitting string \"%s\" into tokens:\n", str);
    pch = strtok(str, ",.- ");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, ",.- ");
    }
    return 0;
}
*/

//�塢������Ϣ���溯��strerror��
//char * strerror ( int errnum );
//errnum������
//���ã����ش���������Ӧ�Ĵ�����Ϣ��
//ע�⣺
//����ͷ�ļ� #include <errno.h>
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>//���������ͷ�ļ�
int main()
{
    //������      �������Ӧ�Ĵ�����Ϣ
    //0           No error
    //1           Operation not permitted
    //2           No such file or directory
    //...
    char* str = strerror(0);
    printf("%s\n", str);

    char* str = strerror(1);
    printf("%s\n", str);

    char* str = strerror(2);
    printf("%s\n", str);

    return 0;
}
*/

//strerror��ʹ�ó�����
//���ڵ��ú���ʱ�����صĽ�����ܲ���������ϣ���ģ����ʱ���ӡ��errno��Ӧ����Ϣ���鿴����ԭ��
/*	 char* str = strerror(errno);	*/
//errno��һ��ȫ�ֵĴ�����ı���
//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ������errno�У���ʱ, ͨ���鿴errno��������Ϣ��֪���������ԭ��
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>//���������ͷ�ļ�
int main()
{
    //���ļ�fopen("�ļ���.��׺","r")   r��ʾ���ļ�  w��ʾд�ļ�������д����Ĭ�ϴӵ�ǰ��Ŀ����·�����Ҹ��ļ�
    //fopen������ļ����ڣ�����һ��FILE*���͵�ָ�룬����ļ������ڣ��򷵻�NULL
    FILE* pf = fopen("test.txt", "r");//fopen��·�������·��
	//FILE* pf = fopen("D:\\VS2019\\code\\����\\3������\\3������\\test12.txt", "r");//fopen��·���Ǿ���·����ע���ļ���֮��ķָ���\��ת��\\
	//FILE* pf = fopen("D:\\VS2019\\code\\����\\3������\\3������\\test12.txt", "r");
	//FILE* pf = fopen("D:/VS2019/code/����/3������/3������/test12.txt", "r");//fopen��·���Ǿ���·����ע���ļ���֮��ķָ���/������Ҫת��
	if (pf == NULL)
        printf("open file filed: %s\n", strerror(errno));//���ļ���ʧ�ܺ�(�����˴���)���ͻ�Ѷ�Ӧ�Ĵ����븳ֵ������errno��
	//ע�⣺ѡ��errnoת�����壬���Բ鿴������
    else
        printf("open file success\n");
    return 0;
}
*/

//�����ַ�����
//ע�⣺
//���º�������ͷ�ļ� #include <errno.h>
//1���ַ����ຯ�����ж��ַ��Ƿ����ڸ����ַ�
/********************************************************************************************
	����			������Ĳ����������������ͷ�����(��0)������Ϊ�ٷ���0
	iscntrl			�κο����ַ�
	isspace			�հ��ַ����ո�' '����ҳ'\f'������'\n'���س�'\r'���Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
	isdigit			ʮ�������� 0~9
	isxdigit		ʮ���������֣���������ʮ�������֣�Сд��ĸa~f����д��ĸA~F
	islower			Сд��ĸa~z
	isupper			��д��ĸA~Z
	isalpha			��ĸa~z��A~Z
	isalnum			��ĸ�������֣�a~z, A~Z, 0~9
	ispunct			�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
	isgraph			�κ�ͼ���ַ�
	isprint			�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
**********************************************************************************************/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch = 'w';
    int ret = islower(ch);
    printf("%d\n", ret);
    return 0;
}
*/

//2���ַ�ת������
//int tolower(int c);����ĸתСд
//int toupper(int c);����ĸת��д
//ע�⣺Сдת��д -32 ��дתСд +32
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch = tolower('Q');
    putchar(ch);//���һ���ַ�
    return 0;
}
*/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char arr[] = "I Am A Student";
	for (int i = 0; i < strlen(arr); i++)
	{
		if (islower(arr[i]))//�ж�Сд��ĸ
			arr[i] = toupper(arr[i]);
	}
	printf("%s\n", arr);
	
	while (arr[i])
	{
		if (isupper(arr[i]))
			arr[i] = tolower(arr[i]);
		i++;
	}
    printf("%s\n", arr);
    return 0;
}
*/
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0;
    char str[] = "Test String.\n";
    char c;
    while (str[i])
    {
        c = str[i];
        if (isupper(c))
            c = tolower(c);
        putchar(c);
        i++;
    }
    return 0;
}
*/

//�ߡ��ڴ��������memcpy��memmove��memset��memcmp
//����ѧ����strlen��strcpy...�Ⱥ��������Ķ������ַ����������ʵ�ֲ�ͬ����֮��Ĳ����أ�
//��ʱ������Ҫʹ�õ��ڴ�������������ڿ��Բ����������͵����ݣ����Ժ����βε���������Ϊvoid*
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	//char* dest,const char* src
	strcpy(arr2, arr1);//�����棬���Ͳ����ݣ���Ϊ���������������int[5]
	//���Թ۲�arr1 arr2�ı仯
	return 0;
}
*/
//arr1����Ԫ�����ڴ��еľֲ���
//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//strcpy���ַ�һ��һ���Ŀ�����Ŀ�ĵؿռ䣬�ʻ��01������arr2�С���������00��'\0'����\0������arr2�󣬾ͻ�������ʽ��Ϊ1
//ע�⣺�ַ������������ڴ�������������𣺽�����������ͬ
//1���ַ�������������һ���ֽ�һ���ֽڵĲ�����������'\0'��0��ֹͣ����
//2���ڴ������������һ���ֽ�һ���ֽڵĲ�������������num���ֽں�ֹͣ����

//1��memcpy�ڴ濽��
//ԭ����num���ֽڣ�һ���ֽ�һ���ֽڵĴ�source������destination�С�������num���ֽڣ�Ȼ��ֹͣ����
/*
//������ͨ��������
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));//�ȼ�memcpy(arr2, arr1,5*sizeof(int));��memcpy(arr2, arr1, 25);
	//���Թ۲�arr1 arr2�ı仯
	return 0;
}
int main()
{
	char arr1[] = "abcd";
	char arr2[5] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));//�ȼ�memcpy(arr2, arr1,strlen(arr1)+1);��\0Ҳ������ȥ
	//���Թ۲�arr1 arr2�ı仯

	char arr3[] = { 'a','b','c','d' };
	char arr4[5] = { 0 };
	memcpy(arr4, arr3, 3);//ֻ����3���ֽ�
	//���Թ۲�arr3 arr4�ı仯
	return 0;
}
*/
/*
//�����Զ�����������
#include <stdio.h>
#include <string.h>
struct S
{
	char name[20];
	int age;
};
int main()
{
	struct S arr1[] = { {"����",20},{"����",30} };
	struct S arr2[3] = { 0 };
	memcpy(arr2, arr1, sizeof(arr1));
	//���Թ۲�arr1 arr2�ı仯
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
struct {
	char name[40];
	int age;
} person, person_copy;
int main()
{
	char myname[] = "Pierre de Fermat";
	// using memcpy to copy string: 
	memcpy(person.name, myname, strlen(myname) + 1);//��\0Ҳ������ȥ
	person.age = 46;
	// using memcpy to copy structure: 
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	return 0;
}
*/

//memcpy������
//void * memcpy ( void * destination, const void * source, size_t num );��source��num���ֽڿ�����destination��
//ע�⣺
//1��num�ĵ�λ�ֽ�
//2�����������������strncpy����
//3������memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
//4��������������� '\0' ��ʱ�򲢲���ͣ������
//5�����source��destination���κε��ص������ƵĽ������δ����ġ�

//ģ��ʵ��memcpy
//ԭ����num���ֽڣ�һ���ֽ�һ���ֽڵĴ�source������destination�С�������num���ֽڣ�Ȼ��ֹͣ����
/*
#include <stdio.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{//void*���͵ı������ܽ����ò���������++����������+/-��������
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//����dest����ʼ��ַ
	while (num--)
	{
		//��Դ�ռ�����ݰ��ֽ�һ��һ���ķ���Ŀ�ĵؿռ䣬��Ҫ��num�ֽڸ�����
		*(char*)dest = *(char*)src;//ǿתΪchar*, ����ʵ��һ���ֽ�һ���ֽڵĿ���
		++(char*)dest;//ͬһ���ȼ������������ϣ�����((char*)dest)++
		++(char*)src;
		//���ϴ������ֱ��д��*((char*)dest)++ = *((char*)src)++
	}
	return ret;//����dest����ʼ��ַ
}
struct S
{
	char name[20];
	int age;
};
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));
	struct S arr3[] = { {"����",20},{"����",30} };
	struct S arr4[3] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	//ͨ�����Թ۲���
	return 0;
}
*/

//˼���⣺
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//ʹ��my_memcpy������1 2 3 4 5������3 4 5 6 7��
/*
#include <stdio.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;//����dest����ʼ��ַ�������char* ret���գ�����dest�Ϳ��Բ���Ҫǿת
	while (num--)
	{
		//��Դ�ռ�����ݰ��ֽ�һ��һ���ķ���Ŀ�ĵؿռ䣬��Ҫ��num�ֽڸ�����
		*(char*)dest = *(char*)src;
		++(char*)dest;//ͬһ���ȼ������������ϣ�����((char*)dest)++
		++(char*)src;
		//ֱ��д��*((char*)dest)++ = *((char*)src)++
	}
	return ret;//����dest����ʼ��ַ
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memcpy(arr+2, arr, 20);//��1 2 3 4 5������3 4 5 6 7��
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	//�����Ԥ�ڵĲ�һ����Ϊʲô��
	//1  2  3  4  5  6  7  8  9  10
	//      1  2  3  4  5			//����
	//      1  2  1  2  1
	//����1��2������3��4��
	//��ʱ���ڽ�3��������5���ͱ���˽�1����5������4����6���ͱ���˽�2����6������5����7����ɽ�1����7��
	return 0;
}
*/
//��ν�1 2 3 4 5������3 4 5 6 7 ������
//1���Ӻ���ǰ����
//1  2  3  4  5  6  7  8  9  10
//      1  2  3  4  5
//5������7�ϣ�4������6�ϣ�3������5�ϣ�2������4�ϣ�1������3��
//��ν�3 4 5 6 7������1 2 3 4 5 ������
//2����ǰ���󿽱�
//1  2  3  4  5  6  7  8  9  10
//3  4  5  6  1
//�����Բ�ͬ�Ŀ�����Ҫ��ͬ�Ŀ���˳�������memmove()������

//2��memmove�ڴ��ƶ�
//���ã������ڴ��ص��ĸ�������
//ԭ����num���ֽڣ�һ���ֽ�һ���ֽڵĴ�source������destination�С�������num���ֽڣ�Ȼ��ֹͣ����
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memmove(arr+2, arr, 20);//��1 2 3 4 5������3 4 5 6 7��
	memcpy(arr+2, arr, 20);
	//ʹ�ñ�׼��memcpyҲ��������
	//C���Ա�׼�涨��
	//memcpy�����Ĺ��ܣ�ֻҪ�����ص����ڴ濽���Ϳ��ԡ���ǰVS��������memcpy���ܸ�ǿ�󣬵���һ���������е�ƽ̨
	//memmove�����Ĺ��ܣ����ڴ����ص��ڴ�Ŀ���
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}
*/

//memmove������
//void * memmove ( void* destination, const void* source, size_t num );��source��num���ֽڿ�����destination��
//ע�⣺
//1��num��λ���ֽ�
//2����memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
//3�����Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������

//ģ��ʵ��memmove
//ԭ����num���ֽڣ�һ���ֽ�һ���ֽڵĴ�source������destination�С�������num���ֽڣ�Ȼ��ֹͣ����
//1����dest < srcʱ��src�е�����Ӧ�ô���ǰһ�����ݿ�ʼ�������ο�����dest��
//2����src < dest < src+numʱ��src�е�����Ӧ�ô�������ݿ�ʼ��ǰ���ο�����dest��
//3����dest > srcʱ�������ص�������src�е����ݿ�����dest�п��Դ�ǰ����Ҳ���ԴӺ���ǰ
//���裺Ҫ��srcԴ�ռ��4 5 6 7 8������Ŀ�ĵ�dest�ռ�
//1 2 3 4 5 6 7 8 9 10
//�����4 5 6 7 8������srcԴ�ռ�����ʱ����dest<srcʱ����4��ʼ�������ο���
//�������4 5 6 7 8������srcԴ�ռ���ұ�ʱ����8��ʼ��ǰ���ο���
//�������4 5 6 7 8������srcԴ�ռ�����˵��ұ�ʱ����ǰ���󿽱������ߴӺ���ǰ��������
//��һ�֣���1��Ϊһ�������2��3�ϲ�
//if(dest<src){ǰ-��}else{��-ǰ}
//�ڶ��֣���2��Ϊһ�������1��3�ϲ�
//if(dest<src || dest>(char*)src+count){ǰ-��}else{��-ǰ}
//ע�⣺�߽�ֵ���Է�������һ��������档
/*
#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* ret = dest;
	if (dest < src)//void*���ͱȽϵ�ʱ�򣬲��ᱨ����
	{
		//ǰ - ��
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//�� - ǰ
		//���裺��34567 ������56789
		//03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00 07 00 00 00 08 00 00 00 09 00 00 00 0a 00 00 00
		//�Ƚ�07 00 00 00 ���򿽱���09 00 00 00����
		//һ���ֽ�һ���ֽڵĿ��������7�����һ���ֽ�00��ʼ��������9�����һ���ֽ�00��
		//(char*)src + 20 -1��Ϊ7�����һ���ֽ�00�ĵ�ַ
		//(char*)dest + 20 -1��Ϊ9�����һ���ֽ�00�ĵ�ַ
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);//while(count){ *((char*)dest + count-1) = *((char*)src + count-1); count--; }
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);//��1 2 3 4 5������3 4 5 6 7 8��
	
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//3��memcmp�ڴ�Ƚ�
//int memcmp(const void* ptr1,const void* ptr2,size_t num);��source��num���ֽ���destination�Ƚ�
//ԭ����num���ֽڣ�һ���ֽ�һ���ֽڵĴ�source��destination�С��Ƚ���num���ֽڣ�Ȼ��ֹͣ�Ƚ�
//ע�⣺
//1��num��λ���ֽ�
//2���Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�
//3������ֵ���趨��strcmp��ͬ
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,5,4,3 };
	//arr1��arr2���ڴ��еĲ���
	//arr1��01 00 00 00 02 00 00 00 ...
	//arr2��01 00 00 00 02 00 00 00 ...
	int ret = memcmp(arr1, arr2, 8);//�Ƚ�ǰ8���ֽ�
	printf("%d\n", ret);

	//arr1��arr2���ڴ��еĲ���
	//arr1��01 00 00 00 02 00 00 00 03 00 00 00 ...
	//arr2��01 00 00 00 02 00 00 00 05 00 00 00 ...
	ret = memcmp(arr1, arr2, 9);//�Ƚ�ǰ9���ֽ�
	printf("%d\n", ret);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n > 0) 
		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n < 0) 
		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else 
		printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int size = sz;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	while (1)
	{
		printf("������Ҫɾ��������");
		scanf("%d", &num);//2

		int i = 0;
		for (i = 0; i < size - 1; i++)//arr[i+1]  i==9Խ��
		{
			if (arr[i] == num)//i == 2�ǵ�����Ԫ��  *(arr+i) == arr[i] 
			{
				memmove(arr + i, arr + i + 1, (size - i - 1) * sizeof(int));//10 - 2 - 1
				size--;
				break;
			}
		}

		if (i == size - 1)//��������һ��Ԫ��
		{
			if (arr[i] != num)//û�ҵ�
			{
				printf("Ҫɾ������������\n");
				continue;
			}
			//�ҵ���
			size--;
		}
		for (int i = 0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
*/

//4��memset�ڴ�����
//void* memset(void* dest, int c, size_t num);
//The memset function sets the first count bytes of dest to the character c.����destǰnum���ֽ�Ϊ�ַ�c
//����dest��Pointer to destinationҪ���õ�ָ��Ŀ�ĵ�ַ��ָ��
//����c��Character to setҪ���õ��ַ�
//����ֵ��memset returns the value of dest.�������ú��Ŀ�ĵ�ַ
//���ã���ʼ������
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[10] = "";//���е�Ԫ�س�ʼ��Ϊ0(\0)
	memset(arr1, '#', 10);//��arr��ǰ10���ֽ�����Ϊ#
	//���Թ۲�arr1

	int arr2[10] = { 0 };//���е�Ԫ�س�ʼ��Ϊ1.int arr2[10] = { 1 };ֻ�Ὣ��һԪ�س�ʼ��Ϊ1��ʣ��Ԫ�ض�Ϊ0
	//����Ԫ������ΪintĬ�ϳ�ʼ��Ϊ0��doubleĬ�ϳ�ʼ��Ϊ0.00000000��charĬ�ϳ�ʼ��Ϊ'\0'
	memset(arr2, 1, 10);//��arr��ǰ10���ֽ�����Ϊ1
	//���Թ۲�arr2
	//arr2��40���ֽڣ�arr2���ڴ��еĲ���
	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 00 00 00 00...
	//ǰ10�ֽڣ�������Ϊ��1
	//arr[0] = 0x01010101 == 16843009
	//arr[1] = 0x01010101 == 16843009
	//arr[2] = 0x01010000 == 257
	return 0;
}
*/
//���ԣ���ѧϰ���˽�⺯��
//https://cplusplus.com/reference/clibrary/

//��ҵ
//1��ģ��ʵ��strstr
//2��ģ��ʵ��memcpy
//3��ģ��ʵ��memmove
//4�����ô�����ϰ�뱾���ⲩ��(���ô���ı�д���漰���ĺ���֪ʶ�������Բ������ӷ�ʽ)