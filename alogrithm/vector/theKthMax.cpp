//找出数组中第k大的数

#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int>datas;
    for(int i=0;i<n;++i){
        std::cin>>datas[i];
    }
    std::sort(datas.begin(),datas.end());
    return datas[datas.size()-k];

}