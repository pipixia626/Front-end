//链表排序
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    //合并两个有序链表
    ListNode *mergeList(ListNode *l1, ListNode *l2)
    { //如果某一个链表为空，则返回剩下一个链表

        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeList(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
    }
    //寻找中间节点
    // 3 ->4->1->2
    ListNode *findMid(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *tail = nullptr;
        //判断fast到结束了没有
        while (fast != nullptr && fast->next != nullptr)
        {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //断开一半
        tail->next = nullptr;
        return tail;
    }
    //递归的拆解
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *mid = findMid(head);
        //排序前面一半
        ListNode *l1 = sortList(head);
        //排序后面一半
        ListNode *l2 = sortList(mid);
        //归并
        return mergeList(l1, l2);
    }
};