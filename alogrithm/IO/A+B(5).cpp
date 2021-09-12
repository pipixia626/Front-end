#include <iostream>
#include <vector>
using namespace std;

// 输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
// 接下来t行, 每行一组数据。
// 每行的第一个整数为整数的个数n(1 <= n <= 100)。
// 接下来n个正整数, 即需要求和的每个正整数。


int main()
{
    int t;
    cin >> t;
    int size = 0;
    int num = 0;
    vector<int> res;
    while (t--)
    {
        cin >> size;
        int sum = 0;
        while (size--)
        {
            cin >> num;
            sum += num;
        }
        if (cin.get() == '\n')
            ;
        res.push_back(sum);
    }

    for (auto it : res)
    {
        cout << it << endl;
    }
    return 0;
}