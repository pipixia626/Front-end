//下一个日子的温度比当前大日子温度大的日子之差（距离）

#include<stack>
#include<iostream>
#include<vector>
using namespace std;

vector<int> dailyTemperature(vector<int>& daily) {
    int n = daily.size();
    vector<int>res(n);
    stack<int> stackVector;
    for (int i = n - 1; i >= 0; --i) {
        //要放进去的值比当前栈顶元素大
        while (!stackVector.empty() && daily[i] >= daily[stackVector.top()]) 
            stackVector.pop();
        //后面没有比他大的
        if (stackVector.empty()) {
            res[i] = 0;
        }
        //后面有比他大的，把第一个top拿出来和i这个第几个数比较差距
        else res[i] = stackVector.top() - i;
        //把这个数放进去
        stackVector.push(i);
    }
    return res;
}

int main() {

    vector<int>daily{ 73,69,72,76,73 };
    vector<int>res = dailyTemperature(daily);
    return 0;
}
