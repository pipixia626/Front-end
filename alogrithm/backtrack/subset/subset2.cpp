#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //因为会有重复元素，因此元素的顺序也很重要，所以需要排序
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return res;
    }
    
    void backtrack(vector<int>&nums,int start){
        res.push_back(path);
        for(int i=start;i<nums.size();++i){
             //去重
            if(i>start&&nums[i]==nums[i-1])
            continue;
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();
        }
    }
private:
vector<int>path;
vector<vector<int>>res;

};

int main(){
    Solution solution;
    vector<int>num{4,4,4,1,4};
    vector<vector<int>>res=solution.subsetsWithDup(num);
    return 0;
}