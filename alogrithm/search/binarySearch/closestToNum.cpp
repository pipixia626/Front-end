//找出一个最接近与某个值的

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r - 1)
    {
        int mid = l + (r - l >> 1);
        if (nums[mid] <target)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    //只有两个值的时候
    if (nums[r] < target)
        return r;
    else if (nums[l] > target)
        return l;
    else
    {
        return target - num[l] < nums[r] - target ? l : r;
    }
}