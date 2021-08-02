#include <iostream>
#include <stack>
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : val(0), left(left), right(right) {}
};

class Tree
{
private:
    BinaryTreeNode *root;

public:
    void preOrder_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        std::cout << root->val << std::endl;
        preOrder_recursion(root->left);
        preOrder_recursion(root->right);
    }

    void inOrder_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder_recursion(root->left);
        std::cout << root->val << std::endl;
        inOrder_recursion(root->right);
    }

    void postOrder_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        inOrder_recursion(root->left);
        inOrder_recursion(root->right);
        std::cout << root->val << std::endl;
    }

    void preOrder_no_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        std::stack<BinaryTreeNode *> stackTree;
        stackTree.push(root);
        while (!stackTree.empty())
        {
            auto node = stackTree.top();
            stackTree.pop();
            std::cout << node->val << std::endl;
            if (node->right != nullptr)
                stackTree.push(node->right);
            if (node->left != nullptr)
                stackTree.push(node->left);
        }
    }

    void inOrder_no_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        auto cur = root;
        std::stack<BinaryTreeNode *> stackTree;
        while (!stackTree.empty() || cur != nullptr)
        {
            while (cur != nullptr)
            {
                stackTree.push(cur);
                cur = cur->left;
            }
            auto node = stackTree.top();
            stackTree.pop();
            std::cout << node->val << std::endl;

            if (node->right != nullptr)
            {
                cur = node->right;
            }
        }
    }

    void postOrder_no_recursion(BinaryTreeNode *root)
    {
        if (root == nullptr)
            return;
        std::stack<BinaryTreeNode *> inTree;
        std::stack<BinaryTreeNode *> resTree;
        inTree.push(root);
        while (!inTree.empty())
        {
            auto node = inTree.top();
            inTree.pop();
            resTree.push(node);
            if (node->left != nullptr)
            {
                inTree.push(node->left);
            }
            if (node->right != nullptr)
            {
                inTree.push(node->right);
            }
        }
        while (!resTree.empty())
        {
            auto it = resTree.top();
            resTree.pop();
            std::cout << it->val << std::endl;
        }
    }
    //获取长度
    int depth(BinaryTreeNode *root)
    {
        int dep1 = 0, dep2 = 0;
        if (root == nullptr)
            return;
        else
        {
            dep1 = depth(root->left);
            dep2 = depth(root->right);
            if (dep1 > dep2)
                return dep1 + 1;
            else
                return dep2 + 1;
        }
    }
};
