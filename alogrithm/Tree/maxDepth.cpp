//给定一个二叉树，找出其最大深度

//左子树和右子树的最大深度 l 和 r，那么该二叉树的最大深度即为
//max(l,r) + 1
#include <iostream>
#include <algorithm>
#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    //深度优先遍历DFS
    int maxDepth_DFS(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return std::max(maxDepth_DFS(root->left), maxDepth_DFS(root->right)) + 1;
    }
    //广度优先遍历BFS(层序遍历)
    int maxDepth_BFS(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        std::queue<TreeNode *> queueTree;
        queueTree.push(root);
        int res = 0;
        while (!queueTree.empty())
        {
            int size = queueTree.size();
            while (size--)
            {
                TreeNode *node = queueTree.front();
                queueTree.pop();
                if (node->left)
                    queueTree.push(node->left);
                if (node->right)
                    queueTree.push(node->right);
            }
            res++;
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(7);
    root->left = left;
    root->right = right;

    TreeNode *left_ = new TreeNode(3);
    TreeNode *right_ = new TreeNode(4);
    TreeNode *left__ = new TreeNode(5);
    TreeNode *right__ = new TreeNode(6);
    left->left = left_;
    left->right = right_;
    right_->left = left__;
    right_->right = right__;

    Solution s;
    std::cout << s.maxDepth_DFS(root) << std::endl;
    std::cout<<s.maxDepth_BFS(root)<<std::endl;
}