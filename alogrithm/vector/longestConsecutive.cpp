//最长连续序列
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
//找连续的方法有从这个数前面开始找和从这个数后面开始找
//首先判断前一个数存在不存在
//存在则跳过
//不存在则从这个数后面开始找
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (const int &num : nums)
        {
            num_set.insert(num);
        }
        int longestStreak = 0;

        for (const int &num : num_set)
        {
            if (!num_set.count(num - 1))//前一个数不存在
            {
                int currentNum = num;
                int currentStreak = 1;
                //从这个数往后面开始找
                while (num_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};