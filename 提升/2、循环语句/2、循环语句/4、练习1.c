#define _CRT_SECURE_NO_WARNINGS 1
/*1������n�Ľ׳ˡ������������������*/
//˼·��n!=1*2*3*4*5...*n������1-n�����֣��ۻ��˵�һ��
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int ret = 1;//��ʼֵ���ܸ�ֵΪ0
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        ret = ret * i;
//    }
//    printf("ret = %d\n", ret);
//
//    return 0;
//}

/*2������1!+2!+3!+......+10!*/
//˼·���ֱ�������ԵĽ׳ˣ��������ۼ�����
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int ret = 1;
//    int sum = 0;
//	//ѭ���ۼ�10��
//    for (n = 1; n <= 3; n++)
//    {
//        //n�Ľ׳�
//        for (i = 1; i <= n; i++)
//        {
//            ret = ret * i;
//        }
//		  //n�׳˵ĺ�
//        sum = sum + ret;
//    } 
//    printf("sum = %d\n", sum);
//    return 0;
//}
//�����
//1!+ 2!+ 3! = 1 + 2 + 6 =9 ��=15
//���������
//ret =1��n = 1��i = 1��ret = ret * i = 1 * 1 = 1��sum = 0 + 1 = 1��1��= 1
//ret =1��n = 2��i = 1��ret = ret * i = 1 * 1 = 1
//				 i = 2��ret = ret * i = 1 * 2 = 2��sum = 1 + 2 = 3��2��= 3
//ret =2��n = 3��i = 1��ret = ret * i = 2 * 1 = 2
//				 i = 2��ret = ret * i = 2 * 2 = 4
//				 i = 3��ret = ret * i = 4 * 3 =12��sum = 3 +12 =15��3��=15
//ret = 1*1=1
//ret = 1*1*2=2
//ret = 2*1*2*3=12
//ret��һֱ�ۼ�

//�����޸ģ�
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int sum = 0;
//	  int ret = 1;
//    //ѭ���ۼ�10��
//    for (n = 1; n <= 3; n++)
//    {
//        ret = 1;//����n�Ľ׳�֮ǰ����ret�ó�1
//        //n�Ľ׳�
//        for (i = 1; i <= n; i++)
//        {
//            ret = ret * i;
//        }
//        //n�Ľ׳˵ĺ�
//        sum = sum + ret;
//    }
//    printf("sum = %d\n", sum);
//    return 0;
//}

//�����Ż���
//˼·��
		//1! = 1
		//2! = 1! * 2
		//3! = 2! * 3
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int ret = 1;
//    int sum = 0;
//    //ѭ���ۼ�10��
//    for (n = 1; n <= 3; n++)
//    {
//		  //n�Ľ׳�
//        ret = ret * n;
//		  //n�Ľ׳˵ĺ�
//        sum = sum + ret;
//    }
//    printf("sum = %d\n", sum);
//    return 0;
//}

/*3����һ�����������в��Ҿ����ĳ������n����дint binsearch(int x, int v[, int n);���ܩU��v[0]<=v[1]<=v[2]<= ....<=v[n-1]�������в���x.*/
//˼·���������е�Ԫ����Ҫ���ҵ�����һһ�Ա�
//����һ�����������Ԫ��--�������������򶼿���
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//��arr[]�����������ҵ�7
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//���������Ԫ�ظ���
//	for (i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("�ҵ���.�±���:.%d \n", i); 
//			break;
//		}
//	}
//	//��������
//	if (i == sz)//�����е�Ԫ�ض�����һ���û�ҵ�
//		printf("�Ҳ��� \n");
//	return 0 ;
//}

//˼·���м�Ԫ����Ҫ���ҵ����Ƚ�
//�����������ֲ��ҷ�/�۰�����㷨
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 7;//Ҫ���ҵ�Ԫ��
//  //��Ԫ�ظ�����Ϊ�±겻����
//	int left = 0;//���±�
//	//����Ԫ�ظ�����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;//���±ꡣ�˷���ֻ�����������int arr[] = { 1,2,3,4,5,6,7,8,9,10 };�ĳ�ʼ�����������±�
//	int mid = 0;//�м�Ԫ���±�
//
//	while (left <= right)//ע��ѭ��������
//	{//Ҫѭ�����ֲ��ҵĶ���
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;		
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			//�����±����
//			printf("�ҵ���,�±���%d\n", mid);
//			break;
//		}
//	}
//	//��������
//	if(left > right)
//		printf("�Ҳ���\n");
//	return 0;
//}

//��������
//ʵ��һ�����ֲ��Һ�����
//#include <stdio.h>
//int bin_search(int arr[], int left, int right, int key)
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) >> 1;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;//�ҵ��ˣ������±�
//	}
//	return -1;//�Ҳ���
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	int key = 9;
//	int num = bin_search(arr,left,right,key);
//	if (num == -1)
//		printf("û�ҵ�\n");	
//	else
//		printf("�ҵ��ˣ��±�Ϊ%d\n", num);
//	return 0;
//}

//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = { 'a','b','c' };
//	printf("arr1[] = { 'a','b','c' }�Ĵ�СΪ��%d\n", sizeof(arr1));//3
//	printf("arr1[] = { 'a','b','c' }��Ԫ�ظ���Ϊ��%d\n", sizeof(arr1) / sizeof(arr1[0]));//3
//	printf("arr1[] = { 'a','b','c' }�ĳ���Ϊ��%d\n", strlen(arr1));//���ֵ
//	//��Դ˷�����ʼ�����ַ����飺
//	//����Ĵ�С��һ��Ԫ�صĴ�С * Ԫ�ظ��� = 1byte * 3 = 3byte
//	//������Ԫ�ظ�����ÿ���ַ���һ��Ԫ�أ����㷽����sizeof(arr1) / sizeof(arr1[0])
//	//�����鳤�ȣ������ַ�'\0'�Ž�������Ϊ���ֵ�������޷�����
//	//���������һ��Ԫ�ص��±꣺sizeof(arr1) / sizeof(arr1[0]) - 1
//
//	int arr2[] = { 1,2,3 };
//	printf("arr1[] = { 1,2,3 }�Ĵ�СΪ��%d\n", sizeof(arr2));//12
//	printf("arr2[] = { 1,2,3 }��Ԫ�ظ���Ϊ��%d\n", sizeof(arr2) / sizeof(arr2[0]));//3
//	printf("arr2[] = { 1,2,3 }�ĳ���Ϊ��%d\n", strlen(arr2));//1
//	//��Դ˷�����ʼ�����������飺
//	//����Ĵ�С��һ��Ԫ�صĴ�С * Ԫ�ظ��� = 4byte * 3 = 12byte
//	//������Ԫ�ظ�����ÿ��������һ��Ԫ�أ����㷽����sizeof(arr1) / sizeof(arr1[0])
//	//�����鳤�ȣ�����1
//	//���������һ��Ԫ�ص��±꣺sizeof(arr1) / sizeof(arr1[0]) - 1
//
//	char arr3[] = "abc";//�൱��arr3[]��������'a'��'b'��'c'��'\0'�ĸ�Ԫ��
//	printf("arr1[] = 'abc'�Ĵ�СΪ��%d\n", sizeof(arr3));//4
//	printf("arr3[] = 'abc'��Ԫ�ظ���Ϊ��%d\n", sizeof(arr3) / sizeof(arr3[0]));//4
//	printf("arr3[] = 'abc'�ĳ���Ϊ��%d\n", strlen(arr3));//3
//	//��Դ˷�����ʼ�����ַ������飺
//	//����Ĵ�С��һ��Ԫ�صĴ�С * Ԫ�ظ��� = 1byte * 4 = 4byte
//	//������Ԫ�ظ��������㷽����sizeof(arr3) / sizeof(arr3[0])������������'\0'
//	//�����鳤�ȣ����㷽����strlen(arr3)��������'\0'
//	//���������һ��Ԫ�ص��±꣺���㷽����sizeof(arr3) / sizeof(arr3[0]) - 2����strlen(arr3) - 1
//	return 0;
//}
//

/*4����д���룬��ʾ����ַ��������ƶ������м��ۡ�*/
// welcome to bit!!!!!!
// ####################
// w##################!
// we################!!
// wel##############!!!
// ...
// welcome to bit!!!!!!
//˼·��ÿѭ��һ�Σ�������������ͬʱ�滻һ��
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//int main()
//{
//    char arr1[] = "welcome to bit!!!";
//    char arr2[] = "#################";
//    int left = 0;// ���±�
//	  //���ڴ�����char arr[] = "welcome";�ĳ�ʼ��
//	  //"welcome",����Ԫ��'\0'
//	  //�������һ�������±�ʱ��sizeof(arr) / sizeof(arr[0]) - 2
//    int right = strlen(arr1) - 1;//strlen --string.h
//    printf("%s\n", arr2);
//    
//    while (left <= right)
//    { //ѭ���Ķ���
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//		  printf("%s\n", arr2);
//		  Sleep(1000);//��Ϣ1000ms--windows.h
//		  system("cls");//ִ��ϵͳ����:cls--�����Ļ--stdlib.h
//        left++;
//        right--;    
//    }
//	  printf("%s\n", arr2);
//    return 0;
//}

/*5����д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�(ֻ���������������룬���������ȷ����ʾ��¼�ɣ�������ξ�����������˳�����*/
//˼·��
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	  //������ȷ�������ַ�����123456��
//    char password[20] = "";
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        printf("����������:>");
//        scanf("%s", password);//���鱾���ǵ�ַ������Ҫȡ��ַ��&
//        //if(paaword == "123456")//�˷����Ƚϵ��������ַ����ĵ�ַ��==���������Ƚ������ַ����Ƿ���ȣ�Ӧ��ʹ��strcmp--string.h
//        if (strcmp(password, "123456") == 0)
//        {   //MSDN����strcmp
//			  //�����ȣ��򷵻�0���������password����"123456"�����ش���0����
//            //���passwordС��"123456"������С��0����
//			  //strcmp�Ƚϵ�������
//			  //��Ӧλ�����ַ���ASCII��ֵ��С�ıȽϣ�����ȱȽ���һλ�ַ���ASCII��ֵ
//			  //�磺abcdef��abccqqqqq
//			  //ǰ�����ַ����Ե�abc�ַ�ASCII��ֵ��ȣ���Ƚ�d��c��dASCII��ֵ����c����abcdef�ַ�����
//            printf("��¼�ɹ�\n");
//            break;
//        }
//        else
//        {
//            printf("�������,�������룡\n");
//        }            
//    }
//    //��������
//    if (i == 3)
//        printf("��������������˳�����\n");
//    return 0;
//}
