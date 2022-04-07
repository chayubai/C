#define _CRT_SECURE_NO_WARNINGS 1
/*1、计算n的阶乘。（不考虑整型溢出）*/
//思路：n!=1*2*3*4*5...*n。产生1-n的数字，累积乘到一起
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int ret = 1;//初始值不能赋值为0
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        ret = ret * i;
//    }
//    printf("ret = %d\n", ret);
//
//    return 0;
//}

/*2、计算1!+2!+3!+......+10!*/
//思路：分别算出各自的阶乘，把它们累加起来
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int ret = 1;
//    int sum = 0;
//	//循环累加10次
//    for (n = 1; n <= 3; n++)
//    {
//        //n的阶乘
//        for (i = 1; i <= n; i++)
//        {
//            ret = ret * i;
//        }
//		  //n阶乘的和
//        sum = sum + ret;
//    } 
//    printf("sum = %d\n", sum);
//    return 0;
//}
//结果：
//1!+ 2!+ 3! = 1 + 2 + 6 =9 ！=15
//代码分析：
//ret =1当n = 1，i = 1，ret = ret * i = 1 * 1 = 1，sum = 0 + 1 = 1，1！= 1
//ret =1当n = 2，i = 1，ret = ret * i = 1 * 1 = 1
//				 i = 2，ret = ret * i = 1 * 2 = 2，sum = 1 + 2 = 3，2！= 3
//ret =2当n = 3，i = 1，ret = ret * i = 2 * 1 = 2
//				 i = 2，ret = ret * i = 2 * 2 = 4
//				 i = 3，ret = ret * i = 4 * 3 =12，sum = 3 +12 =15，3！=15
//ret = 1*1=1
//ret = 1*1*2=2
//ret = 2*1*2*3=12
//ret会一直累加

//程序修改：
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int n = 0;
//    int sum = 0;
//	  int ret = 1;
//    //循环累加10次
//    for (n = 1; n <= 3; n++)
//    {
//        ret = 1;//计算n的阶乘之前，把ret置成1
//        //n的阶乘
//        for (i = 1; i <= n; i++)
//        {
//            ret = ret * i;
//        }
//        //n的阶乘的和
//        sum = sum + ret;
//    }
//    printf("sum = %d\n", sum);
//    return 0;
//}

//程序优化：
//思路：
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
//    //循环累加10次
//    for (n = 1; n <= 3; n++)
//    {
//		  //n的阶乘
//        ret = ret * n;
//		  //n的阶乘的和
//        sum = sum + ret;
//    }
//    printf("sum = %d\n", sum);
//    return 0;
//}

/*3、在一个有序数组中查找具体的某个数字n。编写int binsearch(int x, int v[, int n);功能︰在v[0]<=v[1]<=v[2]<= ....<=v[n-1]的数组中查找x.*/
//思路：将数组中的元素与要查找的数，一一对比
//方法一：遍历数组各元素--适用于有序无序都可以
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//在arr[]有序数组中找到7
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的元素个数
//	for (i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("找到了.下标是:.%d \n", i); 
//			break;
//		}
//	}
//	//跳到这里
//	if (i == sz)//当所有的元素都找了一遍后，没找到
//		printf("找不到 \n");
//	return 0 ;
//}

//思路：中间元素与要查找的数比较
//方法二：二分查找法/折半查找算法
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 7;//要查找的元素
//  //将元素个数作为下标不可行
//	int left = 0;//左下标
//	//计算元素个数：
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;//右下标。此方法只针对整型数组int arr[] = { 1,2,3,4,5,6,7,8,9,10 };的初始化，计算右下标
//	int mid = 0;//中间元素下标
//
//	while (left <= right)//注意循环的条件
//	{//要循环二分查找的动作
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
//			//左右下标相等
//			printf("找到了,下标是%d\n", mid);
//			break;
//		}
//	}
//	//跳到这里
//	if(left > right)
//		printf("找不到\n");
//	return 0;
//}

//方法三：
//实现一个二分查找函数：
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
//			return mid;//找到了，返回下标
//	}
//	return -1;//找不到
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
//		printf("没找到\n");	
//	else
//		printf("找到了，下标为%d\n", num);
//	return 0;
//}

//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = { 'a','b','c' };
//	printf("arr1[] = { 'a','b','c' }的大小为：%d\n", sizeof(arr1));//3
//	printf("arr1[] = { 'a','b','c' }的元素个数为：%d\n", sizeof(arr1) / sizeof(arr1[0]));//3
//	printf("arr1[] = { 'a','b','c' }的长度为：%d\n", strlen(arr1));//随机值
//	//针对此方法初始化的字符数组：
//	//数组的大小：一个元素的大小 * 元素个数 = 1byte * 3 = 3byte
//	//求数组元素个数：每个字符是一个元素，计算方法：sizeof(arr1) / sizeof(arr1[0])
//	//求数组长度：遇见字符'\0'才结束，都为随机值，长度无法计算
//	//数组中最后一个元素的下标：sizeof(arr1) / sizeof(arr1[0]) - 1
//
//	int arr2[] = { 1,2,3 };
//	printf("arr1[] = { 1,2,3 }的大小为：%d\n", sizeof(arr2));//12
//	printf("arr2[] = { 1,2,3 }的元素个数为：%d\n", sizeof(arr2) / sizeof(arr2[0]));//3
//	printf("arr2[] = { 1,2,3 }的长度为：%d\n", strlen(arr2));//1
//	//针对此方法初始化的整型数组：
//	//数组的大小：一个元素的大小 * 元素个数 = 4byte * 3 = 12byte
//	//求数组元素个数：每个整型是一个元素，计算方法：sizeof(arr1) / sizeof(arr1[0])
//	//求数组长度：都是1
//	//数组中最后一个元素的下标：sizeof(arr1) / sizeof(arr1[0]) - 1
//
//	char arr3[] = "abc";//相当于arr3[]数组中有'a'、'b'、'c'、'\0'四个元素
//	printf("arr1[] = 'abc'的大小为：%d\n", sizeof(arr3));//4
//	printf("arr3[] = 'abc'的元素个数为：%d\n", sizeof(arr3) / sizeof(arr3[0]));//4
//	printf("arr3[] = 'abc'的长度为：%d\n", strlen(arr3));//3
//	//针对此方法初始化的字符串数组：
//	//数组的大小：一个元素的大小 * 元素个数 = 1byte * 4 = 4byte
//	//求数组元素个数：计算方法：sizeof(arr3) / sizeof(arr3[0])，包含计算了'\0'
//	//求数组长度：计算方法：strlen(arr3)，不计算'\0'
//	//数组中最后一个元素的下标：计算方法：sizeof(arr3) / sizeof(arr3[0]) - 2或者strlen(arr3) - 1
//	return 0;
//}
//

/*4、编写代码，演示多个字符从两端移动，向中间汇聚。*/
// welcome to bit!!!!!!
// ####################
// w##################!
// we################!!
// wel##############!!!
// ...
// welcome to bit!!!!!!
//思路：每循环一次，数组左右两边同时替换一次
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//int main()
//{
//    char arr1[] = "welcome to bit!!!";
//    char arr2[] = "#################";
//    int left = 0;// 左下标
//	  //对于此数组char arr[] = "welcome";的初始化
//	  //"welcome",包含元素'\0'
//	  //计算最后一个！的下标时，sizeof(arr) / sizeof(arr[0]) - 2
//    int right = strlen(arr1) - 1;//strlen --string.h
//    printf("%s\n", arr2);
//    
//    while (left <= right)
//    { //循环的动作
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//		  printf("%s\n", arr2);
//		  Sleep(1000);//休息1000ms--windows.h
//		  system("cls");//执行系统命令:cls--清空屏幕--stdlib.h
//        left++;
//        right--;    
//    }
//	  printf("%s\n", arr2);
//    return 0;
//}

/*5、编写代码实现，模拟用户登录情景，并且只能登录三次。(只允许输入三次密码，如果密码正确则提示登录成，如果三次均输入错误，则退出程序。*/
//思路：
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	  //假设正确密码是字符串“123456”
//    char password[20] = "";
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        printf("请输入密码:>");
//        scanf("%s", password);//数组本身是地址，不需要取地址符&
//        //if(paaword == "123456")//此方法比较的是两个字符串的地址。==不能用来比较两个字符串是否相等，应该使用strcmp--string.h
//        if (strcmp(password, "123456") == 0)
//        {   //MSDN搜索strcmp
//			  //如果相等，则返回0，否则，如果password大于"123456"，返回大于0的数
//            //如果password小于"123456"，返回小于0的数
//			  //strcmp比较的是内容
//			  //对应位置上字符的ASCII码值大小的比较，若相等比较下一位字符的ASCII码值
//			  //如：abcdef和abccqqqqq
//			  //前面两字符各自的abc字符ASCII码值相等，则比较d和c，dASCII码值大于c，则abcdef字符串大
//            printf("登录成功\n");
//            break;
//        }
//        else
//        {
//            printf("密码错误,重新输入！\n");
//        }            
//    }
//    //跳到这里
//    if (i == 3)
//        printf("三次输入均错误，退出程序\n");
//    return 0;
//}
