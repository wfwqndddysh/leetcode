#include<iostream>
#include<cassert>
#include<algorithm>

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x==0) return 0;

        double diff = 0.1;
        double init = 1.0;

        while(std::abs(init*init-(double(x)))>diff)
        {
            init = (init + x/init)/2;
        }

        return init;
    }
};

int main()
{
    Solution s;
    std::cout<<s.mySqrt(2147395599)<<std::endl;
    return 0;
}

