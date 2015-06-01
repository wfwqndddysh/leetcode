#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        auto sz = nums.size();
        assert(sz>0);
        if(sz==1)
            return nums[0];

        int bit[32] = {0};
        int ret = 0;

        for(size_t i=0; i<32; ++i)
        {
            int cnt_1 = 0;
            int cnt_0 = 0;
            for(size_t j=0; j<sz; ++j)
            {
                if((nums[j]>>i) & 0x1) cnt_1++;
                else cnt_0++;
            }

            bit[i] = (cnt_0 % 3 ==0) ? 1 : 0;
        }

        for(size_t i=0; i<32; ++i)
        {
            ret += bit[i]<<i;
        }

        return ret;
    }
};

//下面的解释才是最牛最清晰的解释

/*
   The basic idea is to implement a modulo-3 counter (to count how many times "1" occurs) for each bit position.
   Such modulo-3 counter needs two bits (B1,B0) to represent.
   (B1,B0):
   (0, 0) : '1' occurs zero times after last resetting,
   (0, 1) : '1' occurs one times after last resetting,
   (1, 0) : '1' occurs two times after last resetting,
   (1, 1) : '1' occurs three times after last resetting, then we need to reset the counter to (0,0)
So to implement such modulo-3 counters, we need three variables (b0, b1, reset)
The n-th bit of b0 is the B0 bit of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit)
The n-th bit of b1 is the B1 bit of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit)
The n-th bit of reset is the reset flag of the modulo-3 counter for the n-th bit (n=0..31 assuming int is 32 bit),

- b0: can be easily implemented with XOR bit operation,  as b0 = b0^ A[i]
- b1: B1 will only be set to 1, when B0 (of the n-th bit counter) =1 and the n-th bit of A[i] = 1
    , and stay '1' until it is reseted. So b1 |=  b0 & A[i];
- The reset flag is set when (B1, B0) = (1,1). So, reset = b0 & b1;
- The reset operation can be done by b0 = b0 ^ reset and b1 = b1 ^ reset;

After updating the b0, b1, reset with all A[], the b0 will be the final result since if the
n-th bit of the to-be-found element is 1, then the times of '1' occurs on the n-th bit is 3*x+1, which is 1 after the modulo 3 opertation.
*/

class SolutionLeetCode
{
public:
    int singleNumber(std::vector<int> A)
    {
        int b0=0, b1=0, reset=0;
        int i;
        int n=A.size();
        assert(n>0);
        if(n==1) return A[0];

        for(i = 0; i<n; i++)
        {
            b1 |= (b0 & A[i]);
            b0 = b0 ^ A[i];
            reset = b1 & b0;
            b1 = b1 ^ reset;
            b0 = b0 ^ reset;
        }

        return b0;
    }
};

int main()
{
    Solution s;
    std::vector<int> v {2, 2, 3, 2};
    std::cout<<s.singleNumber(v)<<std::endl;
    return 0;
}

