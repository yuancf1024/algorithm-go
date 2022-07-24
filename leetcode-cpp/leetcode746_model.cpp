#include <bits/stdc++.h>

using namespace std;

// leetcode 代码
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

// 主函数
int main() { 
    // 在这里定义好函数中的测试数据
    int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> cost(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    // 输出leetcode中的主函数
    cout << solution.minCostClimbingStairs(cost) << endl;
}

/*
int main() {
    //构造vector数组
    int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> num(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    
    //函数返回值是int 可直接输出
    cout << solution.函数名(传参假设是num) << endl;
    
    //函数返回值是vector，不可用cout直接输出
    vector<int>res =  solution.函数名(num)；
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    
    //二维数组定义及输出
    int N=5, M=6; 
    vector<vector<int> > obj(N, vector<int>(M)); //定义二维动态数组5行6列 
    for(int i=0; i< obj.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<obj[i].size();j++)
        {
            cout<<obj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
*/