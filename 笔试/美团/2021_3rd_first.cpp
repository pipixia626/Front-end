// 小美是美团仓库的管理员，她会根据单据的要求按顺序取出仓库中的货物，
//每取出一件货物后会把剩余货物重新堆放，使得自己方便查找。
//已知货物入库的时候是按顺序堆放在一起的。
//如果小美取出其中一件货物，则会把货物所在的一堆物品以取出的货物为界分成两堆，
//这样可以保证货物局部的顺序不变。
//已知货物最初是按1~n的顺序堆放的，每件货物的重量为w_i,小美会根据单据依次不放回的取出货物。
//请问根据上述操作，小美每取出一件货物之后，重量和最大的一堆货物重量是多少？
#include<unordered_set>
#include<vector>
#include<iostream>
#include<algorithm>
//   3 2 4 4 2 5

//  3 2 4 / 2 5
// 2 4 / 2  5
// 2   /2  5
//2  /5
//2   
//


 int getMaxOfVector(std::vector<std::vector<int>>datas){
    int res=0;

    for(int i=0;i<datas.size();++i){
       for(int j=0;j<datas[i].size();++j){
           int count=0;
           count+=datas[i][j];
           res=std::max(count,res);
       }
    }
    return res;
}

void cutVector(std::vector<std::vector<int>>&datas,int cut){
    
}
int main(){
    int n=0;//货物的数量
    std::vector<int> weight(n);
    std::vector<std::vector<int>>res;
    for(int i=0;i<n;++i){
      std::cin>>weight[i];
    }
    for(int i=0;i<n;++i){
     
    }
}