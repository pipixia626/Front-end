_Pragma("once")

#include <iostream>
//数组实现栈
    enum { DEF_CAPACITY = 100 };

template <typename E>
class ArrayStack
{
private:
    E *s;
    int capacity;
    int t;

public:
    ArrayStack(int cap = DEF_CAPACITY)
        : s(new E[cap]), capacity(cap), t(-1)
    {
    }

    ~ArrayStack()
    {
        if (s != nullptr)
        {
            delete[] s;
        }
    }
    void init(const ArrayStack &a)
    {
        capacity = a.capacity;
        t = a.t;
        s = new E[capacity];
        for (int i = 0; i < t; ++i)
        {
            s[i] = a.s[i];
        }
    }
    ArrayStack(const ArrayStack &a)
    {
        init(a);
    }

    ArrayStack &operator=(const ArrayStack &a)
    {
        if (this == &a)
        {
            return *this;
        }
        if (s != nullptr)
        {
            delete[] s;
        }

        init(a);
        return *this;
    }

    ArrayStack(ArrayStack &&a)
    {
        capacity = a.capacity;
        t = a.t;
        s = a.s;
        a.s = nullptr;
    }
    int size() const
    {
        return (t + 1);
    }
    bool empty() const
    {
        return (t < 0);
    }

    const E &top() const
    {
        if (empty())
        {
            throw std::logic_error("ArrayStack empty");
        }
        return s[t];
    }

    void push(const E &e)
    {
        if (size() == capacity)
        {
            throw std::logic_error("ArraStack full");
        }
        s[++t] = e;
    }

    void pop()
    {
        if (empty())
        {
            throw std::logic_error("ArrayStack empty");
        }
        --t;
    }

    void display() const
    {
        for (int i = 0; i <= t; ++i)
        {
            std::cout << s[i] << ",";
        }
        std::cout << std::endl;
    }
};