#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<unordered_map>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        int sz=nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>>  res;
        for(int i=0; i<sz; )
        {
            for(int j=i+1; j<(int)nums.size()-1; )
            {
                int third=find_third(nums, j+1, 0-nums[j]-nums[i]);
                if(third>=0)
                {
                    res.push_back({});
                    res.back().push_back(nums[i]);
                    res.back().push_back(nums[j]);
                    res.back().push_back(nums[third]);
                }
                for(j++; nums[j]==nums[j-1] && i<sz-1; ++j);
            }

            for(i++; nums[i]==nums[i-1] && i<sz-2; ++i);
        }

        return res;
    }

private:
    int find_third(std::vector<int>&  nums, int start, int target)
    {
        int low=start;
        int high=nums.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
            else
            {
                high=mid-1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    /*
    std::vector<int> nums{3, 2, 4};
    s.twoSum(nums, 6);
    */

    //std::vector<int> nums({13,14,1,2,-11,-11,-1,5,-1,-11,-9,-12,5,-3,-7,-4,-12,-9,8,-13,-8,2,-6,8,11,7,7,-6,8,-9,0,6,13,-14,-15,9,12,-9,-9,-4,-4,-3,-9,-14,9,-8,-11,13,-10,13,-15,-11,0,-14,5,-4,0,-3,-3,-7,-4,12,14,-14,5,7,10,-5,13,-14,-2,-6,-9,5,-12,7,4,-8,5,1,-10,-3,5,6,-9,-5,9,6,0,14,-15,11,11,6,4,-6,-10,-1,4,-11,-8,-13,-10,-2,-1,-7,-9,10,-7,3,-4,-2,8,-13});
    std::vector<int> nums{1, -1, -1, 0};
    
    auto vv = s.threeSum(nums);

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

