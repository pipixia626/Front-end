//利用STL自己实现split函数

/*
输入一个字符串，一个分割字符串(可包含多个分隔符)
*/

#include<iostream>
#include<vector>

void SpiltString(std::vector<std::string>& res,const std::string& text,const std::string &label){

    std::string::size_type pos1,pos2;
    pos2=text.find(label);
    pos1=0;
    while (std::string::npos!=pos2)
    {
       res.push_back(text.substr(pos1,pos2-pos1));

       pos1=pos2+label.size();
       pos2=text.find(label,pos1);
    }
    if (pos1!=text.length())
    {
        res.push_back(text.substr(pos1));
    }
    
}

int main(){

    std::string text="hello world";
    std::string label=" ";

    std::vector<std::string>res;
    SpiltString(res,text,label);
    for(auto it:res){
        std::cout<<it<<std::endl;
    }
}

