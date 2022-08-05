/**
 * @file 127.Word-Ladder.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * leetcode-127. 单词接龙
 * 
 * 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 
 * 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

- 每一对相邻的单词只差一个字母。
- 对于 1 <= i <= k 时，每个 si 都在 wordList 中。
注意， beginWord 不需要在 wordList 中。
- sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
如果不存在这样的转换序列，返回 0 。
 
示例 1：
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

示例 2：
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同
 */

// 方法一：广度优先搜索 + 优化建图
class Solution {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    // 将单词添加进哈希表，建立word -> wordId的映射关系
    void addWord(string& word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    // 创建图，节点上存储的是wordId
    void addEdge(string& word) { 
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) { // 遍历字符串word中的每个字符it，注意此处使用引用
            char tmp = it;
            it = '*'; // 将字符串中的单个字符替换成*,生成变化了1个字符的新字符
            addWord(word); // 将新字符添加进哈希表
            int id2 = wordId[word];
            edge[id1].push_back(id2); // 建立两个相差1个字符的图连接，双向连接
            edge[id2].push_back(id1);
            it = tmp; // 复原字符串
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word : wordList) { // 遍历wordList，建立图
            addEdge(word);
        }

        addEdge(beginWord); // 将首部单词添加进图
        if (!wordId.count(endWord)) { // 如果尾部单词不在哈希表中，返回0
            return 0;
        }

        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId); // 起点加入队列
        while (!que.empty()) { // 队列不为空
            int x = que.front(); // 队首出队
            que.pop();
            if (x == endId) { // 结束搜索的条件: 找到目标
                return dis[endId] / 2 + 1; // 返回距离的一半再加一的结果
            }
            for (int& it : edge[x]) { // 遍历节点x的连接节点
                if (dis[it] == INT_MAX) { // 没有遍历过
                    dis[it] = dis[x] + 1;
                    que.push(it); // 将节点it添加进队列
                }
            }
        }
        return 0;
    }
};

/**
 * @brief 参考leetcode官方题解
 * 方法一：广度优先搜索 + 优化建图
 * 思路
本题要求的是最短转换序列的长度，看到最短首先想到的就是广度优先搜索。
想到广度优先搜索自然而然的就能想到图，但是本题并没有直截了当的给出图的模型，
因此我们需要把它抽象成图的模型。

我们可以把每个单词都抽象为一个点，如果两个单词可以只改变一个字母进行转换，
那么说明他们之间有一条双向边。因此我们只需要把满足转换条件的点相连，
就形成了一张图。

基于该图，我们以 beginWord 为图的起点，以 endWord 为终点进行广度优先搜索，
寻找 beginWord 到 endWord 的最短路径。

算法

基于上面的思路我们考虑如何编程实现。

首先为了方便表示，我们先给每一个单词标号，即给每个单词分配一个 id。
创建一个由单词 word 到 id 对应的映射 wordId，
并将 beginWord 与 wordList 中所有的单词都加入这个映射中。
之后我们检查 endWord 是否在该映射内，
若不存在，则输入无解。我们可以使用哈希表实现上面的映射关系。

然后我们需要建图，依据朴素的思路，我们可以枚举每一对单词的组合，
判断它们是否恰好相差一个字符，以判断这两个单词对应的节点是否能够相连。
但是这样效率太低，我们可以优化建图。

具体地，我们可以创建虚拟节点。对于单词 hit，
我们创建三个虚拟节点 *it、h*t、hi*，并让 hit 向这三个虚拟节点
分别连一条边即可。
如果一个单词能够转化为 hit，那么该单词必然会连接到这三个虚拟节点之一。
对于每一个单词，我们枚举它连接到的虚拟节点，
把该单词对应的 id 与这些虚拟节点对应的 id 相连即可。

最后我们将起点加入队列开始广度优先搜索，当搜索到终点时，
我们就找到了最短路径的长度。
注意因为添加了虚拟节点，所以我们得到的距离为实际最短路径长度的两倍。
同时我们并未计算起点对答案的贡献，
所以我们应当返回距离的一半再加一的结果。

复杂度分析

- 时间复杂度：O(N×C^2)。其中 N 为 wordList 的长度，C 为列表中单词的长度。
    - 建图过程中，对于每一个单词，我们需要枚举它连接到的所有虚拟节点，
    时间复杂度为 O(C)，将这些单词加入到哈希表中，时间复杂度为 O(N×C)，
    因此总时间复杂度为 O(N×C)。
    - 广度优先搜索的时间复杂度最坏情况下是 O(N×C)。
    每一个单词需要拓展出 O(C) 个虚拟节点，因此节点数 O(N×C)。

- 空间复杂度：O(N×C^2)。其中 N 为 wordList 的长度，C 为列表中单词的长度。
哈希表中包含 O(N×C) 个节点，每个节点占用空间 O(C)，
因此总的空间复杂度为 O(NC^2)。
 */