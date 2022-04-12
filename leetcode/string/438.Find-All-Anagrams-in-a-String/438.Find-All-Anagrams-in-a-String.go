package leetcode

/*
给定一个字符串 s 和一个非空字符串 p，
找出 s 中的所有是 p 的 Anagrams 字符串的子串，返回这些子串的起始索引。
Anagrams 的意思是和一个字符串的所有字符都一样，只是排列组合不同。*/

// @halfrost 滑动窗口 不太好理解
func findAnagrams(s string, p string) []int {
	n, m := len(s), len(p)
	var freq [256]int // 记录每个字符的出现的频次次数
	result := []int{}
	if n == 0 || n < m {
		return result
	}

	for i := 0; i < m; i++ { // 遍历字符串p，记录p中字符的频次
		freq[p[i] - 'a']++
	}

	left, right, count := 0, 0, m

	for right < n {
		if freq[s[right] - 'a'] >= 1 { // 遍历到的字符s[right]在freq中存在
			count--
		}
		freq[s[right] - 'a']--
		right++
		if count == 0 { // 匹配到合适的元素
			result = append(result, left)
		}
		if (right - left) == m {
			if freq[s[left] - 'a'] >= 0 { // ?
				count++
			}
			freq[s[left] - 'a']++
			left++
		}
	}
	return result
}

/*解题思路 #
这道题是一道考“滑动窗口”的题目。和第 3 题，第 76 题，第 567 题类似的。
解法也是用 freq[256] 记录每个字符的出现的频次次数。

滑动窗口左边界往右滑动的时候，划过去的元素释放次数(即次数 ++)，
滑动窗口右边界往右滑动的时候，划过去的元素消耗次数(即次数 --)。
右边界和左边界相差 len(p) 的时候，需要判断每个元素是否都用过一遍了。

具体做法是每经过一个符合规范的元素，count 就 --，count 初始值是 len(p)，
当每个元素都符合规范的时候，右边界和左边界相差 len(p) 的时候，
count 也会等于 0 。当区间内有不符合规范的元素(freq < 0 或者
是不存在的元素)，那么当区间达到 len(p) 的时候，count 无法减少到 0，
区间右移动的时候，左边界又会开始 count ++，
只有当左边界移出了这些不合规范的元素以后，才可能出现 count = 0 的情况，
即找到 Anagrams 的情况。
*/

// leetcode 题解：滑动窗口 （容易理解）
func findAnagrams_v1(s string, p string) []int {
	ans := []int{}
	sLen, pLen := len(s), len(p)
	if sLen < pLen { // 字符串s长度小于字符串p长度
		return nil
	}

	var sCount, pCount [26]int
	for i, ch := range p { // 遍历字符串 p，记录字符频数
		sCount[s[i] - 'a']++ // 记录字符串s中前pLen个字符的频数
		pCount[ch - 'a']++  // 记录字符串p中字符的频数
	}

	if sCount == pCount { // 开始时字符串s前pLen个字符恰好满足要求的情形
		ans = append(ans, 0)
	}

	for i, ch := range s[:sLen - pLen] { // 以pLen为滑动窗口，单步向后滑动
		sCount[ch - 'a']--
		sCount[s[i+pLen] - 'a']++ // 向后滑动1步
		if sCount == pCount {
			ans = append(ans, i+1)
		}
	}
	return ans
}

/*
思路:
根据题目要求，我们需要在字符串 s 寻找字符串 p 的异位词。
因为字符串 p 的异位词的长度一定与字符串 p 的长度相同，
所以我们可以在字符串 s 中构造一个长度为与字符串 p 的长度相同的滑动窗口，
并在滑动中维护窗口中每种字母的数量；当窗口中每种字母的数量与字符串 p 中
每种字母的数量相同时，则说明当前窗口为字符串 p 的异位词。

算法:
在算法的实现中，我们可以使用数组来存储字符串 p 和滑动窗口中每种字母的数量。

细节:
当字符串 s 的长度小于字符串 p 的长度时，字符串 s 中一定不存在字符串 p 的
异位词。但是因为字符串 s 中无法构造长度与字符串 p 的长度相同的窗口，
所以这种情况需要单独处理。

复杂度分析：
时间复杂度：O(m+(n−m)×Σ)，其中 n 为字符串 s 的长度，m 为字符串 p 的长度，
Σ 为所有可能的字符数。我们需要 O(m) 来统计字符串 p 中每种字母的数量；
需要 O(m) 来初始化滑动窗口；需要判断 n−m+1 个滑动窗口中
每种字母的数量是否与字符串 p 中每种字母的数量相同，
每次判断需要 O(Σ) 。因为 s 和 p 仅包含小写字母，所以 Σ=26。

空间复杂度：O(Σ)。用于存储字符串 p 和滑动窗口中每种字母的数量。
*/

// leetcode 题解：优化的滑动窗口 （不好理解）
func findAnagrams_v2(s string, p string) []int {
	ans := []int{}
	sLen, pLen := len(s), len(p)
	if sLen < pLen {
		return nil
	}

	count := [26]int{}
	for i, ch := range p {
		count[s[i] - 'a']++
		count[ch - 'a']--
	}

	differ := 0
	for _, c := range count {
		if c != 0 {
			differ++
		}
	}
	if differ == 0 {
		ans = append(ans, 0)
	}

	for i, ch := range s[:sLen-pLen] {
		if count[ch - 'a'] == 1 { // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
			differ--
		} else if count[ch - 'a'] == 0 { // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
			differ++
		}
		count[ch - 'a']--

		if count[s[i+pLen] - 'a'] == -1 { // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
			differ--
		} else if count[s[i+pLen] - 'a'] == 0 { // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
			differ++
		}
		count[s[i+pLen] - 'a']++

		if differ == 0 {
			ans = append(ans, i+1)
		}
	}
	return ans
}

/*
思路和算法:
在方法一的基础上，我们不再分别统计滑动窗口和字符串 p 中每种字母的数量，
而是统计滑动窗口和字符串 p 中每种字母数量的差；
并引入变量 differ 来记录当前窗口与字符串 p 中数量不同的字母的个数，
并在滑动窗口的过程中维护它。

在判断滑动窗口中每种字母的数量与字符串 p 中每种字母的数量是否相同时，
只需要判断 differ 是否为零即可。

复杂度分析
时间复杂度：O(n+m+Σ)，其中 n 为字符串 s 的长度，m 为字符串 p 的长度，
其中 Σ 为所有可能的字符数。我们需要 O(m) 来统计字符串 p 中每种字母的数量；
需要 O(m) 来初始化滑动窗口；需要 O(Σ) 来初始化 differ；
需要 O(n−m) 来滑动窗口并判断窗口内每种字母的数量是否与字符串 p 中每种字母的数量相同，
每次判断需要 O(1) 。因为 s 和 p 仅包含小写字母，所以 Σ=26。
空间复杂度：O(Σ)。用于存储滑动窗口和字符串 p 中每种字母数量的差。
*/