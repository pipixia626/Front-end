_Pragma("once")

#include <iostream>

    template <typename E>
    class CLinkedList;

template <typename E>
class CNode
{
private:
    E elem;
    CNode<E> *next;
    friend CLinkedList<E>;
};

template <typename E>
class CLinkedList
{
private:
    CNode<E> *cursor;

public:
    CLinkedList()
        : cursor(nullptr)
    {
    }
    ~CLinkedList()
    {
        while (!empty())
        {
            remove();
        }
    }

    void init(const CLinkedList &c)
    {
        cursor = nullptr;
        if (c.empty())
        {
            return;
        }
        cursor = new CNode<E>;
        cursor->elem = c.cursor->elem;
        cursor->next = cursor;

        CNode<E> *p = c.cursor->next;
        CNode<E> *q = c.cursor;
        while (q != c.cursor)
        {
            CNode<E> *temp = new CNode<E>;
            temp->elem = p->elem;
            temp->next = cursor;
            q->next = tm;
            p = p->next;
            q = q->next;
        }
    }
    CLinkedList(const CLinkedList &c)
    {
        init(c);
    }

    CLinkedList &operator=(const CLinkedList &c)
    {
        if (this == &c)
        {
            return *this;
        }
        while (!empty())
        {
            remove();
        }
        init(c);
        return *this;
    }
    CLinkedList(CLinkedList &&c)
    {
        cursor = c.cursor;
        c.cursor = nullptr;
    }
    bool empty() const
    {
        return (nullptr == cursor);
    }
    const E &front() const // elem following cursor
    {
        if (empty())
        {
            throw std::logic_error("CLinkedList empty");
        }
        return cursor->next->elem;
    }

    const E &back() const // elem at cursor
    {
        if (empty())
        {
            throw std::logic_error("CLinkedList empty");
        }
        return cursor->elem;
    }
    //advance cursor
    void advance()
    {
        if (empty())
        {
            return;
        }
        cursor = cursor->next;
    }
    //add node after cursor
    void add(const E &e)
    {
        CNode<E> *v = new CNode<E>;
        v->elem = e;
        if (empty())
        {
            v->next = v;
            cursor = v;
        }
        else
        {
            v->next = cursor->next;
            cursor->next = v;
        }
    }
    //remove node after cursor
    void remove()
    {
        if (empty())
        {
            throw std::logic_error("CLinkedList empty");
        }
        CNode<E> *old = cursor->next;
        if (old == cursor)
        {
            cursor = nullptr;
        }
        else
        {
            cursor->next = old->next;
        }
        delete old;
    }
};
