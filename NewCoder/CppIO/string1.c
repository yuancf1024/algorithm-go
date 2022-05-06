#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[500];
	scanf("%d\n",&n);//读入数字时连换行符一起读入
	while(n--)
	{
		gets(s);
		printf("%s\n",s);
	}
	return 0;
}