//在旋转数组中寻找最小值
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;

int findMinwithHeap(vector<int>& nums) {
    make_heap(nums.begin(), nums.end(), greater<int>());
    return nums[0];
}

//最小的值便是左边的数比它大，右边的数也比它大
int findMin_binary(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    //从左往右走 
    while (low < high) {
        int mid = low + (high - low >>1);
        //mid 小于high的话就把high作为mid
        if (nums[mid] < nums[high]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return nums[low];
}
int main() {
    vector<int>nums{ 4,5,6,7,0,1,2 };
    cout << findMin_binary(nums);
    return 0;
}