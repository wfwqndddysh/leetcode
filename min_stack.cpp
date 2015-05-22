#include<iostream>
#include<cassert>
#include<stack>
#include<climits>

//如果最小值有大量重复，可以使用这个ref版本，对于相等的，只记录一次
class MinStackRef
{
public:
    void push(int x)
    {
        if(mins_.empty() || x<mins_.top().first)
        {
            mins_.push({x, 1});
        }
        else if(x==mins_.top().first)
        {
            mins_.top().second++;
        }
        data_.push(x);
    }

    void pop()
    {
        if(data_.top()==mins_.top().first)
        {
            if(--mins_.top().second==0)
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
        return mins_.top().first;
    }

private:
    std::stack<int> data_;
    //pair: min and ref_cnt
    std::stack<std::pair<int, int>> mins_;
};

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

//只使用一个stack的方案,当然是只对于能恢复值的数据类型适用的
class MinStackOneStack
{
public:
    MinStackOneStack()
        : min_(INT_MAX) {}

    void push(int x)
    {
        data_.push(x-min_);
        std::cout<<x-min_<<std::endl;
        if(x < min_)
        {
            min_ = x;
        }

        std::cout<<min_<<std::endl;
    }

    void pop()
    {
        int64_t t = data_.top();
        if(t < 0)
        {
            min_ = min_-t;
        }
        data_.pop();
    }

    int top()
    {
        if(data_.top()>0)
            return data_.top()+min_;
        else
            return min_;
    }

    int getMin()
    {
        return min_;
    }

private:
    int64_t min_;
    std::stack<int64_t> data_;
};

int main()
{
    MinStackOneStack s;
    s.push(2);
    s.push(0);
    s.push(3);
    s.push(0);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.getMin();
    std::cout<<std::endl;
    return 0;
}

