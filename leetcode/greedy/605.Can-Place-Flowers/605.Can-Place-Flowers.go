package leetcode

/* 605. 种花问题
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组  flowerbed 表示花坛，
由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，
能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。
*/
// 参考halfrost
func canPlaceFlowers(flowerbed []int, n int) bool {
	length := len(flowerbed)
	for i := 0; i < length && n > 0; i += 2 {
		if flowerbed[i] == 0 {
			if i+1 == length || flowerbed[i+1] == 0 { // i为0，i+1也为0 or i+1为末尾，也能种花
				n--
			} else {
				i++
			}
		}
	}
	if n == 0 {
		return true
	}
	return false
}

/* 
思考🤔：
贪心策略：对于空地块，尽可能选择与种了花的位置隔1的地块。

解题思路
- 这一题最容易想到的解法是步长为 2 遍历数组，
依次计数 0 的个数。
有 2 种特殊情况需要单独判断，第一种情况是首尾连续多个 0，
例如，00001 和 10000，第二种情况是 2 个 1 中间存在的 0 不足以种花，
例如，1001 和 100001，1001 不能种任何花，100001 只能种一种花。单独判断出这 2 种情况，这一题就可以 AC 了。

- 换个思路，找到可以种花的基本单元是 00，那么上面那 2 种特殊情况都可以统一成一种情况。
判断是否当前存在 00 的组合，如果存在 00 的组合，都可以种花。
末尾的情况需要单独判断，如果末尾为 0，也可以种花。
这个时候不需要再找 00 组合，因为会越界。代码实现如下，思路很简洁明了。

*/