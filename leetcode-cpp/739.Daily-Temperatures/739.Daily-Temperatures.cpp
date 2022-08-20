/**
 * @file 739.Daily-Temperatures.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * leetcode-739.每日温度
 * 
给定一个整数数组 temperatures ，表示每天的温度，
返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]
 
提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100


 */

// 单调栈 精简版
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        stack<int> st; // 递增栈
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) { // 注意栈不能为空
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

// 单调栈 思路清晰版
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        stack<int> st; // 递增栈
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] < temperatures[st.top()]) { // 情况1 当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
                st.push(i);
            } else if (temperatures[i] == temperatures[st.top()]) { // 情况2 当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) { // 情况3 当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

/**
 * @brief 
 * 思路
首先想到的当然是暴力解法，两层for循环，把至少需要等待的天数就搜出来了。
时间复杂度是O(n^2)

那么接下来在来看看使用单调栈的解法。

那有同学就问了，我怎么能想到用单调栈呢？ 什么时候用单调栈呢？

通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，
此时我们就要想到可以用单调栈了。

时间复杂度为O(n)。

例如本题其实就是找找到一个元素右边第一个比自己大的元素。

此时就应该想到用单调栈了。

那么单调栈的原理是什么呢？为什么时间复杂度是O(n)就可以找到每一个元素的
右边第一个比它大的元素位置呢？

单调栈的本质是空间换时间，因为在遍历的过程中需要用一个栈来记录
右边第一个比当前元素高的元素，优点是只需要遍历一次。

在使用单调栈的时候首先要明确如下几点：

1. 单调栈里存放的元素是什么？
单调栈里只需要存放元素的下标i就可以了，
如果需要使用对应的元素，直接T[i]就可以获取。

2. 单调栈里元素是递增呢？ 还是递减呢？
注意一下顺序为 从栈头到栈底的顺序，因为单纯的说从左到右或者从前到后，
不说栈头朝哪个方向的话，大家一定会越看越懵。

这里我们要使用递增循序（再强调一下是指从栈头到栈底的顺序），
因为只有递增的时候，加入一个元素i，
才知道栈顶元素在数组中右面第一个比栈顶元素大的元素是i。

文字描述理解起来有点费劲，接下来我画了一系列的图，来讲解单调栈的工作过程。

使用单调栈主要有三个判断条件。

- 当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
- 当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
- 当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况

把这三种情况分析清楚了，也就理解透彻了。

接下来我们用temperatures = [73, 74, 75, 71, 71, 72, 76, 73]
为例来逐步分析，输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

首先先将第一个遍历元素加入单调栈

加入T[1] = 74，因为T[1] > T[0]
（当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况），
而我们要保持一个递增单调栈（从栈头到栈底），所以将T[0]弹出，
T[1]加入，此时result数组可以记录了，result[0] = 1，
即T[0]右面第一个比T[0]大的元素是T[1]。 

加入T[2]，同理，T[1]弹出

加入T[3]，T[3] < T[2] 
（当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况），加T[3]加入单调栈。

加入T[4]，T[4] == T[3] 
（当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况），此时依然要加入栈，
不用计算距离，因为我们要求的是右面第一个大于本元素的位置，
而不是大于等于！ 

加入T[5]，T[5] > T[4] 
（当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况），
将T[4]弹出，同时计算距离，更新result 

T[4]弹出之后， T[5] > T[3] 
（当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况），
将T[3]继续弹出，同时计算距离，更新result

直到发现T[5]小于T[st.top()]，终止弹出，将T[5]加入单调栈 

加入T[6]，同理，需要将栈里的T[5]，T[2]弹出 

同理，继续弹出 

此时栈里只剩下了T[6]

加入T[7]， T[7] < T[6] 直接入栈，这就是最后的情况，result数组也更新完了。 

此时有同学可能就疑惑了，那result[6] , result[7]怎么没更新啊，
元素也一直在栈里。

其实定义result数组的时候，就应该直接初始化为0，
如果result没有更新，说明这个元素右面没有更大的了，也就是为0。

以上在图解的时候，已经把，这三种情况都做了详细的分析。

情况一：当前遍历的元素T[i]小于栈顶元素T[st.top()]的情况
情况二：当前遍历的元素T[i]等于栈顶元素T[st.top()]的情况
情况三：当前遍历的元素T[i]大于栈顶元素T[st.top()]的情况

时间复杂度：O(n)
空间复杂度：O(n)

精简的代码是直接把情况一二三都合并到了一起，
其实这种代码精简是精简，但思路不是很清晰。

建议大家把情况一二三想清楚了，先写出版本一的代码，然后在其基础上在做精简！
 */