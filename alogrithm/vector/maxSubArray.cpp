//在一个数组中求连续数组中最大的和
#include <iostream>
#include <vector>
//暴力解法
int maxSubArray_volience(std::vector<int> &nums)
{
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j)
        {
            sum += nums[j];
            res = std::max(sum, res);
        }
    }
    return res;
}

//dp解法
//dp[i]标识nums中以nums[i]结尾的最大子序和
//考虑 nums[i] 单独成为一段还是加入 f(i-1) 对应的那一段
//dp[i]=max(dp[i-1]+nums[i],nums[i])
int maxSubArray_dp(std::vector<int> &nums)
{
    int res = INT_MIN;
    int size = nums.size();
    std::vector<int> dp(size);
    dp[0] = nums[0];
    res = dp[0];
    for (int i = 1; i < size; i++)
    {
        dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        res = std::max(res, dp[i]);
    }

    return res;
}

//贪心算法

//若当前指针所指元素之前的和小于0，则丢弃当前元素之前的数列

int maxSubArray_greedy(std::vector<int> &nums)
{
    int res = INT_MIN;
    int size = nums.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {

        sum += nums[i];
        res = std::max(res, sum);
        if (sum < 0)
        {
            //丢弃前面的元素
            sum = 0;
        }
    }
    return res;
}