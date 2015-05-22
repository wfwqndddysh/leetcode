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

    int findPeakElement_binary(const std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz==1) return 0;

        int beg = 0;
        int end = sz-1;
        int mid = 0;
        while(beg<=end)
        {
            mid = beg + (end-beg)/2;
            if(beg==end)
            {
                return beg;
            }
            else if(beg+1==end)
            {
                return nums[beg]>nums[end] ? beg : end;
            }
            else if(nums[mid-1]>nums[mid])
            {
                end = mid;
            }
            else if(nums[mid+1]>nums[mid])
            {
                beg = mid;
            }
            else
            {
                return mid;
            }
        }
        return mid;
    }
};

int main()
{
    Solution s;
    std::cout<<s.findPeakElement_binary({1, 2, 1})<<std::endl;
    return 0;
}


