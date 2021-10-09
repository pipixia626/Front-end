//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

// 问总共有多少条不同的路径？

//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int uniquePath_brute(vector<vector<int>> &data)
    {
        row = data.size();
        line = data[0].size();
        backTrack(data, 0, 0);
        return res;
    }

    int backTrack(vector<vector<int>> &data, int n, int m)
    {
        if (data[n][m] == 1)
            return 0;
        if (n == row - 1 && m == line - 1)
        {
            return 1;
        }

        if (n == row - 1)
        {
            backTrack(data, n, m + 1);
        }
        if (m == line - 1)
        {
            backTrack(data, n + 1, m);
        }
        return backTrack(data, n + 1, m) + backTrack(data, n, m + 1);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

private:
    int row = 0;
    int line = 0;
    int res = 0;
};