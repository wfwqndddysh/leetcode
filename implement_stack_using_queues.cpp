#include<iostream>
#include<cassert>
#include<queue>

class Stack
{
public:
    // Push element x onto stack.
    void push(int x)
    {
        if(!in_q_.empty())
            in_q_.push(x);
        else if(!out_q_.empty())
            out_q_.push(x);
        else 
            in_q_.push(x);
    }

    // Removes the element on top of the stack.
    void pop()
    {
        while(in_q_.size()>=1)
        {
            if(in_q_.size()==1)
            {
                in_q_.pop();
                return;
            }

            out_q_.push(in_q_.front());
            in_q_.pop();
        }

        while(out_q_.size()>=1)
        {
            if(out_q_.size()==1)
            {
                out_q_.pop();
                return;
            }

            in_q_.push(out_q_.front());
            out_q_.pop();
        }

    }

    // Get the top element.
    int top()
    {
        while(!in_q_.empty())
        {
            int elem=in_q_.front();
            out_q_.push(elem);
            in_q_.pop();

            if(in_q_.empty()) return elem;
        }

        while(!out_q_.empty())
        {
            int elem=out_q_.front();
            in_q_.push(elem);
            out_q_.pop();

            if(out_q_.empty()) return elem;
        }
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return in_q_.empty() && out_q_.empty();
    }

private:
    std::queue<int> in_q_;
    std::queue<int> out_q_;
};

class StackOneQueue
{
public:
    // Push element x onto stack.
    void push(int x)
    {
        q_.push(x);
    }

    // Removes the element on top of the stack.
    void pop()
    {
        int sz=q_.size();
        for(int i=0; i<sz-1; ++i)
        {
            q_.push(q_.front());
            q_.pop();
        }
        q_.pop();
    }

    // Get the top element.
    int top()
    {
        int elem=0;
        int sz=q_.size();
        for(int i=0; i<sz; ++i)
        {
            elem=q_.front();
            q_.push(elem);
            q_.pop();
        }
        return elem;
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return q_.empty();
    }

private:
    std::queue<int> q_;
};

int main()
{
    std::cout<<std::endl;
    return 0;
}

