//6.	输入一段字符串，无论是否有重复字母出现，都只打印出现过的小写字母，并按照小写字母顺序打印。
//		（如输入qewqwr322rqw<>211qESFSSEraZz， 打印aeqrwz）

#include <stdio.h>
#include <stdlib.h>
#define N 500

int main()
{
	char str1[N] = { 0 };	// 存储用户输入的字符串
	char str2[N] = { 0 };	// 存储要打印的字符串

	scanf("%s", str1);		// 接收用户输入

	int index = 0;			
	for (int i = 0; *(str1 + i) != '\0'; ++i)	// 遍历str1字符串，直到字符串结尾'\0'
	{
		index = *(str1 + i) - 97;				// 取出*(str + i)的字符，减去 小写字母a的ascii码 97，当作数组下标，给index
		*(str2 + index + 97)  = '+';			// 在str2里面，把 index下标的元素置为 + 号，做为标记
	}

	for (int i = 97; i < 26 + 97; ++i)		//	下标从97开始，循环遍历str2
		if( *(str2 + i) == '+')				//	如果遍历到的下标有 + 号标记，之前判断这里是有出现过字母，
			printf("%c ", i);				// 那么就打印这个下标对应的字母ASCII码，也就是打印字母了。

	printf("\n");
	return 0;
}
