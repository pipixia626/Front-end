//最大区间重叠问题

//做法
//将所有的开始时间和结束时间进行排序，如果是开始时间则计数加1，如果是结束时间则减一

//只要一直是开始时间，那就说明遇到的区间一直在重叠。没有结束，当遇到一个结束时间
//时，就说明目前重叠的区间的数目到达一个极大值，不能再加入了

//让结束时间排靠在前->两个区间连接但不重叠

//nlogn(排序)+n(遍历)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int time; //到达时间或者结束时间
    int flag; //为0则为到达时间，为1则为结束时间
    node(int _time, int _flag) : time(_time), flag(_flag) {}
};

int main()
{
    int n; //人数
    cin >> n;
    vector<node> v;

    while (n--)
    {
        int start, end;
        cin >> start >> end; //每个人到达时间和结束时间
        v.emplace_back(node(start, 0));
        v.emplace_back(node(end, 1));
    }

    //按时间排序(所有事件的开始时间和结束时间)
    sort(v.begin(), v.end(), [](const node &a, const node &b)
         {
             if (a.time == b.time)
                 return a.flag > b.flag;
             return a.time < b.time;
         });

    int ans = 0, res = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].flag == 0)
            ans++;
        else
            ans--;
        res = max(res, ans);
    }
    cout << res << endl;
    return 0;
}
