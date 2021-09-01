//环形链表问题
#include<unordered_set>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*判断有没有环*/
bool hasCycle(ListNode *head)
{

    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr)
    {
        slow = slow->next;
        if (fast->next == nullptr)
            return false;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
/*找到环起点第一个点*/

//双指针加一个额外指针
//双指针用来看有没有环，额外的指针用来当相遇时，从头出发一直到和slow指针相遇便会在入环点相遇
ListNode *detectCycle(ListNode *head)
{

    ListNode *fast = head;
    ListNode *slow = head;
    //这里对于快指针的下一个指针循环判断，如果fast为空了，就无法找到下一个next了，因此需要分开判断

    while (fast != nullptr)
    {
        slow = slow->next;
        //分开判断
        if (fast->next == nullptr)
            return nullptr;
        fast = fast->next->next;
        //第二次相遇
        if (fast == slow)
        {
            ListNode *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}
//哈希表实现
//遍历链表中的每个节点，并将它记录下来，一旦遇到了此前遍历过的节点，就可以判断链表中存在环
ListNode* detectCycle_hash(ListNode*head){
    unordered_set<ListNode*>visited;
    while (head!=nullptr)
    {
        if(visited.count(head))return head;
        visited.insert(head);
        head=head->next;
    }
    return nullptr;
    
}


//