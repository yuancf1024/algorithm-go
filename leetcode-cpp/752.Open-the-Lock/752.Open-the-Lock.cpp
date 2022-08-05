/**
 * @file 752.Open-the-Lock.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * leetcode-752. 打开转盘锁
 * 
 * 你有一个带有四个圆形拨轮的转盘锁。
 * 每个拨轮都有10个数字：
 * '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
 * 每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。
 * 每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，
这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，
如果无论如何不能解锁，返回 -1 。

示例 1:
输入：deadends = ["0201","0101","0102","1212","2002"], 
target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。

示例 2:
输入: deadends = ["8888"], target = "0009"
输出：1
解释：把最后一位反向旋转一次即可 "0000" -> "0009"。

示例 3:
输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：无法旋转到目标数字且不被锁定。

提示：

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target 不在 deadends 之中
target 和 deadends[i] 仅由若干位数字组成
 */

// 方法一：广度优先搜索
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 如果 target 就是初始数字 0000，那么直接返回答案 0
        if (target == "0000") {
            return 0;
        }

        // 如果初始数字 0000 出现在 deadends 中，那么直接返回答案 −1
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }

        // 向前旋转
        auto num_prev = [](char x) -> char { 
            return (x == '0' ? '9' : x - 1); 
        };
        // 向后旋转
        auto num_succ = [](char x) -> char { 
            return (x == '9' ? '0' : x + 1); 
        };

        // 枚举status通过一次旋转得到的数字
        auto get = [&](string& status) -> vector<string> { 
            vector<string> ret;
            for (int i = 0; i < 4; ++i) { // 遍历4个字符位置
                char num = status[i];
                status[i] = num_prev(num); // 向前旋转的状态
                ret.push_back(status);
                status[i] = num_succ(num); // 向后旋转的状态
                ret.push_back(status);
                status[i] = num; // 恢复遍历时的初始状态
            }
            return ret;
        };

        // 初始化队列和哈希表
        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = {"0000"};

        // BFS
        while (!q.empty()) {
            auto [status, step] = q.front(); // 队首出队
            q.pop();
            for (auto&& next_status: get(status)) { 
                if (!seen.count(next_status) && !dead.count(next_status)) { // 没有被搜索过
                    if (next_status == target) { // 找到目标，直接返回对应的旋转次数
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1); // 将 (next_status,step+1) 加入队列
                    seen.insert(move(next_status));
                }
            }
        }
        return -1;
    }
};

/**
 * @brief leetcode题解
 * 方法一：广度优先搜索
思路与算法

我们可以使用广度优先搜索，找出从初始数字 0000 到解锁数字 target 的最小旋转次数。

具体地，我们在一开始将 (0000,0) 加入队列，并使用该队列进行广度优先搜索。
在搜索的过程中，设当前搜索到的数字为 status，旋转的次数为step，
我们可以枚举 status 通过一次旋转得到的数字。
设其中的某个数字为 next_status，如果其没有被搜索过，
我们就将 (next_status,step+1) 加入队列。
如果搜索到了 target，我们就返回其对应的旋转次数。

为了避免搜索到死亡数字，我们可以使用哈希表存储 deadends 中的所有元素，
这样在搜索的过程中，我们可以均摊 O(1) 地判断一个数字是否为死亡数字。
同时，我们还需要一个哈希表存储所有搜索到的状态，避免重复搜索。

如果搜索完成后，我们仍没有搜索到 target，说明我们无法解锁，返回 −1。

细节
本题中需要注意如下两个细节：
- 如果 target 就是初始数字 0000，那么直接返回答案 0；
- 如果初始数字 0000 出现在 deadends 中，那么直接返回答案 −1。

复杂度分析
- 时间复杂度：O(b^d*d^2+md)，其中 b 是数字的进制，d 是转盘数字的位数，
m 是数组 deadends 的长度，在本题中 b=10，d=4。
    - 转盘数字的可能性一共有b^d种，这也是我们可以搜索到的状态数上限。
    对于每一个转盘数字，我们需要 O(d) 的时间枚举旋转的数位，
    同时需要 O(d) 的时间生成旋转后的数字（即加入队列），
    因此广度优先搜索的总时间复杂度为 O(b^d*d^2)。
    - 此外，在搜索前我们需要将 deadends 中的所有元素放入哈希表中，
    计算一个字符串哈希值需要的时间为 O(d)，因此需要的总时间为 O(md)。

- 空间复杂度：O(b^d*d+m)
    - 我们最多需要在队列中存储 O(b^d)个长度为 d 的字符串，
    空间复杂度为 O(b^d*d)
    - 哈希表需要 O(m) 的空间。如果使用的语言存储的是元素的拷贝，
    那么需要的空间为 O(md)。
 */

// 方法二：启发式搜索