//相交链表，返回相交开始的第一个节点

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    ListNode *A = headA;
    ListNode *B = headB;
    //消除两个链表的长度，你走我的路，我走你的路
    while (A != B)
    {
        A = A == nullptr ? headB : A->next;
        B = B == nullptr ? headA : B->next;
    }
    return A;
}
