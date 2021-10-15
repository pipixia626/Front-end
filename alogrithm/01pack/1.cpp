#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// N个物品，背包V个体积
//每个物品体积和价值weight[i]和value[i]
//解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
int main() {
	
	int N, V;
	cin >> N >> V;
	vector<int>weight(N + 1);
	vector<int>value(N + 1);
	vector<int>record(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> weight[i] >> value[i];
	}
	vector<vector<int>>dp(N + 1, vector<int>(V + 1, 0));
    vector<int>dp_update(V+1);
	for (int i = 1; i <= N; ++i) {
		for (int j =0 ; j <= V; ++j) {
			if (j < weight[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else 
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}
	int k = V;

	for (int i = N; i > 0; --i) {
		if (dp[i][k] > dp[i - 1][k]) {
			record[i] = 1;
			k = k - weight[i];
		}
		else record[i] = 0;
	}

	for (int i = 0; i <= N; ++i) {
		cout << record[i] << endl;
	}
	cout << dp[N][V] << endl;


	for(int i=1;i<=N;++i){
		for(int j=V;j>=weight[i];j--){
			dp_update[j]=max(dp_update[j], dp_update[j-weight[i]]+value[i]);
		}
	}
	cout<<dp_update[V]<<endl;
	return 0;

}