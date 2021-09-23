#include <iostream>
#include <vector>
#include <string>
using namespace std;
//多个测试用例，每个测试用例一行
//输入：每行通过逗号 ‘，’隔开，有n个字符

//输出:处理好的输入

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    string str, s;
    vector<string> strs;
    while (getline(cin, s))
    {
        stringstream ss;
        ss << s;
        while (getline(ss, str, ','))
        {
            strs.push_back(str);
        }

        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs.size(); ++i)
        {
            cout << strs[i];
            if (i < strs.size() - 1)
                cout << ',';
        }
        cout << endl;
        strs.clear();
    }
}