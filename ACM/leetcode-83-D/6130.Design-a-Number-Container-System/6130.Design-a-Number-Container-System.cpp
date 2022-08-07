/* 6130. 设计数字容器系统
设计一个数字容器系统，可以实现以下功能：

在系统中给定下标处 插入 或者 替换 一个数字。
返回 系统中给定数字的最小下标。
请你实现一个 NumberContainers 类：

- NumberContainers() 初始化数字容器系统。
- void change(int index, int number) 在下标 index 处填入 number 。
如果该下标 index 处已经有数字了，那么用 number 替换该数字。
- int find(int number) 返回给定数字 number 在系统中的最小下标。如果系统中没有 number ，那么返回 -1 。
 
示例：

输入：
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
输出：
[null, -1, null, null, null, null, 1, null, 2]

解释：
NumberContainers nc = new NumberContainers();
nc.find(10); // 没有数字 10 ，所以返回 -1 。
nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
 

提示：
1 <= index, number <= 10^9
调用 change 和 find 的 总次数 不超过 10^5 次。
*/

// 平衡树set
class NumberContainers {
public:
    map<int, int> m;
    map<int, set<int>> ms;

    void change(int index, int number) { 
        auto it = m.find(index);
        if (it != m.end()) {
            ms[it->second].erase(index);
            it->second = number; // 优化：直接在迭代器上赋值
        } else
            m[index] = number;
        ms[number].insert(index);
    }

    int find(int number) { 
        auto it = ms.find(number);
        return it == ms.end() || it->second.empty() ? -1
                                                    : *it->second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

/* 参考@灵茶山艾府
解题思路：
方法1： 平衡树
由于数据范围很大，我们可以用一个哈希表 m 记录每个下标对应的元素，
另一个哈希表套平衡树ms 记录每个元素对应的下标集合。

对于 change 操作，如果 index 处已有数字，则先从 ms[m[index]] 中删掉 index。
然后将 index 和 number 记录到 m 和 ms 中。
*/

// 懒删除堆
class NumberContainers {
public:
    map<int, int> m;
    map<int, priority_queue<int, vector<int>, greater<>>> ms;
    void change(int index, int number) { 
        m[index] = number;
        ms[number].push(index);
    }

    int find(int number) { 
        auto it = ms.find(number);
        if (it == ms.end())
            return -1;
        auto &q = it->second;
        while (!q.empty() && m[q.top()] != number) q.pop();
        return q.empty() ? -1 : q.top();
    }
};

/*
方法2：堆
用堆：
- 对于 change 操作，直接往 ms 中记录，不做任何删除操作；
- 对于 find 操作，查看堆顶下标对应的元素是否和 number 相同，
若不相同则意味着对应的元素已被替换成了其他值，直接弹出堆顶；
否则堆顶就是答案。
*/

// 方法二：懒删除最小堆(优先队列)
class NumberContainers {
    unordered_map<int, int> i2n;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> n2i;
public:
    void change(int index, int number) {
        // // 先看一下原来的数有没有
        // auto it = i2n.find(index);
        // if (it != i2n.end()) {
        //     n2i[it->second].erase(index);
        //     it->second = number; // 直接在迭代器上修改value，这样就不需要再find，效率更高
        // } else {
        //     i2n[index] = number;
        // }
        // n2i[number].insert(index);

        // 先不删，后面find的时候，再删
        i2n[index] = number;
        n2i[number].push(index);
    }

    int find(int number) { 
        // auto it = n2i.find(number);
        // return it == n2i.end() || it->second.empty() ? -1 : *it->second.begin();

        // 检查堆顶下标对应的元素是否为number，如果不是，说明这个index对应的数字已经change过了
        // 直接弹出堆顶
        auto it = n2i.find(number);
        if (it == n2i.end())
            return -1;
        auto &q = it->second;
        while (!q.empty() && i2n[q.top()] != number) { // 对应的数字不正确，下标就作废了
            q.pop();
        }
        return q.empty() ? -1 : q.top();
    }
};

// 方法一：平衡树 set
class NumberContainers {
    unordered_map<int, int> i2n;
    unordered_map<int, set<int>> n2i;
public:
    void change(int index, int number) {
        // 先看一下原来的数有没有
        auto it = i2n.find(index);
        if (it != i2n.end()) {
            n2i[it->second].erase(index);
            it->second = number; // 直接在迭代器上修改value，这样就不需要再find，效率更高
        } else {
            i2n[index] = number;
        }
        n2i[number].insert(index);
    }

    int find(int number) { 
        auto it = n2i.find(number);
        return it == n2i.end() || it->second.empty() ? -1 : *it->second.begin();
    }
};