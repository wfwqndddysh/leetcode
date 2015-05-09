#include<iostream>
#include<cassert>
#include<cstring>
#include<bitset>

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        while(n > m)
        {
            n = n & (n-1);
        }
        return n;
    }

};

int main()
{
    Solution s;
    std::cout<<s.rangeBitwiseAnd(5, 7)<<std::endl;
    return 0;
}

