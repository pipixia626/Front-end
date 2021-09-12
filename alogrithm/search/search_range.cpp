

#include<vector>
#include<iostream>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int size = nums.size();
    int left = 0, right = size - 1;
    vector<int>res(2, -1);
    if (size == 0)return res;
    //找到第一个大于等于target
    while (left<right)
    {
        int mid = left + right >> 1;//除以二向下取整，找左边界
        if (nums[mid] >= target)right = mid;
        else left = mid + 1;

    }
    if (nums[right] != target)return res;
    res[0] = right;
    left = 0, right = size - 1;
    //找到第一个个小于等于target
    while (left < right) {
        int mid = left + right + 1 >> 1;//除以二向上取整，找右边界
        if (nums[mid] <= target)left = mid;
        else right = mid - 1;
    }
    res[1] = right;
    return res;
}

    int main() {
        vector<int>nums{ 5,6,7,8,8,10 };
        int target =8 ;
        vector<int>res = searchRange(nums, target);

        for (auto it : res) {
            cout << it;
        }
    }