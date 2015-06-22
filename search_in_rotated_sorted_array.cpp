#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        auto sz=nums.size();
        if(sz==0) return -1;

        int low = 0;
        int high = sz-1;

        while(low <= high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid]==target)
                return mid;

            if(nums[high]==target)
                return high;

            if(nums[mid]>nums[low])
            {
                if(target>=nums[low] && target<=nums[mid])
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

        return -1;
    }
};

int main()
{
    Solution s;
    //std::vector<int> nums{1, 3};
    //std::vector<int> nums{3, 1};
    std::vector<int> nums{5, 1, 2, 3, 4};
    std::cout<<s.search(nums, 1)<<std::endl;
    return 0;
}

