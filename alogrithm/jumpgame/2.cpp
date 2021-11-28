//给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

// 假设你总是可以到达数组的最后一个位置。

//  
// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int max_far = 0; //目前能跳到最远的位置
        int step = 0;    //跳跃次数
        int end = 0;     //上次跳跃可达范围右边界
        int size = nums.size() - 1;
        for (int i = 0; i < size; ++i)
        {
            max_far = max(max_far, i + nums[i]); //到达上次能跳跃的右边界
            if (i == end)
            {
                end = max_far; //目前能跳到的最远位置变成了下一次起跳位置的边界
                step++;        //进入下一次跳跃
            }
        }
        return step;
    }
};