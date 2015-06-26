#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        auto sz=nums.size();
        assert(sz!=0);

        int max_val = nums[0];
        int cur_max = nums[0];

        for(size_t i=1; i<sz; ++i)
        {
            cur_max = std::max(cur_max+nums[i], nums[i]);
            max_val = std::max(max_val, cur_max);
        }

        return max_val;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

