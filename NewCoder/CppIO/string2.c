#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[500];
	scanf("%d",&n);
	getchar();//在读入数字之后，利用getchar()吞掉回车字符
	while(n--)
	{
		gets(s);
		printf("%s\n",s);
	}
	return 0;
}
