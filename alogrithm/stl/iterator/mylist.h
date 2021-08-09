template <typename T>
class List
{
public:
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std::cout) const;
    //...
private:
    List<T> *_end;
    List<T> *_front;
    long _size;
};

template <typename T>
class ListItem
{
public:
    T value() const { return _value; }
    ListItem *next() const { return _next; }

private:
    T _value;
    ListItem *_next; //单向链表
};