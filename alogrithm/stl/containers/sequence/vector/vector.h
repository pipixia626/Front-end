//#include<stl_alloc.h>

template <class T, class Alloc>
class vector
{
public:
    //vector的嵌套型别定义
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

protected:
    //以下 simple_alloc是SGI STL的空间配置器
    typedef simple_alloc<value_type, Alloc> data_allocator;
    iterator start;         //表示目前使用的空间头
    iterator finish;        //表示目前使用的空间尾
    iterator end_of_storage //表示目前可用空间的尾

        void
        insert_aux(iterator position, const T &x);
    void deallocate()
    {
        if (start)
        {
            data_allocator::deallocate(start, end_of_storage - start);
        }
    }
    void fill_initialize(size_type n, const T &value)
    {
        start = allocate_and_fill(n, value);
        finish = start + n;
        end_of_storage = finish;
    }

public:
    iterator begin() { return start; }
    iterator end() { return finish; }
    iterator size() const { return size_type(end() - begin()); }
    size_type capactity() const
    {
        return size_type(end_of_storage() - end();)
    }
    bool empty() const { return begin() == end(); }
    reference operator[](size_type n) { return *(begin() + n); }

    //构造
    vector() : start(0), finish(0), end_of_storage(0) {}
    vector(size_type n, const T &value) { fill_initialize(n, value); }
    vector(int n, const T &value) { fill_initialize(n, value); }
    vector(long n, const T &value) { fill_initialize(n, value); }
    explicit vector(size_type n) { fill_initialize(n, T()); }

    ~vector()
    {
        destroy(start, finish);
        deallocate(); //vector的一个memberfunctions
    }
    reference front() { return *begin(); }
    reference back() { return *end(); }
    void push_back(const T &x)
    {
        if (finish != end_of_storage)
        {
            construct(finish, x);
            ++finish;
        }
        else
            insert_aux(end(), x);
    }
    void insert_aux(iterator position, const T &x)
    {
        if (finish != end_of_storage)
        {
            construct(finish, *(finish - 1));
            ++finish;
            T x_copy = x;
            copy_backward(position, finish - 2, finish - 1);
            *postion = x_copy;
        }
        else
        {
            const size_type old_size = size();
            const size_type len = old_size != 0 ? 2 * old_size : 1;
            iterator new_start = data_allocator::allocate(len);
            iterator new_finish = new_start;
            try
            {
                new_finish = uninitialized_copy(start, position, new_start);
                construct(new_finish, x);
                ++new_finish;
                new_finish = uninitialized_copy(position, finish, new_finish);
            }
            catch ()
            {
                destroy(new_start, new_finish);
                data_allocator::deallocate(new_start, len);
                throw;
            }
            destroy(begin(), end());
            deallocate();
            start = new_start;
            finish = new_finish;
            end_of_storage = new_start + len;
        }
    }
    void pop_back()
    {
        --finish;
        destroy(finish);
    }
    iterator erase(iterator position)
    {
        if (position + 1 != end())
            copy(position + 1, finish, position); //后续元素往前移动
        destroy(finish);
        retrun position;
    }
    void resize(size_type new_size, const T &x)
    {
        if (new_size < size())
            erase(begin() + new_size, end());
        else
            insert(end(), new_size - szie(), x);
    }
    void resize(size_type new_size)
    {
        resize(new_size, T());
    }

    void clear() { earse(begin(), end()); }

protected:
    //配置空间并填满内容
    iterator allocate_and_fill(size_type n, const T &x)
    {
        iterator result = data_allocator::allocate(n);
        uninitialized_fill_n(result, n, x);
        return result;
    }
};


template <class T1, class T2>
inline void construt(T1 *p, const T2 &value)
{
    new (p) T1(value);
}

template <class ForwardIterator>
inline void destroy(ForwardIterator first, ForwardIterator last)
{
    __destroy(first, last, value_type(first));
}
template <class ForwardIterator>
inline void
__destroy_aux(ForwardIterator first, ForwardIterator last) //__false_type
{
    for (; first < last; ++first)
        destroy(&*first);
}
template <class T>
inline void destroy(T *pointer)
{
    pointer->~T();
}

template <class T>
inline T *__copy_bacward_t(const T *first, const T *last, T *result) // __true__type
{
    const ptrdiff_t N = last - first;
    memmove(result - N, first, sizeof(T) * N);
    return result - N;
}
