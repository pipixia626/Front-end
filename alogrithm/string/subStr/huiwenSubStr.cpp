//判断一个子串里面有多少个回文子串

#include <iostream>
#include <vector>
#include <queue>
#include<unordered_set>
#include<time.h>
using namespace std;
//暴力
bool judgeIsPalindrome(string s) {
    int len = s.length() - 1;
    int left = 0, right = len;
    while (left != len) {
        if (s[left++] != s[right--])return false;
    }
    return true;
}
string mySubStr(string s, int start, int end) {
    string res;
    for (int i = start; i <= end; ++i) {
        res += s[i];
    }

    return res;
}
int countSubstrings(string s) {
    int count = 0;
    unordered_set<string>strings;
    for (int i = s.size()-1; i < s.length(); --i) {
        for (int j = i; j <s.length(); ++j) {
            string str = mySubStr(s,i, j);
            if (judgeIsPalindrome(str))
                ++count;
        }
    }
    return count;
}
//dp
int countSubStrings_dp(string s) {
    vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
    int result = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = i; j < s.size(); ++j) {
            if (s[i] == s[j]) {
                if (j - i <= 1) {
                    ++result;
                    dp[i][j] = true;
                }
                else if(dp[i + 1][j - 1]) {
                    ++result;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}



//中心扩展
int extend(const string& s, int i, int j, int n) {
    int count = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
        i--;
        j++;
        count++;
    }
    return count;
}
//双指针
int countSubStringS_TwoPointer(const string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result += extend(s, i, i, s.size());//以i为中心
        result += extend(s, i, i + 1, s.size());//以i+1为中心
    }
    return result;
}


int main()
{
    string s =
        "aabaa";
    clock_t start1, start2, start3, end1, end2, end3;
    start1 = clock();
    cout << countSubstrings(s) << endl;
    end1 = clock();
    cout << "F1运行时间" << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;
    start2 = clock();
    cout << countSubStrings_dp(s) << endl;
    end2 = clock();
    cout << "F2运行时间" << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

    start3 = clock();
    cout << countSubStringS_TwoPointer(s) << endl;;
    end3 = clock();
    cout << "F3运行时间" << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;
    
    return 0;
  
}