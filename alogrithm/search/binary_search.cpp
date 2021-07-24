//二分查找
#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target)
{
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        pivot = left + (right - left + 1) >> 1;
        if (nums[pivot] == target)
            return pivot;
        else if (nums[pivot] > target)
            left = pivot + 1;
        else
            right = pivot - 1;
    }
    return -1;
}

//stl

template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T &val)
{
    first = std::lower_bound(first, last, val);
    return (first != last && !(val < *first));
}
