#include <iostream>
#include <algorithm>
using namespace std;

//求最大公约数 欧几里得算法
//假设a>b
int gcd(int a, int b) //gcd(a,a mod b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;

    else
    {
        return gcd(b, a % b);
    }
}

//求最小公倍数 辗转相除法
//lcm(a,b)=(a*b)/gcd(a,b)

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(){
    int a=10,b=5;
    cout<<"最大公约数"<<gcd(a,b)<<endl;
    cout<<"最小公倍数"<<lcm(a,b)<<endl;
    
    return 0;
}