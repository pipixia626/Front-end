//stl 常用算法


#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;


class Algor {
private:
	vector<int>datas{ 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
public:
	//查找算法
	void search_stl() {
		/*** adjacent_find: 在iterator对标识元素范围内，查找一对相邻重复元素 ***/
		cout << "adjacent_find: ";
		cout << *adjacent_find(datas.begin(), datas.end()) << endl;

		/*** count: 利用等于操作符，把标志范围内的元素与输入值比较，返回相等元素个数。 ***/
		cout << "count(==6): ";
		cout << count(datas.begin(), datas.end(), 6) << endl;// 统计6的个数

		/*** binary_search: 在有序序列中查找value，找到返回true。 ***/
		cout << "binary_search: ";
		cout << binary_search(datas.begin(), datas.end(), 4) << endl;
	}
};

int main() {
	Algor al;
	al.search_stl();
	return 0;
}