// 输入：[7,1,5,3,6,4]
// 输出：5
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int maxProfit_voilence(vector<int> &prices)
{
    int maxMoney = 0;

    for (int left = 0; left < prices.size() - 1; ++left)
    {
        for (int right = left + 1; right < prices.size(); ++right)
        {
            maxMoney = max(maxMoney, prices[right] - prices[left]);
        }
    }
    return maxMoney;
}
int maxProfit_onceScan(vector<int>& prices){
    int maxMoney=0,minPrice=1e9;
    for(auto price:prices){
        minPrice=min(minPrice,price);
        maxMoney=max(maxMoney,price-minPrice);
    }
    return maxMoney;
}
int main()
{
    vector<int> datas{7, 1, 5, 6, 3};
    cout << maxProfit_voilence(datas) << endl;
    cout<<maxProfit_onceScan(datas)<<endl;
}