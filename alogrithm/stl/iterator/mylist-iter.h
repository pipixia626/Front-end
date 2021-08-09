#include "mylist.h"
template <class Item>
struct ListIter
{
    Item *ptr;            //保持与容器之间的联系
    ListIter(Item *p = 0) //default ctor
        : ptr(p)
    {
    }
    //不必实现 copy ctor 因为编译器提供的缺省行为已经足够
    //不必实现operator = 因为编译器提供的缺省行为已经足够

    Item &operator*() const { return *ptr; }
    Item *operator->() const(return ptr;)

        //一下两个operator++遵循标准做法

        ListIter &
        operator++()
    {
        ptr = ptr->next();
        return *this;
    }

    ListIter operator++(int)
    {
        ListIter tmp = *this;
        ++*this;
        return tmp;
    }
};
