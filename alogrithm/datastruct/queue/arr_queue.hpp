_Pragma("once")

#include <iostream>

    //循环数组实现的单向队列

    enum { DEF_CAPACITY = 100 };

template <typename E>
class CArrayQueue
{
private:
    E *array;
    int capacity;
    int front;
    int tailer;

public:
    CArrayQueue(int cap = DEF_CAPACITY)
        : array(new E[cap + 1]), capacity(cap + 1), front(0), tailer(0)
    {
    }
    ~CArrayQueue()
    {
        if (array != nullptr)
        {
            delete[] array;
        }
    }
    void init(const CArrayQueue &ca)
    {
        capacity = ca.capacity;
        front = ca.front;
        tailer = ca.tailer;
        array = new E[capacity];
        int tmp = f;
        while (tmp != r)
        {
            array[tmp] = ca.array[tmp];
            tmp = ((tmp + 1) % capacity);
        }
    }
    CArrayQueue(const CArrayQueue &ca)
    {
        init(ca);
    }
    CArrayQueue &operator=(const CArrayQueue &ca)
    {
        if (this == &ca)
        {
            return *this;
        }
        if (array != nullptr)
        {
            delete[] array;
        }
        init(ca);
        return *this;
    }
    CArrayQueue(CArrayQueue &&ca)
    {
        capacity = ca.capacity;
        f = ca.f;
        r = ca.r;
        array = ca.array;
        ca.array = nullptr;
    }

    int size() const
    {
        if (nullptr == array)
        {
            return 0;
        }
        return ((r - f + capacity) % capacity);
    }

    bool empty() const
    {
        return (0 == size());
    }

    bool full() const
    {
        return (((r + 1) % capacity) == f);
    }

    const E &front() const
    {
        if (empty())
        {
            throw std::logic_error("CArrayQueue empty");
        }
        return array[f];
    }

    const E &back() const
    {
        if (empty())
        {
            throw std::logic_error("CArrayQueue empty");
        }
        return array[(r - 1 + capacity) % capacity];
    }

    void dequeue()
    {
        if (empty())
        {
            throw std::logic_error("CArrayQueue empty");
        }
        f = ((f + 1) % capacity);
    }

    void enqueue(const E &e)
    {
        if (full())
        {
            throw std::logic_error("CArrayQueue full");
        }
        array[r] = e;
        r = ((r + 1) % capacity);
    }

    void display() const
    {
        if (empty())
        {
            return;
        }
        int tmp = f;
        while (tmp != r)
        {
            std::cout << array[tmp] << ",";
            tmp = ((tmp + 1) % capacity);
        }
        std::cout << std::endl;
    }
};