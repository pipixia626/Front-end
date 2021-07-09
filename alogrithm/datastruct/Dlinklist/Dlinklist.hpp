_Pragma("once")
#include <iostream>

    template <typename E>
    class DlinkedList;

template <typename E>
class DNode
{
private:
    E elem;
    DNode<E> *prev;
    DNode<E> *next;
    friend DlinkedList<E>
};

template <typename E>
class DlinkedList
{
private:
    DNode<E> *header;
    DNode<E> *tailer;

protected:
    //insert new node before v
    void add(DNode<E> *v, const E &e)
    {
        DNode<E>* u=new DNode<E>;
        u->elem=e;
        
        //新节点的下一个节点是v
        u->next=v;
        //新节点的前一个节点是v节点的前一个节点
        u->prev=v->prev;
        //v的前一个节点的下一个节点是新节点
     
        v->prev->next=u;
        //v的前一个节点是u
        v->prev=u;
    }
    void remove(DNode<E> *v)
    {   
        v->prev->next=v->next;
        v->next->prev=v->prev;
        delete v;
    }

public:
    DlinkedList()
    {
        header = new DNode<E>;
        tailer = new DNode<E>;
        header->next = tailer;
        tailer->next = header;
    }

    ~DlinkedList()
    {
        while (/* condition */)
        {
            /* code */
        }
    }

    DlinkedList(DlinkedList &&d)
    {
        header = new DNode<E>;
        tailer = new DNode<E>;

        header->next = d.header->next;
        d.header->next->prev = header;
        tailer->prev = d.tailer->prev;
        d.tailer->prev->next = tailer;

        d.header->next = d.tailer;
        d.tailer->prev = d.header;
    }
    bool empty() const
    {
        return (header->next == tailer);
    }

    const E &front() const
    {
        if (empty())
        {
            throw std::logic_error("DLinkedList empty");
        }
        return header->next->elem;
    }

    const E &back() const
    {
        if (empty())
        { 
            throw std::logic_error("DLinkedList empty");
        }
        return tailer->prev->elem;
    }
    void addFront(const E& e){
        add(header->next,e);
    }

    void addBack(const E&e){
        add(tailer,e);
    }
    void removeFront(){

    }
    void 
};
