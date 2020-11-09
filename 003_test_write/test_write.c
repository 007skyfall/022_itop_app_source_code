//标准输入输出头文件
#include <stdio.h>
//文件操作函数头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int fd;
	char *testwrite = "./testwrite";
	ssize_t length_w;
	char buffer_write[] = "Hello Write Function!";

	if((fd = open(testwrite, O_RDWR|O_CREAT,0664))<0)
	{
		printf("open %s is failed\n",testwrite); 
	}
	
	//将buffer写入fd文件
	length_w = write(fd,buffer_write,strlen(buffer_write));
	if(length_w == -1)
	{
		perror("write");
	}
	else
	{
		printf("Write Function OK!\n");
	}
	printf("buffer_write = %s\n",buffer_write);
	close(fd);
	
return 0;
}
