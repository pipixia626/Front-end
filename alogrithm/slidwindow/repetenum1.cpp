#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//判断存不存在重复字符
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int>set;
         int n=nums.size();
         if(n==0||n==1)return false;
         for(int i=0;i<n;++i){
             if(set.count(nums[i])==1){
                 return true;
             }
             set.insert(nums[i]);
         }
         return false;
    }
};