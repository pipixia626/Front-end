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
    MinHeap(const MinHeap &MinHeap)
    {
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
        //首先把元素插入到最小堆的最后面
        //保存最后一个元素的位置
        //data[0]控制哨兵元素，它不小于最大堆中最大元素，控制循环结束
        int i = ++this->size;
        for (; this->data[i / 2] > num; i = i / 2)
        {
            this->data[i] = this->data[i / 2];
        }
        this->data[i] = num;
        return true;
    }
    void Create(int *num, int n)
    {
        for (int i = 0; i < n; i++)
        {
            this->data[++this->size] = num[i];
        }
        for (int i = this->size / 2; i >= 1; i--)
        {
            this->Predown(i);
        }
    }

    int DeleteMin()
    {
        if (this->IsEmpty())
        { //最小堆已空
            return MinData;
        }
        int min = this->data[0];
        this->size--;
        this->Predown(this->size + 1);
        return min;
    }

    //上滤函数，把data[n]为根的子堆调整为最小堆
    void Predown(int n)
    {
        //保存下标为n的元素
        int x = this->data[n];
        int parent, child;
        //用最后一个元素来替代第一个最小值
        for (parent = n; parent * 2 <= this->size; parent = child)
        {
            //child指向当前结点的左孩子
            child = 2 * parent;
            //左孩子的下标不等于最小堆容量，则说明有右孩子
            //右孩子的键值如果父节点，那么child指向右孩子，否则仍指向左孩子
            if ((child != this->size) && this->data[child] > this->data[child + 1])
            {
                child++; //选择左右孩子中最小值
            }
            if (x <= this->data[child])
            { //找到合适的位置
                break;
            }
            else
            { //否则把孩子上移
                this->data[parent] = this->data[child];
            }
        }
        this->data[parent] = x;
    }

    //打印最小堆
    void Print()
    {
        for (int i = 1; i <= this->size; i++)
        {
            cout << this->data[i] << " ";
        }
    }
};
