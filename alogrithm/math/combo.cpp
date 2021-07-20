//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

//问总共有多少条不同的路径？

/*
输入：m=3,n=7输出 28；
*/


//思路：
//排列组合：m=3,n=2->C(m-1,m+n-2)=C(2,3);

#include<iostream>
using namespace std;

//计算阶乘
/*
0！=1
*/
int factorial(int n){
    int count=1;
    for(int i=1;i<=n;i++) count*=i;
    return count;
}

//计算组合数
/*
从n个不同元素中取出m个元素的所有组合的个数
C(n,m)=n!/(m！*(n-m)!)
*/

int combo(int n,int m){
    return factorial(n)/factorial(m)*factorial(n-m);
    
}

//计算排列数
/*
从n个不同元素中取出m个元素的所有排列的个数
A(n,m)=n!/(n-m)!
*/
int permutaition(int n,int m){
    return factorial(n)/factorial(n-m);
    
}

int main(){
     int m,n;
     cin>>n>>m;
     cout<<"C(n,m)"<<combo(n,m)<<endl;
     cout<<"A(n,m)"<<permutaition(n,m)<<endl;
     return 0;

     
}