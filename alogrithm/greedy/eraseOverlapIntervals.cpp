#include <iostream>

#include <vector>

#include <algorithm>

//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

// 注意:

// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠

using namespace std;
class Solution
{
public:
    //贪心
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        //以区间右端点从小到大排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int n = intervals.size();
        int res = 1;
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            //如果下一个区间的左端点大于right
            if (intervals[i][0] >= right)
            {
                ++res;
                right = intervals[i][1];
            }
        }
        return n - res;
    }
    //动态规划
    int eraseOverlapIntervals_dp(vector<vector<int>> &intervals)
    {
        int n=intervals.size();
        if(n==0)return 0;

        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){return a[0]<b[0]});

        vector<int>dp(n,1);

        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(intervals[j][1]>intervals[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return n-*max_element(dp.begin(),dp.end());
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    s.eraseOverlapIntervals(intervals);
}