#include<iostream>
#include<bitset>
#include<sstream>
using namespace std;
//一些进制转化函数
int main(){
   //按指定进制格式输出

   cout<<"8进制"<<std::oct<<35<<endl;
   cout<<"10进制"<<std::dec<<35<<endl;
   cout<<"16进制"<<std::hex<<35<<endl;
   cout<<"2进制"<<std::bitset<32>(35)<<endl;

   //使用字符串流stringstream

   string s="20";
   int a;
   stringstream ss;
   ss<<hex<<s;//以16进制读入流

   ss>>a;
   cout<<a<<endl;

   //字符串转二进制

   string str="010101";
   bitset<32>bit(str);
   cout<<bit<<endl;

   //十进制转二进制
   a=10;
   int b=-10;
   bitset<32>bita(a);
   bitset<32>bitb(b);
   cout<<bita<<endl;
   cout<<bitb<<endl;
   return 0;
}