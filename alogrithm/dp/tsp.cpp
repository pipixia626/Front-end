#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1000
//dp[N][M]来表示，N表示城市的个数，M表示集合的数量
//为什么这么表示？
// 这里说明一下比如集合{ 1,2,3,4 }为什么用15表示，
// 我们可以把 集合中元素看成二进制1的位置（二进制从右开始看），
// 1表示从右开始第一位为1, 2表示从又开始第二位为1，
// 所以集合{ 1,2,3,4 }可表示二进制（1111）转化为十进制为15。
// 再举个例子比如集合{ 1,3 }表示为二进制为0101，十进制为5。
// 所以我们求出dp[0][15]就是本题的最终解。
//
//注意：
//对于第y个城市，他的二进制表达为，1 << (y - 1)。
//对于数字x，要看它的第i位是不是1，那么可以通过判断布尔表达式(((x >> (i - 1)) & 1) == 1或者（x & (1 << (i - 1))） != 0的真值来实现。
//由动态规划公式可知，需要从集合中剔除元素。假如集合用索引x表示，要剔除元素标号为i, 我们异或运算实现减法，其运算表示为： x = x ^ (1 << (i - 1))。
//	
class Graph {
private:
	int city_num = 0;//城市数量
	int M;
	vector<vector<int>>distance;
	vector<int>path;//保存路径
public:
	void init() {
		this->city_num = 5;
		vector<vector<int>>datas{
			   {0,3,INF,8,9},
			   {3,0,3,10,5},
			   {INF,3,0,4,3},
			   {8,10,4,0,20},
			   {9,5,3,20,0} 
		};
		this->distance = datas;
		int M = 1 << (city_num - 1);
		this->M = M;
		vector<vector<int>>dp(5, vector<int>(M));

		//init
		for (int i = 0; i < city_num; ++i) {
			//所有城市到第0个城市的路径初始化为两市之间的距离
			dp[i][0] = distance[i][0];
		}

		print_city(dp);

		dp_tsp(dp);
		cout << "min res" << dp[0][M-1]<<endl;

	}
	void print_city(vector<vector<int>>dp) {
		for (int i = 0; i < city_num; ++i) {
			for (int j = 0; j < city_num; ++j) {
				cout << distance[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void dp_tsp(vector<vector<int>>&dp) {
		for (int j = 1; j < M; ++j) {
			for (int i = 0; i < city_num; ++i) {
				dp[i][j] = INF;
				//如果集合j中包含节点i则继续，不包含则跳过
				if (((j >> (i - 1)) & 1) == 1) {
					continue;
				}
				//枚举集合j中的节点
				for (int k = 1; k < city_num; ++k) {
					//如果集合中没有节点k，则跳过
					if (((j >> (k - 1)) & 1) == 0) {
						continue;
					}
					////使用异或去掉集合j中的节点k。
					if (dp[i][j] > distance[i][k] + dp[k][j ^ (1 << (k - 1))]) {
						dp[i][j] = distance[i][k] + dp[k][j ^ (1 << (k - 1))];
					}
				}
			}
		}
	}
}; 
int main() {
	Graph g;
	g.init();
	return 0;
}