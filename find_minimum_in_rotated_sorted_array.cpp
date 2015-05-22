#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int findMin(const std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz==0) return INT_MIN;

        int beg = 0;
        int end = sz-1;
        int mid = 0;
        while(beg<=end)
        {
            mid = beg + (end-beg)/2;
            if(beg==end)
            {
                return nums[beg];
            }
            else if(beg+1==end)
            {
                return std::min(nums[beg], nums[end]);
            }
            else if(nums[mid]>nums[end])
            {
                beg = mid;
            }
            else// if(nums[mid]<nums[end])
            {
                end = mid;
            }
        }
        return nums[mid];
    }
};

int main()
{
    Solution s;
    std::cout<<s.findMin({1})<<std::endl;
    return 0;
}


