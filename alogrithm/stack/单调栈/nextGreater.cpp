#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//一个循环数组，找出下一个比这个数大的数，否则该数对应为-1
vector<int> nextGreaterElments(vector<int>& nums) {
	int n = nums.size();
	vector<int>res(n, -1);
	stack<int>s;
	for (int i = 0; i < n * 2 - 1; ++i) {
		while (!s.empty()&&nums[s.top()]<nums[i%n])
		{
			res[s.top()] = nums[i % n];
			s.pop();
		}
		s.push(i % n);
	}
	return res;
}

int main() {
	vector<int>datas{ 1,3,4,2 };
	nextGreaterElments(datas);
	return 0;
}