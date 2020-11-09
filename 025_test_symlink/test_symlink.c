#include <stdio.h>
//symlink函数头文件
#include <unistd.h>

int main(int argc,char *argv[])
{
	int ret;
	
	if(argc <3)
	{
		printf("Please input file path\n");
		return 1;
	}

//测试symlink函数
	ret = symlink(argv[1],argv[2]);
	if(ret)
	{
		printf("symlink is failed\n");
		return 1;
	}
	
	printf("symlink old_file: %s to new_file: %s is success!\n",argv[1],argv[2]);
	
	return 0;
}