#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)//while(t--)等价于while((t--)!=0)
	{
		int a,b;
		cin>>a>>b;
		cout<<a+b<<endl;// 注意换行
	}
	return 0;
}