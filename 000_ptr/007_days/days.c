//7.	输入某个月的第N周和这一周的第M天，通过int *GetDay() 函数获取参数并返回结果，来得出这一天是这个月的第多少天。
//		(如输入：3，4，即这个月的第3周的第4天，即这个月的第18天)


#include <stdio.h>

int *GetDay(int n, int m)
{
	// 在函数返回时，函数内部的局部变量会被销毁
	// static 定义静态变量，这个变量的声明周期是整个源程序，作用域不变
	static int calc[5][7] = 
	{
		{1,2,3,4,5,6,7},
		{8,9,10,11,12,13,14},
		{15,16,17,18,19,20,21},
		{22,23,24,25,26,27,28},
		{29,30,31}
	};
	return &calc[n-1][m-1];
	// 返回数组下标的地址，数组下标是从0开始的，所以要减 1
}

//如果函数返回局部变量的值，程序是不会出错的
//如果函数返回局部变量的地址，虽然你把地址返回了，但是地址里的值已经被销毁了
// 如果其他程序用了这块内存，那么程序执行结果将不可预估


// 作用域： 表示某个变量的作用范围，一般在某个代码块了，用 {} 分隔
// 生命周期： 决定这个变量什么时候被销毁，静态变量的生命周期是整个源程序

int main(int wk, int dy, char Y)
{
//	int a = 0;
	do
	{
//		int b = 0;
		printf("Please input week and day: \n");
		scanf("%d %d", &wk, &dy);
		getchar();
		if(wk > 5 || wk < 1 || dy > 31 || dy < 1)
		{
			printf("Error input! Byebye!\n");
			return 0;
		}

		printf("The days is %d\n", *GetDay(wk, dy));

		printf("If you want again, inpyt 'Y' (other for quit): \n");
		scanf("%c", &Y);


	}while(Y == 'Y');
	printf("\n \n");
	return 0;
}






