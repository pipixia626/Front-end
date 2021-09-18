#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
//有重复元素的字符全排列

class Solution
{
public:
    vector<string> permutation(string s)
    {
        backtrack(s, 0);
        return res;
    }
    void backtrack(string s, int start)
    {
        if (start == s.length() - 1)
        {
            res.push_back(s);
            return;
        }
        set<int> visited; //为了防止同一层递归出现重复元素
        for (int i = start; i < s.length(); ++i)
        {
            if (visited.find(s[i]) != visited.end())
                continue;
            visited.insert(s[i]);
            swap(s[i], s[start]);

            backtrack(s, start + 1);
            swap(s[i], s[start]);
        }
    }
    bool next_permutation(string &s)
    {
        int i = s.size() - 2;
        //从后面开始找相对升序的数
        while (i >= 0 && s[i] >= s[i + 1])
        {
            i--;
        }
        if (i < 0)
        {
            return false; //找完了
        }

        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j])
        {
            j--;
        }
        //交换
        swap(s[i], s[j]);
        //交换后重新排序
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s)
    {
        vector<string> res;
        sort(s.begin(), s.end());
        do
        {
            res.push_back(s);

        } while (next_permutation(s));
        return res;
    }

private:
    vector<string> res;
};
int main()
{
    Solution solution;
    vector<string> res = solution.permutation("aba");
    return 0;
}