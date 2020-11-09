//3.	通过随机函数获取到26个小写英文字母，存储到数组里并小写字母顺序打印出来。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 26

void func(char *s)
{
	srand((unsigned int)time(NULL));
	int n = 0;
	while(n < LEN) // 循环条件是，数组存满了26个字母
	{
		int temp = rand() % LEN;// 设定一个变量用来接收 0~25 的随机数
		if(*(s + temp) == 0)	// 如果数组里的某个下标的值是 0，那么就进入后面的语句，
								//如果数组里的某个下标的值是字母，说明就赋值过了，就不执行后面的语句
		{
			*(s + temp) = temp + 'a'; 	// 把随机到的数字，加上字符'a'，隐式转换成字母，对应下标存放到字符数组里
			n++;	// 每次放入一个正确的字母，n就自增1，
		}
	}
}

int main()
{
	char a[LEN] = { 0 };
	func(a);
	for (int i = 0; i < LEN; ++i)
			printf("%c\n", *(a + i));
	printf("\n");
	return 0;
}
