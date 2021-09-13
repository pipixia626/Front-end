//合并k个有序数组

//暴力
//每次都从每个链表的第一个数中进行比较排序 ->O(K)
//一共有n个数 总的复杂度 O（n*k)

//优先级队列
//用小顶堆维护n个数里面最小的 ->logn
//一共有n个数 ->O(nlogk)

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};
//用来即把节点给存进去(为了找下一个节点)，也把值给存进去，找值

struct cmp
{
    bool operator()(const ListNode *first, const ListNode *second)
    {
        return first->val > second->val;
    }
};
ListNode *mergeKsortedList(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;
    priority_queue<ListNode *, vector<ListNode *>, cmp> min_heap;
    for (auto list : lists)
    {
        min_heap.emplace(list);
    }

    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    while (!min_heap.empty())
    {
        cur->next = min_heap.top();
        min_heap.pop();
        cur = cur->next;
        if (cur->next)
            min_heap.push(cur->next);
    }
    return dummy->next;
}

int main()
{
    int k;
    cin >> k;
    vector<ListNode *> lists;
    int num = 0;
    while (k--)
    {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (true)
        {
            cin >> num;
            ListNode *node = new ListNode(num);
            cur->next = node;
            cur = cur->next;
            if (cin.get() == '\n')
            {
                lists.push_back(head->next);
                break;
            }
        }
    }

    ListNode *res = mergeKsortedList(lists);
    while (res != nullptr)
    {
        cout << res->val << "->";
        res = res->next;
    }
    return 0;
}