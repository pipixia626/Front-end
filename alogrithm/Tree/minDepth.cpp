//给定一个二叉树，找出其最小深度

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

class solution
{
public:
    int minDepth_DFS(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int min_depth = INT_MAX;
        if (root->left != nullptr)
        {
            min_depth = std::min(min_depth, minDepth_DFS(root->left));
        }
        if (root->right != nullptr)
        {
            min_depth = std::min(min_depth, minDepth_DFS(root->right));
        }
        return min_depth + 1;
    }
    int minDepth_BFS(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        std::queue<std::pair<TreeNode *, int>> queueTree;
        queueTree.emplace(root, 1);
        while (!queueTree.empty())
        {
            TreeNode *node = queueTree.front().first;
            int depth = queueTree.front().second;
            queueTree.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            if (node->left != nullptr)
            {
                queueTree.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr)
            {
                queueTree.emplace(node->right, depth + 1);
            }
        }
        return 0;
    }
};