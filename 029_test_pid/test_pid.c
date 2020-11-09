#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	
	pid_t id_p,id;
	
	id_p = getppid();
	printf("ppid = %d\n",id_p);
	
	id = getpid();
	printf("pid = %d\n",id);
	
return 0;
}