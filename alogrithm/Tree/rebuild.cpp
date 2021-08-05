// 根据前序遍历和中序遍历求树

//根据中序遍历和后序遍历求树

#include <iostream>
#include <unordered_map>
#include <vector>
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
    std::unordered_map<int, int> index;

public:
    TreeNode *bulidTree_Pre_Inorder(const std::vector<int> &preorder, const std::vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if(preorder_left>preorder_right)return nullptr;

        //前序遍历第一个节点就是根节点
        int preorder_root=preorder_left;

        //在中序遍历定位根节点
        
        int inorder_root=index[preorder[preorder_root]];

        //先把根节点建立起来
        TreeNode*root=new TreeNode(preorder[preorder_root]);
        
        //得到左子树的节点数目
        int size_left_subTree=inorder_root-inorder_left;

        //递归构造左子树
        root->left=bulidTree_Pre_Inorder(preorder,inorder,preorder_left+1,preorder_left+size_left_subTree,inorder_left,inorder_root-1);

        //递归构造右子树
        root->right=bulidTree_Pre_Inorder(preorder,inorder,preorder_left+size_left_subTree+1,preorder_right,inorder_root+1,inorder_right);
        
        return root;
    }
    TreeNode* bulidTree(std::vector<int>&preorder,std::vector<int>&inorder){
        int n=preorder.size();
        //构建哈希映射
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        return bulidTree_Pre_Inorder(preorder,inorder,0,n-1,0,n-1);
    }
};