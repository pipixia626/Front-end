#include <iostream>

template <typename E>
class SlinkedList;

template <typename>
class SNode
{
private:
    E elem;
    SNode<E> *next;
    friend SLinkedList<E>
};

template <typename E>

class SlinkedList
{
private:
    SNode<E> *header;

public:
    SlinkedList()
    {
        header = new SNode<E>;
        header->next = nullptr;
    }
    ~SlinkedList()
    {
        while (!empty())
        {
            removeFront();
        }
        delete header;
    }

    void init(conts SlinkedList &s)
    {

        header=new SNode<E>;
        header->next=nullptr;
        SNode<E>*p=s.header->next;
    }

    bool empty() const
    {
        return (nullptr == header->next);
    }
    //返回最前面的元素
    const E &front() const
    {
        if (empty())
        {
            throw std::logic_error("SlinkedList empty");
        }
        return header->next->elem;
    }
    //添加节点
    void addFront(const E &e)
    {
        SNode<E> *v = new SNode<E>;
        v->elem = e;
        v->next = header->next;
        header->next = v;
    }
    //删除尾结点
    void removeFront()
    {
        if (empty())
        {
            return;
        }
        SNode<E> *old = header->next;
        header->next = old->next;
        delete old;
    }
    //反转链表
    void reserver()
    {
        if (empty())
        {
            return;
        }
        SNode<E> *prev = header->next;
        SNode<E> *cur = nullptr;
        SNode<E> *pNext = nullptr;
        if (prev->next = nullptr)
        {
            return;
        }
        else
        {
            cur = prev->next;
        }
        while (cur != nullptr)
        {
            pNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = pNext
        }
        header->next->next = nullptr;
        header->next = prev;
    }

    void display() const
    {
        if (empty())
        {
            return;
        }
        SNode<E>*p=header->next;
        while (p!=nullptr)
        {
            std::cou<<p->elem<<",";
            p=p->next;
        }
        std::cout<<std::endl;
        
    }
};
