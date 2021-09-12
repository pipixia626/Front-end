//快速选择求Topk问题

#include<iostream>
#include<vector>
class Solution{
 public:
 int findKthLargest(std::vector<int>&nums,int k){
   return  quickSelect(nums,k,0,nums.size()-1);
 }

 int quickSelect(std::vector<int>&nums,int k,int left,int right){
   int i=left;
   int j=right;
   int mark=nums[left];

   while (left<right)
   {
       while (left<right&&nums[]>=mark)

       {
           /* code */
       }
       
   }
   
 }


};