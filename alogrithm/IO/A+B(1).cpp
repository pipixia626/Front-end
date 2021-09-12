//输入
// 1 5
// 10 20

//输出
// 6
// 30

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num1;
    vector<int> nums;
    while (cin >> num1)
    {
        int sum = 0;
        while (true)
        {
            sum += num1;
            if (cin.get() == '\n')
                break;
            cin >> num1;
        }
        nums.push_back(sum);
    }

    for (auto it : nums)
    {
        cout << it << endl;
    }
}