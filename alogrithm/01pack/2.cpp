//完全背包问题

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// N个物品，背包V个体积
//每个物品体积和价值weight[i]和value[i]
//解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
//每种物品有无限件
int main() {
	
	int N, V;
	cin >> N >> V;
	vector<int>weight(N + 1);
	vector<int>value(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> weight[i] >> value[i];
	}
	vector<vector<int>>dp(N + 1, vector<int>(V + 1, 0));
	for (int i = 1; i <= N; ++i) {
		for (int j =0 ; j <= V; ++j) {
			if (j < weight[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else 
            //把参考系作为了当前物品
			dp[i][j] = max(dp[i -1][j], dp[i][j - weight[i]] + value[i]);
		}
	}



	return 0;

}