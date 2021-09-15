//在两个有序数组中找出中位数

//在一个无序数组中找出中位数

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {

        int n = nums1.size() - 1, m = nums2.size() - 1;
        if (n < 0 && m >= 0)
            return findMidNum(nums2);
        if (n >= 0 && m < 0)
            return findMidNum(nums1);
        int add = m + 1;
        int total = n + m + 1;
        while (add--)
            nums1.push_back(0);

        while (total >= 0 && n >= 0 && m >= 0)
        {
            if (nums1[n] > nums2[m])
            {
                nums1[total--] = nums1[n--];
            }
            else
            {
                nums1[total--] = nums2[m--];
            }
        }
        while (n >= 0)
        {
            nums1[total--] = nums1[n--];
        }
        while (m >= 0)
        {
            nums1[total--] = nums2[m--];
        }
        return findMidNum(nums1);
    }

    double findMidNum(const vector<int> nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            left++;
            right--;
        }
        if (left > right)
        {
            double res = (double)nums[left] + (double)nums[right];
            return res / 2;
        }
        else
            return nums[left];
    }
    //两个堆，大顶堆存比较小的那堆数，堆顶为这堆数最大的
    //小顶堆存比较大的那堆数，堆顶为这堆数最小的
    void initHeap(vector<int>& nums)
    {
        for (auto& it : nums)
        {
            if (max_heap.empty()) {
                max_heap.push(it);
                continue;
            }
            //
            if (max_heap.size() > min_heap.size()) {
                //比大顶堆最大的数还大，因此存给小顶堆
                if (it > max_heap.top())
                    min_heap.push(it);
                //比大顶堆最大的数小，把大顶堆最大的数给小顶堆，然后把这个数存进去
                else {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(it);
                }
                continue;
            }
            //两个堆的size相同
            else if (max_heap.size() == min_heap.size()) {
                //遇到的这个数比大顶堆大，因为默认是大顶堆数多，因此存到大顶堆里面，不然就存给小顶堆
                if (it > max_heap.top())
                    max_heap.push(it);
                else
                    min_heap.push(it);
                continue;
            }
            //同理上述
            else {
                if (it < min_heap.top()) 
                    max_heap.push(it);
                else {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    min_heap.push(it);
                }
                continue;
            }
            
        }
    }
    double findMidNumInUnsorted(vector<int>& nums)
    {
        if (max_heap.size() == min_heap.size()) {
            double res = (double)max_heap.top() + (double)min_heap.top();
            return res / 2;
        }
        else if (max_heap.top() > min_heap.top())
            return max_heap.top();
        else
            return min_heap.top();
    }
};

int main()
{
    vector<int> nums1{ 3,7,6,4,5,4 };
    vector<int> nums2{ -2, -1 };
    Solution solution;
    solution.initHeap(nums1);
    cout<<solution.findMidNumInUnsorted(nums1)<<endl;
}