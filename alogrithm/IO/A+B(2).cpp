
// 输入第一行包括一个数据组数t(1 <= t <= 100)
// 接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)

//输出a+b的结果
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    int num1,num2;
    while (t--)
    {
        cin>>num1>>num2;
        cout<<num1+num2<<endl;
    }

    return 0;
    
}
