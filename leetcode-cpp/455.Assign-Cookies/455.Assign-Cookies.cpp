// 小饼干先喂饱大胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size()-1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size()-1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;
    }
};

// 小饼干先喂饱小胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (index < g.size() && g[index] <= s[i]) {
                index++;
            }
        }
        return index;
    }
};

/*
尝试使用贪心策略，先将饼干数组和小孩数组排序。
然后从后向前遍历小孩数组，用大饼干优先满足胃口大的，
并统计满足小孩数量。
*/