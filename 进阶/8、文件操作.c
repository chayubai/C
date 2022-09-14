#define _CRT_SECURE_NO_WARNINGS 1
//C语言文件操作
//1. 为什么使用文件
//我们前面学习结构体时，写了通讯录的程序，当通讯录运行起来的时候，可以给通讯录中增加、删除数
//据，此时数据是存放在内存中，当程序退出的时候，通讯录中的数据自然就不存在了，等下次运行通讯录程序的时候，数据又得重新录入，如果使用这样的通讯录就很难受。
//我们在想既然是通讯录就应该把信息记录下来，只有我们自己选择删除数据的时候，数据才不复存在。
//这就涉及到了数据持久化的问题，我们一般数据持久化的方法有，把数据存放在磁盘文件、存放到数据库等方式。
//使用文件我们可以将数据直接存放在电脑的硬盘上，做到了数据的持久化。

//2. 什么是文件
//磁盘上的文件是文件。
//但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件（从文件功能的角度来分类的）。
//1 程序文件:包括源程序文件（后缀为.c）, 目标文件（windows环境后缀为.obj）, 可执行程序（windows环境后缀为.exe）。
//2 数据文件:文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。
//本章讨论的是数据文件。
//在以前各章所处理数据的输入输出都是以终端为对象的，即从终端的键盘输入数据，运行结果显示到显示器上。
//其实有时候我们会把信息输出到磁盘上，当需要的时候再从磁盘上把数据读取到内存中使用，这里处理的就是磁盘上文件。
//3 文件名:一个文件要有一个唯一的文件标识，以便用户识别和引用。
//文件名包含3部分：文件路径 + 文件名主干 + 文件后缀
//例如： c : \code\test.txt
//为了方便起见，文件标识常被称为文件名。

//3. 文本文件和二进制文件
//根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
//数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件。
//如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。以ASCII字符的形式存储的文件就是文本文件。
//一个数据在内存中是怎么存储的呢？
//字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。
//如有整数10000，如果以ASCII码的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输出，则在磁盘上只占4个字节（VS2013测试）。
//如：内存中的存储形式：10000(十进制)的二进制存储 - 00000000 00000000 00100111 00010000
//文本文件：以ASCII形式存储：00110001(1) 00110000(0) 00110000(0) 00110000(0) 00110000(0)
//二进制文件：以二进制形式存储：00000000 00000000 00100111 00010000
//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");//打开test.txt文件，以二进制形式写这个文件，当文件不存在时，fopen会创建文件
//	fwrite(&a, 4, 1, pf);//fwrite写文件，将a地址处的数据，写一个4个字节的数据，放入pf维护的指针所在的文件中
//	fclose(pf);//关闭文件
//	pf = NULL;
//	return 0;
//}
//运行后，使用VS打开文件查看
//将test.txt文件添加到工程后，"源文件" - "添加" - "现有项"
//选中test.txt，右键以二进制编辑器打开，由于是小端存储故，10 27 00 00
//由于看到的是十六进制数据，但底层存储的是二进制数据
//即十六进制00 00 27 10  = 十进制10000

//4. 文件缓冲区
//ANSIC 标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序
//中每一个正在使用的文件开辟一块“文件缓冲区”。从内存向磁盘输出数据会先送到内存中的缓冲区，
//装满缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓
//冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小根据C编译系统决定的。
//#include <stdio.h>
//#include <windows.h>
////VS2013 WIN10环境测试
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//先将代码放在输出缓冲区
//	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
//	//注：fflush 在高版本的VS上不能使用了
//	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	fclose(pf);
//	//注：fclose在关闭文件的时候，也会刷新缓冲区
//	pf = NULL;
//	return 0;
//}
//这里可以得出一个结论：因为有缓冲区的存在，C语言在操作文件的时候，需要做刷新缓冲区或者在文件操作结束的时候关闭文件。
//如果不做，可能导致读写文件的问题。

//5、文件指针
//缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
//每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
//这些信息是保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE.
//例如，VS2013编译环境提供的 stdio.h 头文件中有以下的文件类型申明：输入FILE，转到定义，可查看FILE结构体的相关信息
//不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
//每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息，使用者不必关心细节。
//一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。

//下面我们可以创建一个FILE*的指针变量:FILE* pf;//文件指针变量
//定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。
//通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件。

//6. 文件的打开和关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
//在编写程序的时候，在打开文件的同时，都会返回一个FILE* 的指针变量指向该文件，也相当于建立了指针和文件的关系。
//ANSIC 规定使用fopen函数来打开文件，fclose来关闭文件。
//打开文件
//FILE* fopen(const char* filename, const char* mode);
//打开成功，返回文件对应的指针，否则返回NULL
//关闭文件
//int fclose(FILE* stream);
//打开方式如下：
//文件使用方式      含义                                           如果指定文件不存在
//“r”（只读）     为了输入数据，打开一个已经存在的文本文件       出错
//“w”（只写）     为了输出数据，打开一个文本文件                 建立一个新的文件
//“a”（追加）     向文本文件尾添加数据                           建立一个新的文件
//“rb”（只读）    为了输入数据，打开一个二进制文件               出错
//“wb”（只写）    为了输出数据，打开一个二进制文件               建立一个新的文件
//“ab”（追加）    向一个二进制文件尾添加数据                     出错
//“r + ”（读写）  为了读和写，打开一个文本文件                   出错
//“w + ”（读写）  为了读和写，建议一个新的文件                   建立一个新的文件
//“a + ”（读写）  打开一个文件，在文件尾进行读写                 建立一个新的文件
//“rb + ”（读写） 为了读和写打开一个二进制文件                   出错
//“wb + ”（读写） 为了读和写，新建一个新的二进制文件             建立一个新的文件
//“ab + ”（读写） 打开一个二进制文件，在文件尾进行读和写         建立一个新的文件

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pFile;
//    //相对路径
//    //..表示上一级路径
//    //.表示当前路径
//    //当前路径的上一级的上一级路径
//    //../..
//    
//    //打开文件
//    pFile = fopen("myfile.txt", "r");//打开当前路径下的文件 - 相对路径
//    //pFile = fopen("D:\\VS2019\\code\\text\\myfile.txt", "w");//绝对路径
//    //文件操作
//    if (pFile == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //关闭文件
//    fclose(pFile);//将结构体文件信息区的资源释放掉，但是指针还在，需要释放
//    pFile = NULL;
//    return 0;
//}
//注意：fopen("myfile.txt", "w");
//当myfile.txt中有信息，会将旧信息销毁掉

//7. 文件的顺序读写（结合MSDN）
//功能           函数名       适用于
//字符输入函数   fgetc        所有输入流    - 写入一个字符
//字符输出函数   fputc        所有输出流    - 获取一个字符  
//文本行输入函数 fgets        所有输入流    - 写入一行字符
//文本行输出函数 fputs        所有输出流    - 获取一行字符
//格式化输入函数 fscanf       所有输入流    - 格式化形式写入字符
//格式化输出函数 fprintf      所有输出流    - 格式化形式获取字符
//二进制输入     fread        文件
//二进制输出     fwrite       文件
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    FILE* pfWrite;
//    pfWrite = fopen("myfile.txt", "w");//pfWrite所指向的文件以写的方式打开，是文件输出流
//    if (pfWrite == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //写文件
//    fputc('b', pfWrite);
//    fputc('i', pfWrite);
//    fputc('t', pfWrite);
//    //关闭文件
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
//    pfRead = fopen("myfile.txt", "r");//pfWrite所指向的文件以读的方式打开，是文件输入流
//    if (pfRead == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //读文件
//    printf("%c", fgetc(pfRead));//fgetc返回一个ASCII码值
//    printf("%c", fgetc(pfRead));
//    printf("%c", fgetc(pfRead));
//    //关闭文件
//    fclose(pfRead);//将结构体文件信息区的资源释放掉，但是指针还在，需要释放
//    pfRead = NULL;
//    return 0;
//}

//从键盘输入
//输出到屏幕
//键盘和屏幕都是外部设备
//键盘 - 是标准输入设备 - stdin(类型为File*)
//屏幕 - 是标准输出设备 - stdout(类型为File*)
//是一个程序默认打开的两个流设备
//类似与文件，但是设备不需要标准设备默认不需要打开和关闭
//#include <stdio.h>
//int main()
//{
//	//fgetc、fputc适用所有输入或流输出流
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
//    pf = fopen("myfile.txt", "r");//文件中写入bit换行hello
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //读文件
//    //fgets(buf, 1024, pf);//从pf所指向的文件中读取最多1024个字符,放入buf中
//    //printf("%s", buf);//由于bit换行，会把\n也读入buf中，故结果会换行
//    //fgets(buf, 1024, pf);
//    //printf("%s", buf);//由于hello，没有换行，故结果不会换行
//    fgets(buf, 1024, pf);
//    puts(buf);//将字符串（一行）输出到屏幕上，并换行
//    fgets(buf, 1024, pf);
//    puts(buf);
//    //关闭文件
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
//    pf = fopen("myfile.txt", "w");//写入bit换行hello
//    if (pf == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    //写文件
//    fputs("hello", pf);
//    fputs("world", pf);
//    fputs("hello\n", pf);
//    fputs("world", pf);
//    //关闭文件
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    //从键盘读取一行文本信息
//    char buf[1024] = { 0 };
//    fgets(buf, 1024, stdin);//从标准输入读取
//    fputs(buf, stdout);//输出到标准输出
//    //等价以下
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
//    //格式化的形式写文件
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
//    //格式化的形式读数据
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

//对比一组函数：
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
//scanf / fscanf或者printf / fprintf参数只差一个指向文件的流
//fscanf和fprintf既可以用于标准输入输出流的格式化输入输出语句，也可以用与文件流格式化的输入输出语句
//scanf和printf只能用于标准输入输出流的格式化输入输出语句
//sscanf从字符串中读取格式化的数据转换成结构体成员信息
//sprintf把格式化的数据存储成字符串

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
//    //把格式化的数据转换成字符串存储到buf中
//    sprintf(buf, "%d %.2f %s", s.n, s.score, s.arr);
//    printf("%s\n", buf);
//    //从buf中读取格式化的数据到结构体tmp中
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
//    struct S s = { "张三",20,55.6 };
//    FILE* pf = fopen("test.txt", "wb");
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //二进制的形式写文件
//    fwrite(&s, sizeof(struct S), 1, pf);//将1个sizeof(struct S)大小的对象s的信息写入到pf中
//    fclose(pf);
//    pf = NULL;
//    //如果是一个数组，就可以写入多个信息
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
//    //从文件中读取信息
//    fread(&s, sizeof(struct S), 1, pf);//将1个sizeof(struct S)大小的对象s的信息从pf所指向的文件中读出
//    //虽然以二进制形式写入看不懂，但是可以从文件中以二进制形式读出
//    printf("%s %d %lf\n", s.name, s.age, s.score);
//    fclose(pf);
//    pf = NULL;
//    //如果是一个数组，就可以读取多个信息
//    return 0;
//}

//8. 文件的随机读写
//1 fseek:int fseek(FILE * stream, long int offset, int origin);
//根据当前文件指针stream的位置origin和偏移量offset来定位文件指针。
//origin：SEEK_CUR文件指针的当前位置、 SEEK_END文件指针的末尾位置、SEEK_SET文件指针的起始位置（默认）
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //1、定位文件指针
//    fseek(pf, 4, SEEK_CUR);
//    //2、读取文件
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//e
//
//    fseek(pf, -2, SEEK_END);//不能设置为2
//    //2、读取文件
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//e
//
//    fclose(pf);
//    pf = NULL;
//    //如果是一个数组，就可以读取多个信息
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
//返回值：返回文件指针相对于起始位置的偏移量
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
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
//    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
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
//    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //读取文件
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

//3 rewind：void rewind(FILE * stream);
//让文件指针的位置回到文件的起始位置
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //读取文件
//    int ch = fgetc(pf);
//    printf("%c\n", ch);//a，此时指针指向的b
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

//9. 文件读取结束的判定
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");//test.txt中没有内容
//    if (pf == NULL)
//    {
//        return 0;
//    }
//    //读取文件
//    int ch = fgetc(pf);
//    printf("%d\n", ch);//-1
//    
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//被错误使用的feof：
//牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束。
//而是应用于当文件读取结束的时候，判断是读取失败而结束，还是遇到文件尾EOF而结束。
//即feof函数是判断文件是否是读取EOF后而结束的
//feof在没有读完的时候，返回0，在读完的时候返回-1，也就是返回EOF。
//1. 文本文件读取是否结束，判断返回值是否为EOF（使用fgetc读取字符，返回EOF或-1），或者NULL（fgets读取字符串，返回NULL）
//例如：
//fgetc 判断是否为 EOF .
//fgets 判断返回值是否为 NULL .
//2. 二进制文件的读取结束的判断，fread判断返回值是否小于实际要读的个数。
//例如：
//fread判断返回值是否小于实际要读的个数。

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//    //strerror(errno):返回错误码对应的错误信息的字符串地址返回
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
//        perror("open file test2.txt");//perror使得错误信息更加明了
//        return 0;
//    }
//    //...
//    fclose(pf);
//    pf = NULL;
//}

//正确的使用：
//文本文件的例子：
//#include <stdio.h>
//int main()
//{
//    FILE* pf = fopen("test2.txt", "r");
//    if (pf == NULL)
//    {
//        perror("open file test2.txt");//perror使得错误信息更加明了
//        return 0;
//    }
//    //...
//    int ch = 0;
//    while ((ch = fgetc(pf) != EOF))//EOF=-1，转到定义
//    {
//        putchar(ch);//回顾putc函数的使用
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
//    //变量的定义放在最前面较好，因为有部分编译器不支持边定义变使用
//    int c; // 注意：int，非char，要求处理EOF
//    FILE* fp = fopen("test.txt", "r");//test.txt中含有abcdef文本
//    if (!fp) //fp为NULL时，报错
//    {
//        perror("File opening failed");
//        return EXIT_FAILURE;
//    }
//    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//    {
//        putchar(c);
//    }
//    //判断是什么原因结束的
//    if (ferror(fp))
//        puts("I/O error when reading");
//    else if (feof(fp))
//        puts("End of file reached successfully");
//    fclose(fp);
//    fp = NULL;
//}

//二进制文件的例子：
//#include <stdio.h>
//enum { SIZE = 5 };
//int main(void)
//{
//    double a[SIZE] = { 1.,2.,3.,4.,5. };
//    FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式
//    fwrite(a, sizeof * a, SIZE, fp); // 写 double 的数组
//    fclose(fp);
//    double b[SIZE];
//    fp = fopen("test.bin", "rb");
//    size_t ret_code = fread(b, sizeof * b, SIZE, fp); // 读 double 的数组
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