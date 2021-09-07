#include <string>
#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> strs;

    int nums = 0;
    std::string temp;
    std::cin >> nums;
    std::vector<std::string> judges;
    int count = 0;
    std::cin >> count;
    for (int i = 0; i < nums; ++i)
    {
        std::cin >> temp;
        strs.insert(temp);
    }

    for (int i = 0; i < count; ++count)
    {
        std::cin >> temp;
        judges.push_back(temp);
    }

    for (int i = 0; i < count; ++count)
    {
        if (strs.find(judges[i]) == strs.end())
        {
            std::cout << "true";
        }
        else
            std::cout << "false";

        std::cout << std::endl;
    }
    return 0;
}
