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

int main()
{
    Solution s;
    std::vector<int> v {2, 2, 3, 2};
    std::cout<<s.singleNumber(v)<<std::endl;
    return 0;
}

