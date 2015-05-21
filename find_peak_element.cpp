#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int findPeakElement(const std::vector<int>& nums)
    {
        assert(!nums.empty());

        auto sz = nums.size();
        if(sz==1) return 0;

        for(size_t i=1; i<sz; ++i)
        {
            if(nums[i]<nums[i-1])
                return i-1;
        }
        return sz-1;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}


