#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
//string 的一些常规操作
//参考https://www.jianshu.com/p/7b0e25d6c2c8
class String {
private:
	std::string str1;
	std::string str2;

public:
	String(std::string _str1, std::string _str2) :str1(_str1), str2(_str2) {};
	~String() {
	}
	//string 遍历
	void print_cout() {
		for (int i = 0; i < str1.length(); ++i) {
			std::cout << str1[i];
		}
		for (std::string::iterator iter = str2.begin(); iter != str2.end(); ++iter) {
			std::cout << *iter;
		}
	}
	 //basic
	void basic_string() {
		//insert
		std::string::iterator p = str1.begin();
		str1.insert(p, 'a');
		str1.insert(str1.begin(), 'c');
		str1.insert(str1.begin() + 3, 'b');
		str1.insert(str1.begin() + 3, 3,'b');

		//erase
		int pos = 0,len = 3;
		str1.erase(pos, len);//从下标为pos开始的len个字符

		//赋值
		str1.assign(str2, pos, len);//从str2中下标Pos开始的len个字符
		//同理substr(),append(),replace()
	 
		//取子串
		std::string str3 = str1.substr(1,2);

		//连接
		str1.append(str2);

		//替换
		str1.replace(str2.begin(), str2.end(), "aaa");
	    //查找
		std::string name("world");
		std::string::size_type pos1 = name.find("ld");
		if (pos1 == std::string::npos) {
			std::cout << "no find" << std::endl;
		}
		else {
			std::cout << "find it" << std::endl;
		}
		//find 
		    //s.find(args)	查找s中args第一次出现的位置
			//s.rfind(args)	查找s中args最后一次出现的位置
			//s.find_first_of(args)	在s中查找args中任何一个字符第一次出现的位置
			//s.find_last_of(args)	在s中查找args中任何一个字符最后一次出现的位置
			//s.find_first_not_of(args)	在s中查找第一个不在args中的字符
			//s.find_last_not_of(args)	在s中查找最后一个不在args中的字符

	
		//大小写转换
		std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
		std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

		//转数值
		std::string str1 = "-45";
		std::string str2 = "3.14159";
		int value1 = stoi(str1);
		long value2 = stol(str2);

		size_t pos11 = 0;
		value1 = std::stoi("123456abcdefg", &pos1);
		std::cout << value1 << std::endl;//123456
		std::cout << pos11 << std::endl;//6
	}
	//以逗号分割
	std::vector<std::string> splitPathStr() {
		std::vector<std::string>fileLists;
		std::stringstream sstr(str1);
		std::string token;
		while (getline(sstr, token, ';')) {
			fileLists.push_back(token);
		}
		return fileLists;
	}
};

int main() {
	std::string s1 = "hello, world,nihao;tahao";
	std::string s2 = "hello, world,wohao";
	String s(s1,s2);
	//std::cout << s1.erase(2, 3);
	//std::string s2 = "no no no";
	//std::cout<<s1.replace(6, 2, "nnbbn");->hello nnbbnrld
	std::vector<std::string>res = s.splitPathStr();

	std::cout << res[0] << std::endl;

}