//根据前序遍历和中序遍历重建二叉树
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
// preorder:[3,9,20,15,7] 5
// inorder:[9,3,15,20,7] 5

TreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
    {
        return nullptr;
    }
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

TreeNode *ConstructCore(
    int *startPreorder, int *endPreorder,
    int *startInorder, int *endInorder)
{
    //前序遍历序列的第一个数字是根节点的值

    int rootValue = startPreorder[0];
    TreeNode *root = new TreeNode();
    root->val = rootValue;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw ::std::exception("Invalid input.");
    }

    //在中序遍历序列中找到根节点的值

    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }
   
    if (rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw ::std::exception("Invalid input.");
    }

    int leftLength = rootInorder - startInorder;
    int *leftPreorderENd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        //构建左子树
        root->left = ConstructCore(startPreorder + 1, leftPreorderENd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        //构建右子树
        root->right = ConstructCore(leftPreorderENd + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;
}