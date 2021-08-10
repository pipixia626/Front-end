//heap测试实例
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //test heap (底层以vector完成)
    int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
    vector<int> ivec(ia, ia + 9);
    make_heap(ivec.begin(), ivec.end());
    for (int i = 0; i < ivec.size(); ++i)
    {
        cout << ivec[i] << ' '; //9 5 8 3 4 0 2 3 1
        cout << endl;
    }

    ivec.push_back(7);
    push_heap(ivec.begin(), ivec.end());
    for (int i = 0; i < ivec.size(); ++i)
    {
        cout << ivec[i] << ' '; //9 7 8 3 5 0 2 3 1 4
        cout << endl;
    }

    pop_heap(ivec.begin(), ivec.end());
    cout << ivec.back(); //9 return but no remove
    ivec.pop_back();     //remove but not return

    for (int i = 0; i < ivec.size(); ++i)
    {
        cout << ivec[i] << ' '; //9 7 8 3 5 0 2 3 1 4
        cout << endl;
    }
}