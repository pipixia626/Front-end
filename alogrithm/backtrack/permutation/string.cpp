#include <iostream>
#include <string>
#include <vector>
#include<set>
using namespace std;
//没有重复元素的字符全排列
class Solution {
public:
    vector<string> permutation(string s) {
        backtrack(s);
        return res;
    }
    void backtrack(string s) {
        if (visited.size() == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (visited.find(s[i]) == visited.end()) {
                path = path + s[i];
                visited.insert(s[i]);
                backtrack(s);
                visited.erase(s[i]);
                path.erase(path.length() - 1, 1);
            }
        }
    }
private:
    string path;
    vector<string>res;
    set<char>visited;
};
int main()
{
    Solution solution;
    string str = "abc";
    solution.permutation(str);
}