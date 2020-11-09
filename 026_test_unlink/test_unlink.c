#include <stdio.h>
//unlink函数头文件
#include <unistd.h>

int main(int argc,char *argv[])
{
	int ret;
	
	if(argc <2)
	{
		printf("Please input file path\n");
		return 1;
	}

//测试unlink函数
//unlink指向软链接，删除软链接；指向最后一个硬链接，相当于删除文件
	ret = unlink(argv[1]);
	if(ret)
	{
		printf("unlink is failed\n");
		return 1;
	}
	printf("unlink %s is success!\n",argv[1]);
	
	return 0;
}