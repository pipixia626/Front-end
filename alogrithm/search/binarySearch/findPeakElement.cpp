//寻找峰值元素
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
//线性扫描
int findPeakElement_linear(vector<int>& nums) {
   //前一个数比后一个数大就行了
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1])return i;
    }
    return nums.size() - 1;
}
int findPeakElement_binary(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low >> 1);
        //前一个数比后一个数大，就取这个数作为右边界
        if (nums[mid] > nums[mid + 1]) {
            high = mid;
        }
        //前一个数比后一个数小，取这个数的右边数作为左边界
        else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    vector<int>nums{ 1,2,3,1 };
    cout << findPeakElement_binary(nums);
    return 0;
}