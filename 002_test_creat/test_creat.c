//标准输入输出头文件
#include <stdio.h>
//文件操作函数头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char * argv[])
{
	int fd;
	char *leds = "./test.txt";
	char *test1 = "home/skyfall/test1";
	char *test2 = "home/skyfall/test2";
	//需要新建的文件test3
	char *test3 = "./test3";
	
	//使用open函数打开文件
	if((fd = open(leds, O_RDWR|O_NOCTTY|O_NDELAY))<0)
	{
		printf("open %s is failed\n",leds); 
	}
		printf("%s fd is %d\n",leds,fd);
	
	//使用open函数打开不存在的文件，不添加O_CREAT标识符，会报错
	if((fd = open(test1, O_RDWR))<0)
	{
		printf("open %s failed\n",test1); 
	}
	//打开文件创建文件，添加标志位O_CREAT表示不存在这个文件则创建文件
	if((fd = open(test2, O_RDWR|O_CREAT,0664))<0)
	{
		printf("open %s failed\n",test2); 
	}
		printf("%s fd is %d\n",test2,fd);
	
	fd = creat(test3,0777);
	if(fd == -1)
	{
		printf("%s fd is %d\n",test3,fd);
	}
	else
	{
		printf("create %s is succeed\n",test3);
	}
return 0;
}
