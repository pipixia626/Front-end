#include<iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast ->next!= nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* cur = slow->next;
        slow->next = slow->next->next;
        delete(cur);

        return head;
    }
};

int main() {
    ListNode* list = new ListNode();
    ListNode* cur = list;
    for (int i = 1; i < 6; ++i) {
        ListNode* Node = new ListNode(i);
        cur->next = Node;
        cur = Node;
    }
    list = list->next;

    Solution s;
    ListNode* newList = s.removeNthFromEnd(list, 2);
    std::cout << newList->next->val<<std::endl;
}