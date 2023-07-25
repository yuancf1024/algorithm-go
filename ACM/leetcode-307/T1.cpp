#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 思路
 * 
精力是在不断递减的，只需要保证初始精力在energy递减的过程中，最终变为1即可；
因此求energy的和，再加1，减去初始精力，即为训练增加精力的时间。

experience经验数组的要求是初始精力必须大于经验数组的最大间隔值；
 */

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // 要单独处理数组只有一个元素的case
        if (energy.size() == 1) {
            if (initialEnergy > energy[0] && initialExperience > experience[0]) {
                return 0;
            } else {
                return energy[0] - initialEnergy + 1 + experience[0] -
                       initialExperience + 1;
            }
        }
        
        // 处理精力
        int energyTime = 0, experienceTime = 0;
        int energySum = 0;
        for (auto& num : energy) {
            energySum += num;
        }
        energyTime = energySum + 1 - initialEnergy;

        // 处理经验
        vector<int> interval(experience.size());
        int maxInterval = 0;
        // 需要得到一个累加数组
        for (int i = 1; i < experience.size(); ++i) {
            if (experience[i] - experience[i-1] > maxInterval) {
                maxInterval = experience[i] - experience[i - 1];
            }
        }
        experienceTime = maxInterval + 1 - initialExperience;
        return energyTime + experienceTime;
        // return 1;
    }
};

int main() {
    int initialEnergy;
    int initialExperience;
    vector<int> energy;
    vector<int> experience;

    cin >> initialEnergy >> initialExperience;

    int N = 1;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        energy.push_back(temp);
    }

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        experience.push_back(temp);
    }

    Solution solution;
    int res = solution.minNumberOfHours(initialEnergy, initialExperience, energy, experience);
    cout << res << endl;

    // cout << initialEnergy << " " << initialExperience << endl;
    // for (auto& num : energy) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // for (auto& num : experience) {
    //     cout << num << " ";
    // }

    return 0;
}


/*
Case1:
5 3
1 4 3 2
2 6 3 1

8

case2:
2 4
1
3

0

1
1
[1,1,1,1]
[1,1,1,50]

51
*/