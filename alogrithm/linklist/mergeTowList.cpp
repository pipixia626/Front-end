//合并两个有序链表
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 = nullptr)
        return l1;

    ListNode *myList = new ListNode(-1);
    ListNode *cur = myList;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val >= l2->val)
        {
            ListNode *node = new ListNode(l2->val);
            l2 = l2->next;
            cur->next = node;
            cur = cur->next;
        }
        else
        {
            ListNode *node = new ListNode(l1->val);
            l1 = l1->next;
            cur->next = node;
            cur = cur->next;
        }
    }
    cur->next=l1!=nullptr?l1:l2;
    return myList->next;
}

