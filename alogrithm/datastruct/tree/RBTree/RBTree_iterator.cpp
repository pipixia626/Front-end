typedef bool __rb_tree_color_type;
const __rb_tree_color_type __rb_tree_red = false;  //红色为
const __rb_tree_color_type __rb_tree_black = true; //红色为

//struct __rb_tree_node_base ->struct __rb_tree_node
struct __rb_tree_node_base
{
    typedef __rb_tree_color_type color_type;
    typedef __rb_tree_node_base *base_ptr;

    color_type color; //
    base_ptr parent;
    base_ptr left;
    base_ptr right;

    static base_ptr minimum(base_ptr x)
    {
        while (x->left != nullptr)
        {
            x = x->left;
        }
        return x;
    }
    static base_ptr maximum(base_ptr x)
    {
        while (x->right != nullptr)
        {
            x = x->right;
        }
    }
};
template <class value>
struct __rb_tree_node : public __rb_tree_node_base
{
    typedef __rb_tree_node<value> *link_type;
    value value_field; //节点值
};

//基层迭代器
struct __rb_tree_base_iterator
{
    typedef __rb_tree_node_base::base_ptr base_ptr;
    //typedef bidirectional_iterator_tag iterator_category;
    //typedef ptrdiff_t difference_type;
    base_ptr node; //用来和容器之间产生一个连结关系
    void increment()
    {
        //如果有右子节点

        if (node->right != nullptr)
        {
            //往右走
            node = node->right;
            //找到最左节点即是解答
            while (node->left != nullptr)
            {
                node = node->left;
            }
        }
        //没有右子节点
        else
        {
            base_ptr y = node->parent; //找到父节点
            //如果现行节点是一个右子节点
            while (node == y->right)
            {
                //一直上溯，直到不为右子节点为止
                node = y;
                y = y->parent;
            }
            //若此时的右子节点不等于此时的父节点->父节点即为解答
            //欲寻找根节点的下一个节点，而恰巧根节点的无右子节点
            //否则此时的node为解答
            if (node->right != y)
            {
                node = y;
            }
        }
    }

    void decrement()
    {
    }
};

//正规迭代器
template <class Value, class Ref, class Ptr>
struct __rb_tree_iterator : public __rb_tree_base_iterator
{
    typedef Value value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef __rb_tree_iterator<Value, Value &, Value *> iterator;
    typedef __rb_tree_iterator<Value, const Value &, const Value *> const_iterator;
    typedef __rb_tree_iterator<Value, Ref, Ptr> self;
    typedef __rb_tree_node<Value> *link_type;

    __rb_tree_iterator() {}
    __rb_tree_iterator(link_type x) { node = x; }
    __rb_tree_iterator(const iterator &it) { node = it.node; }

    reference operator*() const { retrun link_type(node)->value_field; }
#ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator->() const
    {
        return &(operator*());
    }
#endif /*__SGI_STL_NO_ARROW_OPRATOR*/

    self &operator++()
    {
        increment();
        return *this;
    }
    self operator++(int)
    {
        self tmp = *this;
        tmp = decrement();
        return tmp;
    }
    //同理decrement
    //...
};