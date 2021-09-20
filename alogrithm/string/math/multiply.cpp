//实现两个字符串的相加

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";
    int size1 = num1.length(), size2 = num2.length();
    string res = "";

    vector<int> datas(size2+size1,0);
    //num2和num1相乘

    for (int i = size2 - 1; i >= 0; --i)
    {
        int n2 = num2[i] - '0';
        for (int j = size1 - 1; j >= 0; --j)
        {
            int n1 = num1[j] - '0';
            //datas[i+j+1]表示当前所处的位置 datas[i+j]表示前一个
            int tempSum=datas[i+j+1]+n2*n1;
            datas[i+j+1]=tempSum%10;
            //要和所有这个位置的数相加
            datas[i+j]+=tempSum/10;
        }
    }

    //为了判断第一位是否为0
    bool flag=true;
    for(int i=0;i<datas.size();++i){
        if(datas[i]!=0||!flag){
            flag=false;
            res.push_back(datas[i]+'0');
        }
    }
    return res;
}

int main(){
    string num1="123";
    string num2="456";

    cout<<multiply(num1,num2)<<endl;

    return 0;
}