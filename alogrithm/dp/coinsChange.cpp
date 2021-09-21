//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

// 你可以认为每种硬币的数量是无限的。

class Solution
{
public:
    //找到数量最少的组合
    int coins_findOne(vector<int> &coins, int amount)
    {
        int n = amount + 1;
        //   sort(coins.begin(),coins.end(),[](int a,int b){return a>b;});
        vector<int> dp(n, n);
        dp[0] = 0;
        //dp[i]表示面额为i的最少分配数
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                //如果这个硬币还够用
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    //找出所有组合
    int change_findall(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }

    //dp
    //  即前k个硬币凑齐金额i的组合数等于前k-1个硬币凑齐金额i的组合数加上在原来i-k的基础上使用硬币的组合数。
    //说的更加直白一点，那就是用前k的硬币凑齐金额i，要分为两种情况计算，
    //一种是没有用第K个硬币就凑齐了，一种是前面已经凑到了i-coins[k]，现在就差第k个硬币了。

    int change(int amount, vector<int> &coins)
    {
        int m = coins.size() + 1;
        int n = amount + 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < coins.size() + 1; ++i)
        {
            dp[i][0] = 1; //不同硬币数的，换取amount为0的组合为1
        }
        //dp[i][j]表示
        //即前i个硬币凑齐金额j的组合数等于前i-1个硬币凑齐金额i的组合数加上在原来j-i的基础上使用硬币的组合数。
        //说的更加直白一点，那就是用前i的硬币凑齐金额j，要分为两种情况计算，
        //一种是没有用第i个硬币就凑齐了，一种是前面已经凑到了j-coins[i]，现在就差第i个硬币了。

        for (int i = 1; i <= coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                //金额数大于硬币
                if (j >= coins[i - 1])
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                    //小于
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[coins.size()][amount];
    }
    int climbStairs_step_permute(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);

        dp[0] = 1;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins[j];
                if (i < coin)
                    continue; //台阶少于跨越的步数
                dp[i] = dp[i] + dp[i - coin];
            }
        }
        return dp[amount];
    }
    int climbStairs_step(int n)
    {
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;
        int steps[2] = {1, 2};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int step = steps[j];
                if (j < step)
                    continue; //台阶少于跨越的步数
                dp[i] = dp[i] + dp[i - step];
            }
        }
        return dp[n];
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    //回溯
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        backtrack(amount, coins, 0);
        return res;
    }

    void backtrack(int amount, vector<int> &coins, int start)
    {
        if (amount == 0)
        {
            ++res;
            return;
        }
        for (int i = start; i < coins.size(); ++i)
        {
            if (amount - coins[i] < 0)
                break;
            amount -= coins[i];
            backtrack(amount, coins, i);
            amount += coins[i];
        }
    }

private:
    int res = 0;
};