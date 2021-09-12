//找一个数第一次出现的位置和和最后一次出现的位置
#include <iostream>
#include <vector>

using namespace std;

int firstOccuranceOfNum(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l >> 1);
        if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return -1;
}

int lastOccuranceOfNum(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {   //偶数个的时候停顿
        int mid = l + (r - l+1 >> 1);
        if (nums[mid] > target)
        {
            r=mid-1 ;
        }
        else
        {
            l = mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> datas{1, 1, 2, 2, 2, 6, 7};
}