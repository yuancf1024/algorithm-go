#include"bits/stdc++.h"
using namespace std;
int cal = 0; //统计走的顺序
//棋盘初始化为0做标记
int n, m;
int chress[1000][1000];
#define X n*m
// {
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0,
// 	0, 0, 0, 0, 0, 0, 0, 0
// };

bool ifOut(int x, int y)  //判断是否出界
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
		return false;
	else
		return true;
}
bool ifVisited(int x, int y) //判断是否已经被访问
{
	if (chress[x][y] != 0)
		return true;
	else
		return false;
}
void dfs(int x,int y)
{	
	if (cal == X) //如果遍历完则退出棋盘一共64个位置
		return;
	if (!ifVisited(x, y) && !ifOut(x, y)) //如果没有被访问且没有出界 则访问
	{
		cal++;   
		chress[x][y] = cal; //做标记
		dfs(x + 2, y + 1);	//骑士走法有八个方位，故八个 方位都遍历
		dfs(x - 2, y - 1);  //八个递归的顺序可以改，顺序不一样，结果不一样 
		dfs(x + 2, y - 1);	
		dfs(x - 2, y + 1);	
		dfs(x - 1, y - 2);  
		dfs(x + 1, y - 2);	
		dfs(x + 1, y + 2);	
		dfs(x - 1, y + 2);  
		return;
	}
	else  //出界了则退出return
		return;



}
int main()
{	
    int m, n;
    cin >> m >> n;

	int x, y;
    cin >> x >> y;    //输入坐标
	// cout << "请输入骑士初始的位置：";
	// while (1)
	// {
	// 	cin >> x >> y;    //输入坐标
	// 	if (x > 7 || x<0 || y> 7 || y < 0)
	// 		cout << "初始位置输入错误请重新输入" << endl;
	// 	else
	// 		break;
	// }
	dfs(x,y);
	for (int i = 0; i < n; i++)  //输出打印测试
	{
		for (int j = 0; j < m; j++)
			cout << setw(2)<<chress[i][j]<<" ";
		cout << endl;
	}
	return 0;
}
