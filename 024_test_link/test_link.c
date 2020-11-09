#include <stdio.h>
//link函数头文件
#include <unistd.h>

int main(int argc,char *argv[])
{
	int ret;
	
	if(argc <3)
	{
		printf("Please input file path\n");
		return 1;
	}

//测试link函数
	ret = link(argv[1],argv[2]);
	if(ret)
	{
		printf("link is failed\n");
		return 1;
	}
	printf("link old_file:%s to new_file %s is success!\n",argv[1],argv[2]);
	
	return 0;
}