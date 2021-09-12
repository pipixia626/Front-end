#include<iostream>
#include<vector>
using namespace std;
#include<iostream>
using namespace std;
int main()
{
    int n;
    int sum=0;
    while(cin>>n){
        sum+=n;
        if(cin.get()=='\n'){ //注意：可替换为cin.get()=='\n'
            cout<<sum<<endl;
            sum=0;
        }
    }
    return 0;
}