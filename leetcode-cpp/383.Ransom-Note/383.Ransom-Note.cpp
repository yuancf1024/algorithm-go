/* 383. 赎金信
给你两个字符串：ransomNote 和 magazine ，
判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
 
提示：

1 <= ransomNote.length, magazine.length <= 10^5
ransomNote 和 magazine 由小写英文字母组成

*/

// 参考代码随想录 方法1 暴力解法
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
    }
};

// 哈希解法 数组
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        // add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录magazine里各个字符出现的次数
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            // 如果小于零，说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

/*
暴力解法

那么第一个思路其实就是暴力枚举了，两层for循环，不断去寻找

这里时间复杂度是比较高的，而且里面还有一个字符串删除也就是erase的操作，
也是费时的，当然这段代码也可以过这道题

哈希解法

因为题目所只有小写字母，那可以采用空间换取时间的哈希策略， 
用一个长度为26的数组还记录magazine里字母出现的次数。

然后再用ransomNote去验证这个数组是否包含了ransomNote所需要的所有字母。

依然是数组在哈希法中的应用。

一些同学可能想，用数组干啥，都用map完事了，其实在本题的情况下，
使用map的空间消耗要比数组大一些的，因为map要维护红黑树或者哈希表，
而且还要做哈希函数，是费时的！数据量大的话就能体现出来差别了。 
所以数组更加简单直接有效！
*/