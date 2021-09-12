#include <iostream>
#include <vector>
using namespace std;

//输入包括两个正整数a,b(1 <= a, b <= 10^9),
//输入数据有多组, 如果输入为0 0则结束输入

//输出a+b的结果

int main()
{
    int num1,num2;
    vector<int> res;
    while (cin >> num1>>num2)
    {   int sum=0;
      if(num1==0&&num2==0)break;
      
        res.push_back(num1+num2);
        while (true)
        {  
          if(cin.get()=='\n')
              break;
        }
    
    }
   for(auto it:res){
       cout<<it<<endl;
   }
    return 0;
}
