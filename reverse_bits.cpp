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

    //divide and conquer
    uint32_t reverse_bits_log_n(uint32_t n)
    {
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main()
{
    return 0;
}

