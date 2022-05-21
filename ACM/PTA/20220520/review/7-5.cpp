/* 7-5 我侬数
元初的中国书画大家赵孟頫的妻子管道升曾经写过一首脍炙人口的《我侬词》，
词中道：“把一块泥，捻一个你，塑一个我。将咱们两个一齐打破，用水调和。再捏一个你，再塑一个我。我泥中有你，你泥中有我。”
给定一对正整数 A 和 B，将它们的各位数字收集到一起，再重新分成两个数 A 和 B ′，我们称这样的 A′和 B′
互为基于 A 和 B 的“我侬数“。本题就请你判断任一对数字是否是基于给定 A 和 B 的“我侬数“。

输入格式：

输入首先在第一行中给出两个不超过 10^4位的正整数 A 和 B，
为“我侬数“的基础数。随后每行给出一对不超过 2×10^4位的正整数 A′和B′。
数字间以 1 个空格分隔。

输入以一对 0 结束，这一对 0 不要处理。
题目保证至少有一对需要判定的数字。

输出格式：
对每一对 A′和 B′，判断其是否是基于给定 A 和 B 的“我侬数“。
如果是，则在一行中输出 Yes，否则输出 No。

注意：所有数字均不考虑前导 0。例如 A=101，B=2021，
则我们不能判定 012 和 0121 为“我侬数“。

输入样例：
521212577999 21100008482136
521212577999 21100008482136
00210908482136 512121257799
123456789012597890 11100222
786238645254 19024781758903
21100008482136 521212577999
90 52121257792110008482136
0 0
输出样例：
Yes
No
Yes
No
Yes
No

*/

/*
思路:这个题目其实是字符串处理，首先对基准数字去除前置0，
然后剩余的转换为一个字符串并且排序（便于比对）。其他的做同样的处理后和
基准字符串比对即可。
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string numa, numb;
    cin >> numa >> numb;
    int index = 0; // 处理前置0
    while (numa[index] == '0') index++;
    numa = numa.substr(index);
    index = 0;
    while (numb[index] == '0') index++;
    numb = numb.substr(index);
    numa += numb; // 两数相加
    sort(numa.begin(), numa.end()); // 排序
    string a, b;
    while (true) {
        cin >> a >> b;
        if (a == "0" && b == "0")  //如果遇到结束的 0 0结束循环
            break;
        index = 0; // //去除a，b的前置0
        while (a[index] == '0') index++;
        a = a.substr(index);
        index = 0;
        while (b[index] == '0') index++;
        b = b.substr(index);
        a += b; //相加并排序
        sort(a.begin(), a.end());
        cout << (numa == a ? "Yes\n" : "No\n");
    }
    return 0;
}