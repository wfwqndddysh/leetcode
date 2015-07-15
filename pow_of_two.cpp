#include<iostream>
#include<cassert>

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if(n<=0) return false;
        return (n & (n-1))==0;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

