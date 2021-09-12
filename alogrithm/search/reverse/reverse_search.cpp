//从旋转数组中搜索

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;


//把旋转数组转换为map
int search_map(vector<int>& nums, int target) {
    unordered_map<int, int>searchMap;
    int size = nums.size();
    //映射map
    for (int i = 0; i < size; ++i) {
        searchMap.insert(make_pair(nums[i], i));
    }

    auto it = searchMap.find(target);
    if (it!=searchMap.end())return it->second;
    else return -1;
}

//二分查找

int search(vector<int>& nums, int target) {
    int size = nums.size();
    if (size == 0)return -1;
    if (size == 1)return nums[0] == target ? 1:-1;
    int left = 0, right = size - 1;

    while (left<right)
    {
        int mid = left + (right-left >> 1);
        if (nums[mid] == target)
            return mid;
        //左半边有序
        if (nums[0] <= nums[mid]) {
         
            if (nums[0] <= target && target <= nums[mid]) {
                //target的值在左半边
                right = mid - 1;
            }
            else left = mid + 1;
        }
        //右半边有序
        else {
            if (nums[mid] <= target && target <= nums[size - 1]) {
                //target的值在右半边
                left = mid + 1;
            }
            else right = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int>nums{ 4,5,6,7,0,1,2 };
    int target = 0;
    cout << search(nums, target);
    return 0;
}