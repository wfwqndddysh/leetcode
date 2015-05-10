#include<iostream>
#include<cassert>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int total = 0;
        while(n>0)
        {
            if(n & 1)
                total++;
            n = n >> 1;
        }
        return total;
    }

    int hammingWeight_2(uint32_t n)
    {
        int total = 0;
        while(n>0)
        {
            n = n & (n-1);
            total++;
        }
        return total;
    }

};

int main()
{
    return 0;
}

