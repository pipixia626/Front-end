
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional> // for greater<>
using namespace std;
int main()
{
    vector<float> bigs(10000, 0);
    vector<float>::iterator it;
    // Init vector data
    for (it = bigs.begin(); it != bigs.end(); it++)
    {
        *it = (float)rand() / 7; // random values;
    }
    cout << bigs.size() << endl;
    make_heap(bigs.begin(), bigs.end(), greater<float>()); // The first one is the smallest one!
    float ff;
    for (int i = 0; i < 1000000000; i++)
    {
        ff = (float)rand() / 7; //十亿个数都以随机数代替
        if (ff > bigs.front())  // replace the first one ?
        {
            // set the smallest one to the end!
            pop_heap(bigs.begin(), bigs.end(), greater<float>());
            // remove the last/smallest one
            bigs.pop_back();
            // add to the last one
            bigs.push_back(ff);
            // mask heap again, the first one is still the smallest one
            push_heap(bigs.begin(), bigs.end(), greater<float>());
        }
    }
    // sort by ascent
    sort_heap(bigs.begin(), bigs.end(), greater<float>());
    return 0;
}
