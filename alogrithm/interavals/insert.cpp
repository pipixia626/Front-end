//插入区间
//给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

//在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         int n=intervals.size();

         vector<vector<int>>res;

         //把小于new左区间的区间放进去
         int i=0;
         while(i<n&&intervals[i][1]<newInterval[0]){
             res.emplace_back(intervals[i]);
             ++i;
         }

         //合并重叠区间
         while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            ++i;
         }
          res.emplace_back(newInterval);
         //把右边区间放进去
         while(i<n&&intervals[i][0]>newInterval[1]){
             res.emplace_back(intervals[i]);
             ++i;
         }
         return res;
    }
};