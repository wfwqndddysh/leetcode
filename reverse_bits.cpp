#include<iostream>
#include<cassert>

class Solution
{
public:
    uint32_t reverse_bits(uint32_t n)
    {
        uint32_t r_n = 0;
        for(int i=0; i<32; ++i)
        {
            r_n = (r_n << 1) | (n & 1);
            n = n>>1;
        }
        return r_n;
    }
};

int main()
{
    return 0;
}

