#include<iostream>
#include<vector>
using namespace std;


struct LinkNode {
	int val;
	LinkNode* next;
	LinkNode():val(0),next(nullptr){}
	LinkNode(int _val):val(_val),next(nullptr){}
};

class LinkList {
private:
	LinkNode* head;
	int size;

public:
	LinkList( LinkNode*list) {
		head = list;
	}
	~LinkList() {
		while (!empty()) {
			removeFront();
		}
		delete head;
	}
	void setSize() {
		LinkNode* cur = head->next;
		while (cur) {
			++size;
			cur = cur->next;
		}
		this->size = size;
	}
	bool empty()const {
		return (head->next == nullptr);
	}
	//在第K个地方添加节点
	void addFront(const int k ,const int& e) {
		LinkNode* cur = head;
		for (int i = 0; i < k; ++i) {
			cur = cur->next;
		}
		LinkNode* node =new LinkNode(e);
		node->next = cur->next;
		cur->next = node;
	}
	//删除第k个节点
	void removeK(const int k) {
		LinkNode* cur = head;
		for (int i = 0; i < k-1; ++i) {
			cur = cur->next;
		}
		LinkNode* old = cur->next;
		cur->next = cur->next->next;
		delete old;

	}
	//删除头节点的下一个节点
	void removeFront() {
		if (empty()) {
			return;
		}
		LinkNode* old = head->next;

	}
	//反转链表
	LinkNode* reverse() {
		LinkNode* cur = head->next;
		LinkNode* prev = nullptr;
		LinkNode* pNext = nullptr;
		while (cur) {
			pNext = cur->next;
			cur->next = prev;
			prev = cur;
			cur = pNext;
		}
		return prev;
	}
	//找到第k个节点
	LinkNode* findKth(int k) {
		LinkNode* cur = head;
		for (int i = 0; i < k; ++i) {
			cur = cur->next;
		}
		return cur;
	}
	//判断有没有环
	bool ifCycle(LinkNode*head) {
		if (empty()) {
			return true;
		}
		LinkNode* fast = head->next;
		LinkNode* slow = head->next;
		while (fast) {
			
			slow = slow->next;
			if (fast->next) {
				return false;
			}
			fast = fast->next->next;
			if (fast == slow)
				return true;
		}
		return false;
	}
	//判断两个链表相交不相加
	bool ifIntersection(LinkNode* headA, LinkNode* headB) {
		LinkNode* cur = headA;
		for (int i = 0; i < size - 1; ++i) {
			cur = cur->next;
		}
		cur->next = headB->next;
		if (ifCycle(headA)) {
			return true;
		}
		else return false;
	
	}
	//找到相交链表的第一个相交节点
	LinkNode* getIntersectionNode(LinkNode* headA, LinkNode* headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		LinkNode* A = headA;
		LinkNode* B = headB;
		while (A != B) {
			A = A == nullptr ? headB : A->next;
			B = B == nullptr ? headA : B->next;
		}
		return A;
	}

	//合并两个有序链表
	LinkNode* mergeTwoList(LinkNode* headA, LinkNode* headB) {
		LinkNode* dummy = new LinkNode(-1);
		LinkNode* cur = dummy;
		while (headA!=nullptr&&headB!=nullptr)
		{
			if (headA->val >= headB->val) {
				LinkNode* node = new LinkNode(headA->val);
				headA = headA->next;
				cur->next = node;
			}
			else {
				LinkNode* node = new LinkNode(headB->val);
				headB = headB->next;
				cur->next = node;
			}
		}
		cur->next = headA == nullptr ? headB : headA;
		return dummy->next;
	}

	void displayList()const {
		LinkNode* cur = head;
		while (cur) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}

};