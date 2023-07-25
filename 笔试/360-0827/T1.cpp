/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * DNA匹配
 * 题目描述：
有一种特殊的DNA，仅仅由核酸A和T组成，长度为n，顺次连接
科学家有一种新的手段，可以改变这种DNA。
每一次，科学家可以交换该DNA上两个核酸的位置，
也可以将某个特定位置的核酸修改为另一种核酸。

现在有一个DNA，科学家希望将其改造成另一种DNA，
希望你计算最少的操作次数。

输入描述
输入包含两行，第一行为初始的DNA，
第二行为目标DNA，保证长度相同。

输出描述
输出最少的操作次数

样例输入
ATTTAA
TTAATT

样例输出
3

提示
对于100%的数据，DNA长度小于等于100000

样例解释：
1.首先修改第一个位置的核酸（从A修改为T）
2.交换3和5位置的核酸
3.交换4和6位置的核酸
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int res = 0;
    string str1, str2;
    cin >> str1;
    cin >> str2;

    // 核心代码
    /*
    思路：遍历两个字符串，用哈希表记录
    不相同字母"A", "T"的数量
    - 如果为偶数，返回n/2
    - 如果为奇数，返回n-1/2 + 1

    上面的思路只过了18%
    还需要优化的地方：
    直接取不相同字母'A'或'T'的最大值即可
    AC!😂
    */

    int n = str1.size();
    // int num = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < n; ++i) {
        if (str1[i] != str2[i]) {
            // num++;
            map[str1[i]]++;
        }
    }
    // res = abs(map['T'] - map['A']);
    res = max(map['A'], map['T']);
    // if (num % 2 == 0) {
    //     res = num / 2;
    // } else {
    //     res = (num - 1) / 2 + 1;
    // }
    cout << res << endl;
    return 0;
}