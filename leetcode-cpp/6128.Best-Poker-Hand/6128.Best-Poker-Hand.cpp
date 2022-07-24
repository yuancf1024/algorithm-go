/* 6128. 最好的扑克手牌
给你一个整数数组 ranks 和一个字符数组 suit 。
你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，
花色为 suits[i] 。

下述是从好到坏你可能持有的 手牌类型 ：

1. "Flush"：同花，五张相同花色的扑克牌。
2. "Three of a Kind"：三条，有 3 张大小相同的扑克牌。
3. "Pair"：对子，两张大小一样的扑克牌。
4. "High Card"：高牌，五张大小互不相同的扑克牌。

请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。

注意：返回的字符串 大小写 需与题目描述相同。

示例 1：
输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
输出："Flush"
解释：5 张扑克牌的花色相同，所以返回 "Flush" 。

示例 2：
输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
输出："Three of a Kind"
解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。

示例 3：
输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
输出："Pair"
解释：第一和第二张牌大小相同，所以得到 "Pair" 。
我们无法得到 "Flush" 或者 "Three of a Kind" 。

提示：

ranks.length == suits.length == 5
1 <= ranks[i] <= 13
'a' <= suits[i] <= 'd'
任意两张扑克牌不会同时有相同的大小和花色。
*/

#include <bits/stdc++.h>

using namespace std;

// 参考大佬 @TsReaper
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // 记录花色种类的 set
        set<char> st;
        // 记录每个数字出现几次
        map<int, int> mp;
        // 初始化
        for (int x : ranks) mp[x]++;
        for (char c : suits) st.insert(c);

        // 只有一种花色
        if (st.size() == 1)
            return "Flush";
        int mx = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            mx = max(mx, it->second);
        }

        // 判断出现最多的数字出现了几次
        if (mx >= 3)
            return "Three of a Kind";
        else if (mx == 2)
            return "Pair";
        else
            return "High Card";
    }
};

/*
解题思路：
根据题意模拟，题目要求选出最好的牌，4种类型的牌对应有优先级，应按顺序考虑。
同花"Flush"要求花色相同，可使用set数据结构，具有自动去重功能，
当set.size()==1时，说明花色相同；
三条、对子、高牌对每张牌的大小有要求，可使用hash表存储某大小牌的数量，
遍历数组ranks，更新hash表中值it->second 对应的max值。
最后条件判断。
*/

// 主函数
int main() { 
    // 在这里定义好函数中的测试数据
    int a[] = {13,2,3,1,9};
    vector<int> ranks(a, a + sizeof(a) / sizeof(int));
    
    char b[] = {'a','a','a','a','a'};
    vector<char> suits(b, b + sizeof(b) / sizeof(char));
    
    
    Solution solution;
    // 输出leetcode中的主函数
    cout << solution.bestHand(ranks, suits) << endl;
}