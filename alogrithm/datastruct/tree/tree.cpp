#include <iostream>
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode():val(0),left(nullptr),right(nullptr){}
    BinaryTreeNode(int x):val(x),left(nullptr),right(nullptr){}
    BinaryTreeNode(int x,BinaryTreeNode* left,BinaryTreeNode* right):val(0),left(left),right(right){}
    
};

class Tree
{
private:
    BinaryTreeNode *root;

public:
    void preOrder(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        std::cout << root->val << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        std::cout << root->val << std::endl;
        inOrder(root->right);
    }

    void postOrder(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        inOrder(root->right);
        std::cout << root->val << std::endl;
    }
};
