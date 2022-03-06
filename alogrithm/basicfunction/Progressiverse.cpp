#include<cstdio>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

//将任意进制(radix)转化为10进制
int Atoi(string s, int radix) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = res * radix + s[i] - '0';//
		
	}
	return res;
}

//将10进制转化为任意进制radix
int ItoA(string s, int radix) {
	int res = 0;
	int num = std::stoi(s);
	string temp;
	do {
		int t = num % radix;
		temp += t + '0';
		num /= radix;
	} while (num != 0);
	reverse(temp.begin(), temp.end());
	res = std::stoi(temp);
	return res;
}
int main() {
	string s = "1000";

	/*int radix;
	cin >> radix;
	int res = Atoi(s, radix);
	cout << res << endl;
	return 0;*/

	/*int test = 0;
	test = std::stoi(s);
	cout << test << endl;*/

	int radix;
	cin >> radix;
	cout << ItoA(s, radix);
	return 0;


}
