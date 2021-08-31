//找出数组中第k大的数

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//暴力解法 NlogN 空间复杂度logN ->栈的高度
int findKthLargest_voilence(vector<int> &nums, int k)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    return nums[size - k];
}

//通过partition减治
int findKthLargest_divide(vector<int> &nums, int k)
{
    int size = nums.size();
    int left = 0, right = size - 1;
    //转换一下，第k大元素的下标是size-k

    int target = size - k;

    while (true)
    {
        int index = partition(nums, left, right);
        if (index == target)
        {
            return nums[index];
        }
        else if (index < target)
            left = index + 1;
        else
            right = index - 1;
    }
}

int partition(vector<int> &nums, int left, int right)
{

    if (left < right)
    {
        int randomIndex = RandomInRange(left, right);
        swap(nums,left,randomIndex);
    }
    int pivot=nums[left];
    int j=left;
    for (int i = left + 1; i <= right; ++i)
    {
        if (nums[i] < pivot)
        {
            //j的初值为left,先右移，再交换，小于pivot的元素都被交换到前面
            j++;
            swap(nums, j, i);
        }
        swap(nums, j, left);
    }
    // 交换以后 nums[left..j - 1] < pivot, nums[j] = pivot, nums[j + 1..right] >= pivot
    return j;
}
void swap(vector<int> &nums, int index_left, int index_right)
{
    int temp = nums[index_left];
    nums[index_left] = nums[index_right];
    nums[index_right] = temp;
}
int RandomInRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> datas;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> datas[i];
    }
}