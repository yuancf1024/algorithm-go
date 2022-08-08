/**
 * @file 269.Alien-Dictionary.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * leetcode-114. 外星文字典
 * 
现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。

给定一个字符串列表 words ，作为这门语言的词典，
words 中的字符串已经 按这门新语言的字母顺序进行了排序 。

请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。
若不存在合法字母顺序，返回 "" 。
若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。

字符串 s 字典顺序小于 字符串 t 有两种情况：

- 在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中
位于 t 中字母之前，那么 s 的字典顺序小于 t 。
- 如果前面 min(s.length, t.length) 字母都相同，
那么 s.length < t.length 时，s 的字典顺序也小于 t 。
 

示例 1：
输入：words = ["wrt","wrf","er","ett","rftt"]
输出："wertf"

示例 2：
输入：words = ["z","x"]
输出："zx"

示例 3：
输入：words = ["z","x","z"]
输出：""
解释：不存在合法字母顺序，因此返回 "" 。
 
提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 仅由小写英文字母组成
 */

// 拓扑排序 + 深度优先搜索
class Solution {
public:
    const int VISITING = 1, VISITED = 2; // 标记状态：1访问中，2已访问
    unordered_map<char, vector<char>> edges; // 图映射：字母 -> 边
    unordered_map<char, int> states; // 哈希表：记录节点状态
    bool valid = true; // 有效图 -> 无环
    string order; // 外星文的合法字母顺序
    int index;
    string alienOrder(vector<string>& words) { 
        int length = words.size();
        for (string& word : words) { // 遍历字符串列表
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) { // 遍历字符串
                char c = word[j];
                if (!edges.count(c)) { // 字母c在图中没有出现过
                    edges[c] = vector<char>(); // 新增图节点
                }
            }
        }
        for (int i = 1; i < length && valid; ++i) { // 连接图节点，建边
            addEdge(words[i - 1], words[i]);
        }
        order = string(edges.size(), ' ');
        index = edges.size() - 1;
        for (auto [u, _] : edges) { // 遍历edges的key即单个字母节点
            if (!states.count(u)) { // u未访问过
                dfs(u); // 深度优先搜索
            }
        }
        if (!valid) { // 无效图 -> 有环
            return "";
        }
        return order;
    }

    void addEdge(string before, string after) {
        int length1 = before.size(), length2 = after.size();
        int length = min(length1, length2);
        int index = 0;
        while (index < length) { // 从左到右遍历
            char c1 = before[index], c2 = after[index];
            if (c1 != c2) { // 当遇到第一个不相同的字母时，该位置的两个字母之间存在顺序关系
                edges[c1].emplace_back(c2);
                break; // 结束判断
            }
            index++;
        }
        if (index == length && length1 > length2) { // 出现不合法的字母顺序 “ab",“a" 或 “a",“b",“a"
            valid = false;
        }
    }
    void dfs(char u) { 
        states[u] = VISITING; // 将节点u标记为访问中
        for (char v : edges[u]) { // 遍历u的邻接节点
            if (!states.count(v)) { // 如果邻接节点未访问
                dfs(v); // 继续DFS
                if (!valid) { // 如果有环 直接返回
                    return;
                }
            } else if (states[v] == VISITING) { // 如果邻接节点v也为访问中 说明有环
                valid = false;
                return;
            }
        }
        states[u] = VISITED; // 已访问
        order[index] = u; // 直接放到数组末尾。由于最终的拓扑排序是栈顶到栈底
        index--;
    }
};

/**
 * @brief 
 * 
前言
这道题是拓扑排序问题。外星文字典中的字母和字母顺序可以看成有向图，
字典顺序即为所有字母的一种排列，满足每一条有向边的起点字母和终点字母的
顺序都和这两个字母在排列中的顺序相同，该排列即为有向图的拓扑排序。

只有当有向图中无环时，才有拓扑排序，且拓扑排序可能不止一种。
如果有向图中有环，则环内的字母不存在符合要求的排列，因此没有拓扑排序。

使用拓扑排序求解时，将外星文字典中的每个字母看成一个节点，
将字母之间的顺序关系看成有向边。对于外星文字典中的两个相邻单词，
同时从左到右遍历，当遇到第一个不相同的字母时，该位置的两个字母之间
即存在顺序关系。

以下两种情况不存在合法字母顺序：

- 字母之间的顺序关系存在由至少 2 个字母组成的环，例如 
words=[“a",“b",“a"]；

- 相邻两个单词满足后面的单词是前面的单词的前缀，
且后面的单词的长度小于前面的单词的长度，例如 
words=[“ab",“a"]。

其余情况下都存在合法字母顺序，可以使用拓扑排序得到字典顺序。

拓扑排序可以使用深度优先搜索或广度优先搜索实现，以下分别介绍两种实现方法。


方法一：拓扑排序 + 深度优先搜索


使用深度优先搜索实现拓扑排序的总体思想是：
对于一个特定节点，如果该节点的所有相邻节点都已经搜索完成，
则该节点也会变成已经搜索完成的节点，在拓扑排序中，该节点位于
其所有相邻节点的前面。一个节点的相邻节点指的是从该节点出发通过一条有向边
可以到达的节点。

由于拓扑排序的顺序和搜索完成的顺序相反，因此需要使用一个栈
存储所有已经搜索完成的节点。深度优先搜索的过程中需要维护每个节点的状态，
每个节点的状态可能有三种情况：「未访问」、「访问中」和「已访问」。
初始时，所有节点的状态都是「未访问」。

每一轮搜索时，任意选取一个「未访问」的节点 u，从节点 u 开始深度优先搜索。
将节点 u 的状态更新为「访问中」，对于每个与节点 u 相邻的节点 v，
判断节点 v 的状态，执行如下操作：

- 如果节点 v 的状态是「未访问」，则继续搜索节点 v；

- 如果节点 v 的状态是「访问中」，则找到有向图中的环，因此不存在拓扑排序；

- 如果节点 v 的状态是「已访问」，则节点 v 已经搜索完成并入栈，
节点 u 尚未入栈，因此节点 u 的拓扑顺序一定在节点 v 的前面，
不需要执行任何操作。

当节点 u 的所有相邻节点的状态都是「已访问」时，将节点 u 的状态更新为
「已访问」，并将节点 u 入栈。

当所有节点都访问结束之后，如果没有找到有向图中的环，则存在拓扑排序，
所有节点从栈顶到栈底的顺序即为拓扑排序。

实现方面，由于每个节点是一个字母，因此可以使用字符数组代替栈，
当节点入栈时，在字符数组中按照从后往前的顺序依次填入每个字母。
当所有节点都访问结束之后，将字符数组转成字符串，即为字典顺序。

复杂度分析

时间复杂度：O(n×L+∣Σ∣)，其中 n 是数组words 的长度，即字典中的单词数，
L 是字典中的平均单词长度，Σ 是字典中的字母集合。
遍历字典构造有向图需要 O(n×L) 的时间，由于有向图包含最多 n−1 条边和
∣Σ∣ 个节点，因此深度优先搜索需要 O(n+∣Σ∣) 的时间，
总时间复杂度是O(n×L+n+∣Σ∣)=O(n×L+∣Σ∣)。

空间复杂度：O(n+∣Σ∣)，其中 n 是数组 words 的长度，
即字典中的单词数，Σ 是字典中的字母集合。
空间复杂度主要取决于存储有向图需要的空间，
有向图包含最多 n−1 条边和 ∣Σ∣ 个节点。

TODO 方法二：拓扑排序 + 广度优先搜索
 */