//优先级队列的使用
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//自定义类型的比较

//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) { x = a; }
    bool operator<(const tmp1 &a) const
    {
        return x < a.x; //大顶堆
    }
};

struct tmp2 //重写仿函数
{
    bool operator()(tmp1 a, tmp1 b)
    {
        return a.x < b.x; //大顶堆
    }
};

//二元的
struct node
{
    int x, y;
    node(int x, int y) : x(x), y(y) {}
    bool operator<(const node &b) const
    {
        if (x == b.x)
            return y >= b.y;
        else
            return x > b.x;
    }
};
int main()
{

    //小顶堆
    priority_queue<int, vector<int>, greater<int>> min_heap;

    //大顶堆
    priority_queue<int, vector<int>, less<int>> max_heap;

    priority_queue<string> pri_str;

    for (int i = 0; i < 5; ++i)
    {
        min_heap.push(i);
        max_heap.push(i);
    }

    while (!min_heap.empty())
    {
        cout << min_heap.top() << ' ';
        min_heap.pop();
    }
    cout << endl;

    while (!max_heap.empty())
    {
        cout << max_heap.top() << ' ';
        max_heap.pop();
    }

    pri_str.emplace("abc");
    pri_str.emplace("abcd");
    pri_str.emplace("cbd");
    while (!pri_str.empty())
    {
        cout << pri_str.top() << ' ';
        pri_str.pop();
    }

    //pair的比较 先比较第一个再比较第二个

    priority_queue<pair<int, int>> a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty())
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }

    //自定义的
    tmp1 t1(1);
    tmp1 t2(2);
    tmp1 t3(3);
    priority_queue<tmp1> t;
    t.push(t1);
    t.push(t2);
    t.push(t3);

    while (!t.empty())
    {
        cout << t.top().x << " ";
        t.pop();
    }
    priority_queue<node> pq;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            pq.push(node(i, j));
    while (!pq.empty())
    {
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }
    return 0;

    return 0;
}