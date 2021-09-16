// 小M的程序设计大作业是编写一个多任务下载器，在做到计算任务并发数的时候遇到了困难。

// 在一次下载中，总共包含N个任务，每个任务会在第x秒开始、并持续y秒。小M想要知道，在一次下载中，同时最多会有多少个任务正在下载
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int>const &a,pair<int,int>const&b){
    return a.first<b.first||a.first==b.first&&a.second<b.second;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>vec;
    vec.reserve(2*n);
    int startTime=0,continueTime=0;
    for(int i=0;i<n;++i){
        cin>>startTime>>continueTime;
        vec.emplace_back(startTime,1);
        vec.emplace_back(startTime+continueTime,-1);
    }
    sort(vec.begin(),vec.end(),cmp);

    int res=0;
    int count=0;

    for(auto const&i:vec){
        count+=i.second;
        res=max(res,count);
    }
    cout<<res<<endl;
    return 0;
}

