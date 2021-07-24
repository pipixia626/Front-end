//斐波那契数列解法
#include <iostream>

//cursion
long long Finbonacci_cursion(unsigned n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
    {
        return 1;
    }

    return Finbonacci_cursion(n - 1) + Finbonacci_cursion(n - 2);
}

//dp

long long Finbonacci_dp(unsigned n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    long long fibNMinusOne = 1;
    long long fibMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 0; i < n; ++i)
    {
        fibN = fibNMinusOne + fibMinusTwo;
        fibMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}

// 求矩阵的乘方 [1 1]
//             [1 0]
