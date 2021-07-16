_Pragma("once")

#include <iostream>
#include "linklist\linklist.hpp"
    //链表实现栈

    template <typename E>
    class LinkedStack
{
private:
    SlinkedList<E> s;
    int n;

public:
    LinkedStack()
        : s(),
          n(0)
    {
    }
    LinkedStack(const LinkedStack &ls)
        : s(ls.s), n(ls.n)
    {
    }
    LinkedStack &operator=(const LinkedStack &ls)
    {
        if (this == &ls)
        {
            return *this;
        }
        s = ls.s;
        n = ls.n;
        return *this;
    }
    // 若对象s没有移动构造函数，则调用其拷贝构造函数。
    LinkedStack(LinkedStack &&ls)
        : s(std::move(ls.s)), n(ls.n)
    {
    }
    int size() const
    {
        return n;
    }
    bool empty() const
    {
        return (n == 0);
    }
    const E &top() const
    {
        if (empty())
        {
            throw std::logic_error("LinkedStack empty");
        }
        return s.front();
    }
    void push(const E &e)
    {
        ++n;
        s.addFront(e);
    }
    void pop()
    {
        if (empty())
        {
            throw std::logic_error("LinkedStack empty");
        }
        --n;
        s.removeFront();
    }
    void display() const
    {
        s.display();
    }
};