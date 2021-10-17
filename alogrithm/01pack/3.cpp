//多重背包问题

//有 N 种物品和一个容量为 V的背包。第i种物品最多有 n[i]件可用，每件费用是 value[i] ，
//价值是 value[i] 。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N, V;
	cin >> N >> V;
	vector<int>weight(N + 1);
	vector<int>value(N + 1);
    vector<int>nums(N+1);
    //将第i种物品的数量全部转化到新的物品上，即价值相同，序号不同
}