//三数之和

/*思路
 先对数组排序
 使用两个循环 外层循环用于控制每次必须存在的数

 内层循环用于寻找另外两个元素，使得和为0

时间复杂度O（N^2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{

    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        if (nums.size() < 3)
        {
            return res;
        }
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                break; //后面的元素都大于零，因为已经排序
            if (i != 0 && nums[i] == nums[i - 1])
                continue; //如果元素相同，那么后面元素的情况已经被包含
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (0 == sum)
                {
                    std::vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left++]);
                    temp.push_back(nums[right--]);
                    res.push_back(temp);
                    //下面两行代码用于去掉重复。一定要有left<right,否则出错。如[0,0,0]
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;
                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
    }
};