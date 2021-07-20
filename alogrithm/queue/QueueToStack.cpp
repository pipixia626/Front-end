//用两个队列实现栈操作

#include <iostream>
#include <queue>

class QueueStack
{
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    void push(int node)
    {
        if (queue1.empty())
        {
            queue1.push(node);
            while (!queue2.empty())
            {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }
        else
        {
            queue2.push(node);
            while (!queue1.empty())
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }

    void pop()
    {
        if (queue1.empty())
        {
            queue2.pop();
        }
        else if(queue2.empty())
        {
            queue1.pop();
        }
        else{
            throw std::logic_error("empty queue");
        }
    }

    int top()
    {
        if (queue1.empty())
        {
            return queue2.front();
        }
        else
            return queue1.front();
    }

    bool empty()
    {
        return (queue1.empty() && queue2.empty());
    }
};


int main(){
    QueueStack q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.pop();
    q.push(2);
    q.pop();
}