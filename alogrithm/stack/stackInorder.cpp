//用栈实现中序遍历

#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    void stackInorder(TreeNode *root)
    {
        if (!root)
            return;
        std::stack<TreeNode *> stack_Tree;
        while (!stack_Tree.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                stack_Tree.push(root);
                root = root->left; //先將所有子节点入栈

            }
            else{
                root=stack_Tree.top();
                std::cout<<root->val<<std::endl;
                stack_Tree.pop();
                root=root->right;
            }
        }
    }
};