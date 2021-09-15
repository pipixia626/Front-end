#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(nullptr),right(nullptr){}
	TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};
class Solution {

public:
	TreeNode* buildTree_pre_inorder(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())return nullptr;
		for (int i = 0; i < inorder.size(); ++i) {
			index[inorder[i]] = i;
		}
		return conStructTree_pre_inorder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* conStructTree_pre_inorder(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		//判空操作
		if (preorder_left > preorder_right)return nullptr;
		//获取头节点
		int preorder_root = preorder_left;
		//在中序遍历中找头节点
		int inorder_root = index[preorder[preorder_root]];

		//构造头节点
		TreeNode* root = new TreeNode(preorder[inorder_root]);

		//获取左子树的数量
		int size_subTree = inorder_root - inorder_left;
		//递归构造左节点

		root->left = conStructTree_pre_inorder(preorder, inorder, preorder_left + 1, preorder_left + size_subTree, inorder_left, inorder_root - 1);


		root->right = conStructTree_pre_inorder(preorder, inorder, preorder_left + size_subTree + 1, preorder_right, inorder_root + 1, inorder_right);
		//

		return root;

	}

	TreeNode* buildTree_post_inorder(vector<int>& postorder, vector<int>& inorder) {
		if (postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size())return nullptr;
		for (int i = 0; i < inorder.size(); ++i) {
			index[inorder[i]] = i;
		}
		return conStructTree_post_inorder(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* conStructTree_post_inorder(vector<int>& postorder, vector<int>& inorder, int postorder_left, int postorder_right, int inorder_left, int inorder_right) {
		if (postorder_left > postorder_right)return nullptr;

		//获取头节点
		int postorder_root = postorder_right;
		//根据头节点找到中序遍历对应的头节点
		int inorder_root = index[postorder[postorder_root]];

		//建立头节点
		TreeNode* root = new TreeNode(postorder[postorder_root]);

		//获取右子树的数量
		int size_subTree = inorder_right- inorder_root;
		//构造右子树
		root->right = conStructTree_post_inorder(postorder, inorder, postorder_right-size_subTree, postorder_right-1, inorder_root + 1, inorder_right);

		//构造左子树
		root->left = conStructTree_post_inorder(postorder, inorder, postorder_left, postorder_right- size_subTree-1, inorder_left, inorder_root - 1);

		return root;
	}
private:
	unordered_map<int, int>index;

};
int main() {
	vector<int>preoreder{ 3,9,20,15,7 };
	vector<int>inorder{ 9,3,15,20,7 };
	vector<int>postorder{ 9,15,7,20,3 };
	Solution solution;
	TreeNode* res = solution.buildTree_pre_inorder(preoreder, inorder);
	TreeNode* newRes = solution.buildTree_post_inorder(postorder, inorder);
	cout << newRes->val;
}