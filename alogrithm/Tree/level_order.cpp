//递归和迭代进行层序遍历
#include <vector>
#include <iostream>
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

class Tree
{
private:
    TreeNode *root;
    std::vector<std::vector<int>> res;

public:
    std::vector<std::vector<int>> levelOrder_iteration(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            std::vector<int> temp;
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (temp.size() > 0)
                res.push_back(temp);
        }
        return res;
    }

    void level(TreeNode *root, int lev)
    {
        if (!root || lev == 0)
            return;
         if (lev >= res.size()) {
            res.push_back(std::vector<int>());
        }
        res[lev].push_back(root -> val);
        level(root -> left, lev + 1);
        level(root -> right, lev + 1);
    }

    std::vector<std::vector<int>> levelOrder_cursion(TreeNode *root)
    {

        level(root, 0);
        return res;
    }
};