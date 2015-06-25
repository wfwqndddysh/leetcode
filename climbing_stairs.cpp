#include<iostream>
#include<cassert>

class Solution
{
public:
    int climbStairs(int n)
    {
        if(n<3) return n;

        int ways_prev=2;
        int ways_prev_prev=1;

        int cur = 0;
        for(int i=3; i<=n; ++i)
        {
            cur = ways_prev + ways_prev_prev;
            ways_prev_prev = ways_prev;
            ways_prev = cur;
        }

        return cur;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

