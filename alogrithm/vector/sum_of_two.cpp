//两数之和

//暴力

#include <iostream>

#include <vector>

#include <unordered_map>

std::vector<int> twoSumVoilence(std::vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == target - nums[j])
                return {i, j};
        }
    }
    return {};
}
//暴力的时间复杂度高是因为寻找target-x过高
//因此用hashtable来找到target-x将时间复杂度降低到从 O(N)降低到 O(1)。
std::vector<int> twoSumHash(std::vector<int> &nums, int target)
{
    std::unordered_map<int,int>hashtable;
    for(int i=0;i<nums.size();++i){
        //查询哈希表有没有target-x
        auto it =hashtable.find(target-nums[i]);
        if(it!=hashtable.end()){
            return{it->second,i};
        }
        //没有就加入到哈希表中，保证不会让x和自己匹配
        hashtable[nums[i]]=i;
    }
    return {};
}