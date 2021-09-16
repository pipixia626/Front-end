#include<iostream>
#include<vector>
#include<algorithm>

// 给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，
//找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。
// candidates 中的数字可以无限制重复被选取。
//如果至少一个所选数字数量不同，则两种组合是唯一的。
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target,0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target,int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
       
        for (int i = start; i < candidates.size(); ++i) {
            //剪枝 总和已经大于target了
             if (target-candidates[i] < 0) break;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i],i);

            path.pop_back();
        }
    }
private:
    vector<int>path;
    vector<vector<int>>res;
};

int main(){
    vector<int>nums{2,3,6,7};
    int target=7;
    Solution solution;
    solution.combinationSum(nums,target);
    return 0;
}