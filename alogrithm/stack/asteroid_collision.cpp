//给一个数组，左边的数比右边的数大，右边会被踢掉 <==>右边的数比左边的数小的，右边的数就会被踢掉
// 5 10 -5 -> 5 10

//左边的数比右边的小的，左边会会被踢掉  <==>右边的数比左边的大的，左边会被踢掉

// 5 10 -5->10 -5





//下一个日子的温度比当前大日子温度大的日子之差

#include<stack>
#include<iostream>
#include<vector>
using namespace std;

// 5 10 -5   ->5 10
//左边的数比右边的数大
vector<int>coliision_leftMoreThanRight(vector<int>&nums) {
    vector<int>res;
    int n = nums.size();
    stack<int>s;
    for (int i = n - 1; i >= 0; --i) {
        
        while (!s.empty() && nums[i] > s.top()) {
            s.pop();
        }
        if (s.empty() || nums[i] < s.top()) {
            s.push(nums[i]);
        }
    }
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
//左边的数比右边的数小
// 5 10 -5   ->  -5
vector<int>coliision_leftLessThanRight(vector<int>&nums) {
 
    vector<int>res;
    int n = nums.size();
    stack<int>s;
    s.push(nums[n - 1]);
    for(int i = n - 1; i >= 0; --i) {
        if (nums[i] < s.top()) {
            s.push(nums[i]);
       }
    }
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main() {

    vector<int>daily{ 3,-4,0,7,10,5};

    vector<int>res;

    vector<int>ress;

    res = coliision_leftMoreThanRight(daily);
    ress = coliision_leftLessThanRight(daily);
    return 0;
}
