//树的右视图
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
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

private:
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};

        //bfs层序遍历 将每层最后一个加入结果数组
        std::vector<int> res;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int counts = queue.size();
            for (int i = 0; i < counts; ++i)
            {
                auto node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);

                if(i==counts-1)res.push_back(node->val_);
            }
        }
        return res;
    }
};