// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        backtrack(n, k, 1);
        return res;
    }

    void backtrack(int n, int k, int start)
    {
        if (path.size() == k)
        {
            res.push_back(path);
        }
        for (int i = start; i <= n; ++i)
        {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }
    void diplay()
    {
        for (int i = 0; i < res.size(); ++i)
        {
            for (int j = 0; j < res[i].size(); ++j)
            {
                cout << res[i][j];
            }
            cout << endl;
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};

int main()
{
    Solution solution;
    solution.combine(7, 2);
    solution.diplay();
    return 0;
}