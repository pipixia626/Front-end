#include <iostream>
#include <vector>
using namespace std;

// 输入数据有多组, 每行表示一组输入数据。
// 每行的第一个整数为整数的个数n(1 <= n <= 100)。
// 接下来n个正整数, 即需要求和的每个正整数。

int main()
{
    int size = 0;
    int num = 0;

    vector<int> res;
    while (cin >> size)
    {
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