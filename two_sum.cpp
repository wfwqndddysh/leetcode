#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> res;
        for(size_t i=0; i<nums.size()-1; ++i)
        {
            for(size_t j=0; j<nums.size(); ++j)
            {
                if(nums[i]+nums[j]==target)
                    return {(int)i+1, (int)j+1};
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

