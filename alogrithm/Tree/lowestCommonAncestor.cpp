#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 具体思路：
// （1） 如果当前结点 root 等于 NULL，则直接返回 NULL
// （2） 如果 root 等于 p 或者 q ，那这棵树一定返回 p 或者 q
// （3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 left和 right 表示
// （4） 此时若left为空，那最终结果只要看 right；若 right为空，那最终结果只要看 left，//某一边值为空说明两个节点都在另一边
// （5） 如果 left 和 right 都非空，因为只给了 p 和 q 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先
// （6） 如果 left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）

// 时间复杂度是 O(n)：每个结点最多遍历一次或用主定理，空间复杂度是 O(n)：需要系统栈空间

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        //如果两个值有一个为null 说明两个都在同一边
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        if (left && right)
            return root;
        return nullptr;
    }
};