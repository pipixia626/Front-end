// 这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。

// 请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。

// 注意，不管是什么情况下，你都无法跳到数组之外。

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == 0)
        {
            return true;
        }
        int n = arr.size();
        vector<bool> used(n);
        queue<int> q;
        q.push(start);
        used[start] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node + arr[node] < n && !used[node + arr[node]])
            {
                if (arr[node + arr[node]] == 0)
                {
                    return true;
                }
                q.push(node + arr[node]);
                used[node + arr[node]] = true;
            }
            if (node - arr[node] >= 0 && !used[node - arr[node]])
            {
                if (arr[node - arr[node]] == 0)
                {
                    return true;
                }
                q.push(node - arr[node]);
                used[node - arr[node]] = true;
            }
        }
        return false;
    }
};