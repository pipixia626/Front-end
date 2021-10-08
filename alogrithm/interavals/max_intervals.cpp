//在一维坐标轴上有n个区间段，求重合区间最长的两个区间段

//分析

//首先按照区间的左端点对n个区间段进行排序，然后遍历所有区间，比较前后两个区间的右端点即end

//假设前后区间为[x1,y1],[x2,y2] 因为排序了->x2>=x1
// 1:如果y2>=y1 ,因为后面区间的起点大于x2所以最大的区间为 y1-x2+1 ->或者0不相交

//2:y2<=y1，此重叠区间为y2-x2+1,也就是区间二的大小，但后面可能存在其他区间更大重叠面积
//所以在没有找到一个区间的结束时间大于y1时，得一直查找比较

//nlogn(排序)+n(遍历)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int start;
    int end;
};
//计算区间最大重叠面积
int longestOverlap(vector<node> &v)
{
    int n = v.size();
    int maxOverlap = 0;

    //根据开始时间进行排序
    sort(v.begin(), v.end(), [](const node &a, const node &b)
         { return a.start < b.start; });

    node pre = v[0];
    node cur;
    for (int i = 1; i < n; ++i)
    {
        cur = v[i];
        if (cur.end >= pre.end)
        {
            maxOverlap = max(maxOverlap, max(pre.end - cur.start + 1, 0));
            pre = cur;
        }
        else
        {
            maxOverlap = max(maxOverlap, cur.end - cur.start + 1);
        }
    }
    return maxOverlap;
}
int main()
{
    int n;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].start >> v[i].end;
    }

    return 0;
}