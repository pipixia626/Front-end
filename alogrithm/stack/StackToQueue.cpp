/*
/用两个栈来实现一个队列，完成队列的Push和Pop操作。 
/队列中的元素为int类型。
*/

#include<iostream>
#include<stack>

class StackQueue{
    private:
    std::stack<int>inStack;
    std::stack<int>outStack;
    public:
    void push(int node){
      inStack.push(node);
    }

    int pop(){
      int res;
      if(outStack.empty()){
          while (!inStack.empty())
          {
              outStack.push(inStack.top());
              inStack.pop();
          }
      }
      res=outStack.top();
      outStack.pop();
      return res;
    }
};