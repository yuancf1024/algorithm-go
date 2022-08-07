# 复盘version
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        # 研究一下数据范围比较小的时候，有什么性质
        # rolls[i] <= 2 
        # 取最后一个尚未出现的数字
        # rolls[i] <= 3
        # 不断去找 1~k 的数字，如果都找到，就取最后一个找到的数字，然后把找到的数字清空，重复该过程
        #                                最后一个找到的数字是这一段里面唯一的数字
        # 时间复杂度 O(n)
        ans = 1
        s = set()
        for x in rolls:
            if x not in s:
                s.add(x)
                if len(s) == k: # 找到了1-k的所有数字，也就找到了一个段
                    ans += 1 # 段的个数++
                    s = set()
        return ans


# 另一种解法
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        # 研究一下数据范围比较小的时候，有什么性质
        # rolls[i] <= 2 
        # 取最后一个尚未出现的数字
        # rolls[i] <= 3
        # 不断去找 1~k 的数字，如果都找到，就取最后一个找到的数字，然后把找到的数字清空，重复该过程
        #                                最后一个找到的数字是这一段里面唯一的数字
        # 时间复杂度 O(n)
        ans = 1
        mark = [0] * (k+1)
        left = k
        for x in rolls:
            if mark[x] < ans:
                mark[x] = ans
                left -= 1
                if left == 0:
                    ans += 1
                    left = k
            # if x not in s:
            #     s.add(x)
            #     if len(s) == k: # 找到了1-k的所有数字，也就找到了一个段
            #         ans += 1 # 段的个数++
            #         s = set()
        return ans