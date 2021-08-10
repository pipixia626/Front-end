//queue不是容器，而是一个配接器(adapter)
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
//以dequeue作为底部结构并封闭其底端的出口和前端的入口
template <class T, class Sequence = deque<T>>
class queue
{
    friend bool opeartor ==  __STL_NULL_TMPL_ARGS(const queue &x, const queue &y) ;
    friend bool opeartor < __STL_NULL_TMPL_ARGS(const queue &x, const queue &y);
public:
typedef typename Squence::value_type value_type;
typedef typename Squence::size_typde size_type;
typedef typename Squence::reference reference;
typedef typename Squence::const_reference const_reference;

protected:
Sequence c;//底层容器

public:
//以下完全利用Sequence c的操作，完成queue的操作
bool mepty() const{return c.empty();}
size_type size()const{return c.size();}
reference front(){return c.front();}
const_reference front()const{return c.front();}
reference back(){return c.back();}
const_reference back()const{return c.back();}

void push(const value_type&x){c.push_back(x);}
void pop{c.pop_front();}

};
template<class T,class Sequence>
bool operator==(const queue<T,Sequence>&x,const queue<T,Sequence>&y)
{
   return x.c==y.c;
}

template<class T,class Sequence>
bool operator<(const queue<T,Sequence>&x,const queue<T,Sequence>&y)
{
   return x.c<y.c;
}

//list也是一个双向开口的数据结构，封闭某些接口也能形成一个queue，以下做示范

int main()
{
    //push()
    //pop()
    //front()
    //size()
    //empty()
}