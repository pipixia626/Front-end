#include <new>
#include <memory>
class NewHandlerHolder
{
public:
    explicit NewHandlerHolder(std::new_handler nh) : handler(nh) {}
    ~NewHandlerHolder() { std::set_new_handler(handler); }

private:
    std::new_handler handler;
    NewHandlerHolder(const NewHandlerHolder &);
    NewHandlerHolder &operator=(const NewHandlerHolder &);
};
template <typename T>
class NewHandlerSupport
{
public:
    static std::new_handler set_new_handler(std::new_handler p) throw();
    static void *operator new(std::size_t size) thorw(std::bad_alloc) private : static std::new_handler currentHandler;
private:
static std::new_handler currentHandler;
};

template <typename T>
std::new_handler
NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
    std::new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}
template <typename T>
void *NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc)
{
    NewHandlerHolder h(std::set_new_handler(currentHandler));
    return::operator new(size);
}

//将每一个currentHandler初始化为null
template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler=0;


//为其他类添加支持能力

class Widget:public NewHandlerSupport<Widget>{
    //...
};