#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 给定一个非空数组，返回此数组中第三大的数。
// 如果不存在，则返回数组中最大的数。
// 要求算法时间复杂度必须是O(n)。
// 请注意，你需要找的是数组排序后的第 3个最大的元素，
// 而不是第 3个不同的元素。

int getTopThree(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    //记录最大的数，第二大的数，第三大的数
    int topOne = 0, topTwo = 0, topThree = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] >= topOne)
        {
            topThree = topTwo;
            topTwo = topOne;
            topOne = nums[i];
        }
        else if (nums[i] < topOne && nums[i] >= topTwo)
        {
            topThree = topTwo;
            topTwo = nums[i];
        }
        else if (nums[i] < topTwo && nums[i] >= topThree)
        {
            topThree = nums[i];
        }
        else
            continue;
    }
    return topThree;
}
int main()
{
    vector<int> datas{1, 3, 2, 6, 4, 5, 4, 5,6};
    cout << getTopThree(datas) << endl;
    return 0;
}