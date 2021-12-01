// 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {

        int size = nums.size();
        unordered_set<int> datas;
        for (int i = 0; i < size; ++i)
        {
            if (datas.count(nums[i]) == 1)
                return true;
            datas.insert(nums[i]);
            if (datas.size() > k)
            {
                datas.erase(nums[i - k]);
            }
        }
        return false;
    }
};