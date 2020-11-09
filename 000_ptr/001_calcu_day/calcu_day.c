//1.	输入年份、和这一年的第N天，最后算出这一天是这一年的几月几日。(区分闰年)
#include <stdio.h>
int main(void)
{
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year, days, leapyear;
	printf("Plz input year and how many days: \n");
	scanf("%d,%d", &year, &days);

	if(days > 366)				//错误判断
	{
		printf("Error input!\n");
		return 0;
	}

	leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	// 闰年判断条件：能被4整除，但是不能被100整除；能被400整除
	// 如果上面表达式成立，则返回 1， 表示这一年是闰年

	if(leapyear)
		*(month + 1) = 29;
	// 如果leapyear 是 1， 就把二月的天数改为29天

	int i;	// i 表示每次跳跃的月份
	for (i = 0; days > *(month + i); ++i)
		days -= *(month + i);
	// 循环判断：只要我们输入的天数大于第i个月的天数，那么就一直减下一个月的天数
	// 一直减到不大于当前月份的天数，那么剩下的天数，就是当前月所在的那一天

	printf("Year = %d, month = %d, days = %d\n", year, i + 1, days);
	// 打印最后的结果

	return 0;

}
