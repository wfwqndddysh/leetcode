#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    bool search(std::vector<int>& nums, int target)
    {
        auto sz=nums.size();
        if(sz==0) return -1;

        int low = 0;
        int high = sz-1;

        while(low <= high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid]==target || nums[high]==target)
                return true;

            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                high = high-1;
            }
            else if(nums[mid]==nums[low])
            {
                low = mid+1;
            }
            else if(nums[mid]==nums[high])
            {
                high = mid-1;
            }
            else if(nums[mid]>nums[low])
            {
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    //std::vector<int> nums{1, 3};
    //std::vector<int> nums{3, 1};
    //std::vector<int> nums{1, 1, 3, 1};
    std::vector<int> nums{2, 2, 2, 0, 0, 1};
    std::cout<<s.search(nums, 3)<<std::endl;
    return 0;
}

