//4.	将字符串“We Are Family!”，去除空格后打印出来。（WeAreFamily!）

#include <stdio.h>

char *func(char *p) //定义一个指针函数，返回值是一个指针，该函数的参数是一个指针变量
{
	int i = 0;	// 创建两个变量，用力啊表示数组的下标
	int j = 0;
	// 字符串还是那个字符串，只是下标有两个

	for (; *(p + i) != '\0'; ++i)	// 循环条件是知道字符串结尾'\0',在此之前，i一直自增
		if( *(p + i) != ' ')		// 如果数组的第i位不为空，那么就执行后面的语句
			*(p + j++) = *(p + i);	// 那么就把第i位下标的元素，替换第j位下标的元素，替换完成后，j自增1
		//如此虚幻，只要是不为空格，i 和 j都会自增，并且做替换；如果是空格，那么u会自增，j不动

	*(p + j) = '\0'; 	// 最后，将字符串的第j位置为'\0'
	return p;			// 返回字符串首地址给调用函数
}

int main()
{
	char str[] = "We Are Family!";

	printf("This string is = %s\n", str);
	printf("After delete spaces = %s\n", func(str)); // 函数在此处调用，同时接收返回值

	return 0;
}
