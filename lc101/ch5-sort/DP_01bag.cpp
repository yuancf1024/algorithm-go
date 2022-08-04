#include <bits/stdc++.h>

using namespace std;

// 二维DP数组
void test_2_wei_bag_problem1(vector<int>& weight, vector<int>& value, int bagweight) {
    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小，就是物品的个数
    for (int i = 1; i < weight.size(); i++) { // 遍历物品
        for (int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[weight.size() - 1][bagweight] << endl;

    // // 遍历dp数组
    // for (int i = 0; i < dp.size(); i++) {
    //     for (int j = 0; j < dp[1].size(); j++) 
    //         cout << dp[i][j] << " " << endl;
    // }
}

// 一维DP数组 or 滚动数组
void test_1_wei_bag_problem(vector<int>& weight, vector<int>& value, int bagweight) {
    // 初始化
    vector<int> dp(bagweight + 1, 0);

    // 滚动数组
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = bagweight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagweight] << endl;

    // // 遍历dp数组
    // for (int i = 0; i < dp.size(); i++) {
    //     cout << dp[i] << " " << endl;
    // }
}

int main() { 
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    cout << "二维DP数组: " << endl;
    test_2_wei_bag_problem1(weight, value, bagweight);
    cout << "一维DP数组: " << endl;
    test_1_wei_bag_problem(weight, value, bagweight);
    return 0;
}