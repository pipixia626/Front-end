#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string strRes;
        splitString(s);

        for (int i = res.size() - 1; i >= 0; i--) {
            strRes += res[i];
            strRes += " ";
        }
        return strRes;
    }

    void splitString(std::string s) {
        std::string::size_type pos1, pos2;
        pos2 = s.find(" ");
        pos1 = 0;
        while (std::string::npos != pos2) {
            res.push_back(s.substr(pos1, pos2 - pos1));
            pos1 = pos2 + 1;
            while (s[++pos2] == ' ') {
                pos1++;
            }
            pos2 = s.find(" ", pos1);
        }
        if (pos1 != s.length()) {
            res.push_back(s.substr(pos1));
        }
    }

private:
    std::vector<std::string> res;
};

int main(){
    std::string res="a good   example";

}