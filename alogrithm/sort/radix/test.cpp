#include<iostream>

int main(){
    int left=10;
    int right=30;
    int res=left+(right-left)>>1;
    std::cout<<res<<std::endl;
}