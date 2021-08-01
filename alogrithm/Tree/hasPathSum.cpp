// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum
//  ，判断该树中是否存在 根节点到叶子节点 的路径，
//  这条路径上所有节点值相加等于目标和 targetSum

#include <iostream>
#include <queue>
struct TreeNode
{
    int val_;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val_(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val_(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    bool hasPathSum_recursion(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val_;

        return hasPathSum_recursion(root->left, targetSum - root->val_) || hasPathSum_recursion(root->right, targetSum - root->val_);
    }

    bool hasPathSum_iteration(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        std::queue<TreeNode *> queueTree;
        queueTree.push(root);

        std::queue<int> que_val;
        que_val.push(root->val_);

        while (!queueTree.empty())
        {
            TreeNode *cur = queueTree.front();
            int temp = que_val.front();
            queueTree.pop();
            que_val.pop();
            if (cur->left == nullptr && cur->right == nullptr)
            {
                if (temp == targetSum)
                    return true;

                continue;
            }
            if(cur->left!=nullptr){
                  queueTree.push(cur->left);
                  que_val.push(cur->left->val_+temp);
            }
            if(cur->right!=nullptr){
                queueTree.push(cur->right);
                que_val.push(cur->right->val_+temp);
            }
        }
        return false;
    }
};
