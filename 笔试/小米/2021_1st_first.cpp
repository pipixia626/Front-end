#include <iostream>
#include <vector>
#include<algorithm>
int main()
{
    int box = 0;   //槽位
    int times = 0; //个数

    std::cin >> box >> times;

    std::vector<int> keys(box, 0);

    std::vector<std::pair<int, int>> ranges;
    int countTimes = 0;
    //input
    while (times > countTimes)
    {
        std::pair<int, int> data;
        std::cin >> data.first >> data.second;
        ranges.push_back(data);
        ++countTimes;
    }

    countTimes = 0; //计算轮数
    while (times>countTimes)
    {
        for (int i = ranges[countTimes].first, j = ranges[countTimes].second; i <=j; ++i)
        {
            keys[i] = countTimes+1;
        }
        ++countTimes;
    }
    countTimes = 0;
    for (int i = 0; i < box; ++i) {
         countTimes += keys[i] * i;
    }
    std::cout << countTimes %(100000009);

    return 0;
}