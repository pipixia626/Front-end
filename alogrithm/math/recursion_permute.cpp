//回溯法解决全排列问题

#include <iostream>
#include <vector>
#include <set>

class Solution
{
private:
    std::set<int> used;
    std::vector<int> path;
    std::vector<std::vector<int>> res;

public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        permute(nums);
        return res;
    }

    void next_permute(std::vector<int> &nums)
    {
        if (used.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used.find(nums[i]) == used.end())
            {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                next_permute(nums);
                path.pop_back();
                used.erase(nums[i]);
            }
        }
    }
};