/**
 * @file 771.Jewels-and-Stones.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-771.宝石与石头
 * @version 0.1
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个字符串 jewels 代表石头中宝石的类型，
另有一个字符串 stones 代表你拥有的石头。 
stones 中每个字符代表了一种你拥有的石头的类型，
你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。

示例 1：
输入：jewels = "aA", stones = "aAAbbbb"
输出：3

示例 2：
输入：jewels = "z", stones = "ZZ"
输出：0
 
提示：

1 <= jewels.length, stones.length <= 50
jewels 和 stones 仅由英文字母组成
jewels 中的所有字符都是 唯一的
 */

#include <bits/stdc++.h>

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsCount = 0;
        unordered_set<char> jewelsSet;
        int jewelsLength = jewels.length(), stonesLength = stones.length();
        for (int i = 0 ; i < jewelsLength; i++) {
            char jewel = jewels[i];
            jewelsSet.insert(jewel); 
        }

        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            if (jewelsSet.count(stone)) {
                jewelsCount++;
            }
        }
        return jewelsCount;
    }
};

using namespace std;

int main() {

    string jewels = "aA", stones = "aAAbbbb";
    int res = Solution().numJewelsInStones(jewels, stones);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 方法二：哈希集合
思路与算法

方法一中，对于字符串stones中的每个字符，
都需要遍历一次字符串 jewels，导致时间复杂度较高。
如果使用哈希集合存储字符串jewels 中的宝石，
则可以降低判断的时间复杂度。

遍历字符串jewels，使用哈希集合存储其中的字符，
然后遍历字符串stones，对于其中的每个字符，
如果其在哈希集合中，则是宝石。

复杂度分析

时间复杂度：O(m+n)，其中 m 是字符串jewels的长度，
n是字符串 stones的长度。遍历字符串jewels 
将其中的字符存储到哈希集合中，时间复杂度是 
O(m)，然后遍历字符串stones，
对于stones中的每个字符在 
O(1) 的时间内判断当前字符是否是宝石，
时间复杂度是 O(n)，因此总时间复杂度是 O(m+n)。

空间复杂度：O(m)，其中m是字符串jewels 的长度。
使用哈希集合存储字符串 jewels 中的字符。
 */

