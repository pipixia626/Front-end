//给定一个字符串，找出不含有重复字符的最长字串的长度

/*
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。*/

//双指针解法，左右指针会各遍历一次->O(N)
#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubString(std::string s)
{
    int left, right = 0; //双指针
    //存最大的数
    int res = 0;
    //用一个set集合来存无重复字符
    std::unordered_set<char> strSet;
    //当左指针遍历完之后
    while (left < s.length())
    {
        //用右指针来寻找，count set里面有没有重复的字符
        while (right < s.length() && strSet.count(s[right]) == 0)
        {
            strSet.insert(s[right]);
            res = std::max(res, right - left + 1); //right-left+1是当前字符串的长度
            right++;                               //往右移位
        }
        //有重复的了
        strSet.erase(s[left]);
        left++;
    }
    return res;
}

int main()
{
    std::string s = "abcabcbb";
    int res = lengthOfLongestSubString(s);
    std::cout << res << std::endl;
}
