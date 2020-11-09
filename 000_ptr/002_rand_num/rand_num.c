//2.	取十个1-100的随机整数，然后倒序打印出来。(通过指针，而不是数组下标)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


// 这个函数是获取1~100的随机数，并存储到数组num里
void func(int *num)
{
	srand((unsigned int)time(NULL));
	// srand()函数初始化随机数种子，rand()产生随机数
	for (int i = 0; i < N; ++i)
		printf("num[%d] = %d.\n", i, *(num + i) = rand() % 100 + 1 );
	// 循环产生0~99的随机数，再加上1， 放入num里，同时打印出来
}

int main()
{
	int num[N] = { 0 };
	int *p = num;
	func(num);	// 把数组首地址传入函数func()里

	for(p = num + N - 1; p >= num; --p)
		printf("%d ", *p);
	// 把p的下标移动到数组的最后一位，然后从后往前循环遍历，
	// 如果当前下标的地址大于数组的首地址，那就每次往前移动一个int，同时打印出来

	printf("\n");
	return 0;
}
