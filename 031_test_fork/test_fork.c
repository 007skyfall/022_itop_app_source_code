#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int i=100;
	
	pid = fork();
	//调用出错
	if(pid == -1)
	{
		printf("fork is failed\n");
		return 1;
	}
	
	//返回给父进程子进程号，返回值大于0
	else if(pid)
	{
		i++;
		printf("The father i = %d\n",i);
		printf("The father return value is %d\n",pid);
		printf("The father pid is %d\n",getpid());
		printf("The father ppid is %d\n",getppid());
		while(1);
	}
	//返回子进程0，返回值等于0返回给子进程
	else
	{
		i++;
		printf("The child i = %d\n",i);
		printf("The child return value is %d\n",pid);
		printf("The child pid is %d\n",getpid());
		printf("The child ppid is %d\n",getppid());
		while(1);
	}
	
return 0;
}