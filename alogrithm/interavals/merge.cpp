//合并重叠区间
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int left = 1;
        int right = intervals.size() - 1;
        vector<int> path(2);
        path = intervals[0];
        while (left <= right)
        {
            //第二个区间的左端点大于第一个区间的右端点
            if (path[1] < intervals[left][0])
            {
                res.push_back(path);    //把第一个区间放进去
                path = intervals[left]; //当前区间为path
            }
            //第二个区间的左端点小于等于第一个区间的右端点
            else //(path[1] >= intervals[left][0])
            {
                //第二个区间的右端点小于第一个区间的右端点
                if (path[1] > intervals[left][1])
                {
                    path = path;
                }
                //第二个区间的右端点小于等于第一个区间的左端点
                else
                {
                    //当前区间的左边为第一个区间的左端点，当前区间的右边为第二个区间的右端点
                    path[0] = path[0];
                    path[1] = intervals[left][1];
                }
            }
            ++left;
        }

        //left ==3
        res.push_back(path);
        return res;
    }
};