#include <iostream>
#include <vector>
using namespace std;

// 输入数据包括多组。
// 每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
// 接下来n个正整数,即需要求和的每个正整数。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res;
    int size;
    while (cin >> size)
    {
        if (size == 0)
            break;
        int sum = 0;
        int num = 0;
        while (size--)
        {
            cin >> num;
            sum += num;
        }
        res.push_back(sum);
        while (true)
        {
            if (cin.get() == '\n')
                break;
        }
    }

    for (auto it : res)
    {
        cout << it << endl;
    }
}