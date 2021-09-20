//计算a^n% b其中a，b和n都是32位的非负整数。

#include <iostream>
using namespace std;

//递归快速幂

int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        //需要使用temp来保存求得的一个值
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}
long long qpow(long long a, long long n, int b)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % b;
    else
    {
        //需要使用temp来保存求得的一个值
        int temp = qpow(a, n / 2) % b;
        return temp * temp % b;
    }
}

template <typename T>
T qpow(T a, long long n)
{
    T ans = 1; // 赋值为乘法单位元，可能要根据构造函数修改
    while (n)
    {
        if (n & 1)         //这里是为了幂值不为偶数
            ans = ans * a; // 这里就最好别用自乘了，不然重载完*还要重载*=，有点麻烦。
        n >>= 1;
        a = a * a;
    }
    return ans;
}
//二分法求
double myPow(double x, int n)
{
    long long N = n;
    return N >= 0 ? Binary_Mul(x, N) : 1.0 / Binary_Mul(x, N);
}
double Binary_Mul(double x, long long n)
{
    if (n == 0)
        return 1.0;
    double y = Binary_Mul(x, n / 2);
    // 0 1 2 4 <->    1->(1*1)*2=2->2*2*2=8->8*8=64
    // 0 1 3   <->    1->(1*1)*2=2->2*2*2=8
    return n % 2 == 0 ? y * y : y * y * x;
}
//递归快速幂取模
int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    long long ans = 1; // 赋值为乘法单位元，可能要根据构造函数修改
    while (n)
    {
        if (n & 1)
            ans = ans * a; // 这里就最好别用自乘了，不然重载完*还要重载*=，有点麻烦。
        n >>= 1;
        a = a * a;
    }
    return ans;
}