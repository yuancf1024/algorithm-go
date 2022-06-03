/* 7-8 521序列
所谓“521 序列”是指将一个原始整数序列 S 中的每个数字分别
乘以 5、2、1 后形成的序列，例如 S= { 5, 2, 1 } 时，
其对应的 521 序列就是 { 25, 10, 5, 10, 4, 2, 5, 2, 1 } —— 
这里我们不要求这个序列一定具有某种顺序，
即 521 序列中元素的顺序是可以打乱的。
给定 S 后，计算其对应的 521 序列是很简单的。
但给定一个 521 序列，恢复其对应的原始序列 S 就略微复杂一点了。
本题就请你恢复任意给定的 521 序列的原始序列。

输入格式：
输入第一行给出正整数 N（<10^5），为 521 序列的长度。
随后一行给出 N 个整数，即给定的 521 序列。所有数字的绝对值不超过 10^5，
以空格分隔。

输出格式：
在一行中按照非递增序输出 521 序列对应的原始序列。数字间以 1 个空格分隔，
行首尾不得有多余空格。

题目保证原始序列是存在的。

输入样例：
12
1 -5 10 -1 2 4 5 -2 5 25 10 2
输出样例：
5 2 1 -1

*/

/* 思路
　　以正数为例，因为原始序列都分别乘以1、2、5构成“521”序列。
那么如果从小到大遍历，每次序列中最小的数字便是原始序列中的数字×1的结果，
去除其×2和×5的数字。然后继续重复此操作直到序列中没有数字为止，
就可以获得最终的原始序列。这里需要强调一下几点：
　　（1）为何正数要从小到大遍历
　　因为从小到大处理，可以避免较小值的倍数混淆了原始序列中数字的个数。
比如序列2 5 10 | 4 10 20 | 10 25 50，因为2和5的倍数会出现10，而10也在原始序列中，
从小到大处理会在处理小数字2和5的时候削减他们倍乘之后数字10的计数。
　　（2）负数不能从小到大，而是按照绝对值从小到大处理。
原因和（1）中解释的相同。
　　（3）代码的写法不同，对于0的处理可能不同，具体处理方法见代码。
*/

#include <bits/stdc++.h>
using namespace std;

// 略显冗长的实现

/*
const int MAXSIZE = 100010;
int positive[MAXSIZE] = {0};
int negative[MAXSIZE] = {0};

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    int positive_cnt = 0; // 正负分开处理
    int negative_cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp >= 0) { // 放入非负计数数组
            positive[tmp]++;
            positive_cnt++;
        } else { // 放入负数计数数组
            negative[-tmp]++;
            negative_cnt++;
        }
    }
    positive_cnt /= 3, negative_cnt /= 3; // 原始数据的个数是 总个数/3
    int id = 0;
    while (positive_cnt) { //必须从小到大遍历，否则会受到其他数字干扰，比如如果原始数字有2  5  10 那么2*5和5*2都会干扰10的计数
        while (!positive[id]) id++; // 找到下一个需要处理的数字
        int cnt = positive[id];
        if (id == 0) //如果是0，那么计数器需要/3，因为其倍数也是0，所以计数器相当于重复三次
            cnt /= 3;
        ans.insert(ans.end(), cnt, id); //cnt表示了原始序列中id的个数，插入到答案数组中
        // 对于0的问题：可以每次减1，这样不用计算cnt，每次只处理一个数字即可
        // 这里使用cnt是因为对于每个数字而言，从小到大遍历，由于不受干扰，计数便是其在原始序列中出现的次数，可以一次性处理完
        positive[id] -= cnt; // 倍数计数器减去对应个数
        positive[id * 2] -= cnt;
        positive[id * 5] -= cnt;
        positive_cnt -= cnt; //以此处理cnt个重复的数字，计数器-cnt
    }
    id = 0;
    while (negative_cnt) {  //负数处理办法类似
        while (!negative[id]) id++;
        int cnt = negative[id];
        ans.insert(ans.end(), cnt, -id);
        negative[id] -= cnt;
        negative[id * 2] -= cnt;
        negative[id * 5] -= cnt;
        negative_cnt -= cnt;
    }
    sort(ans.begin(), ans.end()); // 排序后输出
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i != ans.size() - 1)
            putchar(' ');
        cout << ans[i];
    }
    return 0;
}
*/

// 更精简的实现
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n), r;
    for (int &x : a) cin >> x, ++cnt[x];
    sort(all(a), [&](int a, int b) {
        return abs(a) < abs(b);
    });
    for (int x : a) {
        if (cnt[x])
            r.push_back(x), --cnt[x], --cnt[x * 2], --cnt[x * 5];
    sort(all(r));
    reverse(all(r));
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << " \n"[i + 1 == r.size()];
    }
}