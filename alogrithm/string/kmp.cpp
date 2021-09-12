//Substr实现

#include <iostream>
#include <string>

using namespace std;
//判断字符串t在字符串s的第几个位置开始出现

void getNext(string t, int next[])
{

    int length = t.length();
    next[0] = -1;
    int j = 0, k = -1;
    while (j < length)
    {  
        
         // 当k=-1，代表前面匹配失败，重新开始匹配。
        // 当T[k] == T[j]，代表匹配成功，进行下一次的匹配。
        if (k == -1 || t[k] == t[j])
        {
            k++;
            j++;
            next[j] = k;
        }
        else
        {
            k = next[k]; // 如果两个条件都不满足，让k=next[k]，去next的位置，重新开始。
        }
    }
}
int Index_KMP(string s, string t, int next[], int pos)
{
    int i = pos, j = 0;
    getNext(t, next);
    int slen = s.length(), tlen = t.length();
    while (i < slen && j < tlen)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];//让j=next[j]，去next的位置，重新开始
        }
    }
    if (j == tlen)
    {
        return i - tlen + 1;
    }
    return -1;
}

int main()
{
    int next[20];
    string s = "abaacababcac", t = "ababc";
    cout << Index_KMP(s, t, next, 1);
    return 0;
}