#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        size_t index=0;

        for(; index<nums.size(); ++index)
        {
            if(target<=nums[index])
                return index;
        }

        return index;
    }
};

class SolutionBinary
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        if(nums.size()==0) return 0;

        int low = 0;
        int high = nums.size()-1;
        int mid = -1;
        while(low<=high)
        {
            mid=low+(high-low)/2;

            if(nums[mid]>=target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        return nums[mid]>=target ? mid : mid+1;
    }
};

int main()
{
    SolutionBinary s;
    std::vector<int> nums{1};
    std::cout<<s.searchInsert(nums, 2)<<std::endl;
    return 0;
}

