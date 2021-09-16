
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给定一个数组 candidates 和一个目标数 target ，
//找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用一次。
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    backtrack(candidates,target,0);
    return res;
    }
    void backtrack(vector<int>&candidates,int target,int start){
        if(target==0){
            res.push_back(path);
            return ;
        }
        for(int i=start;i<candidates.size();++i){
            //去重
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            //剪枝 总和已经大于target了
            if(target-candidates[i]<0)break;
            path.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1);
            path.pop_back();
        }
    }
private:
vector<int>path;
vector<vector<int>>res;
};