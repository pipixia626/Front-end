// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标。
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
