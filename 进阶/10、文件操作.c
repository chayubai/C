#define _CRT_SECURE_NO_WARNINGS 1
//C语言文件操作
//1. 为什么使用文件
//我们前面学习结构体时，写了通讯录的程序，当通讯录运行起来的时候，可以给通讯录中增加、删除数据，
//此时数据是存放在内存中，当程序退出的时候，通讯录中的数据自然就不存在了，等下次运行通讯录程序的时候，数据又得重新录入，如果使用这样的通讯录就很难受。
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
//例如： c:\code\test.txt
//为了方便起见，文件标识常被称为文件名。

//3. 文本文件和二进制文件
//根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
//数据在内存中以二进制的形式存储，如果不加转换的输出到外存 即把内存中的数据直接放到文件中，就是二进制文件。
//如果要求在外存上以ASCII码的形式存储，则需要在存储前转换(即把内存中的数据转换为字符)。以ASCII字符的形式存储的文件就是文本文件。
//也就是说：文本文件人是可以看得懂的。而二进制文件人是看不懂的。
//一个数据在内存中是怎么存储的呢？
//字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。
//如：内存中有整数10000
//1、如果以ASCII码的形式输出到磁盘(将内存中的整数10000转成字符'1''0''0''0''0''0'存储到磁盘上)，则磁盘中占用5个字节（每个字符一个字节），
//2、如果以二进制形式输出到磁盘(将内存中的整数10000直接存储到磁盘上)，因为数据是整型，则在磁盘上只占整型大小的空间，即4个字节。
//分析：
//1、内存中的存储形式：10000(十进制)的二进制存储 - 00000000 00000000 00100111 00010000
//2、文本文件：以ASCII形式存储：00110001(1) 00110000(0) 00110000(0) 00110000(0) 00110000(0)
//3、二进制文件：以二进制形式存储：00000000 00000000 00100111 00010000
/*
#include <stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//write binary 打开test.txt文件，以二进制形式写这个文件，当文件不存在时，fopen会创建文件
	fwrite(&a, 4, 1, pf);//fwrite写文件，将a地址处的数据，写一个4个字节的数据，放入pf指针维护的所在的文件中
	fclose(pf);//关闭文件
	pf = NULL;
	return 0;
}
*/
//运行后，使用文本编辑器打开是一堆乱码的。使用VS打开文件查看
//将test.txt文件添加到工程后，"源文件" - "添加" - "现有项"。选中test.txt，右键-打开方式“以二进制编辑器打开”
//由于00 00 27 10是小端存储，故该数为：0x10 27 00 00
//注意：虽然看到的是十六进制数据，但计算机底层存储的还是二进制数据(由0、1组成的序列)
//即，十六进制0x10270000  = 十进制10000

//4. 文件缓冲区
//ANSIC 标准(标准C)采用“缓冲文件系统”处理数据文件的。
//所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块“文件缓冲区”。
//从内存向磁盘输出数据会先送到内存中的输出缓冲区，装满缓冲区后才一起送到磁盘上。
//如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存输入缓冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。
//缓冲区的大小根据C编译系统决定的。
//缓冲区的作用：提高CPU的操作效率。比如：每次写入一个字符到文件中，中间没有缓冲。如果频繁的写入就会使用CPU，导致其他程序无法获得CPU.如果先把一些数据
//放到缓冲区上，再使用CPU,这样就让出CPU，使得CPU的利用率提高

//缓冲区分为：
//1、全缓冲区：当填满标准I/O缓存后才进行实际I/O操作。(如：全缓冲的典型代表是对磁盘文件的读写。)
//2、行缓冲区：当在输入和输出中遇到换行符时，执行真正的I/O操作。(典型代表是标准输入(stdin)和标准输出(stdout)。)注意：换行符也被读入缓冲区。
//3、不带缓冲区：典型代表是标准错误stderr

//刷新缓冲区：(清空缓冲区，并将数据交给对象)
//1、缓冲区满了，会刷新
//2、行缓冲遇到 '\n' 会刷新；
//3、调用 fflush()函数；
//4、调用 fclose();
//更多关于输入输出缓冲区的内容，自行查阅相关文档。
/*
#include <stdio.h>
//Linux环境测试
int main()
{
	while (1)
	{
		sleep(1);//单位：秒
		printf("hehe\n");
	}
	return 0;
}
*/
//结果：过了1秒，终端也没有打印“hehe”.只有当输出缓冲区满了，才会显示
//分析：程序数据区 和屏幕(也是一个文件)之间有一个输出缓冲区。当printf输出，先将数据放到输出缓冲区
//只有当输出缓冲区满了，才会将缓冲区的数据放到屏幕上。
/*
#include <stdio.h>
#include <windows.h>
//WIN10环境测试
int main()
{
	FILE* pf = fopen("test.txt", "w");
	//Write a string to a stream.
	//int fputs(const char* string, FILE * stream);

	fputs("abcdef", pf);//先将数据放在输出缓冲区
	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
	Sleep(10000);//单位：毫秒
	printf("刷新缓冲区\n");
	//Flushes a stream.
	//int fflush(FILE * stream);

	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
	//注：fflush 在高版本的VS上可能不能使用了
	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
	Sleep(10000);
	fclose(pf);
	//注：fclose在关闭文件的时候，也会刷新缓冲区
	pf = NULL;
	return 0;
}
*/
//这里可以得出一个结论：因为有缓冲区的存在，C语言在操作文件的时候，需要做刷新缓冲区或者在文件操作结束的时候关闭文件。
//如果不做，可能导致读写文件的问题。

//5、文件指针
//缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
//每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
//这些信息是保存在一个结构体变量中的。该结构体类型是由系统声明的，取名FILE.
//例如，VS2013编译环境提供的 stdio.h 头文件中有以下的文件类型申明：输入FILE，转到定义，可查看FILE结构体的相关信息
//不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
//每当fopen函数打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，(函数内部创建FILE类型的结构体变量，用来维护文件信息区，并返回一个文件信息区空间的起始地址)
//并填充其中的信息，使用者不必关心细节。
//一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便。

//下面我们可以创建一个FILE*的指针变量:FILE* pf;//pf文件指针变量
//定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。
//通过该文件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件。

//6. 文件的打开和关闭
//文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
//在编写程序的时候，在打开文件的同时，都会返回一个FILE* 的指针变量指向该文件，也相当于建立了指针和文件的关系。
//ANSIC 规定使用fopen函数来打开文件，fclose来关闭文件。
//1、fopen打开文件：
//FILE* fopen(const char* filename, const char* mode);
//mode参数：打开方式
//打开成功，返回文件对应的指针，打开失败，则返回NULL
//2、fclose关闭文件：
//int fclose(FILE* stream);
//注意：fopen、fclose的声明在stdio.h中

//打开方式如下：
/*
	文件使用方式    含义                                           如果指定文件不存在			记忆技巧			理解技巧
	“r”（只读）   为了输入数据，打开一个已经存在的文本文件       出错							read				以只读的方式打开文本文件，文件必须存在
	“w”（只写）   为了输出数据，打开一个文本文件(销毁重建写)     建立一个新的文件				write				以只写的方式打开文本文件，文件若存在则清空文件内容从文件头部开始写，若不存在则根据文件名创建新文件并只写打开
	“a”（追加）   向文本文件尾添加数据(追加写)                   建立一个新的文件				append				以只写的方式打开文本文件，文件若存在则从文件尾部以追加的方式开始写，文件原来存在的内容不会清除（除了文件尾标志EOF），若不存在则根据文件名创建新文件并只写打开
	“rb”（只读）  为了输入数据，打开一个二进制文件               出错							read binary			二进制文件模式读
	“wb”（只写）  为了输出数据，打开一个二进制文件               建立一个新的文件				write binary		二进制文件模式写
	“ab”（追加）  向一个二进制文件尾添加数据                     建立一个新的文件				append binary		二进制文件模式追加
	“r+”（读写）  为了读和写，打开一个文本文件                   出错							read+write			以可读写的方式打开文本文件，文件必须存在
	“w+”（读写）  为了读和写，新建一个新的文件                   建立一个新的文件				write+read			以可读写的方式打开文本文件，其他与w一样
	“a+”（读写）  打开一个文件，在文件尾进行读写                 建立一个新的文件				append+read+write	以可读写的方式打开文本文件，其他与a一样
	“rb+”（读写） 为了读和写打开一个二进制文件                   出错							read binary+write binary					
	“wb+”（读写） 为了读和写，新建一个新的二进制文件             建立一个新的文件				write binary+read binary
	“ab+”（读写） 打开一个二进制文件，在文件尾进行读和写         建立一个新的文件				append binary+read binary+write binary
	//若打开二进制文件，可在后面加个b注明，其他一样，如rb，r+b（或rb+）。
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE* pFile;
    //相对路径
    //..表示上一级路径
    //.表示当前路径
    //当前路径的上一级的上一级路径
    //../..
    
    //打开文件
    pFile = fopen("myfile.txt", "w");//打开当前路径下的文件 - 相对路径
    //pFile = fopen("D:\\VS2019\\code\\text\\myfile.txt", "w");//绝对路径
	//pFile = fopen("D:/VS2019/code/text/myfile.txt", "w");//绝对路径
    if (pFile == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;//得加return 0;否则fclose(pFile);这一行会报警告：pFile可能为0
		//因为如果pFile为空后，还会继续fclose(pFile);操作
    }
	//文件操作 - 文件的读写操作
	//...
	
    //关闭文件
    fclose(pFile);//将结构体文件信息区的资源释放掉，但是指针还在，需要置空
    pFile = NULL;
    return 0;
}
//注意：fopen("myfile.txt", "w");
//当myfile.txt中有信息，会将旧文件销毁，重新建立新文件，再写入
*/

//7. 文件的顺序读写（结合MSDN）
/*
	功能           函数名       适用于			含义							函数原型
	字符输入函数   fgetc        所有输入流    - 从流中读取一个字符				int fgetc( FILE *stream );
	字符输出函数   fputc        所有输出流    - 向流中写入一个字符				int fputc(int c, FILE * stream);
	文本行输入函数 fgets        所有输入流    - 从流中读取一行字符				char *fgets( char *string, int n, FILE *stream );
	文本行输出函数 fputs        所有输出流    - 向流中写入一行字符				int fputs( const char *string, FILE *stream );
	格式化输入函数 fscanf       所有输入流    - 格式化形式从流中读取字符		int fscanf( FILE *stream, const char *format [, argument ]... );
	格式化输出函数 fprintf      所有输出流    - 格式化形式向流中写入字符		int fprintf( FILE *stream, const char *format [, argument ]...);
	二进制输入     fread        文件		  - 从文件中读取					size_t fread( void *buffer, size_t size, size_t count, FILE *stream );
	二进制输出     fwrite       文件		  - 从文件中写入					size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
	//相对于文件而言，输入输出是：将数据写入到文件中这是输出，将数据从文件中拿出是输入
	//相对于程序而言，输入输出是：将数据从程序中放到文件是输出，将数据写入到程序中是输入
	//注意：将内存中的数据向文件中写入，是写操作，对文件而言是，输出操作。从文件中读数据到内存，是读操作，对文件而言是，输入操作。
*/
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    FILE* pfWrite;
    pfWrite = fopen("myfile.txt", "w");//pfWrite所指向的文件以写的方式打开，是文件输出流
    if (pfWrite == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //写文件
	//int fputc(int c, FILE * stream);	
    fputc('b', pfWrite);//放到(为文件myfile.txt开辟的)输出缓冲区，文件指针向后偏移1
    fputc('i', pfWrite);//放到(为文件myfile.txt开辟的)输出缓冲区，文件指针向后偏移1
    fputc('t', pfWrite);//放到(为文件myfile.txt开辟的)输出缓冲区，文件指针向后偏移1
    //关闭文件
    fclose(pfWrite);//关闭文件，会刷新输出缓冲区，文件中才会有内容，并文件信息区里的指针复原
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
    pfRead = fopen("myfile.txt", "r");//pfRead所指向的文件以读的方式打开，是文件输入流
    if (pfRead == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //读文件
	//int fgetc( FILE *stream );  fgetc返回一个ASCII码值
    printf("%c", fgetc(pfRead));//b		fgetc(pfRead)放到(为文件myfile.txt开辟的)输入缓冲区，文件指针向后偏移1		printf("%c",'b');放到(为文件stdout开辟的)输出缓冲区，文件指针向后偏移1
    printf("%c", fgetc(pfRead));//i		fgetc(pfRead)放到(为文件myfile.txt开辟的)输入缓冲区，文件指针向后偏移1		printf("%c",'i');放到(为文件stdout开辟的)输出缓冲区，文件指针向后偏移1
    printf("%c", fgetc(pfRead));//t		fgetc(pfRead)放到(为文件myfile.txt开辟的)输入缓冲区，文件指针向后偏移1		printf("%c",'t');放到(为文件stdout开辟的)输出缓冲区，文件指针向后偏移1
    //关闭文件
    fclose(pfRead);//关闭文件，会刷新输出缓冲区，屏幕上才会有内容，并文件信息区里的指针复原
	//将结构体文件信息区的资源释放掉，但是指针还在，需要置空
    pfRead = NULL;
    return 0;
}
*/

//从键盘输入
//输出到屏幕
//键盘和屏幕都是外部设备，本质上还是个文件（也叫流设备）
//键盘 - 是标准输入设备 - stdin(类型为File*)
//屏幕 - 是标准输出设备 - stdout(类型为File*)
//每打开一个程序 stdin stdout stderr 这三个文件流指针默认打开的。与普通文件比较，标准设备默认不需要打开和关闭
/*
#include <stdio.h>
int main()
{
	//fgetc、fputc适用所有输入或流输出流，即适用于文件流，也适用于流设备
	int ch = fgetc(stdin);//从键盘获取数据，(从stdin获取数据，由于缓冲区没有数据需要阻塞等待)
	fputc(ch, stdout);//将数据输出到屏幕,(将数据写入到stdout中)
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
    pf = fopen("myfile.txt", "r");//文件中写入bit换行hello
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
		return 0;
    }
    //读文件
	//char* fgets(char* string, int n, FILE * stream);  

    //fgets(buf, 1024, pf);//读取第一行，从pf所指向的文件中读取最多1024个字符,放入buf中
    //printf("%s", buf);//由于bit换行，会把\n也读入buf中，故结果会换行
    
    //fgets(buf, 1024, pf);//读取第二行
    //printf("%s", buf);//由于hello，没有换行，故结果不会换行
	//注意：如果只有一行，读取两次，两次结果是一样的。如果有多行，则每次读取的结果都不一样

    fgets(buf, 1024, pf);
	//int puts( const char *string );
    puts(buf);//将字符串（一行）输出到屏幕上，并换行

    fgets(buf, 1024, pf);
    puts(buf);//将字符串（一行）输出到屏幕上，并换行
    //注意：puts写入(输出)会主动换行
	//注意：如果只有一行，读取两次，两次结果是一样的。如果有多行，则每次读取的结果都不一样
    //关闭文件
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
    //写文件
    //int fputs( const char *string, FILE *stream );
    fputs("hello", pf);
    fputs("world", pf);
    fputs("hello\n", pf);
    fputs("world", pf);
    //注意：fputs写入不会主动换行，写了'\n'才会换行
    //关闭文件
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    //fgets、fputs适用于任意流
    //从stdin读取一行文本信息
    char buf[1024] = { 0 };
    fgets(buf, 1024, stdin);//从标准输入读取，(由于缓冲区没有数据阻塞等待输入)
    fputs(buf, stdout);//输出到标准输出
    
    //等价以下，因为gets、puts是标准输入输出函数
    //gets(buf);//该函数已经淘汰了
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
    //格式化的形式写文件
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
    //格式化的形式读文件
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
    //fscanf、fprintf适用于任意流
    struct S s = { 0 };
    fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);//从标准输入读取，(由于缓冲区没有数据阻塞等待输入)
    fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);//输出到标准输出
    return 0;
}
*/

//对比一组函数：
//scanf / fscanf / sscanf
//printf / fprintf / sprintf
//scanf / fscanf 或者 printf / fprintf参数只差一个指向文件的流
//scanf和printf只能用于标准输入流/标准输出流的格式化输入/输出语句
//fscanf和fprintf既可以用于标准输入流/标准输出流的格式化输入/输出语句，也可以用于文件流格式化的格式化输入/输出语句
//sscanf从字符串中读取格式化的数据
//sprintf把格式化的数据输出成（存储成）字符串

//sscanf/sprintf
//输入函数 - 读取buf，将buf中的字符串转换成格式化的数据
//int sscanf( const char *buffer, const char *format [, argument ] ... );
//输出函数 - 将格式化的数据转换成字符串，写入buf中
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
    //把格式化的数据转换成字符串存储到buf中
    sprintf(buf, "%d %.2f %s", s.n, s.score, s.arr);
    printf("%s\n", buf);//"100 3.140000 abcdef"

    //从buf中读取字符串转换成格式化的数据
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
    struct S s = { "张三",20,55.6 };
    FILE* pf = fopen("test.txt", "wb");
    if (pf == NULL)
    {
        return 0;
    }
    //二进制的形式写文件
    //size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream );//将buffer地址处的size个字节的数据连续写入count次数到stream中
    //size参数：将多大的字节数据作为一个元素写入
    //count参数：要连续写入的次数
    //返回值：实际写入到的个数。如：将21个字符，每次写入5个，前4次返回5，最后一次返回1
    fwrite(&s, sizeof(struct S), 1, pf);//将1个sizeof(struct S)大小的对象s的信息写入到pf指向的文件中
    fclose(pf);
    pf = NULL;

    //如果s是一个数组，就可以写入更多信息
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
    //从文件中读取信息
    //size_t fread(void* buffer, size_t size, size_t count, FILE * stream);//从stream中连续读取count次数的size个字节的数据到buffer地址处
    //size参数：将多大的字节数据作为一个元素读取
    //count参数：要连续读取的个数
    //返回值：实际读取到的个数。如：将21个字符，每次读取5个，前4次返回5，最后一次返回1
    fread(&s, sizeof(struct S), 1, pf);//将1个sizeof(struct S)大小的对象s的信息从pf所指向的文件中读出
    //虽然以二进制形式写入看不懂，但是可以从文件中以二进制形式读出
    printf("%s %d %lf\n", s.name, s.age, s.score);
    fclose(pf);
    pf = NULL;
    //注意：如果读多个数据，s必须有能力放多个数据。如：fread(&s, sizeof(struct S), 3, pf);s必须有能力放3个数据内容的空间
    
    //如果s是一个数组，就可以读取多个信息
    return 0;
}
*/
/*
#include <stdio.h>
int main()
{
    int arr[] = { 48,49,50,51,52};
    FILE* pf = fopen("test15.txt", "w+");//这种模式打开，则搭配rewind函数，可以实现读和写操作
    if (pf == NULL)
    {
        return 0;
    }
    int buf[255] = { 0 };
    //方法1：
    //fwrite(arr, sizeof(int), 5, pf);//从第一个元素的地址开始，连续写入5次，每次写入4个字节到pf指向的文件中
    //rewind(pf);
    //fread(buf, sizeof(int), 5, pf);//从第一个元素的地址开始，连续读入5次，每次读入4个字节到buf指向的文件中
    //printf("%d %d %d %d %d", buf[0], buf[1], buf[2], buf[3], buf[4]);
    
    //方法2：
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        fwrite(&arr[i], sizeof(int), 1, pf);//fwrite(arr, sizeof(int), 1, pf); - 这是错误的
    }
    fclose(pf);//这种方式实现读写，需要重新打开文件
    pf = fopen("test15.txt", "r");
    for (i = 0; i < 5; i++)
    {
        fread(&buf[i], sizeof(int), 1, pf);//fread(buf, sizeof(int), 1, pf); - 这是错误的
        printf("%d ", buf[i]);
    }
    fclose(pf);
    pf = NULL;

    //如果s是一个数组，就可以读取多个信息
    return 0;
}
*/
//注意：以上函数如果是写入一个字符串，则文件中最后会多出一个空格，这个空格就是字符串的\0

//总结：
//fgetc/fputc	        适用于任意流，终端输入回车，fgetc可以读取到回车符
//fgets/fputs	        适用于任意流    fgets读取一行字符串，会读取回车符，同时会在字符串结尾自动添加\0. fputs输出不会主动换行。
//getc/putc	            适用于任意流，终端输入回车，getc可以读取到回车符      
//getchar/putchar       适用于任意流，终端输入回车，getchar可以读取到回车符  
//gets/puts             是标准输入输出	从标准输入输出流中读/取数据.puts输出会自动多输出一个换行。
//scanf/printf	        是标准输入输出	从标准输入输出流中读/取数据。scanf读取带空格的字符串，读到空格结束.gets被淘汰了。
//scanf读取终端上的数据时，不会读取回车符，但会在字符串结尾自动添加\0
//fscanf/fprintf	    适用于任意流 	fscanf读取带空格的字符串，读到空格结束，fscanf不会读取回车符，但会在字符串结尾自动添加\0
//fread/fwrite          适用于文件流	fread(buf, sizeof(buf),1, stdin);虽然没有报错，但是无法结束

//sscanf/sprintf        格式化数据与字符串的相互转换，不是输入输出函数
//注意：输出函数，终端输入的回车，读会读走。Windows下的IO操作函数都是带缓冲的。只有puts输出的时候会自动多输出一个换行
//问题：缓冲区的数据读走后，还在吗？
//可以认为是不在了，其实是还在的，
//这可能就涉及到了系统的实现了，我认为系统缓冲区肯定是一个 buffer，用一个指针维护着这个buffer数据，
//当你读走一个数据时候，指针肯定后移了一个位置，但是数据还是在的，除非再有数据进入缓冲区覆盖掉这个位置上的数据。
//但是，这些维护buffer的指针值我们肯定访问不到，因此上说，读走一个数据后，即使是还存在的，我们也无法再访问了，等同于 数据被读走后就不在了。

//注意：使用函数时，需要了解，形参，返回值。

//8. 文件的随机读写
//1 fseek
//int fseek(FILE * stream, long int offset, int origin);
//以origin为起点，根据偏移量offset来，调整文件指针stream的位置。
//origin：SEEK_CUR文件指针的当前位置、 SEEK_END文件指针的末尾位置、SEEK_SET文件指针的起始位置（默认）
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
    if (pf == NULL)
    {
        return 0;
    }
    //1、定位文件指针
    fseek(pf, 4, SEEK_CUR);//从SEEK_CUR位置，向后偏移4
    //2、读取文件
    int ch = fgetc(pf);
    printf("%c\n", ch);//e

    fseek(pf, -2, SEEK_END);//从SEEK_END位置，向前偏移2，不能设置为2
    //2、读取文件
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
//返回值：返回文件指针相对于起始位置的偏移量
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
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
    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
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
    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
    if (pf == NULL)
    {
        return 0;
    }
    //读取文件
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
    pFile = fopen("myfile.txt", "rb");//myfile.txt中含有bit文本
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
//让文件指针的位置回到文件的起始位置
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test.txt", "r");//test.txt中含有abcdef文本
    if (pf == NULL)
    {
        return 0;
    }
    //读取文件
    int ch = fgetc(pf);
    printf("%c\n", ch);//a，此时指针指向的b
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

//9. 文件读取结束的判定
/*
#include <stdio.h>
int main()
{
    //EOF - end of file == -1
    FILE* pf = fopen("test.txt", "r");//test.txt中没有内容(空文件)
    if (pf == NULL)
    {
        return 0;
    }
    //读取文件
    int ch = fgetc(pf);
    printf("%d\n", ch);//-1，说明文件读取结束
    
    fclose(pf);
    pf = NULL;
    return 0;
}
*/
//被错误使用的feof：
//牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束。
//而是应用于当文件读取结束的时候，判断是读取错误而结束，还是遇到文件尾EOF而结束。
//即，feof函数是判断文件是否是因为读取EOF后而结束的
//feof在没有读完的时候，返回0，在读完的时候返回-1，也就是返回EOF。
//1. 文本文件读取是否结束，判断返回值是否为EOF（使用fgetc读取字符，返回EOF或-1），或者NULL（fgets读取字符串，返回NULL）
//例如：
//  fgetc 判断是否为EOF，说明读取结束了。
//  fgetc 函数在读取结束的时候，会返回EOF,正常读取的时候，返回读取到的字符的ASCIIm码值
//  fgets 判断返回值是否为 NULL，说明读取结束了。
//  fgets 函数在读取结束的时候，会返回NULL,正常读取的时候，返回存放字符串空间的起始地址
//2. 二进制文件的读取结束的判断，fread判断返回值是否小于实际要读的个数。
//例如：fread判断返回值小于实际要读的个数，说明读取结束了。
//  fread 函数在读取的时候，返回的是实际读取到的完整元素的个数，如果发现读取到的完整的元素个数小于
//指定的元素个数，这就是最后一次读取了。
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
    //strerror(errno):返回错误码对应的错误信息的字符串地址返回
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
        perror("open file test2.txt");//perror使得错误信息更加明了
        //打印：open file test2.txt：No such file or directory
        return 0;
    }
    //...
    fclose(pf);
    pf = NULL;
}
*/

//正确的使用：
//文本文件的例子：
/*
#include <stdio.h>
int main()
{
    FILE* pf = fopen("test2.txt", "r");
    if (!pf)
    {
        perror("open file test2.txt");//perror使得错误信息更加明了
        return 0;
    }
    //...
    int ch = 0;
    while ((ch = fgetc(pf) != EOF))//EOF=-1，转到定义。注意：EOF的逻辑结果是真
    {
        putchar(ch);//回顾putc函数的使用
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
    //变量的定义放在最前面较好，因为有部分编译器不支持边定义变使用
    int c; // 注意：int，非char，要求处理EOF
    FILE* fp = fopen("test.txt", "r");//test.txt中含有abcdef文本
    if (!fp) //fp为NULL时，报错
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    //fread：功能描述
    //fread返回实际读取的完整项的数量，如果发生错误或在到达计数之前遇到文件结尾，则该数量可能小于计数。
    //使用feof或feror函数来区分读取错误和文件结束情况。如果大小或计数为0，则fread返回0，缓冲区内容不变。

    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
    {
        putchar(c);
    }
    //判断是什么原因结束的
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
    fp = NULL;
}
*/

//二进制文件的例子：
/*
#include <stdio.h>
enum { SIZE = 5 };
int main(void)
{
    double a[SIZE] = { 1,2,3,4,5 };
    FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式
    fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin", "rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // 读 double 的数组
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
    FILE* fp = fopen("test.bin", "wb"); // 必须用二进制模式
    fwrite(a, sizeof(*a), SIZE, fp); // 写 double 的数组
    fclose(fp);
    double b = 0.0;
    fp = fopen("test.bin", "rb");
    while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
    {
        printf("%lf\n", b);
    }
    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    if (feof(fp))
        printf("Error reading test.bin: unexpected end of file\n");
    else if (ferror(fp)) //int ferror( FILE *stream );  Tests for an error on a stream.
    {
        perror("Error reading test.bin");
    }
    fclose(fp);
}
*/

//注意：使用函数时，需要了解，形参，返回值。