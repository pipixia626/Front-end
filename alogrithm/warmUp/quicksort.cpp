#include<iostream>
#include<vector>


class Solution{

  public:
  void print_cout(const std::vector<int>datas){

  };

  std::vector<int> MyquickSort(std::vector<int>&datas){
        quickSort(datas,0,datas.size()-1);
        return datas;
  };

  void quickSort(std::vector<int>&datas,int left,int right){
        if(left<right){
            int point=patition(datas,left,right);
            quickSort(datas,left,point-1);
            quickSort(datas,point+1,right);
        }
  }
  int patition(std::vector<int>&datas,int left,int right){
           int first=range(left,right);
           while (left<right)
           {
               while (left<right&&datas[right]>=datas[first])
               {
                    right--;
               }
               swap(datas,left,right);
               while (left<right&&datas[left]<=datas[first])
               { 
                   left++;  
               }
               swap(datas,left,right);
           }
           return left;
  }

  int range(const int left,const int right){
        return rand()%(right-left+1)+left;
  }

  void swap(std::vector<int>&datas,int left,int right){
      int temp=datas[left];
      datas[left]=datas[right];
      datas[right]=temp;
  }
};