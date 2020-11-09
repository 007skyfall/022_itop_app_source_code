/*函数time头文件*/
#include <time.h>
#include <stdio.h> 
#include <unistd.h>

int main(int argc,char *argv[])
{
	time_t timep;
	
	time(&timep);
	printf("UTC time: %ld\n", timep);

	timep = time(NULL);
	printf("UTC time: %ld\n", timep);

	return 0;
}
