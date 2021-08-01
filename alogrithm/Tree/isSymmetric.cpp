//判断一棵树是否为镜像对称的

//例如二叉树 [1,2,2,3,4,4,3] 是对称的

#include <iostream>
#include<queue>
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
    bool isSymmetric(TreeNode*root){
        return check_recursion(root,root);
    }
    //递归
    bool check_recursion(TreeNode* root_left,TreeNode*root_right){
        if(!root_left&&!root_right)return true;
        if(!root_left||!root_right)return false;
        return root_left->val_==root_right->val_&&check_recursion(root_left->left,root_right->right)&&check_recursion(root_left->right,root_right->left);
    }
    //迭代
    bool check_iteration(TreeNode*root_left,TreeNode*root_right){
        std::queue<TreeNode*>queueTree;
        queueTree.push(root_left);
        queueTree.push(root_right);
        while (queueTree.empty())
        {
            root_left=queueTree.front();queueTree.pop();
            root_right=queueTree.front();queueTree.pop();
            if(!root_left&&!root_right)continue;
            if((!root_left||!root_right)||(root_left->val_!=root_right->val_))return false;

            queueTree.push(root_left->left);
            queueTree.push(root_right->right);

            queueTree.push(root_left->right);
            queueTree.push(root_right->left);
        }
        return true;
        
    }
};
