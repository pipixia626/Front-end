//两个字符串相加

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add_str(string num1, string num2) {
    int size1 = num1.length();
    int size2 = num2.length();
    int i = size1 - 1;
    int j = size2 - 1;
    int add = 0;
    string res = "";
    int n1 = 0;
    int n2 = 0;
    while (i >= 0 || j >= 0 || add != 0)
    {

        n1 = i >= 0 ? num1[i--]-'0': 0;

        n2 = j >= 0 ? num2[j--]-'0' : 0;

        int tempSum = n1 + n2 + add;
        add = tempSum / 10;
        res.push_back(tempSum % 10 + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1 = "123";
    string num2 = "9889";
    cout << add_str(num1, num2) << endl;
    return 0;
}