/* STL大顶堆，小顶堆的应用*/

#include <iostream>
#include <vector>
#include <algorithm>

/*
STL 堆操作
（1）make_heap()构造堆
void make_heap(first_pointer,end_pointer,compare_function);
默认比较函数是(<)，即最大堆。
函数的作用是将[begin,end)内的元素处理成堆的结构

（2）push_heap()添加元素到堆
void push_heap(first_pointer,end_pointer,compare_function);
新添加一个元素在末尾，然后重新调整堆序。该算法必须是在一个已经满足堆序的条件下。
先在vector的末尾添加元素，再调用push_heap

（3）pop_heap()从堆中移出元素
void pop_heap(first_pointer,end_pointer,compare_function);
把堆顶元素取出来，放到了数组或者是vector的末尾。
要取走，则可以使用底部容器（vector）提供的pop_back()函数。
先调用pop_heap再从vector中pop_back元素

（4）sort_heap()对整个堆排序
排序之后的元素就不再是一个合法的堆了。
*/

//大顶堆

struct MaxHeapCmp
{
    inline bool operator()(const int &x, const int &y)
    {
        return x < y;
    }
};

//小顶堆

struct MinheapCmp
{
    inline bool operator()(const int &x, const int &y)
    {
        return x > y;
    }
};

template<typename T>  
void Print(T& V)  
{  
    typename T::iterator iter=V.begin();  
    while(iter != V.end())  
    {  
        cout<<*iter++<<" ";  
    }  
    cout<<endl;  
}  
  
int main()  
{  
    std::vector<int> ivec;  
    for(int i=3;i<=7;++i)  
        ivec.push_back(i);  
    for(int i=5;i<=9;++i)  
        ivec.push_back(i);  
    for(int i=1;i<=4;++i)  
        ivec.push_back(i);  
    std::cout<<"原数据：";  
    Print(ivec);  
  
    make_heap(ivec.begin(),ivec.end());//做最大堆排序，其实还在vector容器内  
    std::cout<<"堆排后：";  
    Print(ivec);  
  
    pop_heap(ivec.begin(),ivec.end());//删除最大堆，其实是把数据放到最后了！  
    std::cout<<"删除后：";  
    Print(ivec);  
    ivec.pop_back();  
  
    pop_heap(ivec.begin(),ivec.end());//删除最大堆，其实是把数据放到最后了！  
    std::cout<<"删除后：";  
    Print(ivec);  
    ivec.pop_back();  
  
    ivec.push_back(15);  
    std::cout<<"添加数据后：";  
    Print(ivec);  
  
    push_heap(ivec.begin(),ivec.end());//放入最大堆，其实是把新加入的数据，按照堆排加入堆内  
    std::cout<<"把最后一个数加入堆里:\n";  
    Print(ivec);  
  
    sort_heap(ivec.begin(),ivec.end());//把堆排顺序，还原成一般的排序算法  
    std::cout<<"还原堆排顺序：\n";  
    Print(ivec);  
  
    return 0;  
}  
/*
 9 
make_heap(b,e,cmp)                      /                  \ 
push_heap(b,e)                        8                    6 
push_heap(b,e,cmp)                /         \          /          \ 
pop_heap(b,e)                   7           7        5            5 
pop_heap(b,e,cmp)              /   \       /   \    /   \        / 
sort_heap(b,e)               3     6     4     1  2     3      4 

*/