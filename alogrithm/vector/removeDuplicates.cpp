/*给你一个有序数组 nums ，
请你 原地 删除重复出现的元素，使每个元素 只出现一次 
，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <vector>
using namespace std;
class Solution
{
public:
    //0 1 1 2 2 3
    //0 1 2 3 4 5
    
    //0 1 2 2 2 3 slow=1 fast=3 slow=2 fast=4 slow=2,fast=5
    
    // 0 1 2 3 2 3 slow=3 fast=6
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int slow = 0, fast = 1;
        while (fast < n)
        {   
            if (nums[fast] != nums[slow])
            {   
                //相差大一个数说明有重复
                if (fast - slow > 1)
                {   
                    //移动fast到slow+1
                    nums[slow + 1] = nums[fast];
                }
                slow++;
            }
            fast++;
        }
        return slow + 1;
    }

    int removeDuplicates_other(vector<int>&nums){
        int i=0,j=0;
        while(j<nums.size()){
            if(i==0||nums[j]!=nums[i-1]){
                nums[i++]=nums[j++];
            }
            else j++;
        }
        return i;
    }
};