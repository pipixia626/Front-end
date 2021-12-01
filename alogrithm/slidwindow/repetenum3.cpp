// 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

// 如果存在则返回 true，不存在返回 false。

#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return false;
    set<long> window;
    for (int i = 0; i < n; ++i)
    {
        //找到大于等于nums[i]-t的最小的这个数
        //num>=nums[i]-t -> t+num>=nums[i]
        auto num = window.lower_bound((long)nums[i] - t);
        //在集合中找到的最小的这个数和当前这个数+距离(t)是否符合
        if (num != window.end() && *num <= ((long)nums[i] + t))
            return true;
        window.insert(nums[i]);
        //保持窗口只有k个
        if (i >= k)
            window.erase(nums[i - k]);
    }
    return false;
}

int main()
{
    vector<int> datas{1, 2, 3, 1};
    cout << containsNearbyAlmostDuplicate(datas, 3, 0);
    return 0;
}