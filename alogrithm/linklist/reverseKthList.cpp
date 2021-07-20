#include<iostream>
#include<vector>
struct ListNode
{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class solution {

public:
	
	ListNode* reverse(ListNode*head) {
		ListNode* prev = nullptr;
		ListNode* pNext = nullptr;
		ListNode* cur = head;
		while (cur!=nullptr)
		{
			pNext = cur->next;
			cur->next = prev;
			prev = cur;
			cur = pNext;
		}
		return prev;
	}

	void reverKth(ListNode* head,const int left, const int right) {
		ListNode* phead = new ListNode(-1);
		phead->next = head;
		ListNode* prev = phead;
	    //找到要转移的节点的前一个节点
		for (int i = 0; i < left - 1; ++i) {
			prev = prev->next;
		}
		//找到要转移的节点的最后一个节点
		ListNode* pLastTrans = prev;
		for (int i = 0; i < right - left + 1; ++i) {
			pLastTrans = pLastTrans->next;
		}
		ListNode* pFirstTrans = prev->next;
		//要转移的节点的最后一个节点的下一个节点
		ListNode* pLastTrans_next = pLastTrans->next;

		//断开连接
		prev->next = nullptr;
		pLastTrans->next = nullptr;

		//反转
		reverse(pFirstTrans);

		//恢复连接

		prev->next = pLastTrans;
		pFirstTrans->next = pLastTrans_next;

		coutPrint(phead->next);
	}

	void coutPrint(ListNode*head) const{
		ListNode* cur = head;
		while (cur) {
			std::cout << cur->val << std::endl;
			cur = cur->next;
		}
	}

};

int main() {
	std::vector<int>datas{ 10,20,30,40,50};
	ListNode* head = new ListNode();
	ListNode* cur = head;
	for (auto it : datas) {
		ListNode* node = new ListNode(it);
		cur->next = node;
		cur = node;
	}
	head=head->next;
	solution* s = new solution();
	s->reverKth(head, 2, 4);

}