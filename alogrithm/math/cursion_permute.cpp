/*递归求全排列
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <class T>
inline void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <class T>
bool whetherSwap(T list[], int start, int end)
{
    for (int i = start + 1; i < end; i++)
    {
        if (list[i] == list[start])
            return false;
    }
    return true;
}
template <class T>
void Permutation(T list[], int start, int end)
{
    //只剩下一个元素，那么就是这个元素本身，并且该列表排序完成可以输出
    if (start == end)
    {
        for (int i = 0; i < end; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    //递归求 从所有start到end元素作为第一个元素，剩下元素进行全排列
    //如果list[i:end]子问题中，首元素list[i]和剩下部分list[i+1:end]中的元素有重复的，
    //则不进行后面的交换和全排列
    else
    {
        //i遍历第start-end个数，每次以list[i]所存的数值为打头的数
        for (int i = start; i < end; i++)
        {
            Swap(list[start], list[i]);        //把要打头的数放到最开头的位置（即start所在的位置
            Permutation(list, start + 1, end); //递归
            Swap(list[start], list[i]);        //为避免重复排序，每个数打头结束后都恢复初始排序
        }
    }
}

void stl_permutation(std::string a)
{
    while (next_permutation(a.begin(), a.end()))
        std::cout << a << std::endl;
}

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums, res))
            ;
        return res;
    }

    bool next_permutation(std::vector<int> &nums, std::vector<std::vector<int>> &res)
    {
        int i;
        for (i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i < 0)
            return false;
        else
        {
            for (int j = nums.size() - 1; j >= i + 1; --j)
            {
                if (nums[i] < nums[j])
                {
                    std::swap(nums[i], nums[j]);
                    std::reverse(nums.begin() + i + 1, nums.end());
                    res.push_back(nums);
                    break;
                }
            }
        }
        return true;
    }
};

int main()
{
    // char test[4]={'a','b','c','d'};
    // Permutation(test,0,4);
    std::string str = "abc";
    stl_permutation(str);
}