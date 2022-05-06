#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b&&(a||b)) // a b 都为0时才为0
	{
		cout<<a+b<<endl;
	}
	return 0;
}
