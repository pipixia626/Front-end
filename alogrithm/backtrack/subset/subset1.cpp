//求一共集合的所有子集

#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
    vector<int> path;
    vector<vector<int>> res;

public:
    //二进制枚举
    vector<vector<int>> subSets_enumeration(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) //从0~2^n-1个状态
        {
            path.clear();
            for (int j = 0; j < n; j++) //遍历二进制的每一位
            {
                if (i & (1 << j)) //判断二进制第j位是否存在
                {
                    path.push_back(nums[j]); //如果存在输出第j个元素
                }
            }
            res.push_back(path);
        }
        return res;
    }
    //回溯法
    vector<vector<int>> subSet_backtrack(vector<int>& nums) {
        backtrack(nums, path, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& path, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);//选择
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }

};

int main() {
    Solution solution;
    vector<int>nums{ 1,2,3 };
    vector<vector<int>>res;
    res = solution.subSet_backtrack(nums);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

