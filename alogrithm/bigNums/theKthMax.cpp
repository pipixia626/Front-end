//找出数组中第k大的数

#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

//暴力解法 NlogN 空间复杂度logN ->栈的高度
int findKthLargest_voilence(vector<int>& nums, int k)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    return nums[size - k];
}
int partion(vector<int>& a, int low, int high)
{ //常规的快排划分，但这次是大数在左
    int temp = a[low];
    while (low < high)
    {
        while (low < high && a[high] <= temp)
            high--;
        if (low == high)
            break;
        else
            a[low] = a[high];
        while (low < high && a[low] >= temp)
            low++;
        if (low == high)
            break;
        else
            a[high] = a[low];
    }
    a[low] = temp;
    return low;
}
int quickSort(vector<int>& a, int low, int high, int K)
{
    int p = partion(a, low, high); //先进行一轮划分，p下标左边的都比它大，下标右边都比它小
    if (K == p - low + 1)          //若p刚好是第K个点，则找到
        return a[p];
    else if (p - low + 1 > K)               //从头到p超过k个数组，则目标在左边
        return quickSort(a, low, p - 1, K); //递归左边
    else
        return quickSort(a, p + 1, high, K - (p - low + 1)); //否则，在右边,递归右边,但是需要减去左边更大的数字的数量
}
int findKth(vector<int> a, int n, int K)
{
    return quickSort(a, 0, n - 1, K);
}

//空间大小为k的小顶堆，堆顶就是结果

int KthLargestWithMinHeap(vector<int>& nums, int k) {
    priority_queue< int, vector<int>, greater<int>>min_heap;
    for (auto it : nums) {
        min_heap.push(it);
        if (min_heap.size() > k)min_heap.pop();
    }

   
    return min_heap.top();

}
//空间大小为n的大定堆，pop()k次，堆顶就是结果

int kthLargestWithMaxheap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, less<int>>max_heap;
    for (auto it : nums) {
        max_heap.push(it);
    }
    while (k--)
    {
        max_heap.pop();
    }
    return max_heap.top();

}
int main()
{
    vector<int>nums{ 1,3,2,4 ,5,6};
    cout << KthLargestWithMinHeap(nums, 2);
    return 0;
}