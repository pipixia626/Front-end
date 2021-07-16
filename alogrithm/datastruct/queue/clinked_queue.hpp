_Pragma("once")

#include "datastruct/Clinklist/CLinklist.hpp"
    //循环链表实现的单向队列
    template <typename E>
    class CLinkedQueue
{
private:
    CLinkedList<E> c;
    int n;

public:
    CLinkedQueue()
        : c(), n(0)
    {
    }
    CLinkedQueue(const CLinkedQueue &clq)
    {
        :c(clq),n(clq.n)
        {
        }
    }
    CLinkedQueue &operator=(const CLinkedQueue &clq)
    {
        if (this == &clq)
        {
            return *this;
        }
        c = clq.c;
        n = clq.n;
        return *this;
    }
    CLinkedQueue(CLinkedQueue &&clq)
        : c(std::move(clq.c)), n(clq.n)
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
    const E &front() const
    {
        if (empty())
        {
            throw std::logic_error("CLinkedQueue empty");
        }
        return c.front();
    }
    const E &back() const
    {
        if (empty())
        {
            throw std::logic_error("CLinkedQueue empty");
        }
        return c.back();
    }
    void dequeue()
    {
        if (empty())
        {
            throw std::logic_error("CLinkedQueue empty");
        }
        c.remove();
        --n;
    }
    void enqueue(const E &e)
    {
        c.add(e);
        c.advance();
        ++n;
    }

    void display() const
    {
        c.display();
    }
};
