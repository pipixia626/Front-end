#include<vector>
#include<string>
#include<iostream>
//输入n
//找出括号"{}()[]"的所有n对组合，不包含自己
using namespace std;


class Solution {
public:
    vector<string> findAllSet(int n) {
        backtrack(0, n);
        return res;
    }

    void backtrack(int start, int n) {
        if (path.length() == n) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < 6; ++i) {
            path += strs[i];
            backtrack(i + 1, n);
            path = path.erase(path.length() - 1, 1);
        }
    }
    void display() {
        for (auto& it : res) {
            cout << it << endl;
        }
    }
private:
    vector<string>res;
    string path;
    vector<string>strs{ "(",")","[","]","{","}" };
};


int main() {

    Solution solution;
    solution.findAllSet(2);
    solution.display();

    return 0;
}