#include <bits/stdc++.h>
using namespace std;

// 将数组从第begin个数到第end个数组成一个数字
int generateNum(int* a, int begin, int end) {
    
    int digitNum = end - begin + 1;
    
    int num = 0;
    for(int i = 0; i < digitNum; ++i) {
        num += a[begin + i] * pow(10, digitNum - i - 1);
    }
    
    return num;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    // 输入乘号数量K
    int k;
    cin >> k;
    // 以字符型一个一个输入数字并存储在数组里面
    int* a = new int[n];
    char input;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        a[i] = input - '0';
    }
    
    // 寻找最大乘积
    // dp[i][j]表示第0位数字到第i位数字组成的数字使用k个乘号时的最大乘积
    // 初始化dp
    long** dp = new long*[n];
    for(int i = 0; i < n; ++i) {
        dp[i] = new long[k + 1];
        // 分成一段的话就是只有一个数字
        dp[i][0] = generateNum(a, 0, i);
        for(int j = 1; j < k + 1; ++j) {
            dp[i][j] = 0;
        }
    }
    // 解决所有子问题
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < k + 1; ++j) {
            
            // 乘号数量不能大于或等于数字数量
            if(j >= i + 1) {
                dp[i][j] = 0;
                continue;
            }
            
            // 当前最大乘积需要利用上一步求得的最大乘积来计算
            /*
                即第0位数字到第i位数字组成的数字使用k个乘号时的最大乘积需要用第0位到第b位（b<i）的最大乘积乘以剩下的那一个数
                */
            for(int b = i - 1; b >= 0; --b) {
                dp[i][j] = max(dp[i][j], dp[b][j - 1] * generateNum(a, b + 1, i));
            }
            
        }
    }
    // 输出测试
    cout << dp[n - 1][k] << endl;
    return 0;
}

