template <class T, class Alloc>
class slist
{
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdifft_t difference_type;

    typedef __slist_iterator<T, T &, T *> iterator;
    typedef __slist_iterator<T, const T &, const T *> const_iterator;

private:
    typedef __slist_node<T> list_node;
    typedef __slist_node_base list_node_base;
    typedef __slist_iterator_base iterator_base;
    typedef simple_alloc<list_node, Alloc> list_node_allocator;

    static list_node *create_node(const value_type &x)
    {
        list_node *node = list_node_allocator::allocate(); //配置空间
        __STL_TRY
        {
            construct(&node->data, x);
            node->next = 0;
        }
        __STL_UNWIND(list_node_allocator::deallocate(node));
        return node;
    }

    static void destroy_node(list_node *node)
    {
        destroy(&node->data);                  //析构
        list_node_allocator::deallocate(node); //释放空间
    }

private:
    list_node_base head; //头部，不是指针是实物
public:
    slist() { head.next = 0; }
    ~slist() { clear(); }

public:
    iterator begin() { return iterator((list_node *)head->next); }
    iterator end() { return iterator(0); }
    size_type size() const { return __slist__size(head->next); }
    bool empty() const { return head.next == 0; }

    //两个slist交换，只要交换head就行
    void swap(slist &L)
    {
        list_node_base *tmp = head.next;
        head.next = L.head.next;
        L.head.next = tmp;
    }
public:
reference front();
void push_front();
//没有push_back

void pop_front();
void insert(iterator iter,value_type)//插入到value_type 前面
};