#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
      vector<int>max_dp(n+1,0);
      vector<int>min_dp(n+1,0);
      max_dp[0]=min_dp[0]=nums[0];
      int res=nums[0];
      for(int i=1;i<n;++i){
         max_dp[i]=max(nums[i],max(max_dp[i-1]*nums[i],min_dp[i-1]*nums[i]));
         min_dp[i]=min(nums[i],min(max_dp[i-1]*nums[i],min_dp[i-1]*nums[i]));
         res=max(max_dp[i],res);
      }
      return res;
    }
};