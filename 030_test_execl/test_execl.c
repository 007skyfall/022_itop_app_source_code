#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

//exec函数族
int main(int argc,char *argv[])
{
	if(execl("./test/test_helloexec","test_helloexec","execl123",NULL) == -1)
	{
		perror("execl error");
		exit(1);
	}
	//程序已经跳转走，如果正常execl不返回错误，下面的代码不会执行！
	printf("execl error！\n");
return 0;
}
