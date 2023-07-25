/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小乐虎买基金 10分
 * 
 * 小乐虎省吃俭用攒了10万元，准备用于投资。
 * 小乐虎选择了相对稳健的基金作为投资标，他想利用所学
 * 建模来估算基金的收益情况。
 * 
 * 假定数组funds记录某只基金的价格，第n个元素表示该基金
 * 第n天的价格。小乐虎在某一天买入基金，在未来某一天卖出，
 * 需要设计一个算法计算该基金所能获得的最大收益、
 * 
 * 返回小乐虎可以从这次基金交易中获取的最大收益。
 * 如果无法获取收益，返回0.
 * 
示例1：
[7,2,5,1,6,4]

5

示例2：
[7,5,4,3,1]

0

备注：
1<=funds.length<=10^5
0<=funds[i]<=10^4

 */

#include <bits/stdc++.h>

using namespace std;

/*
参考股票问题 AC
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 基金最大收益
     * @param funds int整型vector 基金价格
     * @return int整型
     */
    int maxIncome(vector<int>& funds) {
        // write code here
        int left = INT_MAX;
        int res = 0;
        for (int i = 0; i < funds.size(); ++i) {
            left = min(left, funds[i]);
            res = max(res, funds[i] - left);
        }
        return res;
    }
};

int main() { 
    vector<int> nums = {7, 2, 5, 1, 6, 4};

    Solution s;
    int res = s.maxIncome(nums);
    cout << res << endl;
    return 0;
}