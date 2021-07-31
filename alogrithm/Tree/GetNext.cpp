// 中序遍历中某个节点的下一个节点

#include <iostream>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr),parent(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr),parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right,TreeNode*parent) : val(x), left(left), right(right),parent(parent) {}
};

TreeNode *GetNext(TreeNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }
    TreeNode *pNext = nullptr;
    //这个节点有右节点
    if (pNode->right != nullptr)
    {
        TreeNode *pRight = pNode->right;
        while (pRight->left != nullptr)
            pRight = pRight->left;

        pNext = pRight;
    }
    //没有右节点,但有父节点
    else if(pNode->parent!=nullptr){
        //获取当前节点
        TreeNode*pCurrent=pNode;
        //获取当前节点的父节点
        TreeNode*pParent=pNode->parent;
        
        while(pParent!=nullptr&&pCurrent==pParent->right){
            //一直往上遍历，直到找到一个是它父节点的左子节点的节点
            pCurrent=pParent;
            pParent=pParent->parent;
        }
        pNext=pParent;
    }
    return  pNext;
}