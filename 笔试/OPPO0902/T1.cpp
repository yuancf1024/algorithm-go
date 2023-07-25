#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，
     * 请勿修改，直接返回方法规定的值即可
     *
     * 输入参数是每个应用持有WakeLock的起始时间及结束时间，
     * 函数返回值是每个应用对总WakeLock时长的贡献值，
     * 返回值vector里面的每个元素的数值累加即为手机总的持有WakeLock的时长。
     * @param wakeLock int整型vector<vector<>> 
     * vector<vector<int>>的每个元素代表某个应用的持有WakeLock的信息，
     * 内部的vector<int>，元素按照奇偶排列，
     * 偶数元素代表拿WakeLock的起始时间点，
     * 奇数代表释放WakeLock的时间点
     * @return int整型vector
     */
    vector<int> getWakeLockContrib(vector<vector<int> >& wakeLock) {
        // write code here
        int n = wakeLock.size();
        vector<int> res(n);

        // 遍历每个应用耗时情况
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < wakeLock[i].size() / 2; ++j) {
                int t = 0;
                t = wakeLock[i][2 * j + 1] - wakeLock[i][2 * j];
                sum += t;
            }
            // 处理均摊的情况

            res[i] = sum;
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> wakeLock = {{1234, 1235}, {1236, 1238}};
    vector<vector<int>> wakeLock = {{1234, 1240}, {1236, 1238, 1245, 1250}};
    Solution s;
    vector<int> res = s.getWakeLockContrib(wakeLock);
    // 打印结果数组
    for (auto& i : res) {
        cout << i << endl;
    }
    return 0;
}

/*
TestCase1:
[[1234,1235], [1236,1238]]
[1,2]


TestCase2:
[[1234, 1240], [1236, 1238, 1245, 1250]]
[5,6]

*/