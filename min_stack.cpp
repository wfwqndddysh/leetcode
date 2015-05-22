#include<iostream>
#include<cassert>
#include<stack>

class MinStack
{
public:
    void push(int x)
    {
        if(mins_.empty() || x<=mins_.top())
        {
            mins_.push(x);
        }
        data_.push(x);
    }

    void pop()
    {
        if(data_.top()==mins_.top())
        {
            mins_.pop();
        }
        data_.pop();
    }

    int top()
    {
        return data_.top();
    }

    int getMin()
    {
        return mins_.top();
    }

private:
    std::stack<int> data_;
    std::stack<int> mins_;
};

int main()
{
    MinStack s;
    s.push(-3);
    s.getMin();
    std::cout<<std::endl;
    return 0;
}


