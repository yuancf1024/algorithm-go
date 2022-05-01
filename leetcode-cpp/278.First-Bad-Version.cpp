// Source : https://leetcode-cn.com/problems/first-bad-version/
// Author : @yuancf1024
// Date   : 2022-04-07

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    // Binary search
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid-1)) { 
                // mid为true，mid-1为false 即为要找的第一个错误版本
                return mid;
            }

            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};