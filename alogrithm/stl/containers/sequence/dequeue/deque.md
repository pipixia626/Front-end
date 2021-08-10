# deque
## 概述
vector 是单向开口的连续线性空间，deque是一种双向开口的连续线性空间

### 和vector的差异
1. 允许常数时间内对起头端进行元素的插入或者移除操作
2. deque没有所谓容量概念，因为它是动态地以分段连续空间组合的，随时可用增加一段新的空间
3. deque虽然也提供了Random Acess iterator ,但它的迭代器不是普通指针


对deque排序可用复制到一个Vector然后排序再复制回来
## 数据结构
deque由一段一段的定量连续空间构造的，因此在前端后后端有必要配置一个定量连续的空间

采用一块所谓的map，是一小块连续空间，其中每个元素都是指针，指向另一段比较大的连续线性空间（缓冲区）
缓冲区是存储空间主体,以及两个迭代器
start :指向第一个缓冲区的第一个元素
finish:指向最后一个缓冲区的最高一个元素的下一个位置

还有记住目前map的大小
map满了之后需要再找一块更大的空间来作为map(reallocte_map)

## 迭代器
```
template<class T,class Ref,class Ptr,size_t BufSize>
struct __deque_iterator{

    static size_t buffer_size(){return __deque_buf_size(BufSiz,sizeof(T));}
    //一些typedef

    typedef __deque_iterator itself;

    //保持与容器的连接
    T *cur;//指向缓存区的current元素
    T* first;//指向缓冲区的头
    T* last;//指向缓冲区的尾
    map_pointer node;//指向管控中心(map)
}
```
其中用来决定缓冲区大小的函数 buffer_size(),调用__deque_buf_size();
调用的函数是一个全局的函数
定义如下
- 如果n 不为0 传回n ,表述buffer size 由用户自定义
- 如果n 为0 表示使用默认值
1. 如果sz(元素大小，sizeof(value_type))小于512，传回512/sz
2. 如果sz不小于512 传回1

## 内存构造
push尾端只剩一个空间元素的时候->push_front_aux

reserve_map_at_front()判断是否需要补充map