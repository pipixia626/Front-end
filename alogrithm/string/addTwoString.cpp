//两个数字字符串相加求和

#include<iostream>
#include<string>

int main() {

    std::string a;
    std::string b;
    std::cin >> a >> b;

    int res = 0;
    res = atoi(a.c_str()) + atoi(b.c_str());
    std::cout << std::to_string(res) << std::endl;
}