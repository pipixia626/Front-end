//二叉搜索树
#include <iostream>
struct BSTNode
{
    int key;         //关键字
    BSTNode *left;   //左子节点
    BSTNode *right;  //右子节点
    BSTNode *parent; //父节点
    BSTNode() : key(0), left(nullptr), right(nullptr), parent(nullptr) {}
    BSTNode(int _key) : key(_key), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BSTree
{
public:
    BSTree();
    ~BSTree();

    void preOrder() const;

    void inOrder() const;

    void postOrder() const;

    bool insert(const int _key); //插入

    BSTNode *search(const int key); //查找
    
	BSTNode *IteratorSearch(const int key);  //迭代实现，在二叉树中查找key节点
    //查找节点node的后继节点
    BSTNode *successor(BSTNode *node); //查找"二叉树中数据值大于该节点"的"最小节点"

    //查找节点node的前驱节点
    BSTNode *predecessor(BSTNode *node); //查找"二叉树中数据值小于该节点"的"最大节点

    void remove(const int key);

    void destroy(); //销毁

private:
    BSTNode *root;
    void preOrder(BSTNode *root) const;  //前序二叉树遍历
    void inOrder(BSTNode *root) const;   //中序二叉树遍历
    void postOrder(BSTNode *root) const; //后序二叉树遍历

    BSTNode *search(BSTNode *node,const int key);         //递归实现，在”二叉树node“中查找key节点
    BSTNode *IteratorSearch(BSTNode *node,const int key); //迭代实现，在“二叉树node”中查找key节点

    BSTNode *minimum(BSTNode *root); //查找最小节点：返回tree为根节点的二叉树的最小节点
    BSTNode *maximum(BSTNode *root); //查找最大节点：返回tree为根节点的二叉树的最大节点

    void insert(BSTNode *&root, BSTNode *z); // 将节点(z)插入到二叉树(tree)中

    BSTNode *remove(BSTNode *root, BSTNode *z); // 删除二叉树(tree)中的节点(z)，并返回被删除的节点

    void destroy(BSTNode *&root); //销毁二叉树
};

BSTree::BSTree() : root(nullptr){};

BSTree::~BSTree() { destroy(); }

bool BSTree::insert(const int _key)
{
    BSTNode *node = new BSTNode(_key);
    if (node == nullptr)
        return false;

    insert(root, node);
}

void BSTree::preOrder(BSTNode *root) const
{
    if (root == nullptr)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void BSTree::preOrder() const
{
    preOrder(root);
}
void BSTree::inOrder(BSTNode *root) const
{
    if (root == nullptr)
    {
        preOrder(root->left);
        std::cout << root->key << " ";
        preOrder(root->right);
    }
}

void BSTree::inOrder() const
{
    inOrder(root);
}

void BSTree::postOrder(BSTNode *root) const
{
    if (root == nullptr)
    {
        preOrder(root->left);

        preOrder(root->right);
        std::cout << root->key << " ";
    }
}

void BSTree::postOrder() const
{
    postOrder(root);
}

BSTNode *BSTree::search(BSTNode *node, const int key)
{
    if (node == nullptr || key == node->key)
        return node;

    if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

BSTNode *BSTree::search(const int _key){
    return search(root,_key);
}

BSTNode *BSTree::IteratorSearch(BSTNode *node,const int _key){
    while (node != NULL && _key != node->key)
	{
		if (_key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
   return node;
}

BSTNode *BSTree::IteratorSearch(const int key)
{
	return IteratorSearch(root, key);  //传入根节点和待查找的关键字key
}
BSTNode *BSTree::minimum(BSTNode *root)  //查找最小节点：返回tree为根节点的二叉树的最小节点。
{
	if (root== NULL)
	{
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
 
//查找最大节点：返回tree为根节点的二叉树的最大节点。
BSTNode *BSTree::maximum(BSTNode *root)  
{
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root;
}
//找节点(node)的后继节点，也就是该节点的右子树中的最小节点
BSTNode *BSTree::successor(BSTNode *node){

}
void BSTree::remove(int key)  // 删除二叉树(tree)中的节点(z)，并返回被删除的节点
{
	BSTNode *z, *node;
	z = IteratorSearch(root, key);  //根据给定的key，查找树中是否存在key节点
	if (z != NULL)
	{
		node = remove(root, z);  //传入树根以及待删除的节点(z)
		if (node != NULL)
		{
			delete node;
		}
	}
}

void BSTree::destroy(BSTNode *&tree)  //销毁二叉树
{
	if (tree == NULL)
	{
		return;  //停止函数的执行
	}
	if (tree->left != NULL)
	{
		return destroy(tree->left);
	}
	if (tree->right != NULL)
	{
		return destroy(tree->right);
	}
	delete tree;
	tree = NULL;
}
 
 
void BSTree::destroy()  //销毁二叉树
{
	destroy(root);
}
 
