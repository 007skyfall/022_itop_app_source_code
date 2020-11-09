#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//argv[1] is oldpath ; argv[2] is newpath
#define LENTH 1024

int main(int argc,char *argv[])
{
	int fd_src,fd_dst;
	char buffer[LENTH];
	char *old_file,*new_file;
	
	old_file = argv[1];
	new_file = argv[2];
	
	if(argc <3)
	{
		printf("Please input file path\n");
		return 1;
	}

	//打开oldpath		
	fd_src = open(old_file,O_RDWR);
	if(fd_src<0)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	
	//打开newpath,如果没有则创建目标文件
	fd_dst = open(new_file,O_RDWR|O_CREAT,0664);
	if(fd_dst<0)
	{
		printf("Please make sure file path\n");
		return 1;
	}

	//读和写操作
	while(read(fd_src,buffer,LENTH))
	{
		write(fd_dst,buffer,strlen(buffer));
	}
	
	//关闭文件
	close(fd_src);
	close(fd_dst);
	
	printf("cp to finished!\n");
	printf("cp %s to %s success!\n",old_file,new_file);
	
	return 0;
}
