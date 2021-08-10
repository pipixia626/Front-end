// 带有权值观念的queue，允许加入新元素，移除旧元素，审视元素值
// 缺省情况下是利用max_heap完成的(vector 表现)
// 完全以底部容器为根据，再加上heap处理规则
// 因为具有“修改某物接口，形成另一种风貌"
// 因此也是适配器

//测试实例
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    //test priority queue

    int ia[9]={0,1,2,3,4,8,9,3,5};
    priority_queue<int>ipq(ia,ia+9);
    cout<<"size="<<ipq.size()<<endl;

    for(int i=0;i<ipq.size();++i){
        cout<<ipq.top()<<' ';//9 9 9 9 9 9 9 9 9 9 
        cout<<endl;
    }
    while (!ipq.empty())
    {
     cout<<ipq.top()<<' ';// 9 8 5 4 3 3 2 1 0
     ipq.pop();
    }
    cout<<endl;
    
}