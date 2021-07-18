#include <iostream>
#include <vector>
#include<algorithm>
//单个元素查找
//find
void find_a_num_find(const std::vector<int> nums, const int target)
{
    auto it = find(nums.begin(), nums.end(), target);
    if (it == nums.end())
    {
        std::cout << *it << std::endl;
    }
    else
        std::cout << "can't find out" << std::endl;
}

//find_if自定义比较函数

bool cmpFunction(int i)
{
    return (i % 15 == 0);
}

void find_a_num_find_if(const std::vector<int> nums, const int target)
{
    auto it = find_if(nums.begin(), nums.end(), cmpFunction(target));
    if (it == nums.end())
    {
        std::cout << *it << std::endl;
    }
    else
        std::cout << "can't find out" << std::endl;
}

//count 统计元素出现次数

void count_num_times_count(const std::vector<int> nums, const int target)
{
    int res = std::count(nums.begin(), nums.end(), target);
    std::cout << res << std::endl;

}

void count_num_times_count_if(const std::vector<int> nums, const int target)
{
    int res = std::count(nums.begin(), nums.end(), cmpFunction(target));
    std::cout << res << std::endl;
}

//search_n 查找区间中重复出现n次的元素

void search(const std::vector<int> nums, const int target){
   auto it=std::search_n(nums.begin(),nums.end(),2,target);
}

//lower_bound() 有序区间中查询元素边界
//low=std::lower_bound (v.begin(), v.end(), 20);


//区间查找 search() 查找子区间首次出现的位置

/*

min_element() 查找最小元素min_element() 在给定区间中查找出最小值;
int myints[] = {3,7,2,5,6,4,9};
std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';

类似算法有：max_element() 查找最大值；

区间查找 search()
search() 查找子区间首次出现的位置find()用来查找单个元素，
search()则用来查找一个子区间；
示例：从myvector中查找出现子区间[20，30]的位置: 
int needle1[] = {20,30}; 
it = std::search (myvector.begin(), myvector.end(), needle1, needle1+2);  
if (it!=myvector.end())  
std::cout << "needle1 found at position " << (it-myvector.begin()) << '\n';
search支持自定义比较函数；
示例：查询给定区间中每个元素比目标区间小1的子区间；bool cmpFunction (int i, int j)
{  return (i-j==1);}
int myints[] = {1,2,3,4,5,1,2,3,4,5};std::vector haystack (myints,myints+10);int needle2[] = {1,2,3};
using predicate comparison:it = std::search (haystack.begin(), haystack.end(), needle2, needle2+3, cmpFunction);find_end() 查找子区间最后一次出现的位置search() 用来查找子区间第一次出现的位置，而find_end()用来查找子区间最后一次出现的位置：find_end()支持自定义比较函数；equal() 判断两个区间是否相等equal（）用来判断两个区间是否相等，
该算法支持自定义比较函数；mismatch() 
查询两个区间首次出现不同的位置mismatch() 
查询两个区间首先出现不同的位置，
这个算法也支持自定义比较函数；



*/

