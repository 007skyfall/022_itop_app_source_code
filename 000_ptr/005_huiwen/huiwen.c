//5.	输入一个字符串，判断其是否是回文。(回文：即正读和反读都一样，如abcba, abccba)

#include <stdio.h>
#include <string.h>
#define N 50	//假如你不是神经病，50个够了

int func(char *p, int len)		// 获取字符串的首地址，和字符串长度
{
	for(int i = 0; i < len / 2; ++i)	// 循环次数是字符串长度的一半
		if( *(p + i) != *(p + len - i - 1))	// 比较前面的字符和后面的字符是否不等
			return 0;						// 如果不相等，就返回0，表示字符串不是回文
	return 1;							// 如果循环接收一直没有返回 0， 则表示字符串是回文，返回1 给调用函数
}

int main1(void)
{
	char str[N] = { 0 };			// 创建一个长度为50的字符串
	scanf("%s", str);				// scanf()接收用户输入的字符串

	if(func(str, strlen(str)))		// 这里做了三步：1.获取字符串长度，并且和字符串首地址一起传给被调用函数的形参
									// 2. 调用了func()函数，同时接收函数的返回值
									// 3. 接收函数的返回值，决定了分支语句的执行
		printf("Yes! %s is huiwen! \n", str);
	else
		printf("Sorry! %s is not huiwen! \n", str);
	return 0;
}

int main(int argc, char *argv[])
{
	if(func(argv[1], strlen(argv[1])))		// 这里做了三步：1.获取字符串长度，并且和字符串首地址一起传给被调用函数的形参
											// 2. 调用了func()函数，同时接收函数的返回值
											// 3. 接收函数的返回值，决定了分支语句的执行
		printf("Yes! %s is huiwen! \n", argv[1]);
	else
		printf("Sorry! %s is not huiwen! \n", argv[1]);
	return 0;
}
