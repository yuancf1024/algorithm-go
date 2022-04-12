package leetcode

// 自己写的
// func canConstruct(ransomNote string, magazine string) bool {
//     // 这种实现有问题，特殊案例无法通过
//     n, m := len(ransomNote), len(magazine)
//     if n > m {
//         return false
//     }

//     hashmap := [26]int{}
//     for i := 0; i < m; i++ {
//         hashmap[magazine[i] - 'a']++
//     }
//     for _, v := range ransomNote {
//         // if hashmap[k] > 0 {
//         //     hashmap[k]--
//         // }
//         hashmap[v - 'a']--
//          if hashmap[v - 'a'] < 0 {
//             return false
//         }
//     }
//     // for _, v := range hashmap { // 这种实现无法应对 'a' 'b'这样的情形
//     //     if v < 0 {
//     //         return false
//     //     }
//     // }
//     return true
// }

// 更优雅的实现
func canConstruct(ransomNote string, magazine string) bool {
    if len(ransomNote) > len(magazine) {
        return false
    }

    var cnt [26]int
    for _, v := range magazine {
        cnt[v - 'a']++
    }
    for _, v := range ransomNote {
        cnt[v - 'a']--
        if cnt[v - 'a'] < 0 {
            return false
        }
    }
    return true
}

/* 
解题思路：ransomNote 和 magazine 都是由小写字母组成，所以用数组进行简单的字符统计
题目要求使用字符串 magazine 中的字符来构建新的字符串 ransomNote
只需要满足字符串 magazine 中的每个英文字母 (’a’-’z’) 的统计次数
都大于等于 ransomNote 中相同字母的统计次数即可。

- 如果字符串 magazine 的长度小于字符串 ransomNote 的长度，
则我们可以肯定 magazine 无法构成 ransomNote，此时直接返回 false。
首先统计 magazine 中每个英文字母 a 的次数 cnt[a]，再遍历统计 ransomNote 中每个英文字母的次数，
如果发现 ransomNote 中存在某个英文字母 c 的统计次数
大于 magazine 中该字母统计次数 cnt[c]，则此时我们直接返回 false。

复杂度分析
时间复杂度：O(m+n)，其中 m 是字符串ransomNote 的长度，n 是字符串 magazine 的长度，
我们只需要遍历两个字符一次即可。

空间复杂度：O(∣S∣)，S 是字符集，这道题中 S 为全部小写英语字母，因此∣S∣=26。
*/