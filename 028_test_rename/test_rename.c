#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//argv[1] is oldpath ; argv[2] is newpath
int main(int argc,char *argv[])
{
	int ret;
	if(argc < 3)
	{
		printf("Please input file path\n");
		return 1;
	}
	
	if((ret = rename(argv[1],argv[2])) < 0)
	{
		printf("rename is error!\n");
	}
		
	printf("rename old_file: %s to new_file: %s success!\n",argv[1],argv[2]);
	
	return 0;
}
