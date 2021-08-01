// 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

// 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的

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
    bool isSameTree_DFS(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (!p || !q)
            return false;
        else if (q->val_ != p->val_)
            return false;
        else
        {
            return isSameTree_DFS(p->left, q->left) && isSameTree_DFS(p->right, q->right);
        }
    }
    bool isSameTree_BFS(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;

        if (!p || !q)
            return false;

        std::queue<TreeNode *> queue1, queue2;
        queue1.push(q);
        queue2.push(p);
        while (!queue1.empty() && !queue2.empty())
        {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            if (node1->val_ != node2->val_)
                return false;
            //左节点和右节点
            auto left1 = node1->left, right1 = node1->right;
            auto left2 = node2->left, right2 = node2->right;

            if (!left1 || !left2)
                return false;
            if (!right1 || !right2)
                return false;

            if (left1 != nullptr)
            {
                queue1.push(left1);
            }
            if (right1 != nullptr)
            {
                queue1.push(right1);
            }
            if (left2 != nullptr)
            {
                queue2.push(left2);
            }
            if (right2 != nullptr)
            {
                queue2.push(right2);
            }
        }
        return queue1.empty() && queue2.empty();
    }
};