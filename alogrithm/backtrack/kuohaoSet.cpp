#include<vector>
#include<string>
//找出括号()有效的组合
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)return res;
        string path = "";
        backtrack(n, n, path);
        return res;
    }
    // left 左括号剩余可以使用的数量，右括号剩余可以使用的数量
    void backtrack(int left, int right, string  path) {
        if (left ==0&&right == 0) {
            res.push_back(path);
            return;
        }
        //左括号剩余数比右括号剩余数少
        if (left > right) {
            return;
        }
        //左括号还能用
        if (left > 0) {
            backtrack(left - 1, right, path+"(");
        }
        //右括号还能用
        if (right > 0) {
            backtrack(left, right - 1, path+")");
        }
    }
private:
    vector<string>res;
};

int main() {
    Solution solution;
    vector<string>res;
    res=solution.generateParenthesis(2);
    return 0;
}