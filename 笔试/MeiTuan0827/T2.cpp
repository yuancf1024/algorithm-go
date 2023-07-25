/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * 裁缝
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小团最近获得了美美团团国的裁缝资格证，
成为了一个裁缝！现在小团有一个长度为n的大布料S
（在这个国家布料其实是一个仅包含小写英文字母的字符串），
小团可以将布料在任意位置剪切，
例如布料abcd可以被裁剪为a与bcd 
或ab与cd或abc与d ，不过，裁剪完之后是不能拼接起来的，
因为小团还不是很擅长拼接布料。

现在小团想知道能不能有一种裁剪方式
能让他把布料恰好裁剪成客人要求的小布料。

形式化地，有一个串S，问是否能将其
划分成m个不相交的连续子串，
使得这些连续子串可以与要求的连续子串一 一对应。
两个串相对应是指这两个串完全相等。
例如"aab"="aab" 但 "aab"≠"baa"


输入描述
第一行两个空格隔开的正整数n和m，
分别表示大布料S长度和客人要求的小布料数量。

接下来一行一个长度为n的仅包含小写英文字母的串S，
表示大布料的组成。

接下来一行m个空格隔开的数x1,x2, ...,xm ，
依次表示所要求的小布料长度。

接下来开始m行，
每行一个长度为xi的仅包含小写英文字母的串si，
表示第i个小布料的组成。

对于所有数据，1<=m<=9,1<=n<=20, 1<=x_i<=n 且x_i的和等于n
 

输出描述
如果存在这样的方案，输出方案总数。
如果不存在任何方案，输出0。

两个方案A、B不相同当且仅当
方案A中存在一个相对于原始长布料的裁剪位置i，
而方案B中并未在该位置i裁剪。

例如aaaaaa 裁剪方案aaa|aaa 
与方案 aaa|aaa是相同的方案。

而方案aa|aaaa与方案aaaa|aa是不同的方案，
虽然划分出的结果都是aa与aaaa，
但前者在第二个a处进行了裁剪，
后者并没有在这里进行裁剪，
所以视为不同的裁剪方案。

样例输入
6 2
aaaaaa
4 2
aaaa
aa
样例输出

2

提示
有两种方案，第一种是aaaa|aa，第二种是aa|aaaa，代表一次裁剪。

规则
请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果
点击“调试”亦可保存代码
编程题可以使用本地编译器，此页面不记录跳出次数
 */

#include <bits/stdc++.h>

using namespace std;

bool isAll(string& S, string& newS) { 
    int s1 = S.size();
    int s2 = newS.size();
    if (s1 != s2) {
        return false;
    }
    bool flag = true;
    for (int i = 0; i < s1; ++i) {
        if (S[i] != newS[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool backtracking(string &S, string& newS, vector<string>&s, int m, int k) {
    if (k == m) {
        if (isAll(S,newS)) {
            return true;
        }
        return false;
    }

    // 核心逻辑
    for (int i = 0; i < m - k; ++i) {
        // 添加
        // newS += s[i];
        int n1 = s[i].size();
        string st = s[i];
        for (int x = 0; x < n1; ++x) {
            newS.push_back(st[x]);
        }
        backtracking(S, newS, s, m, k + 1);
        // 移除 最后s[i]的小字符
        // int n1 = s[i].size();
        for (int a = 0; a < n1; ++a) {
            newS.pop_back();
        }
    }
    return true; // 被这个bug卡了半天
}

int main() {
    int n, m;
    string S;

    vector<int> needL;

    vector<string> s;

    cin >> n >> m;
    cin >> S;

    int temp;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        needL.push_back(temp);
    }

    string t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        s.push_back(t);
    }

    // 核心代码
    int res = 0;
    /*
    思路：
    分别遍历每个需要的子字符串，然后看大字符串中能否分割出满足要求的串
    换位思考，排列组合子字符串，看能否连接后等于S
    - 如果等于，res++
    - 否则跳过，继续组合下一个
    */

    // 用到回溯
    string newS;
    for (int i = 0; i < m; ++i) {
        if (backtracking(S, newS, s, m, i)) {
            res++;
        }
    }
    cout << res << endl;

    // 测试输出
    // cout << n << " " << m << endl;
    // cout << S << endl;

    // for (auto& n : needL) {
    //     cout << n << " ";
    // }
    // cout << endl;
    // for (auto& i : s) {
    //     cout << i << " ";
    // }
    return 0;
}

/*
pass 

说明：
所有测试数据正确率为 27%！
可以尝试再次完善代码，并调试，争取全部AC通过


*/