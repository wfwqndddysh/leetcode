#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        int sz=nums.size();
        if(sz==0) return {-1, -1};

        int low=0;
        int high=sz-1;
        
        int beg=-1;
        int end=-1;
        int mid=-1;
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

        if(nums[mid]==target)
            beg=mid;
        else if(mid+1<sz && nums[mid+1]==target)
            beg=mid+1;

        low=0;
        high=sz-1;
        mid = -1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]<=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        if(nums[mid]==target)
            end=mid;
        else if(mid>0 && nums[mid-1]==target)
            end=mid-1;

        return {beg, end};
    }
};

int main()
{
    Solution s;

    //std::vector<int> nums{1}, 1;

    std::vector<int> nums{1, 4};

    auto v = s.searchRange(nums, 4);
    for(int n : v)
        std::cout<<n<<" ";

    std::cout<<std::endl;
    return 0;
}

