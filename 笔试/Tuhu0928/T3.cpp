/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * 改装汽车的最短时间 15分
 * 
 * 你是一名汽车改装厂的负责人，负责为汽车进行改装，
 * 在待改装的汽车列表vehicles中，每一个元素代表该
 * 辆汽车改装所需要的时间，如vehicles[i]=t
 * 代表i号汽车需要t个时间进行改装。
 * 
 * 由于一辆汽车只能由一名技师进行改装，并且一名技师
 * 只能改装一辆汽车，所以当多辆汽车需要改装时，
 * 技师必须召唤另一名技师共同作业，而召唤技师
 * 需要split个时间。
 * 需要注意的是，召唤技师的行为是可用并行的，
 * 比如两名技师可同时召唤另外两名技师，仅花费split个时间。
 * 
 * 最初你只有一名技师。
 * 请计算改装完所有汽车所需要的最短时间。
 * 
示例1：
[1],1

1

> 1名技师使用1个时间改装1辆汽车

示例2：
[1,2],5

7

> 1. 使用5个时间召唤1名技师
2. 2名技师同时进行改装，花费2个时间
3. 得出5+2=7

示例3：
[1,2,3],1

4

> 1. 召唤1名技师
2. 工人1开始改装2号汽车
3. 工人2召唤1名技师后，进行改装0号和1号汽车
总花费：1+max(3,1 + max(1,2)) = 4

备注：
1<=vehicles.length<=1000
1<=vehicles[i]<=10^5
1<=split<=100

 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回改装完所有汽车所需要的最短时间
     * @param vehicles int整型vector 待改装的汽车列表
     * @param split int整型 召唤技师所需时间
     * @return int整型
     */
    int minVehicleAdaptationsTime(vector<int>& vehicles, int split) {
        // write code here
        
    }
};

int main() {
    vector<int> vehicles = {1, 2, 3};
    int split = 0;
    Solution s;
    int res = s.minVehicleAdaptationsTime(vehicles, split);
    cout << res << endl;
    return 0;
}