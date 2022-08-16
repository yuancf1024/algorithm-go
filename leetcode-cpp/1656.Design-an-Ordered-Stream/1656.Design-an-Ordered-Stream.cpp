/**
 * @file 1656.Design-an-Ordered-Stream.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1656.设计有序流
 * 
有 n 个 (id, value) 对，其中 id 是 1 到 n 之间的一个整数，
value 是一个字符串。不存在 id 相同的两个 (id, value) 对。

设计一个流，以 任意 顺序获取 n 个 (id, value) 对，
并在多次调用时 按 id 递增的顺序 返回一些值。

实现 OrderedStream 类：

- OrderedStream(int n) 构造一个能接收 n 个值的流，
并将当前指针 ptr 设为 1 。
- String[] insert(int id, String value) 向流中存储新的
 (id, value) 对。存储后：
    - 如果流存储有 id = ptr 的 (id, value) 对，
    则找出从 id = ptr 开始的 最长 id 连续递增序列 ，
    并按顺序返回与这些 id 关联的值的列表。
    然后，将 ptr 更新为最后那个id + 1 。
    - 否则，返回一个空列表。

示例：

输入
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
输出
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

解释
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
 

提示：

1 <= n <= 1000
1 <= id <= n
value.length == 5
value 仅由小写字母组成
每次调用 insert 都会使用一个唯一的 id
恰好调用 n 次 insert
 */

// 方法一：使用数组存储 + 遍历
class OrderedStream {
private:
    vector<string> stream;
    int ptr;

public:
    OrderedStream(int n) { 
        stream.resize(n + 1); // 初始化时开辟一个长度为n+1 的数组
        ptr = 1; // 指针ptr 的初始值为1
    }

    vector<string> insert(int idKey, string value) { 
        stream[idKey] = value; // 将stream[id] 置为 value
        vector<string> res;
        while (ptr < stream.size() && !stream[ptr].empty()) { // 指针未超出边界或stream[id] 不为空时
            res.push_back(stream[ptr]);
            ++ptr;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

/**
 * @brief 
方法一：使用数组存储 + 遍历
思路与算法

对于OrderedStream(int n)，我们在初始化时开辟一个长度为n+1 的数组
stream，用来存储后续的字符串。注意到题目中指针ptr 的初始值为1，
而多数语言数组的下标是从0 开始的，因此使用长度为n+1 的数组
可以使得编码更加容易。

对于String[] insert(int id, String value)，我们直接根据题目描述中的要求
进行遍历即可。我们首先将stream[id] 置为 value。
随后，如果stream[id] 不为空，我们就将其加入答案，
并将ptr 增加1，直到指针超出边界或stream[id] 为空时结束并返回答案。

代码

复杂度分析

注意这里我们将字符串的固定常数5 看成常数。

时间复杂度：
OrderedStream(int n) 的时间复杂度为O(n)；
String[] insert(int id, String value) 的时间复杂度为
均摊O(1)，这是因为我们会恰好调用该函数n 次，
那么每一个字符串最多会被包含在返回数组中一次；

空间复杂度：O(n)，即为存储n 个字符串需要的空间。
 */