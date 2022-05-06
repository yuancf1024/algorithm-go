#include<iostream>
#include<cstring>
using namespace std;
inline int read()
{
	int x=0,f=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') //保证负数的正确读入 
	{
		if(ch=='-') 
			f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') 
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();//等价于x=x*10+ch-'0'; 
	return f?-x:x;
}
int main()
{
	int a=read();
	cout<<a<<endl;
	return 0; 
}