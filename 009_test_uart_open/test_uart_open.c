#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main( int argc,char *argv[] )
{
	int fd;
	char *uart3 = "/dev/ttySAC3";
	
	if((fd = open(uart3,O_RDWR|O_CREAT,0777))<0)
	{
		printf("open %s is failed!\n",uart3);
	}
	else
	{
		printf("open %s is success!\n",uart3);
	}
	
	close(fd);
return 0;
}
