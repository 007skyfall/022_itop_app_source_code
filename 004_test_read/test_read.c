//标准输入输出头文件
#include <stdio.h>
//文件操作函数头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc,char *argv[])
{
	int fd;
	ssize_t length_w,length_r = MAX_SIZE;
	ssize_t ret;
	char *testwrite = "./testwrite";
	char buffer_write[] = "Hello Write Function!";
	char buffer_read[MAX_SIZE];
	
	if((fd = open(testwrite,O_RDWR|O_CREAT,0664))<0)
	{
		printf("open %s is failed!\n",testwrite);
	}
	
	length_w = write(fd,buffer_write,strlen(buffer_write));
	if(length_w == -1)
	{
		perror("write");
	}
	else
	{
		printf("Write Function OK!\n");
	}
	close(fd);
	
	if((fd = open(testwrite,O_RDWR|O_CREAT,0664))<0)
	{
		printf("open %s is failed!\n",testwrite);
	}
	
	if((ret = read(fd,buffer_read,length_r)) < 0)
	{
		perror("read");
	}
	printf("Files Content is %s \n",buffer_read);
	close(fd);
	
return 0;
}
