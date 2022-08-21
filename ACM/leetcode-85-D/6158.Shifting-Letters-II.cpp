/**
 * @file 6158.Shifting-Letters-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6158.字母移位II
 * 
给你一个小写英文字母组成的字符串 s 和一个二维整数数组 shifts ，
其中 shifts[i] = [starti, endi, directioni] 。
对于每个 i ，将 s 中从下标 starti 到下标 endi （两者都包含）
所有字符都进行移位运算，如果 directioni = 1 将字符向后移位，
如果 directioni = 0 将字符向前移位。

将一个字符 向后 移位的意思是将这个字符用字母表中 下一个 字母替换
（字母表视为环绕的，所以 'z' 变成 'a'）。
类似的，将一个字符 向前 移位的意思是将这个字符用字母表中 前一个 字母替换
（字母表是环绕的，所以 'a' 变成 'z' ）。

请你返回对 s 进行所有移位操作以后得到的最终字符串。

示例 1：
输入：s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
输出："ace"

解释：首先，将下标从 0 到 1 的字母向前移位，得到 s = "zac" 。
然后，将下标从 1 到 2 的字母向后移位，得到 s = "zbd" 。
最后，将下标从 0 到 2 的字符向后移位，得到 s = "ace" 。

示例 2:
输入：s = "dztz", shifts = [[0,0,0],[1,1,1]]
输出："catz"

解释：首先，将下标从 0 到 0 的字母向前移位，得到 s = "cztz" 。
最后，将下标从 1 到 1 的字符向后移位，得到 s = "catz" 。
 
提示：

1 <= s.length, shifts.length <= 5 * 104
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s 只包含小写英文字母。
 */

// 参考@TsReaper 差分数组
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> f(n + 1);
        for (auto& vec : shifts) {
            if (vec[2] == 1) {
                f[vec[0]]++;
                f[vec[1] + 1]--;
            }
            else {
                f[vec[0]]--;
                f[vec[1] + 1]++;
            }
        }

        string ans;
        for (int i = 0, delta = 0; i < n; ++i) {
            int c = s[i] - 'a';
            delta += f[i];
            c = ((c + delta) % 26 + 26) % 26;
            ans.push_back(c + 'a');
        }
        return ans;
    }
};

// 参考@鹕 差分数组
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size(), m = shifts.size(); // m代表移位次数
        vector<int> a(n + 1);
        for (int i = 0; i < m; ++i) { // 构造数组
            int temp = 1;
            if (shifts[i][2] == 0) {
                temp = -1;
            }
            a[shifts[i][0]] += temp;
            a[shifts[i][1]+1] -= temp;
        }

        int sum = a[0];
        for (int i = 0; i < n; ++i) { // 加入数组
            int temp = (s[i] - 'a' + sum) % 26;
            if (temp < 0) {
                temp += 26; // 确保temp为正
            }
            s[i] = temp + 'a';
            sum += a[i + 1];
        }
        return s;
    }
};

/**
 * @brief 
 * 参考@TsReaper
 * 差分数组
解法：差分数组
维护字母变化量的差分数组，最后枚举所有下标并计算当前下标的字母变化量即可。
复杂度 O(n)。


前缀和主要适用的场景是原始数组不会被修改的情况下，
频繁查询某个区间的累加和

差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减
 */