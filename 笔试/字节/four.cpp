#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 4 -4 1 -3 1 -3

int f(vector<int>& nums) {
    int sum = 0;
    int ans = 0;
    queue<int> que;
    for (int z : nums) {
        if (sum + z >= 0) {
            ans++;
            sum += z;
            if (z < 0) que.push(z);
        }
        else {
            if (!que.empty() && z > que.front()) {
                sum -= que.front();//恢复
                sum += z;
                que.pop();
                que.push(z);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    vector<int> vec;
    vector<vector<int>> vvint;
    while (t--)
    {
        int n;
        cin >> n;
        while (n--)
        {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        vvint.push_back(vec);

        vec.clear();
    }

    for (int i = 0; i < vvint.size(); i++) {
        cout << f(vvint[i]) << endl;
    }
    return 0;
}
// 关注TechGuide！ 大厂笔经面经闪电速递！
