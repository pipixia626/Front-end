#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	Solution(vector<int>&datas) {
		this->size = datas.size();
	}
	//两数之和
	vector<vector<int>>towSum_unordered(vector<int>& datas, int target) {
		unordered_set<int>set;
		res.clear();
		vector<int>stored;
		for (int i = 0; i < size; ++i) {
			if (set.find(target - datas[i]) != set.end()) {
				stored.clear();
				stored.emplace_back(datas[i]);
				stored.emplace_back(target - datas[i]);
				res.emplace_back(stored);
			}
			else {
				set.insert(datas[i]);
			}
		}
		return res;
	}
	//两数之和 有序
	vector<int>towSum(vector<int>& datas, int target) {
		path.clear();
		int low = 0, high = size - 1;
		while (low < high) {
			if (datas[low] + datas[high] == target) {
				path.emplace_back(datas[low]);
				path.emplace_back(datas[high]);
			}
			else if (datas[low] + datas[high] > target) {
				high--;
			}
			else low++;
		}
		return path;
	}
	//最接近的两数之和
	vector<int> closeTwoSum(vector<int>& datas, int target) {
		path.clear();
		if (size < 2)return path;
		sort(datas.begin(), datas.end());
		int low = 0, high = size - 1;
		int closest = INT_MAX;
		int seqFirst=0, seqSecond = 0;
		while (low < high) {
			int sum = datas[low] + datas[high];
			if (sum == target) {
				path.emplace_back(datas[low]);
				path.emplace_back(datas[high]);
				return path;
			}
			
			if (closest < abs(target - sum)) {
				closest = abs(target - sum);
				seqFirst = low;
				seqSecond = high;
			}
			if (sum > target) {
				high--;
			}
			else {
				low++;
			}
		}
		if (seqFirst != 0 && seqSecond != 0) {
			path.emplace_back(datas[seqFirst]);
			path.emplace_back(datas[seqSecond]);
		}
		return path;
	}
	//三数之和
	vector<int> ThreeSum(vector<int>& datas, int target) {
		path.clear();
		if (size < 3)return path;
		sort(datas.begin(), datas.end());
		for (int i = 0; i < size; ++i) {
			int low = i + 1, high = size - 1;
			int remain = target - datas[i];
			while (low < high) {
				if (remain == datas[low] + datas[high]) {
					path.emplace_back(datas[i]);
					path.emplace_back(datas[low]);
					path.emplace_back(datas[high]);
				}
				else if (remain > datas[low] + datas[high]) {
					low++;
				}
				else high--;
			}
		}
		return path;
	}
	//最接近的三数之和
	vector<int> closeThreeSum(vector<int>& datas, int target) {
		path.clear();
		if (size < 3)return path;
		sort(datas.begin(), datas.end());
		int closest = INT_MAX;
		int seqFirst = 0, seqSecond = 0,seqThird;
		for (int i = 0; i < size; ++i) {
			int low = i + 1, high = size - 1;
			int remain = target - datas[i];
			seqFirst = i;
			while (low < high) {
				int sum = datas[low] + datas[high];
				if (sum == remain) {
					path.emplace_back(datas[low]);
					path.emplace_back(datas[high]);
					return path;
				}

				if (closest < abs(remain - sum)) {
					closest = abs(remain - sum);
					seqSecond = low;
					seqThird = high;
				}
				if (sum > remain) {
					high--;
				}
				else {
					low++;
				}
			}
			if (seqFirst != 0 && seqSecond != 0&&seqThird!=0) {
				path.emplace_back(datas[seqFirst]);
				path.emplace_back(datas[seqSecond]);
				path.emplace_back(datas[seqThird]);
			}
		}
		return path;
	}
	//四数之和
	vector<int> fourSum(vector<int>& datas, int target) {

	}
	//n数之和
	vector<vector<int>>nSum(vector<int>& datas, int target) {
		sort(datas.begin(), datas.end());
		path.clear();
		backtrack(datas, target, 0);
		return res;
	}
	void backtrack(vector<int>& datas, int target, int start) {
		if (target == 0) {
			res.emplace_back(path);
			return;
		}
		for (int i = start; i < size; ++i) {
			if (i > start && datas[i] == datas[i-1])continue;
			if (target -datas[i]< 0)break;
			path.emplace_back(datas[i]);
			backtrack(datas, target - datas[i], i + 1);
			path.pop_back();
		}
	}
	//n数之和 ,一个数可以重复选的
	vector<vector<int>>nSum_multi(vector<int>& datas, int target) {
		sort(datas.begin(), datas.end());
		backtrack_multi(datas, target, 0);
		return res;
	}
	void backtrack_multi(vector<int>& datas, int target, int start) {
		if (target == 0) {
			res.emplace_back(path);
			return;
		}
		for (int i = start; i < size; ++i) {
			//if (i > start && datas[i] == datas[i - 1])continue;
			if (target - datas[i] < 0)break;
			path.emplace_back(datas[i]);
			backtrack(datas, target - datas[i], i + 1);
			path.pop_back();
		}
	}
private:
	int size=0;
	vector<int>path;
	vector<vector<int>>res;
};
int main() {
	vector<int>datas{ 1,7,5,2,6 ,9,4};
	Solution* s=new Solution(datas);
	s->towSum(datas,8);


}