#include <string>
#include <iostream>
#include <vector>

bool check_Name(std::string str)
{
    bool containNum = false;
    if (!isalpha(str[0]))
        return false;

    for (int i = 1; i < str.length(); ++i)
    {
        //不是字母或数字
        if (!isalnum(str[i]))
            return false;
        //是字母或数字
        else
        {
            //不是字母
            if (!isalpha(str[i]))
            {
                containNum = true; //包含数字
            }
        }
    }
    return containNum == true ? true : false;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> names(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> names[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (check_Name(names[i]))
        {
            std::cout << "Accept" << std::endl;
        }
        else
        {
            std::cout << "Wrong" << std::endl;
        }
    }
}