#include <algorithm>
#include <vector>
#include <iostream>
#include<set>
#include<map>
using namespace std;

int main()
{
    vector<int> datas{1, 3, 5, 5, 7, 9};
    vector<int> datas2{7, 5, 9};
    //查找一对相邻重复元素
    cout << "一对相邻重复元素" << endl;
    cout << *adjacent_find(datas.begin(), datas.end());

    //二分查找
    cout << "二分查找" << endl;
    cout << binary_search(datas.begin(), datas.end(), 5) << endl;

    //把标志范围内的元素与输入值比较，返回相等元素个数
    cout << "计算某个元素的数量" << endl;
    cout << count(datas.begin(), datas.end(), 5) << endl;

    //对标志范围内的元素进行操作，返回结果为true的个数
    cout << "count_if" << endl;
    cout << count_if(datas.begin(), datas.end(), [](const int &a)
                     { return a >= 5; });

    //功能类似equal，返回一对iterator，第一个表示lower_bound，第二个表示upper_bound。

    set<char> m = {'a', 'b', 'c', 'd'};

    auto ret = m.equal_range('b');

    cout << "b的下限是: " << *ret.first << endl;

    cout << "b的上限是: " << *ret.second << endl;

    //search 和search_n
    vector<int> t1 = {3,5,7,7,11,6,17,19};
	vector<int> t2 = {11,13};
 
	vector<int>::iterator it;
 
	//找到t2中元素在t1中第一次出现的位置，不像find函数只能找一个
	it=search(t1.begin(),t1.end(),t2.begin(),t2.end());
 
	//寻找首次连续出现2次7的位置
	it=search_n(t1.begin(),t1.end(),2,7);
 
	//寻找首次连续出现2次大于7的位置
	it=search_n(t1.begin(),t1.end(),2,7,[](int i,int j){return i>j;});
 
	if(it!=t1.end())cout<<it-t1.begin();

}