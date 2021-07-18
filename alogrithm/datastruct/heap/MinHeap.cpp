#include <iostream>
enum
{
    DEF_CAPACITY = 100
};
const int minData = -1000;

template <typename T>
class MinHeap
{
private:
    T *data;
    int size;
    int capacity;

public:
    MinHeap(int cap = DEF_CAPACITY)
        : data(new T[cap]), capacity(cap), size(0)
    {
        this->data[0] = minData;
    }

    ~MinHeap()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
    }

    void init(const MinHeap &minHeap)
    {
        capacity = minHeap.capacity;
        size = minHeap.size;
        data = new E(capacity);
        for (int i = 0; i < size; ++i)
        {
            data[i] = minHeap.data[i];
        }
    }
    MinHeap(const MinHeap & MinHeap){
        init(MinHeap);
    }
    int getsize() const
    {
        return size;
    }
    //判断最小堆是否已满
    bool full() const
    {
        return size == capacity;
    }
    //是否为空
    bool empty() const
    {
        return size == 0;
    }

    bool insert(const int num)
    {
        if (full())
        {
            throw std::logic_error("minHeaP is full")
        }
    }
};
