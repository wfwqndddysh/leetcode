#include<iostream>
#include<cassert>
#include<stack>

class Queue
{
public:

    // Push element x to the back of queue.
    void push(int x)
    {
        while(!out_st_.empty())
        {
            in_st_.push(out_st_.top());
            out_st_.pop();
        }
        in_st_.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        while(!in_st_.empty())
        {
            out_st_.push(in_st_.top());
            in_st_.pop();
        }
        out_st_.pop();
    }

    // Get the front element.
    int peek(void)
    {
        while(!in_st_.empty())
        {
            out_st_.push(in_st_.top());
            in_st_.pop();
        }
        return out_st_.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return in_st_.empty() && out_st_.empty();
    }
private:
    std::stack<int> in_st_;
    std::stack<int> out_st_;
};

int main()
{
    std::cout<<std::endl;
    return 0;
}

