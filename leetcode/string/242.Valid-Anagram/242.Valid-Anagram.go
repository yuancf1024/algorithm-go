package leetcode

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

// 自己写的
// 解法1
func isAnagram(s string, t string) bool {
    n, m := len(s), len(t)
    if n != m {
        return false
    }

    var cnt [26]int
    for _, v := range s {
        cnt[v - 'a']++
    }
    for _, v := range t {
        cnt[v - 'a']--
        if cnt[v - 'a'] < 0 {
            return false
        }
    }
    return true
}

/*
1. 新建哈希表cnt，key为字符(Ascii),value为字符频数；
2. 遍历字符串s，将每个字符及其频数记录到哈希表cnt；
3. 遍历字符串t，对哈希表中遍历到的每个字符做自减，如果存在映射值小于0，说明字符串t存在s里面没有的元素，返回false
4. 结束遍历，返回true。
- 执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
- 内存消耗：2.6 MB, 在所有 Go 提交中击败了99.95%的用户

复杂度分析
时间复杂度：O(n)，其中 n 为 s 的长度。
空间复杂度：O(S)，其中 S 为字符集大小，此处 S=26。
*/

// 解法2：打表
func isAnagram_v2(s string, t string) bool {
	alphabet := make([]int ,26)
	sBytes := []byte(s)
	tBytes := []byte(t)
	n, m := len(sBytes), len(tBytes)
	if n != m {
		return false
	}
	for i := 0; i < n; i++ {
		alphabet[sBytes[i]- 'a']++
	}
	for i := 0; i < m; i++ {
		alphabet[tBytes[i] - 'a']--
	}
	for i := 0; i < 26; i++ {
		if alphabet[i] != 0 {
			return false
		}
	}
	return true
}

/*
这道题可以用打表的方式做。先把 s 中的每个字母都存在一个 26 个容量的数组里面，
每个下标依次对应 26 个字母。s 中每个字母都对应表中一个字母，
每出现一次就加 1。然后再扫字符串 t，每出现一个字母就在表里面减一。
如果都出现了，最终表里面的值肯定都是 0 。

最终判断表里面的值是否都是 0 即可，有非 0 的数都输出 false 。
*/

// 解法1的更严谨实现
func isAnagram_v1(s string, t string) bool {
	hash := map[rune]int{}
	for _, value := range s {
		hash[value]++
	}
	for _, value := range t {
		hash[value]--
	}
	for _, value := range hash {
		if value != 0 {
			return false
		}
	}
	return true
}


// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
// 第一段代码即可解决 输入字符串包含 unicode 字符
