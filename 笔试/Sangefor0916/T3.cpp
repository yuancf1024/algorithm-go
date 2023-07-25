/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 一个长度为n的01串，求出包含最长连续1的子串的个数
 * 
比如 0110
最长连续子串是11
包含它的子串：
0110
011
110
11

答案可能很大，结果对1000000007取模

输入描述：
第一行一个数n
第二行长度为n的01字符串
1<=n<=1000000

输出描述：
包含最长连续1字符串的子串数

示例1：
4
0110

4

备注：如果有多个子串的内容相同，但是在整个字符串中的位置不同
不算做一个子串，需要多次计算
 */

/*
2022-09-16晚上复盘

思路： 最后的l、r取值不太好想

1. 对于包含一个特定子串t的任意字符串，
假设t的左边有l个字符，右边有r个字符，
则满足条件的字符串的个数为(l+1)*(r+1)
2. 对于本题，我们可以枚举每一个具有最长连续1的字符串
把它当作上上一句话的t
需要注意的地方：排除重复的串。自行体会代码中带注释地方的妙处。


*/
#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = str.substr(0, n);
    vector<int> nums{-1};
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            continue;
        }
        int j = i;
        // 滑动窗口找到最长子串的位置和大小
        while (j+1< n && str[j+1] == str[i]) {
            j++;
        }
        int cnt = j - i + 1;
        if (maxLen < cnt) {
            maxLen = cnt;
            nums = vector<int>{-1};
            nums.push_back(i);
        } else if (maxLen == cnt) {
            nums.push_back(i);
        }
        i = j;
    }

    nums.push_back(n);
    const int MOD = 1e9 + 7;
    long long res = 0;
    for (int i = 1, iend = nums.size() - 1; i < iend; ++i) {
        // 仔细想想l和r为什么这么取
        int l = nums[i] - nums[i - 1], r = (n - (nums[i] + maxLen - 1));
        res = (res += 1LL * l * r) % MOD;
    }
    cout << res << endl;
    return 0;
}

// 自己的垃圾代码
// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// ll GetMaxConsecOnes(string& s) { 
//     ll ans = 0, num = 0, l = 0, r = 0; 
//     while (r < s.size()) {
//         if (s[r] == '1') {
//             num++;
//         }
//         while (r-l+1-num > 0) {
//             if (s[l] == '1') {
//                 num--;
//             }
//             l++;
//         }
//         ans = max(ans, r - l + 1);
//         r++;
//     }
//     return ans;
// }

// int main() { 
//     ll n;
//     cin >> n;
//     string str;
//     cin >> str;

//     // 核心代码
//     ll res = 0;
//     ll tmp = 0;
//     // 1. 找出最长连续子串
//     ll maxLongstr = GetMaxConsecOnes(str);


//     cout << maxLongstr << endl;
//     cout << res % 1000000007 << endl;
//     return 0;
// }

