#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz<2) return true;

        int most_far = -1;
        for(int i=0; i<sz-1; ++i)
        {
            most_far = std::max(most_far, nums[i]+i);
            if(most_far<=i) return false;
            if(most_far>=sz-1) return true;
        }

        return true;
    }
};

int main()
{
    Solution s;
    //std::vector<int> nums{0, 1};
    std::vector<int> nums{2, 0, 0};
    std::cout<<s.canJump(nums)<<std::endl;
    return 0;
}

