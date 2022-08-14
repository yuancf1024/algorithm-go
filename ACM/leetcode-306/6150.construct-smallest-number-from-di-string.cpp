/**
 * @file 6150.construct-smallest-number-from-di-string.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6150.根据模式串构造最小数字
给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。

你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：

num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
请你返回满足上述条件字典序 最小 的字符串 num。

 

示例 1：
输入：pattern = "IIIDIDDD"
输出："123549876"

解释：
下标 0 ，1 ，2 和 4 处，我们需要使 num[i] < num[i+1] 。
下标 3 ，5 ，6 和 7 处，我们需要使 num[i] > num[i+1] 。
一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
"123549876" 是满足条件最小的数字。
注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。

示例 2：

输入：pattern = "DDD"
输出："4321"
解释：
一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
"4321" 是满足条件最小的数字。
 

提示：

1 <= pattern.length <= 8
pattern 只包含字符 'I' 和 'D' 

 */

/*
注意理解题意:
  I I I
1 2 3 4

  I I I D D D
1 2 3 4 7 6 5
第一个数一定是1,后面n个字符才对应数字.
*/

// 贪心 理解难度高
class Solution {
public:
    string smallestNumber(string pattern) { 
        int i = 0, n = pattern.size();
        char cur = '1';
        string ans(n + 1, 0);
        while (i < n) {
            // 注意这个条件判断
            if (i && pattern[i] == 'I') { // 前一段都是I
                ++i;
            }
            for (; i < n && pattern[i] == 'I'; ++i) {
                ans[i] = cur++;
            }
            int i0 = i; // D的起点
            while (i < n && pattern[i] == 'D') { // 后一段都是D
                ++i;
            }
            // pattern[i0:i] 都是D  相当于反转了后半部分(DDD...)
            for (int j = i; j >= i0; --j) {
                ans[j] = cur++;
            }
        }
        return ans;
    }
};

/**
 * @brief 
 * 方法1:贪心 参考@灵茶山艾府
贪心策略：
把 pattern 按照III⋯IDDD⋯D 分组，每组前一段是 I，后一段是 D。

遍历每一段，设当前段的长度为 x，
我们应该把剩余最小的 x 个数字填到该段上
（如果是第一段则填最小的 x+1 个数字），从而保证字典序最小。

举例说明，假如第一段为IIIDDD，构造方案如下：

- 前 2 个 I 视作长度为 3 的上升段；
- 剩余的I 和D 视作长度为 4 的下降段；
- 最小的 3 个数给上升段，然后剩余最小的 4 个数给下降段；
构造结果为 1237654。

按照该方案分组模拟即可。

方法2: DFS 参考@TsReaper
解法：搜索
通过深度优先搜索枚举字符串每一位应该填什么数。
只要从小到大枚举数，找到的第一个答案就是字典序最小的答案。
复杂度O(n!)，其中 n 是 pattern 的长度。

 */

// 搜索 也不好理解
class Solution {
    string pattern, ans;
    bool used[10], ok;

public:
    string smallestNumber(string pattern) { 
        this->pattern = pattern;
        dfs(0);
        return ans;
    }

    // 辅函数
    void dfs(int pos) {
        if (pos > pattern.size()) {
            ok = true;
            return;
        }
        for (int i = 1; i <= 9; ++i) {
            if (!used[i]) {
                if (pos > 0) {
                    int last = ans.back() - '0';
                    if (pattern[pos-1] == 'I') {
                        if (i < last)
                            goto FALLED;
                    } else {
                        if (i > last)
                            goto FALLED;
                    }
                }
                ans.push_back(i + '0');
                used[i] = true;
                dfs(pos + 1);
                if (ok) {
                    return;
                }
                used[i] = false;
                ans.pop_back();
                FALLED:
                    continue;
            }
        }
    }
};