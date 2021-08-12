// RB-Tree的数据结构
#include "RBTree_iterator.h"
template <class Key, class Value, class KeyOfValue, class Compare, class Alloc>
class rb_tree
{
protected:
    typedef void *void_pointer;
    typedef __rb_tree_node_base *base_ptr;
    typedef __rb_tree_color_type color_type;
    typedef simple_alloc<rb_tree_node, Alloc> rb_tree_node_allocator;

public:
    // 注意，没有定义iterator（定义在后面)

    typedef Key key_type;
    typedef Value Value_type;
    typedef Value_type *pointer;
    typedef const Value_type *const_pointer;
    typedef Value_type &reference;
    typedef const Value_type &const_reference;
    typedef __rb_tree_node *link_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

protected:
    link_type get_node(return __rb_tree_node_allocator::allocate();)
        link_type put_node(return __rb_tree_node_allocator::dellocate();)

            link_type create_node(const Value_type &x)
    {
        link_type tmp = get_node();

        __STL_TRY
        {
            constuct(&tmp->value_field, x);
        }
        __STL_UNWIND(put_node(tmp);)
        return tmp;
    }
    link_type clone_node(link_type x)
    {
        link_type tmp = create_node(x->value_field);
        tmp->left - 0;
        tmp->right = 0;
        tmp->color = x->color;
        return tmp;
    }
    void destroy_node(link_type p)
    {
        destroy(&p->value - field); //析构内容
        put_node(p);                //释放内存
    }

protected:
    //只以三笔数据表现
    size_type node_count; //追踪记录树的大小(节点数量)
    link_type header;     //一个小技巧
    Compare key_compare;  //节点间的键值大小比较准则，应该会是个function object

    //三个函数用来取得header的成员
    link_type &root() const { return (link_type &)header->parent; }
    link_type &leftmost() const { return (link_type &)header->left; }
    link_type &rightmost() const { return (link_type &)header->right; }

    //六个static获取节点x的成员
    static link_type &left(link_type x) { return (link_type &)x->left; }
    static link_type &right(link_type x) { return (link_type &)x->right; }
    static link_type &parent(link_type x) { return (link_type &)x->parent; }
    static link_type &value(link_type x) { return (link_type &)x->value_field; }
    static link_type &key(link_type x) { return (link_type &)x->key; }
    static link_type &color(link_type x) { return (color_type &)x->color; }

    //也是六个static获取节点x的成员，只不过参数变成了base_ptr x

    //...

    //求得极大值和极小值
    static link_type minimum(link_type x) { return __rb_tree_node_base::minimum(x); }
    static link_type maximum(link_type x) { return __rb_tree_node_base::maximum(x); }

public:
    typedef __rb_tree_base_iterator<Value_type, reference, pointer> iterator;

private:
    iterator __insert(base_ptr x, base_ptr y, const Value_type &v);
    link_type __copy(link_type x, link_type p);
    void erase(link_type x);
    void init()
    {
        header = get_node();
        color(header) = __rb_tree_red;
        root() = 0;
        leftmost() = header;
        rightmost() = header;
    }
public:
//构造和析构

public:
Compare key_compare()const {return key_compare;}
iterator begin(){return leftmost;}
iterator end(){return header;}//RB树的终点为header所指处
bool empty()const {return node_count==0;}
size_type size()const{return node_count;}
size_type max_size()const{return size_type(-1);}


public:
   //将x插入到RB-tree(保持节点独一无二)
   pair<iterator,bool> insert_unique(const Value_type& x);
   //将x插入到RB-tree(允许节点重复)
   interator insert_equal(const Value_type& x);
};
