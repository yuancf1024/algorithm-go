#include <bits/stdc++.h>

/**
 * @brief 
 * 输入n，1-n的范围内，有多少个num，
 * num要满足num = a^2 + b^3 + c^4，abc均为质数。
 * 输出这样的num的个数
 * 
 * 神奇数字num = a^2+b^3+c^4且a、b、c都是质数
 * 想知道1-n中有多少个神奇数字
 * 1<=t<=10^5, 1<=n<=10^6
 * 
 */

/*
pass 20%
大佬AC代码 参考Refer1.cpp
感觉思路也差不多，为什么我的代码只能过20%

我用的是暴力模拟，即使出错，也只会报超时；
但是Pass 0% 是为什么？

C++ int的范围已经够大了呀
int	4 个字节	-2147483648 到 2147483647


我发现一个bug，就是我在修改质数数组中元素数量时，
会影响给定测试Case的答案

nums.size()=100 正常

nums.size()=300 出现bug // res 从30753开始
3
28
33
4730753
30754

30755
62

感觉像是内存泄露，i被重复使用了一样
*/

/*
TestCase1
3
28
33
47

1
2
3
*/

using namespace std;

int main() {
    int t;
    cin >> t;
    // vector<int> nums;
    

    // 新建质数数组
    // vector<int> nums = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 43};
    // 质数数组必须要手动创建
    vector<int> nums={2};
    for (int i = 3; i <= 1000; ++i) {
        bool flag = true;
        int x = 2;
        while (x <= int(sqrt(i))) {
            if (i % x == 0) {
                flag = false;
                break;
            }
            x++;
        }
        if (flag) {
            nums.push_back(i);
        }
    }

    int n;

    while (t > 0) {
        t--;
        cin >> n;
        // 核心代码
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int a = nums[i] * nums[i];
            for (int j = 0; j < nums.size(); ++j) {
                int b = nums[j] * nums[j] * nums[j];
                for (int k = 0; k < nums.size(); ++k) {
                    int c = nums[k] * nums[k] * nums[k] * nums[k];
                    long x = a + b + c;
                    if (x <= n) {
                        res++;
                    }
                }
            }
        }
        cout << res << endl;
    }

    // 打印质数数组
    // for (auto& i : nums) {
    //     cout << i << " ";
    // }
    cout << nums.size() << endl;
    return 0;
}